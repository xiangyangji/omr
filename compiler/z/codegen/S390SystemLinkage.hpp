/*******************************************************************************
 *
 * (c) Copyright IBM Corp. 2000, 2016
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

#ifndef Z_SYSTEMLINKAGE_INCL
#define Z_SYSTEMLINKAGE_INCL

/*
 * The following #define and typedef must appear before any #includes in this file
 */
#ifndef Z_SYSTEMLINKAGE_CONNECTOR
#define Z_SYSTEMLINKAGE_CONNECTOR
namespace TR { class S390SystemLinkage; }
namespace OMR { typedef TR::S390SystemLinkage SystemLinkageConnector; }
#endif

#include <stddef.h>                            // for NULL, size_t
#include <stdint.h>                            // for int32_t, uintptr_t, etc
#include "codegen/InstOpCode.hpp"              // for InstOpCode, etc
#include "codegen/Linkage.hpp"                 // for TR_S390AutoMarkers, etc
#include "codegen/LinkageConventionsEnum.hpp"  // for TR_LinkageConventions, etc
#include "codegen/RealRegister.hpp"            // for RealRegister, etc
#include "codegen/Register.hpp"                // for Register
#include "compile/Compilation.hpp"             // for Compilation
#include "env/TRMemory.hpp"                    // for Allocator, etc
#include "env/jittypes.h"                      // for intptrj_t
#include "il/Symbol.hpp"                       // for Symbol
#include "il/SymbolReference.hpp"              // for SymbolReference
#include "il/symbol/AutomaticSymbol.hpp"       // for AutomaticSymbol
#include "infra/Array.hpp"                     // for TR_Array
#include "infra/Assert.hpp"                    // for TR_ASSERT

namespace TR { class S390JNICallDataSnippet; }
namespace TR { class Block; }
namespace TR { class CodeGenerator; }
namespace TR { class Instruction; }
namespace TR { class LabelSymbol; }
namespace TR { class Node; }
namespace TR { class ParameterSymbol; }
namespace TR { class RegisterDependencyConditions; }
namespace TR { class ResolvedMethodSymbol; }
namespace TR { class SystemLinkage; }
template <class T> class List;

namespace TR {

////////////////////////////////////////////////////////////////////////////////
//  TR::S390SystemLinkage Definition
////////////////////////////////////////////////////////////////////////////////
class AllocaPatchGroup
   {
public:
   TR::Instruction *ahi;
   TR::Instruction *mvc;
   TR::Instruction *auxMvc;

   AllocaPatchGroup() : ahi(NULL), mvc(NULL), auxMvc(NULL)
      {
      }
   };

class VaStartPatchGroup
   {
public:
   TR::Instruction * instrToBePatched[4];
   VaStartPatchGroup()
      {
      for (int i = 0; i < 4; ++i)
         instrToBePatched[i] = NULL;
      }
   };


class S390SystemLinkage : public TR::Linkage
   {
   TR::RealRegister::RegNum _normalStackPointerRegister;
   TR::RealRegister::RegNum _alternateStackPointerRegister;
   TR::RealRegister::RegNum _debugHooksRegister;
   int16_t _GPRSaveMask;
   int16_t _FPRSaveMask;
   int16_t _ARSaveMask;
   int16_t _HPRSaveMask;
   int32_t _incomingParmAreaBeginOffset;
   int32_t _incomingParmAreaEndOffset;
   int32_t _FPRSaveAreaBeginOffset;
   int32_t _FPRSaveAreaEndOffset;
   int32_t _ARSaveAreaBeginOffset;
   int32_t _ARSaveAreaEndOffset;
   int32_t _HPRSaveAreaBeginOffset;
   int32_t _HPRSaveAreaEndOffset;
   int32_t _LocalsAreaBeginOffset;
   int32_t _LocalsAreaEndOffset;
   int32_t _OutgoingParmAreaBeginOffset;
   int32_t _OutgoingParmAreaEndOffset;
   int32_t _GPRSaveAreaBeginOffset;
   int32_t _GPRSaveAreaEndOffset;
   int32_t _numUsedArgumentGPRs;
   int32_t _numUsedArgumentFPRs;
   int32_t _numUsedArgumentVFRs;
   int32_t _varArgOffsetInParmArea;
   int32_t _varArgRegSaveAreaOffset;
   int32_t _parmOffsetInLocalArea;
   TR_Array<TR::SymbolReference*> *_autoMarkerSymbols; // symbols that mark points in stackframe

protected:
   int32_t _StackFrameSize;

public:
   TR::SystemLinkage * self();

