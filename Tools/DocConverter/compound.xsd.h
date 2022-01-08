
class DoxygenType
{
public:
    std::vector<compounddefType> compounddef;
    DoxVersionNumber             version;
};

class compounddefType
{
public:
    String                compoundname;
    String                title;
    compoundRefType       basecompoundref;
    compoundRefType       derivedcompoundref;
    incType               includes;
    incType               includedby;
    graphType             incdepgraph;
    graphType             invincdepgraph;
    refType               innerdir;
    refType               innerfile;
    refType               innerclass;
    refType               innernamespace;
    refType               innerpage;
    refType               innergroup;
    templateparamlistType templateparamlist;
    sectiondefType        sectiondef;
    String                tableofcontents;
    descriptionType       briefdescription;
    descriptionType       detaileddescription;
    graphType             inheritancegraph;
    graphType             collaborationgraph;
    listingType           programlisting;
    locationType          location;
    listofallmembersType  listofallmembers;
    String                id;
    DoxCompoundKind       kind;
    DoxLanguage           language;
    DoxProtectionKind     prot;
    DoxBool               final;
    DoxBool               sealed;
    DoxBool               abstract;
};

class listofallmembersType
{
public:
    memberRefType member;
};

class memberRefType
{
public:
    String            scope;
    String            name;
    String            refid;
    DoxProtectionKind prot;
    DoxVirtualKind    virt;
    String            ambiguityscope;
};

class compoundRefType
{
public:
    String            refid;
    DoxProtectionKind prot;
    DoxVirtualKind    virt;
};

class reimplementType
{
public:
    String refid;
};

class incType
{
public:
    String  refid;
    DoxBool local;
};

class refType
{
public:
    String            refid;
    DoxProtectionKind prot;
};

class refTextType
{
public:
    String     refid;
    DoxRefKind kindref;
    String     external;
    String     tooltip;
};

class sectiondefType
{
public:
    String          header;
    descriptionType description;
    memberdefType   memberdef;
    DoxSectionKind  kind;
};

class memberdefType
{
public:
    templateparamlistType templateparamlist;
    linkedTextType        type;
    //name="definition"
    //name="argsstring"
    //name="name"
    //name="read"
    //name="write"
    //name="bitfield"
    reimplementType reimplements;
    reimplementType reimplementedby;
    paramType       param;
    enumvalueType   enumvalue;
    linkedTextType  initializer;
    linkedTextType  exceptions;
    descriptionType briefdescription;
    descriptionType detaileddescription;
    descriptionType inbodydescription;
    locationType    location;
    referenceType   references;
    referenceType   referencedby;
    //</xsd:sequence>
    DoxMemberKind     kind;
    String            id;
    DoxProtectionKind prot;
    DoxBool static;
    DoxBool strong;
    DoxBool const;
    DoxBool explicit;
    DoxBool inline;
    DoxRefQualifierKind refqual;
    DoxVirtualKind      virt;
    DoxBool volatile;
    DoxBool mutable;
    DoxBool readable;  //<!-- Qt property -->
    DoxBool writable;
    //<!-- C++/CLI variable -->
    DoxBool initonly;
    //<!-- C++/CLI and C# property -->
    DoxBool settable;
    DoxBool gettable;
    //<!-- C++/CLI function -->
    DoxBool final;
    DoxBool sealed;
    DoxBool new;
    //<!-- C++/CLI event -->
    DoxBool add;
    DoxBool remove;
    DoxBool raise;
    //<!-- Objective-C 2.0 protocol method -->
    DoxBool optional;
    DoxBool required;
    //<!-- Objective-C 2.0 property accessor -->
    DoxAccessor accessor;
    //<!-- UNO IDL -->
    DoxBool attribute;
    DoxBool property;
    DoxBool readonly;
    DoxBool bound;
    DoxBool removable;
    DoxBool contrained;
    DoxBool transient;
    DoxBool maybevoid;
    DoxBool maybedefault;
    DoxBool maybeambiguous;
};

class descriptionType
{
public:
    //<xsd:sequence>
    String          title;
    docParaType     para;
    docSect1Type    sect1;
    docInternalType internal;
    //</xsd:sequence>
};

