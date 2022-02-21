<a id="virtualmachine"></a>
<h1>VirtualMachine</h1>
<a id="namespaceHack_1_1VirtualMachine"></a>
<a href="https://github.com/CharlesCarley/HackComputer.md">~</a>
<a href="indexpage.md#hack">Hack</a>
<span class="inline-text">/</span>
<a href="index.md#index">Index</a>
<span class="inline-text">/</span>
<a href="namespaceHack.md#hack">Hack</a>
<span class="inline-text">::</span>
<span class="bold-text"><b>VirtualMachine</b></span>
<br/>
<br/>
<a id="classes"></a>
<h2>Classes</h2>
<span class="icon-list-item"><a href="classHack_1_1VirtualMachine_1_1CodeStream.md#codestream" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">CodeStream</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="classHack_1_1VirtualMachine_1_1Emitter.md#emitter" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">Emitter</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="structHack_1_1VirtualMachine_1_1KeywordTable.md#keywordtable" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">KeywordTable</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="classHack_1_1VirtualMachine_1_1Parser.md#parser" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">Parser</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="classHack_1_1VirtualMachine_1_1Scanner.md#scanner" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">Scanner</span>
</a>
</span>
<br/>
<a id="enums"></a>
<h2>Enums</h2>
<span class="icon-list-item"><a href="#ramindices" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">RamIndices</span>
</a>
</span>
<br/>
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
<span class="icon-list-item"><a href="#stringcache" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">StringCache</span>
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
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/Compiler/Generator/Generator.h#L32" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Generator.h</span>
</a>
</span>
<br/>
<a id="ramindices"></a>
<h2>RamIndices</h2>
<span class="bold-text"><b>RamIndices</b></span>
<br/>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">STP</span>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">LCL</span>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">ARG</span>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">THS</span>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">THT</span>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">TMP</span>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">SW0</span>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">SW1</span>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">SW2</span>
</span>
</div>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/VirtualMachine/Constants.h#L27" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Constants.h</span>
</a>
</span>
<br/>
<br/>
<a id="tokentype"></a>
<h2>TokenType</h2>
<span class="bold-text"><b>TokenType</b></span>
<br/>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">TOK_ERROR</span>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">TOK_EOF</span>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">TOK_NULL</span>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">TOK_INTEGER</span>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">TOK_IDENTIFIER</span>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">TOK_PUSH</span>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">TOK_POP</span>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">TOK_ARGUMENT</span>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">TOK_LOCAL</span>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">TOK_STATIC</span>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">TOK_CONSTANT</span>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">TOK_THIS</span>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">TOK_THAT</span>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">TOK_POINTER</span>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">TOK_TEMP</span>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">TOK_IF_GOTO</span>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">TOK_GOTO</span>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">TOK_LABEL</span>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">TOK_FUNCTION</span>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">TOK_CALL</span>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">TOK_RETURN</span>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">TOK_EQ</span>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">TOK_GT</span>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">TOK_LT</span>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">TOK_ADD</span>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">TOK_SUB</span>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">TOK_AND</span>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">TOK_OR</span>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">TOK_NOT</span>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">TOK_NEG</span>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">TOK_SET</span>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">TOK_RESET</span>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">TOK_HALT</span>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">TOK_ASM</span>
</span>
</div>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/VirtualMachine/Token.h#L28" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Token.h</span>
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
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/VirtualMachine/Scanner.h#L28" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Scanner.h</span>
</a>
</span>
<br/>
<br/>
<a id="stringcache"></a>
<h2>StringCache</h2>
<a href="classHack_1_1Cache.md#cache">Cache</a>
<span class="inline-text">&lt; </span>
<a href="namespaceHack.md#string">String</a>
<span class="inline-text"> &gt;</span>
<span class="bold-text"><b>StringCache</b></span>
<br/>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/VirtualMachine/Parser.h#L30" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Parser.h</span>
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
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/VirtualMachine/Token.h#L66" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Token.h</span>
</a>
</span>
<br/>
<br/>
<a id="reserved"></a>
<h2>Reserved</h2>
<span class="inline-text">constexpr </span>
<a href="structHack_1_1VirtualMachine_1_1KeywordTable.md#keywordtable">KeywordTable</a>
<span class="bold-text"><b>Reserved</b></span>
<br/>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/VirtualMachine/Scanner.cpp#L37" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Scanner.cpp</span>
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
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/VirtualMachine/Scanner.cpp#L70" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Scanner.cpp</span>
</a>
</span>
<br/>
<br/>
</div>
</div>
</body>
</html>
