/*!
\page Hc03 Assembler

\brief Implements the machine code compiler.

\br
The primary job of the assembler is to convert the input assembly into
16 bit binary codes so that they can be handed to the CPU.

\h1 Asm2Mc

Is the executable that implements this conversion.

\h2 Usage

\code{.txt}
Usage: asm2mc <options> <arg[0] .. arg[n]>
  
  where arg[0] is the input file

    -h, --help    Display this help message
    -o, --output  Specify an output file.

\endcode


\h3 Example

The following code illustrates the output of Asm2Mc from assembly to machine code.
\br
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

\h2 Grammar
The grammar for the assembly syntax can be found [here.](../../Source/Assembler/ASM.grm)

\defined{Hc03Defined}
\defined_in{Source/Assembler}

 */
#pragma once
