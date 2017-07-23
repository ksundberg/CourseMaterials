<map version="freeplane 1.3.0">
<!--To view this file, download free mind mapping software Freeplane from http://freeplane.sourceforge.net -->
<node TEXT="Type and Abstraction" ID="ID_1723255651" CREATED="1283093380553" MODIFIED="1500520068038"><hook NAME="MapStyle">
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
<hook NAME="AutomaticEdgeColor" COUNTER="10"/>
<node TEXT="Type System" POSITION="right" ID="ID_1233187033" CREATED="1500520068042" MODIFIED="1500520149986">
<edge COLOR="#ff0000"/>
<attribute NAME="textbook" VALUE="06-01"/>
<node TEXT="Type constructors" ID="ID_1040734927" CREATED="1500520151587" MODIFIED="1500520156815"/>
<node TEXT="Descriptors" ID="ID_216363492" CREATED="1500520158163" MODIFIED="1500520162439"/>
</node>
<node TEXT="Primitive Types" POSITION="right" ID="ID_382357758" CREATED="1500520173739" MODIFIED="1500520188907">
<edge COLOR="#0000ff"/>
<attribute NAME="textbook" VALUE="06-02"/>
<node TEXT="Integer" ID="ID_1913572718" CREATED="1500520189955" MODIFIED="1500520192416"/>
<node TEXT="Floating Point" ID="ID_1672259520" CREATED="1500520192731" MODIFIED="1500520197112"/>
<node TEXT="Complex" ID="ID_1834028454" CREATED="1500520197515" MODIFIED="1500520201671"/>
<node TEXT="Decimal" ID="ID_304219058" CREATED="1500520202027" MODIFIED="1500520204079"/>
<node TEXT="Boolean" ID="ID_1206085038" CREATED="1500520204459" MODIFIED="1500520206408"/>
<node TEXT="Character" ID="ID_1790485366" CREATED="1500520206731" MODIFIED="1500520208495"/>
</node>
<node TEXT="Strings" POSITION="right" ID="ID_437417811" CREATED="1500520219379" MODIFIED="1500520229315">
<edge COLOR="#00ff00"/>
<attribute NAME="textbook" VALUE="06-03"/>
<node TEXT="Design Choices" ID="ID_1372201482" CREATED="1500520248235" MODIFIED="1500520255331">
<node TEXT="Character array or primitive" ID="ID_1347572261" CREATED="1500520255334" MODIFIED="1500520261144"/>
<node TEXT="Static or Dynamic length" ID="ID_301618154" CREATED="1500520261467" MODIFIED="1500520266183"/>
</node>
<node TEXT="String operations" ID="ID_599753256" CREATED="1500520268915" MODIFIED="1500520271255">
<node TEXT="Slice" ID="ID_1689864562" CREATED="1500520276427" MODIFIED="1500520280223"/>
<node TEXT="Concatenate" ID="ID_1371454150" CREATED="1500520304883" MODIFIED="1500520319472"/>
<node TEXT="Compare" ID="ID_1148465804" CREATED="1500520319883" MODIFIED="1500520325656"/>
<node TEXT="Regular Expression Matching" ID="ID_561365974" CREATED="1500520352147" MODIFIED="1500520361648"/>
</node>
<node TEXT="String length" ID="ID_1488808258" CREATED="1500520389323" MODIFIED="1500520393027">
<node TEXT="Static" ID="ID_1067755375" CREATED="1500520393030" MODIFIED="1500520394640"/>
<node TEXT="Limited dynamic" ID="ID_709401474" CREATED="1500520394963" MODIFIED="1500520401016"/>
<node TEXT="Dynamic" ID="ID_1437724047" CREATED="1500520401443" MODIFIED="1500520404568"/>
</node>
<node TEXT="Implementations" ID="ID_1575058846" CREATED="1500520422851" MODIFIED="1500520425680"/>
</node>
<node TEXT="Enumarations" POSITION="right" ID="ID_194854517" CREATED="1500520426771" MODIFIED="1500520440427">
<edge COLOR="#ff00ff"/>
<attribute NAME="textbook" VALUE="06-04"/>
</node>
<node TEXT="Array" POSITION="right" ID="ID_1186221578" CREATED="1500520477619" MODIFIED="1500520489851">
<edge COLOR="#00ffff"/>
<attribute NAME="textbook" VALUE="06-05"/>
</node>
<node TEXT="Array Categories" POSITION="right" ID="ID_373625368" CREATED="1500520509595" MODIFIED="1500520515900">
<edge COLOR="#ffff00"/>
<node TEXT="Static" ID="ID_1472292676" CREATED="1500520515902" MODIFIED="1500520518152"/>
<node TEXT="Fixed stack dynamic" ID="ID_289968629" CREATED="1500520518571" MODIFIED="1500520524088"/>
<node TEXT="fixed heap dynamic" ID="ID_1875128739" CREATED="1500520524403" MODIFIED="1500520528872"/>
<node TEXT="heap dynamic" ID="ID_515245213" CREATED="1500520529299" MODIFIED="1500520531776"/>
</node>
<node TEXT="Array Operations" POSITION="right" ID="ID_186848434" CREATED="1500520550851" MODIFIED="1500520558983">
<edge COLOR="#7c0000"/>
</node>
<node TEXT="Array Implementation" POSITION="right" ID="ID_174248842" CREATED="1500520559995" MODIFIED="1500520572592">
<edge COLOR="#00007c"/>
</node>
<node TEXT="Lists" POSITION="right" ID="ID_27442776" CREATED="1500520720251" MODIFIED="1500520734243">
<edge COLOR="#7c7c00"/>
<attribute NAME="textbook" VALUE="06-09"/>
</node>
<node TEXT="Associative Arrays" POSITION="right" ID="ID_1529733792" CREATED="1500520573099" MODIFIED="1500520607179">
<edge COLOR="#007c00"/>
<attribute NAME="textbook" VALUE="06-06"/>
</node>
<node TEXT="Records" POSITION="right" ID="ID_1639359770" CREATED="1500520618035" MODIFIED="1500520629746">
<edge COLOR="#7c007c"/>
<attribute NAME="textbook" VALUE="06-07"/>
</node>
<node TEXT="Tuples" POSITION="right" ID="ID_510159792" CREATED="1500520656107" MODIFIED="1500520672410">
<edge COLOR="#007c7c"/>
<attribute NAME="textbook" VALUE="06-08"/>
</node>
<node TEXT="Unions" POSITION="right" ID="ID_1469131663" CREATED="1500520812523" MODIFIED="1500520823970">
<edge COLOR="#ff0000"/>
<attribute NAME="textbook" VALUE="06-10"/>
<node TEXT="Discriminated or Free" ID="ID_1996548466" CREATED="1500520825283" MODIFIED="1500520841552"/>
</node>
<node TEXT="Pointers" POSITION="right" ID="ID_998364589" CREATED="1500520849939" MODIFIED="1500520863298">
<edge COLOR="#0000ff"/>
<attribute NAME="textbook" VALUE="06-11"/>
<node TEXT="Entity is a reference to some other" ID="ID_458382794" CREATED="1500520898852" MODIFIED="1500520911976"/>
<node TEXT="Pointers are addresses" ID="ID_1093382788" CREATED="1500520966611" MODIFIED="1500520971784"/>
<node TEXT="References refer to objects" ID="ID_1204484524" CREATED="1500520972139" MODIFIED="1500521121152"/>
</node>
<node TEXT="Pointer Operations" POSITION="right" ID="ID_503648560" CREATED="1500520912891" MODIFIED="1500520916223">
<edge COLOR="#00ff00"/>
</node>
<node TEXT="Pointer Problems" POSITION="right" ID="ID_1548418832" CREATED="1500520916571" MODIFIED="1500520927992">
<edge COLOR="#ff00ff"/>
<node TEXT="Dangling Pointer" ID="ID_1229858475" CREATED="1500520930284" MODIFIED="1500520935376"/>
<node TEXT="Garbage" ID="ID_484310557" CREATED="1500520936635" MODIFIED="1500520960944"/>
</node>
<node TEXT="Garbage Collection" POSITION="right" ID="ID_424812365" CREATED="1500521134556" MODIFIED="1500521139800">
<edge COLOR="#00ffff"/>
</node>
<node TEXT="Heap Management" POSITION="right" ID="ID_101669246" CREATED="1500521166668" MODIFIED="1500521171040">
<edge COLOR="#ffff00"/>
</node>
<node TEXT="Type Checking" POSITION="right" ID="ID_553737435" CREATED="1500521190964" MODIFIED="1500521216282">
<edge COLOR="#7c0000"/>
<attribute NAME="textbook" VALUE="06-12"/>
<node TEXT="Coercion" ID="ID_433509459" CREATED="1500521202996" MODIFIED="1500521206130"/>
<node TEXT="Type checking" ID="ID_570786583" CREATED="1500521220532" MODIFIED="1500521228880"/>
<node TEXT="Strong Types" ID="ID_1810598682" CREATED="1500521261004" MODIFIED="1500521274594">
<attribute NAME="textbook" VALUE="06-13"/>
</node>
<node TEXT="Type Equivalence" ID="ID_104126849" CREATED="1500521280027" MODIFIED="1500521298747">
<attribute NAME="textbook" VALUE="06-14"/>
</node>
</node>
<node TEXT="User Defined Data Types" POSITION="right" ID="ID_174221598" CREATED="1500521428836" MODIFIED="1500521446843">
<edge COLOR="#00007c"/>
<attribute NAME="textbook" VALUE="11-02"/>
</node>
<node TEXT="Encapsulation and Information Hiding" POSITION="right" ID="ID_812475313" CREATED="1500521563268" MODIFIED="1500521594009">
<edge COLOR="#007c00"/>
<attribute NAME="textbook" VALUE="11-04"/>
</node>
<node TEXT="Parameterized Types" POSITION="right" ID="ID_252198774" CREATED="1500521601612" MODIFIED="1500521617115">
<edge COLOR="#7c007c"/>
<attribute NAME="textbook" VALUE="11-05"/>
</node>
</node>
</map>
