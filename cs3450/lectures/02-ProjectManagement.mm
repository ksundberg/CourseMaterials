<map version="freeplane 1.3.0">
<!--To view this file, download free mind mapping software Freeplane from http://freeplane.sourceforge.net -->
<node TEXT="Project Management" ID="ID_1723255651" CREATED="1283093380553" MODIFIED="1471654632925"><hook NAME="MapStyle">
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
<attribute NAME="author" VALUE="Kenneth Sundberg"/>
<attribute NAME="date" VALUE=""/>
<attribute NAME="subtitle" VALUE="CS 3450"/>
<node TEXT="Documentation" POSITION="right" ID="ID_374127623" CREATED="1471654662849" MODIFIED="1471654668889">
<edge COLOR="#ff0000"/>
<node TEXT="Types" ID="ID_1360921614" CREATED="1473123528738" MODIFIED="1473123625648">
<node TEXT="Historical Documents" ID="ID_1293368695" CREATED="1473123627048" MODIFIED="1473123862547">
<attribute NAME="textbook" VALUE="02-18"/>
<node TEXT="Have somewhere for everything" ID="ID_1339560993" CREATED="1473123640619" MODIFIED="1473123683636"/>
<node TEXT="Email" ID="ID_1183543760" CREATED="1473123684105" MODIFIED="1473123685915"/>
<node TEXT="Notes" ID="ID_657263820" CREATED="1473123686181" MODIFIED="1473123688157"/>
<node TEXT="The purpose is to keep everyone on the same page" ID="ID_1632192056" CREATED="1473123717602" MODIFIED="1473123726264"/>
</node>
<node TEXT="Code" ID="ID_70367371" CREATED="1473123727549" MODIFIED="1473123730422">
<node TEXT="Arguably the most important document" ID="ID_807396414" CREATED="1473123732409" MODIFIED="1473123741652"/>
<node TEXT="Needs good change control" ID="ID_1542537001" CREATED="1473123741922" MODIFIED="1473123747832"/>
</node>
<node TEXT="Design Documents" ID="ID_899271506" CREATED="1473123749519" MODIFIED="1473123753708">
<node TEXT="Like code -- extremly important" ID="ID_1636126265" CREATED="1473123754539" MODIFIED="1473123764736"/>
<node TEXT="Important to keep in sync with the code" ID="ID_1916934621" CREATED="1473123765207" MODIFIED="1473123784753"/>
<node TEXT="Personally I find this easier if they are in the same revision control system" ID="ID_1218752210" CREATED="1473123785079" MODIFIED="1473123799788"/>
</node>
</node>
<node TEXT="Revision Control" ID="ID_670625137" CREATED="1473123801593" MODIFIED="1473123807527">
<node TEXT="Policies" ID="ID_1024692425" CREATED="1473123809782" MODIFIED="1473123920574">
<attribute NAME="textbook" VALUE="02-16"/>
<node TEXT="It is important that not everyone can change everything" ID="ID_1705017814" CREATED="1473123813423" MODIFIED="1473123824090"/>
<node TEXT="As a group decide who has write access" ID="ID_1595100227" CREATED="1473123824420" MODIFIED="1473123837091"/>
<node TEXT="Use revision management software" ID="ID_141244096" CREATED="1473123887179" MODIFIED="1473123894404"/>
</node>
<node TEXT="Tools" ID="ID_1546042450" CREATED="1473123931335" MODIFIED="1473123935545">
<node TEXT="Several options are available" ID="ID_1243295167" CREATED="1473123937057" MODIFIED="1473123945219"/>
<node TEXT="We will use git and GitHub" ID="ID_783507392" CREATED="1473123945640" MODIFIED="1473123950139"/>
</node>
<node TEXT="Peer Review" ID="ID_1958442897" CREATED="1473123955042" MODIFIED="1473123958157">
<node TEXT="Perhaps the most important guardian of quality is the peer review process" ID="ID_731763301" CREATED="1473123959075" MODIFIED="1473123980178"/>
<node TEXT="Applies to code as well as documenation" ID="ID_415143553" CREATED="1473123980400" MODIFIED="1473123990353"/>
<node TEXT="Don&apos;t let formatting cloud discussion - use a tool like clang-format" ID="ID_178449273" CREATED="1473123990905" MODIFIED="1473124025294"/>
</node>
</node>
</node>
<node TEXT="Schedule" POSITION="right" ID="ID_76226198" CREATED="1471654669378" MODIFIED="1471654672361">
<edge COLOR="#0000ff"/>
<node TEXT="Charts" ID="ID_292559708" CREATED="1473124076807" MODIFIED="1473124082308">
<node TEXT="PERT" ID="ID_221406331" CREATED="1473124082853" MODIFIED="1473124619958">
<attribute NAME="textbook" VALUE="03-33"/>
<node TEXT="Activity on Node (AoN) charts:" ID="ID_460667615" CREATED="1473124089405" MODIFIED="1473124109286">
<node TEXT="Nodes represent activities with names and durations" ID="ID_133179473" CREATED="1473124110721" MODIFIED="1473124124239"/>
<node TEXT="Arrows represent dependence relations" ID="ID_764842838" CREATED="1473124124977" MODIFIED="1473124136665"/>
</node>
<node TEXT="Activity on Arrow (AoA) charts also exist" ID="ID_1712180409" CREATED="1473124248529" MODIFIED="1473124261903">
<node TEXT="Nodes are specific states of the project" ID="ID_139235501" CREATED="1473124506165" MODIFIED="1473124516844"/>
<node TEXT="Arrows represent activities to get to states" ID="ID_1272624835" CREATED="1473124517090" MODIFIED="1473124531633"/>
</node>
</node>
<node TEXT="Gantt" ID="ID_684938125" CREATED="1473124220439" MODIFIED="1473124595289">
<attribute NAME="textbook" VALUE="03-41"/>
<node TEXT="Similar information to PERT charts" ID="ID_1331715239" CREATED="1473124228771" MODIFIED="1473124243567"/>
<node TEXT="Duration is expressed with length of task bar" ID="ID_1680287347" CREATED="1473124537259" MODIFIED="1473124549216"/>
</node>
</node>
<node TEXT="Estimation" ID="ID_1639030715" CREATED="1473124560538" MODIFIED="1473124563650">
<node TEXT="Three Point Estimation" ID="ID_1945510940" CREATED="1473124645411" MODIFIED="1473124651222">
<node TEXT="For every task you should estimate 3 times" ID="ID_8518163" CREATED="1473124655190" MODIFIED="1473124665786"/>
<node TEXT="Most Likely" ID="ID_1440586420" CREATED="1473124666183" MODIFIED="1473124671088"/>
<node TEXT="Optimistic" ID="ID_1434218284" CREATED="1473124671365" MODIFIED="1473124674929"/>
<node TEXT="Pessimistic" ID="ID_22910909" CREATED="1473124675286" MODIFIED="1473124678884"/>
</node>
<node TEXT="Critical Paths" ID="ID_1399875678" CREATED="1473124630710" MODIFIED="1473124845981">
<attribute NAME="textbook" VALUE="03-38"/>
<node TEXT="A critical path is a longest path through the necessary activities" ID="ID_106858907" CREATED="1473124708457" MODIFIED="1473124734170"/>
<node TEXT="Critical paths are not unique, in complex projects there can be multiple" ID="ID_408671583" CREATED="1473124734619" MODIFIED="1473124749670"/>
<node TEXT="Critical paths can change" ID="ID_98449912" CREATED="1473124749964" MODIFIED="1473124759760">
<node TEXT="If enough tasks take their pessimistic times a path can become critical" ID="ID_165183275" CREATED="1473124760110" MODIFIED="1473124776277"/>
</node>
<node TEXT="The critical path length is the shortest amount of time in which a project can complete." ID="ID_537747946" CREATED="1473124777173" MODIFIED="1473124810899"/>
<node TEXT="If there are insufficient resources it can take longer" ID="ID_524906310" CREATED="1473124811252" MODIFIED="1473124820810"/>
</node>
<node TEXT="Improving Estimates" ID="ID_1155622905" CREATED="1473124856459" MODIFIED="1473125083551">
<attribute NAME="textbook" VALUE="03-42"/>
<node TEXT="Have experience with similar tasks" ID="ID_1571790039" CREATED="1473124901277" MODIFIED="1473124910807">
<node TEXT="The more similar the better the result" ID="ID_210207430" CREATED="1473124934635" MODIFIED="1473124954934"/>
</node>
<node TEXT="Break tasks into smaller tasks" ID="ID_838105468" CREATED="1473124911171" MODIFIED="1473124980383">
<node TEXT="If you think it will take more than a day, you should probably break it up more" ID="ID_1995302436" CREATED="1473124981048" MODIFIED="1473124997006"/>
</node>
<node TEXT="Expect to be wrong" ID="ID_1348550291" CREATED="1473125008003" MODIFIED="1473125019053">
<node TEXT="This is what the pessimistic time is for" ID="ID_1734005274" CREATED="1473125020644" MODIFIED="1473125027773"/>
</node>
<node TEXT="Track progress" ID="ID_1002062164" CREATED="1473125029468" MODIFIED="1473125034980">
<node TEXT="The closer you are to doing a task the easier it is to estimate" ID="ID_731561494" CREATED="1473125035583" MODIFIED="1473125047659"/>
<node TEXT="Keep estimates and plans up to date" ID="ID_123158163" CREATED="1473125047919" MODIFIED="1473125057508"/>
</node>
</node>
</node>
<node TEXT="Risk" ID="ID_1542000243" CREATED="1473125114421" MODIFIED="1473125124876">
<node TEXT="Risk Management" ID="ID_1400930737" CREATED="1473125128059" MODIFIED="1473125828480">
<attribute NAME="textbook" VALUE="03-47"/>
<node TEXT="Be proactive concerning problems" ID="ID_257643830" CREATED="1473125647949" MODIFIED="1473125665040"/>
<node TEXT="This is not trying to predict why a task fails, only to plan what to do if it does" ID="ID_1902005264" CREATED="1473125786455" MODIFIED="1473125804691">
<node TEXT="No crystal ball needed" ID="ID_705601470" CREATED="1473125835389" MODIFIED="1473125841493"/>
</node>
</node>
<node TEXT="Per Task Risk Attributes" ID="ID_1707516533" CREATED="1473125687762" MODIFIED="1473126216705">
<node TEXT="Likelyhood - What is the probability that the task does not go well" ID="ID_1412009752" CREATED="1473125716228" MODIFIED="1473126216705"/>
<node TEXT="Severity - How bad is it if the task is not completed" ID="ID_1024139863" CREATED="1473125735770" MODIFIED="1473125748695"/>
<node TEXT="Consequences - What other tasks are affected" ID="ID_1729510555" CREATED="1473125751890" MODIFIED="1473125762782"/>
<node TEXT="Mitigation - What can you do if you can not do the planned task" ID="ID_570486364" CREATED="1473125763048" MODIFIED="1473125776901"/>
</node>
</node>
</node>
<node TEXT="Requirements" POSITION="right" ID="ID_589820547" CREATED="1471654672945" MODIFIED="1471654676559">
<edge COLOR="#00ff00"/>
<node TEXT="Traits" ID="ID_937228285" CREATED="1473125968971" MODIFIED="1473125977273">
<node TEXT="Clear and Unambiguous" ID="ID_144003904" CREATED="1473125908054" MODIFIED="1473125922648">
<node TEXT="The purpose of requierments is to help build the right project" ID="ID_846581344" CREATED="1473125922652" MODIFIED="1473125937451"/>
<node TEXT="They should be measurable if possible" ID="ID_1490350053" CREATED="1473126069006" MODIFIED="1473126077439"/>
</node>
<node TEXT="Consistent" ID="ID_172533025" CREATED="1473125938910" MODIFIED="1473125956506">
<node TEXT="If your requirements conflict you are \emph{overconstrained}" ID="ID_1148543457" CREATED="1473125956510" MODIFIED="1473126009480"/>
<node TEXT="Harder to maintain in larger projects and over time" ID="ID_772163904" CREATED="1473126048989" MODIFIED="1473126060190"/>
</node>
<node TEXT="Prioritized" ID="ID_317559241" CREATED="1473126062641" MODIFIED="1473126226824">
<attribute NAME="textbook" VALUE="04-56"/>
<node TEXT="You can&apos;t have everything" ID="ID_1073749866" CREATED="1473126079822" MODIFIED="1473126108585"/>
<node TEXT="MOSCOW" ID="ID_1524664543" CREATED="1473126109804" MODIFIED="1473126116676">
<node TEXT="Must - project fails without" ID="ID_1765065453" CREATED="1473126116680" MODIFIED="1473126142944"/>
<node TEXT="Should - important, but workarounds exist" ID="ID_1600815467" CREATED="1473126118602" MODIFIED="1473126163984"/>
<node TEXT="Could - desirable but probably won&apos;t make it, maybe version 3" ID="ID_643293818" CREATED="1473126120353" MODIFIED="1473126191750"/>
<node TEXT="Wont - will never be included" ID="ID_1239126556" CREATED="1473126121993" MODIFIED="1473126202692"/>
</node>
</node>
<node TEXT="Verifiable" ID="ID_1598272743" CREATED="1473126266581" MODIFIED="1473126273391">
<node TEXT="How do you know that a requirement is met?" ID="ID_411667705" CREATED="1473126273395" MODIFIED="1473126282271"/>
<node TEXT="Avoid" ID="ID_1234077394" CREATED="1473126282892" MODIFIED="1473126284836">
<node TEXT="Comparatives" ID="ID_1299970669" CREATED="1473126284840" MODIFIED="1473126288472"/>
<node TEXT="Imprecise adjectives - i.e. user friendly" ID="ID_378941024" CREATED="1473126288736" MODIFIED="1473126307986"/>
<node TEXT="Commands - i.e. improve feature x" ID="ID_1370997639" CREATED="1473126313784" MODIFIED="1473126326106"/>
</node>
</node>
</node>
<node TEXT="Categories" ID="ID_853849532" CREATED="1473126357004" MODIFIED="1473126362105">
<node TEXT="FURPS" ID="ID_1752154660" CREATED="1473126362592" MODIFIED="1473126469041">
<attribute NAME="textbook" VALUE="04-64"/>
<node TEXT="Functionality" ID="ID_574358244" CREATED="1473126367884" MODIFIED="1473126379919"/>
<node TEXT="Usability" ID="ID_1828181401" CREATED="1473126380132" MODIFIED="1473126383348"/>
<node TEXT="Reliability" ID="ID_498116572" CREATED="1473126383535" MODIFIED="1473126387150"/>
<node TEXT="Performance" ID="ID_1655331854" CREATED="1473126387411" MODIFIED="1473126389703"/>
<node TEXT="Supportability" ID="ID_1825162439" CREATED="1473126389912" MODIFIED="1473126395506"/>
</node>
<node TEXT="FURPS+" ID="ID_1408204926" CREATED="1473126399619" MODIFIED="1473126402112">
<node TEXT="Design Constraints" ID="ID_358192038" CREATED="1473126403902" MODIFIED="1473126425038"/>
<node TEXT="Implementation" ID="ID_1867737890" CREATED="1473126425453" MODIFIED="1473126429895">
<node TEXT="Temporary requirements to transition to new product" ID="ID_1245749684" CREATED="1473126442373" MODIFIED="1473126450976"/>
</node>
<node TEXT="Interface" ID="ID_1439708275" CREATED="1473126430128" MODIFIED="1473126433965"/>
<node TEXT="Physical" ID="ID_1545881151" CREATED="1473126434203" MODIFIED="1473126437454"/>
</node>
</node>
<node TEXT="Gathering" ID="ID_1641044665" CREATED="1473126501964" MODIFIED="1473126506068">
<node TEXT="Listen to Customers and Users" ID="ID_922531077" CREATED="1473126506073" MODIFIED="1473126677947">
<attribute NAME="textbook" VALUE="04-67"/>
<node TEXT="Ask 5 W&apos;s and an H" ID="ID_1126920089" CREATED="1473126514693" MODIFIED="1473126522668"/>
<node TEXT="Study Users as they perform task" ID="ID_1932941497" CREATED="1473126527739" MODIFIED="1473126537103"/>
</node>
<node TEXT="Previous Experience" ID="ID_1910254807" CREATED="1473126595214" MODIFIED="1473126612507">
<node TEXT="Copy existing requirements" ID="ID_896746077" CREATED="1473126612510" MODIFIED="1473126622773"/>
<node TEXT="Experience can suggest requirements" ID="ID_797158376" CREATED="1473126623262" MODIFIED="1473126647758"/>
</node>
</node>
<node TEXT="Recording" ID="ID_649799576" CREATED="1473126710409" MODIFIED="1473126715852">
<node TEXT="User Stories" ID="ID_364623527" CREATED="1473126715855" MODIFIED="1473126904619">
<attribute NAME="textbook" VALUE="04-77"/>
<node TEXT="A easy way to record requirements is a user story" ID="ID_1615702249" CREATED="1473126720154" MODIFIED="1473126734678"/>
<node TEXT="A short paragraph describing an interaction" ID="ID_1557270639" CREATED="1473126734946" MODIFIED="1473126744152"/>
<node TEXT="Use Cases can be derived from stories and requirements from the cases" ID="ID_1889445833" CREATED="1473126746561" MODIFIED="1473126776660"/>
</node>
<node TEXT="Use Cases" ID="ID_1963564677" CREATED="1473126777667" MODIFIED="1473126782547">
<node TEXT="A description of a specific interaction between actors" ID="ID_473375898" CREATED="1473126783352" MODIFIED="1473126793665"/>
<node TEXT="Needs a name, success scenario" ID="ID_1768738544" CREATED="1473126793936" MODIFIED="1473126812533"/>
<node TEXT="May have extensions or variations.  The failure scenario is a common one." ID="ID_1921141396" CREATED="1473126812877" MODIFIED="1473126837192"/>
</node>
<node TEXT="UML Use Case Diagrams" ID="ID_1005905371" CREATED="1473126839669" MODIFIED="1473126844627"/>
</node>
</node>
</node>
</map>
