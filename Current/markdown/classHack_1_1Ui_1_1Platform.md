<a id="platform"></a>
<h1>Platform</h1>
<a id="classhack_1_1ui_1_1platform"></a>
<a href="https://github.com/CharlesCarley/HackComputer#~">~</a>
<a href="indexpage.md#hack">Hack</a>
<span class="inline-text">/</span>
<a href="index.md#index">Index</a>
<span class="inline-text">/</span>
<a href="namespaceHack.md#hack">Hack</a>
<span class="inline-text">::</span>
<a href="namespaceHack_1_1Ui.md#ui">Ui</a>
<span class="inline-text">::</span>
<span class="bold-text"><b>Platform</b></span>
<br/>
<br/>
<a id="derived-by"></a>
<h4>Derived By</h4>
<div class="icon-link">
<img src="../images/class.svg"/><a href="classHack_1_1Ui_1_1PlatformUnix.md#platformunix">Hack::Ui::PlatformUnix</a>
</div>
<img src="../images/dot/internal-diagram-49.dot.svg"/><br/>
<a id="public-typedefs"></a>
<h2>Public Typedefs</h2>
<span class="icon-list-item"><a href="#colorcache" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">ColorCache</span>
</a>
</span>
<br/>
<a id="private-members"></a>
<h2>Private Members</h2>
<span class="icon-list-item"><a href="#_cache" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">_cache</span>
</a>
</span>
<br/>
<a id="public-methods"></a>
<h2>Public Methods</h2>
<span class="icon-list-item"><a href="#platform" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">Platform</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#~platform" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">~Platform</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#clear" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">clear</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#color" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">color</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#flush" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">flush</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#getscreensize" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">getScreenSize</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#poll" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">poll</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#put" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">put</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#put" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">put</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#resetcolor" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">resetColor</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#resetcursor" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">resetCursor</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#setcursor" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">setCursor</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#showcursor" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">showCursor</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#usebackbuffer" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">useBackBuffer</span>
</a>
</span>
<br/>
<a id="public-static-methods"></a>
<h2>Public Static Methods</h2>
<span class="icon-list-item"><a href="#sleep" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">sleep</span>
</a>
</span>
<br/>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Utils/UserInterface/Platform.h#L53" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Platform.h</span>
</a>
</span>
<br/>
<br/>
<blockquote>
<span class="icon-list-item"><a href="#platform" class="icon-list-item"><img src="../images/jumpToTop.svg" class="icon-list-item"/><span class="icon-list-item">top</span>
</a>
</span>
</blockquote>
<a id="colorcache"></a>
<h2>ColorCache</h2>
<span class="inline-text">std::unordered_map&lt; </span>
<span class="bold-text"><b>uint8_t</b></span>
<span class="inline-text">, </span>
<a href="classHack_1_1Ui_1_1ColorCacheItem.md#colorcacheitem">ColorCacheItem</a>
<span class="inline-text"> * &gt;</span>
<span class="bold-text"><b>ColorCache</b></span>
<br/>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Utils/UserInterface/Platform.h#L55" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Platform.h</span>
</a>
</span>
<br/>
<br/>
<blockquote>
<span class="icon-list-item"><a href="#platform" class="icon-list-item"><img src="../images/jumpToTop.svg" class="icon-list-item"/><span class="icon-list-item">top</span>
</a>
</span>
</blockquote>
<br/>
<a id="_cache"></a>
<h2>_cache</h2>
<a href="classHack_1_1Ui_1_1Platform.md#colorcache">ColorCache</a>
<span class="bold-text"><b>_cache</b></span>
<br/>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Utils/UserInterface/Platform.h#L58" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Platform.h</span>
</a>
</span>
<br/>
<br/>
<blockquote>
<span class="icon-list-item"><a href="#platform" class="icon-list-item"><img src="../images/jumpToTop.svg" class="icon-list-item"/><span class="icon-list-item">top</span>
</a>
</span>
</blockquote>
<br/>
<a id="platform"></a>
<h2>Platform</h2>
<span class="bold-text"><b>Platform</b></span>
<span class="italic-text"><i>(</i></span>
<span class="italic-text"><i>)</i></span>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Utils/UserInterface/Platform.h#L61" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Platform.h</span>
</a>
</span>
<br/>
<br/>
<blockquote>
<span class="icon-list-item"><a href="#platform" class="icon-list-item"><img src="../images/jumpToTop.svg" class="icon-list-item"/><span class="icon-list-item">top</span>
</a>
</span>
</blockquote>
<br/>
<a id="~platform"></a>
<h2>~Platform</h2>
<span class="bold-text"><b>~Platform</b></span>
<span class="italic-text"><i>(</i></span>
<span class="italic-text"><i>)</i></span>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Utils/UserInterface/Platform.h#L62" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Platform.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Utils/UserInterface/Platform.cpp#L34" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Platform.cpp</span>
</a>
</span>
<br/>
<br/>
<blockquote>
<span class="icon-list-item"><a href="#platform" class="icon-list-item"><img src="../images/jumpToTop.svg" class="icon-list-item"/><span class="icon-list-item">top</span>
</a>
</span>
</blockquote>
<br/>
<a id="clear"></a>
<h2>clear</h2>
<span class="inline-text">void</span>
<span class="bold-text"><b>clear</b></span>
<span class="italic-text"><i>(</i></span>
<span class="italic-text"><i>)</i></span>
<a id="references"></a>
<h4>References</h4>
<div class="paragraph">
<span class="paragraph"><img src="../images/class.svg"/><a href="classHack_1_1Ui_1_1Platform.md#put">put</a>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/class.svg"/><a href="namespaceHack_1_1Ui_1_1Detail.md#clear">Clear</a>
</span>
</div>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Utils/UserInterface/Platform.h#L76" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Platform.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Utils/UserInterface/Platform.cpp#L128" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Platform.cpp</span>
</a>
</span>
<br/>
<br/>
<blockquote>
<span class="icon-list-item"><a href="#platform" class="icon-list-item"><img src="../images/jumpToTop.svg" class="icon-list-item"/><span class="icon-list-item">top</span>
</a>
</span>
</blockquote>
<br/>
<a id="color"></a>
<h2>color</h2>
<span class="inline-text">void</span>
<span class="bold-text"><b>color</b></span>
<span class="italic-text"><i>(</i></span>
<div class="paragraph">
<span class="paragraph"><img src="../images/horSpace24px.svg"/><span class="bold-text"><b>uint8_t</b></span>
<span class="inline-text">index</span>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/horSpace24px.svg"/><span class="inline-text">uint32_t</span>
<span class="inline-text">color</span>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/horSpace24px.svg"/><span class="inline-text">bool</span>
<span class="inline-text">background</span>
</span>
</div>
<span class="italic-text"><i>)</i></span>
<a id="references"></a>
<h4>References</h4>
<div class="paragraph">
<span class="paragraph"><img src="../images/class.svg"/><a href="classHack_1_1Ui_1_1Platform.md#put">put</a>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/class.svg"/><a href="classHack_1_1Ui_1_1ColorCacheItem.md#background">background</a>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/class.svg"/><a href="classHack_1_1Ui_1_1ColorCacheItem.md#foreground">foreground</a>
</span>
</div>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Utils/UserInterface/Platform.h#L70" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Platform.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Utils/UserInterface/Platform.cpp#L42" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Platform.cpp</span>
</a>
</span>
<br/>
<br/>
<blockquote>
<span class="icon-list-item"><a href="#platform" class="icon-list-item"><img src="../images/jumpToTop.svg" class="icon-list-item"/><span class="icon-list-item">top</span>
</a>
</span>
</blockquote>
<br/>
<a id="flush"></a>
<h2>flush</h2>
<span class="inline-text">void</span>
<span class="bold-text"><b>flush</b></span>
<span class="italic-text"><i>(</i></span>
<span class="italic-text"><i>)</i></span>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Utils/UserInterface/Platform.h#L86" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Platform.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Utils/UserInterface/Platform.cpp#L153" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Platform.cpp</span>
</a>
</span>
<br/>
<br/>
<blockquote>
<span class="icon-list-item"><a href="#platform" class="icon-list-item"><img src="../images/jumpToTop.svg" class="icon-list-item"/><span class="icon-list-item">top</span>
</a>
</span>
</blockquote>
<br/>
<a id="getscreensize"></a>
<h2>getScreenSize</h2>
<span class="inline-text">void</span>
<span class="bold-text"><b>getScreenSize</b></span>
<span class="italic-text"><i>(</i></span>
<div class="paragraph">
<span class="paragraph"><img src="../images/horSpace24px.svg"/><a href="classHack_1_1Ui_1_1Point.md#point">Point</a>
<span class="inline-text"> &amp;</span>
<span class="inline-text">sz</span>
</span>
</div>
<span class="italic-text"><i>)</i></span>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Utils/UserInterface/Platform.h#L64" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Platform.h</span>
</a>
</span>
<br/>
<br/>
<blockquote>
<span class="icon-list-item"><a href="#platform" class="icon-list-item"><img src="../images/jumpToTop.svg" class="icon-list-item"/><span class="icon-list-item">top</span>
</a>
</span>
</blockquote>
<br/>
<a id="poll"></a>
<h2>poll</h2>
<span class="inline-text">int</span>
<span class="bold-text"><b>poll</b></span>
<span class="italic-text"><i>(</i></span>
<div class="paragraph">
<span class="paragraph"><img src="../images/horSpace24px.svg"/><span class="inline-text">bool</span>
<span class="inline-text">block</span>
</span>
</div>
<span class="italic-text"><i>)</i></span>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Utils/UserInterface/Platform.h#L66" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Platform.h</span>
</a>
</span>
<br/>
<br/>
<blockquote>
<span class="icon-list-item"><a href="#platform" class="icon-list-item"><img src="../images/jumpToTop.svg" class="icon-list-item"/><span class="icon-list-item">top</span>
</a>
</span>
</blockquote>
<br/>
<a id="put"></a>
<h2>put</h2>
<span class="inline-text">void</span>
<span class="bold-text"><b>put</b></span>
<span class="italic-text"><i>(</i></span>
<div class="paragraph">
<span class="paragraph"><img src="../images/horSpace24px.svg"/><span class="inline-text">char</span>
<span class="inline-text">ch</span>
</span>
</div>
<span class="italic-text"><i>)</i></span>
<a id="references"></a>
<h4>References</h4>
<div class="paragraph">
<span class="paragraph"><img src="../images/class.svg"/><a href="namespaceHack_1_1Ui.md#cs_seq_start">CS_SEQ_START</a>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/class.svg"/><a href="namespaceHack_1_1Ui.md#cs_start">CS_START</a>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/class.svg"/><a href="namespaceHack_1_1Ui.md#cs_rect_hz">CS_RECT_HZ</a>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/class.svg"/><a href="classHack_1_1Ui_1_1Platform.md#put">put</a>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/class.svg"/><a href="namespaceHack_1_1Ui_1_1Detail.md#linehz">LineHz</a>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/class.svg"/><a href="namespaceHack_1_1Ui.md#cs_rect_vt">CS_RECT_VT</a>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/class.svg"/><a href="namespaceHack_1_1Ui_1_1Detail.md#linevt">LineVt</a>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/class.svg"/><a href="namespaceHack_1_1Ui.md#cs_rect_lt">CS_RECT_LT</a>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/class.svg"/><a href="namespaceHack_1_1Ui_1_1Detail.md#linelt">LineLt</a>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/class.svg"/><a href="namespaceHack_1_1Ui.md#cs_rect_rt">CS_RECT_RT</a>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/class.svg"/><a href="namespaceHack_1_1Ui_1_1Detail.md#linert">LineRt</a>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/class.svg"/><a href="namespaceHack_1_1Ui.md#cs_rect_rb">CS_RECT_RB</a>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/class.svg"/><a href="namespaceHack_1_1Ui_1_1Detail.md#linerb">LineRb</a>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/class.svg"/><a href="namespaceHack_1_1Ui.md#cs_rect_lb">CS_RECT_LB</a>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/class.svg"/><a href="namespaceHack_1_1Ui_1_1Detail.md#linelb">LineLb</a>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/class.svg"/><a href="namespaceHack_1_1Ui.md#cs_rect_lcs">CS_RECT_LCS</a>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/class.svg"/><a href="namespaceHack_1_1Ui_1_1Detail.md#linevertl">LineVertL</a>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/class.svg"/><a href="namespaceHack_1_1Ui.md#cs_rect_rcs">CS_RECT_RCS</a>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/class.svg"/><a href="namespaceHack_1_1Ui_1_1Detail.md#linevertr">LineVertR</a>
</span>
</div>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Utils/UserInterface/Platform.h#L68" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Platform.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Utils/UserInterface/Platform.cpp#L61" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Platform.cpp</span>
</a>
</span>
<br/>
<br/>
<blockquote>
<span class="icon-list-item"><a href="#platform" class="icon-list-item"><img src="../images/jumpToTop.svg" class="icon-list-item"/><span class="icon-list-item">top</span>
</a>
</span>
</blockquote>
<br/>
<a id="put"></a>
<h2>put</h2>
<span class="inline-text">void</span>
<span class="bold-text"><b>put</b></span>
<span class="italic-text"><i>(</i></span>
<div class="paragraph">
<span class="paragraph"><img src="../images/horSpace24px.svg"/><span class="inline-text">const char *</span>
<span class="inline-text">ch</span>
</span>
</div>
<span class="italic-text"><i>)</i></span>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Utils/UserInterface/Platform.h#L72" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Platform.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Utils/UserInterface/Platform.cpp#L100" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Platform.cpp</span>
</a>
</span>
<br/>
<br/>
<blockquote>
<span class="icon-list-item"><a href="#platform" class="icon-list-item"><img src="../images/jumpToTop.svg" class="icon-list-item"/><span class="icon-list-item">top</span>
</a>
</span>
</blockquote>
<br/>
<a id="resetcolor"></a>
<h2>resetColor</h2>
<span class="inline-text">void</span>
<span class="bold-text"><b>resetColor</b></span>
<span class="italic-text"><i>(</i></span>
<span class="italic-text"><i>)</i></span>
<a id="references"></a>
<h4>References</h4>
<div class="paragraph">
<span class="paragraph"><img src="../images/class.svg"/><a href="classHack_1_1Ui_1_1Platform.md#put">put</a>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/class.svg"/><a href="namespaceHack_1_1Ui_1_1Detail.md#resetcolor">ResetColor</a>
</span>
</div>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Utils/UserInterface/Platform.h#L80" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Platform.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Utils/UserInterface/Platform.cpp#L123" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Platform.cpp</span>
</a>
</span>
<br/>
<br/>
<blockquote>
<span class="icon-list-item"><a href="#platform" class="icon-list-item"><img src="../images/jumpToTop.svg" class="icon-list-item"/><span class="icon-list-item">top</span>
</a>
</span>
</blockquote>
<br/>
<a id="resetcursor"></a>
<h2>resetCursor</h2>
<span class="inline-text">void</span>
<span class="bold-text"><b>resetCursor</b></span>
<span class="italic-text"><i>(</i></span>
<span class="italic-text"><i>)</i></span>
<a id="references"></a>
<h4>References</h4>
<div class="paragraph">
<span class="paragraph"><img src="../images/class.svg"/><a href="classHack_1_1Ui_1_1Platform.md#put">put</a>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/class.svg"/><a href="namespaceHack_1_1Ui_1_1Detail.md#zerocursor">ZeroCursor</a>
</span>
</div>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Utils/UserInterface/Platform.h#L78" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Platform.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Utils/UserInterface/Platform.cpp#L118" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Platform.cpp</span>
</a>
</span>
<br/>
<br/>
<blockquote>
<span class="icon-list-item"><a href="#platform" class="icon-list-item"><img src="../images/jumpToTop.svg" class="icon-list-item"/><span class="icon-list-item">top</span>
</a>
</span>
</blockquote>
<br/>
<a id="setcursor"></a>
<h2>setCursor</h2>
<span class="inline-text">void</span>
<span class="bold-text"><b>setCursor</b></span>
<span class="italic-text"><i>(</i></span>
<div class="paragraph">
<span class="paragraph"><img src="../images/horSpace24px.svg"/><span class="inline-text">int16_t</span>
<span class="inline-text">x</span>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/horSpace24px.svg"/><span class="inline-text">int16_t</span>
<span class="inline-text">y</span>
</span>
</div>
<span class="italic-text"><i>)</i></span>
<a id="references"></a>
<h4>References</h4>
<div class="paragraph">
<span class="paragraph"><img src="../images/class.svg"/><a href="namespaceHack_1_1Ui_1_1Detail.md#setcursor">SetCursor</a>
</span>
</div>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Utils/UserInterface/Platform.h#L74" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Platform.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Utils/UserInterface/Platform.cpp#L105" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Platform.cpp</span>
</a>
</span>
<br/>
<br/>
<blockquote>
<span class="icon-list-item"><a href="#platform" class="icon-list-item"><img src="../images/jumpToTop.svg" class="icon-list-item"/><span class="icon-list-item">top</span>
</a>
</span>
</blockquote>
<br/>
<a id="showcursor"></a>
<h2>showCursor</h2>
<span class="inline-text">void</span>
<span class="bold-text"><b>showCursor</b></span>
<span class="italic-text"><i>(</i></span>
<div class="paragraph">
<span class="paragraph"><img src="../images/horSpace24px.svg"/><span class="inline-text">bool</span>
<span class="inline-text">show</span>
</span>
</div>
<span class="italic-text"><i>)</i></span>
<a id="references"></a>
<h4>References</h4>
<div class="paragraph">
<span class="paragraph"><img src="../images/class.svg"/><a href="classHack_1_1Ui_1_1Platform.md#put">put</a>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/class.svg"/><a href="namespaceHack_1_1Ui_1_1Detail.md#showcursor">ShowCursor</a>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/class.svg"/><a href="namespaceHack_1_1Ui_1_1Detail.md#hidecursor">HideCursor</a>
</span>
</div>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Utils/UserInterface/Platform.h#L82" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Platform.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Utils/UserInterface/Platform.cpp#L110" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Platform.cpp</span>
</a>
</span>
<br/>
<br/>
<blockquote>
<span class="icon-list-item"><a href="#platform" class="icon-list-item"><img src="../images/jumpToTop.svg" class="icon-list-item"/><span class="icon-list-item">top</span>
</a>
</span>
</blockquote>
<br/>
<a id="usebackbuffer"></a>
<h2>useBackBuffer</h2>
<span class="inline-text">void</span>
<span class="bold-text"><b>useBackBuffer</b></span>
<span class="italic-text"><i>(</i></span>
<div class="paragraph">
<span class="paragraph"><img src="../images/horSpace24px.svg"/><span class="inline-text">bool</span>
<span class="inline-text">use</span>
</span>
</div>
<span class="italic-text"><i>)</i></span>
<a id="references"></a>
<h4>References</h4>
<div class="paragraph">
<span class="paragraph"><img src="../images/class.svg"/><a href="classHack_1_1Ui_1_1Platform.md#put">put</a>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/class.svg"/><a href="namespaceHack_1_1Ui_1_1Detail.md#clear">Clear</a>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/class.svg"/><a href="namespaceHack_1_1Ui_1_1Detail.md#hidecursor">HideCursor</a>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/class.svg"/><a href="namespaceHack_1_1Ui_1_1Detail.md#zerocursor">ZeroCursor</a>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/class.svg"/><a href="namespaceHack_1_1Ui_1_1Detail.md#usebackbuffer">UseBackBuffer</a>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/class.svg"/><a href="classHack_1_1Ui_1_1Platform.md#flush">flush</a>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/class.svg"/><a href="namespaceHack_1_1Ui_1_1Detail.md#showcursor">ShowCursor</a>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/class.svg"/><a href="namespaceHack_1_1Ui_1_1Detail.md#usefrontbuffer">UseFrontBuffer</a>
</span>
</div>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Utils/UserInterface/Platform.h#L84" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Platform.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Utils/UserInterface/Platform.cpp#L133" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Platform.cpp</span>
</a>
</span>
<br/>
<br/>
<blockquote>
<span class="icon-list-item"><a href="#platform" class="icon-list-item"><img src="../images/jumpToTop.svg" class="icon-list-item"/><span class="icon-list-item">top</span>
</a>
</span>
</blockquote>
<br/>
<a id="sleep"></a>
<h2>sleep</h2>
<span class="inline-text">void</span>
<span class="bold-text"><b>sleep</b></span>
<span class="italic-text"><i>(</i></span>
<div class="paragraph">
<span class="paragraph"><img src="../images/horSpace24px.svg"/><span class="inline-text">const uint32_t &amp;</span>
<span class="inline-text">ms</span>
</span>
</div>
<span class="italic-text"><i>)</i></span>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Utils/UserInterface/Platform.h#L88" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Platform.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master/Source/Utils/UserInterface/Platform.cpp#L159" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">Platform.cpp</span>
</a>
</span>
<br/>
<br/>
<blockquote>
<span class="icon-list-item"><a href="#platform" class="icon-list-item"><img src="../images/jumpToTop.svg" class="icon-list-item"/><span class="icon-list-item">top</span>
</a>
</span>
</blockquote>
<br/>
<br/>
<blockquote>
<img src="../images/debug.svg"/><span class="inline-text">The following sources were used to generate this page.</span>
<br/>
<span class="icon-list-item"><a href="../xml/classHack_1_1Ui_1_1Platform.xml#L1" class="icon-list-item"><img src="../images/lookInside.svg" class="icon-list-item"/><span class="icon-list-item">classHack_1_1Ui_1_1Platform.xml</span>
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