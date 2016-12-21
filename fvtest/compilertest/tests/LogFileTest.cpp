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
 *******************************************************************************/

#include "tests/LogFileTest.hpp"

#include <stdio.h>
#include <string.h>
#include <fstream>
#include <string>
#include <sstream>
#include <unistd.h>
#include <sys/stat.h>

#include "tests/OMRTestEnv.hpp"
#include "tests/OpCodesTest.hpp"

TestCompiler::LogFileTest::LogFileTest()
   {
   // Don't use fork(), since that doesn't let us initialize the compiler
   ::testing::FLAGS_gtest_death_test_style = "threadsafe";
   }

TestCompiler::LogFileTest::~LogFileTest()
   {
   // Remove all generated log files.
   for(auto it = _logFiles.begin(); it != _logFiles.end(); ++it)
      {
      unlink(*it);
      }
   }

void
TestCompiler::LogFileTest::compileTests()
   {
   ::TestCompiler::OpCodesTest unaryTest;
   unaryTest.compileUnaryTestMethods();
   }

/**
 * Determine if a file exists.
 *
 * @param name The name of the file.
 */
bool
TestCompiler::LogFileTest::fileExists(const char *name)
   {
   struct stat buf;
   int result = stat(name, &buf);
   return result == 0;
   }

/**
 * Check that the log file created is not empty.
 *
 * @param logFile The name of the file.
 */
bool
TestCompiler::LogFileTest::fileIsNotEmpty(const char* logFile)
   {
   std::ifstream logFileStream(logFile);
   return logFileStream.peek() != std::ifstream::traits_type::eof();
   }

/**
 * Build a std::map of <key,value> pairs where key is
 * the keyword from the inputs list, and the value is
 * initialized to false. The value tells us whether or not the
 * particular keyword (key) has been found in the log file.
 *
 * @param inputs A list of keywords to build the std::map.
 */

std::map<const char*, bool>
TestCompiler::LogFileTest::buildKeywordMap(std::initializer_list <const char*> inputs)
   {
   std::map<const char*, bool> keywords;
   for (auto w = inputs.begin(); w != inputs.end(); w++)
      {
      keywords.insert(std::pair<const char*, bool>(*w, false));
      }
   return keywords;
   }


/**
 * Startup the compiler, run tests, shut down the compiler, then exit with
 * an exit code of 0.
 * This must be called in a process that has not initialized the
 * compiler yet.
 *
 * @param logFile The file to log to.
 * @param logType The type of log to be generated..
 */
void
TestCompiler::LogFileTest::createLog(const char *logFile, const char *logType)
   {
   std::string args = std::string("-Xjit:");
   args = args + logType + ",log=" + logFile;

   OMRTestEnv::initialize(const_cast<char *>(args.c_str()));
   compileTests();
   OMRTestEnv::shutdown();

   exit(0);
   }

/**
 * Run tests to ensure that a particular set of keywords are found
 * in a particular type of log file.
 * A failure is asserted if any of the keywords cannot be found
 * in the associated log type.
 *
 * @param logFileChecks Pair of the log type and the keywords associated
 *        with that log type.
 */
void
TestCompiler::LogFileTest::runKeywordTests(std::map<const char*, std::map<const char*, bool>> logFileChecks)
   {
   for (auto it = logFileChecks.begin(); it != logFileChecks.end(); ++it)
      {
      const char *logType = it->first;
      std::string logFile = std::string(logType) + std::string(".log");

      forkAndCompile(logFile.c_str(), logType);
      checkLogForKeywords(it->second, logFile.c_str());
      }
   }

/**
 * Assert that the keywords passed in exist in the log file.
 *
 * @param keywords A map with the keyword (key) and a bool (value)
 *        indicating whether or not the keywrd has already been
 *        found in the log file.
 * @param logFile The log file to search.
 */
void
TestCompiler::LogFileTest::checkLogForKeywords(std::map<const char*, bool> keywords, const char *logFile)
   {
   std::ifstream logFileStream(logFile);
   ASSERT_TRUE(logFileStream.is_open());

   int keywordsFound = 0;
   std::string line;

   // Keep looping until all the keywords passed in have been found
   while (keywordsFound < keywords.size())
      {
      std::getline(logFileStream, line);

      ASSERT_FALSE(logFileStream.eof()) << "End of log file reached without finding all keywords";
      ASSERT_TRUE(logFileStream.good()) << "An error occured during an I/O operation while reading logfile";

      if (line.empty())
         continue;

      // Loop through all keywords in the std::map for each line
      for (auto it = keywords.begin(); it != keywords.end(); ++it)
         {
         // If the value of this <key,value> pair is false, the keyword has already
         // been found earlier.
         if(it->second)
            continue;

         // If the keyword is found on this line
         if(line.find(it->first) != std::string::npos)
            {
            it->second = true;
            keywordsFound++;
            }
         }
      }

   ASSERT_EQ(keywords.size(), keywordsFound) << "Only " << keywordsFound << " of " << keywords.size() << " keywords found";
   }

/**
 * Create a log file by creating a new process and running a set of tests.
 *
 * In order to properly test the creation of the log file, a compiler must
 * be initialized. Since a compiler is already initialized when these tests are
 * run, and since shutting down the compiler does not reset everything, we need
 * to create a new process that initializes a compiler with its own options.
 *
 * Note that this is made possible by disabling the global test environment
 * in main.cpp for any new processes in this file.
 *
 * @param logFile The name of the log file to be created.
 * @param logType The type of log to be generated. This is an optional
 *        parameter. The default value is "traceFull"
 */
void
TestCompiler::LogFileTest::forkAndCompile(const char *logFile, const char *logType)
   {
   // Keep track of the filename in the vector _logFiles so that it
   // can be deleted in the destructor.
   _logFiles.push_back(logFile);

   /* This creates the new process, runs createLog, and asserts it exits
    * with a status code of 0.
    */
   ASSERT_EXIT(createLog(logFile, logType), ::testing::ExitedWithCode(0), "") << "Error in createLog.";

   ASSERT_TRUE(fileExists(logFile)) << "Log file not created.";
   }

namespace TestCompiler {

// Note: logType is an optional parameter in forkAndCompile. The default
// value is "traceFull"

// Assert a traceFull log file was created
TEST_F(LogFileTest, CreateTFLogTest)
   {
   const char *logType = "traceFull";
   const char *logFile = "createTFLog.log";
   forkAndCompile(logFile, logType);
   }

// Assert the traceFull log file is not empty
TEST_F(LogFileTest, EmptyTFLogTest)
   {
   const char *logType = "traceFull";
   const char *logFile = "emptyTFLog.log";
   forkAndCompile(logFile, logType);
   ASSERT_TRUE(fileIsNotEmpty(logFile)) << "The traceFull log file created is empty";
   }

// Assert keywords exist in log files
TEST_F(LogFileTest, KeywordsLogTest)
   {
   std::map<const char*, std::map<const char*, bool>> logFileChecks;
   
   /* Additional pairs of log types and keywords to look for can be added to
      logFileChecks like this. A failure is asserted if any of the keywords
      cannot be found in the associated log type.
   */
   logFileChecks.insert(std::pair<const char*, std::map<const char*, bool>>
      ("traceFull", buildKeywordMap({"<jitlog", "<ilgen", "<trees", "</trees>", "BBStart", "BBEnd", "<block_"})));
   logFileChecks.insert(std::pair<const char*, std::map<const char*, bool>>
      ("traceCG", buildKeywordMap({"<codegen"})));

   runKeywordTests(logFileChecks);
   }
}
