/*******************************************************************************
 *
 * (c) Copyright IBM Corp. 2014, 2016
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

#include "compile/Method.hpp"
#include "compile/Compilation.hpp"
#include "il/SymbolReference.hpp"
#include "il/symbol/ParameterSymbol.hpp"
#include "ilgen/TypeDictionary.hpp"
#include "ilgen/IlInjector.hpp"
#include "ilgen/IlBuilder.hpp"
#include "ilgen/MethodBuilder.hpp"
#include "ilgen/IlGeneratorMethodDetails_inlines.hpp"

namespace JitBuilder
{

// needs major overhaul
ResolvedMethod::ResolvedMethod(TR_OpaqueMethodBlock *method)
   {
   // trouble! trouble! where do we get TypeDictionary from now?
   _ilInjector = reinterpret_cast<TR::IlInjector *>(method);

   TR::ResolvedMethod * resolvedMethod = (TR::ResolvedMethod *)_ilInjector->methodSymbol()->getResolvedMethod();
   _fileName = resolvedMethod->classNameChars();
   _name = resolvedMethod->nameChars();
   _numParms = resolvedMethod->getNumArgs();
   _parmTypes = resolvedMethod->_parmTypes;
   _lineNumber = resolvedMethod->getLineNumber();
   _returnType = resolvedMethod->returnIlType();
   _signature = resolvedMethod->getSignature();
   _entryPoint = resolvedMethod->getEntryPoint();
   strncpy(_signatureChars, resolvedMethod->signatureChars(), 62); // TODO: introduce concept of robustness
   }

ResolvedMethod::ResolvedMethod(TR::MethodBuilder *m)
   : _fileName(m->getDefiningFile()),
     _lineNumber(m->getDefiningLine()),
     _name((char *)m->getMethodName()), // sad cast
     _numParms(m->getNumParameters()),
     _parmTypes(m->getParameterTypes()),
     _returnType(m->getReturnType()),
     _entryPoint(0),
     _signature(0),
     _ilInjector(static_cast<TR::IlInjector *>(m))
   {
   computeSignatureChars();
   }

const char *
ResolvedMethod::signature(TR_Memory * trMemory, TR_AllocationKind allocKind)
   {
   if( !_signature )
      {
      char * s = (char *)trMemory->allocateMemory(strlen(_fileName) + 1 + strlen(_lineNumber) + 1 + strlen(_name) + 1, allocKind);
      sprintf(s, "%s:%s:%s", _fileName, _lineNumber, _name);

      if ( allocKind == heapAlloc)
        _signature = s;

      return s;
      }
   else
      return _signature;
   }

TR::DataType
ResolvedMethod::parmType(uint32_t slot)
   {
   TR_ASSERT((slot < _numParms), "Invalid slot provided for Parameter Type");
   return _parmTypes[slot]->getPrimitiveType();
   }

void
ResolvedMethod::computeSignatureChars()
   {
   char *name=NULL;
   uint32_t len=3;
   for (int32_t p=0;p < _numParms;p++)
      {
      TR::IlType *type = _parmTypes[p];
      len += strlen(type->getSignatureName());
      }
   len += strlen(_returnType->getSignatureName());
   TR_ASSERT(len < 64, "signature array may not be large enough"); // TODO: robustness

   int32_t s = 0;
   _signatureChars[s++] = '(';
   for (int32_t p=0;p < _numParms;p++)
      {
      name = _parmTypes[p]->getSignatureName();
      len = strlen(name);
      strncpy(_signatureChars+s, name, len);
      s += len;
      }
   _signatureChars[s++] = ')';
   name = _returnType->getSignatureName();
   len = strlen(name);
   strncpy(_signatureChars+s, name, len);
   s += len;
   _signatureChars[s++] = 0;
   }

void
ResolvedMethod::makeParameterList(TR::ResolvedMethodSymbol *methodSym)
   {
   ListAppender<TR::ParameterSymbol> la(&methodSym->getParameterList());
   TR::ParameterSymbol *parmSymbol;
   int32_t slot = 0;
   int32_t ordinal = 0;

   uint32_t parmSlots = numberOfParameterSlots();
   for (int32_t parmIndex = 0; parmIndex < parmSlots; ++parmIndex)
      {
      TR::IlType *type = _parmTypes[parmIndex];
      TR::DataType dt = type->getPrimitiveType();
      int32_t size = methodSym->convertTypeToSize(dt);

      parmSymbol = methodSym->comp()->getSymRefTab()->createParameterSymbol(methodSym, slot, type->getPrimitiveType(), false);
      parmSymbol->setOrdinal(ordinal++);

      char *s = type->getSignatureName();
      uint32_t len = strlen(s);
      parmSymbol->setTypeSignature(s, len);

      la.add(parmSymbol);

      ++slot;
      }

   int32_t lastInterpreterSlot = slot + numberOfTemps();
   methodSym->setTempIndex(lastInterpreterSlot, methodSym->comp()->fe());
   methodSym->setFirstJitTempIndex(methodSym->getTempIndex());
   }

char *
ResolvedMethod::localName(uint32_t slot,
                          uint32_t bcIndex,
                          int32_t &nameLength,
                          TR_Memory *trMemory)
   {
   char *name=NULL;
   if (_ilInjector != NULL && _ilInjector->isMethodBuilder())
      {
      TR::MethodBuilder *bldr = _ilInjector->asMethodBuilder();
      name = (char *) bldr->getSymbolName(slot);
      if (name == NULL)
         {
         name = "";
         }
      }
   else
      {
      name = (char *) trMemory->allocateHeapMemory(8 * sizeof(char));
      sprintf(name, "Parm %2d", slot);
      }

   nameLength = strlen(name);
   return name;
   }

TR::IlInjector *
ResolvedMethod::getInjector (TR::IlGeneratorMethodDetails * details,
   TR::ResolvedMethodSymbol *methodSymbol,
   TR::FrontEnd *fe,
   TR::SymbolReferenceTable *symRefTab)
   {
   _ilInjector->initialize(details, methodSymbol, fe, symRefTab);
   return _ilInjector;
   }

TR::DataType
ResolvedMethod::returnType()
   {
   return _returnType->getPrimitiveType();
   }
} // namespace JitBuilder
