<a id="scanner"></a>
<h1>Scanner</h1>
<a id="classHack_1_1Assembler_1_1Scanner"></a>
<a href="https://github.com/CharlesCarley/HackComputer.md">~</a>
<a href="indexpage.md#hack">Hack</a>
<span class="inline-text">/</span>
<a href="index.md#index">Index</a>
<span class="inline-text">/</span>
<a href="namespaceHack.md#hack">Hack</a>
<span class="inline-text">::</span>
<a href="namespaceHack_1_1Assembler.md#assembler">Assembler</a>
<span class="inline-text">::</span>
<span class="bold-text"><b>Scanner</b></span>
<br/>
<br/>
<a id="derived-from"></a>
<h4>Derived From</h4>
<div class="icon-link">
<img src="../images/class.svg"/><a href="classHack_1_1ScannerBase.md#hackscannerbase">Hack::ScannerBase</a>
</div>
<img src="../images/dot/internal-diagram-2.dot.svg"/><br/>
<a id="private-members"></a>
<h2>Private Members</h2>
<span class="icon-list-item"><a href="#_fsr" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">_fsr</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#_offs" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">_offs</span>
</a>
</span>
<br/>
<a id="private-methods"></a>
<h2>Private Methods</h2>
<span class="icon-list-item"><a href="#extractrsymbol" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">extractRSymbol</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#initializetables" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">initializeTables</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#readsymbol" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">readSymbol</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#scandecimal" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">scanDecimal</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#scansymbol" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">scanSymbol</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#testmultipleregisterandjump" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">testMultipleRegisterAndJump</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#testsingleregister" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">testSingleRegister</span>
</a>
</span>
<br/>
<a id="public-methods"></a>
<h2>Public Methods</h2>
<span class="icon-list-item"><a href="#scanner" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">Scanner</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#firststaticregister" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">firstStaticRegister</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#nextstaticregister" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">nextStaticRegister</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#scan" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">scan</span>
</a>
</span>
<br/>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/Assembler/Scanner.h#L29" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Scanner.h</span>
</a>
</span>
<br/>
<a id="_fsr"></a>
<h2>_fsr</h2>
<span class="inline-text">size_t</span>
<span class="bold-text"><b>_fsr</b></span>
<br/>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/Assembler/Scanner.h#L31" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Scanner.h</span>
</a>
</span>
<br/>
<br/>
<a id="_offs"></a>
<h2>_offs</h2>
<span class="inline-text">size_t</span>
<span class="bold-text"><b>_offs</b></span>
<br/>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/Assembler/Scanner.h#L31" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Scanner.h</span>
</a>
</span>
<br/>
<br/>
<a id="extractrsymbol"></a>
<h2>extractRSymbol</h2>
<span class="inline-text">bool</span>
<span class="bold-text"><b>extractRSymbol</b></span>
<span class="italic-text"><i>(</i></span>
<div class="paragraph">
<span class="paragraph"><img src="../images/horSpace24px.svg"/><a href="namespaceHack_1_1Assembler.md#token">Token</a>
<span class="inline-text"> &amp;</span>
<span class="inline-text">tok</span>
</span>
</div>
<span class="italic-text"><i>)</i></span>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/Assembler/Scanner.h#L39" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Scanner.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/Assembler/Scanner.cpp#L139" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Scanner.cpp</span>
</a>
</span>
<br/>
<br/>
<a id="initializetables"></a>
<h2>initializeTables</h2>
<span class="inline-text">void</span>
<span class="bold-text"><b>initializeTables</b></span>
<span class="italic-text"><i>(</i></span>
<span class="italic-text"><i>)</i></span>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/Assembler/Scanner.h#L33" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Scanner.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/Assembler/Scanner.cpp#L75" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Scanner.cpp</span>
</a>
</span>
<br/>
<br/>
<a id="readsymbol"></a>
<h2>readSymbol</h2>
<span class="inline-text">void</span>
<span class="bold-text"><b>readSymbol</b></span>
<span class="italic-text"><i>(</i></span>
<div class="paragraph">
<span class="paragraph"><img src="../images/horSpace24px.svg"/><a href="namespaceHack.md#string">String</a>
<span class="inline-text"> &amp;</span>
<span class="inline-text">dest</span>
</span>
</div>
<span class="italic-text"><i>)</i></span>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/Assembler/Scanner.h#L41" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Scanner.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/Assembler/Scanner.cpp#L163" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Scanner.cpp</span>
</a>
</span>
<br/>
<br/>
<a id="scandecimal"></a>
<h2>scanDecimal</h2>
<span class="inline-text">void</span>
<span class="bold-text"><b>scanDecimal</b></span>
<span class="italic-text"><i>(</i></span>
<div class="paragraph">
<span class="paragraph"><img src="../images/horSpace24px.svg"/><a href="namespaceHack_1_1Assembler.md#token">Token</a>
<span class="inline-text"> &amp;</span>
<span class="inline-text">tok</span>
</span>
</div>
<span class="italic-text"><i>)</i></span>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/Assembler/Scanner.h#L35" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Scanner.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/Assembler/Scanner.cpp#L95" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Scanner.cpp</span>
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
<span class="paragraph"><img src="../images/horSpace24px.svg"/><a href="namespaceHack_1_1Assembler.md#token">Token</a>
<span class="inline-text"> &amp;</span>
<span class="inline-text">tok</span>
</span>
</div>
<span class="italic-text"><i>)</i></span>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/Assembler/Scanner.h#L37" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Scanner.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/Assembler/Scanner.cpp#L250" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Scanner.cpp</span>
</a>
</span>
<br/>
<br/>
<a id="testmultipleregisterandjump"></a>
<h2>testMultipleRegisterAndJump</h2>
<span class="inline-text">bool</span>
<span class="bold-text"><b>testMultipleRegisterAndJump</b></span>
<span class="italic-text"><i>(</i></span>
<div class="paragraph">
<span class="paragraph"><img src="../images/horSpace24px.svg"/><a href="namespaceHack_1_1Assembler.md#token">Token</a>
<span class="inline-text"> &amp;</span>
<span class="inline-text">tok</span>
</span>
</div>
<span class="italic-text"><i>)</i></span>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/Assembler/Scanner.h#L45" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Scanner.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/Assembler/Scanner.cpp#L216" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Scanner.cpp</span>
</a>
</span>
<br/>
<br/>
<a id="testsingleregister"></a>
<h2>testSingleRegister</h2>
<span class="inline-text">bool</span>
<span class="bold-text"><b>testSingleRegister</b></span>
<span class="italic-text"><i>(</i></span>
<div class="paragraph">
<span class="paragraph"><img src="../images/horSpace24px.svg"/><a href="namespaceHack_1_1Assembler.md#token">Token</a>
<span class="inline-text"> &amp;</span>
<span class="inline-text">tok</span>
</span>
</div>
<span class="italic-text"><i>)</i></span>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/Assembler/Scanner.h#L43" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Scanner.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/Assembler/Scanner.cpp#L180" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Scanner.cpp</span>
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
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/Assembler/Scanner.h#L48" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Scanner.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/Assembler/Scanner.cpp#L68" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Scanner.cpp</span>
</a>
</span>
<br/>
<br/>
<a id="firststaticregister"></a>
<h2>firstStaticRegister</h2>
<span class="inline-text">size_t</span>
<span class="bold-text"><b>firstStaticRegister</b></span>
<span class="italic-text"><i>(</i></span>
<span class="italic-text"><i>)</i></span>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/Assembler/Scanner.h#L54" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Scanner.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/Assembler/Scanner.cpp#L127" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Scanner.cpp</span>
</a>
</span>
<br/>
<br/>
<a id="nextstaticregister"></a>
<h2>nextStaticRegister</h2>
<span class="inline-text">size_t</span>
<span class="bold-text"><b>nextStaticRegister</b></span>
<span class="italic-text"><i>(</i></span>
<span class="italic-text"><i>)</i></span>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/Assembler/Scanner.h#L56" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Scanner.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/Assembler/Scanner.cpp#L132" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Scanner.cpp</span>
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
<span class="paragraph"><img src="../images/horSpace24px.svg"/><a href="namespaceHack_1_1Assembler.md#token">Token</a>
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
<span class="icon-list-item"><a href="classHack_1_1TokenBase.md#settype" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">setType</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Assembler.md#tok_at" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">TOK_AT</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Assembler.md#tok_minus" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">TOK_MINUS</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Assembler.md#tok_and" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">TOK_AND</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Assembler.md#tok_or" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">TOK_OR</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Assembler.md#tok_not" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">TOK_NOT</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Assembler.md#tok_semi_colon" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">TOK_SEMI_COLON</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Assembler.md#tok_plus" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">TOK_PLUS</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Assembler.md#tok_equal" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">TOK_EQUAL</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Assembler.md#tok_l_paren" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">TOK_L_PAREN</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Assembler.md#tok_r_paren" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">TOK_R_PAREN</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="classHack_1_1ScannerBase.md#scanwhitespace" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">scanWhiteSpace</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="classHack_1_1ScannerBase.md#syntaxerror" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">syntaxError</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Assembler.md#tok_eof" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">TOK_EOF</span>
</a>
</span>
<br/>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/Assembler/Scanner.h#L50" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Scanner.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/Assembler/Scanner.cpp#L285" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Scanner.cpp</span>
</a>
</span>
<br/>
<br/>
</div>
</div>
</body>
</html>
