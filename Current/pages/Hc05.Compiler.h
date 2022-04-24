#pragma once
/*!
\page Hc05 Compiler

\brief Implements the jack compiler.

\n\n
The primary job of the compiler is to take the high level jack language
and translate it from, jack, vm, asm, then finally to mc.

\n\n
\section Hc05SyntaxAnalyzer SyntaxAnalyzer

Provides a static library that compiles the jack code into a parse tree.
\n\n
The definition for the jack grammar can be found [here.](../../Source/Compiler/Analyzer/Jack.grm)
- Note: the not operator `!` is implemented both as '~' and '!'.


\section Hc05CompileUtils CompileUtils

Provides the code that implements the parse tree, as well as extra classes that operate on the parse tree.

\section Hc05Jack2XML Jack2XML

Is the program that uses the parse tree and outputs inspection files.
\n\n

\code{.txt}
Usage: Jack2xml <options> <arg[0] .. arg[n]>

    -h, --help       Display this help message
    -f, --format     Specify an output file format
                      - xml, format as XML (default)
                      - dot, format as DOT
    -d, --directory  Converts all .jack files in the current directory to .xml
    -o, --output     Specify an output file
                       - the directory option takes precedence

\endcode

\section Hc05CodeGenerator CodeGenerator

Is the static library that implements the parse tree conversion from jack to vm.


\section Hc05Defined Defined In

The source is defined in [Source/Compiler](../../Source/Compiler/)

*/
