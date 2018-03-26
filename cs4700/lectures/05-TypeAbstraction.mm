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
<hook NAME="AutomaticEdgeColor" COUNTER="6"/>
<node TEXT="Type" POSITION="right" ID="ID_1091949835" CREATED="1508254750497" MODIFIED="1508254756424">
<edge COLOR="#00ffff"/>
<node TEXT="System" ID="ID_1716125897" CREATED="1508253951928" MODIFIED="1508254785732">
<node TEXT="Type System" ID="ID_1233187033" CREATED="1500520068042" MODIFIED="1508253976240">
<attribute NAME="textbook" VALUE="06-01"/>
<node TEXT="Type constructors" ID="ID_1040734927" CREATED="1500520151587" MODIFIED="1500520156815"/>
<node TEXT="Descriptors" ID="ID_216363492" CREATED="1500520158163" MODIFIED="1500520162439"/>
<node TEXT="Sometimes called a type algebra" ID="ID_684768548" CREATED="1508254715856" MODIFIED="1508254725106"/>
</node>
<node TEXT="Encapsulation and Information Hiding" ID="ID_812475313" CREATED="1500521563268" MODIFIED="1508254003939">
<attribute NAME="textbook" VALUE="11-04"/>
<node TEXT="Does the language support thinking at the right level of abstraction" ID="ID_959482707" CREATED="1508254659668" MODIFIED="1508254673404"/>
<node TEXT="Does the language support thinking at multiple levels of abstraction" ID="ID_1102582116" CREATED="1508254673808" MODIFIED="1508254685941"/>
<node TEXT="Consider Float" LOCALIZED_STYLE_REF="styles.important" ID="ID_509480164" CREATED="1508254022807" MODIFIED="1508254703121"/>
</node>
</node>
<node TEXT="Checking" ID="ID_553737435" CREATED="1500521190964" MODIFIED="1508254790603">
<node TEXT="Type checking" ID="ID_570786583" CREATED="1500521220532" MODIFIED="1508254626775">
<attribute NAME="textbook" VALUE="06-12"/>
<node TEXT="The act of ensuring that types are compatible" ID="ID_1896065311" CREATED="1508255209260" MODIFIED="1508255222944"/>
<node TEXT="Coercion is the automatic conversion of one type to another" ID="ID_1247742422" CREATED="1508255184017" MODIFIED="1508255196410"/>
<node TEXT="Incompatible types that cannot be coerced are type errors" ID="ID_1506481663" CREATED="1508255303165" MODIFIED="1508255319672"/>
</node>
<node TEXT="Type Equivalence" ID="ID_104126849" CREATED="1500521280027" MODIFIED="1500521298747">
<attribute NAME="textbook" VALUE="06-14"/>
<node TEXT="Types are equivalent if no coercion is needed for compatibility" ID="ID_1010925734" CREATED="1508255371302" MODIFIED="1508255387190"/>
<node TEXT="Name equivalence - types are the same if they are named the same" ID="ID_1560456272" CREATED="1508255394789" MODIFIED="1508255407204"/>
<node TEXT="Structure equivalence - types are the same if the structure is the same" ID="ID_1619399711" CREATED="1508255407605" MODIFIED="1508255420935"/>
</node>
<node TEXT="Strong Types" ID="ID_1810598682" CREATED="1500521261004" MODIFIED="1500521274594">
<attribute NAME="textbook" VALUE="06-13"/>
<node TEXT="Strongly typed languages always detect type errors" ID="ID_16644550" CREATED="1508255279968" MODIFIED="1508255300440"/>
</node>
</node>
<node TEXT="Basic Types" ID="ID_1694079629" CREATED="1508255028285" MODIFIED="1508255031247">
<node TEXT="Primitive Types" ID="ID_382357758" CREATED="1500520173739" MODIFIED="1508253981294">
<attribute NAME="textbook" VALUE="06-02"/>
<node TEXT="Integer" ID="ID_1913572718" CREATED="1500520189955" MODIFIED="1500520192416"/>
<node TEXT="Floating Point" ID="ID_1672259520" CREATED="1500520192731" MODIFIED="1500520197112"/>
<node TEXT="Complex" ID="ID_1834028454" CREATED="1500520197515" MODIFIED="1500520201671"/>
<node TEXT="Decimal" ID="ID_304219058" CREATED="1500520202027" MODIFIED="1500520204079"/>
<node TEXT="Boolean" ID="ID_1206085038" CREATED="1500520204459" MODIFIED="1500520206408"/>
<node TEXT="Character" ID="ID_1790485366" CREATED="1500520206731" MODIFIED="1500520208495"/>
</node>
<node TEXT="Enumarations" ID="ID_194854517" CREATED="1500520426771" MODIFIED="1508254352674">
<attribute NAME="textbook" VALUE="06-04"/>
<node TEXT="What forms of coercion are allowed" ID="ID_664344981" CREATED="1508255064866" MODIFIED="1508255078499"/>
<node TEXT="What is the scope of the constants" ID="ID_646023092" CREATED="1508255079036" MODIFIED="1508255100694"/>
<node TEXT="How visible is the underlying representation" ID="ID_1665537713" CREATED="1508255145832" MODIFIED="1508255156152"/>
</node>
</node>
</node>
<node TEXT="Structured Types" POSITION="right" ID="ID_1209315805" CREATED="1508253637101" MODIFIED="1508253643287">
<edge COLOR="#007c7c"/>
<node TEXT="Arrays" ID="ID_27021720" CREATED="1508253656266" MODIFIED="1508253659177">
<node TEXT="Array" ID="ID_1186221578" CREATED="1500520477619" MODIFIED="1508253646623">
<attribute NAME="textbook" VALUE="06-05"/>
<node TEXT="What are legal subscripts" ID="ID_1814059844" CREATED="1508255452742" MODIFIED="1508255459743"/>
<node TEXT="Is the array range checked?" ID="ID_645268511" CREATED="1508255460158" MODIFIED="1508255468730"/>
<node TEXT="What operations are allowed" ID="ID_1590491353" CREATED="1508255469573" MODIFIED="1508255499771">
<node TEXT="Slicing" ID="ID_1973445865" CREATED="1508255543617" MODIFIED="1508255546046"/>
<node TEXT="Membership" ID="ID_216305473" CREATED="1508255546520" MODIFIED="1508255549629"/>
<node TEXT="Transposition" ID="ID_724488024" CREATED="1508255550115" MODIFIED="1508255557588"/>
<node TEXT="Concatenation" ID="ID_560006734" CREATED="1508255558069" MODIFIED="1508255561393"/>
</node>
</node>
<node TEXT="Array Categories" ID="ID_373625368" CREATED="1500520509595" MODIFIED="1508253665734">
<node TEXT="Static" ID="ID_1472292676" CREATED="1500520515902" MODIFIED="1500520518152"/>
<node TEXT="Fixed stack dynamic" ID="ID_289968629" CREATED="1500520518571" MODIFIED="1500520524088"/>
<node TEXT="fixed heap dynamic" ID="ID_1875128739" CREATED="1500520524403" MODIFIED="1500520528872"/>
<node TEXT="heap dynamic" ID="ID_515245213" CREATED="1500520529299" MODIFIED="1500520531776"/>
</node>
<node TEXT="Array Implementation" ID="ID_174248842" CREATED="1500520559995" MODIFIED="1508253673730">
<node TEXT="Are multdimensional arrays allowed?" ID="ID_1830732985" CREATED="1508255597492" MODIFIED="1508255615692"/>
<node TEXT="Are they row or column major?" ID="ID_408359384" CREATED="1508255616112" MODIFIED="1508255624312"/>
<node TEXT="$address[i] = address[0] + i * elementSize$" ID="ID_411596276" CREATED="1508255661463" MODIFIED="1508255700230"/>
</node>
</node>
<node TEXT="Strings" ID="ID_437417811" CREATED="1500520219379" MODIFIED="1508255857968">
<node TEXT="String Design" ID="ID_1372201482" CREATED="1500520248235" MODIFIED="1508255854982">
<attribute NAME="textbook" VALUE="06-03"/>
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
</node>
<node TEXT="Linear Structures" ID="ID_1658155513" CREATED="1508253823734" MODIFIED="1508253827957">
<node TEXT="Lists" ID="ID_27442776" CREATED="1500520720251" MODIFIED="1508253835214">
<attribute NAME="textbook" VALUE="06-09"/>
<node TEXT="Very common in functional languages" ID="ID_36113656" CREATED="1508256820223" MODIFIED="1508256842236"/>
<node TEXT="List comprehensions" ID="ID_481762365" CREATED="1508256842710" MODIFIED="1508256885482">
<node TEXT="Construct one list from another via a function" ID="ID_49827098" CREATED="1508256913015" MODIFIED="1508256922832"/>
</node>
<node TEXT="Ranges" ID="ID_691259955" CREATED="1508256891214" MODIFIED="1508256892706"/>
<node TEXT="Infinite lists" ID="ID_1405357811" CREATED="1508256885925" MODIFIED="1508256890064">
<node TEXT="If language is lazy infinite lists are possible" ID="ID_1859495132" CREATED="1508256936458" MODIFIED="1508256951059"/>
</node>
</node>
<node TEXT="Associative Arrays" ID="ID_1529733792" CREATED="1500520573099" MODIFIED="1508253846419">
<attribute NAME="textbook" VALUE="06-06"/>
<node TEXT="Also called hashs, dictionaries, or maps" ID="ID_1603483101" CREATED="1508256985251" MODIFIED="1508256994539"/>
<node TEXT="Associate a key with a value" ID="ID_974699229" CREATED="1508256994931" MODIFIED="1508257004024"/>
<node TEXT="May be balanced trees or hash tables" ID="ID_1728970027" CREATED="1508257004473" MODIFIED="1508257012124"/>
</node>
</node>
<node TEXT="Groups" ID="ID_1828321125" CREATED="1508253738725" MODIFIED="1508253823100">
<node TEXT="Records" ID="ID_1639359770" CREATED="1500520618035" MODIFIED="1508253755215">
<attribute NAME="textbook" VALUE="06-07"/>
<node TEXT="Records are formed by concatenating two or more types called fields" ID="ID_1377791570" CREATED="1508255934971" MODIFIED="1508255949620"/>
</node>
<node TEXT="Tuples" ID="ID_510159792" CREATED="1500520656107" MODIFIED="1508253758254">
<attribute NAME="textbook" VALUE="06-08"/>
<node TEXT="Tuples are like records but fields are anonymous" ID="ID_1965171323" CREATED="1508255896384" MODIFIED="1508255917521"/>
<node TEXT="Arise in generic programming" ID="ID_1228134902" CREATED="1508255918013" MODIFIED="1508255928586"/>
</node>
<node TEXT="Unions" ID="ID_1469131663" CREATED="1500520812523" MODIFIED="1508253764157">
<attribute NAME="textbook" VALUE="06-10"/>
<node TEXT="List of types and value is at most one of the listed types" ID="ID_500500739" CREATED="1508256587887" MODIFIED="1508256621208"/>
<node TEXT="Discriminated or Free" ID="ID_1996548466" CREATED="1500520825283" MODIFIED="1500520841552"/>
</node>
</node>
</node>
<node TEXT="Allocations" POSITION="right" ID="ID_1643349331" CREATED="1508254037196" MODIFIED="1508254051009">
<edge COLOR="#0000ff"/>
<node TEXT="Memory" ID="ID_1873562928" CREATED="1508254055670" MODIFIED="1508254060138">
<node TEXT="Pointers" ID="ID_998364589" CREATED="1500520849939" MODIFIED="1508254064180">
<attribute NAME="textbook" VALUE="06-11"/>
<node TEXT="Entity is a reference to some other" ID="ID_458382794" CREATED="1500520898852" MODIFIED="1500520911976"/>
<node TEXT="Pointers are addresses" ID="ID_1093382788" CREATED="1500520966611" MODIFIED="1500520971784"/>
<node TEXT="References refer to objects" ID="ID_1204484524" CREATED="1500520972139" MODIFIED="1500521121152"/>
</node>
<node TEXT="Reference Types" ID="ID_17624008" CREATED="1508254078904" MODIFIED="1508254084010">
<node TEXT="Reference types are pointers" ID="ID_1622109240" CREATED="1508254084014" MODIFIED="1508254090777"/>
<node TEXT="Language implementation manages lifetime" ID="ID_1701468889" CREATED="1508254091156" MODIFIED="1508254105610"/>
<node TEXT="Never null" ID="ID_1530420228" CREATED="1508254106045" MODIFIED="1508254111178"/>
</node>
<node TEXT="Pointer Problems" ID="ID_1548418832" CREATED="1500520916571" MODIFIED="1508254115077">
<node TEXT="Dangling Pointer" ID="ID_1229858475" CREATED="1500520930284" MODIFIED="1500520935376"/>
<node TEXT="Garbage" ID="ID_484310557" CREATED="1500520936635" MODIFIED="1500520960944"/>
<node TEXT="Reference Semantics (aliasing)" ID="ID_1637743955" CREATED="1508253899864" MODIFIED="1508253913812"/>
</node>
<node TEXT="Pointer Operations" ID="ID_503648560" CREATED="1500520912891" MODIFIED="1508254119779">
<node TEXT="Pointers refer to memory locations so arithmetic makes sense" ID="ID_1123147473" CREATED="1508254277253" MODIFIED="1508254291163"/>
<node TEXT="References refer to objects so arithmetic does not make sense" ID="ID_1159652386" CREATED="1508254291637" MODIFIED="1508254303506"/>
<node TEXT="In both cases dereferencing (which may be automatic) is defined" ID="ID_1150896303" CREATED="1508254303883" MODIFIED="1508254319195"/>
</node>
<node TEXT="Garbage Collection" ID="ID_424812365" CREATED="1500521134556" MODIFIED="1508254122460">
<node TEXT="Reference counting" ID="ID_1857683605" CREATED="1508256675549" MODIFIED="1508256680194"/>
<node TEXT="Mark and Sweep" ID="ID_528811327" CREATED="1508256680610" MODIFIED="1508256683420"/>
</node>
</node>
</node>
<node TEXT="User Defined" POSITION="right" ID="ID_482814110" CREATED="1508254405211" MODIFIED="1508254413051">
<edge COLOR="#00ff00"/>
<node TEXT="User Defined Data Types" ID="ID_174221598" CREATED="1500521428836" MODIFIED="1508254415608">
<attribute NAME="textbook" VALUE="11-02"/>
<node TEXT="Does the language allow user defined types" ID="ID_955469578" CREATED="1508254546545" MODIFIED="1508254557300"/>
<node TEXT="Are they first or second class citizens" ID="ID_452562790" CREATED="1508254557686" MODIFIED="1508254565127"/>
<node TEXT="What tools exist for encapsulation and abstraction" ID="ID_11181065" CREATED="1508254565649" MODIFIED="1508254590924"/>
</node>
<node TEXT="Parameterized Types" ID="ID_252198774" CREATED="1500521601612" MODIFIED="1508254418049">
<attribute NAME="textbook" VALUE="11-05"/>
<node TEXT="User defined type constructor" ID="ID_197570781" CREATED="1508254420402" MODIFIED="1508254430916"/>
<node TEXT="Critical for generic programming style" ID="ID_1553389825" CREATED="1508254459514" MODIFIED="1508254473262"/>
</node>
</node>
</node>
</map>
