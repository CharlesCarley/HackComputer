/*!
\page Hc00 CMake

\brief It uses \ref Hc00 for its build system.

\h1 Generators 

The build system was written using CMake's `Unix Makefiles` and `Visual Studio 2019` generators.

\h1 Options

It provides the following options to control compilation.
\br
- Hack_BUILD_DOCS | OFF
 - Builds the current version of the manual.
- Hack_BUILD_TEST | OFF
 - Enables building the unit test program.
- Hack_AUTO_RUN_TEST | OFF
 - Automatically runs the unit test program after each build.
- Hack_CHECK_INT_BOUNDS | ON
 - Enables throwing an overflow exception when manipulating individual bits.
- Hack_IMPLEMENT_BLACK_BOX | ON
 - If this is true most chips will be implemented with computed logic gates.
- Hack_PRINT_CHIP_STATE | OFF
 - Enables the print method defined in the Hack::Chip base class. 
- Hack_VM_ZERO_RAM | OFF
 - Emits extra instructions to zero RAM values that are no longer in use.
- Hack_BLOCK_PUSH | OFF
 - Emits conditional instructions to prevent pushing ram segments when its out of context.
- Hack_USE_SDL | OFF
 - Enables or disables the SDL runtime.
- Hack_GEN_SVG_PARSE_TREES | OFF
 - Regenerates SVG files off of the .jack files in the \dir_link{Test/Jack} directory.
 
 */
#pragma once
