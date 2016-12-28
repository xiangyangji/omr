/*******************************************************************************
 *
 * (c) Copyright IBM Corp. 2016, 2016
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
 ******************************************************************************/


#include <iostream>
#include <stdlib.h>
#include <stdint.h>
#include <dlfcn.h>
#include <errno.h>

#include "Jit.hpp"
#include "ilgen/TypeDictionary.hpp"
#include "ilgen/MethodBuilder.hpp"
#include "TransactionalOperations.hpp"

using std::cout;
using std::cerr;

int
main(int argc, char *argv[])
   {
   cout << "Step 1: initialize JIT\n";
   bool initialized = initializeJit();
   if (!initialized)
      {
      cerr << "FAIL: could not initialize JIT\n";
      exit(-1);
      }

   cout << "Step 2: define type dictionary\n";
   TR::TypeDictionary types;

   cout << "Step 3: compile method builder\n";
   TransactionalMethod method(&types);
   uint8_t *entry = 0;
   int32_t rc = compileMethodBuilder(&method, &entry);
   if (rc != 0)
      {
      cerr << "FAIL: compilation error " << rc << "\n";
      exit(-2);
      }

   cout << "Step 4: invoke compiled code and print results\n";
   typedef int32_t (TransactionalMethodFunction)(int32_t*);
   TransactionalMethodFunction *transaction_increment = (TransactionalMethodFunction *) entry;

   int32_t v;
   v=0;   cout << "transaction_increment(" << v; cout << ") == " << transaction_increment(&v) << "\n";
   v=1;   cout << "transaction_increment(" << v; cout << ") == " << transaction_increment(&v) << "\n";
   v=10;  cout << "transaction_increment(" << v; cout << ") == " << transaction_increment(&v) << "\n";
   v=-15; cout << "transaction_increment(" << v; cout << ") == " << transaction_increment(&v) << "\n";

   cout << "Step 5: shutdown JIT\n";
   shutdownJit();
   }



TransactionalMethod::TransactionalMethod(TR::TypeDictionary *d)
   : MethodBuilder(d)
   {
   DefineLine(LINETOSTR(__LINE__));
   DefineFile(__FILE__);

   DefineName("transaction_increment");
   pInt32=d->PointerTo(Int32);
   DefineParameter("addressOfValue", pInt32);
   DefineReturnType(Int32);
   
   }

/**
 * This test case has been tested on both platform supporting TM and the one not.
 * If any update in the future based on this version, it's supposed to be tested on both platforms as well.
 *
 * 1) If the processor doesn't support TM, Transaction() service will choose to use persistenFailure path
 *    directly.  
 * 2) Otherwise, we will go with normal Transaction.
 *
 * Note: users always need to provide all persistentFailure(persistentBuilder), transientFailure(transientBuilder) and fallthrough(transactionBuilder) paths.
 */
bool
TransactionalMethod::buildIL()
   {
   cout << "TransactionalMethod::buildIL() running!\n";

   TR::IlBuilder *persistentBuilder=NULL;
   TR::IlBuilder *transientBuilder=NULL;
   TR::IlBuilder *transactionBuilder=NULL; 

   Transaction(&persistentBuilder, &transientBuilder, &transactionBuilder);
   
   //Either the processor doesn't support TM or persistently fail from Transaction()
   //we will use atomic implementation directly 
   persistentBuilder->AtomicAdd(persistentBuilder->IndexAt(pInt32, persistentBuilder->Load("addressOfValue"), persistentBuilder->ConstInt32(0)),
           				        persistentBuilder->ConstInt32(1));

   //For simplicity, temporary failures are not handled specially and are just treated the same as persistent failures 
   transientBuilder->Goto(&persistentBuilder);

   //if success, use non-atomic way to increment. Store the result of Add() in the position.
   transactionBuilder->StoreAt(transactionBuilder->IndexAt(pInt32,transactionBuilder->Load("addressOfValue"), transactionBuilder->ConstInt32(0)),
                               transactionBuilder->Add(transactionBuilder->LoadAt(pInt32, transactionBuilder->IndexAt(pInt32, transactionBuilder->Load("addressOfValue"), transactionBuilder->ConstInt32(0))),
                                         transactionBuilder->ConstInt32(1)));

   Return(LoadAt(pInt32, Load("addressOfValue")));

   return true;

   }

