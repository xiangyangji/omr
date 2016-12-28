/*******************************************************************************
 *
 * (c) Copyright IBM Corp. 2016
 *
 *  This program and the accompanying materials are made available
 *  under the terms of the Eclipse Public License v1.0 and
 *  Apache License v2.0 which accompanies this distribution.
 *
 *      The Eclipse Public License is available at
 *      http://www.eclipse.org/legal/epl-v10.html
 *
 *      The Apache License v2.0 is available at
 *      http://www.opensource.org/licenses/apache2.0.php
 *
 * Contributors:
 *    Multiple authors (IBM Corp.) - initial implementation and documentation
 *******************************************************************************/

#include "compile/Compilation.hpp"
#include "compile/Method.hpp"
#include "env/FrontEnd.hpp"
#include "infra/List.hpp"
#include "il/Block.hpp"
#include "ilgen/VirtualMachineState.hpp"
#include "ilgen/IlBuilder.hpp"
#include "ilgen/MethodBuilder.hpp"
#include "ilgen/BytecodeBuilder.hpp"
#include "ilgen/TypeDictionary.hpp"

// should really move into IlInjector.hpp
#define TraceEnabled    (comp()->getOption(TR_TraceILGen))
#define TraceIL(m, ...) {if (TraceEnabled) {traceMsg(comp(), m, ##__VA_ARGS__);}}


OMR::BytecodeBuilder::BytecodeBuilder(TR::MethodBuilder *methodBuilder,
                                      int32_t bcIndex,
                                      char *name)
   : TR::IlBuilder(methodBuilder, methodBuilder->typeDictionary()),
   _fallThroughBuilder(0),
   _bcIndex(bcIndex),
   _name(name),
   _initialVMState(0),
   _vmState(0)
   {
   _successorBuilders = new (PERSISTENT_NEW) List<TR::BytecodeBuilder>(_types->trMemory());
   initialize(methodBuilder->details(), methodBuilder->methodSymbol(),
              methodBuilder->fe(), methodBuilder->symRefTab());
   initSequence();
   }

void
TR::BytecodeBuilder::initialize(TR::IlGeneratorMethodDetails * details,
                                TR::ResolvedMethodSymbol     * methodSymbol,
                                TR::FrontEnd                 * fe,
                                TR::SymbolReferenceTable     * symRefTab)
    {
    this->OMR::IlInjector::initialize(details, methodSymbol, fe, symRefTab);

    //addBytecodeBuilderToList relies on _comp and it won't be ready until now
    _methodBuilder->addToAllBytecodeBuildersList(this);
    }

void
OMR::BytecodeBuilder::appendBlock(TR::Block *block, bool addEdge)
   {
   if (block == NULL)
      {
      block = emptyBlock();
      }

   block->setByteCodeIndex(_bcIndex, _comp);
   return TR::IlBuilder::appendBlock(block, addEdge);
   }

uint32_t
OMR::BytecodeBuilder::countBlocks()
   {
   // only count each block once
   if (_count > -1)
      return _count;

   TraceIL("[ %p ] TR::BytecodeBuilder::countBlocks 0\n", this);

   _count = TR::IlBuilder::countBlocks();

   if (NULL != _fallThroughBuilder)
      _methodBuilder->addToBlockCountingWorklist(_fallThroughBuilder);

   ListIterator<TR::BytecodeBuilder> iter(_successorBuilders);
   for (TR::BytecodeBuilder *builder = iter.getFirst(); !iter.atEnd(); builder = iter.getNext())
      if (builder->_count < 0)
         _methodBuilder->addToBlockCountingWorklist(builder);

   TraceIL("[ %p ] TR::BytecodeBuilder::countBlocks %d\n", this, _count);

   return _count;
   }

bool
OMR::BytecodeBuilder::connectTrees()
   {
   if (!_connectedTrees)
      {
      TraceIL("[ %p ] TR::BytecodeBuilder::connectTrees\n", this);
      bool rc = TR::IlBuilder::connectTrees();
      addAllSuccessorBuildersToWorklist();
      return rc;
      }

   return true;
   }


void
OMR::BytecodeBuilder::addAllSuccessorBuildersToWorklist()
   {
   if (NULL != _fallThroughBuilder)
      _methodBuilder->addToTreeConnectingWorklist(_fallThroughBuilder);

   // iterate over _successorBuilders
   ListIterator<TR::BytecodeBuilder> iter(_successorBuilders);
   for (TR::BytecodeBuilder *builder = iter.getFirst(); !iter.atEnd(); builder = iter.getNext())
      _methodBuilder->addToTreeConnectingWorklist(builder);
   }

