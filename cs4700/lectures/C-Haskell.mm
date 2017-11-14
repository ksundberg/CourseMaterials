<map version="freeplane 1.3.0">
<!--To view this file, download free mind mapping software Freeplane from http://freeplane.sourceforge.net -->
<node TEXT="Haskell" ID="ID_1723255651" CREATED="1283093380553" MODIFIED="1509638263799"><hook NAME="MapStyle">
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
<hook NAME="AutomaticEdgeColor" COUNTER="7"/>
<node TEXT="Syntax" POSITION="right" ID="ID_863752899" CREATED="1510075088496" MODIFIED="1510075094221">
<edge COLOR="#7c0000"/>
<node TEXT="Tools" ID="ID_233492264" CREATED="1510072971267" MODIFIED="1510075107918">
<node TEXT="GHC" ID="ID_903155320" CREATED="1510072975651" MODIFIED="1510075161375">
<attribute NAME="textbook" VALUE="15-08"/>
<node TEXT="The Glasgow Haskell Compiler is what we will use for haskell" ID="ID_1565942847" CREATED="1510072981621" MODIFIED="1510073011551"/>
<node TEXT="Includes an interpreter ghci which is very usefull" ID="ID_568757832" CREATED="1510073012053" MODIFIED="1510073022684"/>
<node TEXT=":q to quit" ID="ID_1419492935" CREATED="1510073172741" MODIFIED="1510073176173"/>
</node>
</node>
<node TEXT="Functions" ID="ID_201009229" CREATED="1509638594804" MODIFIED="1510075104927">
<node TEXT="Definition" ID="ID_625090521" CREATED="1510072717529" MODIFIED="1510072721195">
<node TEXT="mylength x y = sqrt ( x * x + y * y )" ID="ID_1124793020" CREATED="1510072740435" MODIFIED="1510073292435"/>
<node TEXT="Function application operator is the space" ID="ID_1495002202" CREATED="1510075293347" MODIFIED="1510075301280"/>
</node>
<node TEXT="Pattern Matching" ID="ID_147905249" CREATED="1509638265162" MODIFIED="1509638600647">
<node TEXT="Value based polymorphism" ID="ID_1761943012" CREATED="1510073630703" MODIFIED="1510073643443"/>
<node TEXT="Rules are checked from top to bottom" ID="ID_874657469" CREATED="1510073643819" MODIFIED="1510073650465"/>
<node TEXT="At least one rule must match every input or it is an error" ID="ID_518278052" CREATED="1510073650904" MODIFIED="1510073662821"/>
<node TEXT="fact 1 = 1" ID="ID_705147728" CREATED="1510073309329" MODIFIED="1510073314777"/>
<node TEXT="fact n = fact (n - 1) * n" ID="ID_1650714406" CREATED="1510073315108" MODIFIED="1510073326144"/>
</node>
<node TEXT="Guards" ID="ID_193591604" CREATED="1510072725307" MODIFIED="1510072728149">
<node TEXT="Property based pattern matching" ID="ID_1423677872" CREATED="1510074068349" MODIFIED="1510074077264"/>
<node TEXT="foo x | x &lt; 10 = 10 | x &gt;= 10 = x" ID="ID_1671641355" CREATED="1510074077745" MODIFIED="1510074101673"/>
</node>
<node TEXT="Partial Function Application" ID="ID_149670798" CREATED="1509777839093" MODIFIED="1509777852710">
<node TEXT="All functions in Haskell take one parameter and return one value" ID="ID_1231288230" CREATED="1509777852718" MODIFIED="1509777863777"/>
<node TEXT="Functions of multiple parameters are formed via partial application" ID="ID_1682650724" CREATED="1509777872739" MODIFIED="1510074263041"/>
</node>
</node>
<node TEXT="Lists" ID="ID_1815318575" CREATED="1509638577876" MODIFIED="1510075100026">
<node TEXT="List" ID="ID_1273784856" CREATED="1510074271033" MODIFIED="1510074274150">
<node TEXT="$[1,4,7,8]$" ID="ID_1945057570" CREATED="1510074274158" MODIFIED="1510075273321"/>
<node TEXT="$[]$" ID="ID_1968906423" CREATED="1510074283656" MODIFIED="1510075277133"/>
</node>
<node TEXT="Ranges" ID="ID_1380806943" CREATED="1509638711731" MODIFIED="1509638713671">
<node TEXT="$[1..8]$" ID="ID_1141796653" CREATED="1510074291075" MODIFIED="1510075282683"/>
<node TEXT="$[2..]$" ID="ID_190136325" CREATED="1510074296703" MODIFIED="1510075289220"/>
</node>
<node TEXT="List Comprehension" ID="ID_1929134547" CREATED="1509638585996" MODIFIED="1509638589719">
<node TEXT="$[ f x | x &lt;- set, pred x]$" ID="ID_1326541889" CREATED="1510074416713" MODIFIED="1510075371426"/>
<node TEXT="$[x*x | x&lt;- [1..10]]$" ID="ID_1605371365" CREATED="1510074439316" MODIFIED="1510075378848"/>
</node>
</node>
<node TEXT="Data Types" ID="ID_1903435828" CREATED="1510075255427" MODIFIED="1510075260491">
<node TEXT="Data Types" ID="ID_1836494661" CREATED="1510072703214" MODIFIED="1510075097719">
<node TEXT="data Name = Type Field Field .." ID="ID_867354080" CREATED="1510074543680" MODIFIED="1510074584643"/>
<node TEXT="Space has a very high precedence you may need parenthesis" ID="ID_1906873753" CREATED="1510074585118" MODIFIED="1510074604943"/>
</node>
</node>
</node>
</node>
</map>
