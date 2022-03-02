<a id="assembler"></a>
<h1>Assembler</h1>
<a id="namespacehack_1_1assembler"></a>
<a href="https://github.com/CharlesCarley/HackComputer#~">~</a>
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
<div class="icon-link">
<img src="../images/class.svg"/><a href="classHack_1_1Assembler_1_1Instruction.md#instruction">Instruction</a>
</div>
<div class="icon-link">
<img src="../images/class.svg"/><a href="structHack_1_1Assembler_1_1KeywordTable.md#keywordtable">KeywordTable</a>
</div>
<div class="icon-link">
<img src="../images/class.svg"/><a href="classHack_1_1Assembler_1_1Parser.md#parser">Parser</a>
</div>
<div class="icon-link">
<img src="../images/class.svg"/><a href="structHack_1_1Assembler_1_1ReservedWordTable.md#reservedwordtable">ReservedWordTable</a>
</div>
<div class="icon-link">
<img src="../images/class.svg"/><a href="classHack_1_1Assembler_1_1Scanner.md#scanner">Scanner</a>
</div>
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
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Assembler/Instruction.cpp#L26" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Instruction.cpp</span>
</a>
</span>
<br/>
<br/>
<blockquote>
<span class="icon-list-item"><a href="#assembler" class="icon-list-item"><img src="../images/jumpToTop.svg" class="icon-list-item"/><span class="icon-list-item">top</span>
</a>
</span>
</blockquote>
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
<a id="tok_d_start"></a>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">TOK_D_START</span>
</span>
</div>
<a id="tok_m"></a>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">TOK_M</span>
</span>
</div>
<a id="tok_d"></a>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">TOK_D</span>
</span>
</div>
<a id="tok_md"></a>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">TOK_MD</span>
</span>
</div>
<a id="tok_a"></a>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">TOK_A</span>
</span>
</div>
<a id="tok_am"></a>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">TOK_AM</span>
</span>
</div>
<a id="tok_ad"></a>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">TOK_AD</span>
</span>
</div>
<a id="tok_amd"></a>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">TOK_AMD</span>
</span>
</div>
<a id="tok_j_start"></a>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">TOK_J_START</span>
</span>
</div>
<a id="tok_jgt"></a>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">TOK_JGT</span>
</span>
</div>
<a id="tok_jeq"></a>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">TOK_JEQ</span>
</span>
</div>
<a id="tok_jge"></a>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">TOK_JGE</span>
</span>
</div>
<a id="tok_jlt"></a>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">TOK_JLT</span>
</span>
</div>
<a id="tok_jne"></a>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">TOK_JNE</span>
</span>
</div>
<a id="tok_jle"></a>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">TOK_JLE</span>
</span>
</div>
<a id="tok_jmp"></a>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">TOK_JMP</span>
</span>
</div>
<a id="tok_zero"></a>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">TOK_ZERO</span>
</span>
</div>
<a id="tok_minus"></a>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">TOK_MINUS</span>
</span>
</div>
<a id="tok_not"></a>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">TOK_NOT</span>
</span>
</div>
<a id="tok_plus"></a>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">TOK_PLUS</span>
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
<a id="tok_at"></a>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">TOK_AT</span>
</span>
</div>
<a id="tok_semi_colon"></a>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">TOK_SEMI_COLON</span>
</span>
</div>
<a id="tok_equal"></a>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">TOK_EQUAL</span>
</span>
</div>
<a id="tok_l_paren"></a>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">TOK_L_PAREN</span>
</span>
</div>
<a id="tok_r_paren"></a>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">TOK_R_PAREN</span>
</span>
</div>
<a id="tok_comma"></a>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">TOK_COMMA</span>
</span>
</div>
<a id="tok_one"></a>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">TOK_ONE</span>
</span>
</div>
<a id="tok_integer"></a>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">TOK_INTEGER</span>
</span>
</div>
<a id="tok_label"></a>
<div class="paragraph">
<span class="paragraph"><img src="../images/enum.svg"/><span class="inline-text">TOK_LABEL</span>
</span>
</div>
<a id="tok_error"></a>
<a id="tok_eof"></a>
<a id="tok_null"></a>
<a id="tok_d_start"></a>
<a id="tok_m"></a>
<a id="tok_d"></a>
<a id="tok_md"></a>
<a id="tok_a"></a>
<a id="tok_am"></a>
<a id="tok_ad"></a>
<a id="tok_amd"></a>
<a id="tok_j_start"></a>
<a id="tok_jgt"></a>
<a id="tok_jeq"></a>
<a id="tok_jge"></a>
<a id="tok_jlt"></a>
<a id="tok_jne"></a>
<a id="tok_jle"></a>
<a id="tok_jmp"></a>
<a id="tok_zero"></a>
<a id="tok_minus"></a>
<a id="tok_not"></a>
<a id="tok_plus"></a>
<a id="tok_and"></a>
<a id="tok_or"></a>
<a id="tok_at"></a>
<a id="tok_semi_colon"></a>
<a id="tok_equal"></a>
<a id="tok_l_paren"></a>
<a id="tok_r_paren"></a>
<a id="tok_comma"></a>
<a id="tok_one"></a>
<a id="tok_integer"></a>
<a id="tok_label"></a>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Assembler/Token.h#L28" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Token.h</span>
</a>
</span>
<br/>
<br/>
<blockquote>
<span class="icon-list-item"><a href="#assembler" class="icon-list-item"><img src="../images/jumpToTop.svg" class="icon-list-item"/><span class="icon-list-item">top</span>
</a>
</span>
</blockquote>
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
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Assembler/Parser.h#L29" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Parser.h</span>
</a>
</span>
<br/>
<br/>
<blockquote>
<span class="icon-list-item"><a href="#assembler" class="icon-list-item"><img src="../images/jumpToTop.svg" class="icon-list-item"/><span class="icon-list-item">top</span>
</a>
</span>
</blockquote>
<br/>
<a id="token"></a>
<h2>Token</h2>
<a href="classHack_1_1TokenBase.md#tokenbase">TokenBase</a>
<span class="bold-text"><b>Token</b></span>
<br/>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Assembler/Token.h#L68" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Token.h</span>
</a>
</span>
<br/>
<br/>
<blockquote>
<span class="icon-list-item"><a href="#assembler" class="icon-list-item"><img src="../images/jumpToTop.svg" class="icon-list-item"/><span class="icon-list-item">top</span>
</a>
</span>
</blockquote>
<br/>
<a id="destandjumptable"></a>
<h2>DestAndJumpTable</h2>
<span class="inline-text">constexpr </span>
<a href="structHack_1_1Assembler_1_1KeywordTable.md#keywordtable">KeywordTable</a>
<span class="bold-text"><b>DestAndJumpTable</b></span>
<br/>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Assembler/Scanner.cpp#L42" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Scanner.cpp</span>
</a>
</span>
<br/>
<br/>
<blockquote>
<span class="icon-list-item"><a href="#assembler" class="icon-list-item"><img src="../images/jumpToTop.svg" class="icon-list-item"/><span class="icon-list-item">top</span>
</a>
</span>
</blockquote>
<br/>
<a id="reservedaddresses"></a>
<h2>ReservedAddresses</h2>
<span class="inline-text">constexpr </span>
<a href="structHack_1_1Assembler_1_1ReservedWordTable.md#reservedwordtable">ReservedWordTable</a>
<span class="bold-text"><b>ReservedAddresses</b></span>
<br/>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Assembler/Scanner.cpp#L57" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Scanner.cpp</span>
</a>
</span>
<br/>
<br/>
<blockquote>
<span class="icon-list-item"><a href="#assembler" class="icon-list-item"><img src="../images/jumpToTop.svg" class="icon-list-item"/><span class="icon-list-item">top</span>
</a>
</span>
</blockquote>
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
<div class="paragraph">
<span class="paragraph"><img src="../images/class.svg"/><a href="namespaceHack_1_1Assembler.md#tok_zero">TOK_ZERO</a>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/class.svg"/><a href="namespaceHack_1_1Assembler.md#tok_one">TOK_ONE</a>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/class.svg"/><a href="namespaceHack_1_1Assembler.md#tok_integer">TOK_INTEGER</a>
</span>
</div>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Assembler/Parser.cpp#L47" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Parser.cpp</span>
</a>
</span>
<br/>
<br/>
<blockquote>
<span class="icon-list-item"><a href="#assembler" class="icon-list-item"><img src="../images/jumpToTop.svg" class="icon-list-item"/><span class="icon-list-item">top</span>
</a>
</span>
</blockquote>
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
<div class="paragraph">
<span class="paragraph"><img src="../images/class.svg"/><a href="namespaceHack_1_1Assembler.md#tok_m">TOK_M</a>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/class.svg"/><a href="namespaceHack_1_1Assembler.md#tok_amd">TOK_AMD</a>
</span>
</div>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Assembler/Parser.cpp#L42" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Parser.cpp</span>
</a>
</span>
<br/>
<br/>
<blockquote>
<span class="icon-list-item"><a href="#assembler" class="icon-list-item"><img src="../images/jumpToTop.svg" class="icon-list-item"/><span class="icon-list-item">top</span>
</a>
</span>
</blockquote>
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
<div class="paragraph">
<span class="paragraph"><img src="../images/class.svg"/><a href="namespaceHack_1_1Assembler.md#tok_jgt">TOK_JGT</a>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/class.svg"/><a href="namespaceHack_1_1Assembler.md#tok_jmp">TOK_JMP</a>
</span>
</div>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Assembler/Parser.cpp#L58" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Parser.cpp</span>
</a>
</span>
<br/>
<br/>
<blockquote>
<span class="icon-list-item"><a href="#assembler" class="icon-list-item"><img src="../images/jumpToTop.svg" class="icon-list-item"/><span class="icon-list-item">top</span>
</a>
</span>
</blockquote>
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
<div class="paragraph">
<span class="paragraph"><img src="../images/class.svg"/><a href="namespaceHack_1_1Assembler.md#tok_plus">TOK_PLUS</a>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/class.svg"/><a href="namespaceHack_1_1Assembler.md#tok_minus">TOK_MINUS</a>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/class.svg"/><a href="namespaceHack_1_1Assembler.md#tok_and">TOK_AND</a>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/class.svg"/><a href="namespaceHack_1_1Assembler.md#tok_or">TOK_OR</a>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/class.svg"/><a href="namespaceHack_1_1Assembler.md#tok_not">TOK_NOT</a>
</span>
</div>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Assembler/Parser.cpp#L52" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Parser.cpp</span>
</a>
</span>
<br/>
<br/>
<blockquote>
<span class="icon-list-item"><a href="#assembler" class="icon-list-item"><img src="../images/jumpToTop.svg" class="icon-list-item"/><span class="icon-list-item">top</span>
</a>
</span>
</blockquote>
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
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Assembler/Parser.cpp#L32" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Parser.cpp</span>
</a>
</span>
<br/>
<br/>
<blockquote>
<span class="icon-list-item"><a href="#assembler" class="icon-list-item"><img src="../images/jumpToTop.svg" class="icon-list-item"/><span class="icon-list-item">top</span>
</a>
</span>
</blockquote>
<br/>
<br/>
<blockquote>
<img src="../images/debug.svg"/><span class="inline-text">The following sources were used to generate this page.</span>
<br/>
<span class="icon-list-item"><a href="../xml/namespaceHack_1_1Assembler.xml#L1" class="icon-list-item"><img src="../images/lookInside.svg" class="icon-list-item"/><span class="icon-list-item">namespaceHack_1_1Assembler.xml</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="../xml/compound.xsd#L1" class="icon-list-item"><img src="../images/lookInside.svg" class="icon-list-item"/><span class="icon-list-item">compound.xsd</span>
</a>
</span>
</blockquote>
</div>
</div>
</body>
</html>
