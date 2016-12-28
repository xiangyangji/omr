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

#ifndef OMR_X86_MACHINE_INCL
#define OMR_X86_MACHINE_INCL

#ifndef OMR_MACHINEBASE_CONNECTOR
#define OMR_MACHINEBASE_CONNECTOR
namespace OMR { namespace X86 { class Machine; } }
namespace OMR { typedef OMR::X86::Machine MachineConnector; }
#endif

#include "compiler/codegen/OMRMachine.hpp"

#include <stdint.h>                               // for uint8_t, int32_t, etc
#include <string.h>                               // for NULL, memset
#include "codegen/RealRegister.hpp"
#include "codegen/Register.hpp"                   // for Register
#include "codegen/RegisterConstants.hpp"
#include "env/FilePointerDecl.hpp"                // for FILE
#include "env/TRMemory.hpp"                       // for TR_Memory, etc
#include "il/DataTypes.hpp"                       // for DataTypes, etc
#include "infra/Assert.hpp"                       // for TR_ASSERT
#include "x/codegen/X86Ops.hpp"                   // for TR_X86OpCodes
#include "x/codegen/X86Register.hpp"
#include "infra/TRlist.hpp"
class TR_BackingStore;
class TR_Debug;
class TR_FrontEnd;
class TR_OutlinedInstructions;
namespace OMR { class RegisterUsage; }
namespace TR { class CodeGenerator; }
namespace TR { class Instruction; }
namespace TR { class Machine; }
namespace TR { class MemoryReference; }
namespace TR { class Node; }
namespace TR { class RegisterDependencyConditions; }
namespace TR { class SymbolReference; }
namespace TR { struct X86LinkageProperties; }
template <typename ListKind> class List;

#define TR_X86_REGISTER_FILE_SIZE (TR::RealRegister::NumRegisters)


// Encapsulates the state of the register assigner at a particular point
// during assignment.  Includes the state of the register file and all
// live registers.
//
// This does not capture X87 state.
//
class TR_RegisterAssignerState
   {
   TR::Machine *_machine;

   TR::RealRegister **_registerFile;
   TR::Register        **_registerAssociations;
   TR::list<TR::Register*>   *_spilledRegistersList;

   public:

   TR_ALLOC(TR_Memory::Machine)

   TR_RegisterAssignerState(TR::Machine *m) :
      _machine(m),
      _registerFile(NULL),
      _registerAssociations(NULL),
      _spilledRegistersList(NULL) {}

   void capture();
   void install();
   TR::RegisterDependencyConditions *createDependenciesFromRegisterState(TR_OutlinedInstructions *oi);
   bool isLive(TR::Register *virtReg);

   void dump();

   };

namespace OMR
{

namespace X86
{

class OMR_EXTENSIBLE Machine : public OMR::Machine
   {
   TR::RealRegister  **_registerFile;
   TR::Register         **_registerAssociations;

   // Floating point stack pseudo-registers: they can be mapped to real
   // registers on demand, based on their relative position from the top of
   // stack marker.
   //
   TR_X86FPStackRegister  *_fpStack[TR_X86FPStackRegister::NumRegisters];

   TR_X86FPStackRegister  *_fpRegisters[TR_X86FPStackRegister::NumRegisters];
   TR_X86FPStackRegister  *_copiedFpRegisters[TR_X86FPStackRegister::NumRegisters];
   TR::Node                *_fpRegisterNodes[TR_X86FPStackRegister::NumRegisters];

   TR::Register            **_xmmGlobalRegisters;

   List<TR::Register>      *_spilledRegistersList;

   TR::SymbolReference     *_dummyLocal[TR::NumTypes];
   TR::CodeGenerator *_cg;

   int32_t                 _fpStackShape[TR_X86FPStackRegister::NumRegisters];
   int32_t                 _fpTopOfStack;

   void initialiseFPStackRegisterFile();

   protected:

   uint32_t *_globalRegisterNumberToRealRegisterMap;


   public:
   void initialiseRegisterFile(const struct TR::X86LinkageProperties&);
   uint32_t* getGlobalRegisterTable(const struct TR::X86LinkageProperties&);
   int32_t getGlobalReg(TR::RealRegister::RegNum reg);

   TR::RealRegister *getX86RealRegister(TR::RealRegister::RegNum regNum)
      {
      return _registerFile[regNum];
      }

   TR::RealRegister **cloneRegisterFile(TR::RealRegister **registerFile, TR_AllocationKind allocKind = heapAlloc);
   TR::RealRegister **getRegisterFile() { return _registerFile; }
   TR::RealRegister **setRegisterFile(TR::RealRegister **r) { return _registerFile = r; }

