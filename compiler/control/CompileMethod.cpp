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

#include "control/CompileMethod.hpp"

#include <exception>                           // for exception
#include <stdint.h>                            // for int32_t, uint8_t, etc
#include <stdio.h>                             // for NULL, fprintf, fflush, etc
#include <string.h>                            // for strlen
#include <unistd.h>                            // for getpid, intptr_t, etc
#include "codegen/CodeGenerator.hpp"           // for CodeGenerator
#include "codegen/FrontEnd.hpp"                // for TR_VerboseLog, etc
#include "codegen/LinkageConventionsEnum.hpp"
#include "compile/Compilation.hpp"             // for Compilation, comp
#include "compile/CompilationTypes.hpp"        // for TR_Hotness
#include "compile/ResolvedMethod.hpp"          // for TR_ResolvedMethod
#include "control/OptimizationPlan.hpp"        // for TR_OptimizationPlan, etc
#include "control/Options.hpp"
#include "control/Options_inlines.hpp"         // for TR::Options, etc
#include "env/CPU.hpp"                         // for Cpu
#include "env/CompilerEnv.hpp"
#include "env/ConcreteFE.hpp"                  // for FrontEnd
#include "env/IO.hpp"                          // for IO
#include "env/JitConfig.hpp"
#include "env/PersistentInfo.hpp"              // for PersistentInfo
#include "env/Processors.hpp"
#include "env/TRMemory.hpp"                    // for TR_Memory, etc
#include "env/defines.h"                       // for TR_HOST_64BIT, etc
#include "env/jittypes.h"                      // for uintptrj_t
#include "il/symbol/ResolvedMethodSymbol.hpp"  // for ResolvedMethodSymbol
#include "ilgen/IlGenRequest.hpp"              // for CompileIlGenRequest
#include "ilgen/IlGeneratorMethodDetails.hpp"
#include "infra/Assert.hpp"                    // for TR_ASSERT
#include "ras/Debug.hpp"                       // for createDebugObject, etc
#include "omr.h"
#include "env/SystemSegmentProvider.hpp"

static void
writePerfToolEntry(void *start, uint32_t size, const char *name)
   {
   // race condition
   static bool firstAttempt = true;
   static FILE *perfFile = 0;

   if (firstAttempt)
      {
      firstAttempt = false;
      pid_t jvmPid = getpid();
      static const int maxPerfFilenameSize = 15 + sizeof(jvmPid)* 3; // "/tmp/perf-%ld.map"
      char perfFilename[maxPerfFilenameSize] = { 0 };

      int numCharsWritten = snprintf(perfFilename, maxPerfFilenameSize, "/tmp/perf-%ld.map", jvmPid);
      if (numCharsWritten > 0 && numCharsWritten < maxPerfFilenameSize)
         {
         perfFile = fopen(perfFilename, "a");
         }
      if (!perfFile) // couldn't open the file
         {
         }
      }
   if (perfFile)
      {
      // perf does not want 0x leading the hex start address and length of the compiled code region
      // the rest of the line is considered to be the name of the region

      // j9jit_fprintf(getPerfFile(), "%lX %lX %s_%s\n", (intptr_t) getMetadata()->startPC, getMetadata()->endWarmPC - getMetadata()->startPC,
      //               getCompilation()->signature(), getCompilation()->getHotnessName(getCompilation()->getMethodHotness()));
      fprintf(perfFile, "%lX %lX %s\n", (intptr_t) start, (intptr_t) size, name);

      // If there is a cold section, add another line
      // if (getMetadata()->startColdPC)
      //    {
      //    j9jit_fprintf(getPerfFile(), "%lX %lX %s_%s\n", (intptr_t) getMetadata()->startColdPC, getMetadata()->endPC - getMetadata()->startColdPC,
      //                  TR::comp()()->signature(), getCompilation()->getHotnessName(getCompilation()->getMethodHotness())); // should we change the name of the method?
      //    }
      // Flushing degrades performance, but ensures that we have the data
      // written even if the JVM is abruptly terminated
      //j9jit_fflush(getPerfFile());
      fflush(perfFile);
      }
   }



