<a id="runtimeinterface"></a>
<h1>RuntimeInterface</h1>
<a id="classhack_1_1computer_1_1runtimeinterface"></a>
<a href="https://github.com/CharlesCarley/HackComputer#~">~</a>
<a href="index.md#index">HackComputer</a>
<span class="inline-text">/</span>
<a href="namespaceHack.md#hack">Hack</a>
<span class="inline-text">::</span>
<a href="namespaceHack_1_1Computer.md#computer">Computer</a>
<span class="inline-text">::</span>
<span class="bold-text"><b>RuntimeInterface</b></span>
<br/>
<br/>
<a id="derived-by"></a>
<h4>Derived By</h4>
<div class="icon-link">
<img src="../images/class.svg"/><a href="classHack_1_1Computer_1_1AssemblyDebugger.md#assemblydebugger">Hack::Computer::AssemblyDebugger</a>
</div>
<div class="icon-link">
<img src="../images/class.svg"/><a href="classHack_1_1Computer_1_1ConsoleRuntime.md#consoleruntime">Hack::Computer::ConsoleRuntime</a>
</div>
<img src="../images/dot/internal-diagram-44.dot.svg"/><br/>
<a id="public-methods"></a>
<h2>Public Methods</h2>
<span class="icon-list-item"><a href="#~runtimeinterface" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">~RuntimeInterface</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#exitrequest" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">exitRequest</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#flushmemory" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">flushMemory</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#getrate" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">getRate</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#initialize" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">initialize</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#processevents" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">processEvents</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#setinstructions" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">setInstructions</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#setrate" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">setRate</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#shouldupdate" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">shouldUpdate</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#update" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">update</span>
</a>
</span>
<br/>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/F:/HackComputer/Source/Computer/RuntimeInterface.h#L30" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">RuntimeInterface.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#runtimeinterface" class="icon-list-item"><img src="../images/jumpToTop.svg" class="icon-list-item"/><span class="icon-list-item">top</span>
</a>
</span>
<a id="~runtimeinterface"></a>
<h2>~RuntimeInterface</h2>
<span class="bold-text"><b>~RuntimeInterface</b></span>
<span class="italic-text"><i>(</i></span>
<span class="italic-text"><i>)</i></span>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/F:/HackComputer/Source/Computer/RuntimeInterface.h#L32" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">RuntimeInterface.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#runtimeinterface" class="icon-list-item"><img src="../images/jumpToTop.svg" class="icon-list-item"/><span class="icon-list-item">top</span>
</a>
</span>
<br/>
<a id="exitrequest"></a>
<h2>exitRequest</h2>
<span class="inline-text">bool</span>
<span class="bold-text"><b>exitRequest</b></span>
<span class="italic-text"><i>(</i></span>
<span class="italic-text"><i>)</i></span>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/F:/HackComputer/Source/Computer/RuntimeInterface.h#L42" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">RuntimeInterface.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#runtimeinterface" class="icon-list-item"><img src="../images/jumpToTop.svg" class="icon-list-item"/><span class="icon-list-item">top</span>
</a>
</span>
<br/>
<a id="flushmemory"></a>
<h2>flushMemory</h2>
<span class="inline-text">void</span>
<span class="bold-text"><b>flushMemory</b></span>
<span class="italic-text"><i>(</i></span>
<div class="paragraph">
<span class="paragraph"><img src="../images/horSpace24px.svg"/><a href="classHack_1_1Chips_1_1Computer.md#computer">Chips::Computer</a>
<span class="inline-text"> *</span>
<span class="inline-text">computer</span>
</span>
</div>
<span class="italic-text"><i>)</i></span>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/F:/HackComputer/Source/Computer/RuntimeInterface.h#L46" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">RuntimeInterface.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#runtimeinterface" class="icon-list-item"><img src="../images/jumpToTop.svg" class="icon-list-item"/><span class="icon-list-item">top</span>
</a>
</span>
<br/>
<a id="getrate"></a>
<h2>getRate</h2>
<span class="inline-text">int16_t</span>
<span class="bold-text"><b>getRate</b></span>
<span class="italic-text"><i>(</i></span>
<span class="italic-text"><i>)</i></span>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/F:/HackComputer/Source/Computer/RuntimeInterface.h#L36" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">RuntimeInterface.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#runtimeinterface" class="icon-list-item"><img src="../images/jumpToTop.svg" class="icon-list-item"/><span class="icon-list-item">top</span>
</a>
</span>
<br/>
<a id="initialize"></a>
<h2>initialize</h2>
<span class="inline-text">void</span>
<span class="bold-text"><b>initialize</b></span>
<span class="italic-text"><i>(</i></span>
<div class="paragraph">
<span class="paragraph"><img src="../images/horSpace24px.svg"/><a href="classHack_1_1Chips_1_1Computer.md#computer">Chips::Computer</a>
<span class="inline-text"> *</span>
<span class="inline-text">computer</span>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/horSpace24px.svg"/><a href="namespaceHack_1_1Chips.md#screen">Chips::Screen</a>
<span class="inline-text"> *</span>
<span class="inline-text">screen</span>
</span>
</div>
<span class="italic-text"><i>)</i></span>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/F:/HackComputer/Source/Computer/RuntimeInterface.h#L40" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">RuntimeInterface.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#runtimeinterface" class="icon-list-item"><img src="../images/jumpToTop.svg" class="icon-list-item"/><span class="icon-list-item">top</span>
</a>
</span>
<br/>
<a id="processevents"></a>
<h2>processEvents</h2>
<span class="inline-text">void</span>
<span class="bold-text"><b>processEvents</b></span>
<span class="italic-text"><i>(</i></span>
<div class="paragraph">
<span class="paragraph"><img src="../images/horSpace24px.svg"/><a href="classHack_1_1Chips_1_1Computer.md#computer">Chips::Computer</a>
<span class="inline-text"> *</span>
<span class="inline-text">computer</span>
</span>
</div>
<span class="italic-text"><i>)</i></span>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/F:/HackComputer/Source/Computer/RuntimeInterface.h#L44" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">RuntimeInterface.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#runtimeinterface" class="icon-list-item"><img src="../images/jumpToTop.svg" class="icon-list-item"/><span class="icon-list-item">top</span>
</a>
</span>
<br/>
<a id="setinstructions"></a>
<h2>setInstructions</h2>
<span class="inline-text">void</span>
<span class="bold-text"><b>setInstructions</b></span>
<span class="italic-text"><i>(</i></span>
<div class="paragraph">
<span class="paragraph"><img src="../images/horSpace24px.svg"/><span class="inline-text">const </span>
<a href="classHack_1_1Assembler_1_1Parser.md#instructions">Assembler::Parser::Instructions</a>
<span class="inline-text"> &amp;</span>
<span class="inline-text">is</span>
</span>
</div>
<span class="italic-text"><i>)</i></span>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/F:/HackComputer/Source/Computer/RuntimeInterface.h#L50" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">RuntimeInterface.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#runtimeinterface" class="icon-list-item"><img src="../images/jumpToTop.svg" class="icon-list-item"/><span class="icon-list-item">top</span>
</a>
</span>
<br/>
<a id="setrate"></a>
<h2>setRate</h2>
<span class="inline-text">void</span>
<span class="bold-text"><b>setRate</b></span>
<span class="italic-text"><i>(</i></span>
<div class="paragraph">
<span class="paragraph"><img src="../images/horSpace24px.svg"/><span class="inline-text">int16_t</span>
<span class="inline-text">v</span>
</span>
</div>
<span class="italic-text"><i>)</i></span>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/F:/HackComputer/Source/Computer/RuntimeInterface.h#L38" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">RuntimeInterface.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#runtimeinterface" class="icon-list-item"><img src="../images/jumpToTop.svg" class="icon-list-item"/><span class="icon-list-item">top</span>
</a>
</span>
<br/>
<a id="shouldupdate"></a>
<h2>shouldUpdate</h2>
<span class="inline-text">bool</span>
<span class="bold-text"><b>shouldUpdate</b></span>
<span class="italic-text"><i>(</i></span>
<span class="italic-text"><i>)</i></span>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/F:/HackComputer/Source/Computer/RuntimeInterface.h#L34" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">RuntimeInterface.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#runtimeinterface" class="icon-list-item"><img src="../images/jumpToTop.svg" class="icon-list-item"/><span class="icon-list-item">top</span>
</a>
</span>
<br/>
<a id="update"></a>
<h2>update</h2>
<span class="inline-text">void</span>
<span class="bold-text"><b>update</b></span>
<span class="italic-text"><i>(</i></span>
<div class="paragraph">
<span class="paragraph"><img src="../images/horSpace24px.svg"/><a href="classHack_1_1Chips_1_1Computer.md#computer">Chips::Computer</a>
<span class="inline-text"> *</span>
<span class="inline-text">computer</span>
</span>
</div>
<span class="italic-text"><i>)</i></span>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/F:/HackComputer/Source/Computer/RuntimeInterface.h#L48" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">RuntimeInterface.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#runtimeinterface" class="icon-list-item"><img src="../images/jumpToTop.svg" class="icon-list-item"/><span class="icon-list-item">top</span>
</a>
</span>
<br/>
</div>
</div>
</body>
</html>