   virtual int32_t getRegisterSaveOffset(TR::RealRegister::RegNum) = 0;

   int32_t setStackFrameSize(int32_t StackFrameSize)  { return _StackFrameSize = StackFrameSize; }
   virtual int32_t getStackFrameSize()                { return _StackFrameSize; }

   int16_t setGPRSaveMask(int16_t GPRSaveMask)  { return _GPRSaveMask = GPRSaveMask; }
   int16_t getGPRSaveMask()                     { return _GPRSaveMask; }

   int16_t setFPRSaveMask(int16_t FPRSaveMask)  { return _FPRSaveMask = FPRSaveMask; }
   int16_t getFPRSaveMask()                     { return _FPRSaveMask; }

   int16_t setARSaveMask(int16_t ARSaveMask)    { return _ARSaveMask = ARSaveMask; }
   int16_t getARSaveMask()                      { return _ARSaveMask; }

   int16_t setHPRSaveMask(int16_t HPRSaveMask)  { return _HPRSaveMask = HPRSaveMask; }
   int16_t getHPRSaveMask()                     { return _HPRSaveMask; }

   static uint16_t flipBitsRegisterSaveMask(uint16_t mask);

   int32_t setGPRSaveAreaBeginOffset(int32_t GPRSaveAreaBeginOffset)  { return _GPRSaveAreaBeginOffset = GPRSaveAreaBeginOffset; }
   int32_t getGPRSaveAreaBeginOffset()                                { return _GPRSaveAreaBeginOffset; }
   int32_t setGPRSaveAreaEndOffset(int32_t GPRSaveAreaEndOffset)  { return _GPRSaveAreaEndOffset = GPRSaveAreaEndOffset; }
   int32_t getGPRSaveAreaEndOffset()                              { return _GPRSaveAreaEndOffset; }

   int32_t setFPRSaveAreaBeginOffset(int32_t FPRSaveAreaBeginOffset)  { return _FPRSaveAreaBeginOffset = FPRSaveAreaBeginOffset; }
   int32_t getFPRSaveAreaBeginOffset()                                { return _FPRSaveAreaBeginOffset; }
   int32_t setFPRSaveAreaEndOffset(int32_t FPRSaveAreaEndOffset)  { return _FPRSaveAreaEndOffset = FPRSaveAreaEndOffset; }
   int32_t getFPRSaveAreaEndOffset()                              { return _FPRSaveAreaEndOffset; }

   int32_t setARSaveAreaBeginOffset(int32_t ARSaveAreaBeginOffset)    { return _ARSaveAreaBeginOffset = ARSaveAreaBeginOffset; }
   int32_t getARSaveAreaBeginOffset()                                 { return _ARSaveAreaBeginOffset; }
   int32_t setARSaveAreaEndOffset(int32_t ARSaveAreaEndOffset)    { return _ARSaveAreaEndOffset = ARSaveAreaEndOffset; }
   int32_t getARSaveAreaEndOffset()                               { return _ARSaveAreaEndOffset; }

   int32_t setHPRSaveAreaBeginOffset(int32_t HPRSaveAreaBeginOffset)  { return _HPRSaveAreaBeginOffset = HPRSaveAreaBeginOffset; }
   int32_t getHPRSaveAreaBeginOffset()                                { return _HPRSaveAreaBeginOffset; }
   int32_t setHPRSaveAreaEndOffset(int32_t HPRSaveAreaEndOffset)  { return _HPRSaveAreaEndOffset = HPRSaveAreaEndOffset; }
   int32_t getHPRSaveAreaEndOffset()                              { return _HPRSaveAreaEndOffset; }

   int32_t setOutgoingParmAreaBeginOffset(int32_t OutgoingParmAreaBeginOffset)    { return _OutgoingParmAreaBeginOffset = OutgoingParmAreaBeginOffset; }
   int32_t getOutgoingParmAreaBeginOffset()                                 { return _OutgoingParmAreaBeginOffset; }
   int32_t setOutgoingParmAreaEndOffset(int32_t OutgoingParmAreaEndOffset) { return _OutgoingParmAreaEndOffset = OutgoingParmAreaEndOffset; }
   int32_t getOutgoingParmAreaEndOffset()                                  { return _OutgoingParmAreaEndOffset; }

