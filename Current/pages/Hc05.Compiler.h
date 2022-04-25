#pragma once
/*!
\page Hc05 Compiler

\brief Implements the compiler for the .jack format.

\br

The primary job of the compiler is to take the high-level jack language
and translate it from, .jack, .vm, .asm, then finally to machine code.

\section Hc05SyntaxAnalyzer SyntaxAnalyzer

Provides static library that compiles the jack code into an intermediate parse tree.
\n\n
The definition for the jack grammar can be found [here.](../../Source/Compiler/Analyzer/Jack.grm)
- The not operator `!` is implemented both as '~' and '!'.


\section Hc05CompileUtils CompileUtils

Provides the code that implements the parse tree, as well as extra classes that operate on the parse tree.

\section Hc05Jack2XML Jack2XML

Uses the parse tree and outputs inspection files.
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
\br

The following shows example output with the supplied <tt>.jack</tt> source file.
\sec{Test10}
\code{.txt}
class Main {
	method void main() {
		var int x,y;
		let x = 2;
		let y = 6;
		return x+y;
	}
}
\endcode

\sec{XML}
\code{.xml}
<?xml version='1.0'?>
<ClassList Filename="Test10.jack">
 <RuleClass Line="3">
   <Keyword Line="3">class</Keyword>
   <Identifier Line="3">Main</Identifier>
   <Symbol Line="3">{</Symbol>
   <RuleClassDescription Line="3">
     <RuleMethod Line="5">
       <RuleMethodSpecification Line="5">
         <Keyword Line="5">method</Keyword>
       </RuleMethodSpecification>
       <RuleMethodReturnType Line="5">
         <Keyword Line="5">void</Keyword>
       </RuleMethodReturnType>
       <Identifier Line="5">main</Identifier>
       <Symbol Line="5">(</Symbol>
       <RuleParameterList Line="5">
       </RuleParameterList>
       <Symbol Line="5">)</Symbol>
       <RuleMethodBody Line="5">
         <Symbol Line="5">{</Symbol>
         <RuleBody Line="6">
           <RuleVariable Line="6">
             <Keyword Line="6">var</Keyword>
             <RuleDataType Line="6">
               <Keyword Line="6">int</Keyword>
             </RuleDataType>
             <RuleIdentifierList Line="6">
               <Identifier Line="6">x</Identifier>
               <Identifier Line="6">y</Identifier>
             </RuleIdentifierList>
             <Symbol Line="6">;</Symbol>
           </RuleVariable>
           <RuleStatement Line="7">
             <RuleLetStatement Line="7" Subtype="SubtypeLetEqual">
               <Keyword Line="7">let</Keyword>
               <Identifier Line="7">x</Identifier>
               <Symbol Line="7">=</Symbol>
               <RuleExpression Line="7">
                 <RuleSingleExpression Line="7" Subtype="SubtypeTerm">
                   <RuleTerm Line="7">
                     <RuleSimpleTerm Line="8">
                       <Identifier Line="8">2</Identifier>
                     </RuleSimpleTerm>
                   </RuleTerm>
                 </RuleSingleExpression>
               </RuleExpression>
               <Symbol Line="8">;</Symbol>
             </RuleLetStatement>
           </RuleStatement>
           <RuleStatement Line="8">
             <RuleLetStatement Line="8" Subtype="SubtypeLetEqual">
               <Keyword Line="8">let</Keyword>
               <Identifier Line="8">y</Identifier>
               <Symbol Line="8">=</Symbol>
               <RuleExpression Line="8">
                 <RuleSingleExpression Line="8" Subtype="SubtypeTerm">
                   <RuleTerm Line="8">
                     <RuleSimpleTerm Line="9">
                       <Identifier Line="9">6</Identifier>
                     </RuleSimpleTerm>
                   </RuleTerm>
                 </RuleSingleExpression>
               </RuleExpression>
               <Symbol Line="9">;</Symbol>
             </RuleLetStatement>
           </RuleStatement>
           <RuleStatement Line="9">
             <RuleReturnStatement Line="9">
               <Keyword Line="9">return</Keyword>
               <RuleExpression Line="9">
                 <RuleSingleExpression Line="9" Subtype="SubtypeTerm">
                   <RuleTerm Line="9">
                     <RuleSimpleTerm Line="9">
                       <Identifier Line="9">x</Identifier>
                     </RuleSimpleTerm>
                   </RuleTerm>
                 </RuleSingleExpression>
                 <RuleSingleExpression Line="9" Subtype="SubtypeOpTerm">
                   <RuleOperator Line="9">
                     <Symbol Line="9">+</Symbol>
                   </RuleOperator>
                   <RuleTerm Line="9">
                     <RuleSimpleTerm Line="11">
                       <Identifier Line="11">y</Identifier>
                     </RuleSimpleTerm>
                   </RuleTerm>
                 </RuleSingleExpression>
               </RuleExpression>
               <Symbol Line="11">;</Symbol>
             </RuleReturnStatement>
           </RuleStatement>
         </RuleBody>
         <Symbol Line="11">}</Symbol>
       </RuleMethodBody>
     </RuleMethod>
   </RuleClassDescription>
   <Symbol Line="11">}</Symbol>
 </RuleClass>
</ClassList>
\endcode

\sec{DOT}
\image html Test10.svg


\section Hc05CodeGenerator CodeGenerator

Is the static library that implements the parse tree conversion from jack to vm.


\section Hc05compiler Compiler

The current state does not implement a standalone compiler.
Compilation happens in the \ref Hc07 "Computer" executable.
 

\defined{Hc05Defined}
\defined_in{Source/Compiler}

*/
