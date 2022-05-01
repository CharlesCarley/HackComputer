<a id="memory"></a>
<h1>Memory</h1>
<a id="classhack_1_1chips_1_1memory"></a>
<a href="https://github.com/CharlesCarley/HackComputer#~">~</a>
<a href="index.md#index">HackComputer</a>
<span class="inline-text">/</span>
<a href="namespaceHack.md#hack">Hack</a>
<span class="inline-text">::</span>
<a href="namespaceHack_1_1Chips.md#chips">Chips</a>
<span class="inline-text">::</span>
<span class="bold-text"><b>Memory</b></span>
<br/>
<br/>
<a id="derived-from"></a>
<h4>Derived From</h4>
<div class="icon-link">
<img src="../images/class.svg"/><a href="classHack_1_1Chips_1_1Chip.md#chip">Hack::Chips::Chip&lt; uint8_t, 8 &gt;</a>
</div>
<img src="../images/dot/internal-diagram-19.dot.svg"/><br/>
<a id="public-static-members"></a>
<h2>Public Static Members</h2>
<span class="icon-list-item"><a href="#extensionaddress" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">ExtensionAddress</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#heapaddress" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">HeapAddress</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#maxaddress" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">MaxAddress</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#screenaddress" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">ScreenAddress</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#stackaddress" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">StackAddress</span>
</a>
</span>
<br/>
<a id="private-members"></a>
<h2>Private Members</h2>
<span class="icon-list-item"><a href="#_address" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">_address</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#_in" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">_in</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#_out" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">_out</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#_ram16" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">_ram16</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#_screen" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">_screen</span>
</a>
</span>
<br/>
<a id="private-methods"></a>
<h2>Private Methods</h2>
<span class="icon-list-item"><a href="#evaluate" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">evaluate</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#isdirty" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">isDirty</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#markdirty" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">markDirty</span>
</a>
</span>
<br/>
<a id="public-methods"></a>
<h2>Public Methods</h2>
<span class="icon-list-item"><a href="#memory" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">Memory</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#~memory" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">~Memory</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#get" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">get</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#getout" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">getOut</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#getscreen" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">getScreen</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#initializescreen" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">initializeScreen</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#lock" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">lock</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#pointer" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">pointer</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#setaddress" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">setAddress</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#setclock" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">setClock</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#setin" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">setIn</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#setload" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">setLoad</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#setvalue" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">setValue</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#zero" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">zero</span>
</a>
</span>
<br/>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Chips/Memory.h#L30" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Memory.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#memory" class="icon-list-item"><img src="../images/jumpToTop.svg" class="icon-list-item"/><span class="icon-list-item">top</span>
</a>
</span>
<a id="extensionaddress"></a>
<h2>ExtensionAddress</h2>
<span class="inline-text">const </span>
<span class="bold-text"><b>uint16_t</b></span>
<span class="bold-text"><b>ExtensionAddress</b></span>
<br/>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Chips/Memory.h#L36" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Memory.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#memory" class="icon-list-item"><img src="../images/jumpToTop.svg" class="icon-list-item"/><span class="icon-list-item">top</span>
</a>
</span>
<br/>
<a id="heapaddress"></a>
<h2>HeapAddress</h2>
<span class="inline-text">const </span>
<span class="bold-text"><b>uint16_t</b></span>
<span class="bold-text"><b>HeapAddress</b></span>
<br/>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Chips/Memory.h#L35" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Memory.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#memory" class="icon-list-item"><img src="../images/jumpToTop.svg" class="icon-list-item"/><span class="icon-list-item">top</span>
</a>
</span>
<br/>
<a id="maxaddress"></a>
<h2>MaxAddress</h2>
<span class="inline-text">const </span>
<span class="bold-text"><b>uint16_t</b></span>
<span class="bold-text"><b>MaxAddress</b></span>
<br/>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Chips/Memory.h#L32" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Memory.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#memory" class="icon-list-item"><img src="../images/jumpToTop.svg" class="icon-list-item"/><span class="icon-list-item">top</span>
</a>
</span>
<br/>
<a id="screenaddress"></a>
<h2>ScreenAddress</h2>
<span class="inline-text">const </span>
<span class="bold-text"><b>uint16_t</b></span>
<span class="bold-text"><b>ScreenAddress</b></span>
<br/>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Chips/Memory.h#L33" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Memory.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#memory" class="icon-list-item"><img src="../images/jumpToTop.svg" class="icon-list-item"/><span class="icon-list-item">top</span>
</a>
</span>
<br/>
<a id="stackaddress"></a>
<h2>StackAddress</h2>
<span class="inline-text">const </span>
<span class="bold-text"><b>uint16_t</b></span>
<span class="bold-text"><b>StackAddress</b></span>
<br/>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Chips/Memory.h#L34" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Memory.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#memory" class="icon-list-item"><img src="../images/jumpToTop.svg" class="icon-list-item"/><span class="icon-list-item">top</span>
</a>
</span>
<br/>
<a id="_address"></a>
<h2>_address</h2>
<span class="bold-text"><b>uint16_t</b></span>
<span class="bold-text"><b>_address</b></span>
<br/>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Chips/Memory.h#L45" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Memory.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#memory" class="icon-list-item"><img src="../images/jumpToTop.svg" class="icon-list-item"/><span class="icon-list-item">top</span>
</a>
</span>
<br/>
<a id="_in"></a>
<h2>_in</h2>
<span class="bold-text"><b>uint16_t</b></span>
<span class="bold-text"><b>_in</b></span>
<br/>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Chips/Memory.h#L43" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Memory.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#memory" class="icon-list-item"><img src="../images/jumpToTop.svg" class="icon-list-item"/><span class="icon-list-item">top</span>
</a>
</span>
<br/>
<a id="_out"></a>
<h2>_out</h2>
<span class="bold-text"><b>uint16_t</b></span>
<span class="bold-text"><b>_out</b></span>
<br/>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Chips/Memory.h#L44" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Memory.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#memory" class="icon-list-item"><img src="../images/jumpToTop.svg" class="icon-list-item"/><span class="icon-list-item">top</span>
</a>
</span>
<br/>
<a id="_ram16"></a>
<h2>_ram16</h2>
<a href="namespaceHack_1_1Chips.md#ram16k">Ram16k</a>
<span class="inline-text"> *</span>
<span class="bold-text"><b>_ram16</b></span>
<br/>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Chips/Memory.h#L47" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Memory.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#memory" class="icon-list-item"><img src="../images/jumpToTop.svg" class="icon-list-item"/><span class="icon-list-item">top</span>
</a>
</span>
<br/>
<a id="_screen"></a>
<h2>_screen</h2>
<a href="namespaceHack_1_1Chips.md#screen">Screen</a>
<span class="inline-text"> *</span>
<span class="bold-text"><b>_screen</b></span>
<br/>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Chips/Memory.h#L48" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Memory.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#memory" class="icon-list-item"><img src="../images/jumpToTop.svg" class="icon-list-item"/><span class="icon-list-item">top</span>
</a>
</span>
<br/>
<a id="evaluate"></a>
<h2>evaluate</h2>
<span class="inline-text">void</span>
<span class="bold-text"><b>evaluate</b></span>
<span class="italic-text"><i>(</i></span>
<span class="italic-text"><i>)</i></span>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Chips/Memory.h#L39" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Memory.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Chips/Memory.cpp#L155" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Memory.cpp</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#memory" class="icon-list-item"><img src="../images/jumpToTop.svg" class="icon-list-item"/><span class="icon-list-item">top</span>
</a>
</span>
<br/>
<a id="isdirty"></a>
<h2>isDirty</h2>
<span class="inline-text">bool</span>
<span class="bold-text"><b>isDirty</b></span>
<span class="italic-text"><i>(</i></span>
<span class="italic-text"><i>)</i></span>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Chips/Memory.h#L40" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Memory.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Chips/Memory.cpp#L145" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Memory.cpp</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#memory" class="icon-list-item"><img src="../images/jumpToTop.svg" class="icon-list-item"/><span class="icon-list-item">top</span>
</a>
</span>
<br/>
<a id="markdirty"></a>
<h2>markDirty</h2>
<span class="inline-text">void</span>
<span class="bold-text"><b>markDirty</b></span>
<span class="italic-text"><i>(</i></span>
<span class="italic-text"><i>)</i></span>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Chips/Memory.h#L41" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Memory.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Chips/Memory.cpp#L150" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Memory.cpp</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#memory" class="icon-list-item"><img src="../images/jumpToTop.svg" class="icon-list-item"/><span class="icon-list-item">top</span>
</a>
</span>
<br/>
<a id="memory"></a>
<h2>Memory</h2>
<span class="bold-text"><b>Memory</b></span>
<span class="italic-text"><i>(</i></span>
<span class="italic-text"><i>)</i></span>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Chips/Memory.h#L51" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Memory.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Chips/Memory.cpp#L31" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Memory.cpp</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#memory" class="icon-list-item"><img src="../images/jumpToTop.svg" class="icon-list-item"/><span class="icon-list-item">top</span>
</a>
</span>
<br/>
<a id="~memory"></a>
<h2>~Memory</h2>
<span class="bold-text"><b>~Memory</b></span>
<span class="italic-text"><i>(</i></span>
<span class="italic-text"><i>)</i></span>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Chips/Memory.h#L52" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Memory.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Chips/Memory.cpp#L40" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Memory.cpp</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#memory" class="icon-list-item"><img src="../images/jumpToTop.svg" class="icon-list-item"/><span class="icon-list-item">top</span>
</a>
</span>
<br/>
<a id="get"></a>
<h2>get</h2>
<span class="bold-text"><b>uint16_t</b></span>
<span class="bold-text"><b>get</b></span>
<span class="italic-text"><i>(</i></span>
<div class="paragraph">
<span class="paragraph"><img src="../images/horSpace24px.svg"/><span class="inline-text">const size_t &amp;</span>
<span class="inline-text">i</span>
</span>
</div>
<span class="italic-text"><i>)</i></span>
<a id="references"></a>
<h4>References</h4>
<div class="paragraph">
<span class="paragraph"><img src="../images/class.svg"/><a href="classHack_1_1Chips_1_1Memory.md#maxaddress">MaxAddress</a>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/class.svg"/><a href="classHack_1_1Chips_1_1Memory.md#screenaddress">ScreenAddress</a>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/class.svg"/><a href="classHack_1_1Chips_1_1DefaultMemorySegment.md#get">get</a>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/class.svg"/><a href="classHack_1_1Chips_1_1IMemorySegment.md#get">get</a>
</span>
</div>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Chips/Memory.h#L72" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Memory.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Chips/Memory.cpp#L121" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Memory.cpp</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#memory" class="icon-list-item"><img src="../images/jumpToTop.svg" class="icon-list-item"/><span class="icon-list-item">top</span>
</a>
</span>
<br/>
<a id="getout"></a>
<h2>getOut</h2>
<span class="bold-text"><b>uint16_t</b></span>
<span class="bold-text"><b>getOut</b></span>
<span class="italic-text"><i>(</i></span>
<span class="italic-text"><i>)</i></span>
<a id="references"></a>
<h4>References</h4>
<div class="paragraph">
<span class="paragraph"><img src="../images/class.svg"/><a href="classHack_1_1Chips_1_1Chip.md#_bits">_bits</a>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/class.svg"/><a href="namespaceHack_1_1Chips.md#bit7">Bit7</a>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/class.svg"/><a href="namespaceHack_1_1Chips.md#bit6">Bit6</a>
</span>
</div>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Chips/Memory.h#L70" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Memory.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Chips/Memory.cpp#L114" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Memory.cpp</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#memory" class="icon-list-item"><img src="../images/jumpToTop.svg" class="icon-list-item"/><span class="icon-list-item">top</span>
</a>
</span>
<br/>
<a id="getscreen"></a>
<h2>getScreen</h2>
<a href="namespaceHack_1_1Chips.md#screen">Screen</a>
<span class="inline-text"> *</span>
<span class="bold-text"><b>getScreen</b></span>
<span class="italic-text"><i>(</i></span>
<span class="italic-text"><i>)</i></span>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Chips/Memory.h#L54" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Memory.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Chips/Memory.cpp#L46" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Memory.cpp</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#memory" class="icon-list-item"><img src="../images/jumpToTop.svg" class="icon-list-item"/><span class="icon-list-item">top</span>
</a>
</span>
<br/>
<a id="initializescreen"></a>
<h2>initializeScreen</h2>
<span class="inline-text">void</span>
<span class="bold-text"><b>initializeScreen</b></span>
<span class="italic-text"><i>(</i></span>
<div class="paragraph">
<span class="paragraph"><img src="../images/horSpace24px.svg"/><a href="namespaceHack_1_1Chips.md#screen">Screen</a>
<span class="inline-text"> *</span>
<span class="inline-text">screen</span>
<span class="inline-text"> = </span>
<span class="inline-text">nullptr</span>
</span>
</div>
<span class="italic-text"><i>)</i></span>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Chips/Memory.h#L56" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Memory.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Chips/Memory.cpp#L51" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Memory.cpp</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#memory" class="icon-list-item"><img src="../images/jumpToTop.svg" class="icon-list-item"/><span class="icon-list-item">top</span>
</a>
</span>
<br/>
<a id="lock"></a>
<h2>lock</h2>
<span class="inline-text">void</span>
<span class="bold-text"><b>lock</b></span>
<span class="italic-text"><i>(</i></span>
<div class="paragraph">
<span class="paragraph"><img src="../images/horSpace24px.svg"/><span class="inline-text">bool</span>
<span class="inline-text">v</span>
</span>
</div>
<span class="italic-text"><i>)</i></span>
<a id="references"></a>
<h4>References</h4>
<div class="paragraph">
<span class="paragraph"><img src="../images/class.svg"/><a href="classHack_1_1Chips_1_1Chip.md#_bits">_bits</a>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/class.svg"/><a href="namespaceHack_1_1Chips.md#bit6">Bit6</a>
</span>
</div>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Chips/Memory.h#L68" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Memory.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Chips/Memory.cpp#L106" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Memory.cpp</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#memory" class="icon-list-item"><img src="../images/jumpToTop.svg" class="icon-list-item"/><span class="icon-list-item">top</span>
</a>
</span>
<br/>
<a id="pointer"></a>
<h2>pointer</h2>
<span class="bold-text"><b>uint16_t</b></span>
<span class="inline-text"> *</span>
<span class="bold-text"><b>pointer</b></span>
<span class="italic-text"><i>(</i></span>
<div class="paragraph">
<span class="paragraph"><img src="../images/horSpace24px.svg"/><span class="inline-text">const size_t &amp;</span>
<span class="inline-text">address</span>
</span>
</div>
<span class="italic-text"><i>)</i></span>
<a id="references"></a>
<h4>References</h4>
<div class="paragraph">
<span class="paragraph"><img src="../images/class.svg"/><a href="classHack_1_1Chips_1_1Memory.md#screenaddress">ScreenAddress</a>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/class.svg"/><a href="classHack_1_1Chips_1_1DefaultMemorySegment.md#pointer">pointer</a>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/class.svg"/><a href="classHack_1_1Chips_1_1IMemorySegment.md#pointer">pointer</a>
</span>
</div>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Chips/Memory.h#L74" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Memory.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Chips/Memory.cpp#L132" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Memory.cpp</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#memory" class="icon-list-item"><img src="../images/jumpToTop.svg" class="icon-list-item"/><span class="icon-list-item">top</span>
</a>
</span>
<br/>
<a id="setaddress"></a>
<h2>setAddress</h2>
<span class="inline-text">void</span>
<span class="bold-text"><b>setAddress</b></span>
<span class="italic-text"><i>(</i></span>
<div class="paragraph">
<span class="paragraph"><img src="../images/horSpace24px.svg"/><span class="inline-text">const </span>
<span class="bold-text"><b>uint16_t</b></span>
<span class="inline-text"> &amp;</span>
<span class="inline-text">v</span>
</span>
</div>
<span class="italic-text"><i>)</i></span>
<a id="references"></a>
<h4>References</h4>
<div class="paragraph">
<span class="paragraph"><img src="../images/class.svg"/><a href="classHack_1_1Chips_1_1Memory.md#maxaddress">MaxAddress</a>
</span>
</div>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Chips/Memory.h#L60" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Memory.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Chips/Memory.cpp#L71" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Memory.cpp</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#memory" class="icon-list-item"><img src="../images/jumpToTop.svg" class="icon-list-item"/><span class="icon-list-item">top</span>
</a>
</span>
<br/>
<a id="setclock"></a>
<h2>setClock</h2>
<span class="inline-text">void</span>
<span class="bold-text"><b>setClock</b></span>
<span class="italic-text"><i>(</i></span>
<div class="paragraph">
<span class="paragraph"><img src="../images/horSpace24px.svg"/><span class="inline-text">bool</span>
<span class="inline-text">v</span>
</span>
</div>
<span class="italic-text"><i>)</i></span>
<a id="references"></a>
<h4>References</h4>
<div class="paragraph">
<span class="paragraph"><img src="../images/class.svg"/><a href="classHack_1_1Chips_1_1Chip.md#_bits">_bits</a>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/class.svg"/><a href="namespaceHack_1_1Chips.md#bit1">Bit1</a>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/class.svg"/><a href="namespaceHack_1_1Chips.md#bit7">Bit7</a>
</span>
</div>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Chips/Memory.h#L66" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Memory.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Chips/Memory.cpp#L97" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Memory.cpp</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#memory" class="icon-list-item"><img src="../images/jumpToTop.svg" class="icon-list-item"/><span class="icon-list-item">top</span>
</a>
</span>
<br/>
<a id="setin"></a>
<h2>setIn</h2>
<span class="inline-text">void</span>
<span class="bold-text"><b>setIn</b></span>
<span class="italic-text"><i>(</i></span>
<div class="paragraph">
<span class="paragraph"><img src="../images/horSpace24px.svg"/><span class="inline-text">const </span>
<span class="bold-text"><b>uint16_t</b></span>
<span class="inline-text"> &amp;</span>
<span class="inline-text">v</span>
</span>
</div>
<span class="italic-text"><i>)</i></span>
<a id="references"></a>
<h4>References</h4>
<div class="paragraph">
<span class="paragraph"><img src="../images/class.svg"/><a href="classHack_1_1Chips_1_1Chip.md#_bits">_bits</a>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/class.svg"/><a href="namespaceHack_1_1Chips.md#bit7">Bit7</a>
</span>
</div>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Chips/Memory.h#L58" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Memory.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Chips/Memory.cpp#L62" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Memory.cpp</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#memory" class="icon-list-item"><img src="../images/jumpToTop.svg" class="icon-list-item"/><span class="icon-list-item">top</span>
</a>
</span>
<br/>
<a id="setload"></a>
<h2>setLoad</h2>
<span class="inline-text">void</span>
<span class="bold-text"><b>setLoad</b></span>
<span class="italic-text"><i>(</i></span>
<div class="paragraph">
<span class="paragraph"><img src="../images/horSpace24px.svg"/><span class="inline-text">bool</span>
<span class="inline-text">v</span>
</span>
</div>
<span class="italic-text"><i>)</i></span>
<a id="references"></a>
<h4>References</h4>
<div class="paragraph">
<span class="paragraph"><img src="../images/class.svg"/><a href="classHack_1_1Chips_1_1Chip.md#_bits">_bits</a>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/class.svg"/><a href="namespaceHack_1_1Chips.md#bit0">Bit0</a>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/class.svg"/><a href="namespaceHack_1_1Chips.md#bit7">Bit7</a>
</span>
</div>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Chips/Memory.h#L64" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Memory.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Chips/Memory.cpp#L88" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Memory.cpp</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#memory" class="icon-list-item"><img src="../images/jumpToTop.svg" class="icon-list-item"/><span class="icon-list-item">top</span>
</a>
</span>
<br/>
<a id="setvalue"></a>
<h2>setValue</h2>
<span class="inline-text">void</span>
<span class="bold-text"><b>setValue</b></span>
<span class="italic-text"><i>(</i></span>
<div class="paragraph">
<span class="paragraph"><img src="../images/horSpace24px.svg"/><span class="inline-text">const size_t &amp;</span>
<span class="inline-text">index</span>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/horSpace24px.svg"/><span class="inline-text">const </span>
<span class="bold-text"><b>uint16_t</b></span>
<span class="inline-text"> &amp;</span>
<span class="inline-text">v</span>
</span>
</div>
<span class="italic-text"><i>)</i></span>
<a id="references"></a>
<h4>References</h4>
<div class="paragraph">
<span class="paragraph"><img src="../images/class.svg"/><a href="classHack_1_1Chips_1_1Memory.md#maxaddress">MaxAddress</a>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/class.svg"/><a href="classHack_1_1Chips_1_1Memory.md#screenaddress">ScreenAddress</a>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/class.svg"/><a href="classHack_1_1Chips_1_1DefaultMemorySegment.md#setvalue">setValue</a>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/class.svg"/><a href="classHack_1_1Chips_1_1IMemorySegment.md#setvalue">setValue</a>
</span>
</div>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Chips/Memory.h#L62" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Memory.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Chips/Memory.cpp#L77" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Memory.cpp</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#memory" class="icon-list-item"><img src="../images/jumpToTop.svg" class="icon-list-item"/><span class="icon-list-item">top</span>
</a>
</span>
<br/>
<a id="zero"></a>
<h2>zero</h2>
<span class="inline-text">void</span>
<span class="bold-text"><b>zero</b></span>
<span class="italic-text"><i>(</i></span>
<span class="italic-text"><i>)</i></span>
<a id="references"></a>
<h4>References</h4>
<div class="paragraph">
<span class="paragraph"><img src="../images/class.svg"/><a href="classHack_1_1Chips_1_1DefaultMemorySegment.md#zero">zero</a>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/class.svg"/><a href="classHack_1_1Chips_1_1IMemorySegment.md#zero">zero</a>
</span>
</div>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Chips/Memory.h#L76" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Memory.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Chips/Memory.cpp#L139" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Memory.cpp</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#memory" class="icon-list-item"><img src="../images/jumpToTop.svg" class="icon-list-item"/><span class="icon-list-item">top</span>
</a>
</span>
<br/>
</div>
</div>
</body>
</html>
