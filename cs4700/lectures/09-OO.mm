<map version="freeplane 1.3.0">
<!--To view this file, download free mind mapping software Freeplane from http://freeplane.sourceforge.net -->
<node TEXT="OO Support" ID="ID_1723255651" CREATED="1283093380553" MODIFIED="1501545949475"><hook NAME="MapStyle">
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
<node TEXT="Introduction" POSITION="right" ID="ID_1907657266" CREATED="1511282644452" MODIFIED="1511282648620">
<edge COLOR="#7c0000"/>
<node TEXT="OO" ID="ID_595918756" CREATED="1511282649608" MODIFIED="1511282651118">
<node TEXT="Dominant Design Practice" ID="ID_230408891" CREATED="1511282697629" MODIFIED="1511282707664">
<node TEXT="Roots in SIMULA 67 and the lambda calculus" ID="ID_1514743463" CREATED="1511282715792" MODIFIED="1511282758066"/>
<node TEXT="Considered to begin with SmallTalk 80" ID="ID_1843158236" CREATED="1511282758435" MODIFIED="1511282769726"/>
<node TEXT="Currently the dominant practice" LOCALIZED_STYLE_REF="styles.topic" ID="ID_758646729" CREATED="1511282770664" MODIFIED="1511282793148"/>
<node TEXT="&quot;Too many people think that &apos;object-oriented&apos; is simply a synonym for &apos;good&apos;&quot; -- Bjarne Stroustrup" ID="ID_523533110" CREATED="1501546205802" MODIFIED="1511282655097"/>
</node>
<node TEXT="Three Key Features" ID="ID_1912598584" CREATED="1501546099179" MODIFIED="1511282658473">
<attribute NAME="textbook" VALUE="12-02"/>
<node TEXT="Abstract Data Types" ID="ID_1787805545" CREATED="1501546103678" MODIFIED="1501546113384"/>
<node TEXT="Inheritance" ID="ID_376517042" CREATED="1501546113850" MODIFIED="1501546119512"/>
<node TEXT="Dynamic Binding" ID="ID_286862036" CREATED="1501546119818" MODIFIED="1501546131887"/>
</node>
</node>
<node TEXT="Inheritance" ID="ID_1785295652" CREATED="1501546297322" MODIFIED="1511282896579">
<node TEXT="Inheritance" ID="ID_189060374" CREATED="1511282868816" MODIFIED="1511282892610">
<attribute NAME="textbook" VALUE="12-03"/>
<node TEXT="Seeks to improve productivity via reuse" LOCALIZED_STYLE_REF="styles.topic" ID="ID_1380691528" CREATED="1511282900230" MODIFIED="1511282987567"/>
<node TEXT="ADT&apos;s promise reuse but in practice deliver little" ID="ID_1034756921" CREATED="1511282926521" MODIFIED="1511282947984"/>
<node TEXT="Existing types are often close but not quite right" LOCALIZED_STYLE_REF="styles.topic" ID="ID_1962234441" CREATED="1511282957983" MODIFIED="1511282992708"/>
<node TEXT="Inheritance gives a way to extend a type without redefining it" ID="ID_682304796" CREATED="1511282996635" MODIFIED="1511283046480"/>
<node TEXT="Inheritance also provides an organizational framework" ID="ID_18212556" CREATED="1511283046898" MODIFIED="1511283066283"/>
</node>
<node TEXT="Multiple Inheritance" ID="ID_1922482229" CREATED="1501546301861" MODIFIED="1501546306647">
<node TEXT="If a language allows more than one parent class it allows multiple inheritance" ID="ID_1017115472" CREATED="1511283121873" MODIFIED="1511283138311"/>
<node TEXT="This makes dependence relations a graph rather than just a tree" ID="ID_1672480897" CREATED="1511283138767" MODIFIED="1511283188796"/>
</node>
<node TEXT="Subtypes" ID="ID_912972426" CREATED="1501546373906" MODIFIED="1501546435142">
<node TEXT="Does the language support the principle of substitution?" ID="ID_967178909" CREATED="1511283399103" MODIFIED="1511283414109"/>
<node TEXT="Is Derived an instance of Base?" ID="ID_475503141" CREATED="1511283414485" MODIFIED="1511283430311"/>
</node>
</node>
<node TEXT="Dynamic Binding" ID="ID_1078418058" CREATED="1511284852581" MODIFIED="1511284859724">
<node TEXT="Dynamic Binding" ID="ID_1493433315" CREATED="1511284859730" MODIFIED="1511284868028">
<node TEXT="Substitution and extension require dynamic (run-time) binding of functions" ID="ID_1298147678" CREATED="1511284868033" MODIFIED="1511284895834"/>
</node>
</node>
</node>
<node TEXT="Implementation" POSITION="right" ID="ID_1420217239" CREATED="1511282850857" MODIFIED="1511282855063">
<edge COLOR="#00007c"/>
<node TEXT="Inheritance" ID="ID_276234984" CREATED="1511283260236" MODIFIED="1511283269260">
<node TEXT="Exclusive Objects" ID="ID_400070540" CREATED="1511283269265" MODIFIED="1511283294427">
<attribute NAME="textbook" VALUE="12-03"/>
<node TEXT="Is every user defined type an object?" ID="ID_1043318932" CREATED="1511283299348" MODIFIED="1511283317558"/>
<node TEXT="Do they all inherit from Object?" ID="ID_155578181" CREATED="1511283318393" MODIFIED="1511283331205"/>
</node>
<node TEXT="Is everything Object?" ID="ID_1422795346" CREATED="1501546365009" MODIFIED="1501546371783">
<node TEXT="&quot;I find OOP technically unsound.  It attempts to decompose the world in terms of interfaces that vary on a single type.  To deal with the real problems you need multisorted algebras -- families of interfaces that span multiple types. I find OOP philosophically unsound.  It claims that everything is an object.  Even if it is true it is not very interesting -- saying that everything is an object is saying nothing at all.  I find OOP methodologically wrong. It starts with classes. It is as if mathematicians would start with axioms. You do not start with axioms - you start with proofs. Only when you have found a bunch of related proofs, can you come up with axioms. You end with axioms. The same thing is true in programming: you have to start with interesting algorithms. Only when you understand them well, can you come up with an interface that will let them work. &quot; -- Alexander Stepanov" ID="ID_145874835" CREATED="1501545949489" MODIFIED="1511284836115"/>
</node>
<node TEXT="Interfaces" ID="ID_518885349" CREATED="1511283338849" MODIFIED="1511283345137">
<node TEXT="Multiple inheritance can lead to diamonds in the dependence graph which must be resolved" ID="ID_1466869734" CREATED="1511283345142" MODIFIED="1511283367859"/>
<node TEXT="On common solution is the Interface" ID="ID_1398895851" CREATED="1511283368420" MODIFIED="1511283374740"/>
</node>
<node TEXT="Slicing" ID="ID_1102061413" CREATED="1501546464513" MODIFIED="1501546471735"/>
</node>
<node TEXT="Dynamic Binding" ID="ID_500949471" CREATED="1501546542921" MODIFIED="1511284938750">
<node TEXT="Virtual Method Tables" ID="ID_1912280770" CREATED="1501546573937" MODIFIED="1511284932785">
<attribute NAME="textbook" VALUE="12=-05"/>
</node>
</node>
</node>
<node TEXT="Other" POSITION="right" ID="ID_1769306375" CREATED="1511284948194" MODIFIED="1511284950132">
<edge COLOR="#007c00"/>
<node TEXT="Reflection" ID="ID_1878783364" CREATED="1511284951464" MODIFIED="1511284953769">
<node TEXT="Reflection" ID="ID_1931075061" CREATED="1501546604609" MODIFIED="1511284956835">
<attribute NAME="textbook" VALUE="12-06"/>
</node>
</node>
</node>
</node>
</map>
