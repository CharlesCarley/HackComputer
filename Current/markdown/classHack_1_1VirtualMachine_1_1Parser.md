<a id="parser"></a>
<h1>Parser</h1>
<a id="classHack_1_1VirtualMachine_1_1Parser"></a>
<a href="https://github.com/CharlesCarley/HackComputer.md">~</a>
<a href="indexpage.md#hack">Hack</a>
<span class="inline-text">/</span>
<a href="index.md#index">Index</a>
<span class="inline-text">/</span>
<a href="namespaceHack.md#hack">Hack</a>
<span class="inline-text">::</span>
<a href="namespaceHack_1_1VirtualMachine.md#virtualmachine">VirtualMachine</a>
<span class="inline-text">::</span>
<span class="bold-text"><b>Parser</b></span>
<br/>
<br/>
<a id="derived-from"></a>
<h4>Derived From</h4>
<div class="icon-link">
<img src="../images/class.svg"/><a href="classHack_1_1ParserBase.md#hackparserbase">Hack::ParserBase</a>
</div>
<img src="../images/dot/internal-diagram-51.dot.svg"/><br/>
<a id="private-members"></a>
<h2>Private Members</h2>
<span class="icon-list-item"><a href="#_emitter" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">_emitter</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#_labels" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">_labels</span>
</a>
</span>
<br/>
<a id="private-methods"></a>
<h2>Private Methods</h2>
<span class="icon-list-item"><a href="#callexpression" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">callExpression</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#expression" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">expression</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#functionexpression" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">functionExpression</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#gotoexpression" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">gotoExpression</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#labelexpression" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">labelExpression</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#parseimpl" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">parseImpl</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#popexpression" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">popExpression</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#pushexpression" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">pushExpression</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#setexpression" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">setExpression</span>
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
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/VirtualMachine/Parser.h#L33" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Parser.h</span>
</a>
</span>
<br/>
<a id="_emitter"></a>
<h2>_emitter</h2>
<a href="classHack_1_1VirtualMachine_1_1Emitter.md#emitter">Emitter</a>
<span class="bold-text"><b>_emitter</b></span>
<br/>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/VirtualMachine/Parser.h#L35" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Parser.h</span>
</a>
</span>
<br/>
<br/>
<a id="_labels"></a>
<h2>_labels</h2>
<a href="namespaceHack_1_1VirtualMachine.md#stringcache">StringCache</a>
<span class="bold-text"><b>_labels</b></span>
<br/>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/VirtualMachine/Parser.h#L36" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Parser.h</span>
</a>
</span>
<br/>
<br/>
<a id="callexpression"></a>
<h2>callExpression</h2>
<span class="inline-text">void</span>
<span class="bold-text"><b>callExpression</b></span>
<span class="italic-text"><i>(</i></span>
<span class="italic-text"><i>)</i></span>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/VirtualMachine/Parser.h#L55" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Parser.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/VirtualMachine/Parser.cpp#L217" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Parser.cpp</span>
</a>
</span>
<br/>
<br/>
<a id="expression"></a>
<h2>expression</h2>
<span class="inline-text">void</span>
<span class="bold-text"><b>expression</b></span>
<span class="italic-text"><i>(</i></span>
<span class="italic-text"><i>)</i></span>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/VirtualMachine/Parser.h#L43" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Parser.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/VirtualMachine/Parser.cpp#L274" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Parser.cpp</span>
</a>
</span>
<br/>
<br/>
<a id="functionexpression"></a>
<h2>functionExpression</h2>
<span class="inline-text">void</span>
<span class="bold-text"><b>functionExpression</b></span>
<span class="italic-text"><i>(</i></span>
<span class="italic-text"><i>)</i></span>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/VirtualMachine/Parser.h#L53" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Parser.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/VirtualMachine/Parser.cpp#L187" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Parser.cpp</span>
</a>
</span>
<br/>
<br/>
<a id="gotoexpression"></a>
<h2>gotoExpression</h2>
<span class="inline-text">void</span>
<span class="bold-text"><b>gotoExpression</b></span>
<span class="italic-text"><i>(</i></span>
<span class="italic-text"><i>)</i></span>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/VirtualMachine/Parser.h#L49" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Parser.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/VirtualMachine/Parser.cpp#L161" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Parser.cpp</span>
</a>
</span>
<br/>
<br/>
<a id="labelexpression"></a>
<h2>labelExpression</h2>
<span class="inline-text">void</span>
<span class="bold-text"><b>labelExpression</b></span>
<span class="italic-text"><i>(</i></span>
<span class="italic-text"><i>)</i></span>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/VirtualMachine/Parser.h#L51" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Parser.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/VirtualMachine/Parser.cpp#L139" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Parser.cpp</span>
</a>
</span>
<br/>
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
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/VirtualMachine/Parser.h#L39" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Parser.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/VirtualMachine/Parser.cpp#L372" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Parser.cpp</span>
</a>
</span>
<br/>
<br/>
<a id="popexpression"></a>
<h2>popExpression</h2>
<span class="inline-text">void</span>
<span class="bold-text"><b>popExpression</b></span>
<span class="italic-text"><i>(</i></span>
<span class="italic-text"><i>)</i></span>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/VirtualMachine/Parser.h#L47" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Parser.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/VirtualMachine/Parser.cpp#L91" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Parser.cpp</span>
</a>
</span>
<br/>
<br/>
<a id="pushexpression"></a>
<h2>pushExpression</h2>
<span class="inline-text">void</span>
<span class="bold-text"><b>pushExpression</b></span>
<span class="italic-text"><i>(</i></span>
<span class="italic-text"><i>)</i></span>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/VirtualMachine/Parser.h#L45" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Parser.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/VirtualMachine/Parser.cpp#L41" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Parser.cpp</span>
</a>
</span>
<br/>
<br/>
<a id="setexpression"></a>
<h2>setExpression</h2>
<span class="inline-text">void</span>
<span class="bold-text"><b>setExpression</b></span>
<span class="italic-text"><i>(</i></span>
<span class="italic-text"><i>)</i></span>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/VirtualMachine/Parser.h#L57" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Parser.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/VirtualMachine/Parser.cpp#L247" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Parser.cpp</span>
</a>
</span>
<br/>
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
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/VirtualMachine/Parser.h#L41" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Parser.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/VirtualMachine/Parser.cpp#L399" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Parser.cpp</span>
</a>
</span>
<br/>
<br/>
<a id="parser"></a>
<h2>Parser</h2>
<span class="bold-text"><b>Parser</b></span>
<span class="italic-text"><i>(</i></span>
<span class="italic-text"><i>)</i></span>
<a id="references"></a>
<h4>References</h4>
<span class="icon-list-item"><a href="classHack_1_1ParserBase.md#_scanner" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">_scanner</span>
</a>
</span>
<br/>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/VirtualMachine/Parser.h#L60" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Parser.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/VirtualMachine/Parser.cpp#L30" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Parser.cpp</span>
</a>
</span>
<br/>
<br/>
<a id="~parser"></a>
<h2>~Parser</h2>
<span class="bold-text"><b>~Parser</b></span>
<span class="italic-text"><i>(</i></span>
<span class="italic-text"><i>)</i></span>
<a id="references"></a>
<h4>References</h4>
<span class="icon-list-item"><a href="classHack_1_1ParserBase.md#_scanner" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">_scanner</span>
</a>
</span>
<br/>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/VirtualMachine/Parser.h#L62" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Parser.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/VirtualMachine/Parser.cpp#L35" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Parser.cpp</span>
</a>
</span>
<br/>
<br/>
</div>
</div>
</body>
</html>
