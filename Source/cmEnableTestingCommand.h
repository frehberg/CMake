/*============================================================================
  CMake - Cross Platform Makefile Generator
  Copyright 2000-2009 Kitware, Inc., Insight Software Consortium

  Distributed under the OSI-approved BSD License (the "License");
  see accompanying file Copyright.txt for details.

  This software is distributed WITHOUT ANY WARRANTY; without even the
  implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the License for more information.
============================================================================*/
#ifndef cmEnableTestingCommand_h
#define cmEnableTestingCommand_h

#include "cmCommand.h"

/** \class cmEnableTestingCommand
 * \brief Enable testing for this directory and below.
 *
 * Produce the output testfile. This produces a file in the build directory
 * called CMakeTestfile with a syntax similar to CMakeLists.txt.  It contains
 * the SUBDIRS() and ADD_TEST() commands from the source CMakeLists.txt
 * file with CMake variables expanded.  Only the subdirs and tests
 * within the valid control structures are replicated in Testfile
 * (i.e. SUBDIRS() and ADD_TEST() commands within IF() commands that are
 * not entered by CMake are not replicated in Testfile).
 * Note that CTest expects to find this file in the build directory root;
 * therefore, this command should be in the source directory root too.
 */
class cmEnableTestingCommand : public cmCommand
{
public:
  /**
   * This is a virtual constructor for the command.
   */
  cmCommand* Clone() CM_OVERRIDE { return new cmEnableTestingCommand; }

  /**
   * This is called when the command is first encountered in
   * the CMakeLists.txt file.
   */
  bool InitialPass(std::vector<std::string> const&,
                   cmExecutionStatus&) CM_OVERRIDE;

  /**
   * The name of the command as specified in CMakeList.txt.
   */
  std::string GetName() const CM_OVERRIDE { return "enable_testing"; }

  cmTypeMacro(cmEnableTestingCommand, cmCommand);
};

#endif
