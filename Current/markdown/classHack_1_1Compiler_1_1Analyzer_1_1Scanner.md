<a id="scanner"></a>
<h1>Scanner</h1>
<a id="classHack_1_1Compiler_1_1Analyzer_1_1Scanner"></a>
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
<span class="bold-text"><b>Scanner</b></span>
<br/>
<br/>
<a id="derived-from"></a>
<h4>Derived From</h4>
<div class="icon-link">
<img src="../images/class.svg"/><a href="classHack_1_1ScannerBase.md#hackscannerbase">Hack::ScannerBase</a>
</div>
<img src="../images/dot/internal-diagram-41.dot.svg"/><br/>
<a id="private-members"></a>
<h2>Private Members</h2>
<span class="icon-list-item"><a href="#_code" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">_code</span>
</a>
</span>
<br/>
<a id="private-methods"></a>
<h2>Private Methods</h2>
<span class="icon-list-item"><a href="#scancode" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">scanCode</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#scandigit" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">scanDigit</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#scanstring" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">scanString</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#scansymbol" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">scanSymbol</span>
</a>
</span>
<br/>
<a id="public-methods"></a>
<h2>Public Methods</h2>
<span class="icon-list-item"><a href="#scanner" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">Scanner</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#getcode" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">getCode</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#scan" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">scan</span>
</a>
</span>
<br/>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/Compiler/Analyzer/Scanner.h#L32" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Scanner.h</span>
</a>
</span>
<br/>
<a id="_code"></a>
<h2>_code</h2>
<a href="namespaceHack_1_1Compiler_1_1Analyzer.md#codecache">CodeCache</a>
<span class="bold-text"><b>_code</b></span>
<br/>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/Compiler/Analyzer/Scanner.h#L35" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Scanner.h</span>
</a>
</span>
<br/>
<br/>
<a id="scancode"></a>
<h2>scanCode</h2>
<span class="inline-text">void</span>
<span class="bold-text"><b>scanCode</b></span>
<span class="italic-text"><i>(</i></span>
<div class="paragraph">
<span class="paragraph"><img src="../images/horSpace24px.svg"/><a href="namespaceHack_1_1Compiler_1_1Analyzer.md#token">Token</a>
<span class="inline-text"> &amp;</span>
<span class="inline-text">tok</span>
</span>
</div>
<span class="italic-text"><i>)</i></span>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/Compiler/Analyzer/Scanner.h#L37" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Scanner.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/Compiler/Analyzer/Scanner.cpp#L71" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Scanner.cpp</span>
</a>
</span>
<br/>
<br/>
<a id="scandigit"></a>
<h2>scanDigit</h2>
<span class="inline-text">void</span>
<span class="bold-text"><b>scanDigit</b></span>
<span class="italic-text"><i>(</i></span>
<div class="paragraph">
<span class="paragraph"><img src="../images/horSpace24px.svg"/><a href="namespaceHack_1_1Compiler_1_1Analyzer.md#token">Token</a>
<span class="inline-text"> &amp;</span>
<span class="inline-text">tok</span>
</span>
</div>
<span class="italic-text"><i>)</i></span>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/Compiler/Analyzer/Scanner.h#L41" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Scanner.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/Compiler/Analyzer/Scanner.cpp#L115" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Scanner.cpp</span>
</a>
</span>
<br/>
<br/>
<a id="scanstring"></a>
<h2>scanString</h2>
<span class="inline-text">void</span>
<span class="bold-text"><b>scanString</b></span>
<span class="italic-text"><i>(</i></span>
<div class="paragraph">
<span class="paragraph"><img src="../images/horSpace24px.svg"/><a href="namespaceHack_1_1Compiler_1_1Analyzer.md#token">Token</a>
<span class="inline-text"> &amp;</span>
<span class="inline-text">tok</span>
</span>
</div>
<span class="italic-text"><i>)</i></span>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/Compiler/Analyzer/Scanner.h#L43" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Scanner.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/Compiler/Analyzer/Scanner.cpp#L133" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Scanner.cpp</span>
</a>
</span>
<br/>
<br/>
<a id="scansymbol"></a>
<h2>scanSymbol</h2>
<span class="inline-text">void</span>
<span class="bold-text"><b>scanSymbol</b></span>
<span class="italic-text"><i>(</i></span>
<div class="paragraph">
<span class="paragraph"><img src="../images/horSpace24px.svg"/><a href="namespaceHack_1_1Compiler_1_1Analyzer.md#token">Token</a>
<span class="inline-text"> &amp;</span>
<span class="inline-text">tok</span>
</span>
</div>
<span class="italic-text"><i>)</i></span>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/Compiler/Analyzer/Scanner.h#L39" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Scanner.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/Compiler/Analyzer/Scanner.cpp#L81" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Scanner.cpp</span>
</a>
</span>
<br/>
<br/>
<a id="scanner"></a>
<h2>Scanner</h2>
<span class="bold-text"><b>Scanner</b></span>
<span class="italic-text"><i>(</i></span>
<span class="italic-text"><i>)</i></span>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/Compiler/Analyzer/Scanner.h#L47" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Scanner.h</span>
</a>
</span>
<br/>
<br/>
<a id="getcode"></a>
<h2>getCode</h2>
<span class="inline-text">void</span>
<span class="bold-text"><b>getCode</b></span>
<span class="italic-text"><i>(</i></span>
<div class="paragraph">
<span class="paragraph"><img src="../images/horSpace24px.svg"/><a href="namespaceHack.md#string">String</a>
<span class="inline-text"> &amp;</span>
<span class="inline-text">dest</span>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/horSpace24px.svg"/><span class="inline-text">const size_t &amp;</span>
<span class="inline-text">idx</span>
</span>
</div>
<span class="italic-text"><i>)</i></span>
<a id="references"></a>
<h4>References</h4>
<span class="icon-list-item"><a href="classHack_1_1ScannerBase.md#syntaxerror" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">syntaxError</span>
</a>
</span>
<br/>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/Compiler/Analyzer/Scanner.h#L51" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Scanner.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/Compiler/Analyzer/Scanner.cpp#L189" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Scanner.cpp</span>
</a>
</span>
<br/>
<br/>
<a id="scan"></a>
<h2>scan</h2>
<span class="inline-text">void</span>
<span class="bold-text"><b>scan</b></span>
<span class="italic-text"><i>(</i></span>
<div class="paragraph">
<span class="paragraph"><img src="../images/horSpace24px.svg"/><a href="namespaceHack_1_1Compiler_1_1Analyzer.md#token">Token</a>
<span class="inline-text"> &amp;</span>
<span class="inline-text">tok</span>
</span>
</div>
<span class="italic-text"><i>)</i></span>
<a id="references"></a>
<h4>References</h4>
<span class="icon-list-item"><a href="classHack_1_1ScannerBase.md#_stream" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">_stream</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="classHack_1_1ScannerBase.md#syntaxerror" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">syntaxError</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="classHack_1_1TokenBase.md#clear" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">clear</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="classHack_1_1TokenBase.md#setline" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">setLine</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="classHack_1_1ScannerBase.md#_line" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">_line</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="classHack_1_1ScannerBase.md#scanlinecomment" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">scanLineComment</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="classHack_1_1ScannerBase.md#scanmultilinecomment" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">scanMultiLineComment</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="classHack_1_1TokenBase.md#settype" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">setType</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler_1_1Analyzer.md#tokopdivide" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">TokOpDivide</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="classHack_1_1ScannerBase.md#scanwhitespace" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">scanWhiteSpace</span>
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
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler_1_1Analyzer.md#tokopeq" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">TokOpEq</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler_1_1Analyzer.md#tokoplt" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">TokOpLt</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler_1_1Analyzer.md#tokopgt" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">TokOpGt</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler_1_1Analyzer.md#toksymperiod" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">TokSymPeriod</span>
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
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler_1_1Analyzer.md#toksymlbracket" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">TokSymLBracket</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler_1_1Analyzer.md#toksymrbracket" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">TokSymRBracket</span>
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
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler_1_1Analyzer.md#toksymcomma" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">TokSymComma</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler_1_1Analyzer.md#toksymsemicolon" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">TokSymSemicolon</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler_1_1Analyzer.md#tokeof" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">TokEof</span>
</a>
</span>
<br/>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/Compiler/Analyzer/Scanner.h#L49" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Scanner.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/Compiler/Analyzer/Scanner.cpp#L197" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Scanner.cpp</span>
</a>
</span>
<br/>
<br/>
</div>
</div>
</body>
</html>
