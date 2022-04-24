#pragma once
/*!
\page Hc07 Computer

\brief Implements a program to tie the system together.

\n\n
It ties together the ROM, RAM and CPU chips and implements multiple runtime targets.

\n\n
If SDL is enabled the default runtime will open a window and map the screen region of memory to a SDL window.
Otherwise if SDL is disabled, the default and only runtime is the command line debugger.
\n

\section Hc07Debugger Debugger

\image html Debugger.png
\n\n


\section Hc07Usage Usage

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


\section Hc07Defines Defined In

The source is defined in [Source/Computer](../../Source/Computer/)
*/

