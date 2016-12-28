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

#ifndef JITBUILDER_STACKATLASPOD_INCL
#define JITBUILDER_STACKATLASPOD_INCL

#include <stdint.h>

/*
 * This structure describes the shape of the encoded stack atlas information.
 * It must be a C++ POD object and follow all the rules behind POD formation.
 * Because its fields may be extracted by a runtime system, its exact layout
 * shape MUST be preserved.
 *
 * DO NOT subclass this struct.  A project may replace it by including an
 * identically named header file earlier in the IPATH.
 */

namespace OMR
{

struct StackAtlasPOD
   {
   uint16_t numberOfMaps;
   uint16_t bytesPerStackMap;
   int32_t frameObjectParmOffset;
   int32_t localBaseOffset;
   };

}

#endif // !defined(JITBUILDER_STACKATLASPOD_INCL)
