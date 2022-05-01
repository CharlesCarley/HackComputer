<a id="vmemitter"></a>
<h1>VmEmitter</h1>
<a id="classhack_1_1compiler_1_1codegenerator_1_1vmemitter"></a>
<a href="https://github.com/CharlesCarley/HackComputer#~">~</a>
<a href="index.md#index">HackComputer</a>
<span class="inline-text">/</span>
<a href="namespaceHack.md#hack">Hack</a>
<span class="inline-text">::</span>
<a href="namespaceHack_1_1Compiler.md#compiler">Compiler</a>
<span class="inline-text">::</span>
<a href="namespaceHack_1_1Compiler_1_1CodeGenerator.md#codegenerator">CodeGenerator</a>
<span class="inline-text">::</span>
<span class="bold-text"><b>VmEmitter</b></span>
<br/>
<br/>
<a id="private-members"></a>
<h2>Private Members</h2>
<span class="icon-list-item"><a href="#_eof" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">_eof</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#_stream" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">_stream</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#_uid" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">_uid</span>
</a>
</span>
<br/>
<a id="private-methods"></a>
<h2>Private Methods</h2>
<span class="icon-list-item"><a href="#write" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">write</span>
</a>
</span>
<br/>
<a id="public-methods"></a>
<h2>Public Methods</h2>
<span class="icon-list-item"><a href="#vmemitter" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">VmEmitter</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#clear" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">clear</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#finalize" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">finalize</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#generatelabel" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">generateLabel</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#initialize" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">initialize</span>
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
<span class="icon-list-item"><a href="#stream" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">stream</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#symboladd" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">symbolAdd</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#symboland" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">symbolAnd</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#symbolequals" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">symbolEquals</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#symbolgreater" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">symbolGreater</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#symbolless" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">symbolLess</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#symbolneg" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">symbolNeg</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#symbolnot" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">symbolNot</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#symbolor" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">symbolOr</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#symbolsub" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">symbolSub</span>
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
<span class="icon-list-item"><a href="#writefield" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">writeField</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#writefunction" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">writeFunction</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#writegoto" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">writeGoto</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#writeifstart" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">writeIfStart</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#writelabel" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">writeLabel</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#writemethod" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">writeMethod</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#writereturn" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">writeReturn</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#writestatic" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">writeStatic</span>
</a>
</span>
<br/>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Compiler/Generator/VmEmitter.h#L33" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">VmEmitter.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#vmemitter" class="icon-list-item"><img src="../images/jumpToTop.svg" class="icon-list-item"/><span class="icon-list-item">top</span>
</a>
</span>
<a id="_eof"></a>
<h2>_eof</h2>
<a href="namespaceHack.md#string">String</a>
<span class="bold-text"><b>_eof</b></span>
<br/>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Compiler/Generator/VmEmitter.h#L37" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">VmEmitter.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#vmemitter" class="icon-list-item"><img src="../images/jumpToTop.svg" class="icon-list-item"/><span class="icon-list-item">top</span>
</a>
</span>
<br/>
<a id="_stream"></a>
<h2>_stream</h2>
<a href="namespaceHack.md#outputstringstream">OutputStringStream</a>
<span class="bold-text"><b>_stream</b></span>
<br/>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Compiler/Generator/VmEmitter.h#L35" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">VmEmitter.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#vmemitter" class="icon-list-item"><img src="../images/jumpToTop.svg" class="icon-list-item"/><span class="icon-list-item">top</span>
</a>
</span>
<br/>
<a id="_uid"></a>
<h2>_uid</h2>
<span class="inline-text">int</span>
<span class="bold-text"><b>_uid</b></span>
<br/>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Compiler/Generator/VmEmitter.h#L36" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">VmEmitter.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#vmemitter" class="icon-list-item"><img src="../images/jumpToTop.svg" class="icon-list-item"/><span class="icon-list-item">top</span>
</a>
</span>
<br/>
<a id="write"></a>
<h2>write</h2>
<span class="inline-text">void</span>
<span class="bold-text"><b>write</b></span>
<span class="italic-text"><i>(</i></span>
<div class="paragraph">
<span class="paragraph"><img src="../images/horSpace24px.svg"/><span class="inline-text">Args &amp;&amp;...</span>
<span class="inline-text">args</span>
</span>
</div>
<span class="italic-text"><i>)</i></span>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Compiler/Generator/VmEmitter.h#L40" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">VmEmitter.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#vmemitter" class="icon-list-item"><img src="../images/jumpToTop.svg" class="icon-list-item"/><span class="icon-list-item">top</span>
</a>
</span>
<br/>
<a id="vmemitter"></a>
<h2>VmEmitter</h2>
<span class="bold-text"><b>VmEmitter</b></span>
<span class="italic-text"><i>(</i></span>
<span class="italic-text"><i>)</i></span>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Compiler/Generator/VmEmitter.h#L48" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">VmEmitter.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Compiler/Generator/VmEmitter.cpp#L30" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">VmEmitter.cpp</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#vmemitter" class="icon-list-item"><img src="../images/jumpToTop.svg" class="icon-list-item"/><span class="icon-list-item">top</span>
</a>
</span>
<br/>
<a id="clear"></a>
<h2>clear</h2>
<span class="inline-text">void</span>
<span class="bold-text"><b>clear</b></span>
<span class="italic-text"><i>(</i></span>
<span class="italic-text"><i>)</i></span>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Compiler/Generator/VmEmitter.h#L56" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">VmEmitter.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Compiler/Generator/VmEmitter.cpp#L47" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">VmEmitter.cpp</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#vmemitter" class="icon-list-item"><img src="../images/jumpToTop.svg" class="icon-list-item"/><span class="icon-list-item">top</span>
</a>
</span>
<br/>
<a id="finalize"></a>
<h2>finalize</h2>
<span class="inline-text">void</span>
<span class="bold-text"><b>finalize</b></span>
<span class="italic-text"><i>(</i></span>
<span class="italic-text"><i>)</i></span>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Compiler/Generator/VmEmitter.h#L54" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">VmEmitter.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Compiler/Generator/VmEmitter.cpp#L42" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">VmEmitter.cpp</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#vmemitter" class="icon-list-item"><img src="../images/jumpToTop.svg" class="icon-list-item"/><span class="icon-list-item">top</span>
</a>
</span>
<br/>
<a id="generatelabel"></a>
<h2>generateLabel</h2>
<a href="namespaceHack.md#string">String</a>
<span class="bold-text"><b>generateLabel</b></span>
<span class="italic-text"><i>(</i></span>
<span class="italic-text"><i>)</i></span>
<a id="references"></a>
<h4>References</h4>
<div class="paragraph">
<span class="paragraph"><img src="../images/class.svg"/><a href="classHack_1_1StringUtils.md#generate">generate</a>
</span>
</div>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Compiler/Generator/VmEmitter.h#L58" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">VmEmitter.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Compiler/Generator/VmEmitter.cpp#L52" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">VmEmitter.cpp</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#vmemitter" class="icon-list-item"><img src="../images/jumpToTop.svg" class="icon-list-item"/><span class="icon-list-item">top</span>
</a>
</span>
<br/>
<a id="initialize"></a>
<h2>initialize</h2>
<span class="inline-text">void</span>
<span class="bold-text"><b>initialize</b></span>
<span class="italic-text"><i>(</i></span>
<span class="italic-text"><i>)</i></span>
<a id="references"></a>
<h4>References</h4>
<div class="paragraph">
<span class="paragraph"><img src="../images/class.svg"/><a href="classHack_1_1Compiler_1_1CodeGenerator_1_1VmEmitter.md#generatelabel">generateLabel</a>
</span>
</div>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Compiler/Generator/VmEmitter.h#L52" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">VmEmitter.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Compiler/Generator/VmEmitter.cpp#L35" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">VmEmitter.cpp</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#vmemitter" class="icon-list-item"><img src="../images/jumpToTop.svg" class="icon-list-item"/><span class="icon-list-item">top</span>
</a>
</span>
<br/>
<a id="popargument"></a>
<h2>popArgument</h2>
<span class="inline-text">void</span>
<span class="bold-text"><b>popArgument</b></span>
<span class="italic-text"><i>(</i></span>
<div class="paragraph">
<span class="paragraph"><img src="../images/horSpace24px.svg"/><span class="inline-text">const size_t &amp;</span>
<span class="inline-text">size</span>
</span>
</div>
<span class="italic-text"><i>)</i></span>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Compiler/Generator/VmEmitter.h#L76" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">VmEmitter.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Compiler/Generator/VmEmitter.cpp#L98" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">VmEmitter.cpp</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#vmemitter" class="icon-list-item"><img src="../images/jumpToTop.svg" class="icon-list-item"/><span class="icon-list-item">top</span>
</a>
</span>
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
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Compiler/Generator/VmEmitter.h#L74" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">VmEmitter.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Compiler/Generator/VmEmitter.cpp#L93" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">VmEmitter.cpp</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#vmemitter" class="icon-list-item"><img src="../images/jumpToTop.svg" class="icon-list-item"/><span class="icon-list-item">top</span>
</a>
</span>
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
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Compiler/Generator/VmEmitter.h#L82" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">VmEmitter.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Compiler/Generator/VmEmitter.cpp#L118" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">VmEmitter.cpp</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#vmemitter" class="icon-list-item"><img src="../images/jumpToTop.svg" class="icon-list-item"/><span class="icon-list-item">top</span>
</a>
</span>
<br/>
<a id="popstatic"></a>
<h2>popStatic</h2>
<span class="inline-text">void</span>
<span class="bold-text"><b>popStatic</b></span>
<span class="italic-text"><i>(</i></span>
<div class="paragraph">
<span class="paragraph"><img src="../images/horSpace24px.svg"/><span class="inline-text">const size_t &amp;</span>
<span class="inline-text">idx</span>
</span>
</div>
<span class="italic-text"><i>)</i></span>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Compiler/Generator/VmEmitter.h#L84" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">VmEmitter.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Compiler/Generator/VmEmitter.cpp#L125" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">VmEmitter.cpp</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#vmemitter" class="icon-list-item"><img src="../images/jumpToTop.svg" class="icon-list-item"/><span class="icon-list-item">top</span>
</a>
</span>
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
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Compiler/Generator/VmEmitter.h#L86" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">VmEmitter.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Compiler/Generator/VmEmitter.cpp#L103" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">VmEmitter.cpp</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#vmemitter" class="icon-list-item"><img src="../images/jumpToTop.svg" class="icon-list-item"/><span class="icon-list-item">top</span>
</a>
</span>
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
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Compiler/Generator/VmEmitter.h#L80" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">VmEmitter.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Compiler/Generator/VmEmitter.cpp#L113" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">VmEmitter.cpp</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#vmemitter" class="icon-list-item"><img src="../images/jumpToTop.svg" class="icon-list-item"/><span class="icon-list-item">top</span>
</a>
</span>
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
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Compiler/Generator/VmEmitter.h#L78" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">VmEmitter.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Compiler/Generator/VmEmitter.cpp#L108" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">VmEmitter.cpp</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#vmemitter" class="icon-list-item"><img src="../images/jumpToTop.svg" class="icon-list-item"/><span class="icon-list-item">top</span>
</a>
</span>
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
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Compiler/Generator/VmEmitter.h#L91" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">VmEmitter.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Compiler/Generator/VmEmitter.cpp#L135" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">VmEmitter.cpp</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#vmemitter" class="icon-list-item"><img src="../images/jumpToTop.svg" class="icon-list-item"/><span class="icon-list-item">top</span>
</a>
</span>
<br/>
<a id="pushconstant"></a>
<h2>pushConstant</h2>
<span class="inline-text">void</span>
<span class="bold-text"><b>pushConstant</b></span>
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
<div class="paragraph">
<span class="paragraph"><img src="../images/class.svg"/><a href="classHack_1_1Char.md#toint16">toInt16</a>
</span>
</div>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Compiler/Generator/VmEmitter.h#L70" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">VmEmitter.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Compiler/Generator/VmEmitter.cpp#L83" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">VmEmitter.cpp</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#vmemitter" class="icon-list-item"><img src="../images/jumpToTop.svg" class="icon-list-item"/><span class="icon-list-item">top</span>
</a>
</span>
<br/>
<a id="pushconstant"></a>
<h2>pushConstant</h2>
<span class="inline-text">void</span>
<span class="bold-text"><b>pushConstant</b></span>
<span class="italic-text"><i>(</i></span>
<div class="paragraph">
<span class="paragraph"><img src="../images/horSpace24px.svg"/><span class="inline-text">const size_t &amp;</span>
<span class="inline-text">value</span>
</span>
</div>
<span class="italic-text"><i>)</i></span>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Compiler/Generator/VmEmitter.h#L72" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">VmEmitter.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Compiler/Generator/VmEmitter.cpp#L88" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">VmEmitter.cpp</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#vmemitter" class="icon-list-item"><img src="../images/jumpToTop.svg" class="icon-list-item"/><span class="icon-list-item">top</span>
</a>
</span>
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
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Compiler/Generator/VmEmitter.h#L89" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">VmEmitter.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Compiler/Generator/VmEmitter.cpp#L130" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">VmEmitter.cpp</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#vmemitter" class="icon-list-item"><img src="../images/jumpToTop.svg" class="icon-list-item"/><span class="icon-list-item">top</span>
</a>
</span>
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
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Compiler/Generator/VmEmitter.h#L98" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">VmEmitter.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Compiler/Generator/VmEmitter.cpp#L150" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">VmEmitter.cpp</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#vmemitter" class="icon-list-item"><img src="../images/jumpToTop.svg" class="icon-list-item"/><span class="icon-list-item">top</span>
</a>
</span>
<br/>
<a id="pushstatic"></a>
<h2>pushStatic</h2>
<span class="inline-text">void</span>
<span class="bold-text"><b>pushStatic</b></span>
<span class="italic-text"><i>(</i></span>
<div class="paragraph">
<span class="paragraph"><img src="../images/horSpace24px.svg"/><span class="inline-text">const size_t &amp;</span>
<span class="inline-text">idx</span>
</span>
</div>
<span class="italic-text"><i>)</i></span>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Compiler/Generator/VmEmitter.h#L100" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">VmEmitter.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Compiler/Generator/VmEmitter.cpp#L158" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">VmEmitter.cpp</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#vmemitter" class="icon-list-item"><img src="../images/jumpToTop.svg" class="icon-list-item"/><span class="icon-list-item">top</span>
</a>
</span>
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
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Compiler/Generator/VmEmitter.h#L102" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">VmEmitter.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Compiler/Generator/VmEmitter.cpp#L163" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">VmEmitter.cpp</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#vmemitter" class="icon-list-item"><img src="../images/jumpToTop.svg" class="icon-list-item"/><span class="icon-list-item">top</span>
</a>
</span>
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
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Compiler/Generator/VmEmitter.h#L96" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">VmEmitter.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Compiler/Generator/VmEmitter.cpp#L145" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">VmEmitter.cpp</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#vmemitter" class="icon-list-item"><img src="../images/jumpToTop.svg" class="icon-list-item"/><span class="icon-list-item">top</span>
</a>
</span>
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
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Compiler/Generator/VmEmitter.h#L94" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">VmEmitter.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Compiler/Generator/VmEmitter.cpp#L140" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">VmEmitter.cpp</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#vmemitter" class="icon-list-item"><img src="../images/jumpToTop.svg" class="icon-list-item"/><span class="icon-list-item">top</span>
</a>
</span>
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
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Compiler/Generator/VmEmitter.h#L50" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">VmEmitter.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#vmemitter" class="icon-list-item"><img src="../images/jumpToTop.svg" class="icon-list-item"/><span class="icon-list-item">top</span>
</a>
</span>
<br/>
<a id="symboladd"></a>
<h2>symbolAdd</h2>
<span class="inline-text">void</span>
<span class="bold-text"><b>symbolAdd</b></span>
<span class="italic-text"><i>(</i></span>
<span class="italic-text"><i>)</i></span>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Compiler/Generator/VmEmitter.h#L107" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">VmEmitter.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Compiler/Generator/VmEmitter.cpp#L173" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">VmEmitter.cpp</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#vmemitter" class="icon-list-item"><img src="../images/jumpToTop.svg" class="icon-list-item"/><span class="icon-list-item">top</span>
</a>
</span>
<br/>
<a id="symboland"></a>
<h2>symbolAnd</h2>
<span class="inline-text">void</span>
<span class="bold-text"><b>symbolAnd</b></span>
<span class="italic-text"><i>(</i></span>
<span class="italic-text"><i>)</i></span>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Compiler/Generator/VmEmitter.h#L111" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">VmEmitter.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Compiler/Generator/VmEmitter.cpp#L188" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">VmEmitter.cpp</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#vmemitter" class="icon-list-item"><img src="../images/jumpToTop.svg" class="icon-list-item"/><span class="icon-list-item">top</span>
</a>
</span>
<br/>
<a id="symbolequals"></a>
<h2>symbolEquals</h2>
<span class="inline-text">void</span>
<span class="bold-text"><b>symbolEquals</b></span>
<span class="italic-text"><i>(</i></span>
<span class="italic-text"><i>)</i></span>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Compiler/Generator/VmEmitter.h#L121" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">VmEmitter.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Compiler/Generator/VmEmitter.cpp#L213" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">VmEmitter.cpp</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#vmemitter" class="icon-list-item"><img src="../images/jumpToTop.svg" class="icon-list-item"/><span class="icon-list-item">top</span>
</a>
</span>
<br/>
<a id="symbolgreater"></a>
<h2>symbolGreater</h2>
<span class="inline-text">void</span>
<span class="bold-text"><b>symbolGreater</b></span>
<span class="italic-text"><i>(</i></span>
<span class="italic-text"><i>)</i></span>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Compiler/Generator/VmEmitter.h#L117" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">VmEmitter.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Compiler/Generator/VmEmitter.cpp#L203" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">VmEmitter.cpp</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#vmemitter" class="icon-list-item"><img src="../images/jumpToTop.svg" class="icon-list-item"/><span class="icon-list-item">top</span>
</a>
</span>
<br/>
<a id="symbolless"></a>
<h2>symbolLess</h2>
<span class="inline-text">void</span>
<span class="bold-text"><b>symbolLess</b></span>
<span class="italic-text"><i>(</i></span>
<span class="italic-text"><i>)</i></span>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Compiler/Generator/VmEmitter.h#L119" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">VmEmitter.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Compiler/Generator/VmEmitter.cpp#L208" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">VmEmitter.cpp</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#vmemitter" class="icon-list-item"><img src="../images/jumpToTop.svg" class="icon-list-item"/><span class="icon-list-item">top</span>
</a>
</span>
<br/>
<a id="symbolneg"></a>
<h2>symbolNeg</h2>
<span class="inline-text">void</span>
<span class="bold-text"><b>symbolNeg</b></span>
<span class="italic-text"><i>(</i></span>
<span class="italic-text"><i>)</i></span>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Compiler/Generator/VmEmitter.h#L123" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">VmEmitter.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Compiler/Generator/VmEmitter.cpp#L183" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">VmEmitter.cpp</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#vmemitter" class="icon-list-item"><img src="../images/jumpToTop.svg" class="icon-list-item"/><span class="icon-list-item">top</span>
</a>
</span>
<br/>
<a id="symbolnot"></a>
<h2>symbolNot</h2>
<span class="inline-text">void</span>
<span class="bold-text"><b>symbolNot</b></span>
<span class="italic-text"><i>(</i></span>
<span class="italic-text"><i>)</i></span>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Compiler/Generator/VmEmitter.h#L115" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">VmEmitter.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Compiler/Generator/VmEmitter.cpp#L198" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">VmEmitter.cpp</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#vmemitter" class="icon-list-item"><img src="../images/jumpToTop.svg" class="icon-list-item"/><span class="icon-list-item">top</span>
</a>
</span>
<br/>
<a id="symbolor"></a>
<h2>symbolOr</h2>
<span class="inline-text">void</span>
<span class="bold-text"><b>symbolOr</b></span>
<span class="italic-text"><i>(</i></span>
<span class="italic-text"><i>)</i></span>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Compiler/Generator/VmEmitter.h#L113" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">VmEmitter.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Compiler/Generator/VmEmitter.cpp#L193" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">VmEmitter.cpp</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#vmemitter" class="icon-list-item"><img src="../images/jumpToTop.svg" class="icon-list-item"/><span class="icon-list-item">top</span>
</a>
</span>
<br/>
<a id="symbolsub"></a>
<h2>symbolSub</h2>
<span class="inline-text">void</span>
<span class="bold-text"><b>symbolSub</b></span>
<span class="italic-text"><i>(</i></span>
<span class="italic-text"><i>)</i></span>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Compiler/Generator/VmEmitter.h#L109" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">VmEmitter.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Compiler/Generator/VmEmitter.cpp#L178" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">VmEmitter.cpp</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#vmemitter" class="icon-list-item"><img src="../images/jumpToTop.svg" class="icon-list-item"/><span class="icon-list-item">top</span>
</a>
</span>
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
<span class="inline-text">id</span>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/horSpace24px.svg"/><span class="inline-text">size_t</span>
<span class="inline-text">size</span>
</span>
</div>
<span class="italic-text"><i>)</i></span>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Compiler/Generator/VmEmitter.h#L125" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">VmEmitter.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Compiler/Generator/VmEmitter.cpp#L218" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">VmEmitter.cpp</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#vmemitter" class="icon-list-item"><img src="../images/jumpToTop.svg" class="icon-list-item"/><span class="icon-list-item">top</span>
</a>
</span>
<br/>
<a id="writecode"></a>
<h2>writeCode</h2>
<span class="inline-text">void</span>
<span class="bold-text"><b>writeCode</b></span>
<span class="italic-text"><i>(</i></span>
<div class="paragraph">
<span class="paragraph"><img src="../images/horSpace24px.svg"/><span class="inline-text">int</span>
<span class="inline-text">type</span>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/horSpace24px.svg"/><span class="inline-text">const </span>
<a href="namespaceHack.md#string">String</a>
<span class="inline-text"> &amp;</span>
<span class="inline-text">code</span>
</span>
</div>
<span class="italic-text"><i>)</i></span>
<a id="references"></a>
<h4>References</h4>
<div class="paragraph">
<span class="paragraph"><img src="../images/class.svg"/><a href="namespaceHack_1_1Compiler.md#ruleinlinevm">RuleInlineVm</a>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/class.svg"/><a href="namespaceHack_1_1Compiler.md#ruleinlineasm">RuleInlineAsm</a>
</span>
</div>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Compiler/Generator/VmEmitter.h#L133" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">VmEmitter.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Compiler/Generator/VmEmitter.cpp#L240" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">VmEmitter.cpp</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#vmemitter" class="icon-list-item"><img src="../images/jumpToTop.svg" class="icon-list-item"/><span class="icon-list-item">top</span>
</a>
</span>
<br/>
<a id="writefield"></a>
<h2>writeField</h2>
<span class="inline-text">void</span>
<span class="bold-text"><b>writeField</b></span>
<span class="italic-text"><i>(</i></span>
<div class="paragraph">
<span class="paragraph"><img src="../images/horSpace24px.svg"/><span class="inline-text">const </span>
<a href="classHack_1_1Compiler_1_1CodeGenerator_1_1Symbol.md#symbol">Symbol</a>
<span class="inline-text"> &amp;</span>
<span class="inline-text">sym</span>
</span>
</div>
<span class="italic-text"><i>)</i></span>
<a id="references"></a>
<h4>References</h4>
<div class="paragraph">
<span class="paragraph"><img src="../images/class.svg"/><a href="classHack_1_1Compiler_1_1CodeGenerator_1_1Symbol.md#entry">entry</a>
</span>
</div>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Compiler/Generator/VmEmitter.h#L62" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">VmEmitter.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Compiler/Generator/VmEmitter.cpp#L65" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">VmEmitter.cpp</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#vmemitter" class="icon-list-item"><img src="../images/jumpToTop.svg" class="icon-list-item"/><span class="icon-list-item">top</span>
</a>
</span>
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
<span class="paragraph"><img src="../images/horSpace24px.svg"/><span class="bold-text"><b>uint16_t</b></span>
<span class="inline-text">numParams</span>
</span>
</div>
<span class="italic-text"><i>)</i></span>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Compiler/Generator/VmEmitter.h#L64" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">VmEmitter.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Compiler/Generator/VmEmitter.cpp#L71" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">VmEmitter.cpp</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#vmemitter" class="icon-list-item"><img src="../images/jumpToTop.svg" class="icon-list-item"/><span class="icon-list-item">top</span>
</a>
</span>
<br/>
<a id="writegoto"></a>
<h2>writeGoto</h2>
<span class="inline-text">void</span>
<span class="bold-text"><b>writeGoto</b></span>
<span class="italic-text"><i>(</i></span>
<div class="paragraph">
<span class="paragraph"><img src="../images/horSpace24px.svg"/><span class="inline-text">const </span>
<a href="namespaceHack.md#string">String</a>
<span class="inline-text"> &amp;</span>
<span class="inline-text">label</span>
</span>
</div>
<span class="italic-text"><i>)</i></span>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Compiler/Generator/VmEmitter.h#L129" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">VmEmitter.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Compiler/Generator/VmEmitter.cpp#L229" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">VmEmitter.cpp</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#vmemitter" class="icon-list-item"><img src="../images/jumpToTop.svg" class="icon-list-item"/><span class="icon-list-item">top</span>
</a>
</span>
<br/>
<a id="writeifstart"></a>
<h2>writeIfStart</h2>
<span class="inline-text">void</span>
<span class="bold-text"><b>writeIfStart</b></span>
<span class="italic-text"><i>(</i></span>
<div class="paragraph">
<span class="paragraph"><img src="../images/horSpace24px.svg"/><span class="inline-text">const </span>
<a href="namespaceHack.md#string">String</a>
<span class="inline-text"> &amp;</span>
<span class="inline-text">label</span>
</span>
</div>
<span class="italic-text"><i>)</i></span>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Compiler/Generator/VmEmitter.h#L127" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">VmEmitter.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Compiler/Generator/VmEmitter.cpp#L223" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">VmEmitter.cpp</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#vmemitter" class="icon-list-item"><img src="../images/jumpToTop.svg" class="icon-list-item"/><span class="icon-list-item">top</span>
</a>
</span>
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
<span class="inline-text">label</span>
</span>
</div>
<span class="italic-text"><i>)</i></span>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Compiler/Generator/VmEmitter.h#L131" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">VmEmitter.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Compiler/Generator/VmEmitter.cpp#L234" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">VmEmitter.cpp</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#vmemitter" class="icon-list-item"><img src="../images/jumpToTop.svg" class="icon-list-item"/><span class="icon-list-item">top</span>
</a>
</span>
<br/>
<a id="writemethod"></a>
<h2>writeMethod</h2>
<span class="inline-text">void</span>
<span class="bold-text"><b>writeMethod</b></span>
<span class="italic-text"><i>(</i></span>
<div class="paragraph">
<span class="paragraph"><img src="../images/horSpace24px.svg"/><span class="inline-text">const </span>
<a href="namespaceHack.md#string">String</a>
<span class="inline-text"> &amp;</span>
<span class="inline-text">className</span>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/horSpace24px.svg"/><span class="inline-text">const </span>
<a href="namespaceHack.md#string">String</a>
<span class="inline-text"> &amp;</span>
<span class="inline-text">methodName</span>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/horSpace24px.svg"/><span class="bold-text"><b>uint16_t</b></span>
<span class="inline-text">numParams</span>
</span>
</div>
<span class="italic-text"><i>)</i></span>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Compiler/Generator/VmEmitter.h#L66" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">VmEmitter.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Compiler/Generator/VmEmitter.cpp#L76" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">VmEmitter.cpp</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#vmemitter" class="icon-list-item"><img src="../images/jumpToTop.svg" class="icon-list-item"/><span class="icon-list-item">top</span>
</a>
</span>
<br/>
<a id="writereturn"></a>
<h2>writeReturn</h2>
<span class="inline-text">void</span>
<span class="bold-text"><b>writeReturn</b></span>
<span class="italic-text"><i>(</i></span>
<span class="italic-text"><i>)</i></span>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Compiler/Generator/VmEmitter.h#L105" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">VmEmitter.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Compiler/Generator/VmEmitter.cpp#L168" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">VmEmitter.cpp</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#vmemitter" class="icon-list-item"><img src="../images/jumpToTop.svg" class="icon-list-item"/><span class="icon-list-item">top</span>
</a>
</span>
<br/>
<a id="writestatic"></a>
<h2>writeStatic</h2>
<span class="inline-text">void</span>
<span class="bold-text"><b>writeStatic</b></span>
<span class="italic-text"><i>(</i></span>
<div class="paragraph">
<span class="paragraph"><img src="../images/horSpace24px.svg"/><span class="inline-text">const </span>
<a href="classHack_1_1Compiler_1_1CodeGenerator_1_1Symbol.md#symbol">Symbol</a>
<span class="inline-text"> &amp;</span>
<span class="inline-text">sym</span>
</span>
</div>
<span class="italic-text"><i>)</i></span>
<a id="references"></a>
<h4>References</h4>
<div class="paragraph">
<span class="paragraph"><img src="../images/class.svg"/><a href="classHack_1_1Compiler_1_1CodeGenerator_1_1Symbol.md#entry">entry</a>
</span>
</div>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Compiler/Generator/VmEmitter.h#L60" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">VmEmitter.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Compiler/Generator/VmEmitter.cpp#L59" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">VmEmitter.cpp</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#vmemitter" class="icon-list-item"><img src="../images/jumpToTop.svg" class="icon-list-item"/><span class="icon-list-item">top</span>
</a>
</span>
<br/>
</div>
</div>
</body>
</html>
