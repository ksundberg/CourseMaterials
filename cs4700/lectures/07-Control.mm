<map version="freeplane 1.3.0">
<!--To view this file, download free mind mapping software Freeplane from http://freeplane.sourceforge.net -->
<node TEXT="Control" ID="ID_1723255651" CREATED="1283093380553" MODIFIED="1500526233824"><hook NAME="MapStyle">
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
<hook NAME="AutomaticEdgeColor" COUNTER="8"/>
<node TEXT="Control" POSITION="right" ID="ID_1720329564" CREATED="1510246008962" MODIFIED="1510246010942">
<edge COLOR="#00007c"/>
<node TEXT="Selection" ID="ID_1759031605" CREATED="1510245932957" MODIFIED="1510246013116">
<node TEXT="Selection" ID="ID_684404050" CREATED="1500526266497" MODIFIED="1510246015124">
<attribute NAME="textbook" VALUE="08-02"/>
<node TEXT="Statements that allow conditional execution" ID="ID_1385385537" CREATED="1510245901152" MODIFIED="1510245925948"/>
</node>
<node TEXT="Two way" ID="ID_1560321219" CREATED="1510246017089" MODIFIED="1510246023999">
<node TEXT="If - then - else" ID="ID_1124336949" CREATED="1510246024367" MODIFIED="1510246046074"/>
<node TEXT="What is the type of the control expression?" ID="ID_1714563554" CREATED="1510246046483" MODIFIED="1510246071010"/>
<node TEXT="What is the form of the clause?" ID="ID_1006946086" CREATED="1510246071991" MODIFIED="1510246082115">
<node TEXT="Single statement?" ID="ID_1561303531" CREATED="1510246082119" MODIFIED="1510246085309"/>
<node TEXT="Block?" ID="ID_607039289" CREATED="1510246085648" MODIFIED="1510246089411"/>
</node>
</node>
<node TEXT="Nesting ambiguity" ID="ID_919860264" CREATED="1510246118497" MODIFIED="1510246124427">
<node TEXT="if e1 if e2 c1 else c2" ID="ID_1039556816" CREATED="1510246124431" MODIFIED="1510246146251"/>
<node TEXT="Where does the else belong?" ID="ID_261717126" CREATED="1510246146707" MODIFIED="1510246151784"/>
<node TEXT="Only occurs if clause form permits" ID="ID_1100399357" CREATED="1510246184981" MODIFIED="1510246200350"/>
</node>
<node TEXT="Multiple Selection" ID="ID_1061263442" CREATED="1510246209394" MODIFIED="1510246217299">
<node TEXT="Switch - Case - Patterns" ID="ID_1242246676" CREATED="1510246217304" MODIFIED="1510246289632"/>
<node TEXT="What is the form of the selection expression?" ID="ID_856610345" CREATED="1510246233869" MODIFIED="1510246241109"/>
<node TEXT="How are the cases specified?" ID="ID_149537175" CREATED="1510246244091" MODIFIED="1510246250387"/>
<node TEXT="What if nothing matches?" ID="ID_123695973" CREATED="1510246262613" MODIFIED="1510246272868"/>
</node>
<node TEXT="Multiple Selection Implementation" ID="ID_296865855" CREATED="1510246305488" MODIFIED="1510246319576">
<node TEXT="Nested ifs" ID="ID_1087550362" CREATED="1510246319580" MODIFIED="1510246323546"/>
<node TEXT="Tree - (Command Pattern)" ID="ID_168071045" CREATED="1510246323923" MODIFIED="1510246338355"/>
<node TEXT="Jump tables" ID="ID_1562523023" CREATED="1510246338816" MODIFIED="1510246341786"/>
</node>
</node>
<node TEXT="Iteration" ID="ID_350612878" CREATED="1510246377756" MODIFIED="1510246385066">
<node TEXT="Iteration" ID="ID_1659503822" CREATED="1500526302969" MODIFIED="1510246387945">
<attribute NAME="textbook" VALUE="08-03"/>
<node TEXT="Used for repetition" ID="ID_1951081278" CREATED="1510246389125" MODIFIED="1510246400377"/>
<node TEXT="How is it controlled" ID="ID_651952690" CREATED="1510246439595" MODIFIED="1510246443689"/>
<node TEXT="Where does the control structure appear" ID="ID_848790413" CREATED="1510246444468" MODIFIED="1510246452198"/>
<node TEXT="Can be replaced by recursion" ID="ID_197018483" CREATED="1510246452829" MODIFIED="1510246472007"/>
</node>
<node TEXT="Counter Controlled Loops" ID="ID_406285384" CREATED="1510246477425" MODIFIED="1510246484574">
<node TEXT="Has a loop variable" ID="ID_282348139" CREATED="1510246484578" MODIFIED="1510246496544"/>
<node TEXT="Loop variable has a begin, end, and step" ID="ID_1926005490" CREATED="1510246496894" MODIFIED="1510246506318"/>
<node TEXT="For" ID="ID_687648487" CREATED="1510246511363" MODIFIED="1510246512670"/>
<node TEXT="For each" ID="ID_885622479" CREATED="1510246513021" MODIFIED="1510246514788"/>
</node>
<node TEXT="Logically Controlled Loops" ID="ID_841547422" CREATED="1510246548135" MODIFIED="1510246553716">
<node TEXT="Has a condition" ID="ID_1742216206" CREATED="1510246553720" MODIFIED="1510246627770"/>
<node TEXT="Is the test before or after the loop" ID="ID_1452845031" CREATED="1510246632208" MODIFIED="1510246652801"/>
<node TEXT="while(e)" ID="ID_1509402399" CREATED="1510246656624" MODIFIED="1510246659556"/>
<node TEXT="do .. while(e)" ID="ID_141827211" CREATED="1510246659936" MODIFIED="1510246666613"/>
</node>
<node TEXT="Loop Control Statements" ID="ID_512010093" CREATED="1510246678148" MODIFIED="1510246686129">
<node TEXT="User located loop exits" ID="ID_830504296" CREATED="1510246686134" MODIFIED="1510246707459">
<node TEXT="break" ID="ID_1576566064" CREATED="1510246714512" MODIFIED="1510246722408"/>
<node TEXT="last" ID="ID_1095257021" CREATED="1510246722823" MODIFIED="1510246724241"/>
</node>
<node TEXT="Skip statement" ID="ID_1480432873" CREATED="1510246736540" MODIFIED="1510246743445">
<node TEXT="continue" ID="ID_237446597" CREATED="1510246743449" MODIFIED="1510246756531"/>
</node>
<node TEXT="Used to eliminate some uses of goto" ID="ID_1689100441" CREATED="1510246758300" MODIFIED="1510246768068"/>
</node>
<node TEXT="Unconditional Branch" ID="ID_834970620" CREATED="1500526377993" MODIFIED="1510246403316">
<attribute NAME="textbook" VALUE="08-04"/>
<node TEXT="Most flexible and powerful of statements" ID="ID_1233964786" CREATED="1510246789628" MODIFIED="1510246798561"/>
<node TEXT="Other control structures an be implemented in terms of goto" ID="ID_1165120834" CREATED="1510246798966" MODIFIED="1510246812215"/>
<node TEXT="Some languages don&apos;t have it" ID="ID_1527431368" CREATED="1510246851173" MODIFIED="1510246871054"/>
</node>
<node TEXT="Goto Considered Harmful" ID="ID_78174649" CREATED="1500526235441" MODIFIED="1510246409009">
<node TEXT="Dijkstra&apos;s 1968 seminal paper" ID="ID_1172398502" CREATED="1510246821222" MODIFIED="1510246842706"/>
</node>
</node>
<node TEXT="Non-deterministic" ID="ID_1103003980" CREATED="1510246890136" MODIFIED="1510246929086">
<node TEXT="Guarded Commands" ID="ID_540279879" CREATED="1500526558817" MODIFIED="1510246931205">
<attribute NAME="textbook" VALUE="08-05"/>
<node TEXT="Introduced by Dijkstra in 1975" ID="ID_550581972" CREATED="1510247054830" MODIFIED="1510247065229"/>
<node TEXT="A block of statements with boolean guards" ID="ID_798659648" CREATED="1510247065861" MODIFIED="1510248347839"/>
<node TEXT="One expression whos guard is true is executed." ID="ID_1926200242" CREATED="1510248348219" MODIFIED="1510248363331"/>
</node>
</node>
</node>
</node>
</map>
