<a id="chip"></a>
<h1>Chip</h1>
<a id="classhack_1_1chips_1_1chip"></a>
<a href="https://github.com/CharlesCarley/HackComputer#~">~</a>
<a href="indexpage.md#hack">Hack</a>
<span class="inline-text">/</span>
<a href="index.md#index">Index</a>
<span class="inline-text">/</span>
<a href="namespaceHack.md#hack">Hack</a>
<span class="inline-text">::</span>
<a href="namespaceHack_1_1Chips.md#chips">Chips</a>
<span class="inline-text">::</span>
<span class="bold-text"><b>Chip</b></span>
<br/>
<br/>
<a href="classHack_1_1Chips_1_1Chip.md#chip">Chip</a>
<span class="inline-text"> is the base class for all chips defined in this system. It uses a template integer for the </span>
<span class="bold-text"><b>_bits</b></span>
<span class="inline-text"> member variable. Most chips should maintain a cache bit (usually the MSB) to control evaluation. Evaluation happens as follows: </span>
<br/>
<a id="protected-members"></a>
<h2>Protected Members</h2>
<span class="icon-list-item"><a href="#_bits" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">_bits</span>
</a>
</span>
<br/>
<a id="protected-methods"></a>
<h2>Protected Methods</h2>
<span class="icon-list-item"><a href="#isdirty" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">isDirty</span>
</a>
</span>
<br/>
<a id="public-methods"></a>
<h2>Public Methods</h2>
<span class="icon-list-item"><a href="#chip" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">Chip</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#~chip" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">~Chip</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#applybit" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">applyBit</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#assignbit" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">assignBit</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#clearbit" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">clearBit</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#getbit" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">getBit</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#setbit" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">setBit</span>
</a>
</span>
<br/>
<a id="details"></a>
<h2>Details</h2>
<ul>
<li><span class="inline-text">If the input of the chip is modified mark the cache bit.</span>
</li>
<li><span class="inline-text">Any call to query an output should check this bit. a. If it is set call evaluate then return the output. b. If it is not set then return the output. </span>
</li>
</ul>
<ul>
<li><span class="bold-text"><b>T</b></span>
<span class="inline-text"> - </span>
<span class="inline-text">Should be one of the uint8_t, uint16_t, uint32_t, uint64_t, </span>
<a href="unionHack_1_1Chips_1_1bit16__t.md#bit16_t">bit16_t</a>
<span class="inline-text">, </span>
<a href="unionHack_1_1Chips_1_1bit32__t.md#bit32_t">bit32_t</a>
<span class="inline-text">, or </span>
<a href="unionHack_1_1Chips_1_1bit64__t.md#bit64_t">bit64_t</a>
<span class="inline-text"> integer types. </span>
</li>
<li><span class="bold-text"><b>Count</b></span>
<span class="inline-text"> - </span>
<span class="inline-text">Should reflect the total number of bits stored in T. </span>
</li>
</ul>
<br/>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Chips/Chip.h#L48" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Chip.h</span>
</a>
</span>
<br/>
<br/>
<blockquote>
<span class="icon-list-item"><a href="#chip" class="icon-list-item"><img src="../images/jumpToTop.svg" class="icon-list-item"/><span class="icon-list-item">top</span>
</a>
</span>
</blockquote>
<a id="_bits"></a>
<h2>_bits</h2>
<span class="inline-text">T</span>
<span class="bold-text"><b>_bits</b></span>
<br/>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Chips/Chip.h#L52" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Chip.h</span>
</a>
</span>
<br/>
<br/>
<blockquote>
<span class="icon-list-item"><a href="#chip" class="icon-list-item"><img src="../images/jumpToTop.svg" class="icon-list-item"/><span class="icon-list-item">top</span>
</a>
</span>
</blockquote>
<br/>
<a id="isdirty"></a>
<h2>isDirty</h2>
<span class="inline-text">bool</span>
<span class="bold-text"><b>isDirty</b></span>
<span class="italic-text"><i>(</i></span>
<span class="italic-text"><i>)</i></span>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Chips/Chip.h#L50" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Chip.h</span>
</a>
</span>
<br/>
<br/>
<blockquote>
<span class="icon-list-item"><a href="#chip" class="icon-list-item"><img src="../images/jumpToTop.svg" class="icon-list-item"/><span class="icon-list-item">top</span>
</a>
</span>
</blockquote>
<br/>
<a id="chip"></a>
<h2>Chip</h2>
<span class="bold-text"><b>Chip</b></span>
<span class="italic-text"><i>(</i></span>
<span class="italic-text"><i>)</i></span>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Chips/Chip.h#L55" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Chip.h</span>
</a>
</span>
<br/>
<br/>
<blockquote>
<span class="icon-list-item"><a href="#chip" class="icon-list-item"><img src="../images/jumpToTop.svg" class="icon-list-item"/><span class="icon-list-item">top</span>
</a>
</span>
</blockquote>
<br/>
<a id="~chip"></a>
<h2>~Chip</h2>
<span class="bold-text"><b>~Chip</b></span>
<span class="italic-text"><i>(</i></span>
<span class="italic-text"><i>)</i></span>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Chips/Chip.h#L57" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Chip.h</span>
</a>
</span>
<br/>
<br/>
<blockquote>
<span class="icon-list-item"><a href="#chip" class="icon-list-item"><img src="../images/jumpToTop.svg" class="icon-list-item"/><span class="icon-list-item">top</span>
</a>
</span>
</blockquote>
<br/>
<a id="applybit"></a>
<h2>applyBit</h2>
<span class="inline-text">void</span>
<span class="bold-text"><b>applyBit</b></span>
<span class="italic-text"><i>(</i></span>
<div class="paragraph">
<span class="paragraph"><img src="../images/horSpace24px.svg"/><span class="inline-text">const </span>
<span class="bold-text"><b>uint8_t</b></span>
<span class="inline-text"> &amp;</span>
<span class="inline-text">index</span>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/horSpace24px.svg"/><span class="inline-text">const bool</span>
<span class="inline-text">value</span>
</span>
</div>
<span class="italic-text"><i>)</i></span>
<a id="details"></a>
<h4>Details</h4>
<span class="inline-text">Clears or sets the bit at the supplied index. </span>
<br/>
<br/>
<ul>
<li><span class="bold-text"><b>index</b></span>
<span class="inline-text"> - </span>
</li>
<li><span class="bold-text"><b>value</b></span>
<span class="inline-text"> - </span>
<span class="inline-text">A value of true will set the bit.</span>
</li>
</ul>
<br/>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Chips/Chip.h#L84" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Chip.h</span>
</a>
</span>
<br/>
<br/>
<blockquote>
<span class="icon-list-item"><a href="#chip" class="icon-list-item"><img src="../images/jumpToTop.svg" class="icon-list-item"/><span class="icon-list-item">top</span>
</a>
</span>
</blockquote>
<br/>
<a id="assignbit"></a>
<h2>assignBit</h2>
<span class="inline-text">void</span>
<span class="bold-text"><b>assignBit</b></span>
<span class="italic-text"><i>(</i></span>
<div class="paragraph">
<span class="paragraph"><img src="../images/horSpace24px.svg"/><span class="inline-text">const </span>
<span class="bold-text"><b>uint8_t</b></span>
<span class="inline-text"> &amp;</span>
<span class="inline-text">index</span>
</span>
</div>
<span class="italic-text"><i>)</i></span>
<a id="details"></a>
<h4>Details</h4>
<span class="inline-text">Zeros all bits except for the bit at the supplied index. </span>
<br/>
<br/>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Chips/Chip.h#L72" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Chip.h</span>
</a>
</span>
<br/>
<br/>
<blockquote>
<span class="icon-list-item"><a href="#chip" class="icon-list-item"><img src="../images/jumpToTop.svg" class="icon-list-item"/><span class="icon-list-item">top</span>
</a>
</span>
</blockquote>
<br/>
<a id="clearbit"></a>
<h2>clearBit</h2>
<span class="inline-text">void</span>
<span class="bold-text"><b>clearBit</b></span>
<span class="italic-text"><i>(</i></span>
<div class="paragraph">
<span class="paragraph"><img src="../images/horSpace24px.svg"/><span class="inline-text">const </span>
<span class="bold-text"><b>uint8_t</b></span>
<span class="inline-text"> &amp;</span>
<span class="inline-text">index</span>
</span>
</div>
<span class="italic-text"><i>)</i></span>
<a id="details"></a>
<h4>Details</h4>
<span class="inline-text">Clears the bit at the supplied index. </span>
<br/>
<br/>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Chips/Chip.h#L77" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Chip.h</span>
</a>
</span>
<br/>
<br/>
<blockquote>
<span class="icon-list-item"><a href="#chip" class="icon-list-item"><img src="../images/jumpToTop.svg" class="icon-list-item"/><span class="icon-list-item">top</span>
</a>
</span>
</blockquote>
<br/>
<a id="getbit"></a>
<h2>getBit</h2>
<span class="inline-text">bool</span>
<span class="bold-text"><b>getBit</b></span>
<span class="italic-text"><i>(</i></span>
<div class="paragraph">
<span class="paragraph"><img src="../images/horSpace24px.svg"/><span class="inline-text">const </span>
<span class="bold-text"><b>uint8_t</b></span>
<span class="inline-text"> &amp;</span>
<span class="inline-text">index</span>
</span>
</div>
<span class="italic-text"><i>)</i></span>
<a id="details"></a>
<h4>Details</h4>
<span class="inline-text">Returns the state of the bit at the supplied index. </span>
<br/>
<br/>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Chips/Chip.h#L62" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Chip.h</span>
</a>
</span>
<br/>
<br/>
<blockquote>
<span class="icon-list-item"><a href="#chip" class="icon-list-item"><img src="../images/jumpToTop.svg" class="icon-list-item"/><span class="icon-list-item">top</span>
</a>
</span>
</blockquote>
<br/>
<a id="setbit"></a>
<h2>setBit</h2>
<span class="inline-text">void</span>
<span class="bold-text"><b>setBit</b></span>
<span class="italic-text"><i>(</i></span>
<div class="paragraph">
<span class="paragraph"><img src="../images/horSpace24px.svg"/><span class="inline-text">const </span>
<span class="bold-text"><b>uint8_t</b></span>
<span class="inline-text"> &amp;</span>
<span class="inline-text">index</span>
</span>
</div>
<span class="italic-text"><i>)</i></span>
<a id="details"></a>
<h4>Details</h4>
<span class="inline-text">Sets the bit at the supplied index. </span>
<br/>
<br/>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Chips/Chip.h#L67" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Chip.h</span>
</a>
</span>
<br/>
<br/>
<blockquote>
<span class="icon-list-item"><a href="#chip" class="icon-list-item"><img src="../images/jumpToTop.svg" class="icon-list-item"/><span class="icon-list-item">top</span>
</a>
</span>
</blockquote>
<br/>
<br/>
<blockquote>
<img src="../images/debug.svg"/><span class="inline-text">The following sources were used to generate this page.</span>
<br/>
<span class="icon-list-item"><a href="../xml/classHack_1_1Chips_1_1Chip.xml#L1" class="icon-list-item"><img src="../images/lookInside.svg" class="icon-list-item"/><span class="icon-list-item">classHack_1_1Chips_1_1Chip.xml</span>
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