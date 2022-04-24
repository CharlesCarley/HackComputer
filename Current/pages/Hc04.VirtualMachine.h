/*!
\page Hc04 Virtual Machine

\brief Implements the virtual machine compiler.

\n

\section Hc04SVm2Asm Vm2Asm

The primary job of the compiler is to switch abstractions from VM to ASM code.

\n\n
\code{.txt}
Usage: vm2mc <options> <arg[0] .. arg[n]>

  where arg[0] is the input file
  
    -h, --help    Display this help message
    -o, --output  Specify an output file
\endcode

\subsection Hc04Grammar Grammar

The grammar for the VM can be found [here.](../../Source/VirtualMachine/VM.grm) 

\subsubsection Hc04GrammarNotes Note

It uses extra keywords that are not in the course specification.

- __set__ `set <int> <int>` Allows directly setting RAM values
- __reset__ `reset` Forces a CPU reset by jumping to the end of ROM `@32766 D=A;JMP`
- __halt__ `halt` Will emit code that enters into an infinite loop


\section Hc04Defined Defined In

The source is defined in [Source/VirtualMachine](../../Source/VirtualMachine/)

 */
#pragma once
