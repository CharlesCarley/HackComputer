#pragma once
/*!
\page Hc05 Compiler

\brief Implements the compiler for the .jack source file.

\br
The primary job of the compiler is to take the high-level jack language
and translate it from, <tt>.jack,</tt> to <tt>.vm,</tt> then <tt>.asm,</tt> and finally to machine code.

\h1 SyntaxAnalyzer

The SyntaxAnalyzer project provides a static library that compiles the jack code
into an intermediate parse tree.
\br
The definition for the jack grammar can be found
\file_ref{here.,Source/Compiler/Analyzer/Jack.grm}
The primary difference in syntax between this implementation and the course
is that the not operator `!` is implemented both as '~' and '!'.


\h1 CompileUtils

Provides an intermediate static library that implements the parse tree structure.
The tree structure is meant to be shared between multiple projects. This library provides
that space. As such, it also contains extra classes that provide output formats for
the parse tree.

\h1 Jack2XML

Is an executable project that provides the means to output inspection files.

\br
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

\h2 Example

The following shows the different outputs of Jack2XML using the supplied <tt>.jack</tt> source file.

\code{.txt}
class Main
{
    function int main()
    {
        return 0;
    }
}
\endcode

Using \ref Hack::Compiler::XmlWriterImpl "XmlWriter"

\code{.xml}
<?xml version='1.0'?>
<ClassList Filename="example.jack">
 <RuleClass>
   <Keyword>class</Keyword>
   <Identifier>Main</Identifier>
   <Symbol>{</Symbol>
   <RuleClassDescription>
     <RuleMethod>
       <RuleMethodSpecification>
         <Keyword>function</Keyword>
       </RuleMethodSpecification>
       <RuleMethodReturnType>
         <RuleDataType>
           <Keyword>int</Keyword>
         </RuleDataType>
       </RuleMethodReturnType>
       <Identifier>main</Identifier>
       <Symbol>(</Symbol>
       <RuleParameterList>
       </RuleParameterList>
       <Symbol>)</Symbol>
       <RuleMethodBody>
         <Symbol>{</Symbol>
         <RuleBody>
           <RuleStatement>
             <RuleReturnStatement>
               <Keyword>return</Keyword>
               <RuleExpression>
                 <RuleSingleExpression Subtype="SubtypeTerm">
                   <RuleTerm>
                     <RuleSimpleTerm>
                       <Identifier>0</Identifier>
                     </RuleSimpleTerm>
                   </RuleTerm>
                 </RuleSingleExpression>
               </RuleExpression>
               <Symbol>;</Symbol>
             </RuleReturnStatement>
           </RuleStatement>
         </RuleBody>
         <Symbol>}</Symbol>
       </RuleMethodBody>
     </RuleMethod>
   </RuleClassDescription>
   <Symbol>}</Symbol>
 </RuleClass>
</ClassList>
\endcode

Using \ref Hack::Compiler::DotWriterImpl "DotWriter" after it has be converted to SVG with dot.

\image html Example.svg


\h1 CodeGenerator
Is a static library which implements the conversion from parse tree to <tt>.vm</tt>.


\h1 Compiler

The current state of this project does not implement a standalone compiler.
Instead, compilation happens in the \ref Hc06 "Computer" executable.
 

\defined{Hc05Defined}
\defined_in{Source/Compiler}

*/
