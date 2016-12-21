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
 ******************************************************************************/

#ifndef OMR_REGISTERMAPPEDSYMBOL_INCL
#define OMR_REGISTERMAPPEDSYMBOL_INCL

/*
 * The following #define and typedef must appear before any #includes in this file
 */
#ifndef OMR_REGISTERMAPPEDSYMBOL_CONNECTOR
#define OMR_REGISTERMAPPEDSYMBOL_CONNECTOR
namespace OMR { class RegisterMappedSymbol; }
namespace OMR { typedef OMR::RegisterMappedSymbol RegisterMappedSymbolConnector; }
#endif

#include "il/Symbol.hpp"

#include <stdint.h>          // for int32_t, etc
#include "il/DataTypes.hpp"  // for DataTypes
#include "infra/Assert.hpp"  // for TR_ASSERT

class TR_FrontEnd;
namespace TR { class RegisterMappedSymbol; }
namespace TR { class SymbolReference; }

/**
 * Selects a register to be used
 */
enum TR_MethodMetaDataType
   {
   TR_MethodMetaDataType_Default,
   TR_MethodMetaDataType_GPR,
   TR_MethodMetaDataType_FPR,
   TR_MethodMetaDataType_AR,
   TR_MethodMetaDataType_CR,
   TR_MethodMetaDataType_SegR,
   };


namespace OMR
{
/**
 * RegisterMappedSymbols are those that may reside in a register
 *
 * \todo Concept doesn't have the best name, and should likely be renamed
 */
class OMR_EXTENSIBLE RegisterMappedSymbol : public TR::Symbol
   {

protected:

   RegisterMappedSymbol(int32_t o = 0);

   RegisterMappedSymbol(TR::DataType d);

   RegisterMappedSymbol(TR::DataType d, uint32_t s);

   TR::RegisterMappedSymbol * self();

public:

   template <typename AllocatorType>
   static TR::RegisterMappedSymbol * create(AllocatorType t, int32_t o = 0);

   template <typename AllocatorType>
   static TR::RegisterMappedSymbol * create(AllocatorType m, TR::DataType d);

   template <typename AllocatorType>
   static TR::RegisterMappedSymbol * create(AllocatorType m, TR::DataType d, uint32_t s);

   int32_t getOffset()          {return _mappedOffset;}
   void    setOffset(int32_t o) {_mappedOffset = o;}

   int32_t getGCMapIndex()          {return _GCMapIndex;}
   void    setGCMapIndex(int32_t i) {_GCMapIndex = i;}

   uint16_t getLiveLocalIndex()     {return _liveLocalIndex;}
   void     setLiveLocalIndex(uint16_t i, TR_FrontEnd * fe);

   bool isLiveLocalIndexUninitialized();
   void setLiveLocalIndexUninitialized();

protected:

   int32_t  _mappedOffset;
   int32_t  _GCMapIndex;

private:

   uint16_t _liveLocalIndex;

/**
 * TR_MethodMetaDataSymbol
 *
 * Doesn't contain data about methods, surprisingly enough. Is used for data
 * that is thread-local, stored on the VMThread for example.
 *
 * @{
 */
public:

  /**
   * Create a 'method metadata' symbol.
   *
   * \todo Rename this concept, as the current name is terrible.
   */
   template <typename AllocatorType>
   static TR::RegisterMappedSymbol * createMethodMetaDataSymbol(AllocatorType m, const char *name, TR_MethodMetaDataType type = TR_MethodMetaDataType_Default);

   TR_MethodMetaDataType getMethodMetaDataType();
   void                  setMethodMetaDataType(TR_MethodMetaDataType type);

protected:
   friend class ::TR_DebugExt;

   TR_MethodMetaDataType  _type;

   /** @} */

   };

}

#endif