class enumvalueType
{
public:
    //<xsd:sequence>
    //name="name"
    linkedTextType  initializer;
    descriptionType briefdescription;
    descriptionType detaileddescription;
    //</xsd:sequence>
    String            id;
    DoxProtectionKind prot;
};

class templateparamlistType
{
public:
    //<xsd:sequence>
    paramType param;
    //</xsd:sequence>
};

class paramType
{
public:
    //<xsd:sequence>
    linkedTextType type;
    //name="declname"
    //name="defname"
    //name="array"
    linkedTextType  defval;
    linkedTextType  typeconstraint;
    descriptionType briefdescription;
    //</xsd:sequence>
};

class linkedTextType
{
public:
    //<xsd:sequence>
    refTextType ref;
    //</xsd:sequence>
};

class graphType
{
public:
    //<xsd:sequence>
    nodeType node;
    //</xsd:sequence>
};

class nodeType
{
public:
    //<xsd:sequence>
    //name="label"
    linkType      link;
    childnodeType childnode;
    //</xsd:sequence>
    String id;
};

class childnodeType
{
public:
    //<xsd:sequence>
    //name="edgelabel"
    //</xsd:sequence>
    String           refid;
    DoxGraphRelation relation;
};

class linkType
{
public:
    String refid;
    String external;
};

class listingType
{
public:
    //<xsd:sequence>
    codelineType codeline;
    //</xsd:sequence>
    String filename;
};

class codelineType
{
public:
    //<xsd:sequence>
    highlightType highlight;
    //</xsd:sequence>
    int64_t    lineno;
    String     refid;
    DoxRefKind refkind;
    DoxBool    external;
};

class highlightType
{
public:
    //<xsd:choice >
    spType      sp;
    refTextType ref;
    //</xsd:choice>
    DoxHighlightClass class;
};

class spType
{
public:
    int64_t value;
};

class referenceType
{
public:
    String  refid;
    String  compoundref;
    int64_t startline;
    int64_t endline;
};

class locationType
{
public:
    String  file;
    int64_t line;
    int64_t column;
    String  bodyfile;
    int64_t bodystart;
    int64_t bodyend;
};

class docSect1Type
{
public:
    //<xsd:sequence>
    String            title;
    docParaType       para;
    docSect2Type      sect2;
    docInternalS1Type internal;
    //</xsd:sequence>
    String id;
};

class docSect2Type
{
public:
    //<xsd:sequence>
    String            title;
    docParaType       para;
    docSect3Type      sect3;
    docInternalS2Type internal;
    //</xsd:sequence>
    String id;
};

class docSect3Type
{
public:
    //<xsd:sequence>
    String            title;
    docParaType       para;
    docSect4Type      sect4;
    docInternalS3Type internal;
    //</xsd:sequence>
    String id;
};

class docSect4Type
{
public:
    //<xsd:sequence>
    String            title;
    docParaType       para;
    docInternalS4Type internal;
    //</xsd:sequence>
    String id;
};

class docInternalType
{
public:
    //<xsd:sequence>
    docParaType  para;
    docSect1Type sect1;
    //</xsd:sequence>
};

class docInternalS1Type
{
public:
    //<xsd:sequence>
    docParaType  para;
    docSect2Type sect2;
    //</xsd:sequence>
};

class docInternalS2Type
{
public:
    //<xsd:sequence>
    docParaType  para;
    docSect3Type sect3;
    //</xsd:sequence>
};

class docInternalS3Type
{
public:
    //<xsd:sequence>
    docParaType  para;
    docSect4Type sect3;
    //</xsd:sequence>
};

class docInternalS4Type
{
public:
    //<xsd:sequence>
    docParaType para;
    //</xsd:sequence>
};

