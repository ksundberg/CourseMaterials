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
<hook NAME="AutomaticEdgeColor" COUNTER="1"/>
<node TEXT="Identifiers" POSITION="right" ID="ID_1957596854" CREATED="1500396522669" MODIFIED="1500396541612">
<edge COLOR="#ff0000"/>
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
<node TEXT="Variables" POSITION="right" ID="ID_1182995203" CREATED="1500519260485" MODIFIED="1500519299980">
<edge COLOR="#0000ff"/>
<attribute NAME="textbook" VALUE="05-03"/>
<node TEXT="L-values" ID="ID_1363023446" CREATED="1500519280192" MODIFIED="1500519283494"/>
<node TEXT="R-values" ID="ID_1968997084" CREATED="1500519284186" MODIFIED="1500519286265"/>
<node TEXT="Aliases" ID="ID_181016718" CREATED="1500519286762" MODIFIED="1500519292591"/>
<node TEXT="Type" ID="ID_945498601" CREATED="1500519322794" MODIFIED="1500519324599"/>
</node>
<node TEXT="Binding" POSITION="right" ID="ID_370098955" CREATED="1500519334738" MODIFIED="1500519346269">
<edge COLOR="#00ff00"/>
<attribute NAME="textbook" VALUE="05-04"/>
<node TEXT="Assocating an attribute and an entity" ID="ID_1498953949" CREATED="1500519368440" MODIFIED="1500519384400"/>
<node TEXT="Binding Time" ID="ID_1606048834" CREATED="1500519384938" MODIFIED="1500519391640">
<node TEXT="Langauge Design" ID="ID_1535475752" CREATED="1500519404210" MODIFIED="1500519408031"/>
<node TEXT="Language Implementation" ID="ID_1397305128" CREATED="1500519408361" MODIFIED="1500519416679"/>
<node TEXT="Compile Time" ID="ID_42284755" CREATED="1500519417058" MODIFIED="1500519423703"/>
<node TEXT="Link Time" ID="ID_677978520" CREATED="1500519424042" MODIFIED="1500519429759"/>
<node TEXT="Load Time" ID="ID_534123730" CREATED="1500519430122" MODIFIED="1500519432255"/>
<node TEXT="Run Time" ID="ID_1403480066" CREATED="1500519432618" MODIFIED="1500519445895"/>
</node>
<node TEXT="Binding is \emph{static} if it begins before run time and remains unchanged otherwise it is \emph{dynamic}" ID="ID_1701663486" CREATED="1500519463242" MODIFIED="1500519507118"/>
</node>
<node TEXT="Type" POSITION="right" ID="ID_312531470" CREATED="1500519537522" MODIFIED="1500519540706">
<edge COLOR="#ff00ff"/>
<node TEXT="Static Type" ID="ID_937295674" CREATED="1500519540709" MODIFIED="1500519544271"/>
<node TEXT="Dynamic Type" ID="ID_170655081" CREATED="1500519544650" MODIFIED="1500519546711"/>
</node>
<node TEXT="Lifetime" POSITION="right" ID="ID_346749172" CREATED="1500519550458" MODIFIED="1500519555298">
<edge COLOR="#00ffff"/>
<node TEXT="Static Variables" ID="ID_782843686" CREATED="1500519555302" MODIFIED="1500519558303"/>
<node TEXT="Stack-Dynamic" ID="ID_605581451" CREATED="1500519558834" MODIFIED="1500519566279"/>
<node TEXT="Explicit Heap-Dynamic" ID="ID_1305366830" CREATED="1500519566762" MODIFIED="1500519574792"/>
<node TEXT="Implicit Heap-Dynamic" ID="ID_679248549" CREATED="1500519585834" MODIFIED="1500519591975"/>
</node>
<node TEXT="Scope" POSITION="right" ID="ID_806472397" CREATED="1500519592714" MODIFIED="1500519608523">
<edge COLOR="#ffff00"/>
<attribute NAME="textbook" VALUE="05-05"/>
<node TEXT="Scope is the range of statements where something is visible" ID="ID_1447766839" CREATED="1500519609890" MODIFIED="1500519643503"/>
<node TEXT="An object is visible if it can be referenced" ID="ID_1134666311" CREATED="1500519643842" MODIFIED="1500519653327"/>
<node TEXT="An entity is local to a scope if it is defined there" ID="ID_554750678" CREATED="1500519687131" MODIFIED="1500519734440"/>
<node TEXT="An entity is global if it is visible everywhere" ID="ID_1061803972" CREATED="1500519734770" MODIFIED="1500519743303"/>
</node>
<node TEXT="Static Scope" POSITION="right" ID="ID_1531871850" CREATED="1500519748418" MODIFIED="1500519772183">
<edge COLOR="#7c0000"/>
</node>
<node TEXT="Block" POSITION="right" ID="ID_210965918" CREATED="1500519772618" MODIFIED="1500519800407">
<edge COLOR="#00007c"/>
</node>
<node TEXT="Declarations" POSITION="right" ID="ID_640701779" CREATED="1500519845338" MODIFIED="1500519849267">
<edge COLOR="#7c007c"/>
<node TEXT="Begining of Block" ID="ID_1125465170" CREATED="1500519849270" MODIFIED="1500519852727"/>
<node TEXT="Anywhere and scope if from declaration on" ID="ID_1363236008" CREATED="1500519853106" MODIFIED="1500519860966"/>
<node TEXT="Anywhere and scope is entire block" ID="ID_550225541" CREATED="1500519861266" MODIFIED="1500519867655"/>
</node>
<node TEXT="Dynamic Scope" POSITION="right" ID="ID_876762915" CREATED="1500519902747" MODIFIED="1500519908039">
<edge COLOR="#007c7c"/>
</node>
<node TEXT="Referencing Enviornment" POSITION="right" ID="ID_711988226" CREATED="1500519942443" MODIFIED="1500519956003">
<edge COLOR="#7c7c00"/>
<attribute NAME="textbook" VALUE="05-07"/>
</node>
<node TEXT="Named Constants" POSITION="right" ID="ID_1353475941" CREATED="1500519985066" MODIFIED="1500519997331">
<edge COLOR="#ff0000"/>
<attribute NAME="textbook" VALUE="05-08"/>
</node>
</node>
</map>
