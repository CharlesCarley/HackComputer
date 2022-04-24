/*!
\page Hc03 Assembler

\brief Implements the machine code compiler.


\n\n

The primary job of the assembler is to convert the input assembly into
16 bit binary codes that can be handed to the Cpu.

\section Hc03Asm2Mc Asm2Mc

Is the executable that implements this conversion.

\subsection Hc03Asm2McUsage Usage

\code{.txt}

Usage: asm2mc <options> <arg[0] .. arg[n]>
  
  where arg[0] is the input file

    -h, --help    Display this help message
    -o, --output  Specify an output file.

\endcode

The following code illustrates the conversion.
\n\n

<b>Assembly:</b>
\code{.txt}
@123
D=A
@0
M=D
@1
M=D
@2
M=D
@32766 D=A;JMP
\endcode

<b>Machine Code:</b>
\code{.txt}
0000000001111011
1110110000010000
0000000000000000
1110001100001000
0000000000000001
1110001100001000
0000000000000010
1110001100001000
0111111111111110
1110110000010111
\endcode
\n

\subsection Hc03AsmGrammar Grammar
The grammar for the assembly can be found [here](../../Source/Assembler/ASM.grm).

\section Hc03Defined Defined In

The source is defined in [Source/Assembler](../../Source/Assembler/)

 */
#pragma once
