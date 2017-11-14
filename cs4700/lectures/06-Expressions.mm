<map version="freeplane 1.3.0">
<!--To view this file, download free mind mapping software Freeplane from http://freeplane.sourceforge.net -->
<node TEXT="Expressions" ID="ID_1723255651" CREATED="1283093380553" MODIFIED="1500521876232"><hook NAME="MapStyle">
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
<hook NAME="AutomaticEdgeColor" COUNTER="2"/>
<node TEXT="Expressions" POSITION="right" ID="ID_761644185" CREATED="1509465363995" MODIFIED="1509465366812">
<edge COLOR="#0000ff"/>
<node TEXT="Syntax" ID="ID_587853303" CREATED="1509465332015" MODIFIED="1509465369163">
<node TEXT="Expression" ID="ID_992320581" CREATED="1509463944710" MODIFIED="1509465351834">
<attribute NAME="textbook" VALUE="07-01"/>
<node TEXT="Means of expressing computation" ID="ID_1200969156" CREATED="1509463951475" MODIFIED="1509463964513"/>
<node TEXT="Combination of values and operators that has a value" ID="ID_387011808" CREATED="1509463965245" MODIFIED="1509463998801"/>
</node>
<node TEXT="Operator Overloading" ID="ID_1685045047" CREATED="1500522006332" MODIFIED="1509465355182">
<attribute NAME="textbook" VALUE="07-03"/>
<node TEXT="Can users overload operators?" ID="ID_249776810" CREATED="1509464657217" MODIFIED="1509464666343"/>
<node TEXT="Does the language overload operators?" ID="ID_1862606471" CREATED="1509464666796" MODIFIED="1509464673823"/>
<node TEXT="How does this affect the language?" ID="ID_512548134" CREATED="1509464674302" MODIFIED="1509464691055"/>
</node>
</node>
<node TEXT="Evaluations" ID="ID_882247451" CREATED="1509465211907" MODIFIED="1509465373393">
<node TEXT="Side Effects" ID="ID_1691460214" CREATED="1500521983564" MODIFIED="1509465233110">
<node TEXT="An observable change of global state made by a function call" ID="ID_1421545090" CREATED="1509464304568" MODIFIED="1509464333745"/>
<node TEXT="Examples:" ID="ID_25497129" CREATED="1509464334143" MODIFIED="1509464340306">
<node TEXT="output parameters" ID="ID_68646715" CREATED="1509464340309" MODIFIED="1509464343932"/>
<node TEXT="global variables" ID="ID_491576212" CREATED="1509464344373" MODIFIED="1509464349283"/>
<node TEXT="class variables" ID="ID_688289667" CREATED="1509464394223" MODIFIED="1509464397703"/>
<node TEXT="IO" ID="ID_1796614926" CREATED="1509464350126" MODIFIED="1509464384280"/>
</node>
</node>
<node TEXT="Referential Transparency" ID="ID_482960535" CREATED="1500521993292" MODIFIED="1509465228796">
<node TEXT="If an expression has no side effects it can be thought of as a reference to its value" ID="ID_1944831959" CREATED="1509464440210" MODIFIED="1509464498616"/>
<node TEXT="Functions are called pure if they have this property" ID="ID_351348198" CREATED="1509464499084" MODIFIED="1509464532057"/>
<node TEXT="Four major causes of impurity" ID="ID_250760682" CREATED="1509464532612" MODIFIED="1509464540425">
<node TEXT="Error" ID="ID_336191669" CREATED="1509464540430" MODIFIED="1509464544224"/>
<node TEXT="Non-determinism" ID="ID_1081046003" CREATED="1509464544701" MODIFIED="1509464568867"/>
<node TEXT="Context" ID="ID_629424943" CREATED="1509464569372" MODIFIED="1509464572581"/>
<node TEXT="Destruction" ID="ID_1920054274" CREATED="1509464573322" MODIFIED="1509464596412"/>
</node>
</node>
<node TEXT="Short-Circuit Evaluation" ID="ID_1571895953" CREATED="1500523888134" MODIFIED="1509465222353">
<attribute NAME="textbook" VALUE="07-06"/>
<node TEXT="If the value of an expression can be and is determined without evaluating the whole expression it is called short-circuit evaluation" ID="ID_324662884" CREATED="1509464817636" MODIFIED="1509464873033"/>
<node TEXT="Very common with boolean algebra" ID="ID_1594499151" CREATED="1509464873569" MODIFIED="1509464888306">
<node TEXT="$0 * X = 0$" ID="ID_1457548510" CREATED="1509464888312" MODIFIED="1509464916646"/>
<node TEXT="$1 + X = 1$" ID="ID_1870237218" CREATED="1509464917091" MODIFIED="1509464926191"/>
</node>
<node TEXT="Also possible with memoized pure functions" ID="ID_53735491" CREATED="1509464931934" MODIFIED="1509464946110"/>
</node>
<node TEXT="Lazy vs. Eager Evaluation" ID="ID_318050" CREATED="1509464985652" MODIFIED="1509465225019">
<node TEXT="Eager evaluation - expressions become values at earliest opportunity" ID="ID_1285336765" CREATED="1509465005616" MODIFIED="1509465025476"/>
<node TEXT="Lazy evaluation - expressions become values at the latest possible moment" ID="ID_572456284" CREATED="1509465025937" MODIFIED="1509465045679">
<node TEXT="Very common in functional languages" ID="ID_963563050" CREATED="1509465045684" MODIFIED="1509465064935"/>
<node TEXT="Allows expression of infinite objects - but not their evaluation" ID="ID_1149401092" CREATED="1509465065483" MODIFIED="1509465114667"/>
</node>
</node>
</node>
<node TEXT="Types of Expressions" ID="ID_346534413" CREATED="1509465263265" MODIFIED="1509465376337">
<node TEXT="Arithmetic Expressions" ID="ID_1724892985" CREATED="1500521876235" MODIFIED="1509465294663">
<attribute NAME="textbook" VALUE="07-02"/>
<node TEXT="Unary" ID="ID_192387377" CREATED="1500521881815" MODIFIED="1500521884873"/>
<node TEXT="Binary" ID="ID_1378683384" CREATED="1500521885356" MODIFIED="1500521887749">
<node TEXT="Infix" ID="ID_794116850" CREATED="1500521887751" MODIFIED="1500521890201"/>
<node TEXT="Prefix" ID="ID_1693217262" CREATED="1500521890468" MODIFIED="1500521891849"/>
<node TEXT="Postfix" ID="ID_1069308131" CREATED="1500521892220" MODIFIED="1500521896585"/>
</node>
<node TEXT="Ternary" ID="ID_1220918428" CREATED="1500521897548" MODIFIED="1500521901033"/>
</node>
<node TEXT="Boolean Expressions" ID="ID_179767979" CREATED="1500523843862" MODIFIED="1509465282088">
<attribute NAME="textbook" VALUE="07-05"/>
<node TEXT="Comparisons" ID="ID_151872876" CREATED="1509464755974" MODIFIED="1509464774374">
<node TEXT="Two way comparisons" ID="ID_1149192030" CREATED="1509464774380" MODIFIED="1509464785368"/>
<node TEXT="Three way comparison" ID="ID_641637173" CREATED="1509464785852" MODIFIED="1509464790318"/>
</node>
<node TEXT="Boolean algebra" ID="ID_12517267" CREATED="1509464798138" MODIFIED="1509464803508"/>
</node>
<node TEXT="Assignment" ID="ID_181634895" CREATED="1500523911695" MODIFIED="1509465278751">
<attribute NAME="textbook" VALUE="07-07"/>
<node TEXT="Procedural Languages - Write to memory, always a side effect" ID="ID_1379524455" CREATED="1509465139006" MODIFIED="1509465157357"/>
<node TEXT="Functional and Logic - Create a new name binding to a constant value" ID="ID_1001013679" CREATED="1509465157787" MODIFIED="1509465195059"/>
</node>
<node TEXT="Type Conversions" ID="ID_1059778886" CREATED="1500522064932" MODIFIED="1509465285268">
<attribute NAME="textbook" VALUE="07-04"/>
<node TEXT="narrowing" ID="ID_731620233" CREATED="1500523786153" MODIFIED="1500523789467"/>
<node TEXT="widening" ID="ID_414658533" CREATED="1500523789846" MODIFIED="1500523798163"/>
<node TEXT="casting" ID="ID_555326714" CREATED="1500523824575" MODIFIED="1500523826555"/>
<node TEXT="Which operations are allowed?" ID="ID_1716791390" CREATED="1509464703748" MODIFIED="1509464710283"/>
<node TEXT="Which are implicit and which explicit?" ID="ID_461825346" CREATED="1509464710565" MODIFIED="1509464718160"/>
<node TEXT="Are mixed mode expressions allowed?" ID="ID_1000112880" CREATED="1509464729744" MODIFIED="1509464737955"/>
</node>
</node>
</node>
</node>
</map>
