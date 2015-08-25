<map version="freeplane 1.2.0">
<!--To view this file, download free mind mapping software Freeplane from http://freeplane.sourceforge.net -->
<node TEXT="Data Structure Concepts" ID="ID_1723255651" CREATED="1283093380553" MODIFIED="1440538493196"><hook NAME="MapStyle">
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
<hook NAME="AutomaticEdgeColor" COUNTER="3"/>
<node TEXT="Collections" POSITION="right" ID="ID_1604913180" CREATED="1440538493214" MODIFIED="1440538596316">
<edge COLOR="#ff0000"/>
<node TEXT="Data Structures" ID="ID_125031392" CREATED="1440538616739" MODIFIED="1440538627460">
<node TEXT="Abstraction" ID="ID_1285968586" CREATED="1440538627471" MODIFIED="1440538633444">
<node TEXT="A Data Structure is an abstraction" ID="ID_1367438219" CREATED="1440538633452" MODIFIED="1440538644508"/>
<node TEXT="It is a collection of objects" ID="ID_1441276861" CREATED="1440538644811" MODIFIED="1440538663011"/>
<node TEXT="The abstraction is over the relationships" ID="ID_1285595249" CREATED="1440538663452" MODIFIED="1440538677021"/>
</node>
<node TEXT="Example: Set" ID="ID_1279442984" CREATED="1440538678019" MODIFIED="1440538688756">
<node TEXT="A Set is a collection of unique objects" ID="ID_173732133" CREATED="1440538688762" MODIFIED="1440538696370"/>
<node TEXT="Objects must be equality comparable" ID="ID_441373601" CREATED="1440538696803" MODIFIED="1440538722670"/>
<node TEXT="Objects can be added or removed from a set" ID="ID_1335669829" CREATED="1440538722995" MODIFIED="1440538739369"/>
<node TEXT="Set could support:" ID="ID_214540264" CREATED="1440538739947" MODIFIED="1440538751196">
<node TEXT="Intersection" ID="ID_1572864332" CREATED="1440538751203" MODIFIED="1440538753721"/>
<node TEXT="Union" ID="ID_1081365436" CREATED="1440538754123" MODIFIED="1440538755643"/>
<node TEXT="Difference" ID="ID_1780779637" CREATED="1440538755995" MODIFIED="1440538758536"/>
<node TEXT="Not (if universe is defined)" ID="ID_1384186540" CREATED="1440538760179" MODIFIED="1440538767722"/>
</node>
</node>
<node TEXT="Example: Array" ID="ID_176018729" CREATED="1440538805923" MODIFIED="1440538810339">
<node TEXT="An array is a fixed size collection of objects in an order" ID="ID_1309704570" CREATED="1440538810344" MODIFIED="1440538823347"/>
<node TEXT="Objects can be accessed via their index" ID="ID_1390581493" CREATED="1440538823851" MODIFIED="1440538832487"/>
<node TEXT="Objects can not be added or removed, only changed" ID="ID_515614405" CREATED="1440538832939" MODIFIED="1440538841330"/>
</node>
</node>
<node TEXT="Polymorphism" ID="ID_737234593" CREATED="1440539274339" MODIFIED="1440539292939">
<node TEXT="Is not about the contained object" ID="ID_1248024771" CREATED="1440539292944" MODIFIED="1440539306112">
<node TEXT="The abstraction is about the container not the objects contained" ID="ID_1312665366" CREATED="1440539310995" MODIFIED="1440539321784"/>
<node TEXT="We don&apos;t want to write repetitive container code" ID="ID_999287439" CREATED="1440539322227" MODIFIED="1440539332392"/>
<node TEXT="We need a technique (there are several) to write the container without reference to the objects" ID="ID_560515759" CREATED="1440539332921" MODIFIED="1440539357000"/>
</node>
<node TEXT="Concepts" ID="ID_1878275008" CREATED="1440539306379" MODIFIED="1440539308817">
<node TEXT="Sometimes you need to know something about your contained objects" ID="ID_1861744292" CREATED="1440539359035" MODIFIED="1440539376328"/>
<node TEXT="The requirements on contained objects (implicit or explicit) are called a \emph{concept}" ID="ID_836949155" CREATED="1440539376611" MODIFIED="1440539399392"/>
<node TEXT="An object that meets the requirements is said to \emph{model} the concept" ID="ID_462294357" CREATED="1440539399819" MODIFIED="1440539413433"/>
<node TEXT="Concepts should be as general as possible as each requirement limits the utility of the container" ID="ID_1418680743" CREATED="1440539414003" MODIFIED="1440539434296"/>
<node TEXT="Common requirements;" ID="ID_1067020021" CREATED="1440539434683" MODIFIED="1440539439611">
<node TEXT="Default construction" ID="ID_587800278" CREATED="1440539439616" MODIFIED="1440539469312"/>
<node TEXT="Copy / Move construction" ID="ID_1379067607" CREATED="1440539499179" MODIFIED="1440539504112"/>
<node TEXT="Equality comparison" ID="ID_1869797057" CREATED="1440539470115" MODIFIED="1440539483506"/>
<node TEXT="Less than comparison" ID="ID_1504854037" CREATED="1440539483891" MODIFIED="1440539488841"/>
</node>
</node>
<node TEXT="Possible Methods (in C++)" ID="ID_887862921" CREATED="1440539530731" MODIFIED="1440539546259">
<node TEXT="Template programming" LOCALIZED_STYLE_REF="styles.topic" ID="ID_1144395011" CREATED="1440539546264" MODIFIED="1440541149723">
<node TEXT="A way to instruct the compiler how to create a container for any given type" ID="ID_542212647" CREATED="1440539554232" MODIFIED="1440539571977"/>
<node TEXT="This is the technique used in the Standard Template Library" ID="ID_541726780" CREATED="1440539572251" MODIFIED="1440539588568"/>
</node>
<node TEXT="Inheritance" ID="ID_1998410041" CREATED="1440539589451" MODIFIED="1440539593532">
<node TEXT="A way to allow objects to have more than one type" ID="ID_1374999908" CREATED="1440539593537" MODIFIED="1440539612051"/>
<node TEXT="Very common in other languages" ID="ID_187582802" CREATED="1440539612315" MODIFIED="1440539624257"/>
<node TEXT="Less general but this is the OO way" ID="ID_1951990400" CREATED="1440539624459" MODIFIED="1440539632952"/>
</node>
</node>
</node>
<node TEXT="Resource Management" ID="ID_1578243258" CREATED="1440540772931" MODIFIED="1440540791839">
<node TEXT="RAII" ID="ID_1183127554" CREATED="1440540791847" MODIFIED="1440540795652">
<node TEXT="Resource Acquisition Is Initialization" ID="ID_947123701" CREATED="1440540842301" MODIFIED="1440540864133"/>
<node TEXT="Perhaps the most important C++ idiom" LOCALIZED_STYLE_REF="styles.topic" ID="ID_311653794" CREATED="1440540864556" MODIFIED="1440540910845"/>
<node TEXT="Aquire resource in constructor" ID="ID_1855542351" CREATED="1440540884661" MODIFIED="1440540892261"/>
<node TEXT="Release resource in destructor" LOCALIZED_STYLE_REF="styles.topic" ID="ID_773121782" CREATED="1440540892603" MODIFIED="1440540916330"/>
<node TEXT="Many standard library classes exist to do this for you" ID="ID_1660935453" CREATED="1440540874861" MODIFIED="1440540884354"/>
</node>
<node TEXT="Memory" ID="ID_1753552978" CREATED="1440540797429" MODIFIED="1440540800949">
<node TEXT="Collections often need to be able to create objects at runtime" ID="ID_234390044" CREATED="1440540803517" MODIFIED="1440540815338"/>
<node TEXT="Collections may need to be able to destroy objects at runtime" ID="ID_732351981" CREATED="1440540815861" MODIFIED="1440540825528"/>
<node TEXT="All of this requires memory management techniques" ID="ID_915815039" CREATED="1440540825805" MODIFIED="1440540840034"/>
</node>
</node>
</node>
<node TEXT="Techniques" POSITION="right" ID="ID_348515707" CREATED="1440538600371" MODIFIED="1440538604201">
<edge COLOR="#0000ff"/>
<node TEXT="Templates" ID="ID_479931572" CREATED="1440539637299" MODIFIED="1440539642457">
<node TEXT="Overview: Why templates?" ID="ID_1092527913" CREATED="1440539643963" MODIFIED="1440540675582">
<node TEXT="Some code is very similar" ID="ID_83564414" CREATED="1440539658239" MODIFIED="1440539685720"/>
<node TEXT="Often differing only in argument types" ID="ID_1732186093" CREATED="1440539686003" MODIFIED="1440539694417"/>
</node>
<node TEXT="Example: swap" LOCALIZED_STYLE_REF="styles.important" ID="ID_1846678207" CREATED="1440539695147" MODIFIED="1440539767286">
<node TEXT="void swap(int &amp; a, int &amp; b)" ID="ID_248803567" CREATED="1440539707883" MODIFIED="1440539988673"/>
<node TEXT="{" ID="ID_1326362958" CREATED="1440539717139" MODIFIED="1440539720296"/>
<node TEXT="  auto temp = b;" ID="ID_1431096534" CREATED="1440539720571" MODIFIED="1440539727992"/>
<node TEXT="  b = a;" ID="ID_760365790" CREATED="1440539728267" MODIFIED="1440539732488"/>
<node TEXT="  a = b;" ID="ID_306317757" CREATED="1440539732707" MODIFIED="1440539735529"/>
<node TEXT="}" ID="ID_1744364079" CREATED="1440539735859" MODIFIED="1440539737281"/>
<node TEXT="void swap(double &amp; a,double &amp; b)" ID="ID_1120189790" CREATED="1440539737699" MODIFIED="1440539995865"/>
<node TEXT="{" ID="ID_521360297" CREATED="1440539744363" MODIFIED="1440539745633"/>
<node TEXT="  auto temp = b;" ID="ID_1216963916" CREATED="1440539745995" MODIFIED="1440539751321"/>
<node TEXT="  b = a;" ID="ID_1730355328" CREATED="1440539751651" MODIFIED="1440539754193"/>
<node TEXT="  a = b;" ID="ID_1134351722" CREATED="1440539754411" MODIFIED="1440539757200"/>
<node TEXT="}" ID="ID_228339040" CREATED="1440539757443" MODIFIED="1440539759240"/>
</node>
<node TEXT="DRY" ID="ID_142635241" CREATED="1440539812891" MODIFIED="1440539814515">
<node TEXT="These two functions are too similar" ID="ID_680861047" CREATED="1440539814520" MODIFIED="1440539821088"/>
<node TEXT="Writing both violates the DRY (Don&apos;t Repeat Yourself) principle" ID="ID_13007341" CREATED="1440539821435" MODIFIED="1440539837857"/>
<node TEXT="Both are required because C++ is strongly typed" ID="ID_939037650" CREATED="1440539838947" MODIFIED="1440539850564"/>
</node>
<node TEXT="Template Functions" ID="ID_1843384471" CREATED="1440539854107" MODIFIED="1440540630850">
<attribute NAME="textbook" VALUE="16-02"/>
<node TEXT="Instead of writing both functions we can write a template function" ID="ID_194919610" CREATED="1440539858608" MODIFIED="1440539870449"/>
<node TEXT="A template function is a family of functions, each with every possible types" ID="ID_867378643" CREATED="1440539870723" MODIFIED="1440539890185"/>
<node TEXT="During name resolution template functions are checked after normal functions" ID="ID_1105001272" CREATED="1440539891139" MODIFIED="1440539911515"/>
</node>
<node TEXT="Example: template swap" LOCALIZED_STYLE_REF="styles.important" ID="ID_706113670" CREATED="1440539929723" MODIFIED="1440540022954">
<node TEXT="template &lt;typename T&gt;" ID="ID_881147954" CREATED="1440539937364" MODIFIED="1440539946241"/>
<node TEXT="void swap(T &amp; a, T &amp; b)" ID="ID_1351809940" CREATED="1440539946732" MODIFIED="1440539961330"/>
<node TEXT="{" ID="ID_49988415" CREATED="1440539961675" MODIFIED="1440539962962"/>
<node TEXT="  auto temp = b;" ID="ID_1183682983" CREATED="1440539963451" MODIFIED="1440539968125"/>
<node TEXT="  b = a;" ID="ID_69668180" CREATED="1440539968355" MODIFIED="1440539970953"/>
<node TEXT="  a = temp;" ID="ID_1712611835" CREATED="1440539971227" MODIFIED="1440539974920"/>
<node TEXT="}" ID="ID_17777579" CREATED="1440539975363" MODIFIED="1440539977593"/>
</node>
<node TEXT="Swap Concept" ID="ID_908624701" CREATED="1440540003843" MODIFIED="1440540007851">
<node TEXT="What concept is required of swap?" LOCALIZED_STYLE_REF="styles.topic" ID="ID_252502793" CREATED="1440540007854" MODIFIED="1440540603850"/>
<node TEXT="Copy assignable" ID="ID_1288276848" CREATED="1440540574556" MODIFIED="1440540582234"/>
<node TEXT="This template algorithm works for any object that models the concept" ID="ID_1499008067" CREATED="1440540582588" MODIFIED="1440540596246"/>
</node>
</node>
<node TEXT="Memory" ID="ID_853356730" CREATED="1440540761717" MODIFIED="1440540766434"/>
</node>
<node TEXT="Linked List" POSITION="right" ID="ID_79091090" CREATED="1440538604691" MODIFIED="1440538614465">
<edge COLOR="#00ff00"/>
</node>
</node>
</map>
