#pragma once
/*!
\page Hc07 Computer

\brief Implements the primary program that ties the project's components together.

\section Hc07Computer Computer


The computer executable accepts any of the source file formats that are
defined in this project as its input. It then reduces the input into an array of
16-bit integers, and passes it to the \ref Hack::Computer "Computer" class, and
finally to the \ref Hack::Chips::Rom32 "Rom32" class.
The \ref Hack::Computer::RuntimeInterface "RuntimeInterface" is used to
execute the code in various ways.
\br

- Command Line - Runs the file until completion.
- Command Line Debugger - Debugs the state of execution.
- SDL Runtime - Displays only the screen memory.

If SDL is enabled, the default runtime will be SDL otherwise, the default
runtime is the command line debugger.

\br
\code{.txt}
Usage: computer <options> <arg[0] .. arg[n]>

    -h, --help      Display this help message
    -c              Use the command line runtime
    -d              Debug the supplied file
    -r, --run-end   Run the supplied file until it exits
    -t, --trace     Output a dump of the non-zero portions of ram
        --show-vm   Output the emitted VM code from the supplied file
        --show-asm  Output the emitted assembly code from the supplied file
        --show-mc   Output the emitted machine code from the supplied file
\endcode

\n
\subsection Hc07Debugger Command Line Debugger.

The debugger will execute one instruction and refresh the console display with the current state of the chips.
\br
- The up-arrow key will initiate a tick.
- The r key will reset execution.
- The c key will loop execution.
\br
\image html Debugger.png

\defined{Hc07Defined}
\defined_in{Source/Computer}

*/