static void
generatePerfToolEntry(uint8_t *startPC, uint8_t *endPC, const char *sig, const char *hotness)
   {
   char buffer[1024];
   char *name;
   if (strlen(sig) + 1 + strlen(hotness) + 1 < 1024)
      {
      sprintf(buffer, "%s_%s (compiled code)", sig, hotness);
      name = buffer;
      }
   else
      name = "(compiled code)";

   writePerfToolEntry(startPC, endPC - startPC, name);
   }

#if defined(TR_TARGET_POWER)
#include "p/codegen/PPCTableOfConstants.hpp"
#endif

static uint64_t totalCompilationTime = 0;


int32_t commonJitInit(OMR::FrontEnd &fe, char *cmdLineOptions)
   {
   auto jitConfig = fe.jitConfig();

   if (init_options(jitConfig, cmdLineOptions) < 0)
      return -1;

   // This doesn't make sense for non-Power platforms!
   //
   TR::Compiler->target.cpu.setProcessor(TR_DefaultPPCProcessor);

   TR_VerboseLog::initialize(jitConfig);
   TR::Options::setCanJITCompile(true);
   TR::Options::getCmdLineOptions()->setOption(TR_NoRecompile);
   TR::CompilationController::init(NULL);

   void *pseudoTOC = NULL;
#if defined(TR_TARGET_POWER)
   pseudoTOC = (void *) TR_PPCTableOfConstants::initTOC(&fe, fe.getPersistentInfo(), jitConfig->getInterpreterTOC());
   if (pseudoTOC == (void*)0x1)
      pseudoTOC = NULL;
#endif
   jitConfig->setPseudoTOC(pseudoTOC);

   return 0;
   }

int32_t init_options(TR::JitConfig *jitConfig, char *cmdLineOptions)
   {
   OMR::FrontEnd *fe = OMR::FrontEnd::instance();

   if (cmdLineOptions)
      {
      // The callers (ruby/python) guarantee that we have at least -Xjit in cmdline options
      //
      cmdLineOptions += 5; // skip the leading -Xjit
      if (*cmdLineOptions == ':') cmdLineOptions++; // also skip :
      }

   char *endOptions = TR::Options::processOptionsJIT(cmdLineOptions, jitConfig, fe);
   if (*endOptions)
      {
      fprintf(stderr, "JIT: fatal error: invalid command line at %s\n", endOptions);
      return -1;
      }

   // Fake the AOT options.. the codegen expects this to be done
   TR::Options::processOptionsAOT("", &jitConfig, fe);

   // in this world, latePostProcess can be done immediately
   endOptions = TR::Options::latePostProcessJIT(jitConfig);
   if (endOptions)
      {
      fprintf(stderr, "<JIT: fatal error: invalid command line>\n");
      return -1;
      }

   TR::Options::getCmdLineOptions()->setTarget();
   return 0;
   }

static bool methodCanBeCompiled(OMR::FrontEnd *fe, TR_ResolvedMethod &method, TR_FilterBST *&filter, TR_Memory *trMemory)
   {
   if (!method.isCompilable(trMemory))
      return false;

   if (!TR::Options::getDebug())
      return true;

   return TR::Options::getDebug()->methodCanBeCompiled(trMemory, &method, filter);
   }


void
registerTrampoline(uint8_t *start, uint32_t size, const char *name)
   {
   if (TR::Options::getCmdLineOptions()->getOption(TR_PerfTool))
      writePerfToolEntry(start, size, name);
   }

static void
printCompFailureInfo(TR::JitConfig *jitConfig, TR::Compilation * comp, const char * reason)
   {
   if (comp)
      {
      traceMsg(comp, "\n=== EXCEPTION THROWN (%s) ===\n", reason);

      if (debug("traceCompilationException"))
         {
         diagnostic("JIT: terminated compile of %s: %s\n", comp->signature(), reason ? reason : "<no reason provided>");
         fprintf(stderr, "JIT: terminated compile of %s: %s\n", comp->signature(), reason ? reason : "<no reason provided>");
         fflush(stderr);
         }

      if (jitConfig->options.verboseFlags != 0)
         {
         TR_VerboseLog::writeLineLocked(TR_Vlog_COMPFAIL,"%s failed compilation", comp->signature());
         }

      if (comp->getOutFile() != NULL && comp->getOption(TR_TraceAll))
         traceMsg(comp, "<result success=\"false\">exception thrown by the compiler</result>\n");
      }
   }