   TR::RealRegister **captureRegisterFile();
   void installRegisterFile(TR::RealRegister **registerFileCopy);
   TR::Register **captureRegisterAssociations();
   TR::list<TR::Register*> *captureSpilledRegistersList();

   void purgeDeadRegistersFromRegisterFile();
   void adjustRegisterUseCountsUp(TR::list<OMR::RegisterUsage *> *rul, bool adjustFuture);
   void adjustRegisterUseCountsDown(TR::list<OMR::RegisterUsage *> *rul, bool adjustFuture);
   void disassociateUnspilledBackingStorage();

   TR::Register **getRegisterAssociations() { return _registerAssociations; }
   void setRegisterAssociations(TR::Register **ra) { _registerAssociations = ra; }

   TR::Register *getVirtualAssociatedWithReal(TR::RealRegister::RegNum regNum)
       {
       return _registerAssociations[regNum];
       }

   TR::Register *setVirtualAssociatedWithReal(TR::RealRegister::RegNum regNum, TR::Register *virtReg)
       {
       return (_registerAssociations[regNum] = virtReg);
       }

   List<TR::Register> *getSpilledRegistersList() { return _spilledRegistersList; }
   void setSpilledRegistersList(List<TR::Register> *srl) { _spilledRegistersList = srl; }

   TR::RealRegister *findBestFreeGPRegister(TR::Instruction   *currentInstruction,
                                            TR::Register      *virtReg,
                                            TR_RegisterSizes   requestedRegSize = TR_WordReg,
                                            bool               considerUnlatched = false);

   TR::RealRegister *freeBestGPRegister(TR::Instruction           *currentInstruction,
                                        TR::Register              *virtReg,
                                        TR_RegisterSizes           requestedRegSize = TR_WordReg,
                                        TR::RealRegister::RegNum   targetRegister = TR::RealRegister::NoReg,
                                        bool                       considerVirtAsSpillCandidate = false);

   TR::RealRegister *reverseGPRSpillState(TR::Instruction   *currentInstruction,
                                          TR::Register      *spilledRegister,
                                          TR::RealRegister  *targetRegister = NULL,
                                          TR_RegisterSizes   requestedRegSize = TR_WordReg);

   void coerceXMMRegisterAssignment(TR::Instruction           *currentInstruction,
                                    TR::Register              *virtualRegister,
                                    TR::RealRegister::RegNum   registerNumber,
                                    bool                       coerceToSatisfyRegDeps = false);

   void coerceGPRegisterAssignment(TR::Instruction           *currentInstruction,
                                   TR::Register              *virtualRegister,
                                   TR::RealRegister::RegNum   registerNumber,
                                   bool                       coerceToSatisfyRegDeps = false);

   void coerceGPRegisterAssignment(TR::Instruction   *currentInstruction,
                                   TR::Register      *virtualRegister,
                                   TR_RegisterSizes   requestedRegSize = TR_WordReg);

   void swapGPRegisters(TR::Instruction           *currentInstruction,
                        TR::RealRegister::RegNum   regNum1,
                        TR::RealRegister::RegNum   regNum2);

   void clearRegisterAssociations()
      {
      memset(_registerAssociations, 0, sizeof(TR::Register *) * TR::RealRegister::NumRegisters);
      }

   void setGPRWeightsFromAssociations();

   void createRegisterAssociationDirective(TR::Instruction *cursor);

   //
   // Methods to support the IA32 floating point register stack.
   //

   TR_X86OpCodes fpDeterminePopOpCode(TR_X86OpCodes op);
   TR_X86OpCodes fpDetermineReverseOpCode(TR_X86OpCodes op);

   TR::MemoryReference  *getDummyLocalMR(TR::DataType dt);

   TR::RealRegister *fpMapToStackRelativeRegister(TR::Register *vreg);

   TR::RealRegister *fpMapToStackRelativeRegister(int32_t stackReg)
      {
      return _registerFile[stackReg + TR::RealRegister::FirstFPR];
      }

   int32_t                 getFPTopOfStack() {return _fpTopOfStack;}
   TR_X86FPStackRegister  *getFPTopOfStackPtr() {return (_fpTopOfStack > TR_X86FPStackRegister::fpStackEmpty &&
                                                         _fpTopOfStack < TR_X86FPStackRegister::fpStackFull) ?
                                                            _fpStack[_fpTopOfStack] : NULL; }
   TR_X86FPStackRegister  *getFPStackLocationPtr(int32_t location) {return (location > TR_X86FPStackRegister::fpStackEmpty &&
                                                                            location < TR_X86FPStackRegister::fpStackFull) ?
                                                                            _fpStack[location] : NULL; }

   void                    setFPTopOfStack(TR::Register *vreg);