   virtual int32_t setLocalsAreaBeginOffset(int32_t LocalsAreaBeginOffset)    { return _LocalsAreaBeginOffset = LocalsAreaBeginOffset; }
   virtual int32_t getLocalsAreaBeginOffset()                                 { return _LocalsAreaBeginOffset; }
   virtual int32_t setLocalsAreaEndOffset(int32_t LocalsAreaEndOffset)        { return _LocalsAreaEndOffset = LocalsAreaEndOffset; }
   virtual int32_t getLocalsAreaEndOffset()                                   { return _LocalsAreaEndOffset; }

   int32_t setNumUsedArgumentGPRs(int32_t numUsedArgumentGPRs)    { return _numUsedArgumentGPRs = numUsedArgumentGPRs; }
   int32_t getNumUsedArgumentGPRs()  { return _numUsedArgumentGPRs; }

   int32_t setNumUsedArgumentFPRs(int32_t numUsedArgumentFPRs)    { return _numUsedArgumentFPRs = numUsedArgumentFPRs; }
   int32_t getNumUsedArgumentFPRs()  { return _numUsedArgumentFPRs; }

   int32_t setNumUsedArgumentVFRs(int32_t numUsedArgumentVFRs)    { return _numUsedArgumentVFRs = numUsedArgumentVFRs; }
   int32_t getNumUsedArgumentVFRs()  { return _numUsedArgumentVFRs; }

   int32_t setVarArgOffsetInParmArea(int32_t varArgOffsetInParmArea)    { return _varArgOffsetInParmArea = varArgOffsetInParmArea; }
   int32_t getVarArgOffsetInParmArea()  { return _varArgOffsetInParmArea; }

   int32_t setVarArgRegSaveAreaOffset(int32_t varArgRegSaveAreaOffset)    { return _varArgRegSaveAreaOffset = varArgRegSaveAreaOffset; }
   int32_t getVarArgRegSaveAreaOffset()  { return _varArgRegSaveAreaOffset; }

   void setIncomingParmAreaBeginOffset(int32_t offset) { _incomingParmAreaBeginOffset = offset; }
   int32_t getIncomingParmAreaBeginOffset() { return _incomingParmAreaBeginOffset; }
   void setIncomingParmAreaEndOffset(int32_t offset) { _incomingParmAreaEndOffset = offset; }
   int32_t getIncomingParmAreaEndOffset() { return _incomingParmAreaEndOffset; }
   virtual int32_t getIncomingParameterBlockSize() { return _incomingParmAreaEndOffset - _incomingParmAreaBeginOffset; }
   virtual int32_t setParmOffsetInLocalArea(int32_t ParmOffsetInLocalArea)   { return _parmOffsetInLocalArea = ParmOffsetInLocalArea; }
   virtual int32_t getParmOffsetInLocalArea()              { return _parmOffsetInLocalArea; }


   bool        _notifiedOfalloca;
   bool   getNotifiedOfAlloca() { return _notifiedOfalloca; }
   int32_t _allocaParmAreaSize;
   bool                 _notifiedOfDebugHooks;
   bool   getNotifiedOfDebugHooks() { return _notifiedOfDebugHooks; }


public:
   S390SystemLinkage(TR::CodeGenerator * cg, TR_S390LinkageConventions elc=TR_S390LinkageDefault, TR_LinkageConventions lc=TR_System)
      : TR::Linkage(cg, elc,lc),
        _notifiedOfalloca(false),
        _notifiedOfDebugHooks(false),
        _GPRSaveMask(0), _FPRSaveMask(0),_ARSaveMask(0), _HPRSaveMask(0)
      {
      }

   virtual uint32_t
   getIntArgOffset(int32_t index)
      {
      return 0;
      }

   virtual void generateInstructionsForCall(TR::Node * callNode, TR::RegisterDependencyConditions * dependencies,
         intptrj_t targetAddress, TR::Register * methodAddressReg, TR::Register * javaLitOffsetReg, TR::LabelSymbol * returnFromJNICallLabel,
         TR::S390JNICallDataSnippet * jniCallDataSnippet, bool isJNIGCPoint = true);

   virtual TR::Register * callNativeFunction(TR::Node * callNode, TR::RegisterDependencyConditions * dependencies,
      intptrj_t targetAddress, TR::Register * methodAddressReg, TR::Register * javaLitOffsetReg, TR::LabelSymbol * returnFromJNICallLabel, TR::S390JNICallDataSnippet * jniCallDataSnippet,
      bool isJNIGCPoint = true);

   virtual TR::Register *
   buildDirectDispatch(TR::Node * callNode)
      {
      return buildSystemLinkageDispatch(callNode);
      }