class docTitleCmdGroup
{
public:
    docURLLink     ulink;
    docMarkupType  bold;
    docMarkupType  emphasis;
    docMarkupType  computeroutput;
    docMarkupType  subscript;
    docMarkupType  superscript;
    docMarkupType  center;
    docMarkupType  small;
    String         htmlonly;
    String         manonly;
    String         xmlonly;
    String         rtfonly;
    String         latexonly;
    String         dot;
    String         plantuml;
    docAnchorType  anchor;
    docFormulaType formula;
    docRefTextType ref;
    docEmptyType   nonbreakablespace;
    docEmptyType   iexcl;
    docEmptyType   cent;
    docEmptyType   pound;
    docEmptyType   curren;
    docEmptyType   yen;
    docEmptyType   brvbar;
    docEmptyType   sect;
    docEmptyType   umlaut;
    docEmptyType   copy;
    docEmptyType   ordf;
    docEmptyType   laquo;
    docEmptyType not ;
    docEmptyType shy;
    docEmptyType registered;
    docEmptyType macr;
    docEmptyType deg;
    docEmptyType plusmn;
    docEmptyType sup2;
    docEmptyType sup3;
    docEmptyType acute;
    docEmptyType micro;
    docEmptyType para;
    docEmptyType middot;
    docEmptyType cedil;
    docEmptyType sup1;
    docEmptyType ordm;
    docEmptyType raquo;
    docEmptyType frac14;
    docEmptyType frac12;
    docEmptyType frac34;
    docEmptyType iquest;
    docEmptyType Agrave;
    docEmptyType Aacute;
    docEmptyType Acirc;
    docEmptyType Atilde;
    docEmptyType Aumlaut;
    docEmptyType Aring;
    docEmptyType AElig;
    docEmptyType Ccedil;
    docEmptyType Egrave;
    docEmptyType Eacute;
    docEmptyType Ecirc;
    docEmptyType Eumlaut;
    docEmptyType Igrave;
    docEmptyType Iacute;
    docEmptyType Icirc;
    docEmptyType Iumlaut;
    docEmptyType ETH;
    docEmptyType Ntilde;
    docEmptyType Ograve;
    docEmptyType Oacute;
    docEmptyType Ocirc;
    docEmptyType Otilde;
    docEmptyType Oumlaut;
    docEmptyType times;
    docEmptyType Oslash;
    docEmptyType Ugrave;
    docEmptyType Uacute;
    docEmptyType Ucirc;
    docEmptyType Uumlaut;
    docEmptyType Yacute;
    docEmptyType THORN;
    docEmptyType szlig;
    docEmptyType agrave;
    docEmptyType aacute;
    docEmptyType acirc;
    docEmptyType atilde;
    docEmptyType aumlaut;
    docEmptyType aring;
    docEmptyType aelig;
    docEmptyType ccedil;
    docEmptyType egrave;
    docEmptyType eacute;
    docEmptyType ecirc;
    docEmptyType eumlaut;
    docEmptyType igrave;
    docEmptyType iacute;
    docEmptyType icirc;
    docEmptyType iumlaut;
    docEmptyType eth;
    docEmptyType ntilde;
    docEmptyType ograve;
    docEmptyType oacute;
    docEmptyType ocirc;
    docEmptyType otilde;
    docEmptyType oumlaut;
    docEmptyType divide;
    docEmptyType oslash;
    docEmptyType ugrave;
    docEmptyType uacute;
    docEmptyType ucirc;
    docEmptyType uumlaut;
    docEmptyType yacute;
    docEmptyType thorn;
    docEmptyType yumlaut;
    docEmptyType fnof;
    docEmptyType Alpha;
    docEmptyType Beta;
    docEmptyType Gamma;
    docEmptyType Delta;
    docEmptyType Epsilon;
    docEmptyType Zeta;
    docEmptyType Eta;
    docEmptyType Theta;
    docEmptyType Iota;
    docEmptyType Kappa;
    docEmptyType Lambda;
    docEmptyType Mu;
    docEmptyType Nu;
    docEmptyType Xi;
    docEmptyType Omicron;
    docEmptyType Pi;
    docEmptyType Rho;
    docEmptyType Sigma;
    docEmptyType Tau;
    docEmptyType Upsilon;
    docEmptyType Phi;
    docEmptyType Chi;
    docEmptyType Psi;
    docEmptyType Omega;
    docEmptyType alpha;
    docEmptyType beta;
    docEmptyType gamma;
    docEmptyType delta;
    docEmptyType epsilon;
    docEmptyType zeta;
    docEmptyType eta;
    docEmptyType theta;
    docEmptyType iota;
    docEmptyType kappa;
    docEmptyType lambda;
    docEmptyType mu;
    docEmptyType nu;
    docEmptyType xi;
    docEmptyType omicron;
    docEmptyType pi;
    docEmptyType rho;
    docEmptyType sigmaf;
    docEmptyType sigma;
    docEmptyType tau;
    docEmptyType upsilon;
    docEmptyType phi;
    docEmptyType chi;
    docEmptyType psi;
    docEmptyType omega;
    docEmptyType thetasym;
    docEmptyType upsih;
    docEmptyType piv;
    docEmptyType bull;
    docEmptyType hellip;
    docEmptyType prime;
    docEmptyType Prime;
    docEmptyType oline;
    docEmptyType frasl;
    docEmptyType weierp;
    docEmptyType imaginary;
    docEmptyType real;
    docEmptyType trademark;
    docEmptyType alefsym;
    docEmptyType larr;
    docEmptyType uarr;
    docEmptyType rarr;
    docEmptyType darr;
    docEmptyType harr;
    docEmptyType crarr;
    docEmptyType lArr;
    docEmptyType uArr;
    docEmptyType rArr;
    docEmptyType dArr;
    docEmptyType hArr;
    docEmptyType forall;
    docEmptyType part;
    docEmptyType exist;
    docEmptyType empty;
    docEmptyType nabla;
    docEmptyType isin;
    docEmptyType notin;
    docEmptyType ni;
    docEmptyType prod;
    docEmptyType sum;
    docEmptyType minus;
    docEmptyType lowast;
    docEmptyType radic;
    docEmptyType prop;
    docEmptyType infin;
    docEmptyType ang;
    docEmptyType and;
    docEmptyType or ;
    docEmptyType cap;
    docEmptyType cup;
    docEmptyType int;
    docEmptyType there4;
    docEmptyType sim;
    docEmptyType cong;
    docEmptyType asymp;
    docEmptyType ne;
    docEmptyType equiv;
    docEmptyType le;
    docEmptyType ge;
    docEmptyType sub;
    docEmptyType sup;
    docEmptyType nsub;
    docEmptyType sube;
    docEmptyType supe;
    docEmptyType oplus;
    docEmptyType otimes;
    docEmptyType perp;
    docEmptyType sdot;
    docEmptyType lceil;
    docEmptyType rceil;
    docEmptyType lfloor;
    docEmptyType rfloor;
    docEmptyType lang;
    docEmptyType rang;
    docEmptyType loz;
    docEmptyType spades;
    docEmptyType clubs;
    docEmptyType hearts;
    docEmptyType diams;
    docEmptyType OElig;
    docEmptyType oelig;
    docEmptyType Scaron;
    docEmptyType scaron;
    docEmptyType Yumlaut;
    docEmptyType circ;
    docEmptyType tilde;
    docEmptyType ensp;
    docEmptyType emsp;
    docEmptyType thinsp;
    docEmptyType zwnj;
    docEmptyType zwj;
    docEmptyType lrm;
    docEmptyType rlm;
    docEmptyType ndash;
    docEmptyType mdash;
    docEmptyType lsquo;
    docEmptyType rsquo;
    docEmptyType sbquo;
    docEmptyType ldquo;
    docEmptyType rdquo;
    docEmptyType bdquo;
    docEmptyType dagger;
    docEmptyType Dagger;
    docEmptyType permil;
    docEmptyType lsaquo;
    docEmptyType rsaquo;
    docEmptyType euro;
    docEmptyType tm;
};

