<map version="freeplane 1.3.0">
<!--To view this file, download free mind mapping software Freeplane from http://freeplane.sourceforge.net -->
<node TEXT="Subprograms" ID="ID_1723255651" CREATED="1283093380553" MODIFIED="1501218051996"><hook NAME="MapStyle">
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
<node TEXT="Subprogram" POSITION="right" ID="ID_45417054" CREATED="1501218052016" MODIFIED="1501218241934">
<edge COLOR="#ff0000"/>
<node TEXT="Definitions" ID="ID_418503463" CREATED="1510637414947" MODIFIED="1510637425320">
<node TEXT="Subprogram" ID="ID_1213636000" CREATED="1501218091773" MODIFIED="1510637437434">
<attribute NAME="textbook" VALUE="09-02"/>
<node TEXT="Basic Subprograms have:" LOCALIZED_STYLE_REF="styles.topic" ID="ID_565595966" CREATED="1510637270237" MODIFIED="1510680120766">
<node TEXT="Single entry point" ID="ID_504962201" CREATED="1501218095927" MODIFIED="1510677241045"/>
<node TEXT="Suspend the caller" ID="ID_1397643061" CREATED="1501218110581" MODIFIED="1510637296834"/>
</node>
<node TEXT="Multiple entry points gives coroutines" LOCALIZED_STYLE_REF="styles.topic" ID="ID_1057456378" CREATED="1510637311564" MODIFIED="1510677246978"/>
<node TEXT="Avoiding suspension gives concurrency" ID="ID_1973750084" CREATED="1510637336719" MODIFIED="1510637360707"/>
</node>
<node TEXT="Definition" ID="ID_1639983511" CREATED="1510637439094" MODIFIED="1510637454324">
<node TEXT="The definition includes" ID="ID_771329129" CREATED="1510637454333" MODIFIED="1510637466888">
<node TEXT="Interface" ID="ID_1574162437" CREATED="1510637467257" MODIFIED="1510637476197"/>
<node TEXT="Actions" ID="ID_1358677823" CREATED="1510637476672" MODIFIED="1510637478117"/>
</node>
</node>
<node TEXT="Call and Return" ID="ID_1994481580" CREATED="1501218067165" MODIFIED="1501218146898">
<node TEXT="Call - the request to enter a sub program" ID="ID_286836515" CREATED="1510637734331" MODIFIED="1510637744862"/>
<node TEXT="Return - the resumption of the calling program (possibly with a value" ID="ID_1660906043" CREATED="1510637745366" MODIFIED="1510637763580"/>
<node TEXT="A subprogram is active between call and return" ID="ID_932796698" CREATED="1510637764895" MODIFIED="1510637778644"/>
</node>
<node TEXT="Procedures and Functions" ID="ID_1264438617" CREATED="1501218185253" MODIFIED="1510677328920">
<node TEXT="Procedures" ID="ID_1430353744" CREATED="1510677376527" MODIFIED="1510677434632">
<node TEXT="Do not return" ID="ID_1244533650" CREATED="1510677427520" MODIFIED="1510677430723"/>
<node TEXT="They are intended as extension points for statements in the language" ID="ID_476499152" CREATED="1510677399879" MODIFIED="1510677417991"/>
<node TEXT="Mostly a feature of older languages" ID="ID_372766321" CREATED="1510677418474" MODIFIED="1510677446412"/>
</node>
<node TEXT="Functions" ID="ID_1024202111" CREATED="1510677447337" MODIFIED="1510677450061">
<node TEXT="Return" ID="ID_1952711122" CREATED="1510677450065" MODIFIED="1510677452084"/>
<node TEXT="Modeled on math functions" ID="ID_736144614" CREATED="1510677453214" MODIFIED="1510677458988"/>
<node TEXT="Generally should not have side effects" ID="ID_848277263" CREATED="1510677459456" MODIFIED="1510677468922"/>
</node>
</node>
<node TEXT="Coroutines" ID="ID_1115302264" CREATED="1501218665411" MODIFIED="1501218691043">
<attribute NAME="textbook" VALUE="09-13"/>
<node TEXT="Include Yield and Resume" ID="ID_1895347416" CREATED="1510678814589" MODIFIED="1510678824182"/>
<node TEXT="Yield returns a value but maintains current state" ID="ID_1142131174" CREATED="1510678834481" MODIFIED="1510678846248"/>
<node TEXT="Resume restarts co-routine after last yeild" ID="ID_321931033" CREATED="1510678846698" MODIFIED="1510678868719"/>
<node TEXT="Call and Return still exist and define the lifetime" ID="ID_377076310" CREATED="1510678869240" MODIFIED="1510678882455"/>
</node>
<node TEXT="Side effects" ID="ID_882321217" CREATED="1501218528996" MODIFIED="1501218572398">
<attribute NAME="textbook" VALUE="09-08"/>
<node TEXT="Ways in which a CS function is not like a math function" ID="ID_1892603849" CREATED="1510678637317" MODIFIED="1510678671812"/>
<node TEXT="Context" ID="ID_441476115" CREATED="1510678672441" MODIFIED="1510678716433">
<node TEXT="global variables" ID="ID_892536416" CREATED="1510678683124" MODIFIED="1510678687242"/>
<node TEXT="static local variables" ID="ID_1031332026" CREATED="1510678690231" MODIFIED="1510678698135"/>
</node>
<node TEXT="Error" ID="ID_1349452318" CREATED="1510678716958" MODIFIED="1510678718983"/>
<node TEXT="Non-determinisim" ID="ID_1510446332" CREATED="1510678719547" MODIFIED="1510678725459"/>
<node TEXT="Destruction" ID="ID_910756464" CREATED="1510678725966" MODIFIED="1510678730279">
<node TEXT="I/O" ID="ID_1687318818" CREATED="1510678730283" MODIFIED="1510678732710"/>
<node TEXT="out parameter" ID="ID_1942340393" CREATED="1510678678055" MODIFIED="1510678682645"/>
</node>
</node>
<node TEXT="Referencing environments" ID="ID_1928409853" CREATED="1501218218460" MODIFIED="1501218287133">
<attribute NAME="textbook" VALUE="09-04"/>
<node TEXT="Set of bindings visible to a subprogram" ID="ID_557581482" CREATED="1510678899452" MODIFIED="1510678917726">
<node TEXT="local variables" ID="ID_832725099" CREATED="1501218289268" MODIFIED="1501218292345"/>
<node TEXT="nested subprograms" ID="ID_1877848518" CREATED="1501218295876" MODIFIED="1501218300457"/>
</node>
</node>
<node TEXT="closures" ID="ID_1812157670" CREATED="1501218264332" MODIFIED="1501218639780">
<attribute NAME="textbook" VALUE="09-12"/>
<node TEXT="A subprogram and its referencing enviornment are called a closure" ID="ID_1718259699" CREATED="1510678931973" MODIFIED="1510678945721"/>
</node>
<node TEXT="Return Values" ID="ID_1267540051" CREATED="1501218556972" MODIFIED="1501218575188">
<attribute NAME="textbook" VALUE="09-08"/>
<node TEXT="What are the types of return" ID="ID_1600420417" CREATED="1510679114145" MODIFIED="1510679120597"/>
<node TEXT="What are the number of return types" ID="ID_1838654048" CREATED="1510679121068" MODIFIED="1510679128889"/>
</node>
</node>
<node TEXT="Parameters" ID="ID_1496153009" CREATED="1510677493653" MODIFIED="1510677496300">
<node TEXT="Formal and Actual" ID="ID_781409976" CREATED="1510677497488" MODIFIED="1510677506095">
<node TEXT="The parameter definitions in the header are called formal" ID="ID_1227777059" CREATED="1510677506100" MODIFIED="1510677517275"/>
<node TEXT="The parameter values in a call site are called actual" ID="ID_745176171" CREATED="1510677517649" MODIFIED="1510677534199"/>
</node>
<node TEXT="Positional and Keyword" ID="ID_1263080566" CREATED="1510677565352" MODIFIED="1510677573279">
<node TEXT="If the matching between formal and actual parameters is based only on order then the language uses positional parameters" ID="ID_321279655" CREATED="1510677573284" MODIFIED="1510677606623"/>
<node TEXT="If each actual parameter can be associated with a formal parameter name in any order the language used keyword parameters" ID="ID_44270608" CREATED="1510677607043" MODIFIED="1510677651753">
<node TEXT="foo(bar = 42)" ID="ID_668853148" CREATED="1510677651770" MODIFIED="1510677692016"/>
</node>
</node>
<node TEXT="Parameter passing" ID="ID_1585999038" CREATED="1501218305916" MODIFIED="1510678150446">
<attribute NAME="textbook" VALUE="09-05"/>
<node TEXT="pass by value" ID="ID_1326900621" CREATED="1501218325572" MODIFIED="1501218328378">
<node TEXT="Only the value is passed (a copy)" ID="ID_1987675680" CREATED="1510677760309" MODIFIED="1510677769359"/>
</node>
<node TEXT="pass by result" ID="ID_636661733" CREATED="1501218328788" MODIFIED="1501218331201">
<node TEXT="A local variable is created" ID="ID_1202531907" CREATED="1510677772044" MODIFIED="1510677808271"/>
<node TEXT="Value (result) is copied into caller at end of function" ID="ID_1989711793" CREATED="1510677810646" MODIFIED="1510677827815"/>
</node>
<node TEXT="pass by value result" ID="ID_1096608584" CREATED="1501218331548" MODIFIED="1501218337409">
<node TEXT="Copy passed to function" ID="ID_549374789" CREATED="1510677858349" MODIFIED="1510677867620"/>
<node TEXT="Value copied back into caller" ID="ID_921500967" CREATED="1510677868056" MODIFIED="1510677876938"/>
<node TEXT="Also called pass by copy" ID="ID_763913802" CREATED="1510677877302" MODIFIED="1510677883469"/>
</node>
<node TEXT="pass by reference" ID="ID_930463517" CREATED="1501218337684" MODIFIED="1501218340232">
<node TEXT="Create and copy an alias" ID="ID_1964297941" CREATED="1510677902803" MODIFIED="1510677911977"/>
</node>
<node TEXT="pass by name" ID="ID_910929097" CREATED="1501218340460" MODIFIED="1501218342297">
<node TEXT="As if parameter was textually substituted" ID="ID_490489201" CREATED="1510677934091" MODIFIED="1510677949586"/>
<node TEXT="Referencing environment must also be included for name lookups" ID="ID_625400383" CREATED="1510677950046" MODIFIED="1510678021222"/>
</node>
</node>
<node TEXT="Type checking parameters" ID="ID_1586720894" CREATED="1501218361540" MODIFIED="1510678145310">
<node TEXT="Do formal parameters have type?" ID="ID_1513324976" CREATED="1510678115049" MODIFIED="1510678122283"/>
<node TEXT="Do formal and actual parameters have to match?" ID="ID_297386340" CREATED="1510678122697" MODIFIED="1510678137403"/>
</node>
<node TEXT="multidimensional arrays as parameters" ID="ID_21311258" CREATED="1501218367724" MODIFIED="1501218375665">
<node TEXT="A language needs to be able to build the array mapping" ID="ID_135752825" CREATED="1510678212774" MODIFIED="1510678233546"/>
<node TEXT="This complicates passing arrays" ID="ID_418761806" CREATED="1510678234112" MODIFIED="1510678244316">
<node TEXT="Send a pointer and do pointer arithmetic" ID="ID_337856793" CREATED="1510678244320" MODIFIED="1510678265134"/>
<node TEXT="Less flexible functions (specific array size and layout)" ID="ID_399405947" CREATED="1510678278770" MODIFIED="1510678291107"/>
<node TEXT="More complex built in arrays" ID="ID_364777620" CREATED="1510678265693" MODIFIED="1510678276417"/>
</node>
</node>
<node TEXT="subprograms as parameters" ID="ID_1324602268" CREATED="1501218385820" MODIFIED="1501218400061">
<attribute NAME="textbook" VALUE="09-06"/>
<node TEXT="How can subprograms be passed - what restrictions are there?" ID="ID_427009180" CREATED="1510678425191" MODIFIED="1510678452770"/>
<node TEXT="What is the referencing environment?" ID="ID_1402667126" CREATED="1510678453238" MODIFIED="1510678474522">
<node TEXT="call statment - shallow binding" ID="ID_532554318" CREATED="1510678474526" MODIFIED="1510678485781"/>
<node TEXT="passed function definition - deep binding" ID="ID_1538742317" CREATED="1510678486652" MODIFIED="1510678501564"/>
<node TEXT="specified at call site - ad hoc binding" ID="ID_1516699552" CREATED="1510678502115" MODIFIED="1510678513276"/>
</node>
</node>
</node>
<node TEXT="Other" ID="ID_1299722368" CREATED="1510803206956" MODIFIED="1510803211666">
<node TEXT="Indirect subprograms" ID="ID_1502578656" CREATED="1501218454876" MODIFIED="1501218464877">
<attribute NAME="textbook" VALUE="09-07"/>
<node TEXT="Function pointers" ID="ID_654085211" CREATED="1501218510916" MODIFIED="1501218514800"/>
<node TEXT="delegates" ID="ID_225776864" CREATED="1501218515060" MODIFIED="1501218517713">
<node TEXT="A Callable and assignable object" ID="ID_121248243" CREATED="1510678572958" MODIFIED="1510678581746"/>
</node>
<node TEXT="virtual functions" ID="ID_588083414" CREATED="1510678568384" MODIFIED="1510678571486">
<node TEXT="Implemented in terms of indirect subprograms" ID="ID_903933624" CREATED="1510678592309" MODIFIED="1510678600306"/>
</node>
</node>
<node TEXT="Overloaded functions" ID="ID_687164605" CREATED="1501218259893" MODIFIED="1510803231545">
<attribute NAME="textbook" VALUE="09-09"/>
<node TEXT="Subprograms with the same name and referencing environment" ID="ID_1482336879" CREATED="1510803231994" MODIFIED="1510803313291"/>
<node TEXT="Each must have a different protocol (number, type, and order of arguments)" ID="ID_854167308" CREATED="1510803280201" MODIFIED="1510803339837"/>
</node>
<node TEXT="Overloaded Operators" ID="ID_1074711550" CREATED="1501218644604" MODIFIED="1501218657915">
<attribute NAME="textbook" VALUE="09-11"/>
<node TEXT="Some languages (C++, Ada, Python, Ruby, others) allow operators to be overloaded" ID="ID_1122259394" CREATED="1510805929330" MODIFIED="1510805954160"/>
<node TEXT="Usually there is some special function name that is invoked by operator syntax" ID="ID_1823956610" CREATED="1510805954593" MODIFIED="1510805982083"/>
</node>
<node TEXT="Generic subprograms" ID="ID_976906178" CREATED="1501218262660" MODIFIED="1510806105567">
<attribute NAME="textbook" VALUE="09-10"/>
<node TEXT="Generic subprograms work on multiple types" ID="ID_1142557959" CREATED="1510806105572" MODIFIED="1510806143711"/>
<node TEXT="The concept of a parameter is what the generic subprogram expects" ID="ID_857715175" CREATED="1510806144811" MODIFIED="1510806162576"/>
<node TEXT="A type is said to model the concept if it meets the requirements" ID="ID_1935452129" CREATED="1510806162893" MODIFIED="1510806178226"/>
<node TEXT="Generic programs work on all types that model their concept" ID="ID_1124785134" CREATED="1510806178540" MODIFIED="1510806189550"/>
</node>
</node>
<node TEXT="Implementation" ID="ID_422479456" CREATED="1501218835059" MODIFIED="1510806840759">
<node TEXT="Prologue and Epilogue" ID="ID_1430622511" CREATED="1501218719979" MODIFIED="1501218739267">
<attribute NAME="textbook" VALUE="10-2"/>
<node TEXT="Function call must" ID="ID_1572826945" CREATED="1510806230895" MODIFIED="1510806236802">
<node TEXT="Suspend caller" ID="ID_423326876" CREATED="1510806236806" MODIFIED="1510806244293"/>
<node TEXT="Compute and pass parameters" ID="ID_17784584" CREATED="1510806244738" MODIFIED="1510806251917"/>
<node TEXT="Pass return address" ID="ID_474478184" CREATED="1510806252307" MODIFIED="1510806270688"/>
<node TEXT="Transfer control" ID="ID_615943666" CREATED="1510806260191" MODIFIED="1510806266044"/>
</node>
<node TEXT="Return must" ID="ID_796423984" CREATED="1510806271654" MODIFIED="1510806275564">
<node TEXT="Resolve out parameters" ID="ID_1566731279" CREATED="1510806275568" MODIFIED="1510806284193"/>
<node TEXT="Pass return value" ID="ID_556134270" CREATED="1510806284645" MODIFIED="1510806298050"/>
<node TEXT="Return control" ID="ID_1217399447" CREATED="1510806298502" MODIFIED="1510806305361"/>
<node TEXT="Resum caller into previous state" ID="ID_1496963540" CREATED="1510806305848" MODIFIED="1510806315021"/>
</node>
</node>
<node TEXT="Activation Records" ID="ID_1493262926" CREATED="1501218758243" MODIFIED="1510806632937">
<attribute_layout NAME_WIDTH="55" VALUE_WIDTH="55"/>
<attribute NAME="textbook" VALUE="10-03"/>
<attribute NAME="textbook" VALUE="10-04"/>
<node TEXT="Data needed by every invocation of a function" ID="ID_924094617" CREATED="1510806352396" MODIFIED="1510806365166"/>
<node TEXT="Stack local variables" ID="ID_1335086951" CREATED="1510806365667" MODIFIED="1510806372261"/>
<node TEXT="Parameters" ID="ID_1433013072" CREATED="1510806372613" MODIFIED="1510806374259"/>
<node TEXT="Return address" ID="ID_1936958512" CREATED="1510806374985" MODIFIED="1510806432106"/>
<node TEXT="Dynamic link" ID="ID_795084415" CREATED="1510806432573" MODIFIED="1510806439050"/>
<node TEXT="Static link" ID="ID_685043716" CREATED="1510806526887" MODIFIED="1510806530339"/>
</node>
<node TEXT="Example: Recursive Factorial" ID="ID_963337042" CREATED="1510806469328" MODIFIED="1510806476697"/>
<node TEXT="Blocks" ID="ID_817669315" CREATED="1501218815059" MODIFIED="1501218823915">
<attribute NAME="textbook" VALUE="10-05"/>
<node TEXT="Entering a block adds a new activation record" ID="ID_835313485" CREATED="1510806658076" MODIFIED="1510806674127"/>
<node TEXT="Chains of static links used to lookup non-local names" ID="ID_661954200" CREATED="1510806674548" MODIFIED="1510806698694"/>
</node>
<node TEXT="Dynamic Scope" ID="ID_1178711344" CREATED="1501218852516" MODIFIED="1501218866506">
<attribute NAME="textbook" VALUE="10-06"/>
<node TEXT="Deep access - lookup names using dynamic links" ID="ID_1563399317" CREATED="1510806789717" MODIFIED="1510806808981"/>
<node TEXT="Shallow access - maintain a stack for each name" ID="ID_1248521737" CREATED="1510806809292" MODIFIED="1510806824846"/>
<node TEXT="Semantics are identical" ID="ID_500980806" CREATED="1510806825235" MODIFIED="1510806830361"/>
</node>
</node>
</node>
</node>
</map>
