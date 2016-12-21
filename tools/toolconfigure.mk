###############################################################################
#
# (c) Copyright IBM Corp. 2015
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
### toolconfigure.mk.  Generated from toolconfigure.mk.in by configure.
###
### Cross-compilation support
###

# Build tools that run on the build system should include this makefile instead of configure.mk.
# Use the main OMR configuration, but override the compilation toolchain to target the build platform.

include $(top_srcdir)/omrmakefiles/configure.mk

ifeq (1,$(OMR_CROSS_COMPILE))

OMR_HOST_OS := osx
OMR_HOST_ARCH := x86
OMR_TOOLCHAIN := gcc
OMR_TARGET_DATASIZE := 64

CC := cc
CCLINK := cc
CCLINKSHARED := cc
CCLINKEXE := cc
CXX := c++
CXXLINK := c++
CXXLINKSHARED := c++
CXXLINKEXE := c++

GLOBAL_INCLUDES :=

endif
