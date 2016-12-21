###############################################################################
#
# (c) Copyright IBM Corp. 2015, 2016
#
#  This program and the accompanying materials are made available
#  under the terms of the Eclipse Public License v1.0 and
#  Apache License v2.0 which accompanies this distribution.
#
#      The Eclipse Public License is available at
#      http://www.eclipse.org/legal/epl-v10.html
#
#      The Apache License v2.0 is available at
#      http://www.opensource.org/licenses/apache2.0.php
#
# Contributors:
#    Multiple authors (IBM Corp.) - initial implementation and documentation
###############################################################################

###
### omrmakefiles/configure.mk.  Generated from configure.mk.in by configure.
###

###
### Ensure the default target is "all"
###

all:
.PHONY: all

###
### OMR Build Flags
###

OMR_ARCH_ARM := 0
OMR_ARCH_POWER := 0
OMR_ARCH_S390 := 0
OMR_ARCH_X86 := 1
OMR_ENV_DATA64 := 1
OMR_ENV_GCC := 0
OMR_ENV_LITTLE_ENDIAN := 1
#zg. Try to remove example from OMR.
OMR_EXAMPLE := 0
OMR_GC := 1
OMR_GC_ALLOCATION_TAX := 1
OMR_GC_ARRAYLETS := 1
OMR_GC_BATCH_CLEAR_TLH := 1
OMR_GC_COMBINATION_SPEC := 1
OMR_GC_COMPRESSED_POINTERS := 0
OMR_GC_CONCURRENT_SCAVENGER := 0
OMR_GC_CONCURRENT_SWEEP := 0
OMR_GC_DEBUG_ASSERTS := 1
OMR_GC_DYNAMIC_CLASS_UNLOADING := 0
OMR_GC_HEAP_CARD_TABLE := 1
OMR_GC_HYBRID_ARRAYLETS := 0
OMR_GC_LARGE_OBJECT_AREA := 1
OMR_GC_MINIMUM_OBJECT_SIZE := 1
OMR_GC_MODRON_COMPACTION := 0
OMR_GC_MODRON_CONCURRENT_MARK := 1
OMR_GC_MODRON_SCAVENGER := 1
OMR_GC_MODRON_STANDARD := 1
OMR_GC_NON_ZERO_TLH := 1
OMR_GC_OBJECT_ALLOCATION_NOTIFY := 0
OMR_GC_OBJECT_MAP := 0
OMR_GC_REALTIME := 0
OMR_GC_SEGREGATED_HEAP := 1
OMR_GC_STACCATO := 0
OMR_GC_THREAD_LOCAL_HEAP := 1
OMR_GC_TLH_PREFETCH_FTA := 1
OMR_GC_VLHGC := 0
OMR_INTERP_COMPRESSED_OBJECT_HEADER := 0
OMR_INTERP_HAS_SEMAPHORES := 1
OMR_INTERP_SMALL_MONITOR_SLOT := 0
OMR_JIT := 1
OMR_NOTIFY_POLICY_CONTROL := 1
OMR_OMRSIG := 1
OMR_OPT_CUDA := 0
OMR_PORT := 1
OMR_PORT_ALLOCATE_TOP_DOWN := 0
OMR_PORT_ASYNC_HANDLER := 0
OMR_PORT_CAN_RESERVE_SPECIFIC_ADDRESS := 1
OMR_PORT_NUMA_SUPPORT := 0
OMR_PORT_ZOS_CEEHDLRSUPPORT := 0
OMR_RAS_TDF_TRACE := 1
OMR_THR_ADAPTIVE_SPIN := 1
OMR_THR_CUSTOM_SPIN_OPTIONS := 1
OMR_THR_FORK_SUPPORT := 1
OMR_THR_JLM := 1
OMR_THR_JLM_HOLD_TIMES := 1
OMR_THR_LOCK_NURSERY := 1
OMR_THR_THREE_TIER_LOCKING := 1
OMR_THR_TRACING := 0
OMR_THR_YIELD_ALG := 1
OMR_THR_SPIN_WAKE_CONTROL := 0
OMR_THREAD := 1
OMRTHREAD_LIB_AIX := 0
OMRTHREAD_LIB_UNIX := 1
OMRTHREAD_LIB_WIN32 := 0
OMRTHREAD_LIB_ZOS := 0

###
### Global Autoconfigure Flags
###

# If OMRGLUE contains relative paths, assume they are relative to the
# top of the build tree.
# We can't convert OMRGLUE to absolute paths because, for z/OS, Windows, and AIX,
# the J9 build runs configure and compiles in different directory structures.
#zg. Trying to using the glue in som++
#OMRGLUE ?= $(filter /%,./example/glue)$(addprefix $(top_srcdir)/,$(filter-out /%,./example/glue))
OMRGLUE ?= $(filter /%,./../som++/src/somrvm)$(addprefix $(top_srcdir)/,$(filter-out /%,./../som++/src/somrvm))
SOM_HEADS= $(filter /%,./../som++/src/vmobjects)$(addprefix $(top_srcdir)/,$(filter-out /%,./../som++/src/vmobjects))

