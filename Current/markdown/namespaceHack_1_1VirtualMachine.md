<a id="virtualmachine"></a>
<h1>VirtualMachine</h1>
<a id="namespacehack_1_1virtualmachine"></a>
<a href="https://github.com/CharlesCarley/HackComputer#~">~</a>
<a href="index.md#index">HackComputer</a>
<span class="inline-text">/</span>
<a href="namespaceHack.md#hack">Hack</a>
<span class="inline-text">::</span>
<span class="bold-text"><b>VirtualMachine</b></span>
<br/>
<br/>
<a id="classes"></a>
<h2>Classes</h2>
<div class="icon-link">
<img src="../images/class.svg"/><a href="classHack_1_1VirtualMachine_1_1CodeStream.md#codestream">CodeStream</a>
</div>
<div class="icon-link">
<img src="../images/class.svg"/><a href="classHack_1_1VirtualMachine_1_1Emitter.md#emitter">Emitter</a>
</div>
<div class="icon-link">
<img src="../images/class.svg"/><a href="structHack_1_1VirtualMachine_1_1KeywordTable.md#keywordtable">KeywordTable</a>
</div>
<div class="icon-link">
<img src="../images/class.svg"/><a href="classHack_1_1VirtualMachine_1_1Parser.md#parser">Parser</a>
</div>
<div class="icon-link">
<img src="../images/class.svg"/><a href="classHack_1_1VirtualMachine_1_1Scanner.md#scanner">Scanner</a>
</div>
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
<span class="icon-list-item"><a href="#intlist" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">IntList</span>
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
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Compiler/Generator/Generator.h#L33" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Generator.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#virtualmachine" class="icon-list-item"><img src="../images/jumpToTop.svg" class="icon-list-item"/><span class="icon-list-item">top</span>
</a>
</span>
<a id="ramindices"></a>
<h2>RamIndices</h2>
<span class="bold-text"><b>RamIndices</b></span>
<br/>
<a id="stp"></a>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">STP</span>
</span>
</div>
<a id="lcl"></a>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">LCL</span>
</span>
</div>
<a id="arg"></a>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">ARG</span>
</span>
</div>
<a id="ths"></a>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">THS</span>
</span>
</div>
<a id="tht"></a>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">THT</span>
</span>
</div>
<a id="tmp"></a>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">TMP</span>
</span>
</div>
<a id="sw0"></a>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">SW0</span>
</span>
</div>
<a id="sw1"></a>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">SW1</span>
</span>
</div>
<a id="sw2"></a>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">SW2</span>
</span>
</div>
<a id="stp"></a>
<a id="lcl"></a>
<a id="arg"></a>
<a id="ths"></a>
<a id="tht"></a>
<a id="tmp"></a>
<a id="sw0"></a>
<a id="sw1"></a>
<a id="sw2"></a>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/VirtualMachine/Constants.h#L27" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Constants.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#virtualmachine" class="icon-list-item"><img src="../images/jumpToTop.svg" class="icon-list-item"/><span class="icon-list-item">top</span>
</a>
</span>
<br/>
<a id="tokentype"></a>
<h2>TokenType</h2>
<span class="bold-text"><b>TokenType</b></span>
<br/>
<a id="tok_error"></a>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">TOK_ERROR</span>
</span>
</div>
<a id="tok_eof"></a>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">TOK_EOF</span>
</span>
</div>
<a id="tok_null"></a>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">TOK_NULL</span>
</span>
</div>
<a id="tok_integer"></a>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">TOK_INTEGER</span>
</span>
</div>
<a id="tok_identifier"></a>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">TOK_IDENTIFIER</span>
</span>
</div>
<a id="tok_push"></a>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">TOK_PUSH</span>
</span>
</div>
<a id="tok_pop"></a>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">TOK_POP</span>
</span>
</div>
<a id="tok_argument"></a>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">TOK_ARGUMENT</span>
</span>
</div>
<a id="tok_local"></a>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">TOK_LOCAL</span>
</span>
</div>
<a id="tok_static"></a>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">TOK_STATIC</span>
</span>
</div>
<a id="tok_constant"></a>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">TOK_CONSTANT</span>
</span>
</div>
<a id="tok_this"></a>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">TOK_THIS</span>
</span>
</div>
<a id="tok_that"></a>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">TOK_THAT</span>
</span>
</div>
<a id="tok_pointer"></a>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">TOK_POINTER</span>
</span>
</div>
<a id="tok_temp"></a>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">TOK_TEMP</span>
</span>
</div>
<a id="tok_if_goto"></a>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">TOK_IF_GOTO</span>
</span>
</div>
<a id="tok_goto"></a>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">TOK_GOTO</span>
</span>
</div>
<a id="tok_label"></a>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">TOK_LABEL</span>
</span>
</div>
<a id="tok_function"></a>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">TOK_FUNCTION</span>
</span>
</div>
<a id="tok_call"></a>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">TOK_CALL</span>
</span>
</div>
<a id="tok_return"></a>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">TOK_RETURN</span>
</span>
</div>
<a id="tok_eq"></a>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">TOK_EQ</span>
</span>
</div>
<a id="tok_gt"></a>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">TOK_GT</span>
</span>
</div>
<a id="tok_lt"></a>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">TOK_LT</span>
</span>
</div>
<a id="tok_add"></a>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">TOK_ADD</span>
</span>
</div>
<a id="tok_sub"></a>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">TOK_SUB</span>
</span>
</div>
<a id="tok_and"></a>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">TOK_AND</span>
</span>
</div>
<a id="tok_or"></a>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">TOK_OR</span>
</span>
</div>
<a id="tok_not"></a>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">TOK_NOT</span>
</span>
</div>
<a id="tok_neg"></a>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">TOK_NEG</span>
</span>
</div>
<a id="tok_set"></a>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">TOK_SET</span>
</span>
</div>
<a id="tok_reset"></a>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">TOK_RESET</span>
</span>
</div>
<a id="tok_halt"></a>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">TOK_HALT</span>
</span>
</div>
<a id="tok_asm"></a>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">TOK_ASM</span>
</span>
</div>
<a id="tok_error"></a>
<a id="tok_eof"></a>
<a id="tok_null"></a>
<a id="tok_integer"></a>
<a id="tok_identifier"></a>
<a id="tok_push"></a>
<a id="tok_pop"></a>
<a id="tok_argument"></a>
<a id="tok_local"></a>
<a id="tok_static"></a>
<a id="tok_constant"></a>
<a id="tok_this"></a>
<a id="tok_that"></a>
<a id="tok_pointer"></a>
<a id="tok_temp"></a>
<a id="tok_if_goto"></a>
<a id="tok_goto"></a>
<a id="tok_label"></a>
<a id="tok_function"></a>
<a id="tok_call"></a>
<a id="tok_return"></a>
<a id="tok_eq"></a>
<a id="tok_gt"></a>
<a id="tok_lt"></a>
<a id="tok_add"></a>
<a id="tok_sub"></a>
<a id="tok_and"></a>
<a id="tok_or"></a>
<a id="tok_not"></a>
<a id="tok_neg"></a>
<a id="tok_set"></a>
<a id="tok_reset"></a>
<a id="tok_halt"></a>
<a id="tok_asm"></a>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/VirtualMachine/Token.h#L28" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Token.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#virtualmachine" class="icon-list-item"><img src="../images/jumpToTop.svg" class="icon-list-item"/><span class="icon-list-item">top</span>
</a>
</span>
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
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/VirtualMachine/Scanner.h#L28" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Scanner.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#virtualmachine" class="icon-list-item"><img src="../images/jumpToTop.svg" class="icon-list-item"/><span class="icon-list-item">top</span>
</a>
</span>
<br/>
<a id="intlist"></a>
<h2>IntList</h2>
<span class="inline-text">std::vector&lt; int &gt;</span>
<span class="bold-text"><b>IntList</b></span>
<br/>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/VirtualMachine/Emitter.h#L29" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Emitter.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#virtualmachine" class="icon-list-item"><img src="../images/jumpToTop.svg" class="icon-list-item"/><span class="icon-list-item">top</span>
</a>
</span>
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
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/VirtualMachine/Parser.h#L30" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Parser.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#virtualmachine" class="icon-list-item"><img src="../images/jumpToTop.svg" class="icon-list-item"/><span class="icon-list-item">top</span>
</a>
</span>
<br/>
<a id="token"></a>
<h2>Token</h2>
<a href="classHack_1_1TokenBase.md#tokenbase">TokenBase</a>
<span class="bold-text"><b>Token</b></span>
<br/>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/VirtualMachine/Token.h#L66" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Token.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#virtualmachine" class="icon-list-item"><img src="../images/jumpToTop.svg" class="icon-list-item"/><span class="icon-list-item">top</span>
</a>
</span>
<br/>
<a id="reserved"></a>
<h2>Reserved</h2>
<span class="inline-text">constexpr </span>
<a href="structHack_1_1VirtualMachine_1_1KeywordTable.md#keywordtable">KeywordTable</a>
<span class="bold-text"><b>Reserved</b></span>
<br/>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/VirtualMachine/Scanner.cpp#L37" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Scanner.cpp</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#virtualmachine" class="icon-list-item"><img src="../images/jumpToTop.svg" class="icon-list-item"/><span class="icon-list-item">top</span>
</a>
</span>
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
<div class="paragraph">
<span class="paragraph"><img src="../images/class.svg"/><a href="namespaceHack.md#isletter">isLetter</a>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/class.svg"/><a href="namespaceHack.md#isdecimal">isDecimal</a>
</span>
</div>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/VirtualMachine/Scanner.cpp#L70" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Scanner.cpp</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#virtualmachine" class="icon-list-item"><img src="../images/jumpToTop.svg" class="icon-list-item"/><span class="icon-list-item">top</span>
</a>
</span>
<br/>
</div>
</div>
</body>
</html>
