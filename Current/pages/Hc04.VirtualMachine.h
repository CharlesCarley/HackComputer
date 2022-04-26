/*!
\page Hc04 Virtual Machine

\brief Implements the virtual machine compiler.

\h1 Vm2Asm

The primary job of this compiler is to switch abstractions from a stack based virtual machine to assembly code.
\br

\code{.txt}
Usage: vm2mc <options> <arg[0] .. arg[n]>

  where arg[0] is the input file
  
    -h, --help    Display this help message
    -o, --output  Specify an output file
\endcode

\h2 Grammar

The grammar for the VM syntax can be found [here.](../../Source/VirtualMachine/VM.grm) \n
It uses the following extra keywords that are not in the course specification.
- __set__ `set <int> <int>` Allows directly setting RAM values
- __reset__ `reset` Forces a CPU reset by jumping to the end of ROM `@32766 D=A;JMP`
- __halt__ `halt` Will emit code that enters into an infinite loop

\defined{Hc04Defined}
\defined_in{Source/VirtualMachine}

 */
#pragma once