class docEmptyType
{
public:
    int n;
};

class docTitleType
{
public:
    < xsd : group ref = "docTitleCmdGroup"
};

//<xsd:group name="docCmdGroup">
//<xsd:choice>
//<xsd:group ref="docTitleCmdGroup"/>
docEmptyType        linebreak;
docEmptyType        hruler;
docMarkupType       preformatted;
listingType         programlisting;
String              verbatim;
docIndexEntryType   indexentry;
docListType         orderedlist;
docListType         itemizedlist;
docSimpleSectType   simplesect;
docTitleType        title;
docVariableListType variablelist;
docTableType        table;
docHeadingType      heading;
docImageType        image;
docFileType         dotfile;
docFileType         mscfile;
docFileType         diafile;
docTocListType      toclist;
docLanguageType     language;
docParamListType    parameterlist;
docXRefSectType     xrefsect;
docCopyType         copydoc;
docBlockQuoteType   blockquote;
docParBlockType     parblock;
//</xsd:choice>
//</xsd:group>

class docParaType
{
public:
    //<xsd:group ref="docCmdGroup"
};

class docMarkupType
{
public:
    //<xsd:group ref="docCmdGroup"
};

class docURLLink
{
public:
    //<xsd:group ref="docTitleCmdGroup"
    String url;
};