// Must be called *after* all code has been added to the bytecode builder
// Also, current VM state is assumed to be what should propagate to the fallthrough builder
void
OMR::BytecodeBuilder::AddFallThroughBuilder(TR::BytecodeBuilder *ftb)
   {
   TR_ASSERT(comesBack(), "builder does not appear to have a fall through path");

   TraceIL("IlBuilder[ %p ]:: fallThrough successor [ %p ]\n", this, ftb);

   TR::BytecodeBuilder *b = ftb;
   transferVMState(&b);    // may change what b points at!

   if (b != ftb)
      TraceIL("IlBuilder[ %p ]:: fallThrough successor changed to [ %p ]\n", this, b);
   _fallThroughBuilder = b;
    _methodBuilder->addBytecodeBuilderToWorklist(ftb);

   // add explicit goto and register the actual fall-through block
   TR::IlBuilder *tgtb = b;
   TR::IlBuilder::Goto(&tgtb);
   }

// AddSuccessorBuilders() should be called with a list of TR::BytecodeBuilder ** pointers.
// Each one of these pointers could be changed by AddSuccessorBuilders() in the case where
// some operations need to be inserted along the control flow edges to synchronize the
// vm state from "this" builder to the target BytecodeBuilder. For this reason, the actual
// control flow edges should be created (i.e. with Goto, IfCmp*, etc.) *after* calling
// AddSuccessorBuilders, and the target used when creating those flow edges should take
// into account that AddSuccessorBuilders may change the builder object provided.
void
OMR::BytecodeBuilder::AddSuccessorBuilders(uint32_t numExits, ...)
   {
   va_list exits;
   va_start(exits, numExits);
   for (int32_t e=0;e < numExits;e++)
      {
      TR::BytecodeBuilder **builder = (TR::BytecodeBuilder **) va_arg(exits, TR::BytecodeBuilder **);
      transferVMState(builder);            // may change what builder points at!
      _successorBuilders->add(*builder);   // must be the bytecode builder that comes back from transferVMState()
      _methodBuilder->addBytecodeBuilderToWorklist(*builder);
      TraceIL("IlBuilder[ %p ]:: successor [ %p ]\n", this, *builder);
      }
   va_end(exits);
   }

void
OMR::BytecodeBuilder::setHandlerInfo(uint32_t catchType)
   {
   TR::Block *catchBlock = getEntry();
   catchBlock->setIsCold();
   catchBlock->setHandlerInfo(catchType, comp()->getInlineDepth(), -1, _methodSymbol->getResolvedMethod(), comp());
   }

void
OMR::BytecodeBuilder::propagateVMState(OMR::VirtualMachineState *fromVMState)
   {
   _initialVMState = (OMR::VirtualMachineState *) fromVMState->MakeCopy();
   _vmState = (OMR::VirtualMachineState *) fromVMState->MakeCopy();
   }

// transferVMState needs to be called before the actual transfer operation (Goto, IfCmp,
// etc.) is created because we may need to insert a builder object along that control
// flow edge to synchronize the vm state at the target (in the case of a merge point).
// On return, the object pointed at by the "b" parameter may have changed. The caller
// should direct control for this edge to whatever the parameter passed to "b" is
// pointing at on return
void
OMR::BytecodeBuilder::transferVMState(TR::BytecodeBuilder **b)
   {
   TR_ASSERT(_vmState != NULL, "asked to transfer a NULL vmState from builder %p [ bci %d ]", this, _bcIndex);
   if ((*b)->initialVMState())
      {
      // there is already a vm state at the target builder
      // so we need to synchronize this builder's vm state with the target builder's vm state
      // for example, the local variables holding the elements on the operand stack may not match
      // create an intermediate builder object to do that work
      TR::BytecodeBuilder *intermediateBuilder = _methodBuilder->OrphanBytecodeBuilder((*b)->_bcIndex, (*b)->_name);

      _vmState->MergeInto((*b)->initialVMState(), intermediateBuilder);
      TraceIL("IlBuilder[ %p ]:: transferVMState merged vm state on way to [ %p ] using [ %p ]\n", this, *b, intermediateBuilder);

      TR::IlBuilder *tgtb = *b;
      intermediateBuilder->IlBuilder::Goto(&tgtb);
      intermediateBuilder->_fallThroughBuilder = *b;
      TraceIL("IlBuilder[ %p ]:: fallThrough successor [ %p ]\n", intermediateBuilder, *b);
      *b = intermediateBuilder; // branches should direct towards intermediateBuilder not original *b
      }
   else
      {
      (*b)->propagateVMState(_vmState);
      }
   }

void
OMR::BytecodeBuilder::Goto(TR::BytecodeBuilder **dest)
   {
   if (*dest == NULL)
      *dest = _methodBuilder->OrphanBytecodeBuilder(_bcIndex, _name);
   Goto(*dest);
   }

