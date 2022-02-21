<a id="parseutils"></a>
<h1>ParseUtils</h1>
<a id="classHack_1_1Compiler_1_1Analyzer_1_1ParseUtils"></a>
<a href="https://github.com/CharlesCarley/HackComputer.md">~</a>
<a href="indexpage.md#hack">Hack</a>
<span class="inline-text">/</span>
<a href="index.md#index">Index</a>
<span class="inline-text">/</span>
<a href="namespaceHack.md#hack">Hack</a>
<span class="inline-text">::</span>
<a href="namespaceHack_1_1Compiler.md#compiler">Compiler</a>
<span class="inline-text">::</span>
<a href="namespaceHack_1_1Compiler_1_1Analyzer.md#analyzer">Analyzer</a>
<span class="inline-text">::</span>
<span class="bold-text"><b>ParseUtils</b></span>
<br/>
<br/>
<a id="public-static-methods"></a>
<h2>Public Static Methods</h2>
<span class="icon-list-item"><a href="#iscallterm" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">isCallTerm</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#iscomplexterm" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">isComplexTerm</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#isexpressionexitterm" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">isExpressionExitTerm</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#isfunctioncall" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">isFunctionCall</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#ismethodcall" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">isMethodCall</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#isoperator" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">isOperator</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#isterm" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">isTerm</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#isunary" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">isUnary</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#string" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">string</span>
</a>
</span>
<br/>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/Compiler/Analyzer/ParseUtils.h#L29" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">ParseUtils.h</span>
</a>
</span>
<br/>
<a id="iscallterm"></a>
<h2>isCallTerm</h2>
<span class="inline-text">bool</span>
<span class="bold-text"><b>isCallTerm</b></span>
<span class="italic-text"><i>(</i></span>
<div class="paragraph">
<span class="paragraph"><img src="../images/horSpace24px.svg"/><span class="inline-text">int8_t</span>
<span class="inline-text">t0</span>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/horSpace24px.svg"/><span class="inline-text">int8_t</span>
<span class="inline-text">t1</span>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/horSpace24px.svg"/><span class="inline-text">int8_t</span>
<span class="inline-text">t2</span>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/horSpace24px.svg"/><span class="inline-text">int8_t</span>
<span class="inline-text">t3</span>
</span>
</div>
<span class="italic-text"><i>)</i></span>
<a id="references"></a>
<h4>References</h4>
<span class="icon-list-item"><a href="classHack_1_1Compiler_1_1Analyzer_1_1ParseUtils.md#isfunctioncall" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">isFunctionCall</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="classHack_1_1Compiler_1_1Analyzer_1_1ParseUtils.md#ismethodcall" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">isMethodCall</span>
</a>
</span>
<br/>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/Compiler/Analyzer/ParseUtils.h#L45" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">ParseUtils.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/Compiler/Analyzer/ParseUtils.cpp#L114" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">ParseUtils.cpp</span>
</a>
</span>
<br/>
<br/>
<a id="iscomplexterm"></a>
<h2>isComplexTerm</h2>
<span class="inline-text">bool</span>
<span class="bold-text"><b>isComplexTerm</b></span>
<span class="italic-text"><i>(</i></span>
<div class="paragraph">
<span class="paragraph"><img src="../images/horSpace24px.svg"/><span class="inline-text">int8_t</span>
<span class="inline-text">t0</span>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/horSpace24px.svg"/><span class="inline-text">int8_t</span>
<span class="inline-text">t1</span>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/horSpace24px.svg"/><span class="inline-text">int8_t</span>
<span class="inline-text">t2</span>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/horSpace24px.svg"/><span class="inline-text">int8_t</span>
<span class="inline-text">t3</span>
</span>
</div>
<span class="italic-text"><i>)</i></span>
<a id="references"></a>
<h4>References</h4>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler_1_1Analyzer.md#toksymlpar" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">TokSymLPar</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler_1_1Analyzer.md#tokid" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">TokId</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler_1_1Analyzer.md#toksymlbracket" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">TokSymLBracket</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="classHack_1_1Compiler_1_1Analyzer_1_1ParseUtils.md#iscallterm" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">isCallTerm</span>
</a>
</span>
<br/>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/Compiler/Analyzer/ParseUtils.h#L47" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">ParseUtils.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/Compiler/Analyzer/ParseUtils.cpp#L122" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">ParseUtils.cpp</span>
</a>
</span>
<br/>
<br/>
<a id="isexpressionexitterm"></a>
<h2>isExpressionExitTerm</h2>
<span class="inline-text">bool</span>
<span class="bold-text"><b>isExpressionExitTerm</b></span>
<span class="italic-text"><i>(</i></span>
<div class="paragraph">
<span class="paragraph"><img src="../images/horSpace24px.svg"/><span class="inline-text">int8_t</span>
<span class="inline-text">t0</span>
</span>
</div>
<span class="italic-text"><i>)</i></span>
<a id="references"></a>
<h4>References</h4>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler_1_1Analyzer.md#toksymrbracket" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">TokSymRBracket</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler_1_1Analyzer.md#toksymsemicolon" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">TokSymSemicolon</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler_1_1Analyzer.md#toksymrpar" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">TokSymRPar</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler_1_1Analyzer.md#toksymcomma" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">TokSymComma</span>
</a>
</span>
<br/>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/Compiler/Analyzer/ParseUtils.h#L39" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">ParseUtils.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/Compiler/Analyzer/ParseUtils.cpp#L66" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">ParseUtils.cpp</span>
</a>
</span>
<br/>
<br/>
<a id="isfunctioncall"></a>
<h2>isFunctionCall</h2>
<span class="inline-text">bool</span>
<span class="bold-text"><b>isFunctionCall</b></span>
<span class="italic-text"><i>(</i></span>
<div class="paragraph">
<span class="paragraph"><img src="../images/horSpace24px.svg"/><span class="inline-text">int8_t</span>
<span class="inline-text">t0</span>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/horSpace24px.svg"/><span class="inline-text">int8_t</span>
<span class="inline-text">t1</span>
</span>
</div>
<span class="italic-text"><i>)</i></span>
<a id="references"></a>
<h4>References</h4>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler_1_1Analyzer.md#tokid" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">TokId</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler_1_1Analyzer.md#toksymlpar" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">TokSymLPar</span>
</a>
</span>
<br/>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/Compiler/Analyzer/ParseUtils.h#L41" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">ParseUtils.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/Compiler/Analyzer/ParseUtils.cpp#L95" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">ParseUtils.cpp</span>
</a>
</span>
<br/>
<br/>
<a id="ismethodcall"></a>
<h2>isMethodCall</h2>
<span class="inline-text">bool</span>
<span class="bold-text"><b>isMethodCall</b></span>
<span class="italic-text"><i>(</i></span>
<div class="paragraph">
<span class="paragraph"><img src="../images/horSpace24px.svg"/><span class="inline-text">int8_t</span>
<span class="inline-text">t0</span>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/horSpace24px.svg"/><span class="inline-text">int8_t</span>
<span class="inline-text">t1</span>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/horSpace24px.svg"/><span class="inline-text">int8_t</span>
<span class="inline-text">t2</span>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/horSpace24px.svg"/><span class="inline-text">int8_t</span>
<span class="inline-text">t3</span>
</span>
</div>
<span class="italic-text"><i>)</i></span>
<a id="references"></a>
<h4>References</h4>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler_1_1Analyzer.md#tokid" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">TokId</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler_1_1Analyzer.md#tokkwthis" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">TokKwThis</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler_1_1Analyzer.md#toksymperiod" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">TokSymPeriod</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler_1_1Analyzer.md#toksymlpar" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">TokSymLPar</span>
</a>
</span>
<br/>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/Compiler/Analyzer/ParseUtils.h#L43" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">ParseUtils.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/Compiler/Analyzer/ParseUtils.cpp#L103" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">ParseUtils.cpp</span>
</a>
</span>
<br/>
<br/>
<a id="isoperator"></a>
<h2>isOperator</h2>
<span class="inline-text">bool</span>
<span class="bold-text"><b>isOperator</b></span>
<span class="italic-text"><i>(</i></span>
<div class="paragraph">
<span class="paragraph"><img src="../images/horSpace24px.svg"/><span class="inline-text">int8_t</span>
<span class="inline-text">id</span>
</span>
</div>
<span class="italic-text"><i>)</i></span>
<a id="references"></a>
<h4>References</h4>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler_1_1Analyzer.md#tokopminus" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">TokOpMinus</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler_1_1Analyzer.md#tokopplus" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">TokOpPlus</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler_1_1Analyzer.md#tokopmultiply" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">TokOpMultiply</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler_1_1Analyzer.md#tokopdivide" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">TokOpDivide</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler_1_1Analyzer.md#tokopand" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">TokOpAnd</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler_1_1Analyzer.md#tokopor" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">TokOpOr</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler_1_1Analyzer.md#tokopgt" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">TokOpGt</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler_1_1Analyzer.md#tokoplt" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">TokOpLt</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler_1_1Analyzer.md#tokopeq" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">TokOpEq</span>
</a>
</span>
<br/>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/Compiler/Analyzer/ParseUtils.h#L33" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">ParseUtils.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/Compiler/Analyzer/ParseUtils.cpp#L29" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">ParseUtils.cpp</span>
</a>
</span>
<br/>
<br/>
<a id="isterm"></a>
<h2>isTerm</h2>
<span class="inline-text">bool</span>
<span class="bold-text"><b>isTerm</b></span>
<span class="italic-text"><i>(</i></span>
<div class="paragraph">
<span class="paragraph"><img src="../images/horSpace24px.svg"/><span class="inline-text">int8_t</span>
<span class="inline-text">t0</span>
</span>
</div>
<span class="italic-text"><i>)</i></span>
<a id="references"></a>
<h4>References</h4>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler_1_1Analyzer.md#tokid" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">TokId</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler_1_1Analyzer.md#tokint" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">TokInt</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler_1_1Analyzer.md#tokstring" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">TokString</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler_1_1Analyzer.md#tokkwfalse" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">TokKwFalse</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler_1_1Analyzer.md#tokkwtrue" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">TokKwTrue</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler_1_1Analyzer.md#tokkwnull" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">TokKwNull</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler_1_1Analyzer.md#tokkwthis" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">TokKwThis</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler_1_1Analyzer.md#toksymlpar" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">TokSymLPar</span>
</a>
</span>
<br/>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/Compiler/Analyzer/ParseUtils.h#L35" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">ParseUtils.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/Compiler/Analyzer/ParseUtils.cpp#L48" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">ParseUtils.cpp</span>
</a>
</span>
<br/>
<br/>
<a id="isunary"></a>
<h2>isUnary</h2>
<span class="inline-text">bool</span>
<span class="bold-text"><b>isUnary</b></span>
<span class="italic-text"><i>(</i></span>
<div class="paragraph">
<span class="paragraph"><img src="../images/horSpace24px.svg"/><span class="inline-text">int8_t</span>
<span class="inline-text">t0</span>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/horSpace24px.svg"/><span class="inline-text">int8_t</span>
<span class="inline-text">t1</span>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/horSpace24px.svg"/><span class="inline-text">int8_t</span>
<span class="inline-text">t2</span>
</span>
</div>
<span class="italic-text"><i>)</i></span>
<a id="references"></a>
<h4>References</h4>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler_1_1Analyzer.md#tokopnot" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">TokOpNot</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler_1_1Analyzer.md#tokopminus" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">TokOpMinus</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="classHack_1_1Compiler_1_1Analyzer_1_1ParseUtils.md#isterm" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">isTerm</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler_1_1Analyzer.md#toksymlpar" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">TokSymLPar</span>
</a>
</span>
<br/>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/Compiler/Analyzer/ParseUtils.h#L37" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">ParseUtils.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/Compiler/Analyzer/ParseUtils.cpp#L80" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">ParseUtils.cpp</span>
</a>
</span>
<br/>
<br/>
<a id="string"></a>
<h2>string</h2>
<a href="namespaceHack.md#string">String</a>
<span class="bold-text"><b>string</b></span>
<span class="italic-text"><i>(</i></span>
<div class="paragraph">
<span class="paragraph"><img src="../images/horSpace24px.svg"/><span class="inline-text">int</span>
<span class="inline-text">index</span>
</span>
</div>
<span class="italic-text"><i>)</i></span>
<a id="references"></a>
<h4>References</h4>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler_1_1Analyzer.md#toknull" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">TokNull</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler_1_1Analyzer.md#tokerror" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">TokError</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler_1_1Analyzer.md#tokeof" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">TokEof</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler_1_1Analyzer.md#tokint" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">TokInt</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler_1_1Analyzer.md#tokid" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">TokId</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler_1_1Analyzer.md#tokstring" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">TokString</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler_1_1Analyzer.md#tokkwclass" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">TokKwClass</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler_1_1Analyzer.md#tokkwconstructor" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">TokKwConstructor</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler_1_1Analyzer.md#tokkwfunction" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">TokKwFunction</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler_1_1Analyzer.md#tokkwmethod" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">TokKwMethod</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler_1_1Analyzer.md#tokkwfield" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">TokKwField</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler_1_1Analyzer.md#tokkwstatic" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">TokKwStatic</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler_1_1Analyzer.md#tokkwvar" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">TokKwVar</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler_1_1Analyzer.md#tokkwint" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">TokKwInt</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler_1_1Analyzer.md#tokkwchar" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">TokKwChar</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler_1_1Analyzer.md#tokkwbool" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">TokKwBool</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler_1_1Analyzer.md#tokkwvoid" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">TokKwVoid</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler_1_1Analyzer.md#tokkwlet" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">TokKwLet</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler_1_1Analyzer.md#tokkwdo" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">TokKwDo</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler_1_1Analyzer.md#tokkwif" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">TokKwIf</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler_1_1Analyzer.md#tokkwelse" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">TokKwElse</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler_1_1Analyzer.md#tokkwwhile" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">TokKwWhile</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler_1_1Analyzer.md#tokkwreturn" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">TokKwReturn</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler_1_1Analyzer.md#tokkwtrue" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">TokKwTrue</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler_1_1Analyzer.md#tokkwfalse" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">TokKwFalse</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler_1_1Analyzer.md#tokkwnull" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">TokKwNull</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler_1_1Analyzer.md#tokkwthis" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">TokKwThis</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler_1_1Analyzer.md#tokkwinlinevm" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">TokKwInlineVm</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler_1_1Analyzer.md#tokkwinlineasm" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">TokKwInlineAsm</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler_1_1Analyzer.md#tokopplus" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">TokOpPlus</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler_1_1Analyzer.md#tokopminus" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">TokOpMinus</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler_1_1Analyzer.md#tokopmultiply" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">TokOpMultiply</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler_1_1Analyzer.md#tokopdivide" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">TokOpDivide</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler_1_1Analyzer.md#tokopand" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">TokOpAnd</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler_1_1Analyzer.md#tokopor" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">TokOpOr</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler_1_1Analyzer.md#tokopnot" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">TokOpNot</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler_1_1Analyzer.md#tokopgt" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">TokOpGt</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler_1_1Analyzer.md#tokoplt" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">TokOpLt</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler_1_1Analyzer.md#tokopeq" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">TokOpEq</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler_1_1Analyzer.md#toksymlbracket" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">TokSymLBracket</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler_1_1Analyzer.md#toksymrbracket" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">TokSymRBracket</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler_1_1Analyzer.md#toksymlbrace" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">TokSymLBrace</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler_1_1Analyzer.md#toksymrbrace" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">TokSymRBrace</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler_1_1Analyzer.md#toksymlpar" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">TokSymLPar</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler_1_1Analyzer.md#toksymrpar" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">TokSymRPar</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler_1_1Analyzer.md#toksymperiod" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">TokSymPeriod</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler_1_1Analyzer.md#toksymcomma" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">TokSymComma</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler_1_1Analyzer.md#toksymsemicolon" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">TokSymSemicolon</span>
</a>
</span>
<br/>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/Compiler/Analyzer/ParseUtils.h#L31" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">ParseUtils.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/Compiler/Analyzer/ParseUtils.cpp#L134" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">ParseUtils.cpp</span>
</a>
</span>
<br/>
<br/>
</div>
</div>
</body>
</html>