class docAnchorType
{
public:
    String id;
};

class docFormulaType
{
public:
    String id;
};

class docIndexEntryType
{
public:
    String primaryie;
    String secondaryie;
};

class docListType
{
public:
    docListItemType listitem;
};

class docListItemType
{
public:
    docParaType para;
};

class docSimpleSectType
{
public:
    docTitleType      title;
    docParaType       para;
    DoxSimpleSectKind kind;
};

class docVarListEntryType
{
public:
    docTitleType term;
};

class docVariableListGroup
{
public:
    docVarListEntryType varlistentry;
    docListItemType     listitem;
};

class docVariableListType
{
public:
    //<xsd:sequence>
    //<xsd:group ref="docVariableListGroup"
    //</xsd:sequence>
};

class docRefTextType
{
public:
    String     refid;
    DoxRefKind kindref;
    String     external;
};

class docTableType
{
public:
    docRowType     row;
    docCaptionType caption;
    int64_t        rows;
    int64_t        cols;
};

class docRowType
{
public:
    docEntryType entry;
};

class docEntryType
{
public:
    docParaType para;
    DoxBool     thead;
};

class docCaptionType
{
public:
    //<xsd:group ref="docTitleCmdGroup"
};

class docHeadingType
{
public:
    //<xsd:group ref="docTitleCmdGroup"
    int64_t level;  //<!-- todo: range 1-6 -->
};

class docImageType
{
public:
    //<xsd:group ref="docTitleCmdGroup"
    DoxImageKind type;
    String       name;
    String       width;
    String       height;
};

class docFileType
{
public:
    //<xsd:group ref="docTitleCmdGroup"
    String name;
};

class docTocItemType
{
public:
    //<xsd:group ref="docTitleCmdGroup"
    String id;
};

class docTocListType
{
public:
    docTocItemType tocitem;
};

class docLanguageType
{
public:
    docParaType para;
    String      langid;
};

class docParamListType
{
public:
    docParamListItem parameteritem;
    DoxParamListKind kind;
};

class docParamListItem
{
public:
    docParamNameList parameternamelist;
    descriptionType  parameterdescription;
};

class docParamNameList
{
public:
    docParamType parametertype;
    docParamName parametername;
};

class docParamType
{
public:
    refTextType ref;
};

class docParamName
{
public:
    refTextType ref;
    DoxParamDir direction;
};

class docXRefSectType
{
public:
    String          xreftitle;
    descriptionType xrefdescription;
    String          id;
};

class docCopyType
{
public:
    docParaType     para;
    docSect1Type    sect1;
    docInternalType internal;
    String          link;
};

class docBlockQuoteType
{
public:
    docParaType para;
};

class docParBlockType
{
public:
    docParaType para;
};

//<xsd:complexType name="docEmptyType"/>

//<!-- Simple types -->

enum DoxBool
{
    YES,
    NO,
};

enum DoxGraphRelation
{
    INCLUDE,
    USAGE,
    TEMPLATE_INSTANCE,
    PUBLIC_INHERITANCE,
    PROTECTED_INHERITANCE,
    PRIVATE_INHERITANCE,
    TYPE_CONSTRAINT,
};

