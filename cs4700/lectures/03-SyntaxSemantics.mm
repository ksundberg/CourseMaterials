<map version="freeplane 1.3.0">
<!--To view this file, download free mind mapping software Freeplane from http://freeplane.sourceforge.net -->
<node TEXT="Syntax and Semantics" ID="ID_1723255651" CREATED="1283093380553" MODIFIED="1500350691443"><hook NAME="MapStyle">
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
<attribute NAME="author" VALUE="Kenneth Sundberg"/>
<attribute NAME="subtitle" VALUE="CS 4700"/>
<node TEXT="Theory" POSITION="right" ID="ID_1335213720" CREATED="1505225753908" MODIFIED="1505225762165">
<edge COLOR="#7c0000"/>
<node TEXT="Language" ID="ID_741882860" CREATED="1505225226467" MODIFIED="1505225234847">
<node TEXT="Language" ID="ID_18695416" CREATED="1505225248432" MODIFIED="1505225251078">
<node TEXT="Given an alphabet (a set of characters)" ID="ID_30577059" CREATED="1505225256061" MODIFIED="1505225290030"/>
<node TEXT="A language is a set of character strings" ID="ID_668762443" CREATED="1505225290360" MODIFIED="1505225318858"/>
<node TEXT="All computable questions can be framed in terms of languages" ID="ID_303559477" CREATED="1505225357147" MODIFIED="1505225373193"/>
</node>
<node TEXT="Recognizers" ID="ID_1718392118" CREATED="1500349767891" MODIFIED="1500349770778">
<node TEXT="A recognizer for a language is a machine that returns true or false given a string of characters" ID="ID_1936061836" CREATED="1505225377337" MODIFIED="1505225421373"/>
<node TEXT="The recognizer only returns true for elements of the language" ID="ID_252289504" CREATED="1505225424074" MODIFIED="1505225449729"/>
<node TEXT="Some recognizers may never return at all on some inputs, those inputs are not in the language" ID="ID_897816619" CREATED="1505225450740" MODIFIED="1505225476497"/>
</node>
<node TEXT="Generators" ID="ID_872672935" CREATED="1500349771445" MODIFIED="1500349773151">
<node TEXT="A generator is a machine (sometimes non-deterministic) that can produce every element of a language" ID="ID_1974271125" CREATED="1505225479788" MODIFIED="1505225502880"/>
</node>
<node TEXT="Hierarchy of computable languages" ID="ID_1694454940" CREATED="1505225522926" MODIFIED="1505225541934">
<node TEXT="There are three types of computable languages" ID="ID_1656715884" CREATED="1505225541941" MODIFIED="1505225566398">
<node TEXT="Regular" ID="ID_1488679390" CREATED="1505225568040" MODIFIED="1505225570886"/>
<node TEXT="Context Free" ID="ID_1569434140" CREATED="1505225571304" MODIFIED="1505225574694"/>
<node TEXT="Context Sensitive" ID="ID_1570898919" CREATED="1505225575120" MODIFIED="1505225579953"/>
</node>
<node TEXT="Each langauge class is a proper subset of the next" ID="ID_1060559284" CREATED="1505225586408" MODIFIED="1505225609752"/>
</node>
</node>
</node>
<node TEXT="Language" POSITION="right" ID="ID_1402361844" CREATED="1500349473387" MODIFIED="1505225813326">
<edge COLOR="#ff0000"/>
<node TEXT="Lexical Structure" ID="ID_604409077" CREATED="1505225623906" MODIFIED="1505225737285">
<node TEXT="Lexemes" ID="ID_462591628" CREATED="1500349625955" MODIFIED="1505225737284">
<attribute NAME="textbook" VALUE="03-02"/>
<node TEXT="A Lexeme is a word in a programming language" ID="ID_906889043" CREATED="1505225641154" MODIFIED="1505225650573"/>
<node TEXT="Forms the most basic structure" ID="ID_1867119709" CREATED="1505225667347" MODIFIED="1505225678679"/>
<node TEXT="The language of legal lexemes for a programming language is regular" ID="ID_1902813552" CREATED="1505225682283" MODIFIED="1505225700080"/>
<node TEXT="Examples:" ID="ID_1911315003" CREATED="1505225650994" MODIFIED="1505225655998">
<node TEXT="Identifiers" ID="ID_248623934" CREATED="1505225656006" MODIFIED="1505225659804"/>
<node TEXT="Keywords" ID="ID_1394562692" CREATED="1505225660233" MODIFIED="1505225663288"/>
</node>
</node>
<node TEXT="Lexical Analysis" ID="ID_894477464" CREATED="1500350438068" MODIFIED="1505225815790">
<attribute NAME="textbook" VALUE="04-02"/>
</node>
<node TEXT="Regular Expressions" ID="ID_1133713139" CREATED="1500350481483" MODIFIED="1500350484512">
<node TEXT="Concatenation" ID="ID_199870314" CREATED="1505226018122" MODIFIED="1505226027851"/>
<node TEXT="Alternation" ID="ID_1086552282" CREATED="1505226028312" MODIFIED="1505226032205"/>
<node TEXT="Kleene Closure" ID="ID_615642291" CREATED="1505226032605" MODIFIED="1505226037824"/>
</node>
<node TEXT="Finite Automata" ID="ID_1266848958" CREATED="1500350472156" MODIFIED="1500350481145"/>
<node TEXT="FA = RE" ID="ID_1878450427" CREATED="1505225977368" MODIFIED="1505225986905"/>
<node TEXT="NFA = FA" ID="ID_89945977" CREATED="1505225987444" MODIFIED="1505226008106"/>
</node>
<node TEXT="Syntax" ID="ID_1919105845" CREATED="1505225730027" MODIFIED="1505225782835">
<node TEXT="Context Free Grammars" ID="ID_389745230" CREATED="1500349802395" MODIFIED="1500349822321">
<attribute NAME="textbook" VALUE="03-03"/>
<node TEXT="Alphabet of terminal symbols (same alphabet as language)" ID="ID_933734167" CREATED="1505230578553" MODIFIED="1505230605074">
<node TEXT="Lexemes" ID="ID_1830592289" CREATED="1505230721517" MODIFIED="1505230736703"/>
</node>
<node TEXT="Alphabet of non-terminal symbols (Not in the language)" ID="ID_731866240" CREATED="1505230605556" MODIFIED="1505230622205"/>
<node TEXT="Set of re-writing rules" ID="ID_1070318189" CREATED="1505230622930" MODIFIED="1505230641388">
<node TEXT="Left side is a single non-terminal" ID="ID_1870344261" CREATED="1505230641394" MODIFIED="1505230649531"/>
<node TEXT="Right side is a string of symbols (terminal, non-terminal, or mixed) which may be empty" ID="ID_526892762" CREATED="1505230649991" MODIFIED="1505230675171"/>
</node>
</node>
<node TEXT="Parsing" ID="ID_991931485" CREATED="1500350492852" MODIFIED="1505225823976">
<attribute NAME="textbook" VALUE="04-03"/>
<node TEXT="CFGs are convenient for people and are good generators" ID="ID_1486710371" CREATED="1505230747053" MODIFIED="1505230771972"/>
<node TEXT="A parser is a mechanical acceptor of a context free grammar" ID="ID_316893215" CREATED="1505230772320" MODIFIED="1505230787068"/>
<node TEXT="Also known as a push down automata" ID="ID_1908292078" CREATED="1505230799837" MODIFIED="1505230830636">
<node TEXT="CFG = PDA" ID="ID_922230754" CREATED="1505230830641" MODIFIED="1505230835090"/>
<node TEXT="NPDA = PDA" ID="ID_261834430" CREATED="1505230835587" MODIFIED="1505230840803"/>
</node>
<node TEXT="Parsing produces a parse tree (may be implicit)" ID="ID_545784239" CREATED="1505230864001" MODIFIED="1505230886195"/>
</node>
<node TEXT="Ambiguity" ID="ID_483661089" CREATED="1500349842179" MODIFIED="1500349845112">
<node TEXT="A sentence in a language for which there is more than one possible parse tree is ambiguous" ID="ID_799577797" CREATED="1505230888626" MODIFIED="1505230915290"/>
<node TEXT="Programming languages do not tolerate ambiguity well" ID="ID_1041928164" CREATED="1505230915840" MODIFIED="1505230949397"/>
</node>
<node TEXT="Operator precedence" ID="ID_601840039" CREATED="1500349961483" MODIFIED="1500349965944">
<node TEXT="A common source of ambiguity are math operators" ID="ID_765947680" CREATED="1505230955413" MODIFIED="1505230973655"/>
<node TEXT="Unambiguous grammars exist but require more states" ID="ID_1306222270" CREATED="1505230974110" MODIFIED="1505230999341"/>
<node TEXT="The issue can be solved more efficiently with precedence rules" ID="ID_1356378664" CREATED="1505230999759" MODIFIED="1505231028244"/>
</node>
<node TEXT="Recursive Descent" ID="ID_980913813" CREATED="1500350504164" MODIFIED="1500350599475">
<attribute NAME="textbook" VALUE="04-04"/>
<node TEXT="Recursive descent parsing (LL parsing) is simple to write" ID="ID_371172274" CREATED="1505231090090" MODIFIED="1505231109607"/>
<node TEXT="Write a function for each non-terminal" ID="ID_639236542" CREATED="1505231109962" MODIFIED="1505231129933"/>
<node TEXT="Following the right hand side if there is a terminal consume it if there is a non-terminal invoke the appropriate function" ID="ID_453887098" CREATED="1505231131301" MODIFIED="1505231156538"/>
<node TEXT="Unable to cope with left recursion - making it generally unsuitable for programming languages" ID="ID_1034560117" CREATED="1505231157374" MODIFIED="1505231190637"/>
</node>
<node TEXT="LR Parser" ID="ID_314210539" CREATED="1500350519772" MODIFIED="1500350632908">
<attribute NAME="textbook" VALUE="04-05"/>
<node TEXT="LR parsing is more general than LL" ID="ID_1805861471" CREATED="1505231203010" MODIFIED="1505231218805"/>
<node TEXT="Produces very fast , table based parsers" ID="ID_1387532660" CREATED="1505231219066" MODIFIED="1505231239622"/>
<node TEXT="The algorithm is beyond the scope of the course and is very prone to human error" ID="ID_838428959" CREATED="1505231245242" MODIFIED="1505231267789">
<node TEXT="A very important use case for goto" ID="ID_1386398984" CREATED="1505231267792" MODIFIED="1505231280822"/>
<node TEXT="Generated by programs called compiler compilers (javacc, bison, etc)" ID="ID_1398522939" CREATED="1505231281201" MODIFIED="1505231304680"/>
</node>
</node>
<node TEXT="Arithmetic Parsing" ID="ID_1436533491" CREATED="1505231378773" MODIFIED="1505231452661"/>
</node>
<node TEXT="Semantics" ID="ID_1369099253" CREATED="1500349978427" MODIFIED="1505225775311">
<node TEXT="Static Semantics" ID="ID_1538235156" CREATED="1500349986931" MODIFIED="1500350083969">
<attribute NAME="textbook" VALUE="03-04"/>
<node TEXT="Some rules of languages are difficult (or impossible) to specify only with a CFG" ID="ID_102179633" CREATED="1505231668606" MODIFIED="1505231684903"/>
<node TEXT="Any rule that depends on context" ID="ID_1017540373" CREATED="1505231685453" MODIFIED="1505231733591">
<node TEXT="Type checking" ID="ID_985421937" CREATED="1505231733595" MODIFIED="1505231736576"/>
<node TEXT="Undefined identifiers" ID="ID_1995740864" CREATED="1505231736965" MODIFIED="1505231749590"/>
</node>
</node>
<node TEXT="Attribute Grammars" ID="ID_657797324" CREATED="1500350086579" MODIFIED="1500350092024"/>
<node TEXT="Arithmatic Grammar" ID="ID_61499148" CREATED="1500350092419" MODIFIED="1500350236353"/>
<node TEXT="Dynamic Semantics" ID="ID_588101664" CREATED="1500350244396" MODIFIED="1500350257659">
<attribute NAME="textbook" VALUE="03-05"/>
<node TEXT="What does a program mean?" ID="ID_917520694" CREATED="1505837488951" MODIFIED="1505837501471"/>
<node TEXT="What are the defined run time behaviors" ID="ID_1967883622" CREATED="1505837501880" MODIFIED="1505837509132"/>
</node>
<node TEXT="Operational Semantics" ID="ID_1411333744" CREATED="1500350303148" MODIFIED="1500350309673">
<node TEXT="Define meaning of program in terms of state changes on a low level machine" ID="ID_192166207" CREATED="1505837400529" MODIFIED="1505837415366"/>
<node TEXT="Changes are too small and numerous to be of much use" ID="ID_1327690776" CREATED="1505837415698" MODIFIED="1505837426007"/>
<node TEXT="Natural Operational Semantics - Define the effect of entire program" ID="ID_1644590402" CREATED="1505837438558" MODIFIED="1505837458772"/>
<node TEXT="Structural Operational Semantics - Define low level sequence of state changes" ID="ID_851617693" CREATED="1505837459140" MODIFIED="1505837480519"/>
</node>
<node TEXT="Denotational Semantics" ID="ID_1407608982" CREATED="1500350310156" MODIFIED="1505837697509">
<node TEXT="Map language constructs onto math objects" ID="ID_1712874885" CREATED="1505837511794" MODIFIED="1505837564778"/>
<node TEXT="Typically functions, but also possibly ranges, categories, groups and others" ID="ID_521615770" CREATED="1505837565160" MODIFIED="1505837597223"/>
<node TEXT="Complex denotational semantics generally indicate a difficult to implement language" ID="ID_56817082" CREATED="1505837667481" MODIFIED="1505837687654"/>
</node>
<node TEXT="Axiomatic Semantics" ID="ID_1390733064" CREATED="1500350367940" MODIFIED="1500350373329">
<node TEXT="The program means what it can be proven to mean" ID="ID_620098613" CREATED="1505837714762" MODIFIED="1505837730200">
<node TEXT="No model of a state machine" ID="ID_832677315" CREATED="1505837754568" MODIFIED="1505837761659"/>
<node TEXT="Only the fixed relations between language entities" ID="ID_1196157381" CREATED="1505837762013" MODIFIED="1505837781112"/>
</node>
<node TEXT="Useful in program verification" ID="ID_489398102" CREATED="1505837730573" MODIFIED="1505837735278">
<node TEXT="Preconditions" ID="ID_1636927903" CREATED="1505837847257" MODIFIED="1505837855043"/>
<node TEXT="Postconditions" ID="ID_1290096019" CREATED="1505837855319" MODIFIED="1505837858838"/>
</node>
</node>
</node>
</node>
</node>
</map>
