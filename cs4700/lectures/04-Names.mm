<map version="freeplane 1.3.0">
<!--To view this file, download free mind mapping software Freeplane from http://freeplane.sourceforge.net -->
<node TEXT="Names and Bindings" ID="ID_1723255651" CREATED="1283093380553" MODIFIED="1500350842707"><hook NAME="MapStyle">
    <properties show_icon_for_attributes="true"/>

<map_styles>
<stylenode LOCALIZED_TEXT="styles.root_node">
<stylenode LOCALIZED_TEXT="styles.predefined" POSITION="right">
<stylenode LOCALIZED_TEXT="default" MAX_WIDTH="600" COLOR="#000000" STYLE="as_parent">
<font NAME="SansSerif" SIZE="10" BOLD="false" ITALIC="false"/>
</stylenode>
<stylenode LOCALIZED_TEXT="defaultstyle.details"/>
<stylenode LOCALIZED_TEXT="defaultstyle.note"/>
<stylenode LOCALIZED_TEXT="defaultstyle.floating">
<edge STYLE="hide_edge"/>
<cloud COLOR="#f0f0f0" SHAPE="ROUND_RECT"/>
</stylenode>
</stylenode>
<stylenode LOCALIZED_TEXT="styles.user-defined" POSITION="right">
<stylenode LOCALIZED_TEXT="styles.topic" COLOR="#18898b" STYLE="fork">
<font NAME="Liberation Sans" SIZE="10" BOLD="true"/>
</stylenode>
<stylenode LOCALIZED_TEXT="styles.subtopic" COLOR="#cc3300" STYLE="fork">
<font NAME="Liberation Sans" SIZE="10" BOLD="true"/>
</stylenode>
<stylenode LOCALIZED_TEXT="styles.subsubtopic" COLOR="#669900">
<font NAME="Liberation Sans" SIZE="10" BOLD="true"/>
</stylenode>
<stylenode LOCALIZED_TEXT="styles.important">
<icon BUILTIN="yes"/>
</stylenode>
</stylenode>
<stylenode LOCALIZED_TEXT="styles.AutomaticLayout" POSITION="right">
<stylenode LOCALIZED_TEXT="AutomaticLayout.level.root" COLOR="#000000">
<font SIZE="18"/>
</stylenode>
<stylenode LOCALIZED_TEXT="AutomaticLayout.level,1" COLOR="#0033ff">
<font SIZE="16"/>
</stylenode>
<stylenode LOCALIZED_TEXT="AutomaticLayout.level,2" COLOR="#00b439">
<font SIZE="14"/>
</stylenode>
<stylenode LOCALIZED_TEXT="AutomaticLayout.level,3" COLOR="#990000">
<font SIZE="12"/>
</stylenode>
<stylenode LOCALIZED_TEXT="AutomaticLayout.level,4" COLOR="#111111">
<font SIZE="10"/>
</stylenode>
</stylenode>
</stylenode>
</map_styles>
</hook>
<hook NAME="AutomaticEdgeColor" COUNTER="9"/>
<node TEXT="Binding" POSITION="right" ID="ID_1631716674" CREATED="1506439171570" MODIFIED="1506439174297">
<edge COLOR="#00007c"/>
<node TEXT="Names" ID="ID_1309480229" CREATED="1506438964857" MODIFIED="1506439184394">
<node TEXT="Identifiers" ID="ID_1957596854" CREATED="1500396522669" MODIFIED="1506438976902">
<attribute NAME="textbook" VALUE="05-02"/>
<node TEXT="Name forms" ID="ID_1066381124" CREATED="1500396556253" MODIFIED="1500396564574">
<node TEXT="What are legal characters" ID="ID_1774882158" CREATED="1500396564576" MODIFIED="1500396574675"/>
<node TEXT="Are names case sensitive" ID="ID_1915480575" CREATED="1500396575125" MODIFIED="1500396582674"/>
</node>
<node TEXT="Special words" ID="ID_443212069" CREATED="1500396584629" MODIFIED="1500396588394">
<node TEXT="Key words" ID="ID_253970838" CREATED="1500396588397" MODIFIED="1500396590842"/>
<node TEXT="Reserved Words" ID="ID_203052421" CREATED="1500396591238" MODIFIED="1500396594609"/>
</node>
</node>
<node TEXT="Binding" ID="ID_370098955" CREATED="1500519334738" MODIFIED="1506438980323">
<attribute NAME="textbook" VALUE="05-04"/>
<node TEXT="Associating an attribute and an entity" ID="ID_1498953949" CREATED="1500519368440" MODIFIED="1506446927760"/>
<node TEXT="Binding is \emph{static} if it begins before run time and remains unchanged otherwise it is \emph{dynamic}" ID="ID_1701663486" CREATED="1500519463242" MODIFIED="1500519507118"/>
</node>
<node TEXT="Binding Time" ID="ID_1606048834" CREATED="1500519384938" MODIFIED="1506438985832">
<node TEXT="Langauge Design" ID="ID_1535475752" CREATED="1500519404210" MODIFIED="1500519408031"/>
<node TEXT="Language Implementation" ID="ID_1397305128" CREATED="1500519408361" MODIFIED="1500519416679"/>
<node TEXT="Compile Time" ID="ID_42284755" CREATED="1500519417058" MODIFIED="1500519423703"/>
<node TEXT="Link Time" ID="ID_677978520" CREATED="1500519424042" MODIFIED="1500519429759"/>
<node TEXT="Load Time" ID="ID_534123730" CREATED="1500519430122" MODIFIED="1500519432255"/>
<node TEXT="Run Time" ID="ID_1403480066" CREATED="1500519432618" MODIFIED="1500519445895"/>
</node>
</node>
</node>
<node TEXT="Variables" POSITION="right" ID="ID_202477169" CREATED="1506439187430" MODIFIED="1506439190498">
<edge COLOR="#007c00"/>
<node TEXT="Variables" ID="ID_1638060957" CREATED="1506438993668" MODIFIED="1506439192958">
<node TEXT="Variables" ID="ID_1182995203" CREATED="1500519260485" MODIFIED="1506439000096">
<attribute NAME="textbook" VALUE="05-03"/>
<node TEXT="Type" ID="ID_945498601" CREATED="1500519322794" MODIFIED="1500519324599"/>
<node TEXT="Value" ID="ID_1525120871" CREATED="1506439027319" MODIFIED="1506439029391"/>
</node>
<node TEXT="Aliases" ID="ID_181016718" CREATED="1500519286762" MODIFIED="1500519292591">
<node TEXT="If state changes made through one name are visible through another the two names are aliases" ID="ID_1893473115" CREATED="1506439606608" MODIFIED="1506439642092"/>
<node TEXT="Source of many subtle errors" ID="ID_129370031" CREATED="1506439642552" MODIFIED="1506439673237"/>
</node>
<node TEXT="Value" ID="ID_1533598785" CREATED="1506369213919" MODIFIED="1506369216053">
<node TEXT="L-values" ID="ID_1363023446" CREATED="1500519280192" MODIFIED="1500519283494"/>
<node TEXT="R-values" ID="ID_1968997084" CREATED="1500519284186" MODIFIED="1500519286265"/>
</node>
<node TEXT="Type" ID="ID_312531470" CREATED="1500519537522" MODIFIED="1506439039125">
<node TEXT="Static Type" ID="ID_937295674" CREATED="1500519540709" MODIFIED="1500519544271"/>
<node TEXT="Dynamic Type" ID="ID_170655081" CREATED="1500519544650" MODIFIED="1500519546711"/>
</node>
<node TEXT="Named Constants" ID="ID_1353475941" CREATED="1500519985066" MODIFIED="1506439064000">
<attribute NAME="textbook" VALUE="05-08"/>
<node TEXT="Bound to a value only once" ID="ID_1538894678" CREATED="1506369419997" MODIFIED="1506369426082"/>
</node>
</node>
<node TEXT="Lifetime" ID="ID_346749172" CREATED="1500519550458" MODIFIED="1506439199584">
<node TEXT="Lifetime" ID="ID_1148068713" CREATED="1506369309598" MODIFIED="1506439129932">
<attribute NAME="textbook" VALUE="05-06"/>
<node TEXT="Static Variables" ID="ID_782843686" CREATED="1500519555302" MODIFIED="1500519558303"/>
<node TEXT="Stack-Dynamic" ID="ID_605581451" CREATED="1500519558834" MODIFIED="1500519566279"/>
<node TEXT="Explicit Heap-Dynamic" ID="ID_1305366830" CREATED="1500519566762" MODIFIED="1500519574792"/>
<node TEXT="Implicit Heap-Dynamic" ID="ID_679248549" CREATED="1500519585834" MODIFIED="1500519591975"/>
</node>
</node>
<node TEXT="Scope" ID="ID_1253391066" CREATED="1506439099427" MODIFIED="1506439202835">
<node TEXT="Scope" ID="ID_806472397" CREATED="1500519592714" MODIFIED="1506439104518">
<attribute NAME="textbook" VALUE="05-05"/>
<node TEXT="Scope is the range of statements where something is visible" ID="ID_1447766839" CREATED="1500519609890" MODIFIED="1500519643503"/>
<node TEXT="An object is visible if it can be referenced" ID="ID_1134666311" CREATED="1500519643842" MODIFIED="1500519653327"/>
<node TEXT="An entity is local to a scope if it is defined there" ID="ID_554750678" CREATED="1500519687131" MODIFIED="1500519734440"/>
<node TEXT="An entity is global if it is visible everywhere" ID="ID_1061803972" CREATED="1500519734770" MODIFIED="1500519743303"/>
</node>
<node TEXT="Static Scope" ID="ID_1531871850" CREATED="1500519748418" MODIFIED="1506439119562">
<node TEXT="Also called lexical scoping" ID="ID_661321976" CREATED="1506439428396" MODIFIED="1506439436868"/>
<node TEXT="Scoping can be determined prior to run time using only the program text" ID="ID_1870198151" CREATED="1506439437304" MODIFIED="1506439461347"/>
</node>
<node TEXT="Dynamic Scope" ID="ID_876762915" CREATED="1500519902747" MODIFIED="1506439122034">
<node TEXT="Scoping depends on run time context" ID="ID_351262969" CREATED="1506439463615" MODIFIED="1506439474934"/>
<node TEXT="Generally considered to be less reliable" ID="ID_1145714678" CREATED="1506439483903" MODIFIED="1506439496175"/>
<node TEXT="Harder to reason about due to context dependence" ID="ID_650890479" CREATED="1506439496562" MODIFIED="1506439509990"/>
</node>
<node TEXT="Referencing Enviornment" ID="ID_711988226" CREATED="1500519942443" MODIFIED="1506439106582">
<attribute NAME="textbook" VALUE="05-07"/>
<node TEXT="What is visible to a statement?" ID="ID_553112995" CREATED="1506369371770" MODIFIED="1506369382716"/>
</node>
<node TEXT="Block" ID="ID_210965918" CREATED="1500519772618" MODIFIED="1506439110482">
<node TEXT="A set of statements" ID="ID_196338280" CREATED="1506439361465" MODIFIED="1506439369815"/>
<node TEXT="Starts a new scope" ID="ID_350936499" CREATED="1506439370290" MODIFIED="1506439377364"/>
<node TEXT="Generally used in statically scoped languages" ID="ID_734977965" CREATED="1506439527158" MODIFIED="1506439545722"/>
<node TEXT="Introduced by ALGOL and available in many languages." ID="ID_1247416877" CREATED="1506439377848" MODIFIED="1506439410392"/>
</node>
<node TEXT="Declarations" ID="ID_640701779" CREATED="1500519845338" MODIFIED="1506439114402">
<node TEXT="Begining of Block" ID="ID_1125465170" CREATED="1500519849270" MODIFIED="1500519852727"/>
<node TEXT="Anywhere and scope if from declaration on" ID="ID_1363236008" CREATED="1500519853106" MODIFIED="1500519860966"/>
<node TEXT="Anywhere and scope is entire block" ID="ID_550225541" CREATED="1500519861266" MODIFIED="1500519867655"/>
</node>
</node>
</node>
</node>
</map>