enum DoxRefKind
{
    COMPOUND,
    MEMBER,
};

enum DoxMemberKind
{
    DEFINE,
    PROPERTY,
    EVENT,
    VARIABLE,
    TYPEDEF,
    ENUM,
    FUNCTION,
    SIGNAL,
    PROTOTYPE,
    FRIEND,
    DCOP,
    SLOT,
    INTERFACE,
    SERVICE,
};

enum DoxProtectionKind
{
    PUBLIC,
    PROTECTED,
    PRIVATE,
    PACKAGE,
};

enum DoxRefQualifierKind
{
    LVALUE,
    RVALUE,
};

enum DoxLanguage
{
    UNKNOWN,
    IDL,
    JAVA,
    CSHARP,
    D,
    PHP,
    OBJECTIVEC,
    CPP,
    JAVASCRIPT,
    PYTHON,
    FORTRAN,
    VHDL,
    XML,
    SQL,
    TCL,
    MARKDOWN,
};

enum DoxVirtualKind
{
    NON_VIRTUAL,
    VIRTUAL,
    PURE_VIRTUAL,
};

enum DoxCompoundKind
{
    CLASS,
    STRUCT,
    UNION,
    INTERFACE,
    PROTOCOL,
    CATEGORY,
    EXCEPTION,
    SERVICE,
    SINGLETON,
    MODULE,
    TYPE,
    FILE,
    NAMESPACE,
    GROUP,
    PAGE,
    EXAMPLE,
    DIR,
};

enum DoxSectionKind
{
    USER_DEFINED,
    PUBLIC_TYPE,
    PUBLIC_FUNC,
    PUBLIC_ATTRIB,
    PUBLIC_SLOT,
    SIGNAL,
    DCOP_FUNC,
    PROPERTY,
    EVENT,
    PUBLIC_STATIC_FUNC,
    PUBLIC_STATIC_ATTRIB,
    PROTECTED_TYPE,
    PROTECTED_FUNC,
    PROTECTED_ATTRIB,
    PROTECTED_SLOT,
    PROTECTED_STATIC_FUNC,
    PROTECTED_STATIC_ATTRIB,
    PACKAGE_TYPE,
    PACKAGE_FUNC,
    PACKAGE_ATTRIB,
    PACKAGE_STATIC_FUNC,
    PACKAGE_STATIC_ATTRIB,
    PRIVATE_TYPE,
    PRIVATE_FUNC,
    PRIVATE_ATTRIB,
    PRIVATE_SLOT,
    PRIVATE_STATIC_FUNC,
    PRIVATE_STATIC_ATTRIB,
    FRIEND,
    RELATED,
    DEFINE,
    PROTOTYPE,
    TYPEDEF,
    ENUM,
    FUNC,
    VAR,
};

enum DoxHighlightClass
{
    COMMENT,
    NORMAL,
    PREPROCESSOR,
    KEYWORD,
    KEYWORDTYPE,
    KEYWORDFLOW,
    STRINGLITERAL,
    CHARLITERAL,
};

enum DoxSimpleSectKind
{
    SEE,
    RETURN,
    AUTHOR,
    AUTHORS,
    VERSION,
    SINCE,
    DATE,
    NOTE,
    WARNING,
    PRE,
    POST,
    COPYRIGHT,
    INVARIANT,
    REMARK,
    ATTENTION,
    PAR,
    RCS,
};

enum DoxVersionNumber
{
    //<xsd:pattern value="\d+\.\d+.*"
};

enum DoxImageKind
{
    HTML,
    LATEX,
    RTF,
};

enum DoxParamListKind
{
    PARAM,
    RETVAL,
    EXCEPTION,
    TEMPLATE_PARAM,
};

enum DoxCharRange
{
    //<xsd:pattern value="[aeiouncAEIOUNC]"
};

enum DoxParamDir
{
    IN,
    OUT,
    IN_OUT,
};

enum DoxAccessor
{
    RETAIN,
    COPY,
    ASSIGN,
    WEAK,
    STRONG,
    UNRETAINED,
};

//</xsd:schema>