   virtual TR::Register *
   buildIndirectDispatch(TR::Node * callNode)
      {
      return buildSystemLinkageDispatch(callNode);
      }

   virtual void mapStack(TR::ResolvedMethodSymbol * symbol);
   virtual void mapStack(TR::ResolvedMethodSymbol * method, uint32_t stackIndex);
   virtual void mapSingleAutomatic(TR::AutomaticSymbol * p, uint32_t & stackIndex);
   virtual bool hasToBeOnStack(TR::ParameterSymbol * parm);

   virtual void notifyHasalloca();

   virtual void createPrologue(TR::Instruction * cursor);
   virtual void createEpilogue(TR::Instruction * cursor);

   virtual TR::Instruction* saveGPRsInPrologue(TR::Instruction * cursor);
   virtual TR::Instruction* saveGPRsInPrologue2(TR::Instruction * cursor);
   virtual TR::Instruction* restoreGPRsInEpilogue(TR::Instruction *cursor);
   virtual TR::Instruction* restoreGPRsInEpilogue2(TR::Instruction *cursor);

   virtual FrameType checkLeafRoutine(int32_t stackFrameSize, TR::Instruction **callInstruction = 0) { return standardFrame; }      // default implementation.  Should be overridden
   virtual FrameType checkLeafRoutine(int32_t stackFrameSize) { return standardFrame; }      // default implementation.  Should be overridden
   virtual void initS390RealRegisterLinkage();

   virtual TR::RealRegister::RegNum setNormalStackPointerRegister  (TR::RealRegister::RegNum r) { return _normalStackPointerRegister = r; }
   virtual TR::RealRegister::RegNum getNormalStackPointerRegister()   { return _normalStackPointerRegister; }
   virtual TR::RealRegister *getNormalStackPointerRealRegister() {return getS390RealRegister(_normalStackPointerRegister);}

   virtual TR::RealRegister::RegNum setAlternateStackPointerRegister  (TR::RealRegister::RegNum r) { return _alternateStackPointerRegister = r; }
   virtual TR::RealRegister::RegNum getAlternateStackPointerRegister()   { return _alternateStackPointerRegister; }
   virtual TR::RealRegister *getAlternateStackPointerRealRegister() {return getS390RealRegister(_alternateStackPointerRegister);}
   virtual void initParamOffset(TR::ResolvedMethodSymbol * method, int32_t stackIndex, List<TR::ParameterSymbol> *parameterList=0);

   // Register used for EX instructions for debug hooks - set by notifyHasHooks
   virtual TR::RealRegister::RegNum setDebugHooksRegister(TR::RealRegister::RegNum r) { return _debugHooksRegister = r; }
   virtual TR::RealRegister::RegNum getDebugHooksRegister()   { return _debugHooksRegister; }
   virtual TR::RealRegister *getDebugHooksRealRegister() {return getS390RealRegister(_debugHooksRegister);}

   virtual TR::SymbolReference *createAutoMarkerSymbol(TR_S390AutoMarkers markerType);
   virtual void setAutoMarkerSymbols(TR_Array<TR::SymbolReference*> *symbols) { _autoMarkerSymbols = symbols; }
   virtual TR::SymbolReference *getAutoMarkerSymbol(TR_S390AutoMarkers markerType) { return _autoMarkerSymbols ? (*_autoMarkerSymbols)[markerType] : 0; }
   virtual void setAutoMarkerSymbolOffset(TR_S390AutoMarkers markerType, int32_t offset) { getAutoMarkerSymbol(markerType)->getSymbol()->castToAutoSymbol()->setOffset(offset); }


   // == General utilities (linkage independent)
   virtual TR::Instruction *addImmediateToRealRegister(TR::RealRegister * targetReg, int32_t immediate, TR::RealRegister *tempReg, TR::Node *node, TR::Instruction *cursor, bool *checkTempNeeded=NULL);
   virtual TR::Instruction *getputFPRs(TR::InstOpCode::Mnemonic opcode, TR::Instruction *cursor, TR::Node *node, TR::RealRegister *spReg=0);
   virtual TR::Instruction *getputARs(TR::InstOpCode::Mnemonic opcode, TR::Instruction *cursor, TR::Node *node, TR::RealRegister *spReg=0);
   virtual TR::Instruction *getputHPRs(TR::InstOpCode::Mnemonic opcode, TR::Instruction *cursor, TR::Node *node, TR::RealRegister *spReg=0);

   };

}

#endif
