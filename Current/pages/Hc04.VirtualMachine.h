/*!
\page Hc04 Virtual Machine

\brief Implements a virtual machine compiler.

\n\n
The primary target is a static library so that it can be used in other areas of code.
The file [VM.grm](../../Source/VirtualMachine/VM.grm) defines the implemented grammar.

\n\n
It uses extra keywords that are not in the course specification.

- __set__ `set <int> <int>`
  - Allows directly setting RAM values
- __reset__ `reset`
  - Forces a CPU reset by jumping to the end of ROM
    - `@32766 D=A;JMP`
- __halt__ `halt`
  - Will emit code that enters into an infinite loop

\section Hc04S2 Vm2Asm

Is the program that inputs a <tt>.vm</tt> file as and outputs an assembly file.
The output file can be compiled to machine code with the \ref Hc03

\n\n
\code{.txt}
Usage: vm2mc <options> <arg[0] .. arg[n]>

    -h, --help    Display this help message
    -o, --output  Specify an output file
\endcode

\section Hc04Defined Defined In

The source is defined in [Source/VirtualMachine](../../Source/VirtualMachine/)

 */
#pragma once