   bool isFPStackFull() { return (_fpTopOfStack+1 == TR_X86FPStackRegister::fpStackFull) ? true : false; }
   bool isFPRTopOfStack(TR::Register *virtReg);

   uint8_t fpGetNumberOfLiveFPRs()  {return _fpTopOfStack+1;}
   uint8_t fpGetNumberOfLiveXMMRs() {return 0;}

   TR_X86FPStackRegister *getFPStackRegister(int32_t location) {return _fpRegisters[location];}
   void setFPStackRegister(int32_t location, TR_X86FPStackRegister *reg) {_fpRegisters[location] = reg; }
   TR_X86FPStackRegister *getCopiedFPStackRegister(int32_t location) {return _copiedFpRegisters[location];}
   void setCopiedFPStackRegister(int32_t location, TR_X86FPStackRegister *reg) {_copiedFpRegisters[location] = reg; }
   TR::Node *getFPStackRegisterNode(int32_t location) {return _fpRegisterNodes[location];}
   void setFPStackRegisterNode(int32_t location, TR::Node *node) {_fpRegisterNodes[location] = node; }

   void resetFPStackRegisters();

   int32_t *getFPStackShape() {return _fpStackShape;}

   void fpStackPush(TR::Register *virtReg);
   void fpStackCoerce(TR::Register *virtReg, int32_t location);
   TR::Register *fpStackPop();
   void popEntireStack();

   TR::Instruction  *fpStackFXCH(TR::Instruction *currentInstruction,
                                   TR::Register    *virtReg,
                                   bool            generateCode = true);

   TR::Instruction  *fpStackFXCH(TR::Instruction *currentInstruction,
                                   int32_t         stackReg);

   void fpCoerceRegistersToTopOfStack(TR::Instruction *currentInstruction,
                                      TR::Register    *X,
                                      TR::Register    *Y,
                                      bool            strict);

   TR_X86FPStackRegister *findFreeFPRegister();
   TR::Instruction *freeBestFPRegister(TR::Instruction *);
   TR::Instruction *reverseFPRSpillState(TR::Instruction *currentInstruction,
                                        TR::Register    *spilledRegister);
   TR::Instruction *fpSpillFPR(TR::Instruction *precedingInstruction,
                              TR::Register    *vreg);
   TR::Instruction *fpSpillStack(TR::Instruction *precedingInstruction);

   TR::Register *getXMMGlobalRegister(int32_t regNum)                   {return _xmmGlobalRegisters[regNum];}
   void         setXMMGlobalRegister(int32_t regNum, TR::Register *reg) {_xmmGlobalRegisters[regNum] = reg;}

   void resetXMMGlobalRegisters();

   TR_Debug         *getDebug();
   TR::CodeGenerator *cg() {return _cg;}

   uint8_t _numGlobalGPRs, _numGlobal8BitGPRs, _numGlobalFPRs;

   // TODO:AMD64: Are these two still correct?  What are they?
   uint8_t getGlobalGPRPartitionLimit() {return 2;}
   uint8_t getGlobalFPRPartitionLimit() {return 0;}

   TR_GlobalRegisterNumber getNumGlobalGPRs()
      {return _numGlobalGPRs;}

   TR_GlobalRegisterNumber getLastGlobalGPRRegisterNumber()
      {return _numGlobalGPRs - 1;}

   TR_GlobalRegisterNumber getLast8BitGlobalGPRRegisterNumber()
      {return _numGlobal8BitGPRs - 1;}

   TR_GlobalRegisterNumber getLastGlobalFPRRegisterNumber()
      {return _numGlobalGPRs + _numGlobalFPRs - 1;}

   TR::RegisterDependencyConditions  *createDepCondForLiveGPRs();
   TR::RegisterDependencyConditions  *createCondForLiveAndSpilledGPRs(bool cleanRegState, TR::list<TR::Register*> *spilledRegisterList = NULL);

#if defined(DEBUG)
   void printGPRegisterStatus(TR_FrontEnd *, TR::RealRegister **registerFile, TR::FILE *pOutFile);
   void printFPRegisterStatus(TR_FrontEnd *, TR::FILE *pOutFile);
#endif

   protected:

   Machine
      (
      uint8_t numIntRegs,
      uint8_t numFPRegs,
      TR::CodeGenerator *cg,
      TR::RealRegister **registerFile,
      TR::Register **registerAssociations,
      uint8_t numGlobalGPRs,
      uint8_t numGlobal8BitGPRs,
      uint8_t numGlobalFPRs,
      TR::Register **xmmGlobalRegisters,
      uint32_t *globalRegisterNumberToRealRegisterMap
      );

   };
}
}
#endif
