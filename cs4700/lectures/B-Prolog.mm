<map version="freeplane 1.3.0">
<!--To view this file, download free mind mapping software Freeplane from http://freeplane.sourceforge.net -->
<node TEXT="Prolog" ID="ID_1723255651" CREATED="1283093380553" MODIFIED="1504798038334"><hook NAME="MapStyle">

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
<hook NAME="AutomaticEdgeColor" COUNTER="4"/>
<node TEXT="History" POSITION="right" ID="ID_1495219338" CREATED="1504798039008" MODIFIED="1504798043893">
<edge COLOR="#ff0000"/>
<node TEXT="History" ID="ID_1775032872" CREATED="1506009123415" MODIFIED="1506009130095">
<node TEXT="Prolog" ID="ID_1824970613" CREATED="1506009130100" MODIFIED="1506009135337">
<node TEXT="Short for Programming in Logic" ID="ID_365127134" CREATED="1506009135341" MODIFIED="1506009868890"/>
<node TEXT="Developed between 1970 and 1972" ID="ID_206714677" CREATED="1506009145866" MODIFIED="1506009159693"/>
</node>
<node TEXT="Logic Language" ID="ID_1536273205" CREATED="1506009882087" MODIFIED="1506009887735">
<node TEXT="Prolog is the first and most popular logic language" ID="ID_387048813" CREATED="1506009892850" MODIFIED="1506009915052"/>
<node TEXT="In a &apos;pure&apos; logic lanugage the order of statements is unimportant" ID="ID_551298119" CREATED="1506009915408" MODIFIED="1506009944975">
<node TEXT="Prolog is not pure, but close" ID="ID_405759030" CREATED="1506009961519" MODIFIED="1506009983844"/>
</node>
<node TEXT="Based on theorem proving" ID="ID_768318419" CREATED="1506009993404" MODIFIED="1506010003934">
<node TEXT="Program consists of axioms and inference rules" ID="ID_646483315" CREATED="1506010004885" MODIFIED="1506010015622"/>
<node TEXT="Execution asks if certain queries can be proven" ID="ID_1936746269" CREATED="1506010016271" MODIFIED="1506010030748"/>
</node>
</node>
</node>
</node>
<node TEXT="Syntax" POSITION="right" ID="ID_1910212926" CREATED="1504798058518" MODIFIED="1504798069296">
<edge COLOR="#00ff00"/>
<node TEXT="Statements" ID="ID_586191226" CREATED="1504798087446" MODIFIED="1504798093966">
<node TEXT="Statements" ID="ID_1970464835" CREATED="1504798199273" MODIFIED="1504798203460">
<node TEXT="Statements occur in files" ID="ID_1960010940" CREATED="1504798223809" MODIFIED="1504798232125"/>
<node TEXT="A form of database" ID="ID_361429576" CREATED="1504798232487" MODIFIED="1504798241690"/>
</node>
<node TEXT="Predicates" ID="ID_1042523087" CREATED="1504798270032" MODIFIED="1504798285992">
<node TEXT="name(args...)." ID="ID_1507612640" CREATED="1504798285997" MODIFIED="1504798301769"/>
<node TEXT="Asserts that predicate name is true for given arguments (may be empty)" ID="ID_229215578" CREATED="1504798302128" MODIFIED="1504798328075"/>
<node TEXT="The axioms of the logic system" ID="ID_1428314380" CREATED="1506010037455" MODIFIED="1506010043594"/>
</node>
<node TEXT="Rules" ID="ID_1088565112" CREATED="1504798349128" MODIFIED="1504798360948">
<node TEXT="name(vars...):- statement list" ID="ID_651135542" CREATED="1504798360952" MODIFIED="1504798403597"/>
</node>
</node>
<node TEXT="Queries" ID="ID_1665530702" CREATED="1504798094281" MODIFIED="1504798096894">
<node TEXT="Queries" ID="ID_131114084" CREATED="1506008887298" MODIFIED="1506008917433">
<node TEXT="Queries have the same syntax as predicates" ID="ID_326950652" CREATED="1506008917438" MODIFIED="1506008948935"/>
<node TEXT="Respond with a matching predicate or with fail" ID="ID_342700486" CREATED="1506008949428" MODIFIED="1506008977288"/>
</node>
<node TEXT="Variables" ID="ID_459479923" CREATED="1506009001451" MODIFIED="1506009004972">
<node TEXT="Queries can contain variables" ID="ID_1622412396" CREATED="1506009005968" MODIFIED="1506009014619"/>
<node TEXT="These are like math variables" ID="ID_865147171" CREATED="1506009027880" MODIFIED="1506009041401">
<node TEXT="Unknown" ID="ID_276664716" CREATED="1506009041405" MODIFIED="1506009049732"/>
<node TEXT="Fixed values" ID="ID_354113420" CREATED="1506009050069" MODIFIED="1506009056031"/>
<node TEXT="Multiple solutions possible" ID="ID_1646131777" CREATED="1506009056410" MODIFIED="1506009070084"/>
</node>
<node TEXT="Queries with multiple solutions return multiple times" ID="ID_63520845" CREATED="1506009071879" MODIFIED="1506009087661"/>
</node>
</node>
</node>
<node TEXT="Resolution" POSITION="right" ID="ID_1530790348" CREATED="1504798070000" MODIFIED="1504798075859">
<edge COLOR="#ff00ff"/>
<node TEXT="Resolution" ID="ID_1799034551" CREATED="1506010168464" MODIFIED="1506010178687">
<node TEXT="Resolution" ID="ID_506524768" CREATED="1506010223815" MODIFIED="1506010227618">
<node TEXT="Resolution is the process of proving a query" ID="ID_440582481" CREATED="1506010227622" MODIFIED="1506010270854"/>
<node TEXT="Proceeds as if checking from the top of the file" ID="ID_1904002691" CREATED="1506010345943" MODIFIED="1506010800881"/>
<node TEXT="Order can effect performance" ID="ID_390826928" CREATED="1506010801314" MODIFIED="1506010813812"/>
</node>
<node TEXT="Unification" ID="ID_35171301" CREATED="1506010178691" MODIFIED="1506010188762">
<node TEXT="Unification is the process of solving for a variable in a query" ID="ID_1920143356" CREATED="1506010188766" MODIFIED="1506010222403"/>
</node>
</node>
<node TEXT="Debugging" ID="ID_802464737" CREATED="1506010133719" MODIFIED="1506010137512">
<node TEXT="Trace" ID="ID_929057152" CREATED="1506010142192" MODIFIED="1506010145123">
<node TEXT="To start the debugger type trace" ID="ID_138951337" CREATED="1506010146045" MODIFIED="1506010155498"/>
<node TEXT="Then type a query" ID="ID_1231109330" CREATED="1506010156266" MODIFIED="1506010163736"/>
</node>
<node TEXT="Port Model" ID="ID_327463357" CREATED="1504798075870" MODIFIED="1504798081689">
<node TEXT="Call" ID="ID_483235492" CREATED="1504798701033" MODIFIED="1506011206760"/>
<node TEXT="Exit" ID="ID_594367219" CREATED="1504798702924" MODIFIED="1506011210997"/>
<node TEXT="Fail" ID="ID_86674872" CREATED="1504798706133" MODIFIED="1504798707143"/>
<node TEXT="Redo" ID="ID_1129549478" CREATED="1504798707375" MODIFIED="1504798709554"/>
</node>
</node>
</node>
</node>
</map>
