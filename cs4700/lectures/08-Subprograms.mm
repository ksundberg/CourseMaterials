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
<node TEXT="Call and Return" ID="ID_1994481580" CREATED="1501218067165" MODIFIED="1501218146898"/>
<node TEXT="Yeild and Resume" ID="ID_628699178" CREATED="1501218131733" MODIFIED="1501218137610"/>
<node TEXT="Characteristics" ID="ID_1213636000" CREATED="1501218091773" MODIFIED="1501218235103">
<attribute NAME="textbook" VALUE="09-01"/>
<node TEXT="Single entry" ID="ID_504962201" CREATED="1501218095927" MODIFIED="1501218109851">
<node TEXT="Co-routines have multiple entry points" ID="ID_1101549434" CREATED="1501218118853" MODIFIED="1501218129931"/>
</node>
<node TEXT="Only one active" ID="ID_1397643061" CREATED="1501218110581" MODIFIED="1501218116634"/>
</node>
<node TEXT="Parameters" ID="ID_294512485" CREATED="1501218153989" MODIFIED="1501218157938">
<node TEXT="actual" ID="ID_793984352" CREATED="1501218169965" MODIFIED="1501218172314"/>
<node TEXT="formal" ID="ID_1033745148" CREATED="1501218172885" MODIFIED="1501218175450"/>
<node TEXT="positional" ID="ID_1898983582" CREATED="1501218175956" MODIFIED="1501218178386"/>
<node TEXT="keyword" ID="ID_1691579468" CREATED="1501218178645" MODIFIED="1501218180410"/>
</node>
<node TEXT="parameter passing" ID="ID_1585999038" CREATED="1501218305916" MODIFIED="1501218320558">
<attribute NAME="textbook" VALUE="09-05"/>
<node TEXT="pass by value" ID="ID_1326900621" CREATED="1501218325572" MODIFIED="1501218328378"/>
<node TEXT="pass by result" ID="ID_636661733" CREATED="1501218328788" MODIFIED="1501218331201"/>
<node TEXT="pass by value result" ID="ID_1096608584" CREATED="1501218331548" MODIFIED="1501218337409"/>
<node TEXT="pass by reference" ID="ID_930463517" CREATED="1501218337684" MODIFIED="1501218340232"/>
<node TEXT="pass by name" ID="ID_910929097" CREATED="1501218340460" MODIFIED="1501218342297"/>
</node>
<node TEXT="type checking parameters" ID="ID_1586720894" CREATED="1501218361540" MODIFIED="1501218367498"/>
<node TEXT="multidimensional arrays as parameters" ID="ID_21311258" CREATED="1501218367724" MODIFIED="1501218375665"/>
<node TEXT="subprograms as parameters" ID="ID_1324602268" CREATED="1501218385820" MODIFIED="1501218400061">
<attribute NAME="textbook" VALUE="09-06"/>
</node>
<node TEXT="Indirect subprograms" ID="ID_1502578656" CREATED="1501218454876" MODIFIED="1501218464877">
<attribute NAME="textbook" VALUE="09-07"/>
<node TEXT="Function pointers" ID="ID_654085211" CREATED="1501218510916" MODIFIED="1501218514800"/>
<node TEXT="delegates" ID="ID_225776864" CREATED="1501218515060" MODIFIED="1501218517713"/>
</node>
<node TEXT="Procedures" ID="ID_1264438617" CREATED="1501218185253" MODIFIED="1501218188274"/>
<node TEXT="Functions" ID="ID_1237979224" CREATED="1501218188525" MODIFIED="1501218190754"/>
<node TEXT="Design Issues" ID="ID_250156205" CREATED="1501218203836" MODIFIED="1501218226862">
<attribute NAME="textbook" VALUE="09-03"/>
<node TEXT="overloaded" ID="ID_687164605" CREATED="1501218259893" MODIFIED="1501218591611">
<attribute NAME="textbook" VALUE="09-09"/>
</node>
<node TEXT="generic" ID="ID_976906178" CREATED="1501218262660" MODIFIED="1501218611916">
<attribute NAME="textbook" VALUE="09-10"/>
</node>
<node TEXT="closures" ID="ID_1812157670" CREATED="1501218264332" MODIFIED="1501218639780">
<attribute NAME="textbook" VALUE="09-12"/>
</node>
</node>
<node TEXT="Referencing environments" ID="ID_1928409853" CREATED="1501218218460" MODIFIED="1501218287133">
<attribute NAME="textbook" VALUE="09-04"/>
<node TEXT="local variables" ID="ID_832725099" CREATED="1501218289268" MODIFIED="1501218292345"/>
<node TEXT="nested subprograms" ID="ID_1877848518" CREATED="1501218295876" MODIFIED="1501218300457"/>
</node>
<node TEXT="Side effects" ID="ID_882321217" CREATED="1501218528996" MODIFIED="1501218572398">
<attribute NAME="textbook" VALUE="09-08"/>
</node>
<node TEXT="Return Values" ID="ID_1267540051" CREATED="1501218556972" MODIFIED="1501218575188">
<attribute NAME="textbook" VALUE="09-08"/>
</node>
<node TEXT="Overloaded Operators" ID="ID_1074711550" CREATED="1501218644604" MODIFIED="1501218657915">
<attribute NAME="textbook" VALUE="09-11"/>
</node>
<node TEXT="Coroutines" ID="ID_1115302264" CREATED="1501218665411" MODIFIED="1501218691043">
<attribute NAME="textbook" VALUE="09-13"/>
</node>
<node TEXT="Activation Records" ID="ID_422479456" CREATED="1501218835059" MODIFIED="1501218838536">
<node TEXT="Prologue and Epilogue" ID="ID_1430622511" CREATED="1501218719979" MODIFIED="1501218739267">
<attribute NAME="textbook" VALUE="10-2"/>
</node>
<node TEXT="Activation Records" ID="ID_1493262926" CREATED="1501218758243" MODIFIED="1501218768547">
<attribute NAME="textbook" VALUE="10-03"/>
</node>
<node TEXT="Static Chains" ID="ID_1859625539" CREATED="1501218800003" MODIFIED="1501218809682">
<attribute NAME="textbook" VALUE="10-04"/>
</node>
<node TEXT="Blocks" ID="ID_817669315" CREATED="1501218815059" MODIFIED="1501218823915">
<attribute NAME="textbook" VALUE="10-05"/>
</node>
<node TEXT="Dynamic Scope" ID="ID_1178711344" CREATED="1501218852516" MODIFIED="1501218866506">
<attribute NAME="textbook" VALUE="10-06"/>
</node>
</node>
</node>
</node>
</map>
