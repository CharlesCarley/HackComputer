#pragma once
/*!
\page Hc07 Computer

\brief Defines the main program that ties the components together.

\section Hc07Computer Computer

The Hack::Computer class links together the ROM, RAM and CPU chips.
It accepts as input an array of 16 bit integers.

This projects responsibilities are to tie together the Hack::Computer class with rest of the system.
And combine the result with a runtime interface. The runtime interface executes the supplied input with
a user selected implementation.

\n\n
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


The runtime interface is composed of multiple back ends.
\n
- Command Line - Runs the file until completion
- Command Line Debugger - Debugs the state of execution.
- SDL runtime - Displays only the screen memory.

If SDL is enabled, the default runtime will be SDL. Otherwise, the default runtime is the command line debugger.

\n
\subsection Hc07Debugger Command Line Debugger.

The debugger will execute one instruction from ROM and refresh the console with the current state of the circuits.
\n\n

- The up-arrow key will initiate a tick.
- The r key will reset execution.
- The c key will loop execution.

 
\n\n
\image html Debugger.png

\section Hc07Defines Defined In

The source is defined in [Source/Computer](../../Source/Computer/)
*/

