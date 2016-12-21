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

#ifndef OMR_VIRTUALMACHINEREGISTERINSTRUCT_INCL
#define OMR_VIRTUALMACHINEREGISTERINSTRUCT_INCL

#include "ilgen/VirtualMachineRegister.hpp"
#include "ilgen/IlBuilder.hpp"

namespace OMR
{

/**
 * @brief used to represent virtual machine variables that are maintained in a structure stored in a local variable, such as a thread or frame object passed as a parameter to the method
 *
 * The value does not need to be a virtual machine register, but often it is the registers
 * of the virtual machine that are candidates for VirtualMachineRegisterInStruct. An
 * alternative is VirtualMachineRegister, which can be more convenient if the virtual
 * machine value is stored in a more arbitrary place or in a structure that isn't readily
 * accessible inside the compiled method. 
 * VirtualMachineRegisterInStruct is a subclass of VirtualMachineRegister
 *
 * The simulated register value is simply stored in a single local variable, which
 * gives the compiler visibility to all changes to the register (and enables
 * optimization / simplification). Because there is just a single local variable,
 * the Merge() function does not need to do anything (the value is accessible from
 * the same location at all locations). The Commit() and Reload() functions simply
 * move the value back and forth between the local variable and the structure that
 * holds the actual virtual machine state.
 */

class VirtualMachineRegisterInStruct : public ::OMR::VirtualMachineRegister
   {
   public:
   /**
    * @brief public constructor used to create a virtual machine state variable from struct
    * @param b a builder object where the first Reload operations will be inserted
    * @param structName the name of the struct type that holds the virtual machine state variable
    * @param localNameHoldingStructAddress is the name of a local variable holding the struct base address; it must have been stored in this name before control will reach the builder "b"
    * @param fieldName name of the field in "structName" that holds the virtual machine state variable
    * @param localName the name of the local variable where the simulated value is to be stored
    */
   VirtualMachineRegisterInStruct(TR::IlBuilder *b,
                          const char * const structName,
                          const char * const localNameHoldingStructAddress,
                          const char * const fieldName,
                          const char * const localName) :
      ::OMR::VirtualMachineRegister(localName),
      _structName(structName),
      _fieldName(fieldName),
      _localNameHoldingStructAddress(localNameHoldingStructAddress)
      {
      _elementType = b->typeDictionary()->GetFieldType(structName, fieldName)->baseType();
      _adjustByStep = _elementType->getSize();
      Reload(b);
      }

   /**
    * @brief write the simulated register value to the proper field in the struct
    * @param b a builder object where the operations to do the write will be inserted
    */
   virtual void Commit(TR::IlBuilder *b)
      {
      b->StoreIndirect(_structName, _fieldName,
      b->   Load(_localNameHoldingStructAddress),
      b->   Load(_localName));
      }

   /**
    * @brief read the simulated register value from the proper field in the struct
    * @param b a builder object where the operations to do the write will be inserted
    */
   virtual void Reload(TR::IlBuilder *b)
      {
      b->Store(_localName,
      b->   LoadIndirect(_structName, _fieldName,
      b->      Load(_localNameHoldingStructAddress)));
      }

   private:

   const char * const _structName;
   const char * const _fieldName;
   const char * const _localNameHoldingStructAddress;
   };
}

#endif // !defined(OMR_VIRTUALMACHINEREGISTERINSTRUCT_INCL)