OMR_CROSS_COMPILE := 0

OMR_HOST_OS := osx
OMR_HOST_ARCH := x86
OMR_TARGET_DATASIZE := 64
OMR_TOOLCHAIN := gcc

lib_output_dir := $(top_srcdir)/lib
exe_output_dir := $(top_srcdir)

CPPFLAGS := 
CFLAGS := 
CXXFLAGS := 
LDFLAGS := 

OMRGLUE_CPPFLAGS := 
OMRGLUE_CFLAGS := 
OMRGLUE_CXXFLAGS := 
OMRGLUE_INCLUDES := $(OMRGLUE) $(SOM_HEADS) $(filter /%,) $(addprefix $(top_srcdir)/,$(filter-out /%,))

# GNU make provides a default value for ARFLAGS. We want to override it with our own value.
ARFLAGS = 

CC := cc
CXX := c++
CCLINK := $(CC)
CCLINKSHARED := $(CCLINK)
CCLINKEXE := $(CCLINK)
CXXLINK := $(CXX)
CXXLINKSHARED := $(CC)
CXXLINKEXE := $(CXX)

AS := as
AR := ar
OBJCOPY := objcopy

LIBPREFIX := lib
EXEEXT := 
SOLIBEXT := .dylib
ARLIBEXT := .a
OBJEXT := .o


###
### Platform Flags
###

# Need to allow deferred expansion of automatic variables like $*
GLOBAL_CPPFLAGS = 
GLOBAL_CFLAGS = 
GLOBAL_CXXFLAGS = 
GLOBAL_INCLUDES = 
GLOBAL_LDFLAGS = 
GLOBAL_STATIC_LIBS = 
GLOBAL_SHARED_LIBS = 
GLOBAL_LIBPATH = 
GLOBAL_ARFLAGS = 

#zg. remove optimize
#OMR_OPTIMIZE := 1
OMR_OPTIMIZE := 0
OMR_WARNINGS_AS_ERRORS := 1
OMR_ENHANCED_WARNINGS := 1
OMR_DEBUG := 1

ENABLE_FVTEST := yes
ENABLE_FVTEST_AGENT := yes
ENABLE_TRACEGEN := yes

ENABLE_DDR := no

###
### Global Options
###

## Add Global Flags
# Header files in the current directory should have first precedence.
MODULE_INCLUDES += .
GLOBAL_INCLUDES += $(top_srcdir)/include_core $(top_srcdir)/nls

GLOBAL_CPPFLAGS += -DUT_DIRECT_TRACE_REGISTRATION

# By default, shared libs are built into exe_output_dir, and
# static libs are built into lib_output_dir.
GLOBAL_LIBPATH += . $(exe_output_dir) $(lib_output_dir)

## Special settings for fvtests
# Location of fvtest framework
OMR_GTEST_DIR := $(top_srcdir)/third_party/gtest-1.7.0
OMR_GTEST_INCLUDES := $(OMR_GTEST_DIR) $(OMR_GTEST_DIR)/include $(top_srcdir)/fvtest/omrGtestGlue
OMR_PUGIXML_DIR := $(top_srcdir)/third_party/pugixml-1.5

# googletest code requires exception handling
ifeq (linux,$(OMR_HOST_OS))
  ifeq (xlc,$(OMR_TOOLCHAIN))
    OMR_GTEST_CXXFLAGS += -qeh
  else
    OMR_GTEST_CXXFLAGS += -fexceptions
  endif
endif
ifeq (msvc,$(OMR_TOOLCHAIN))
  OMR_GTEST_CXXFLAGS += /EHsc
endif

# Public Core OMR header files
OMR_IPATH = \
  $(top_srcdir)/include_core \
  $(top_srcdir)/omr/startup \
  $(top_srcdir)/gc/include \
  $(top_srcdir)/gc/startup \

# Internal OMR header files needed by OMR glue code
OMRGC_IPATH = \
  $(top_srcdir)/gc/base \
  $(top_srcdir)/gc/base/standard \
  $(top_srcdir)/gc/verbose \
  $(top_srcdir)/gc/verbose/handler_standard \
  $(top_srcdir)/gc/stats \
  $(top_srcdir)/gc/structs

ifeq (1,$(OMR_GC_SEGREGATED_HEAP))
OMRGC_IPATH += $(top_srcdir)/gc/base/segregated
endif

ifeq (yes,$(ENABLE_DDR))
# libdwarf location
OMR_LIBDWARF_IPATH = 
OMR_LIBDWARF_STATIC_LIBS = dwarf elf
OMR_LIBDWARF_SHARED_LIBS = 
endif