void
OMR::BytecodeBuilder::Goto(TR::BytecodeBuilder *dest)
   {
   AddSuccessorBuilder(&dest);
   OMR::IlBuilder::Goto(dest);
   }

void
OMR::BytecodeBuilder::IfCmpEqual(TR::BytecodeBuilder **dest, TR::IlValue *v1, TR::IlValue *v2)
   {
   if (*dest == NULL)
      *dest = _methodBuilder->OrphanBytecodeBuilder(_bcIndex, _name);
   IfCmpEqual(*dest, v1, v2);
   }

void
OMR::BytecodeBuilder::IfCmpEqual(TR::BytecodeBuilder *dest, TR::IlValue *v1, TR::IlValue *v2)
   {
   TR_ASSERT(dest != NULL, "service cannot be called with NULL destination builder");
   AddSuccessorBuilder(&dest);
   OMR::IlBuilder::IfCmpEqual(dest, v1, v2);
   }

void
OMR::BytecodeBuilder::IfCmpEqualZero(TR::BytecodeBuilder **dest, TR::IlValue *c)
   {
   if (*dest == NULL)
      *dest = _methodBuilder->OrphanBytecodeBuilder(_bcIndex, _name);
   IfCmpEqualZero(*dest, c);
   }

void
OMR::BytecodeBuilder::IfCmpEqualZero(TR::BytecodeBuilder *dest, TR::IlValue *c)
   {
   TR_ASSERT(dest != NULL, "service cannot be called with NULL destination builder");
   AddSuccessorBuilder(&dest);
   OMR::IlBuilder::IfCmpEqualZero(dest, c);
   }

void
OMR::BytecodeBuilder::IfCmpNotEqual(TR::BytecodeBuilder **dest, TR::IlValue *v1, TR::IlValue *v2)
   {
   if (*dest == NULL)
      *dest = _methodBuilder->OrphanBytecodeBuilder(_bcIndex, _name);
   IfCmpNotEqual(*dest, v1, v2);
   }

void
OMR::BytecodeBuilder::IfCmpNotEqual(TR::BytecodeBuilder *dest, TR::IlValue *v1, TR::IlValue *v2)
   {
   TR_ASSERT(dest != NULL, "service cannot be called with NULL destination builder");
   AddSuccessorBuilder(&dest);
   OMR::IlBuilder::IfCmpNotEqual(dest, v1, v2);
   }

void
OMR::BytecodeBuilder::IfCmpNotEqualZero(TR::BytecodeBuilder **dest, TR::IlValue *c)
   {
   if (*dest == NULL)
      *dest = _methodBuilder->OrphanBytecodeBuilder(_bcIndex, _name);
   IfCmpNotEqualZero(*dest, c);
   }

void
OMR::BytecodeBuilder::IfCmpNotEqualZero(TR::BytecodeBuilder *dest, TR::IlValue *c)
   {
   TR_ASSERT(dest != NULL, "service cannot be called with NULL destination builder");
   AddSuccessorBuilder(&dest);
   OMR::IlBuilder::IfCmpNotEqualZero(dest, c);
   }

void
OMR::BytecodeBuilder::IfCmpLessThan(TR::BytecodeBuilder **dest, TR::IlValue *v1, TR::IlValue *v2)
   {
   if (*dest == NULL)
      *dest = _methodBuilder->OrphanBytecodeBuilder(_bcIndex, _name);
   IfCmpLessThan(*dest, v1, v2);
   }

void
OMR::BytecodeBuilder::IfCmpLessThan(TR::BytecodeBuilder *dest, TR::IlValue *v1, TR::IlValue *v2)
   {
   TR_ASSERT(dest != NULL, "service cannot be called with NULL destination builder");
   AddSuccessorBuilder(&dest);
   OMR::IlBuilder::IfCmpLessThan(dest, v1, v2);
   }

void
OMR::BytecodeBuilder::IfCmpGreaterThan(TR::BytecodeBuilder **dest, TR::IlValue *v1, TR::IlValue *v2)
   {
   if (*dest == NULL)
      *dest = _methodBuilder->OrphanBytecodeBuilder(_bcIndex, _name);
   IfCmpGreaterThan(*dest, v1, v2);
   }

void
OMR::BytecodeBuilder::IfCmpGreaterThan(TR::BytecodeBuilder *dest, TR::IlValue *v1, TR::IlValue *v2)
   {
   TR_ASSERT(dest != NULL, "service cannot be called with NULL destination builder");
   AddSuccessorBuilder(&dest);
   OMR::IlBuilder::IfCmpGreaterThan(dest, v1, v2);
   }
