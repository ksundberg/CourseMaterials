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
<node TEXT="Possible Methods (in C++)" ID="ID_887862921" CREATED="1440539530731" MODIFIED="1444935296495">
<attribute NAME="textbook" VALUE="11-06"/>
<node TEXT="Overloading" ID="ID_1695323696" CREATED="1444050302459" MODIFIED="1444050314532">
<node TEXT="Have multiple calls for the same function" ID="ID_1279328599" CREATED="1444050314542" MODIFIED="1444050328293"/>
<node TEXT="Especially useful for operators" ID="ID_569773117" CREATED="1444050328783" MODIFIED="1444050341107"/>
</node>
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
<node TEXT="  a = temp;" ID="ID_306317757" CREATED="1440539732707" MODIFIED="1444933546925"/>
<node TEXT="}" ID="ID_1744364079" CREATED="1440539735859" MODIFIED="1440539737281"/>
<node TEXT="void swap(double &amp; a,double &amp; b)" ID="ID_1120189790" CREATED="1440539737699" MODIFIED="1440539995865"/>
<node TEXT="{" ID="ID_521360297" CREATED="1440539744363" MODIFIED="1440539745633"/>
<node TEXT="  auto temp = b;" ID="ID_1216963916" CREATED="1440539745995" MODIFIED="1440539751321"/>
<node TEXT="  b = a;" ID="ID_1730355328" CREATED="1440539751651" MODIFIED="1440539754193"/>
<node TEXT="  a = temp;" ID="ID_1134351722" CREATED="1440539754411" MODIFIED="1444933551035"/>
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
<node TEXT="Template class" ID="ID_731774818" CREATED="1440783395413" MODIFIED="1440783956031">
<attribute NAME="textbook" VALUE="16-03"/>
<node TEXT="You can also write templated classes" ID="ID_987426859" CREATED="1440783405914" MODIFIED="1440783415785"/>
<node TEXT="Provides tools for composing patterns of types" ID="ID_1610912425" CREATED="1440783416244" MODIFIED="1440783443515"/>
<node TEXT="You can write special versions for some types called \emph{specializations}" ID="ID_1705248708" CREATED="1440783652597" MODIFIED="1440783677210"/>
<node TEXT="This is a very abusable language feature ... be careful ... be sane" ID="ID_199821403" CREATED="1440783698805" MODIFIED="1440783719752"/>
</node>
<node TEXT="Template Fibbonaci (not quite sane)" LOCALIZED_STYLE_REF="styles.important" ID="ID_247828700" CREATED="1440783505109" MODIFIED="1440783782789">
<node TEXT="template&lt;int n&gt;" ID="ID_1962006678" CREATED="1440783527682" MODIFIED="1440783537210"/>
<node TEXT="struct fibb" ID="ID_327131018" CREATED="1440783537764" MODIFIED="1440783544287"/>
<node TEXT="{" ID="ID_1929111933" CREATED="1440783544701" MODIFIED="1440783546219"/>
<node TEXT="  const int value =" ID="ID_1788991682" CREATED="1440783546629" MODIFIED="1440783806254"/>
<node TEXT="    fibb&lt;n-1&gt;::value + fib&lt;n-2&gt;::value;" ID="ID_1224709822" CREATED="1440783786205" MODIFIED="1440783819578"/>
<node TEXT="};" ID="ID_1213744830" CREATED="1440783586349" MODIFIED="1440783591355"/>
<node TEXT="" ID="ID_131977012" CREATED="1440783591893" MODIFIED="1440783591893"/>
<node TEXT="template&lt;&gt;" ID="ID_912963904" CREATED="1440783601277" MODIFIED="1440783606262"/>
<node TEXT="struct fibb&lt;0&gt; {const int value = 1;};" ID="ID_290482277" CREATED="1440783606741" MODIFIED="1440783625040"/>
<node TEXT="" ID="ID_1605754905" CREATED="1440783636941" MODIFIED="1440783636941"/>
<node TEXT="template&lt;&gt;" ID="ID_42362846" CREATED="1440783601277" MODIFIED="1440783606262"/>
<node TEXT="struct fibb&lt;1&gt; {const int value = 1;};" ID="ID_469948898" CREATED="1440783606741" MODIFIED="1440783648651"/>
</node>
</node>
<node TEXT="Memory" ID="ID_853356730" CREATED="1440540761717" MODIFIED="1440540766434">
<node TEXT="Reference and Value Semantics" ID="ID_1777829472" CREATED="1440784037173" MODIFIED="1440784049862">
<node TEXT="Variables are containers of values" LOCALIZED_STYLE_REF="styles.topic" ID="ID_609676703" CREATED="1440784127741" MODIFIED="1440784212961"/>
<node TEXT="When possible treat variables as values" LOCALIZED_STYLE_REF="styles.topic" ID="ID_909068728" CREATED="1440784049871" MODIFIED="1440784212959">
<node TEXT="Ignores storage details" ID="ID_277450604" CREATED="1440784079263" MODIFIED="1440784091478"/>
<node TEXT="Easier to reason about -- more math-like" ID="ID_275515351" CREATED="1440784091909" MODIFIED="1440784104235"/>
</node>
<node TEXT="Sometimes we need to talk about the variable itself" LOCALIZED_STYLE_REF="styles.topic" ID="ID_775164389" CREATED="1440784139535" MODIFIED="1440784212953">
<node TEXT="A name that refers to a variable and not a value is a \emph{reference}" ID="ID_1248653770" CREATED="1440784153775" MODIFIED="1440784173651"/>
</node>
<node TEXT="Most (not all) other language only have reference semantics" ID="ID_468094252" CREATED="1440784189981" MODIFIED="1440784205184"/>
</node>
<node TEXT="Memory" ID="ID_1753552978" CREATED="1440540797429" MODIFIED="1440540800949">
<node TEXT="Collections often need to be able to create objects at runtime" ID="ID_234390044" CREATED="1440540803517" MODIFIED="1440540815338"/>
<node TEXT="Collections may need to be able to destroy objects at runtime" ID="ID_732351981" CREATED="1440540815861" MODIFIED="1440540825528"/>
<node TEXT="All of this requires memory management techniques" ID="ID_915815039" CREATED="1440540825805" MODIFIED="1440540840034"/>
</node>
<node TEXT="Section of Memory" ID="ID_227339233" CREATED="1440784236109" MODIFIED="1440784267598">
<node TEXT="Variables can be located in one of three locations:" ID="ID_998404306" CREATED="1440784267603" MODIFIED="1440784281318"/>
<node TEXT="Global Data" ID="ID_1691765038" CREATED="1440784291933" MODIFIED="1440784299294">
<node TEXT="Constants" ID="ID_202870951" CREATED="1440784299303" MODIFIED="1440784305250"/>
<node TEXT="Global variables" ID="ID_263095960" CREATED="1440784305741" MODIFIED="1440784309286"/>
<node TEXT="Static variables" ID="ID_1793121347" CREATED="1440784309645" MODIFIED="1440784312875"/>
</node>
<node TEXT="Stack" ID="ID_1256903441" CREATED="1440784313965" MODIFIED="1440784317173">
<node TEXT="Local variables" ID="ID_1659858357" CREATED="1440784317178" MODIFIED="1440784329254"/>
<node TEXT="Function call information" ID="ID_212137543" CREATED="1440784329765" MODIFIED="1440784359923"/>
</node>
<node TEXT="Heap" ID="ID_39134525" CREATED="1440784361469" MODIFIED="1440784363990">
<node TEXT="Dynamically allocated memory" ID="ID_63596355" CREATED="1440784363995" MODIFIED="1440784370235"/>
</node>
</node>
<node TEXT="Using the Heap" ID="ID_364358950" CREATED="1440784377509" MODIFIED="1440784384053">
<node TEXT="You can create new variables at \emph{run time} on the heap" ID="ID_1702667" CREATED="1440784384056" MODIFIED="1440784420235"/>
<node TEXT="The lifetime of heap allocated memory is not automatically managed" ID="ID_794349481" CREATED="1440784397700" MODIFIED="1440784466499"/>
<node TEXT="If you create a variable, don&apos;t destroy it and lose the ability to refer to it -- you have made a \emph{memory leak}" ID="ID_698609512" CREATED="1440784469101" MODIFIED="1440784502410"/>
</node>
<node TEXT="The good, the bad, and the ugly" ID="ID_111811570" CREATED="1440784530653" MODIFIED="1440784612315">
<node TEXT="There are a number of ways to allocate memory -- They are not created equally." ID="ID_1423684291" CREATED="1440784612805" MODIFIED="1440784631178"/>
<node TEXT="C style" ID="ID_112685995" CREATED="1440784631805" MODIFIED="1440784652238">
<node TEXT="malloc(bytes) to aquire memory" ID="ID_478973187" CREATED="1440784652247" MODIFIED="1440784668818"/>
<node TEXT="free() to release" ID="ID_706249282" CREATED="1440784669173" MODIFIED="1440784672091"/>
<node TEXT="This memory has no type -- never do this in C++ code" ID="ID_1715744029" CREATED="1440784672373" MODIFIED="1440784690584"/>
</node>
<node TEXT="Low level C++" ID="ID_576001896" CREATED="1440784691765" MODIFIED="1440784702205">
<node TEXT="new to aquire memory" ID="ID_75279558" CREATED="1440784702210" MODIFIED="1440784708392"/>
<node TEXT="delete to release" ID="ID_1847938570" CREATED="1440784708789" MODIFIED="1440784712339"/>
<node TEXT="new and delete are radioactive.  Someone has to use them, but you don&apos;t want it to be you" ID="ID_141774025" CREATED="1440784712861" MODIFIED="1440784737387"/>
</node>
<node TEXT="Modern C++" ID="ID_327490570" CREATED="1440784738261" MODIFIED="1440784759759">
<node TEXT="use make\_shared" ID="ID_1023209916" CREATED="1440784744882" MODIFIED="1440784773811"/>
<node TEXT="use make\_unique if available" ID="ID_314945854" CREATED="1440784774245" MODIFIED="1440784779818"/>
</node>
</node>
<node TEXT="Modern C++ pointers" ID="ID_1885485165" CREATED="1440784784949" MODIFIED="1440784789594">
<node TEXT="Unique Pointers" ID="ID_523657761" CREATED="1440784796229" MODIFIED="1440784799543"/>
<node TEXT="Shared Pointers" ID="ID_1686188853" CREATED="1440784790349" MODIFIED="1440784796003"/>
<node TEXT="Weak Pointers" ID="ID_775335822" CREATED="1440784800654" MODIFIED="1440784808719"/>
</node>
<node TEXT="RAII" ID="ID_1183127554" CREATED="1440540791847" MODIFIED="1440540795652">
<node TEXT="Resource Acquisition Is Initialization" ID="ID_947123701" CREATED="1440540842301" MODIFIED="1440540864133"/>
<node TEXT="Perhaps the most important C++ idiom" LOCALIZED_STYLE_REF="styles.topic" ID="ID_311653794" CREATED="1440540864556" MODIFIED="1440540910845"/>
<node TEXT="Aquire resource in constructor" ID="ID_1855542351" CREATED="1440540884661" MODIFIED="1440540892261"/>
<node TEXT="Release resource in destructor" LOCALIZED_STYLE_REF="styles.topic" ID="ID_773121782" CREATED="1440540892603" MODIFIED="1440540916330"/>
<node TEXT="Many standard library classes exist to do this for you" ID="ID_1660935453" CREATED="1440540874861" MODIFIED="1440540884354"/>
</node>
</node>
</node>
<node TEXT="Linked List" POSITION="right" ID="ID_79091090" CREATED="1440538604691" MODIFIED="1440538614465">
<edge COLOR="#00ff00"/>
<node TEXT="Structure" ID="ID_787382842" CREATED="1440785011157" MODIFIED="1440785029003">
<node TEXT="Linked List Concept" ID="ID_181512582" CREATED="1440785032925" MODIFIED="1444935364598">
<attribute NAME="textbook" VALUE="17-01"/>
<node TEXT="A linked list is a simple data structure" ID="ID_1949697616" CREATED="1440785046144" MODIFIED="1440785057050"/>
<node TEXT="Composed of nodes" ID="ID_1690431274" CREATED="1440785057501" MODIFIED="1440785076123"/>
<node TEXT="Each node has a value and a pointer to the next node" ID="ID_1273429159" CREATED="1440785076421" MODIFIED="1440785088087"/>
</node>
<node TEXT="Operations" ID="ID_844921947" CREATED="1440785257493" MODIFIED="1444935381355">
<attribute NAME="textbook" VALUE="17-02"/>
<node TEXT="Searching" ID="ID_1044195740" CREATED="1440785122965" MODIFIED="1440785125132">
<node TEXT="Find a value in the list" ID="ID_1469947515" CREATED="1440785294997" MODIFIED="1440785299584"/>
</node>
<node TEXT="Insertion" ID="ID_1805465560" CREATED="1440785107421" MODIFIED="1440785110382">
<node TEXT="Add a new value (and a new node) at any location" ID="ID_1852615700" CREATED="1440785276966" MODIFIED="1440785287303"/>
</node>
<node TEXT="Deletion" ID="ID_524453729" CREATED="1440785110789" MODIFIED="1440785113899">
<node TEXT="Remove a value from list" ID="ID_1238092160" CREATED="1440785288749" MODIFIED="1440785293399"/>
</node>
</node>
<node TEXT="Performance" ID="ID_999297947" CREATED="1440785101909" MODIFIED="1440785106603">
<node TEXT="The linked list is important for pedagogy" ID="ID_314370256" CREATED="1440785160886" MODIFIED="1440785178789"/>
<node TEXT="The performance of a linked list on modern hardware is terrible" ID="ID_1297595643" CREATED="1440785179142" MODIFIED="1440785195119"/>
<node TEXT="Just use std::vector" ID="ID_1926971977" CREATED="1440785195357" MODIFIED="1440785198827"/>
</node>
</node>
<node TEXT="Implementation" ID="ID_263559065" CREATED="1440785029373" MODIFIED="1440785031770">
<node TEXT="Node" LOCALIZED_STYLE_REF="styles.important" ID="ID_73778406" CREATED="1440785316973" MODIFIED="1444935522031">
<node TEXT="template&lt;typename T&gt;" ID="ID_1728910187" CREATED="1440785353325" MODIFIED="1444933563125"/>
<node TEXT="struct Node" ID="ID_1549917560" CREATED="1440785321103" MODIFIED="1440785326411"/>
<node TEXT="{" ID="ID_1518771268" CREATED="1440785326821" MODIFIED="1440785327907"/>
<node TEXT="  T value;" ID="ID_75019223" CREATED="1440785328477" MODIFIED="1440785333983"/>
<node TEXT="  std::shared_ptr&lt;Node&gt; next;" ID="ID_1058678228" CREATED="1440785334453" MODIFIED="1440785349850"/>
<node TEXT="};" ID="ID_1829162777" CREATED="1440785350237" MODIFIED="1440785352412"/>
</node>
<node TEXT="Find" LOCALIZED_STYLE_REF="styles.important" ID="ID_1283854934" CREATED="1440785420870" MODIFIED="1444935520070">
<node TEXT="template&lt;typename T&gt;" ID="ID_874510129" CREATED="1440785423603" MODIFIED="1444933734415"/>
<node TEXT="std::shared_ptr&lt;Node&lt;T&gt;&gt; find(" ID="ID_1363093251" CREATED="1440785432821" MODIFIED="1440785637141"/>
<node TEXT="  T const &amp; target" ID="ID_752759678" CREATED="1440785432821" MODIFIED="1440785656767"/>
<node TEXT=" ,std::shared_ptr&lt;Node&lt;T&gt;&gt; list);" ID="ID_1308906021" CREATED="1440785432821" MODIFIED="1440785664506"/>
</node>
<node TEXT="Find" LOCALIZED_STYLE_REF="styles.important" ID="ID_41513824" CREATED="1440785420870" MODIFIED="1440785566671">
<node TEXT="template&lt;typename T&gt;" ID="ID_1450448510" CREATED="1440785423603" MODIFIED="1444933729641"/>
<node TEXT="std::shared_ptr&lt;Node&lt;T&gt;&gt; find(" ID="ID_1945733915" CREATED="1440785432821" MODIFIED="1440785637141"/>
<node TEXT="  T const &amp; target" ID="ID_300398624" CREATED="1440785432821" MODIFIED="1440785656767"/>
<node TEXT=" ,std::shared_ptr&lt;Node&lt;T&gt;&gt; list)" ID="ID_383557528" CREATED="1440785432821" MODIFIED="1440785707938"/>
<node TEXT="{" ID="ID_1099158256" CREATED="1440785468790" MODIFIED="1440785470267"/>
<node TEXT="  if(!list) return list;" ID="ID_654895245" CREATED="1440785473517" MODIFIED="1440785480909"/>
<node TEXT="  if(list-&gt;value == target) return list;" ID="ID_1188223461" CREATED="1440785481349" MODIFIED="1440785497979"/>
<node TEXT="  return find(target,list-&gt;next);" ID="ID_1462419743" CREATED="1440785498445" MODIFIED="1440785509447"/>
<node TEXT="}" ID="ID_1861146745" CREATED="1440785470990" MODIFIED="1440785472646"/>
</node>
<node TEXT="Insert" LOCALIZED_STYLE_REF="styles.important" ID="ID_1843023754" CREATED="1444933704866" MODIFIED="1444933898800">
<node TEXT="tempate&lt;typename T&gt;" ID="ID_321024647" CREATED="1444933715492" MODIFIED="1444933723121"/>
<node TEXT="void insertAfter(T const &amp; value" ID="ID_331470446" CREATED="1444933762482" MODIFIED="1444935136522"/>
<node TEXT="  ,std::shared_ptr&lt;Node&lt;T&gt;&gt; location);" ID="ID_1887765435" CREATED="1444933762482" MODIFIED="1444935131986"/>
</node>
<node TEXT="Insert" LOCALIZED_STYLE_REF="styles.important" ID="ID_1770094372" CREATED="1444933800226" MODIFIED="1444933898803">
<node TEXT="tempate&lt;typename T&gt;" ID="ID_1427493248" CREATED="1444933715492" MODIFIED="1444933723121"/>
<node TEXT="void insertAfter(T const &amp; value" ID="ID_1254926642" CREATED="1444933762482" MODIFIED="1444935136522"/>
<node TEXT="  ,std::shared_ptr&lt;Node&lt;T&gt;&gt; location)" ID="ID_1408570457" CREATED="1444933762482" MODIFIED="1444935175829"/>
<node TEXT="{" ID="ID_1502961767" CREATED="1444933810818" MODIFIED="1444933812226"/>
<node TEXT="  if(!location) return;" ID="ID_992916649" CREATED="1444933873802" MODIFIED="1444933879176"/>
<node TEXT="  auto node = std::make_shared&lt;Node&lt;T&gt;&gt;(value);" ID="ID_871698946" CREATED="1444933812647" MODIFIED="1444933842874"/>
<node TEXT="  node-&gt;next = location-&gt;next;" ID="ID_1762591642" CREATED="1444933843394" MODIFIED="1444933872707"/>
<node TEXT="  location-&gt;next = node;" ID="ID_594739292" CREATED="1444933882816" MODIFIED="1444933889525"/>
<node TEXT="}" ID="ID_1353745195" CREATED="1444933889977" MODIFIED="1444933892138"/>
</node>
<node TEXT="Delete" LOCALIZED_STYLE_REF="styles.important" ID="ID_1762662247" CREATED="1444933936184" MODIFIED="1444934094997">
<node TEXT="template&lt;typename T&gt;" ID="ID_550327517" CREATED="1444933940226" MODIFIED="1444933945074"/>
<node TEXT="void deleteNext(std::shared_ptr&lt;Node&lt;T&gt;&gt; previous);" ID="ID_1619727026" CREATED="1444933945562" MODIFIED="1444933973753"/>
</node>
<node TEXT="Delete" LOCALIZED_STYLE_REF="styles.important" ID="ID_75223410" CREATED="1444933936184" MODIFIED="1444934094995">
<node TEXT="template&lt;typename T&gt;" ID="ID_797944553" CREATED="1444933940226" MODIFIED="1444933945074"/>
<node TEXT="void deleteNext(std::shared_ptr&lt;Node&lt;T&gt;&gt; previous)" ID="ID_884515701" CREATED="1444933945562" MODIFIED="1444933989470"/>
<node TEXT="{" ID="ID_992168262" CREATED="1444933989938" MODIFIED="1444933991311"/>
<node TEXT="  if(!previous) return;" ID="ID_732371881" CREATED="1444933991713" MODIFIED="1444934000448"/>
<node TEXT="  if(!previous-&gt;next) return;" ID="ID_289980100" CREATED="1444934000857" MODIFIED="1444934032657"/>
<node TEXT="  previous-&gt;next = previous-&gt;next-&gt;next;" ID="ID_472454865" CREATED="1444934033442" MODIFIED="1444934085049"/>
<node TEXT="}" ID="ID_1024615910" CREATED="1444934065338" MODIFIED="1444934066577"/>
</node>
<node TEXT="Copy and Move" ID="ID_524115924" CREATED="1444934098874" MODIFIED="1444935320166">
<attribute NAME="textbook" VALUE="11-05"/>
<node TEXT="Shallow vs Deep copy" ID="ID_1083977319" CREATED="1444934101824" MODIFIED="1444934121608">
<node TEXT="Copy the pointer" ID="ID_1477249686" CREATED="1444934121611" MODIFIED="1444934124479"/>
<node TEXT="Copy the data" ID="ID_1587119339" CREATED="1444934124729" MODIFIED="1444934130447"/>
</node>
<node TEXT="Move is a optimization of Copy" ID="ID_951945554" CREATED="1444934133497" MODIFIED="1444934148130">
<node TEXT="If you know that the copy source is being destroyed then a shallow copy is good enough" ID="ID_55195930" CREATED="1444934148137" MODIFIED="1444934171629"/>
<node TEXT="The compiler knows what values are being destroyed, they are r-values that are not l-values" ID="ID_389676570" CREATED="1444934177938" MODIFIED="1444934215801"/>
<node TEXT="You can write code to be invoked by the compiler in this situation" ID="ID_1038501498" CREATED="1444934216248" MODIFIED="1444934229281"/>
<node TEXT="You can use std::move to instruct that a move happen -- but this is usually not needed" ID="ID_879950617" CREATED="1444934239283" MODIFIED="1444934262965"/>
</node>
</node>
</node>
</node>
</node>
</map>
