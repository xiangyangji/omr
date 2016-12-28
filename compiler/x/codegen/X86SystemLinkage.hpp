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

#ifndef X86SYSTEMLINKAGE_INCL
#define X86SYSTEMLINKAGE_INCL

#include <stdint.h>                         // for int32_t, uint16_t, etc
#include "codegen/Linkage.hpp"              // for Linkage, etc
#include "codegen/Register.hpp"             // for Register
#include "codegen/RegisterConstants.hpp"    // for TR_RegisterKinds
#include "il/DataTypes.hpp"                 // for DataTypes

namespace TR { class CodeGenerator; }
namespace TR { class Instruction; }
namespace TR { class Node; }
namespace TR { class ParameterSymbol; }
namespace TR { class RegisterDependencyConditions; }
namespace TR { class ResolvedMethodSymbol; }

namespace TR {

typedef struct parmLayoutResult
   {
   enum statusEnum
      {
      IN_LINKAGE_REG = 0x1,
      IN_LINKAGE_REG_PAIR = 0x2, // Only on AMD64 SysV ABI: a struct might take 2 linkage registers.
      ON_STACK = 0x4,
      };
   uint8_t abstract;
   uint32_t offset;
   struct
      {
      TR_RegisterKinds regKind;
      uint16_t regIndex;
      } regs[2];
   parmLayoutResult()
      {
      abstract = (statusEnum)0;
      offset =0;
      regs[0].regKind = regs[1].regKind = (TR_RegisterKinds)-1;
      regs[0].regIndex = regs[1].regIndex = (uint16_t)-1;
      }
   } parmLayoutResult;

class X86SystemLinkage : public TR::Linkage
   {
   protected:
   X86SystemLinkage(TR::CodeGenerator *cg);

   TR::X86LinkageProperties _properties;

   TR::Instruction* copyParametersToHomeLocation(TR::Instruction *cursor);

   TR::Instruction* savePreservedRegisters(TR::Instruction *cursor);
   TR::Instruction* restorePreservedRegisters(TR::Instruction *cursor);

   virtual void createPrologue(TR::Instruction *cursor);
   virtual void createEpilogue(TR::Instruction *cursor);

   int32_t computeMemoryArgSize(TR::Node *callNode, int32_t first, int32_t last, int8_t direction);
   int32_t getParameterStartingPos(int32_t &dataCursor, uint32_t align);
   int32_t layoutTypeOnStack(TR::DataType, int32_t&, TR::parmLayoutResult&);
   virtual int32_t buildArgs(TR::Node *callNode, TR::RegisterDependencyConditions *deps) = 0;
   virtual uint32_t getAlignment(TR::DataType) = 0;
   virtual int32_t layoutParm(TR::Node *parmNode, int32_t &dataCursor, uint16_t &intReg, uint16_t &floatReg, TR::parmLayoutResult &layoutResult) = 0;
   virtual int32_t layoutParm(TR::ParameterSymbol *paramSymbol, int32_t &dataCursor, uint16_t &intReg, uint16_t &floatRrgs, TR::parmLayoutResult&) = 0;

   virtual TR::Register* buildVolatileAndReturnDependencies(TR::Node*, TR::RegisterDependencyConditions*) = 0;
   public:

   const TR::X86LinkageProperties& getProperties();

   virtual TR::Register *buildIndirectDispatch(TR::Node *callNode) = 0;
   virtual TR::Register *buildDirectDispatch(TR::Node *callNode, bool spillFPRegs) = 0;

   virtual void mapIncomingParms(TR::ResolvedMethodSymbol *method);
   virtual void mapIncomingParms(TR::ResolvedMethodSymbol *method, uint32_t &stackIndex) { mapIncomingParms(method); };


   virtual void copyLinkageInfoToParameterSymbols();
   virtual void copyGlRegDepsToParameterSymbols(TR::Node *bbStart, TR::CodeGenerator *cg);

   virtual void setUpStackSizeForCallNode(TR::Node *node) = 0;
   };

inline TR::X86SystemLinkage *toX86SystemLinkage(TR::Linkage *l) {return (TR::X86SystemLinkage *)l;}

}

#endif
