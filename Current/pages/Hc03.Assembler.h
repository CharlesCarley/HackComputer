/*!
\page Hc03 Assembler

\brief Implements a machine code compiler.

\n\n
It outputs binary instructions that are later used to control the CPU chip.
The grammar for the assembly can be found [here](../../Source/Assembler/ASM.grm).
\n\n

\section Hc03Asm2Mc Asm2Mc

Is the executable that implements this.
\n\n

\code{.txt}
Usage: asm2mc <options> <arg[0] .. arg[n]>
  
  where arg[0] is the input file

    -h, --help    Display this help message
    -o, --output  Specify an output file.

\endcode

\section Hc03Defined Defined In

The source is defined in [Source/Assembler](../../Source/Assembler/)

 */
#pragma once
