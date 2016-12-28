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

#include "ilgen/VirtualMachineOperandStack.hpp"
#include "ilgen/VirtualMachineRegister.hpp"
#include "compile/Compilation.hpp"
#include "il/SymbolReference.hpp"
#include "il/symbol/AutomaticSymbol.hpp"
#include "ilgen/IlBuilder.hpp"
#include "ilgen/MethodBuilder.hpp"
#include "ilgen/TypeDictionary.hpp"

namespace OMR
{

VirtualMachineOperandStack::VirtualMachineOperandStack(TR::MethodBuilder *mb, int32_t sizeHint,
   TR::IlType *elementType, OMR::VirtualMachineRegister *stackTopRegister)
   : VirtualMachineState(),
   _mb(mb),
   _stackTopRegister(stackTopRegister),
   _stackMax(sizeHint),
   _stackTop(-1),
   _elementType(elementType)
   {
   int32_t numBytes = _stackMax * sizeof(TR::IlValue *);
   _stack = (TR::IlValue **) TR::comp()->trMemory()->allocateHeapMemory(numBytes);
   memset(_stack, 0, numBytes);

   // store current operand stack pointer base address so we can use it whenever we need
   // to recreate the stack as the interpreter would have
   mb->Store("OperandStack_base", stackTopRegister->Load(mb));

   _pushAmount = (growsUp()) ? +1 : -1;
   _stackOffset = stackPtrStartingOffset();
   }

VirtualMachineOperandStack::VirtualMachineOperandStack(OMR::VirtualMachineOperandStack *other)
   : VirtualMachineState(),
   _mb(other->_mb),
   _stackTopRegister(other->_stackTopRegister),
   _stackMax(other->_stackMax),
   _stackTop(other->_stackTop),
   _elementType(other->_elementType),
   _pushAmount(other->_pushAmount),
   _stackOffset(other->_stackOffset)
   {
   int32_t numBytes = _stackMax * sizeof(TR::IlValue *);
   _stack = (TR::IlValue **) TR::comp()->trMemory()->allocateHeapMemory(numBytes);
   memcpy(_stack, other->_stack, numBytes);
   }


// commits the simulated operand stack of values to the virtual machine state
// the given builder object is where the operations to commit the state will be inserted
// the top of the stack is assumed to be managed independently, most likely
//    as a VirtualMachineRegister or a VirtualMachineRegisterInStruct
void
VirtualMachineOperandStack::Commit(TR::IlBuilder *b)
   {
   TR::IlType *Element = _elementType;
   TR::IlType *pElement = _mb->typeDictionary()->PointerTo(Element);

   TR::IlValue *stack = b->Load("OperandStack_base");
   for (int32_t i = _stackTop;i >= 0;i--)
      {
      // TBD: how to handle hitting the end of stack?

      b->StoreAt(
      b->   IndexAt(pElement,
               stack,
      b->      ConstInt32(i - _stackOffset)),
            Pick(_stackTop-i)); // should generalize, maybe delegate element storage ?
      }
   }

void
VirtualMachineOperandStack::MergeInto(OMR::VirtualMachineOperandStack *other, TR::IlBuilder *b)
   {
   TR_ASSERT(_stackTop == other->_stackTop, "stacks are not same size");
   for (int32_t i=_stackTop;i >= 0;i--)
      {
      // only need to do something if the two entries aren't already the same
      if (other->_stack[i]->getCPIndex() != _stack[i]->getCPIndex())
         {
         // what if types don't match? could use ConvertTo, but seems...arbitrary
         // nobody *should* design bytecode set where corresponding elements of stacks from
         // two incoming control flow edges can have different primitive types. objects, sure
         // but not primitive types (even different types of objects should have same primitive
         // type: Address. Expecting to be disappointed here some day...
         TR_ASSERT(_stack[i]->getSymbol()->getDataType() == other->_stack[i]->getSymbol()->getDataType(), "invalid stack merge: primitive type mismatch at same depth stack elements");
         b->Store(other->_stack[i]->getSymbol()->getAutoSymbol()->getName(),
               _stack[i]);
         }
      }
   }

// Allocate a new operand stack and copy everything in this state
// If VirtualMachineOperandStack is subclassed, this function *must* also be implemented in the subclass!
VirtualMachineState *
VirtualMachineOperandStack::MakeCopy()
   {
   VirtualMachineOperandStack *copy = (VirtualMachineOperandStack *) TR::comp()->trMemory()->allocateHeapMemory(sizeof(VirtualMachineOperandStack));
   new (copy) VirtualMachineOperandStack(this);

   return copy;
   }

void
VirtualMachineOperandStack::Push(TR::IlBuilder *b, TR::IlValue *value)
   {
   checkSize();
   _stack[++_stackTop] = value;
   _stackTopRegister->Adjust(b, +_pushAmount);
   }

TR::IlValue *
VirtualMachineOperandStack::Top()
   {
   TR_ASSERT(_stackTop >= 0, "no top: stack empty");
   return _stack[_stackTop];
   }

TR::IlValue *
VirtualMachineOperandStack::Pop(TR::IlBuilder *b)
   {
   TR_ASSERT(_stackTop >= 0, "stack underflow");
   _stackTopRegister->Adjust(b, -_pushAmount);
   return _stack[_stackTop--];
   }

TR::IlValue *
VirtualMachineOperandStack::Pick(int32_t depth)
   {
   TR_ASSERT(_stackTop >= depth, "pick request exceeds stack depth");
   return _stack[_stackTop - depth];
   }

void
VirtualMachineOperandStack::Drop(TR::IlBuilder *b, int32_t depth)
   {
   TR_ASSERT(_stackTop >= depth-1, "stack underflow");
   _stackTop-=depth;
   _stackTopRegister->Adjust(b, -depth * _pushAmount);
   }

void
VirtualMachineOperandStack::Dup(TR::IlBuilder *b)
   {
   TR_ASSERT(_stackTop >= 0, "cannot dup: stack empty");
   TR::IlValue *top = _stack[_stackTop];
   Push(b, top);
   }

void
VirtualMachineOperandStack::copyTo(VirtualMachineOperandStack *copy)
   {
   }

void
VirtualMachineOperandStack::checkSize()
   {
   if (_stackTop == _stackMax - 1)
      grow();
   }

void
VirtualMachineOperandStack::grow(int32_t growAmount)
   {
   if (growAmount == 0)
      growAmount = (_stackMax >> 1);

   // if _stackMax == 1, growAmount would still be zero, so bump to 1
   if (growAmount == 0)
      growAmount = 1;

   int32_t newMax = _stackMax + growAmount;
   int32_t newBytes = newMax * sizeof(TR::IlValue *);
   TR::IlValue ** newStack = (TR::IlValue **) TR::comp()->trMemory()->allocateHeapMemory(newBytes);

   memset(newStack, 0, newBytes);

   int32_t numBytes = _stackMax * sizeof(TR::IlValue *);
   memcpy(newStack, _stack, numBytes);

   _stack = newStack;
   _stackMax = newMax;
   }

} // namespace OMR
