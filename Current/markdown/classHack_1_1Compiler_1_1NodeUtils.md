<a id="nodeutils"></a>
<h1>NodeUtils</h1>
<a id="classHack_1_1Compiler_1_1NodeUtils"></a>
<a href="https://github.com/CharlesCarley/HackComputer.md">~</a>
<a href="indexpage.md#hack">Hack</a>
<span class="inline-text">/</span>
<a href="index.md#index">Index</a>
<span class="inline-text">/</span>
<a href="namespaceHack.md#hack">Hack</a>
<span class="inline-text">::</span>
<a href="namespaceHack_1_1Compiler.md#compiler">Compiler</a>
<span class="inline-text">::</span>
<span class="bold-text"><b>NodeUtils</b></span>
<br/>
<br/>
<a id="public-static-methods"></a>
<h2>Public Static Methods</h2>
<span class="icon-list-item"><a href="#nodesubtypestring" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">nodeSubtypeString</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#nodetypestring" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">nodeTypeString</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#nodetypexmlstring" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">nodeTypeXmlString</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="#string" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">string</span>
</a>
</span>
<br/>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/Compiler/Common/NodeUtils.h#L135" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">NodeUtils.h</span>
</a>
</span>
<br/>
<a id="nodesubtypestring"></a>
<h2>nodeSubtypeString</h2>
<span class="inline-text">void</span>
<span class="bold-text"><b>nodeSubtypeString</b></span>
<span class="italic-text"><i>(</i></span>
<div class="paragraph">
<span class="paragraph"><img src="../images/horSpace24px.svg"/><a href="namespaceHack.md#string">String</a>
<span class="inline-text"> &amp;</span>
<span class="inline-text">dest</span>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/horSpace24px.svg"/><a href="classHack_1_1Compiler_1_1Node.md#node">Node</a>
<span class="inline-text"> *</span>
<span class="inline-text">node</span>
</span>
</div>
<span class="italic-text"><i>)</i></span>
<a id="details"></a>
<h4>Details</h4>
<span class="inline-text">Returns a exact string representation of the Subtype_ name </span>
<br/>
<br/>
<ul>
<li><span class="bold-text"><b>dest</b></span>
<span class="inline-text"> - </span>
</li>
<li><span class="bold-text"><b>node</b></span>
<span class="inline-text"> - </span>
</li>
</ul>
<br/>
<a id="references"></a>
<h4>References</h4>
<span class="icon-list-item"><a href="classHack_1_1Compiler_1_1Node.md#subtype" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">subtype</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#subtypenone" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">SubtypeNone</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#subtypeexpressiongroup" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">SubtypeExpressionGroup</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#subtypecall" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">SubtypeCall</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#subtypecallfunction" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">SubtypeCallFunction</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#subtypecallmethod" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">SubtypeCallMethod</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#subtypearrayindex" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">SubtypeArrayIndex</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#subtypeifelsecombo" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">SubtypeIfElseCombo</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#subtypeterm" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">SubtypeTerm</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#subtypeopterm" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">SubtypeOpTerm</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#subtypeletequal" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">SubtypeLetEqual</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#subtypeletarrayequal" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">SubtypeLetArrayEqual</span>
</a>
</span>
<br/>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/Compiler/Common/NodeUtils.h#L160" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">NodeUtils.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/Compiler/Common/NodeUtils.cpp#L266" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">NodeUtils.cpp</span>
</a>
</span>
<br/>
<br/>
<a id="nodetypestring"></a>
<h2>nodeTypeString</h2>
<span class="inline-text">void</span>
<span class="bold-text"><b>nodeTypeString</b></span>
<span class="italic-text"><i>(</i></span>
<div class="paragraph">
<span class="paragraph"><img src="../images/horSpace24px.svg"/><a href="namespaceHack.md#string">String</a>
<span class="inline-text"> &amp;</span>
<span class="inline-text">dest</span>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/horSpace24px.svg"/><a href="classHack_1_1Compiler_1_1Node.md#node">Node</a>
<span class="inline-text"> *</span>
<span class="inline-text">node</span>
</span>
</div>
<span class="italic-text"><i>)</i></span>
<a id="details"></a>
<h4>Details</h4>
<span class="inline-text">Returns a exact string representation of the enum name </span>
<br/>
<br/>
<ul>
<li><span class="bold-text"><b>dest</b></span>
<span class="inline-text"> - </span>
</li>
<li><span class="bold-text"><b>node</b></span>
<span class="inline-text"> - </span>
</li>
</ul>
<br/>
<a id="references"></a>
<h4>References</h4>
<span class="icon-list-item"><a href="classHack_1_1Compiler_1_1NodeUtils.md#string" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">string</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="classHack_1_1Compiler_1_1Node.md#type" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">type</span>
</a>
</span>
<br/>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/Compiler/Common/NodeUtils.h#L147" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">NodeUtils.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/Compiler/Common/NodeUtils.cpp#L48" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">NodeUtils.cpp</span>
</a>
</span>
<br/>
<br/>
<a id="nodetypexmlstring"></a>
<h2>nodeTypeXmlString</h2>
<span class="inline-text">void</span>
<span class="bold-text"><b>nodeTypeXmlString</b></span>
<span class="italic-text"><i>(</i></span>
<div class="paragraph">
<span class="paragraph"><img src="../images/horSpace24px.svg"/><a href="namespaceHack.md#string">String</a>
<span class="inline-text"> &amp;</span>
<span class="inline-text">dest</span>
</span>
</div>
<div class="paragraph">
<span class="paragraph"><img src="../images/horSpace24px.svg"/><a href="classHack_1_1Compiler_1_1Node.md#node">Node</a>
<span class="inline-text"> *</span>
<span class="inline-text">node</span>
</span>
</div>
<span class="italic-text"><i>)</i></span>
<a id="details"></a>
<h4>Details</h4>
<span class="inline-text">Returns an XML representation of the enum name </span>
<br/>
<br/>
<ul>
<li><span class="bold-text"><b>dest</b></span>
<span class="inline-text"> - </span>
</li>
<li><span class="bold-text"><b>type</b></span>
<span class="inline-text"> - </span>
</li>
</ul>
<br/>
<a id="references"></a>
<h4>References</h4>
<span class="icon-list-item"><a href="classHack_1_1Compiler_1_1Node.md#type" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">type</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#rule" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">Rule</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#ruleclass" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">RuleClass</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#ruleclassdescription" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">RuleClassDescription</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#rulefield" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">RuleField</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#ruledatatype" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">RuleDataType</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#rulefieldspecification" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">RuleFieldSpecification</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#ruleidentifierlist" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">RuleIdentifierList</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#rulemethod" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">RuleMethod</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#rulemethodspecification" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">RuleMethodSpecification</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#rulemethodreturntype" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">RuleMethodReturnType</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#rulemethodbody" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">RuleMethodBody</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#rulebody" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">RuleBody</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#rulevariable" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">RuleVariable</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#rulestatement" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">RuleStatement</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#ruleletstatement" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">RuleLetStatement</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#ruleifstatement" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">RuleIfStatement</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#ruleelsestatement" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">RuleElseStatement</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#rulewhilestatement" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">RuleWhileStatement</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#ruledostatement" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">RuleDoStatement</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#rulereturnstatement" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">RuleReturnStatement</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#rulestatementlist" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">RuleStatementList</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#ruleexpression" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">RuleExpression</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#rulesingleexpression" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">RuleSingleExpression</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#ruleterm" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">RuleTerm</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#rulesimpleterm" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">RuleSimpleTerm</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#rulecomplexterm" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">RuleComplexTerm</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#ruleoperator" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">RuleOperator</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#ruleunaryoperator" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">RuleUnaryOperator</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#ruleexpressionlist" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">RuleExpressionList</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#rulecallmethod" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">RuleCallMethod</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#ruleparameterlist" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">RuleParameterList</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#ruleparameter" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">RuleParameter</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#ruleinlinevm" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">RuleInlineVm</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#ruleinlineasm" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">RuleInlineAsm</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#ruleend" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">RuleEnd</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#keyword" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">Keyword</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#keywordclass" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">KeywordClass</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#keywordconstructor" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">KeywordConstructor</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#keywordfunction" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">KeywordFunction</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#keywordmethod" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">KeywordMethod</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#keywordfield" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">KeywordField</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#keywordstatic" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">KeywordStatic</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#keywordint" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">KeywordInt</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#keywordchar" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">KeywordChar</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#keywordbool" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">KeywordBool</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#keywordvoid" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">KeywordVoid</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#keywordvar" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">KeywordVar</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#keywordlet" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">KeywordLet</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#keywordif" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">KeywordIf</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#keywordelse" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">KeywordElse</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#keyworddo" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">KeywordDo</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#keywordwhile" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">KeywordWhile</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#keywordreturn" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">KeywordReturn</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#keywordend" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">KeywordEnd</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#symbol" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">Symbol</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#symbolopenbrace" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">SymbolOpenBrace</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#symbolclosebrace" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">SymbolCloseBrace</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#symbolsemicolon" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">SymbolSemiColon</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#symbolleftparenthesis" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">SymbolLeftParenthesis</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#symbolrightparenthesis" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">SymbolRightParenthesis</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#symbolleftbracket" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">SymbolLeftBracket</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#symbolrightbracket" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">SymbolRightBracket</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#symbolcomma" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">SymbolComma</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#symbolequals" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">SymbolEquals</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#symbolplus" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">SymbolPlus</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#symbolminus" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">SymbolMinus</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#symbolmultiply" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">SymbolMultiply</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#symboldivide" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">SymbolDivide</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#symboland" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">SymbolAnd</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#symbolor" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">SymbolOr</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#symbolgreater" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">SymbolGreater</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#symbolless" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">SymbolLess</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#symbolnot" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">SymbolNot</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#symbolperiod" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">SymbolPeriod</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#symbolend" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">SymbolEnd</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#constant" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">Constant</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#constantidentifier" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">ConstantIdentifier</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#constantinteger" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">ConstantInteger</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#constantinlinevm" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">ConstantInlineVm</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#constantinlineasm" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">ConstantInlineAsm</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#constantstring" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">ConstantString</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="classHack_1_1Compiler_1_1Node.md#value" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">value</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#constanttrue" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">ConstantTrue</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#constantfalse" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">ConstantFalse</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#constantnull" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">ConstantNull</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#constantthis" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">ConstantThis</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#constantend" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">ConstantEnd</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#subtypenone" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">SubtypeNone</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#subtypeexpressiongroup" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">SubtypeExpressionGroup</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#subtypecall" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">SubtypeCall</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#subtypecallfunction" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">SubtypeCallFunction</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#subtypecallmethod" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">SubtypeCallMethod</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#subtypearrayindex" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">SubtypeArrayIndex</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#subtypeifelsecombo" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">SubtypeIfElseCombo</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#subtypeterm" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">SubtypeTerm</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#subtypeopterm" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">SubtypeOpTerm</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#subtypeletequal" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">SubtypeLetEqual</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#subtypeletarrayequal" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">SubtypeLetArrayEqual</span>
</a>
</span>
<br/>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/Compiler/Common/NodeUtils.h#L153" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">NodeUtils.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/Compiler/Common/NodeUtils.cpp#L158" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">NodeUtils.cpp</span>
</a>
</span>
<br/>
<br/>
<a id="string"></a>
<h2>string</h2>
<a href="namespaceHack.md#string">String</a>
<span class="bold-text"><b>string</b></span>
<span class="italic-text"><i>(</i></span>
<div class="paragraph">
<span class="paragraph"><img src="../images/horSpace24px.svg"/><span class="inline-text">int8_t</span>
<span class="inline-text">type</span>
</span>
</div>
<span class="italic-text"><i>)</i></span>
<a id="details"></a>
<h4>Details</h4>
<span class="inline-text">Returns a exact string representation of the enum name </span>
<br/>
<br/>
<a id="references"></a>
<h4>References</h4>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#rule" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">Rule</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#ruleclass" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">RuleClass</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#ruleclassdescription" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">RuleClassDescription</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#rulefield" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">RuleField</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#ruledatatype" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">RuleDataType</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#rulefieldspecification" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">RuleFieldSpecification</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#ruleidentifierlist" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">RuleIdentifierList</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#rulemethod" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">RuleMethod</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#rulemethodspecification" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">RuleMethodSpecification</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#rulemethodreturntype" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">RuleMethodReturnType</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#rulemethodbody" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">RuleMethodBody</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#rulebody" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">RuleBody</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#rulevariable" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">RuleVariable</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#rulestatement" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">RuleStatement</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#ruleletstatement" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">RuleLetStatement</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#ruleifstatement" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">RuleIfStatement</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#ruleelsestatement" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">RuleElseStatement</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#rulewhilestatement" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">RuleWhileStatement</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#ruledostatement" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">RuleDoStatement</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#rulereturnstatement" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">RuleReturnStatement</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#rulestatementlist" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">RuleStatementList</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#ruleexpression" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">RuleExpression</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#rulesingleexpression" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">RuleSingleExpression</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#ruleterm" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">RuleTerm</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#rulesimpleterm" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">RuleSimpleTerm</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#rulecomplexterm" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">RuleComplexTerm</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#ruleoperator" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">RuleOperator</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#ruleunaryoperator" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">RuleUnaryOperator</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#ruleexpressionlist" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">RuleExpressionList</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#rulecallmethod" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">RuleCallMethod</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#ruleparameterlist" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">RuleParameterList</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#ruleparameter" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">RuleParameter</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#ruleinlinevm" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">RuleInlineVm</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#ruleinlineasm" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">RuleInlineAsm</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#ruleend" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">RuleEnd</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#keyword" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">Keyword</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#keywordclass" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">KeywordClass</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#keywordconstructor" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">KeywordConstructor</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#keywordfunction" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">KeywordFunction</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#keywordmethod" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">KeywordMethod</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#keywordfield" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">KeywordField</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#keywordstatic" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">KeywordStatic</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#keywordint" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">KeywordInt</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#keywordchar" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">KeywordChar</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#keywordbool" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">KeywordBool</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#keywordvoid" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">KeywordVoid</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#keywordvar" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">KeywordVar</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#keywordlet" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">KeywordLet</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#keywordif" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">KeywordIf</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#keywordelse" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">KeywordElse</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#keyworddo" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">KeywordDo</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#keywordwhile" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">KeywordWhile</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#keywordreturn" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">KeywordReturn</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#keywordend" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">KeywordEnd</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#symbol" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">Symbol</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#symbolopenbrace" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">SymbolOpenBrace</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#symbolclosebrace" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">SymbolCloseBrace</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#symbolsemicolon" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">SymbolSemiColon</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#symbolleftparenthesis" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">SymbolLeftParenthesis</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#symbolrightparenthesis" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">SymbolRightParenthesis</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#symbolleftbracket" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">SymbolLeftBracket</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#symbolrightbracket" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">SymbolRightBracket</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#symbolcomma" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">SymbolComma</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#symbolequals" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">SymbolEquals</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#symbolplus" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">SymbolPlus</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#symbolminus" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">SymbolMinus</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#symbolmultiply" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">SymbolMultiply</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#symboldivide" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">SymbolDivide</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#symboland" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">SymbolAnd</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#symbolor" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">SymbolOr</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#symbolgreater" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">SymbolGreater</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#symbolless" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">SymbolLess</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#symbolnot" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">SymbolNot</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#symbolperiod" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">SymbolPeriod</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#symbolend" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">SymbolEnd</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#constant" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">Constant</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#constantidentifier" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">ConstantIdentifier</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#constantinteger" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">ConstantInteger</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#constantstring" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">ConstantString</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#constantinlinevm" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">ConstantInlineVm</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#constantinlineasm" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">ConstantInlineAsm</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#constanttrue" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">ConstantTrue</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#constantfalse" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">ConstantFalse</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#constantnull" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">ConstantNull</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#constantthis" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">ConstantThis</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#constantend" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">ConstantEnd</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#subtypenone" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">SubtypeNone</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#subtypeexpressiongroup" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">SubtypeExpressionGroup</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#subtypecall" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">SubtypeCall</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#subtypecallfunction" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">SubtypeCallFunction</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#subtypecallmethod" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">SubtypeCallMethod</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#subtypearrayindex" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">SubtypeArrayIndex</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#subtypeifelsecombo" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">SubtypeIfElseCombo</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#subtypeterm" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">SubtypeTerm</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#subtypeopterm" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">SubtypeOpTerm</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#subtypeletequal" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">SubtypeLetEqual</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="namespaceHack_1_1Compiler.md#subtypeletarrayequal" class="icon-list-item"><img src="../images/class.svg" class="icon-list-item"/><span class="icon-list-item">SubtypeLetArrayEqual</span>
</a>
</span>
<br/>
<a id="defined-in"></a>
<h4>Defined in</h4>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/Compiler/Common/NodeUtils.h#L140" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">NodeUtils.h</span>
</a>
</span>
<br/>
<span class="icon-list-item"><a href="https://github.com/CharlesCarley/HackComputer/blob/master//Source/Compiler/Common/NodeUtils.cpp#L53" class="icon-list-item"><img src="../images/file.svg" class="icon-list-item"/><span class="icon-list-item">NodeUtils.cpp</span>
</a>
</span>
<br/>
<br/>
</div>
</div>
</body>
</html>
