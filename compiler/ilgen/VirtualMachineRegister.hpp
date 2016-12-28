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

#ifndef OMR_VIRTUALMACHINEREGISTER_INCL
#define OMR_VIRTUALMACHINEREGISTER_INCL


#include "ilgen/VirtualMachineState.hpp"
#include "ilgen/IlBuilder.hpp"
#include "ilgen/TypeDictionary.hpp"

namespace TR { class IlBuilder; }

namespace OMR
{

/**
 * @brief simulate virtual machine state variable via an address
 * 
 * VirtualMachineRegister can be used to represent values in the virtual machine
 * at any address. The value does not need to be a virtual machine register, but
 * often it is the registers of the virtual machine that are candidates for
 * VirtualMachineRegister. An alternative is VirtualMachineRegisterInStruct,
 * which may be more convenient if the virtual machine value is stored in a
 * structure that the compiled method has easy access to (for example, if the
 * base address of the struct is a parameter of every compiled method such as
 * a "thread" structure or a "frame" structure).
 *
 * The simulated register value is simply stored in a single local variable in the
 * native stack frame, which gives the compiler visibility to all changes to the
 * register (and enables dataflow optimization / simplification). Because there is
 * just a single local variable, the CopyState() and MergeInto() functions do not
 * need to do anything (the value can accessible from that variable at all program
 * locations). The Commit() and Reload() functions simply move the value back and
 * forth between the local variable and the address of the actual virtual machine
 * state variable.
 *
 * VirtualMachineRegister provides two additional functions:
 * Load() will load the *simulated* value of the register for use in the builder "b"
 * Store() will store the provided "value" into the *simulated* register by
 * appending to the builder "b"
 */

class VirtualMachineRegister : public OMR::VirtualMachineState
   {
   protected:
   /**
    * @brief constructor can be used by subclasses to initialize just the const pointer
    * @param localName the name of the local variable where the simulated value is to be stored
    */
   VirtualMachineRegister(const char * const localName)
      : OMR::VirtualMachineState(),
      _localName(localName)
      { }

   public:
   /**
    * @brief public constructor used to create a virtual machine state variable
    * @param b a builder object where the first Reload operations will be inserted
    * @param localName the name of the local variable where the simulated value is to be stored
    * @param pointerToRegisterType must be pointer to the type of the register
    * @param adjustByStep is a multiplier for the value passed to Adjust()
    * @param addressOfRegister is the address of the actual register
    */
   VirtualMachineRegister(TR::IlBuilder *b,
                          const char * const localName,
                          TR::IlType * pointerToRegisterType,
                          uint32_t adjustByStep,
                          TR::IlValue * addressOfRegister)
      : OMR::VirtualMachineState(),
      _localName(localName),
      _addressOfRegister(addressOfRegister),
      _pointerToRegisterType(pointerToRegisterType),
      _elementType(pointerToRegisterType->baseType()),
      _adjustByStep(adjustByStep)
      {
      Reload(b);
      }

  
   /**
    * @brief write the simulated register value to the virtual machine
    * @param b the builder where the operation will be placed to store the virtual machine value
    */
   virtual void Commit(TR::IlBuilder *b)
      {
      b->StoreAt(
            _addressOfRegister,
      b->   Load(_localName));
      }

   /**
    * @brief transfer the current virtual machine register value to the simulated local variable
    * @param b the builder where the operation will be placed to load the virtual machine value
    */
   virtual void Reload(TR::IlBuilder *b)
      {
      b->Store(_localName,
      b->   LoadAt((TR::IlType *)_pointerToRegisterType,
               _addressOfRegister));
      }

   /**
    * @brief used in the compiled method to load the (simulated) register's value
    * @param b the builder where the operation will be placed to load the simulated value
    * @returns TR:IlValue * for the loaded simulated register value
    */
   TR::IlValue *Load(TR::IlBuilder *b)
      {
      return b->Load(_localName);
      }

   /**
    * @brief used in the compiled method to store to the (simulated) register's value
    * @param b the builder where the operation will be placed to store to the simulated value
    */
   void Store(TR::IlBuilder *b, TR::IlValue *value)
      {
      b->Store(_localName, value);
      }

   /**
    * @brief used in the compiled method to add to the (simulated) register's value
    * @param b the builder where the operation will be placed to add to the simulated value
    * @param amount the TR::IlValue that should be added to the simulated value, after multiplication by _adjustByStep
    * Adjust() is really a convenience function for the common operation of adding a value to the register. More
    * complicated operations (e.g. multiplying the value) can be built using Load() and Store() if needed.
    */
   virtual void Adjust(TR::IlBuilder *b, TR::IlValue *amount)
      {
      TR::IlValue *off=b->Mul(amount,
                       b->    ConstInteger(_elementType, _adjustByStep));
      adjust(b, off);
      }

   /**
    * @brief used in the compiled method to add to the (simulated) register's value
    * @param b the builder where the operation will be placed to add to the simulated value
    * @param amount the constant value that should be added to the simulated value, after multiplication by _adjustByStep
    * Adjust() is really a convenience function for the common operation of adding a value to the register. More
    * complicated operations (e.g. multiplying the value) can be built using Load() and Store() if needed.
    */
   virtual void Adjust(TR::IlBuilder *b, int64_t amount)
      {
      adjust(b, b->ConstInteger(_elementType, amount * _adjustByStep));
      }

   protected:
   void adjust(TR::IlBuilder *b, TR::IlValue *rawAmount)
      {
      b->Store(_localName,
      b->   Add(
      b->      Load(_localName),
               rawAmount));
      }
   const char  * const _localName;
   TR::IlValue * _addressOfRegister;
   TR::IlType  * _pointerToRegisterType;
   TR::IlType  * _elementType;
   uint32_t      _adjustByStep;
   };
}

#endif // !defined(OMR_VIRTUALMACHINEREGISTER_INCL)
