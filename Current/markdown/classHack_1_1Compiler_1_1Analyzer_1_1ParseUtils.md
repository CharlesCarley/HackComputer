<a id="parseutils"></a>
<h1>ParseUtils</h1>
<a id="classhack_1_1compiler_1_1analyzer_1_1parseutils"></a>
<a href="https://github.com/CharlesCarley/HackComputer#~">~</a>
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
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Compiler/Analyzer/ParseUtils.h#L29" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">ParseUtils.h</span>
</a>
</span>
<br/>
<br/>
<blockquote>
<span class="icon-list-item"><a href="#parseutils" class="icon-list-item"><img src="../images/jumpToTop.svg" class="icon-list-item"/><span class="icon-list-item">top</span>
</a>
</span>
</blockquote>
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
<div class="paragraph">
<span class="paragraph"><img src="../images/class.svg"/><a href="classHack_1_1Compiler_1_1Analyzer_1_1ParseUtils.md#isfunctioncall">isFunctionCall</a>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/class.svg"/><a href="classHack_1_1Compiler_1_1Analyzer_1_1ParseUtils.md#ismethodcall">isMethodCall</a>
</span>
</div>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Compiler/Analyzer/ParseUtils.h#L45" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">ParseUtils.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Compiler/Analyzer/ParseUtils.cpp#L114" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">ParseUtils.cpp</span>
</a>
</span>
<br/>
<br/>
<blockquote>
<span class="icon-list-item"><a href="#parseutils" class="icon-list-item"><img src="../images/jumpToTop.svg" class="icon-list-item"/><span class="icon-list-item">top</span>
</a>
</span>
</blockquote>
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
<div class="paragraph">
<span class="paragraph"><img src="../images/class.svg"/><a href="namespaceHack_1_1Compiler_1_1Analyzer.md#toksymlpar">TokSymLPar</a>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/class.svg"/><a href="namespaceHack_1_1Compiler_1_1Analyzer.md#tokid">TokId</a>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/class.svg"/><a href="namespaceHack_1_1Compiler_1_1Analyzer.md#toksymlbracket">TokSymLBracket</a>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/class.svg"/><a href="classHack_1_1Compiler_1_1Analyzer_1_1ParseUtils.md#iscallterm">isCallTerm</a>
</span>
</div>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Compiler/Analyzer/ParseUtils.h#L47" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">ParseUtils.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Compiler/Analyzer/ParseUtils.cpp#L122" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">ParseUtils.cpp</span>
</a>
</span>
<br/>
<br/>
<blockquote>
<span class="icon-list-item"><a href="#parseutils" class="icon-list-item"><img src="../images/jumpToTop.svg" class="icon-list-item"/><span class="icon-list-item">top</span>
</a>
</span>
</blockquote>
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
<div class="paragraph">
<span class="paragraph"><img src="../images/class.svg"/><a href="namespaceHack_1_1Compiler_1_1Analyzer.md#toksymrbracket">TokSymRBracket</a>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/class.svg"/><a href="namespaceHack_1_1Compiler_1_1Analyzer.md#toksymsemicolon">TokSymSemicolon</a>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/class.svg"/><a href="namespaceHack_1_1Compiler_1_1Analyzer.md#toksymrpar">TokSymRPar</a>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/class.svg"/><a href="namespaceHack_1_1Compiler_1_1Analyzer.md#toksymcomma">TokSymComma</a>
</span>
</div>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Compiler/Analyzer/ParseUtils.h#L39" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">ParseUtils.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Compiler/Analyzer/ParseUtils.cpp#L66" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">ParseUtils.cpp</span>
</a>
</span>
<br/>
<br/>
<blockquote>
<span class="icon-list-item"><a href="#parseutils" class="icon-list-item"><img src="../images/jumpToTop.svg" class="icon-list-item"/><span class="icon-list-item">top</span>
</a>
</span>
</blockquote>
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
<div class="paragraph">
<span class="paragraph"><img src="../images/class.svg"/><a href="namespaceHack_1_1Compiler_1_1Analyzer.md#tokid">TokId</a>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/class.svg"/><a href="namespaceHack_1_1Compiler_1_1Analyzer.md#toksymlpar">TokSymLPar</a>
</span>
</div>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Compiler/Analyzer/ParseUtils.h#L41" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">ParseUtils.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Compiler/Analyzer/ParseUtils.cpp#L95" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">ParseUtils.cpp</span>
</a>
</span>
<br/>
<br/>
<blockquote>
<span class="icon-list-item"><a href="#parseutils" class="icon-list-item"><img src="../images/jumpToTop.svg" class="icon-list-item"/><span class="icon-list-item">top</span>
</a>
</span>
</blockquote>
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
<div class="paragraph">
<span class="paragraph"><img src="../images/class.svg"/><a href="namespaceHack_1_1Compiler_1_1Analyzer.md#tokid">TokId</a>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/class.svg"/><a href="namespaceHack_1_1Compiler_1_1Analyzer.md#tokkwthis">TokKwThis</a>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/class.svg"/><a href="namespaceHack_1_1Compiler_1_1Analyzer.md#toksymperiod">TokSymPeriod</a>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/class.svg"/><a href="namespaceHack_1_1Compiler_1_1Analyzer.md#toksymlpar">TokSymLPar</a>
</span>
</div>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Compiler/Analyzer/ParseUtils.h#L43" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">ParseUtils.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Compiler/Analyzer/ParseUtils.cpp#L103" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">ParseUtils.cpp</span>
</a>
</span>
<br/>
<br/>
<blockquote>
<span class="icon-list-item"><a href="#parseutils" class="icon-list-item"><img src="../images/jumpToTop.svg" class="icon-list-item"/><span class="icon-list-item">top</span>
</a>
</span>
</blockquote>
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
<div class="paragraph">
<span class="paragraph"><img src="../images/class.svg"/><a href="namespaceHack_1_1Compiler_1_1Analyzer.md#tokopminus">TokOpMinus</a>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/class.svg"/><a href="namespaceHack_1_1Compiler_1_1Analyzer.md#tokopplus">TokOpPlus</a>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/class.svg"/><a href="namespaceHack_1_1Compiler_1_1Analyzer.md#tokopmultiply">TokOpMultiply</a>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/class.svg"/><a href="namespaceHack_1_1Compiler_1_1Analyzer.md#tokopdivide">TokOpDivide</a>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/class.svg"/><a href="namespaceHack_1_1Compiler_1_1Analyzer.md#tokopand">TokOpAnd</a>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/class.svg"/><a href="namespaceHack_1_1Compiler_1_1Analyzer.md#tokopor">TokOpOr</a>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/class.svg"/><a href="namespaceHack_1_1Compiler_1_1Analyzer.md#tokopgt">TokOpGt</a>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/class.svg"/><a href="namespaceHack_1_1Compiler_1_1Analyzer.md#tokoplt">TokOpLt</a>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/class.svg"/><a href="namespaceHack_1_1Compiler_1_1Analyzer.md#tokopeq">TokOpEq</a>
</span>
</div>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Compiler/Analyzer/ParseUtils.h#L33" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">ParseUtils.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Compiler/Analyzer/ParseUtils.cpp#L29" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">ParseUtils.cpp</span>
</a>
</span>
<br/>
<br/>
<blockquote>
<span class="icon-list-item"><a href="#parseutils" class="icon-list-item"><img src="../images/jumpToTop.svg" class="icon-list-item"/><span class="icon-list-item">top</span>
</a>
</span>
</blockquote>
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
<div class="paragraph">
<span class="paragraph"><img src="../images/class.svg"/><a href="namespaceHack_1_1Compiler_1_1Analyzer.md#tokid">TokId</a>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/class.svg"/><a href="namespaceHack_1_1Compiler_1_1Analyzer.md#tokint">TokInt</a>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/class.svg"/><a href="namespaceHack_1_1Compiler_1_1Analyzer.md#tokstring">TokString</a>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/class.svg"/><a href="namespaceHack_1_1Compiler_1_1Analyzer.md#tokkwfalse">TokKwFalse</a>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/class.svg"/><a href="namespaceHack_1_1Compiler_1_1Analyzer.md#tokkwtrue">TokKwTrue</a>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/class.svg"/><a href="namespaceHack_1_1Compiler_1_1Analyzer.md#tokkwnull">TokKwNull</a>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/class.svg"/><a href="namespaceHack_1_1Compiler_1_1Analyzer.md#tokkwthis">TokKwThis</a>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/class.svg"/><a href="namespaceHack_1_1Compiler_1_1Analyzer.md#toksymlpar">TokSymLPar</a>
</span>
</div>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Compiler/Analyzer/ParseUtils.h#L35" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">ParseUtils.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Compiler/Analyzer/ParseUtils.cpp#L48" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">ParseUtils.cpp</span>
</a>
</span>
<br/>
<br/>
<blockquote>
<span class="icon-list-item"><a href="#parseutils" class="icon-list-item"><img src="../images/jumpToTop.svg" class="icon-list-item"/><span class="icon-list-item">top</span>
</a>
</span>
</blockquote>
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
<div class="paragraph">
<span class="paragraph"><img src="../images/class.svg"/><a href="namespaceHack_1_1Compiler_1_1Analyzer.md#tokopnot">TokOpNot</a>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/class.svg"/><a href="namespaceHack_1_1Compiler_1_1Analyzer.md#tokopminus">TokOpMinus</a>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/class.svg"/><a href="classHack_1_1Compiler_1_1Analyzer_1_1ParseUtils.md#isterm">isTerm</a>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/class.svg"/><a href="namespaceHack_1_1Compiler_1_1Analyzer.md#toksymlpar">TokSymLPar</a>
</span>
</div>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Compiler/Analyzer/ParseUtils.h#L37" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">ParseUtils.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Compiler/Analyzer/ParseUtils.cpp#L80" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">ParseUtils.cpp</span>
</a>
</span>
<br/>
<br/>
<blockquote>
<span class="icon-list-item"><a href="#parseutils" class="icon-list-item"><img src="../images/jumpToTop.svg" class="icon-list-item"/><span class="icon-list-item">top</span>
</a>
</span>
</blockquote>
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
<div class="paragraph">
<span class="paragraph"><img src="../images/class.svg"/><a href="namespaceHack_1_1Compiler_1_1Analyzer.md#toknull">TokNull</a>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/class.svg"/><a href="namespaceHack_1_1Compiler_1_1Analyzer.md#tokerror">TokError</a>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/class.svg"/><a href="namespaceHack_1_1Compiler_1_1Analyzer.md#tokeof">TokEof</a>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/class.svg"/><a href="namespaceHack_1_1Compiler_1_1Analyzer.md#tokint">TokInt</a>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/class.svg"/><a href="namespaceHack_1_1Compiler_1_1Analyzer.md#tokid">TokId</a>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/class.svg"/><a href="namespaceHack_1_1Compiler_1_1Analyzer.md#tokstring">TokString</a>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/class.svg"/><a href="namespaceHack_1_1Compiler_1_1Analyzer.md#tokkwclass">TokKwClass</a>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/class.svg"/><a href="namespaceHack_1_1Compiler_1_1Analyzer.md#tokkwconstructor">TokKwConstructor</a>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/class.svg"/><a href="namespaceHack_1_1Compiler_1_1Analyzer.md#tokkwfunction">TokKwFunction</a>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/class.svg"/><a href="namespaceHack_1_1Compiler_1_1Analyzer.md#tokkwmethod">TokKwMethod</a>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/class.svg"/><a href="namespaceHack_1_1Compiler_1_1Analyzer.md#tokkwfield">TokKwField</a>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/class.svg"/><a href="namespaceHack_1_1Compiler_1_1Analyzer.md#tokkwstatic">TokKwStatic</a>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/class.svg"/><a href="namespaceHack_1_1Compiler_1_1Analyzer.md#tokkwvar">TokKwVar</a>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/class.svg"/><a href="namespaceHack_1_1Compiler_1_1Analyzer.md#tokkwint">TokKwInt</a>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/class.svg"/><a href="namespaceHack_1_1Compiler_1_1Analyzer.md#tokkwchar">TokKwChar</a>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/class.svg"/><a href="namespaceHack_1_1Compiler_1_1Analyzer.md#tokkwbool">TokKwBool</a>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/class.svg"/><a href="namespaceHack_1_1Compiler_1_1Analyzer.md#tokkwvoid">TokKwVoid</a>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/class.svg"/><a href="namespaceHack_1_1Compiler_1_1Analyzer.md#tokkwlet">TokKwLet</a>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/class.svg"/><a href="namespaceHack_1_1Compiler_1_1Analyzer.md#tokkwdo">TokKwDo</a>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/class.svg"/><a href="namespaceHack_1_1Compiler_1_1Analyzer.md#tokkwif">TokKwIf</a>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/class.svg"/><a href="namespaceHack_1_1Compiler_1_1Analyzer.md#tokkwelse">TokKwElse</a>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/class.svg"/><a href="namespaceHack_1_1Compiler_1_1Analyzer.md#tokkwwhile">TokKwWhile</a>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/class.svg"/><a href="namespaceHack_1_1Compiler_1_1Analyzer.md#tokkwreturn">TokKwReturn</a>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/class.svg"/><a href="namespaceHack_1_1Compiler_1_1Analyzer.md#tokkwtrue">TokKwTrue</a>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/class.svg"/><a href="namespaceHack_1_1Compiler_1_1Analyzer.md#tokkwfalse">TokKwFalse</a>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/class.svg"/><a href="namespaceHack_1_1Compiler_1_1Analyzer.md#tokkwnull">TokKwNull</a>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/class.svg"/><a href="namespaceHack_1_1Compiler_1_1Analyzer.md#tokkwthis">TokKwThis</a>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/class.svg"/><a href="namespaceHack_1_1Compiler_1_1Analyzer.md#tokkwinlinevm">TokKwInlineVm</a>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/class.svg"/><a href="namespaceHack_1_1Compiler_1_1Analyzer.md#tokkwinlineasm">TokKwInlineAsm</a>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/class.svg"/><a href="namespaceHack_1_1Compiler_1_1Analyzer.md#tokopplus">TokOpPlus</a>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/class.svg"/><a href="namespaceHack_1_1Compiler_1_1Analyzer.md#tokopminus">TokOpMinus</a>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/class.svg"/><a href="namespaceHack_1_1Compiler_1_1Analyzer.md#tokopmultiply">TokOpMultiply</a>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/class.svg"/><a href="namespaceHack_1_1Compiler_1_1Analyzer.md#tokopdivide">TokOpDivide</a>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/class.svg"/><a href="namespaceHack_1_1Compiler_1_1Analyzer.md#tokopand">TokOpAnd</a>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/class.svg"/><a href="namespaceHack_1_1Compiler_1_1Analyzer.md#tokopor">TokOpOr</a>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/class.svg"/><a href="namespaceHack_1_1Compiler_1_1Analyzer.md#tokopnot">TokOpNot</a>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/class.svg"/><a href="namespaceHack_1_1Compiler_1_1Analyzer.md#tokopgt">TokOpGt</a>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/class.svg"/><a href="namespaceHack_1_1Compiler_1_1Analyzer.md#tokoplt">TokOpLt</a>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/class.svg"/><a href="namespaceHack_1_1Compiler_1_1Analyzer.md#tokopeq">TokOpEq</a>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/class.svg"/><a href="namespaceHack_1_1Compiler_1_1Analyzer.md#toksymlbracket">TokSymLBracket</a>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/class.svg"/><a href="namespaceHack_1_1Compiler_1_1Analyzer.md#toksymrbracket">TokSymRBracket</a>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/class.svg"/><a href="namespaceHack_1_1Compiler_1_1Analyzer.md#toksymlbrace">TokSymLBrace</a>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/class.svg"/><a href="namespaceHack_1_1Compiler_1_1Analyzer.md#toksymrbrace">TokSymRBrace</a>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/class.svg"/><a href="namespaceHack_1_1Compiler_1_1Analyzer.md#toksymlpar">TokSymLPar</a>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/class.svg"/><a href="namespaceHack_1_1Compiler_1_1Analyzer.md#toksymrpar">TokSymRPar</a>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/class.svg"/><a href="namespaceHack_1_1Compiler_1_1Analyzer.md#toksymperiod">TokSymPeriod</a>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/class.svg"/><a href="namespaceHack_1_1Compiler_1_1Analyzer.md#toksymcomma">TokSymComma</a>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/class.svg"/><a href="namespaceHack_1_1Compiler_1_1Analyzer.md#toksymsemicolon">TokSymSemicolon</a>
</span>
</div>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Compiler/Analyzer/ParseUtils.h#L31" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">ParseUtils.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Compiler/Analyzer/ParseUtils.cpp#L134" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">ParseUtils.cpp</span>
</a>
</span>
<br/>
<br/>
<blockquote>
<span class="icon-list-item"><a href="#parseutils" class="icon-list-item"><img src="../images/jumpToTop.svg" class="icon-list-item"/><span class="icon-list-item">top</span>
</a>
</span>
</blockquote>
<br/>
</div>
</div>
</body>
</html>
