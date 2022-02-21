<a id="emitter"></a>
<h1>Emitter</h1>
<a id="classHack_1_1VirtualMachine_1_1Emitter"></a>
<a href="https://github.com/CharlesCarley/HackComputer.md">~</a>
<a href="indexpage.md#hack">Hack</a>
<span class="inline-text">/</span>
<a href="index.md#index">Index</a>
<span class="inline-text">/</span>
<a href="namespaceHack.md#hack">Hack</a>
<span class="inline-text">::</span>
<a href="namespaceHack_1_1VirtualMachine.md#virtualmachine">VirtualMachine</a>
<span class="inline-text">::</span>
<span class="bold-text"><b>Emitter</b></span>
<br/>
<br/>
<a id="public-typedefs"></a>
<h2>Public Typedefs</h2>
<span class="icon-list-item"><a href="#stringstack" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">StringStack</span>
</a>
</span>
<br/>
<a id="private-members"></a>
<h2>Private Members</h2>
<span class="icon-list-item"><a href="#_cmp" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">_cmp</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#_functions" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">_functions</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#_stream" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">_stream</span>
</a>
</span>
<br/>
<a id="private-methods"></a>
<h2>Private Methods</h2>
<span class="icon-list-item"><a href="#genlabel" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">genLabel</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#getjumplabels" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">getJumpLabels</span>
</a>
</span>
<br/>
<a id="public-methods"></a>
<h2>Public Methods</h2>
<span class="icon-list-item"><a href="#emitter" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">Emitter</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#clear" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">clear</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#popargument" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">popArgument</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#poplocal" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">popLocal</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#poppointer" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">popPointer</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#popstatic" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">popStatic</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#poptemp" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">popTemp</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#popthat" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">popThat</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#popthis" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">popThis</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#pushargument" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">pushArgument</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#pushconstant" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">pushConstant</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#pushlocal" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">pushLocal</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#pushpointer" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">pushPointer</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#pushstatic" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">pushStatic</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#pushtemp" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">pushTemp</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#pushthat" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">pushThat</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#pushthis" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">pushThis</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#setram" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">setRam</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#stream" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">stream</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#writeadd" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">writeAdd</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#writeand" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">writeAnd</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#writecall" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">writeCall</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#writecode" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">writeCode</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#writeeq" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">writeEq</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#writefunction" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">writeFunction</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#writegt" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">writeGt</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#writehalt" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">writeHalt</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#writelabel" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">writeLabel</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#writelt" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">writeLt</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#writeneg" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">writeNeg</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#writenot" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">writeNot</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#writeor" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">writeOr</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#writereset" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">writeReset</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#writereturn" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">writeReturn</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#writesub" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">writeSub</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#writgoto" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">writGoto</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#writifgoto" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">writIfGoto</span>
</a>
</span>
<br/>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/VirtualMachine/Emitter.h#L32" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Emitter.h</span>
</a>
</span>
<br/>
<a id="stringstack"></a>
<h2>StringStack</h2>
<span class="inline-text">std::stack&lt; </span>
<a href="namespaceHack.md#string">String</a>
<span class="inline-text"> &gt;</span>
<span class="bold-text"><b>StringStack</b></span>
<br/>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/VirtualMachine/Emitter.h#L34" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Emitter.h</span>
</a>
</span>
<br/>
<br/>
<a id="_cmp"></a>
<h2>_cmp</h2>
<span class="inline-text">int</span>
<span class="bold-text"><b>_cmp</b></span>
<br/>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/VirtualMachine/Emitter.h#L38" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Emitter.h</span>
</a>
</span>
<br/>
<br/>
<a id="_functions"></a>
<h2>_functions</h2>
<a href="classHack_1_1VirtualMachine_1_1Emitter.md#stringstack">StringStack</a>
<span class="bold-text"><b>_functions</b></span>
<br/>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/VirtualMachine/Emitter.h#L39" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Emitter.h</span>
</a>
</span>
<br/>
<br/>
<a id="_stream"></a>
<h2>_stream</h2>
<a href="namespaceHack.md#outputstringstream">OutputStringStream</a>
<span class="bold-text"><b>_stream</b></span>
<br/>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/VirtualMachine/Emitter.h#L37" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Emitter.h</span>
</a>
</span>
<br/>
<br/>
<a id="genlabel"></a>
<h2>genLabel</h2>
<span class="inline-text">void</span>
<span class="bold-text"><b>genLabel</b></span>
<span class="italic-text"><i>(</i></span>
<div class="paragraph">
<span class="paragraph"><img src="../images/horSpace24px.svg"/><a href="namespaceHack.md#string">String</a>
<span class="inline-text"> &amp;</span>
<span class="inline-text">val</span>
</span>
</div>
<span class="italic-text"><i>)</i></span>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/VirtualMachine/Emitter.h#L44" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Emitter.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/VirtualMachine/Emitter.cpp#L406" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Emitter.cpp</span>
</a>
</span>
<br/>
<br/>
<a id="getjumplabels"></a>
<h2>getJumpLabels</h2>
<span class="inline-text">void</span>
<span class="bold-text"><b>getJumpLabels</b></span>
<span class="italic-text"><i>(</i></span>
<div class="paragraph">
<span class="paragraph"><img src="../images/horSpace24px.svg"/><a href="namespaceHack.md#string">String</a>
<span class="inline-text"> &amp;</span>
<span class="inline-text">valTrue</span>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/horSpace24px.svg"/><a href="namespaceHack.md#string">String</a>
<span class="inline-text"> &amp;</span>
<span class="inline-text">valDone</span>
</span>
</div>
<span class="italic-text"><i>)</i></span>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/VirtualMachine/Emitter.h#L42" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Emitter.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/VirtualMachine/Emitter.cpp#L398" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Emitter.cpp</span>
</a>
</span>
<br/>
<br/>
<a id="emitter"></a>
<h2>Emitter</h2>
<span class="bold-text"><b>Emitter</b></span>
<span class="italic-text"><i>(</i></span>
<span class="italic-text"><i>)</i></span>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/VirtualMachine/Emitter.h#L47" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Emitter.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/VirtualMachine/Emitter.cpp#L388" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Emitter.cpp</span>
</a>
</span>
<br/>
<br/>
<a id="clear"></a>
<h2>clear</h2>
<span class="inline-text">void</span>
<span class="bold-text"><b>clear</b></span>
<span class="italic-text"><i>(</i></span>
<span class="italic-text"><i>)</i></span>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/VirtualMachine/Emitter.h#L49" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Emitter.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/VirtualMachine/Emitter.cpp#L393" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Emitter.cpp</span>
</a>
</span>
<br/>
<br/>
<a id="popargument"></a>
<h2>popArgument</h2>
<span class="inline-text">void</span>
<span class="bold-text"><b>popArgument</b></span>
<span class="italic-text"><i>(</i></span>
<div class="paragraph">
<span class="paragraph"><img src="../images/horSpace24px.svg"/><span class="inline-text">const size_t &amp;</span>
<span class="inline-text">idx</span>
</span>
</div>
<span class="italic-text"><i>)</i></span>
<a id="references"></a>
<h4>References</h4>
<span class="icon-list-item"><a href="classHack_1_1VirtualMachine_1_1CodeStream.md#popsegment" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">popSegment</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1VirtualMachine.md#arg" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">ARG</span>
</a>
</span>
<br/>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/VirtualMachine/Emitter.h#L84" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Emitter.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/VirtualMachine/Emitter.cpp#L555" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Emitter.cpp</span>
</a>
</span>
<br/>
<br/>
<a id="poplocal"></a>
<h2>popLocal</h2>
<span class="inline-text">void</span>
<span class="bold-text"><b>popLocal</b></span>
<span class="italic-text"><i>(</i></span>
<div class="paragraph">
<span class="paragraph"><img src="../images/horSpace24px.svg"/><span class="inline-text">const size_t &amp;</span>
<span class="inline-text">idx</span>
</span>
</div>
<span class="italic-text"><i>)</i></span>
<a id="references"></a>
<h4>References</h4>
<span class="icon-list-item"><a href="classHack_1_1VirtualMachine_1_1CodeStream.md#popsegment" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">popSegment</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1VirtualMachine.md#lcl" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">LCL</span>
</a>
</span>
<br/>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/VirtualMachine/Emitter.h#L74" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Emitter.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/VirtualMachine/Emitter.cpp#L549" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Emitter.cpp</span>
</a>
</span>
<br/>
<br/>
<a id="poppointer"></a>
<h2>popPointer</h2>
<span class="inline-text">void</span>
<span class="bold-text"><b>popPointer</b></span>
<span class="italic-text"><i>(</i></span>
<div class="paragraph">
<span class="paragraph"><img src="../images/horSpace24px.svg"/><span class="inline-text">const size_t &amp;</span>
<span class="inline-text">idx</span>
</span>
</div>
<span class="italic-text"><i>)</i></span>
<a id="references"></a>
<h4>References</h4>
<span class="icon-list-item"><a href="classHack_1_1VirtualMachine_1_1CodeStream.md#jumpstacktop" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">jumpStackTop</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="classHack_1_1VirtualMachine_1_1CodeStream.md#movemintod" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">moveMIntoD</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="classHack_1_1VirtualMachine_1_1CodeStream.md#movedintox" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">moveDIntoX</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1VirtualMachine.md#ths" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">THS</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1VirtualMachine.md#tht" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">THT</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="classHack_1_1VirtualMachine_1_1CodeStream.md#decrement" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">decrement</span>
</a>
</span>
<br/>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/VirtualMachine/Emitter.h#L82" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Emitter.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/VirtualMachine/Emitter.cpp#L608" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Emitter.cpp</span>
</a>
</span>
<br/>
<br/>
<a id="popstatic"></a>
<h2>popStatic</h2>
<span class="inline-text">void</span>
<span class="bold-text"><b>popStatic</b></span>
<span class="italic-text"><i>(</i></span>
<div class="paragraph">
<span class="paragraph"><img src="../images/horSpace24px.svg"/><span class="inline-text">const </span>
<a href="namespaceHack.md#string">String</a>
<span class="inline-text"> &amp;</span>
<span class="inline-text">context</span>
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
<span class="icon-list-item"><a href="namespaceHack.md#stringcombine" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">StringCombine</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="classHack_1_1VirtualMachine_1_1CodeStream.md#jumpstacktop" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">jumpStackTop</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="classHack_1_1VirtualMachine_1_1CodeStream.md#movemintod" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">moveMIntoD</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="classHack_1_1VirtualMachine_1_1CodeStream.md#movedintox" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">moveDIntoX</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="classHack_1_1VirtualMachine_1_1CodeStream.md#decrement" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">decrement</span>
</a>
</span>
<br/>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/VirtualMachine/Emitter.h#L86" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Emitter.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/VirtualMachine/Emitter.cpp#L561" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Emitter.cpp</span>
</a>
</span>
<br/>
<br/>
<a id="poptemp"></a>
<h2>popTemp</h2>
<span class="inline-text">void</span>
<span class="bold-text"><b>popTemp</b></span>
<span class="italic-text"><i>(</i></span>
<div class="paragraph">
<span class="paragraph"><img src="../images/horSpace24px.svg"/><span class="inline-text">const size_t &amp;</span>
<span class="inline-text">idx</span>
</span>
</div>
<span class="italic-text"><i>)</i></span>
<a id="references"></a>
<h4>References</h4>
<span class="icon-list-item"><a href="classHack_1_1VirtualMachine_1_1CodeStream.md#offsetto" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">offsetTo</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1VirtualMachine.md#tmp" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">TMP</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="classHack_1_1VirtualMachine_1_1CodeStream.md#movedintox" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">moveDIntoX</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1VirtualMachine.md#sw0" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">SW0</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="classHack_1_1VirtualMachine_1_1CodeStream.md#jumpstacktop" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">jumpStackTop</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="classHack_1_1VirtualMachine_1_1CodeStream.md#movemintod" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">moveMIntoD</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="classHack_1_1VirtualMachine_1_1CodeStream.md#jumptoaddressin" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">jumpToAddressIn</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="classHack_1_1VirtualMachine_1_1CodeStream.md#movedintom" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">moveDIntoM</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="classHack_1_1VirtualMachine_1_1CodeStream.md#decrement" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">decrement</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="classHack_1_1VirtualMachine_1_1CodeStream.md#move" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">move</span>
</a>
</span>
<br/>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/VirtualMachine/Emitter.h#L80" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Emitter.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/VirtualMachine/Emitter.cpp#L585" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Emitter.cpp</span>
</a>
</span>
<br/>
<br/>
<a id="popthat"></a>
<h2>popThat</h2>
<span class="inline-text">void</span>
<span class="bold-text"><b>popThat</b></span>
<span class="italic-text"><i>(</i></span>
<div class="paragraph">
<span class="paragraph"><img src="../images/horSpace24px.svg"/><span class="inline-text">const size_t &amp;</span>
<span class="inline-text">idx</span>
</span>
</div>
<span class="italic-text"><i>)</i></span>
<a id="references"></a>
<h4>References</h4>
<span class="icon-list-item"><a href="classHack_1_1VirtualMachine_1_1CodeStream.md#popsegment" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">popSegment</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1VirtualMachine.md#tht" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">THT</span>
</a>
</span>
<br/>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/VirtualMachine/Emitter.h#L78" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Emitter.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/VirtualMachine/Emitter.cpp#L579" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Emitter.cpp</span>
</a>
</span>
<br/>
<br/>
<a id="popthis"></a>
<h2>popThis</h2>
<span class="inline-text">void</span>
<span class="bold-text"><b>popThis</b></span>
<span class="italic-text"><i>(</i></span>
<div class="paragraph">
<span class="paragraph"><img src="../images/horSpace24px.svg"/><span class="inline-text">const size_t &amp;</span>
<span class="inline-text">idx</span>
</span>
</div>
<span class="italic-text"><i>)</i></span>
<a id="references"></a>
<h4>References</h4>
<span class="icon-list-item"><a href="classHack_1_1VirtualMachine_1_1CodeStream.md#popsegment" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">popSegment</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1VirtualMachine.md#ths" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">THS</span>
</a>
</span>
<br/>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/VirtualMachine/Emitter.h#L76" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Emitter.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/VirtualMachine/Emitter.cpp#L573" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Emitter.cpp</span>
</a>
</span>
<br/>
<br/>
<a id="pushargument"></a>
<h2>pushArgument</h2>
<span class="inline-text">void</span>
<span class="bold-text"><b>pushArgument</b></span>
<span class="italic-text"><i>(</i></span>
<div class="paragraph">
<span class="paragraph"><img src="../images/horSpace24px.svg"/><span class="inline-text">const size_t &amp;</span>
<span class="inline-text">idx</span>
</span>
</div>
<span class="italic-text"><i>)</i></span>
<a id="references"></a>
<h4>References</h4>
<span class="icon-list-item"><a href="classHack_1_1VirtualMachine_1_1CodeStream.md#comparedintox" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">compareDIntoX</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1VirtualMachine.md#sw2" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">SW2</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1VirtualMachine.md#arg" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">ARG</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="classHack_1_1VirtualMachine_1_1CodeStream.md#jumpifequals" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">jumpIfEquals</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="classHack_1_1VirtualMachine_1_1CodeStream.md#dereferenceoffset" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">dereferenceOffset</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="classHack_1_1VirtualMachine_1_1CodeStream.md#copymintod" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">copyMIntoD</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="classHack_1_1VirtualMachine_1_1CodeStream.md#pushd" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">pushD</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="classHack_1_1VirtualMachine_1_1CodeStream.md#label" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">label</span>
</a>
</span>
<br/>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/VirtualMachine/Emitter.h#L62" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Emitter.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/VirtualMachine/Emitter.cpp#L491" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Emitter.cpp</span>
</a>
</span>
<br/>
<br/>
<a id="pushconstant"></a>
<h2>pushConstant</h2>
<span class="inline-text">void</span>
<span class="bold-text"><b>pushConstant</b></span>
<span class="italic-text"><i>(</i></span>
<div class="paragraph">
<span class="paragraph"><img src="../images/horSpace24px.svg"/><span class="inline-text">const int &amp;</span>
<span class="inline-text">idx</span>
</span>
</div>
<span class="italic-text"><i>)</i></span>
<a id="references"></a>
<h4>References</h4>
<span class="icon-list-item"><a href="classHack_1_1VirtualMachine_1_1CodeStream.md#push" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">push</span>
</a>
</span>
<br/>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/VirtualMachine/Emitter.h#L58" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Emitter.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/VirtualMachine/Emitter.cpp#L418" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Emitter.cpp</span>
</a>
</span>
<br/>
<br/>
<a id="pushlocal"></a>
<h2>pushLocal</h2>
<span class="inline-text">void</span>
<span class="bold-text"><b>pushLocal</b></span>
<span class="italic-text"><i>(</i></span>
<div class="paragraph">
<span class="paragraph"><img src="../images/horSpace24px.svg"/><span class="inline-text">const size_t &amp;</span>
<span class="inline-text">idx</span>
</span>
</div>
<span class="italic-text"><i>)</i></span>
<a id="references"></a>
<h4>References</h4>
<span class="icon-list-item"><a href="classHack_1_1VirtualMachine_1_1CodeStream.md#comparedintox" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">compareDIntoX</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1VirtualMachine.md#sw2" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">SW2</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1VirtualMachine.md#lcl" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">LCL</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="classHack_1_1VirtualMachine_1_1CodeStream.md#jumpifequals" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">jumpIfEquals</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="classHack_1_1VirtualMachine_1_1CodeStream.md#dereferenceoffset" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">dereferenceOffset</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="classHack_1_1VirtualMachine_1_1CodeStream.md#copymintod" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">copyMIntoD</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="classHack_1_1VirtualMachine_1_1CodeStream.md#pushd" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">pushD</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="classHack_1_1VirtualMachine_1_1CodeStream.md#label" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">label</span>
</a>
</span>
<br/>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/VirtualMachine/Emitter.h#L60" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Emitter.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/VirtualMachine/Emitter.cpp#L424" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Emitter.cpp</span>
</a>
</span>
<br/>
<br/>
<a id="pushpointer"></a>
<h2>pushPointer</h2>
<span class="inline-text">void</span>
<span class="bold-text"><b>pushPointer</b></span>
<span class="italic-text"><i>(</i></span>
<div class="paragraph">
<span class="paragraph"><img src="../images/horSpace24px.svg"/><span class="inline-text">const size_t &amp;</span>
<span class="inline-text">idx</span>
</span>
</div>
<span class="italic-text"><i>)</i></span>
<a id="references"></a>
<h4>References</h4>
<span class="icon-list-item"><a href="classHack_1_1VirtualMachine_1_1CodeStream.md#comparedintox" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">compareDIntoX</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1VirtualMachine.md#sw2" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">SW2</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1VirtualMachine.md#arg" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">ARG</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="classHack_1_1VirtualMachine_1_1CodeStream.md#jumpifequals" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">jumpIfEquals</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="classHack_1_1VirtualMachine_1_1CodeStream.md#offsetto" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">offsetTo</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1VirtualMachine.md#ths" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">THS</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="classHack_1_1VirtualMachine_1_1CodeStream.md#copymintod" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">copyMIntoD</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="classHack_1_1VirtualMachine_1_1CodeStream.md#pushd" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">pushD</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="classHack_1_1VirtualMachine_1_1CodeStream.md#label" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">label</span>
</a>
</span>
<br/>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/VirtualMachine/Emitter.h#L72" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Emitter.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/VirtualMachine/Emitter.cpp#L510" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Emitter.cpp</span>
</a>
</span>
<br/>
<br/>
<a id="pushstatic"></a>
<h2>pushStatic</h2>
<span class="inline-text">void</span>
<span class="bold-text"><b>pushStatic</b></span>
<span class="italic-text"><i>(</i></span>
<div class="paragraph">
<span class="paragraph"><img src="../images/horSpace24px.svg"/><span class="inline-text">const </span>
<a href="namespaceHack.md#string">String</a>
<span class="inline-text"> &amp;</span>
<span class="inline-text">context</span>
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
<span class="icon-list-item"><a href="namespaceHack.md#stringcombine" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">StringCombine</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="classHack_1_1VirtualMachine_1_1CodeStream.md#ataddressof" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">atAddressOf</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="classHack_1_1VirtualMachine_1_1CodeStream.md#copymintod" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">copyMIntoD</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="classHack_1_1VirtualMachine_1_1CodeStream.md#incrementandjump" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">incrementAndJump</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="classHack_1_1VirtualMachine_1_1CodeStream.md#movedintom" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">moveDIntoM</span>
</a>
</span>
<br/>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/VirtualMachine/Emitter.h#L68" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Emitter.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/VirtualMachine/Emitter.cpp#L538" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Emitter.cpp</span>
</a>
</span>
<br/>
<br/>
<a id="pushtemp"></a>
<h2>pushTemp</h2>
<span class="inline-text">void</span>
<span class="bold-text"><b>pushTemp</b></span>
<span class="italic-text"><i>(</i></span>
<div class="paragraph">
<span class="paragraph"><img src="../images/horSpace24px.svg"/><span class="inline-text">const size_t &amp;</span>
<span class="inline-text">idx</span>
</span>
</div>
<span class="italic-text"><i>)</i></span>
<a id="references"></a>
<h4>References</h4>
<span class="icon-list-item"><a href="classHack_1_1VirtualMachine_1_1CodeStream.md#offsetto" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">offsetTo</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1VirtualMachine.md#tmp" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">TMP</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="classHack_1_1VirtualMachine_1_1CodeStream.md#movemintod" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">moveMIntoD</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="classHack_1_1VirtualMachine_1_1CodeStream.md#pushd" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">pushD</span>
</a>
</span>
<br/>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/VirtualMachine/Emitter.h#L70" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Emitter.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/VirtualMachine/Emitter.cpp#L483" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Emitter.cpp</span>
</a>
</span>
<br/>
<br/>
<a id="pushthat"></a>
<h2>pushThat</h2>
<span class="inline-text">void</span>
<span class="bold-text"><b>pushThat</b></span>
<span class="italic-text"><i>(</i></span>
<div class="paragraph">
<span class="paragraph"><img src="../images/horSpace24px.svg"/><span class="inline-text">const size_t &amp;</span>
<span class="inline-text">idx</span>
</span>
</div>
<span class="italic-text"><i>)</i></span>
<a id="references"></a>
<h4>References</h4>
<span class="icon-list-item"><a href="classHack_1_1VirtualMachine_1_1CodeStream.md#comparedintox" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">compareDIntoX</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1VirtualMachine.md#sw2" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">SW2</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1VirtualMachine.md#tht" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">THT</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="classHack_1_1VirtualMachine_1_1CodeStream.md#jumpifequals" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">jumpIfEquals</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="classHack_1_1VirtualMachine_1_1CodeStream.md#dereferenceoffset" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">dereferenceOffset</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="classHack_1_1VirtualMachine_1_1CodeStream.md#copymintod" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">copyMIntoD</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="classHack_1_1VirtualMachine_1_1CodeStream.md#pushd" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">pushD</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="classHack_1_1VirtualMachine_1_1CodeStream.md#label" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">label</span>
</a>
</span>
<br/>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/VirtualMachine/Emitter.h#L66" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Emitter.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/VirtualMachine/Emitter.cpp#L464" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Emitter.cpp</span>
</a>
</span>
<br/>
<br/>
<a id="pushthis"></a>
<h2>pushThis</h2>
<span class="inline-text">void</span>
<span class="bold-text"><b>pushThis</b></span>
<span class="italic-text"><i>(</i></span>
<div class="paragraph">
<span class="paragraph"><img src="../images/horSpace24px.svg"/><span class="inline-text">const size_t &amp;</span>
<span class="inline-text">idx</span>
</span>
</div>
<span class="italic-text"><i>)</i></span>
<a id="references"></a>
<h4>References</h4>
<span class="icon-list-item"><a href="classHack_1_1VirtualMachine_1_1CodeStream.md#comparedintox" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">compareDIntoX</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1VirtualMachine.md#sw2" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">SW2</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1VirtualMachine.md#ths" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">THS</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="classHack_1_1VirtualMachine_1_1CodeStream.md#jumpifequals" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">jumpIfEquals</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="classHack_1_1VirtualMachine_1_1CodeStream.md#dereferenceoffset" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">dereferenceOffset</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="classHack_1_1VirtualMachine_1_1CodeStream.md#copymintod" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">copyMIntoD</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="classHack_1_1VirtualMachine_1_1CodeStream.md#pushd" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">pushD</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="classHack_1_1VirtualMachine_1_1CodeStream.md#label" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">label</span>
</a>
</span>
<br/>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/VirtualMachine/Emitter.h#L64" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Emitter.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/VirtualMachine/Emitter.cpp#L445" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Emitter.cpp</span>
</a>
</span>
<br/>
<br/>
<a id="setram"></a>
<h2>setRam</h2>
<span class="inline-text">void</span>
<span class="bold-text"><b>setRam</b></span>
<span class="italic-text"><i>(</i></span>
<div class="paragraph">
<span class="paragraph"><img src="../images/horSpace24px.svg"/><span class="inline-text">int</span>
<span class="inline-text">index</span>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/horSpace24px.svg"/><span class="inline-text">int</span>
<span class="inline-text">value</span>
</span>
</div>
<span class="italic-text"><i>)</i></span>
<a id="references"></a>
<h4>References</h4>
<span class="icon-list-item"><a href="classHack_1_1VirtualMachine_1_1CodeStream.md#move" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">move</span>
</a>
</span>
<br/>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/VirtualMachine/Emitter.h#L56" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Emitter.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/VirtualMachine/Emitter.cpp#L412" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Emitter.cpp</span>
</a>
</span>
<br/>
<br/>
<a id="stream"></a>
<h2>stream</h2>
<a href="namespaceHack.md#outputstringstream">OutputStringStream</a>
<span class="inline-text"> &amp;</span>
<span class="bold-text"><b>stream</b></span>
<span class="italic-text"><i>(</i></span>
<span class="italic-text"><i>)</i></span>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/VirtualMachine/Emitter.h#L51" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Emitter.h</span>
</a>
</span>
<br/>
<br/>
<a id="writeadd"></a>
<h2>writeAdd</h2>
<span class="inline-text">void</span>
<span class="bold-text"><b>writeAdd</b></span>
<span class="italic-text"><i>(</i></span>
<span class="italic-text"><i>)</i></span>
<a id="references"></a>
<h4>References</h4>
<span class="icon-list-item"><a href="classHack_1_1VirtualMachine_1_1CodeStream.md#jumpstacktop" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">jumpStackTop</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="classHack_1_1VirtualMachine_1_1CodeStream.md#movemintod" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">moveMIntoD</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="classHack_1_1VirtualMachine_1_1CodeStream.md#decrementa" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">decrementA</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="classHack_1_1VirtualMachine_1_1CodeStream.md#adddmintom" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">addDmIntoM</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="classHack_1_1VirtualMachine_1_1CodeStream.md#decrement" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">decrement</span>
</a>
</span>
<br/>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/VirtualMachine/Emitter.h#L94" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Emitter.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/VirtualMachine/Emitter.cpp#L655" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Emitter.cpp</span>
</a>
</span>
<br/>
<br/>
<a id="writeand"></a>
<h2>writeAnd</h2>
<span class="inline-text">void</span>
<span class="bold-text"><b>writeAnd</b></span>
<span class="italic-text"><i>(</i></span>
<span class="italic-text"><i>)</i></span>
<a id="references"></a>
<h4>References</h4>
<span class="icon-list-item"><a href="classHack_1_1VirtualMachine_1_1CodeStream.md#jumpstacktop" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">jumpStackTop</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="classHack_1_1VirtualMachine_1_1CodeStream.md#movemintod" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">moveMIntoD</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="classHack_1_1VirtualMachine_1_1CodeStream.md#decrementa" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">decrementA</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="classHack_1_1VirtualMachine_1_1CodeStream.md#anddmintom" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">andDmIntoM</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="classHack_1_1VirtualMachine_1_1CodeStream.md#decrement" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">decrement</span>
</a>
</span>
<br/>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/VirtualMachine/Emitter.h#L90" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Emitter.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/VirtualMachine/Emitter.cpp#L635" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Emitter.cpp</span>
</a>
</span>
<br/>
<br/>
<a id="writecall"></a>
<h2>writeCall</h2>
<span class="inline-text">void</span>
<span class="bold-text"><b>writeCall</b></span>
<span class="italic-text"><i>(</i></span>
<div class="paragraph">
<span class="paragraph"><img src="../images/horSpace24px.svg"/><span class="inline-text">const </span>
<a href="namespaceHack.md#string">String</a>
<span class="inline-text"> &amp;</span>
<span class="inline-text">name</span>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/horSpace24px.svg"/><span class="inline-text">const int &amp;</span>
<span class="inline-text">args</span>
</span>
</div>
<span class="italic-text"><i>)</i></span>
<a id="references"></a>
<h4>References</h4>
<span class="icon-list-item"><a href="classHack_1_1VirtualMachine_1_1CodeStream.md#setd" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">setD</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="classHack_1_1VirtualMachine_1_1CodeStream.md#pushd" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">pushD</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="classHack_1_1VirtualMachine_1_1CodeStream.md#ataddressof" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">atAddressOf</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="classHack_1_1VirtualMachine_1_1CodeStream.md#moveaintod" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">moveAIntoD</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="classHack_1_1VirtualMachine_1_1CodeStream.md#copymintodat" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">copyMIntoDAt</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1VirtualMachine.md#lcl" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">LCL</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1VirtualMachine.md#arg" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">ARG</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1VirtualMachine.md#ths" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">THS</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1VirtualMachine.md#tht" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">THT</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="classHack_1_1VirtualMachine_1_1CodeStream.md#addxtod" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">addXToD</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1VirtualMachine.md#stp" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">STP</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="classHack_1_1VirtualMachine_1_1CodeStream.md#subdmintod" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">subDmIntoD</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="classHack_1_1VirtualMachine_1_1CodeStream.md#subxfromd" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">subXFromD</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="classHack_1_1VirtualMachine_1_1CodeStream.md#movedintom" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">moveDIntoM</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="classHack_1_1VirtualMachine_1_1CodeStream.md#jumpto" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">jumpTo</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="classHack_1_1VirtualMachine_1_1CodeStream.md#label" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">label</span>
</a>
</span>
<br/>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/VirtualMachine/Emitter.h#L118" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Emitter.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/VirtualMachine/Emitter.cpp#L800" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Emitter.cpp</span>
</a>
</span>
<br/>
<br/>
<a id="writecode"></a>
<h2>writeCode</h2>
<span class="inline-text">void</span>
<span class="bold-text"><b>writeCode</b></span>
<span class="italic-text"><i>(</i></span>
<div class="paragraph">
<span class="paragraph"><img src="../images/horSpace24px.svg"/><span class="inline-text">const </span>
<a href="namespaceHack.md#string">String</a>
<span class="inline-text"> &amp;</span>
<span class="inline-text">cs</span>
</span>
</div>
<span class="italic-text"><i>)</i></span>
<a id="references"></a>
<h4>References</h4>
<span class="icon-list-item"><a href="classHack_1_1VirtualMachine_1_1CodeStream.md#write" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">write</span>
</a>
</span>
<br/>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/VirtualMachine/Emitter.h#L122" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Emitter.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/VirtualMachine/Emitter.cpp#L891" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Emitter.cpp</span>
</a>
</span>
<br/>
<br/>
<a id="writeeq"></a>
<h2>writeEq</h2>
<span class="inline-text">void</span>
<span class="bold-text"><b>writeEq</b></span>
<span class="italic-text"><i>(</i></span>
<span class="italic-text"><i>)</i></span>
<a id="references"></a>
<h4>References</h4>
<span class="icon-list-item"><a href="classHack_1_1VirtualMachine_1_1CodeStream.md#jumpstacktop" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">jumpStackTop</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="classHack_1_1VirtualMachine_1_1CodeStream.md#copymintod" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">copyMIntoD</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="classHack_1_1VirtualMachine_1_1CodeStream.md#decrementa" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">decrementA</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="classHack_1_1VirtualMachine_1_1CodeStream.md#submdintod" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">subMdIntoD</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="classHack_1_1VirtualMachine_1_1CodeStream.md#jumpifequals" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">jumpIfEquals</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="classHack_1_1VirtualMachine_1_1CodeStream.md#setd" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">setD</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="classHack_1_1VirtualMachine_1_1CodeStream.md#jumpto" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">jumpTo</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="classHack_1_1VirtualMachine_1_1CodeStream.md#label" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">label</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="classHack_1_1VirtualMachine_1_1CodeStream.md#movedintom" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">moveDIntoM</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="classHack_1_1VirtualMachine_1_1CodeStream.md#decrement" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">decrement</span>
</a>
</span>
<br/>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/VirtualMachine/Emitter.h#L100" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Emitter.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/VirtualMachine/Emitter.cpp#L679" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Emitter.cpp</span>
</a>
</span>
<br/>
<br/>
<a id="writefunction"></a>
<h2>writeFunction</h2>
<span class="inline-text">void</span>
<span class="bold-text"><b>writeFunction</b></span>
<span class="italic-text"><i>(</i></span>
<div class="paragraph">
<span class="paragraph"><img src="../images/horSpace24px.svg"/><span class="inline-text">const </span>
<a href="namespaceHack.md#string">String</a>
<span class="inline-text"> &amp;</span>
<span class="inline-text">name</span>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/horSpace24px.svg"/><span class="inline-text">const int &amp;</span>
<span class="inline-text">locals</span>
</span>
</div>
<span class="italic-text"><i>)</i></span>
<a id="references"></a>
<h4>References</h4>
<span class="icon-list-item"><a href="classHack_1_1VirtualMachine_1_1CodeStream.md#label" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">label</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="classHack_1_1VirtualMachine_1_1CodeStream.md#dereferenceoffset" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">dereferenceOffset</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1VirtualMachine.md#lcl" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">LCL</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="classHack_1_1VirtualMachine_1_1CodeStream.md#setm" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">setM</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="classHack_1_1VirtualMachine_1_1CodeStream.md#increment" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">increment</span>
</a>
</span>
<br/>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/VirtualMachine/Emitter.h#L116" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Emitter.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/VirtualMachine/Emitter.cpp#L783" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Emitter.cpp</span>
</a>
</span>
<br/>
<br/>
<a id="writegt"></a>
<h2>writeGt</h2>
<span class="inline-text">void</span>
<span class="bold-text"><b>writeGt</b></span>
<span class="italic-text"><i>(</i></span>
<span class="italic-text"><i>)</i></span>
<a id="references"></a>
<h4>References</h4>
<span class="icon-list-item"><a href="classHack_1_1VirtualMachine_1_1CodeStream.md#jumpstacktop" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">jumpStackTop</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="classHack_1_1VirtualMachine_1_1CodeStream.md#copymintod" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">copyMIntoD</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="classHack_1_1VirtualMachine_1_1CodeStream.md#decrementa" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">decrementA</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="classHack_1_1VirtualMachine_1_1CodeStream.md#submdintod" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">subMdIntoD</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="classHack_1_1VirtualMachine_1_1CodeStream.md#jumpifgreater" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">jumpIfGreater</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="classHack_1_1VirtualMachine_1_1CodeStream.md#setd" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">setD</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="classHack_1_1VirtualMachine_1_1CodeStream.md#jumpto" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">jumpTo</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="classHack_1_1VirtualMachine_1_1CodeStream.md#label" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">label</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="classHack_1_1VirtualMachine_1_1CodeStream.md#movedintom" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">moveDIntoM</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="classHack_1_1VirtualMachine_1_1CodeStream.md#decrement" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">decrement</span>
</a>
</span>
<br/>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/VirtualMachine/Emitter.h#L104" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Emitter.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/VirtualMachine/Emitter.cpp#L724" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Emitter.cpp</span>
</a>
</span>
<br/>
<br/>
<a id="writehalt"></a>
<h2>writeHalt</h2>
<span class="inline-text">void</span>
<span class="bold-text"><b>writeHalt</b></span>
<span class="italic-text"><i>(</i></span>
<span class="italic-text"><i>)</i></span>
<a id="references"></a>
<h4>References</h4>
<span class="icon-list-item"><a href="classHack_1_1VirtualMachine_1_1CodeStream.md#label" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">label</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="classHack_1_1VirtualMachine_1_1CodeStream.md#jumptoromaddress" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">jumpToRomAddress</span>
</a>
</span>
<br/>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/VirtualMachine/Emitter.h#L108" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Emitter.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/VirtualMachine/Emitter.cpp#L752" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Emitter.cpp</span>
</a>
</span>
<br/>
<br/>
<a id="writelabel"></a>
<h2>writeLabel</h2>
<span class="inline-text">void</span>
<span class="bold-text"><b>writeLabel</b></span>
<span class="italic-text"><i>(</i></span>
<div class="paragraph">
<span class="paragraph"><img src="../images/horSpace24px.svg"/><span class="inline-text">const </span>
<a href="namespaceHack.md#string">String</a>
<span class="inline-text"> &amp;</span>
<span class="inline-text">value</span>
</span>
</div>
<span class="italic-text"><i>)</i></span>
<a id="references"></a>
<h4>References</h4>
<span class="icon-list-item"><a href="classHack_1_1VirtualMachine_1_1CodeStream.md#label" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">label</span>
</a>
</span>
<br/>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/VirtualMachine/Emitter.h#L114" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Emitter.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/VirtualMachine/Emitter.cpp#L777" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Emitter.cpp</span>
</a>
</span>
<br/>
<br/>
<a id="writelt"></a>
<h2>writeLt</h2>
<span class="inline-text">void</span>
<span class="bold-text"><b>writeLt</b></span>
<span class="italic-text"><i>(</i></span>
<span class="italic-text"><i>)</i></span>
<a id="references"></a>
<h4>References</h4>
<span class="icon-list-item"><a href="classHack_1_1VirtualMachine_1_1CodeStream.md#jumpstacktop" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">jumpStackTop</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="classHack_1_1VirtualMachine_1_1CodeStream.md#copymintod" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">copyMIntoD</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="classHack_1_1VirtualMachine_1_1CodeStream.md#decrementa" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">decrementA</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="classHack_1_1VirtualMachine_1_1CodeStream.md#submdintod" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">subMdIntoD</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="classHack_1_1VirtualMachine_1_1CodeStream.md#jumpifless" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">jumpIfLess</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="classHack_1_1VirtualMachine_1_1CodeStream.md#setd" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">setD</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="classHack_1_1VirtualMachine_1_1CodeStream.md#jumpto" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">jumpTo</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="classHack_1_1VirtualMachine_1_1CodeStream.md#label" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">label</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="classHack_1_1VirtualMachine_1_1CodeStream.md#movedintom" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">moveDIntoM</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="classHack_1_1VirtualMachine_1_1CodeStream.md#decrement" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">decrement</span>
</a>
</span>
<br/>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/VirtualMachine/Emitter.h#L102" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Emitter.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/VirtualMachine/Emitter.cpp#L702" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Emitter.cpp</span>
</a>
</span>
<br/>
<br/>
<a id="writeneg"></a>
<h2>writeNeg</h2>
<span class="inline-text">void</span>
<span class="bold-text"><b>writeNeg</b></span>
<span class="italic-text"><i>(</i></span>
<span class="italic-text"><i>)</i></span>
<a id="references"></a>
<h4>References</h4>
<span class="icon-list-item"><a href="classHack_1_1VirtualMachine_1_1CodeStream.md#jumpstacktop" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">jumpStackTop</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="classHack_1_1VirtualMachine_1_1CodeStream.md#negmintom" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">negMIntoM</span>
</a>
</span>
<br/>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/VirtualMachine/Emitter.h#L98" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Emitter.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/VirtualMachine/Emitter.cpp#L672" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Emitter.cpp</span>
</a>
</span>
<br/>
<br/>
<a id="writenot"></a>
<h2>writeNot</h2>
<span class="inline-text">void</span>
<span class="bold-text"><b>writeNot</b></span>
<span class="italic-text"><i>(</i></span>
<span class="italic-text"><i>)</i></span>
<a id="references"></a>
<h4>References</h4>
<span class="icon-list-item"><a href="classHack_1_1VirtualMachine_1_1CodeStream.md#jumpstacktop" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">jumpStackTop</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="classHack_1_1VirtualMachine_1_1CodeStream.md#notmintom" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">notMIntoM</span>
</a>
</span>
<br/>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/VirtualMachine/Emitter.h#L96" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Emitter.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/VirtualMachine/Emitter.cpp#L665" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Emitter.cpp</span>
</a>
</span>
<br/>
<br/>
<a id="writeor"></a>
<h2>writeOr</h2>
<span class="inline-text">void</span>
<span class="bold-text"><b>writeOr</b></span>
<span class="italic-text"><i>(</i></span>
<span class="italic-text"><i>)</i></span>
<a id="references"></a>
<h4>References</h4>
<span class="icon-list-item"><a href="classHack_1_1VirtualMachine_1_1CodeStream.md#jumpstacktop" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">jumpStackTop</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="classHack_1_1VirtualMachine_1_1CodeStream.md#movemintod" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">moveMIntoD</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="classHack_1_1VirtualMachine_1_1CodeStream.md#decrementa" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">decrementA</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="classHack_1_1VirtualMachine_1_1CodeStream.md#ordmintom" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">orDmIntoM</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="classHack_1_1VirtualMachine_1_1CodeStream.md#decrement" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">decrement</span>
</a>
</span>
<br/>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/VirtualMachine/Emitter.h#L88" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Emitter.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/VirtualMachine/Emitter.cpp#L625" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Emitter.cpp</span>
</a>
</span>
<br/>
<br/>
<a id="writereset"></a>
<h2>writeReset</h2>
<span class="inline-text">void</span>
<span class="bold-text"><b>writeReset</b></span>
<span class="italic-text"><i>(</i></span>
<span class="italic-text"><i>)</i></span>
<a id="references"></a>
<h4>References</h4>
<span class="icon-list-item"><a href="classHack_1_1VirtualMachine_1_1CodeStream.md#jumptoromaddress" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">jumpToRomAddress</span>
</a>
</span>
<br/>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/VirtualMachine/Emitter.h#L106" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Emitter.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/VirtualMachine/Emitter.cpp#L746" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Emitter.cpp</span>
</a>
</span>
<br/>
<br/>
<a id="writereturn"></a>
<h2>writeReturn</h2>
<span class="inline-text">void</span>
<span class="bold-text"><b>writeReturn</b></span>
<span class="italic-text"><i>(</i></span>
<span class="italic-text"><i>)</i></span>
<a id="references"></a>
<h4>References</h4>
<span class="icon-list-item"><a href="classHack_1_1VirtualMachine_1_1CodeStream.md#copymintodat" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">copyMIntoDAt</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1VirtualMachine.md#lcl" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">LCL</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="classHack_1_1VirtualMachine_1_1CodeStream.md#movedintox" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">moveDIntoX</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1VirtualMachine.md#sw0" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">SW0</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="classHack_1_1VirtualMachine_1_1CodeStream.md#jumpstacktop" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">jumpStackTop</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="classHack_1_1VirtualMachine_1_1CodeStream.md#movemintod" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">moveMIntoD</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="classHack_1_1VirtualMachine_1_1CodeStream.md#decrement" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">decrement</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="classHack_1_1VirtualMachine_1_1CodeStream.md#atdereferencedaddressof" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">atDeReferencedAddressOf</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1VirtualMachine.md#arg" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">ARG</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="classHack_1_1VirtualMachine_1_1CodeStream.md#movedintom" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">moveDIntoM</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="classHack_1_1VirtualMachine_1_1CodeStream.md#addxtod" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">addXToD</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="classHack_1_1VirtualMachine_1_1CodeStream.md#ataddressof" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">atAddressOf</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1VirtualMachine.md#stp" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">STP</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="classHack_1_1VirtualMachine_1_1CodeStream.md#popstackframe" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">popStackFrame</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1VirtualMachine.md#tht" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">THT</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1VirtualMachine.md#ths" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">THS</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="classHack_1_1VirtualMachine_1_1CodeStream.md#movemintodat" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">moveMIntoDAt</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="classHack_1_1VirtualMachine_1_1CodeStream.md#subxfromd" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">subXFromD</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="classHack_1_1VirtualMachine_1_1CodeStream.md#dereferenced" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">dereferenceD</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1VirtualMachine.md#sw2" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">SW2</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="classHack_1_1VirtualMachine_1_1CodeStream.md#jumptod" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">jumpToD</span>
</a>
</span>
<br/>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/VirtualMachine/Emitter.h#L120" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Emitter.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/VirtualMachine/Emitter.cpp#L855" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Emitter.cpp</span>
</a>
</span>
<br/>
<br/>
<a id="writesub"></a>
<h2>writeSub</h2>
<span class="inline-text">void</span>
<span class="bold-text"><b>writeSub</b></span>
<span class="italic-text"><i>(</i></span>
<span class="italic-text"><i>)</i></span>
<a id="references"></a>
<h4>References</h4>
<span class="icon-list-item"><a href="classHack_1_1VirtualMachine_1_1CodeStream.md#jumpstacktop" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">jumpStackTop</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="classHack_1_1VirtualMachine_1_1CodeStream.md#movemintod" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">moveMIntoD</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="classHack_1_1VirtualMachine_1_1CodeStream.md#decrementa" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">decrementA</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="classHack_1_1VirtualMachine_1_1CodeStream.md#submdintom" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">subMdIntoM</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="classHack_1_1VirtualMachine_1_1CodeStream.md#decrement" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">decrement</span>
</a>
</span>
<br/>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/VirtualMachine/Emitter.h#L92" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Emitter.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/VirtualMachine/Emitter.cpp#L645" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Emitter.cpp</span>
</a>
</span>
<br/>
<br/>
<a id="writgoto"></a>
<h2>writGoto</h2>
<span class="inline-text">void</span>
<span class="bold-text"><b>writGoto</b></span>
<span class="italic-text"><i>(</i></span>
<div class="paragraph">
<span class="paragraph"><img src="../images/horSpace24px.svg"/><span class="inline-text">const </span>
<a href="namespaceHack.md#string">String</a>
<span class="inline-text"> &amp;</span>
<span class="inline-text">value</span>
</span>
</div>
<span class="italic-text"><i>)</i></span>
<a id="references"></a>
<h4>References</h4>
<span class="icon-list-item"><a href="classHack_1_1VirtualMachine_1_1CodeStream.md#jumptoromaddress" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">jumpToRomAddress</span>
</a>
</span>
<br/>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/VirtualMachine/Emitter.h#L110" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Emitter.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/VirtualMachine/Emitter.cpp#L762" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Emitter.cpp</span>
</a>
</span>
<br/>
<br/>
<a id="writifgoto"></a>
<h2>writIfGoto</h2>
<span class="inline-text">void</span>
<span class="bold-text"><b>writIfGoto</b></span>
<span class="italic-text"><i>(</i></span>
<div class="paragraph">
<span class="paragraph"><img src="../images/horSpace24px.svg"/><span class="inline-text">const </span>
<a href="namespaceHack.md#string">String</a>
<span class="inline-text"> &amp;</span>
<span class="inline-text">value</span>
</span>
</div>
<span class="italic-text"><i>)</i></span>
<a id="references"></a>
<h4>References</h4>
<span class="icon-list-item"><a href="classHack_1_1VirtualMachine_1_1CodeStream.md#jumpstacktop" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">jumpStackTop</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="classHack_1_1VirtualMachine_1_1CodeStream.md#movemintod" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">moveMIntoD</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="classHack_1_1VirtualMachine_1_1CodeStream.md#decrement" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">decrement</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="classHack_1_1VirtualMachine_1_1CodeStream.md#jumpifnotequals" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">jumpIfNotEquals</span>
</a>
</span>
<br/>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/VirtualMachine/Emitter.h#L112" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Emitter.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/VirtualMachine/Emitter.cpp#L768" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Emitter.cpp</span>
</a>
</span>
<br/>
<br/>
</div>
</div>
</body>
</html>