uint8_t *
compileMethod(
      OMR_VMThread *omrVMThread,
      TR_ResolvedMethod &compilee,
      TR_Hotness hotness,
      int32_t &rc)
   {
   TR::IlGeneratorMethodDetails details(&compilee);
   return compileMethodFromDetails(omrVMThread, details, hotness, rc);
   }

uint8_t *
compileMethodFromDetails(
      OMR_VMThread *omrVMThread,
      TR::IlGeneratorMethodDetails & details,
      TR_Hotness hotness,
      int32_t &rc)
   {
   OMR::FrontEnd &fe = OMR::FrontEnd::singleton();
   auto jitConfig = fe.jitConfig();
   TR::RawAllocator rawAllocator;
   TR::SystemSegmentProvider scratchSegmentProvider(1 << 16, rawAllocator);
   TR::Region dispatchRegion(scratchSegmentProvider, rawAllocator);
   TR_Memory trMemory(*fe.persistentMemory(), dispatchRegion);
   TR_ResolvedMethod & compilee = *((TR_ResolvedMethod *)details.getMethod());

   TR::CompileIlGenRequest request(details);

   // initialize return code before compilation starts
   rc = COMPILATION_REQUESTED;

   uint8_t *startPC = 0;

   TR_FilterBST *filterInfo = 0;
   TR_OptimizationPlan *plan = 0;
   if (!methodCanBeCompiled(&fe, compilee, filterInfo, &trMemory))
      {
      if (TR::Options::getCmdLineOptions()->getVerboseOption(TR_VerboseCompileExclude))
         {
         TR_VerboseLog::write("<JIT: %s cannot be translated>\n",
                              compilee.signature(&trMemory));
         }
      }
   else if (0 == (plan = TR_OptimizationPlan::alloc(hotness, false, false)))
      {
      // FIXME: maybe it would be better to allocate the plan on the stack
      // so that we don't have to deal with OOM ugliness below
      if (TR::Options::getCmdLineOptions()->getVerboseOption(TR_VerboseCompileExclude))
         {
         TR_VerboseLog::write("<JIT: %s out-of-memory allocating optimization plan>\n",
                              compilee.signature(&trMemory));
         }

      }
   else
      {
      TR::Options *options = 0;

      int32_t optionSetIndex = filterInfo ? filterInfo->getOptionSet() : 0;
      int32_t lineNumber = filterInfo ? filterInfo->getLineNumber() : 0;
      options = new (trMemory.trHeapMemory()) TR::Options(
            &trMemory,
            optionSetIndex,
            lineNumber,
            &compilee,
            0,
            plan,
            false);

      // FIXME: once we can do recompilation , we need to pass in the old start PC  -----------------------^

      // FIXME: what happens if we can't allocate memory at the new above?
      // FIXME: perhaps use stack memory instead

      TR_ASSERT(TR::comp() == NULL, "there seems to be a current TLS TR::Compilation object %p for this thread. At this point there should be no current TR::Compilation object", TR::comp());
      TR::Compilation compiler(0, omrVMThread, &fe, &compilee, request, *options, dispatchRegion, &trMemory, plan);
      TR_ASSERT(TR::comp() == &compiler, "the TLS TR::Compilation object %p for this thread does not match the one %p just created.", TR::comp(), &compiler);

      try
         {
         //fprintf(stderr,"loading JIT debug\n");
         if (TR::Options::requiresDebugObject()
             || options->getLogFileName()
             || options->enableDebugCounters())
            {
            compiler.setDebug(createDebugObject(&compiler));
            }

#ifdef TEST_PROJECT_SPECIFIC
         compiler.setIlVerifier(details.getIlVerifier());
#endif

         if (TR::Options::getCmdLineOptions()->getVerboseOption(TR_VerboseCompileStart))
            {
            const char *signature = compilee.signature(&trMemory);
            TR_VerboseLog::writeLineLocked(TR_Vlog_COMPSTART,"compiling %s",
                                                             signature);
            }

         if (compiler.getOutFile() != NULL && compiler.getOption(TR_TraceAll))
            {
            const char *signature = compilee.signature(&trMemory);
            traceMsg((&compiler), "<compile hotness=\"%s\" method=\"%s\">\n",
                                  compiler.getHotnessName(compiler.getMethodHotness()),
                                  signature);
            }

         compiler.getJittedMethodSymbol()->setLinkage(TR_System);

         // --------------------------------------------------------------------
         // Compile the method
         //
         uint64_t translationTime = TR::Compiler->vm.getUSecClock();
         rc = compiler.compile();
         translationTime = TR::Compiler->vm.getUSecClock() - translationTime;
         totalCompilationTime+=translationTime;

         if (rc == COMPILATION_SUCCEEDED) // success!
            {

            // not ready yet...
            //OMR::MethodMetaDataPOD *metaData = fe.createMethodMetaData(&compiler);

            startPC = compiler.cg()->getCodeStart();

            if (TR::Options::getCmdLineOptions()->getVerboseOption(TR_VerboseCompileEnd)||TR::Options::getCmdLineOptions()->getVerboseOption(TR_VerboseCompileTime))
               {
               const char *signature = compilee.signature(&trMemory);
               TR_VerboseLog::writeLineLocked(TR_Vlog_COMP,"(%s @ %#p t=%lldms  %lld.%lldms) %s",
                                              compiler.getHotnessName(compiler.getMethodHotness()),
                                              startPC,
                                              TR::Compiler->vm.getUSecClock() - fe.getStartTime(),
                                              translationTime / 1000,
                                              translationTime % 1000,
                                              signature);
               trfflush(jitConfig->options.vLogFile);
               }

            if (TR::Options::getCmdLineOptions()->getOption(TR_PerfTool))
               generatePerfToolEntry(startPC, compiler.cg()->getCodeEnd(), compiler.signature(), compiler.getHotnessName(compiler.getMethodHotness()));

            if (compiler.getOutFile() != NULL && compiler.getOption(TR_TraceAll))
               traceMsg((&compiler), "<result success=\"true\" startPC=\"%#p\" time=\"%lld.%lldms\"/>\n",
                                     startPC,
                                     translationTime/1000,
                                     translationTime%1000);
            }
         else /* of rc == COMPILATION_SUCCEEDED */
            {
            TR_ASSERT(false, "compiler error code %d returned\n", rc);
            }

         if (compiler.getOption(TR_BreakAfterCompile))
            {
            TR::Compiler->debug.breakPoint();
            }

         }
      catch (const std::exception &exception)
         {
         // failed! :-(

#if defined(J9ZOS390)
         // Compiling with -Wc,lp64 results in a crash on z/OS when trying
         // to call the what() virtual method of the exception.
         printCompFailureInfo(jitConfig, &compiler, "");
#else
         printCompFailureInfo(jitConfig, &compiler, exception.what());
#endif
         try
            {
            throw;
            }
         catch (const TR::ILGenFailure &e)
            {
            rc = COMPILATION_IL_GEN_FAILURE;
            }
         catch (const TR::UnimplementedOpCode &e)
            {
            rc = COMPILATION_UNIMPL_OPCODE;
            }
         catch (...)
            {
            rc = COMPILATION_FAILED;
            }
         }

      // A better place to do this would have been the destructor for
      // TR::Compilation. We'll need exceptions working instead of setjmp
      // before we can get working, and we need to make sure the other
      // frontends are properly calling the destructor
      fe.unreserveCodeCache(compiler.getCurrentCodeCache());

      TR_OptimizationPlan::freeOptimizationPlan(plan);
      }

   return startPC;
   }
