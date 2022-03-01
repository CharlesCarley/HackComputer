<a id="parser"></a>
<h1>Parser</h1>
<a id="classhack_1_1assembler_1_1parser"></a>
<a href="https://github.com/CharlesCarley/HackComputer#~">~</a>
<a href="indexpage.md#hack">Hack</a>
<span class="inline-text">/</span>
<a href="index.md#index">Index</a>
<span class="inline-text">/</span>
<a href="namespaceHack.md#hack">Hack</a>
<span class="inline-text">::</span>
<a href="namespaceHack_1_1Assembler.md#assembler">Assembler</a>
<span class="inline-text">::</span>
<span class="bold-text"><b>Parser</b></span>
<br/>
<br/>
<a id="derived-from"></a>
<h4>Derived From</h4>
<div class="icon-link">
<img src="../images/class.svg"/><a href="classHack_1_1ParserBase.md#parserbase">Hack::ParserBase</a>
</div>
<img src="../images/dot/internal-diagram-1.dot.svg"/><br/>
<a id="public-typedefs"></a>
<h2>Public Typedefs</h2>
<span class="icon-list-item"><a href="#instructions" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">Instructions</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#labellookup" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">LabelLookup</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#labels" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">Labels</span>
</a>
</span>
<br/>
<a id="private-members"></a>
<h2>Private Members</h2>
<span class="icon-list-item"><a href="#_abit" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">_aBit</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#_cbits" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">_cBits</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#_dbits" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">_dBits</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#_instructions" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">_instructions</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#_jbits" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">_jBits</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#_labels" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">_labels</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#_resolution" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">_resolution</span>
</a>
</span>
<br/>
<a id="private-methods"></a>
<h2>Private Methods</h2>
<span class="icon-list-item"><a href="#assignmentexpression" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">assignmentExpression</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#compoundexpression" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">compoundExpression</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#compoundexpressionaone" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">compoundExpressionAOne</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#compoundexpressionazero" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">compoundExpressionAZero</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#expression" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">expression</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#expressiona" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">expressionA</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#expressionc" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">expressionC</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#identityexpression" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">identityExpression</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#label" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">label</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#parseimpl" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">parseImpl</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#pushcinstruction" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">pushCInstruction</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#resolvelabels" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">resolveLabels</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#writeimpl" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">writeImpl</span>
</a>
</span>
<br/>
<a id="public-methods"></a>
<h2>Public Methods</h2>
<span class="icon-list-item"><a href="#parser" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">Parser</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#~parser" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">~Parser</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#instructions" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">instructions</span>
</a>
</span>
<br/>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Assembler/Parser.h#L32" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Parser.h</span>
</a>
</span>
<br/>
<br/>
<blockquote>
<span class="icon-list-item"><a href="#parser" class="icon-list-item"><img src="../images/jumpToTop.svg" class="icon-list-item"/><span class="icon-list-item">top</span>
</a>
</span>
</blockquote>
<a id="instructions"></a>
<h2>Instructions</h2>
<span class="inline-text">std::vector&lt; </span>
<span class="bold-text"><b>uint16_t</b></span>
<span class="inline-text"> &gt;</span>
<span class="bold-text"><b>Instructions</b></span>
<br/>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Assembler/Parser.h#L34" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Parser.h</span>
</a>
</span>
<br/>
<br/>
<blockquote>
<span class="icon-list-item"><a href="#parser" class="icon-list-item"><img src="../images/jumpToTop.svg" class="icon-list-item"/><span class="icon-list-item">top</span>
</a>
</span>
</blockquote>
<br/>
<a id="labellookup"></a>
<h2>LabelLookup</h2>
<span class="inline-text">std::vector&lt; </span>
<a href="namespaceHack_1_1Assembler.md#stringindex">StringIndex</a>
<span class="inline-text"> &gt;</span>
<span class="bold-text"><b>LabelLookup</b></span>
<br/>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Assembler/Parser.h#L36" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Parser.h</span>
</a>
</span>
<br/>
<br/>
<blockquote>
<span class="icon-list-item"><a href="#parser" class="icon-list-item"><img src="../images/jumpToTop.svg" class="icon-list-item"/><span class="icon-list-item">top</span>
</a>
</span>
</blockquote>
<br/>
<a id="labels"></a>
<h2>Labels</h2>
<span class="inline-text">std::unordered_map&lt; </span>
<a href="namespaceHack.md#string">String</a>
<span class="inline-text">, size_t &gt;</span>
<span class="bold-text"><b>Labels</b></span>
<br/>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Assembler/Parser.h#L35" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Parser.h</span>
</a>
</span>
<br/>
<br/>
<blockquote>
<span class="icon-list-item"><a href="#parser" class="icon-list-item"><img src="../images/jumpToTop.svg" class="icon-list-item"/><span class="icon-list-item">top</span>
</a>
</span>
</blockquote>
<br/>
<a id="_abit"></a>
<h2>_aBit</h2>
<span class="bold-text"><b>uint8_t</b></span>
<span class="bold-text"><b>_aBit</b></span>
<br/>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Assembler/Parser.h#L43" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Parser.h</span>
</a>
</span>
<br/>
<br/>
<blockquote>
<span class="icon-list-item"><a href="#parser" class="icon-list-item"><img src="../images/jumpToTop.svg" class="icon-list-item"/><span class="icon-list-item">top</span>
</a>
</span>
</blockquote>
<br/>
<a id="_cbits"></a>
<h2>_cBits</h2>
<span class="bold-text"><b>uint16_t</b></span>
<span class="bold-text"><b>_cBits</b></span>
<br/>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Assembler/Parser.h#L41" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Parser.h</span>
</a>
</span>
<br/>
<br/>
<blockquote>
<span class="icon-list-item"><a href="#parser" class="icon-list-item"><img src="../images/jumpToTop.svg" class="icon-list-item"/><span class="icon-list-item">top</span>
</a>
</span>
</blockquote>
<br/>
<a id="_dbits"></a>
<h2>_dBits</h2>
<span class="bold-text"><b>uint8_t</b></span>
<span class="bold-text"><b>_dBits</b></span>
<br/>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Assembler/Parser.h#L42" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Parser.h</span>
</a>
</span>
<br/>
<br/>
<blockquote>
<span class="icon-list-item"><a href="#parser" class="icon-list-item"><img src="../images/jumpToTop.svg" class="icon-list-item"/><span class="icon-list-item">top</span>
</a>
</span>
</blockquote>
<br/>
<a id="_instructions"></a>
<h2>_instructions</h2>
<a href="classHack_1_1Assembler_1_1Parser.md#instructions">Instructions</a>
<span class="bold-text"><b>_instructions</b></span>
<br/>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Assembler/Parser.h#L39" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Parser.h</span>
</a>
</span>
<br/>
<br/>
<blockquote>
<span class="icon-list-item"><a href="#parser" class="icon-list-item"><img src="../images/jumpToTop.svg" class="icon-list-item"/><span class="icon-list-item">top</span>
</a>
</span>
</blockquote>
<br/>
<a id="_jbits"></a>
<h2>_jBits</h2>
<span class="bold-text"><b>uint8_t</b></span>
<span class="bold-text"><b>_jBits</b></span>
<br/>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Assembler/Parser.h#L44" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Parser.h</span>
</a>
</span>
<br/>
<br/>
<blockquote>
<span class="icon-list-item"><a href="#parser" class="icon-list-item"><img src="../images/jumpToTop.svg" class="icon-list-item"/><span class="icon-list-item">top</span>
</a>
</span>
</blockquote>
<br/>
<a id="_labels"></a>
<h2>_labels</h2>
<a href="classHack_1_1Assembler_1_1Parser.md#labels">Labels</a>
<span class="bold-text"><b>_labels</b></span>
<br/>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Assembler/Parser.h#L40" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Parser.h</span>
</a>
</span>
<br/>
<br/>
<blockquote>
<span class="icon-list-item"><a href="#parser" class="icon-list-item"><img src="../images/jumpToTop.svg" class="icon-list-item"/><span class="icon-list-item">top</span>
</a>
</span>
</blockquote>
<br/>
<a id="_resolution"></a>
<h2>_resolution</h2>
<a href="classHack_1_1Assembler_1_1Parser.md#labellookup">LabelLookup</a>
<span class="bold-text"><b>_resolution</b></span>
<br/>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Assembler/Parser.h#L45" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Parser.h</span>
</a>
</span>
<br/>
<br/>
<blockquote>
<span class="icon-list-item"><a href="#parser" class="icon-list-item"><img src="../images/jumpToTop.svg" class="icon-list-item"/><span class="icon-list-item">top</span>
</a>
</span>
</blockquote>
<br/>
<a id="assignmentexpression"></a>
<h2>assignmentExpression</h2>
<span class="inline-text">void</span>
<span class="bold-text"><b>assignmentExpression</b></span>
<span class="italic-text"><i>(</i></span>
<span class="italic-text"><i>)</i></span>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Assembler/Parser.h#L55" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Parser.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Assembler/Parser.cpp#L359" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Parser.cpp</span>
</a>
</span>
<br/>
<br/>
<blockquote>
<span class="icon-list-item"><a href="#parser" class="icon-list-item"><img src="../images/jumpToTop.svg" class="icon-list-item"/><span class="icon-list-item">top</span>
</a>
</span>
</blockquote>
<br/>
<a id="compoundexpression"></a>
<h2>compoundExpression</h2>
<span class="inline-text">void</span>
<span class="bold-text"><b>compoundExpression</b></span>
<span class="italic-text"><i>(</i></span>
<span class="italic-text"><i>)</i></span>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Assembler/Parser.h#L53" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Parser.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Assembler/Parser.cpp#L342" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Parser.cpp</span>
</a>
</span>
<br/>
<br/>
<blockquote>
<span class="icon-list-item"><a href="#parser" class="icon-list-item"><img src="../images/jumpToTop.svg" class="icon-list-item"/><span class="icon-list-item">top</span>
</a>
</span>
</blockquote>
<br/>
<a id="compoundexpressionaone"></a>
<h2>compoundExpressionAOne</h2>
<span class="inline-text">void</span>
<span class="bold-text"><b>compoundExpressionAOne</b></span>
<span class="italic-text"><i>(</i></span>
<span class="italic-text"><i>)</i></span>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Assembler/Parser.h#L51" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Parser.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Assembler/Parser.cpp#L271" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Parser.cpp</span>
</a>
</span>
<br/>
<br/>
<blockquote>
<span class="icon-list-item"><a href="#parser" class="icon-list-item"><img src="../images/jumpToTop.svg" class="icon-list-item"/><span class="icon-list-item">top</span>
</a>
</span>
</blockquote>
<br/>
<a id="compoundexpressionazero"></a>
<h2>compoundExpressionAZero</h2>
<span class="inline-text">void</span>
<span class="bold-text"><b>compoundExpressionAZero</b></span>
<span class="italic-text"><i>(</i></span>
<span class="italic-text"><i>)</i></span>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Assembler/Parser.h#L49" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Parser.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Assembler/Parser.cpp#L182" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Parser.cpp</span>
</a>
</span>
<br/>
<br/>
<blockquote>
<span class="icon-list-item"><a href="#parser" class="icon-list-item"><img src="../images/jumpToTop.svg" class="icon-list-item"/><span class="icon-list-item">top</span>
</a>
</span>
</blockquote>
<br/>
<a id="expression"></a>
<h2>expression</h2>
<span class="inline-text">void</span>
<span class="bold-text"><b>expression</b></span>
<span class="italic-text"><i>(</i></span>
<span class="italic-text"><i>)</i></span>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Assembler/Parser.h#L65" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Parser.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Assembler/Parser.cpp#L472" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Parser.cpp</span>
</a>
</span>
<br/>
<br/>
<blockquote>
<span class="icon-list-item"><a href="#parser" class="icon-list-item"><img src="../images/jumpToTop.svg" class="icon-list-item"/><span class="icon-list-item">top</span>
</a>
</span>
</blockquote>
<br/>
<a id="expressiona"></a>
<h2>expressionA</h2>
<span class="inline-text">void</span>
<span class="bold-text"><b>expressionA</b></span>
<span class="italic-text"><i>(</i></span>
<span class="italic-text"><i>)</i></span>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Assembler/Parser.h#L61" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Parser.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Assembler/Parser.cpp#L105" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Parser.cpp</span>
</a>
</span>
<br/>
<br/>
<blockquote>
<span class="icon-list-item"><a href="#parser" class="icon-list-item"><img src="../images/jumpToTop.svg" class="icon-list-item"/><span class="icon-list-item">top</span>
</a>
</span>
</blockquote>
<br/>
<a id="expressionc"></a>
<h2>expressionC</h2>
<span class="inline-text">void</span>
<span class="bold-text"><b>expressionC</b></span>
<span class="italic-text"><i>(</i></span>
<span class="italic-text"><i>)</i></span>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Assembler/Parser.h#L59" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Parser.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Assembler/Parser.cpp#L387" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Parser.cpp</span>
</a>
</span>
<br/>
<br/>
<blockquote>
<span class="icon-list-item"><a href="#parser" class="icon-list-item"><img src="../images/jumpToTop.svg" class="icon-list-item"/><span class="icon-list-item">top</span>
</a>
</span>
</blockquote>
<br/>
<a id="identityexpression"></a>
<h2>identityExpression</h2>
<span class="inline-text">void</span>
<span class="bold-text"><b>identityExpression</b></span>
<span class="italic-text"><i>(</i></span>
<span class="italic-text"><i>)</i></span>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Assembler/Parser.h#L57" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Parser.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Assembler/Parser.cpp#L154" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Parser.cpp</span>
</a>
</span>
<br/>
<br/>
<blockquote>
<span class="icon-list-item"><a href="#parser" class="icon-list-item"><img src="../images/jumpToTop.svg" class="icon-list-item"/><span class="icon-list-item">top</span>
</a>
</span>
</blockquote>
<br/>
<a id="label"></a>
<h2>label</h2>
<span class="inline-text">void</span>
<span class="bold-text"><b>label</b></span>
<span class="italic-text"><i>(</i></span>
<span class="italic-text"><i>)</i></span>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Assembler/Parser.h#L63" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Parser.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Assembler/Parser.cpp#L451" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Parser.cpp</span>
</a>
</span>
<br/>
<br/>
<blockquote>
<span class="icon-list-item"><a href="#parser" class="icon-list-item"><img src="../images/jumpToTop.svg" class="icon-list-item"/><span class="icon-list-item">top</span>
</a>
</span>
</blockquote>
<br/>
<a id="parseimpl"></a>
<h2>parseImpl</h2>
<span class="inline-text">void</span>
<span class="bold-text"><b>parseImpl</b></span>
<span class="italic-text"><i>(</i></span>
<div class="paragraph">
<span class="paragraph"><img src="../images/horSpace24px.svg"/><a href="namespaceHack.md#istream">IStream</a>
<span class="inline-text"> &amp;</span>
<span class="inline-text">is</span>
</span>
</div>
<span class="italic-text"><i>)</i></span>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Assembler/Parser.h#L69" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Parser.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Assembler/Parser.cpp#L491" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Parser.cpp</span>
</a>
</span>
<br/>
<br/>
<blockquote>
<span class="icon-list-item"><a href="#parser" class="icon-list-item"><img src="../images/jumpToTop.svg" class="icon-list-item"/><span class="icon-list-item">top</span>
</a>
</span>
</blockquote>
<br/>
<a id="pushcinstruction"></a>
<h2>pushCInstruction</h2>
<span class="inline-text">void</span>
<span class="bold-text"><b>pushCInstruction</b></span>
<span class="italic-text"><i>(</i></span>
<span class="italic-text"><i>)</i></span>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Assembler/Parser.h#L47" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Parser.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Assembler/Parser.cpp#L78" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Parser.cpp</span>
</a>
</span>
<br/>
<br/>
<blockquote>
<span class="icon-list-item"><a href="#parser" class="icon-list-item"><img src="../images/jumpToTop.svg" class="icon-list-item"/><span class="icon-list-item">top</span>
</a>
</span>
</blockquote>
<br/>
<a id="resolvelabels"></a>
<h2>resolveLabels</h2>
<span class="inline-text">void</span>
<span class="bold-text"><b>resolveLabels</b></span>
<span class="italic-text"><i>(</i></span>
<span class="italic-text"><i>)</i></span>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Assembler/Parser.h#L67" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Parser.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Assembler/Parser.cpp#L416" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Parser.cpp</span>
</a>
</span>
<br/>
<br/>
<blockquote>
<span class="icon-list-item"><a href="#parser" class="icon-list-item"><img src="../images/jumpToTop.svg" class="icon-list-item"/><span class="icon-list-item">top</span>
</a>
</span>
</blockquote>
<br/>
<a id="writeimpl"></a>
<h2>writeImpl</h2>
<span class="inline-text">void</span>
<span class="bold-text"><b>writeImpl</b></span>
<span class="italic-text"><i>(</i></span>
<div class="paragraph">
<span class="paragraph"><img src="../images/horSpace24px.svg"/><a href="namespaceHack.md#ostream">OStream</a>
<span class="inline-text"> &amp;</span>
<span class="inline-text">os</span>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/horSpace24px.svg"/><span class="inline-text">int</span>
<span class="inline-text">format</span>
<span class="inline-text"> = </span>
<span class="inline-text">0</span>
</span>
</div>
<span class="italic-text"><i>)</i></span>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Assembler/Parser.h#L71" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Parser.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Assembler/Parser.cpp#L517" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Parser.cpp</span>
</a>
</span>
<br/>
<br/>
<blockquote>
<span class="icon-list-item"><a href="#parser" class="icon-list-item"><img src="../images/jumpToTop.svg" class="icon-list-item"/><span class="icon-list-item">top</span>
</a>
</span>
</blockquote>
<br/>
<a id="parser"></a>
<h2>Parser</h2>
<span class="bold-text"><b>Parser</b></span>
<span class="italic-text"><i>(</i></span>
<span class="italic-text"><i>)</i></span>
<a id="references"></a>
<h4>References</h4>
<div class="paragraph">
<span class="paragraph"><img src="../images/class.svg"/><a href="classHack_1_1ParserBase.md#_scanner">_scanner</a>
</span>
</div>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Assembler/Parser.h#L74" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Parser.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Assembler/Parser.cpp#L63" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Parser.cpp</span>
</a>
</span>
<br/>
<br/>
<blockquote>
<span class="icon-list-item"><a href="#parser" class="icon-list-item"><img src="../images/jumpToTop.svg" class="icon-list-item"/><span class="icon-list-item">top</span>
</a>
</span>
</blockquote>
<br/>
<a id="~parser"></a>
<h2>~Parser</h2>
<span class="bold-text"><b>~Parser</b></span>
<span class="italic-text"><i>(</i></span>
<span class="italic-text"><i>)</i></span>
<a id="references"></a>
<h4>References</h4>
<div class="paragraph">
<span class="paragraph"><img src="../images/class.svg"/><a href="classHack_1_1ParserBase.md#_scanner">_scanner</a>
</span>
</div>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Assembler/Parser.h#L75" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Parser.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Assembler/Parser.cpp#L72" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Parser.cpp</span>
</a>
</span>
<br/>
<br/>
<blockquote>
<span class="icon-list-item"><a href="#parser" class="icon-list-item"><img src="../images/jumpToTop.svg" class="icon-list-item"/><span class="icon-list-item">top</span>
</a>
</span>
</blockquote>
<br/>
<a id="instructions"></a>
<h2>instructions</h2>
<span class="inline-text">const </span>
<a href="classHack_1_1Assembler_1_1Parser.md#instructions">Instructions</a>
<span class="inline-text"> &amp;</span>
<span class="bold-text"><b>instructions</b></span>
<span class="italic-text"><i>(</i></span>
<span class="italic-text"><i>)</i></span>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Assembler/Parser.h#L77" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Parser.h</span>
</a>
</span>
<br/>
<br/>
<blockquote>
<span class="icon-list-item"><a href="#parser" class="icon-list-item"><img src="../images/jumpToTop.svg" class="icon-list-item"/><span class="icon-list-item">top</span>
</a>
</span>
</blockquote>
<br/>
</div>
</div>
</body>
</html>
