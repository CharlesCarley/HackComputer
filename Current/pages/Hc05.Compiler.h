/*!
\page Hc05 Compiler

\brief Provides tools to parse <tt>.jack</tt> files.

\n\n
The definition of the grammar can be found in [Jack.grm](../../Source/Compiler/Analyzer/Jack.grm).

\n\n
Options not in the course specification.

- __NOT__ `!`
  - The not unary operator is implemented as '~' and '!'.


\section Hc05Contents Contents

The compiler consists of a set of tools to handle <tt>.jack</tt> files.

\subsection Hc05SyntaxAnalyzer SyntaxAnalyzer

Implements a static library to parse and compile the parse tree to a node tree.


\subsection Hc05CompileUtils CompileUtils

Provides a bridge to store the node tree in intermediate form. 


\subsection Hc05Jack2XML Jack2XML

Transforms the node tree into an output xml or dot file.\n\n

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


\subsection Hc05CodeGenerator CodeGenerator

Implements a static library that converts the <tt>.jack</tt> parse tree into <tt>.vm</tt>  form.


\section Hc05Defined Defined In

The source is defined in [Source/Compiler](../../Source/Compiler/)

*/
#pragma once
