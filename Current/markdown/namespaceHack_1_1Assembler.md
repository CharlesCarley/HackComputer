<a id="assembler"></a>
<h1>Assembler</h1>
<a id="namespaceHack_1_1Assembler"></a>
<a href="https://github.com/CharlesCarley/HackComputer.md">~</a>
<a href="indexpage.md#hack">Hack</a>
<span class="inline-text">/</span>
<a href="index.md#index">Index</a>
<span class="inline-text">/</span>
<a href="namespaceHack.md#hack">Hack</a>
<span class="inline-text">::</span>
<span class="bold-text"><b>Assembler</b></span>
<br/>
<br/>
<a id="classes"></a>
<h2>Classes</h2>
<span class="icon-list-item"><a href="classHack_1_1Assembler_1_1Instruction.md#instruction" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">Instruction</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="structHack_1_1Assembler_1_1KeywordTable.md#keywordtable" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">KeywordTable</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="classHack_1_1Assembler_1_1Parser.md#parser" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">Parser</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="structHack_1_1Assembler_1_1ReservedWordTable.md#reservedwordtable" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">ReservedWordTable</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="classHack_1_1Assembler_1_1Scanner.md#scanner" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">Scanner</span>
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
<span class="icon-list-item"><a href="#stringindex" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">StringIndex</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#token" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">Token</span>
</a>
</span>
<br/>
<a id="variables"></a>
<h2>Variables</h2>
<span class="icon-list-item"><a href="#destandjumptable" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">DestAndJumpTable</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#reservedaddresses" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">ReservedAddresses</span>
</a>
</span>
<br/>
<a id="functions"></a>
<h2>Functions</h2>
<span class="icon-list-item"><a href="#isconstanttoken" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">isConstantToken</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#isdesttoken" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">isDestToken</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#isjumptoken" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">isJumpToken</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#isoperatortoken" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">isOperatorToken</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#testcompoundexpression" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">testCompoundExpression</span>
</a>
</span>
<br/>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/Assembler/Instruction.cpp#L26" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Instruction.cpp</span>
</a>
</span>
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
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">TOK_D_START</span>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">TOK_M</span>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">TOK_D</span>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">TOK_MD</span>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">TOK_A</span>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">TOK_AM</span>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">TOK_AD</span>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">TOK_AMD</span>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">TOK_J_START</span>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">TOK_JGT</span>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">TOK_JEQ</span>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">TOK_JGE</span>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">TOK_JLT</span>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">TOK_JNE</span>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">TOK_JLE</span>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">TOK_JMP</span>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">TOK_ZERO</span>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">TOK_MINUS</span>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">TOK_NOT</span>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">TOK_PLUS</span>
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
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">TOK_AT</span>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">TOK_SEMI_COLON</span>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">TOK_EQUAL</span>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">TOK_L_PAREN</span>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">TOK_R_PAREN</span>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">TOK_COMMA</span>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">TOK_ONE</span>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">TOK_INTEGER</span>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">TOK_LABEL</span>
</span>
</div>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/Assembler/Token.h#L28" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Token.h</span>
</a>
</span>
<br/>
<br/>
<a id="stringindex"></a>
<h2>StringIndex</h2>
<span class="inline-text">std::pair&lt; </span>
<a href="namespaceHack.md#string">String</a>
<span class="inline-text">, size_t &gt;</span>
<span class="bold-text"><b>StringIndex</b></span>
<br/>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/Assembler/Parser.h#L29" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Parser.h</span>
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
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/Assembler/Token.h#L68" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Token.h</span>
</a>
</span>
<br/>
<br/>
<a id="destandjumptable"></a>
<h2>DestAndJumpTable</h2>
<span class="inline-text">constexpr </span>
<a href="structHack_1_1Assembler_1_1KeywordTable.md#keywordtable">KeywordTable</a>
<span class="bold-text"><b>DestAndJumpTable</b></span>
<br/>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/Assembler/Scanner.cpp#L42" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Scanner.cpp</span>
</a>
</span>
<br/>
<br/>
<a id="reservedaddresses"></a>
<h2>ReservedAddresses</h2>
<span class="inline-text">constexpr </span>
<a href="structHack_1_1Assembler_1_1ReservedWordTable.md#reservedwordtable">ReservedWordTable</a>
<span class="bold-text"><b>ReservedAddresses</b></span>
<br/>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/Assembler/Scanner.cpp#L57" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Scanner.cpp</span>
</a>
</span>
<br/>
<br/>
<a id="isconstanttoken"></a>
<h2>isConstantToken</h2>
<span class="inline-text">bool</span>
<span class="bold-text"><b>isConstantToken</b></span>
<span class="italic-text"><i>(</i></span>
<div class="paragraph">
<span class="paragraph"><img src="../images/horSpace24px.svg"/><span class="inline-text">const int8_t</span>
<span class="inline-text">type</span>
</span>
</div>
<span class="italic-text"><i>)</i></span>
<a id="references"></a>
<h4>References</h4>
<span class="icon-list-item"><a href="namespaceHack_1_1Assembler.md#tok_zero" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">TOK_ZERO</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Assembler.md#tok_one" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">TOK_ONE</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Assembler.md#tok_integer" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">TOK_INTEGER</span>
</a>
</span>
<br/>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/Assembler/Parser.cpp#L47" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Parser.cpp</span>
</a>
</span>
<br/>
<br/>
<a id="isdesttoken"></a>
<h2>isDestToken</h2>
<span class="inline-text">bool</span>
<span class="bold-text"><b>isDestToken</b></span>
<span class="italic-text"><i>(</i></span>
<div class="paragraph">
<span class="paragraph"><img src="../images/horSpace24px.svg"/><span class="inline-text">const int8_t</span>
<span class="inline-text">type</span>
</span>
</div>
<span class="italic-text"><i>)</i></span>
<a id="references"></a>
<h4>References</h4>
<span class="icon-list-item"><a href="namespaceHack_1_1Assembler.md#tok_m" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">TOK_M</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Assembler.md#tok_amd" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">TOK_AMD</span>
</a>
</span>
<br/>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/Assembler/Parser.cpp#L42" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Parser.cpp</span>
</a>
</span>
<br/>
<br/>
<a id="isjumptoken"></a>
<h2>isJumpToken</h2>
<span class="inline-text">bool</span>
<span class="bold-text"><b>isJumpToken</b></span>
<span class="italic-text"><i>(</i></span>
<div class="paragraph">
<span class="paragraph"><img src="../images/horSpace24px.svg"/><span class="inline-text">const int8_t</span>
<span class="inline-text">type</span>
</span>
</div>
<span class="italic-text"><i>)</i></span>
<a id="references"></a>
<h4>References</h4>
<span class="icon-list-item"><a href="namespaceHack_1_1Assembler.md#tok_jgt" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">TOK_JGT</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Assembler.md#tok_jmp" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">TOK_JMP</span>
</a>
</span>
<br/>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/Assembler/Parser.cpp#L58" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Parser.cpp</span>
</a>
</span>
<br/>
<br/>
<a id="isoperatortoken"></a>
<h2>isOperatorToken</h2>
<span class="inline-text">bool</span>
<span class="bold-text"><b>isOperatorToken</b></span>
<span class="italic-text"><i>(</i></span>
<div class="paragraph">
<span class="paragraph"><img src="../images/horSpace24px.svg"/><span class="inline-text">const int8_t</span>
<span class="inline-text">type</span>
</span>
</div>
<span class="italic-text"><i>)</i></span>
<a id="references"></a>
<h4>References</h4>
<span class="icon-list-item"><a href="namespaceHack_1_1Assembler.md#tok_plus" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">TOK_PLUS</span>
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
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/Assembler/Parser.cpp#L52" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Parser.cpp</span>
</a>
</span>
<br/>
<br/>
<a id="testcompoundexpression"></a>
<h2>testCompoundExpression</h2>
<span class="inline-text">bool</span>
<span class="bold-text"><b>testCompoundExpression</b></span>
<span class="italic-text"><i>(</i></span>
<div class="paragraph">
<span class="paragraph"><img src="../images/horSpace24px.svg"/><span class="inline-text">const int8_t</span>
<span class="inline-text">a</span>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/horSpace24px.svg"/><span class="inline-text">const int8_t</span>
<span class="inline-text">b</span>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/horSpace24px.svg"/><span class="inline-text">const int8_t</span>
<span class="inline-text">c</span>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/horSpace24px.svg"/><span class="inline-text">const int8_t</span>
<span class="inline-text">d</span>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/horSpace24px.svg"/><span class="inline-text">const int8_t</span>
<span class="inline-text">e</span>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/horSpace24px.svg"/><span class="inline-text">const int8_t</span>
<span class="inline-text">f</span>
</span>
</div>
<span class="italic-text"><i>)</i></span>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/Assembler/Parser.cpp#L32" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Parser.cpp</span>
</a>
</span>
<br/>
<br/>
</div>
</div>
</body>
</html>
