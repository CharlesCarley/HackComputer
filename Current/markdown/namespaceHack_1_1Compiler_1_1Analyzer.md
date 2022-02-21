<a id="analyzer"></a>
<h1>Analyzer</h1>
<a id="namespaceHack_1_1Compiler_1_1Analyzer"></a>
<a href="https://github.com/CharlesCarley/HackComputer.md">~</a>
<a href="indexpage.md#hack">Hack</a>
<span class="inline-text">/</span>
<a href="index.md#index">Index</a>
<span class="inline-text">/</span>
<a href="namespaceHack.md#hack">Hack</a>
<span class="inline-text">::</span>
<a href="namespaceHack_1_1Compiler.md#compiler">Compiler</a>
<span class="inline-text">::</span>
<span class="bold-text"><b>Analyzer</b></span>
<br/>
<br/>
<a id="classes"></a>
<h2>Classes</h2>
<span class="icon-list-item"><a href="structHack_1_1Compiler_1_1Analyzer_1_1KeywordTable.md#keywordtable" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">KeywordTable</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="classHack_1_1Compiler_1_1Analyzer_1_1Parser.md#parser" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">Parser</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="classHack_1_1Compiler_1_1Analyzer_1_1ParseUtils.md#parseutils" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">ParseUtils</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="classHack_1_1Compiler_1_1Analyzer_1_1Scanner.md#scanner" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">Scanner</span>
</a>
</span>
<br/>
<a id="enums"></a>
<h2>Enums</h2>
<span class="icon-list-item"><a href="#tokentype" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">TokenType</span>
</a>
</span>
<br/>
<a id="typedefs"></a>
<h2>Typedefs</h2>
<span class="icon-list-item"><a href="#codecache" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">CodeCache</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#nu" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">Nu</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#pu" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">Pu</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#token" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">Token</span>
</a>
</span>
<br/>
<a id="variables"></a>
<h2>Variables</h2>
<span class="icon-list-item"><a href="#reserved" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">Reserved</span>
</a>
</span>
<br/>
<a id="functions"></a>
<h2>Functions</h2>
<span class="icon-list-item"><a href="#isvalidcharacter" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">isValidCharacter</span>
</a>
</span>
<br/>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/Compiler/Analyzer/Parser.cpp#L31" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Parser.cpp</span>
</a>
</span>
<br/>
<a id="tokentype"></a>
<h2>TokenType</h2>
<span class="bold-text"><b>TokenType</b></span>
<br/>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">TokError</span>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">TokEof</span>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">TokNull</span>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">TokInt</span>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">TokId</span>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">TokString</span>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">TokKwClass</span>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">TokKwConstructor</span>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">TokKwFunction</span>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">TokKwMethod</span>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">TokKwField</span>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">TokKwStatic</span>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">TokKwVar</span>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">TokKwInt</span>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">TokKwChar</span>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">TokKwBool</span>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">TokKwVoid</span>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">TokKwLet</span>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">TokKwDo</span>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">TokKwIf</span>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">TokKwElse</span>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">TokKwWhile</span>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">TokKwReturn</span>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">TokKwTrue</span>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">TokKwFalse</span>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">TokKwNull</span>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">TokKwThis</span>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">TokKwInlineVm</span>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">TokKwInlineAsm</span>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">TokOpPlus</span>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">TokOpMinus</span>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">TokOpMultiply</span>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">TokOpDivide</span>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">TokOpAnd</span>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">TokOpOr</span>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">TokOpNot</span>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">TokOpGt</span>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">TokOpLt</span>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">TokOpEq</span>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">TokSymLBracket</span>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">TokSymRBracket</span>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">TokSymLBrace</span>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">TokSymRBrace</span>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">TokSymLPar</span>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">TokSymRPar</span>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">TokSymPeriod</span>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">TokSymComma</span>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">TokSymSemicolon</span>
</span>
</div>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/Compiler/Analyzer/Token.h#L28" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Token.h</span>
</a>
</span>
<br/>
<br/>
<a id="codecache"></a>
<h2>CodeCache</h2>
<span class="inline-text">std::vector&lt; </span>
<a href="namespaceHack.md#string">String</a>
<span class="inline-text"> &gt;</span>
<span class="bold-text"><b>CodeCache</b></span>
<br/>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/Compiler/Analyzer/Scanner.h#L28" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Scanner.h</span>
</a>
</span>
<br/>
<br/>
<a id="nu"></a>
<h2>Nu</h2>
<a href="classHack_1_1Compiler_1_1NodeUtils.md#nodeutils">NodeUtils</a>
<span class="bold-text"><b>Nu</b></span>
<br/>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/Compiler/Analyzer/Parser.cpp#L33" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Parser.cpp</span>
</a>
</span>
<br/>
<br/>
<a id="pu"></a>
<h2>Pu</h2>
<a href="classHack_1_1Compiler_1_1Analyzer_1_1ParseUtils.md#parseutils">ParseUtils</a>
<span class="bold-text"><b>Pu</b></span>
<br/>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/Compiler/Analyzer/Parser.cpp#L32" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Parser.cpp</span>
</a>
</span>
<br/>
<br/>
<a id="token"></a>
<h2>Token</h2>
<a href="classHack_1_1TokenBase.md#tokenbase">TokenBase</a>
<span class="bold-text"><b>Token</b></span>
<br/>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/Compiler/Analyzer/Token.h#L81" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Token.h</span>
</a>
</span>
<br/>
<br/>
<a id="reserved"></a>
<h2>Reserved</h2>
<span class="inline-text">constexpr </span>
<a href="structHack_1_1Compiler_1_1Analyzer_1_1KeywordTable.md#keywordtable">KeywordTable</a>
<span class="bold-text"><b>Reserved</b></span>
<br/>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/Compiler/Analyzer/Scanner.cpp#L39" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Scanner.cpp</span>
</a>
</span>
<br/>
<br/>
<a id="isvalidcharacter"></a>
<h2>isValidCharacter</h2>
<span class="inline-text">bool</span>
<span class="bold-text"><b>isValidCharacter</b></span>
<span class="italic-text"><i>(</i></span>
<div class="paragraph">
<span class="paragraph"><img src="../images/horSpace24px.svg"/><span class="inline-text">const int</span>
<span class="inline-text">ch</span>
</span>
</div>
<span class="italic-text"><i>)</i></span>
<a id="references"></a>
<h4>References</h4>
<span class="icon-list-item"><a href="namespaceHack.md#isletter" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">isLetter</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack.md#isdecimal" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">isDecimal</span>
</a>
</span>
<br/>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/Compiler/Analyzer/Scanner.cpp#L66" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Scanner.cpp</span>
</a>
</span>
<br/>
<br/>
</div>
</div>
</body>
</html>
