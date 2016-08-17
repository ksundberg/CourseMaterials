<map version="freeplane 1.2.0">
<!--To view this file, download free mind mapping software Freeplane from http://freeplane.sourceforge.net -->
<node TEXT="Linear Data Structures" ID="ID_555524160" CREATED="1298332092587" MODIFIED="1298332644601">
<attribute NAME="author" VALUE="Kenneth Sundberg"/>
<attribute NAME="date" VALUE=""/>
<attribute NAME="subtitle" VALUE="CS 1410 -- Chapters 17 and 18"/>
<hook NAME="MapStyle">
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
<node TEXT="Stacks" POSITION="right" ID="ID_410567184" CREATED="1298332254503" MODIFIED="1298332267030">
<node TEXT="Operations" ID="ID_948391507" CREATED="1298332325089" MODIFIED="1298332336335">
<node TEXT="LIFO" ID="ID_151609244" CREATED="1298333368985" MODIFIED="1447102074777">
<attribute NAME="textbook" VALUE="18-01"/>
<node TEXT="Last In -- First Out" ID="ID_1848198062" CREATED="1298333381513" MODIFIED="1298333396943"/>
<node TEXT="Only add and remove from the head of the list" ID="ID_764683013" CREATED="1298333402239" MODIFIED="1298333410589"/>
</node>
<node TEXT="Push" ID="ID_209511576" CREATED="1298333351401" MODIFIED="1298333353848">
<node TEXT="Add an item to the head of the list" ID="ID_1089370497" CREATED="1298333429354" MODIFIED="1298333436890"/>
</node>
<node TEXT="Pop" ID="ID_1196577268" CREATED="1298333354265" MODIFIED="1298333356129">
<node TEXT="Remove an item from the head of the list" ID="ID_777197017" CREATED="1298333437842" MODIFIED="1298333443739"/>
</node>
</node>
<node TEXT="Uses" ID="ID_554993897" CREATED="1298333545489" MODIFIED="1298333547169">
<node TEXT="Uses" ID="ID_532876446" CREATED="1298332339665" MODIFIED="1298332343495">
<node TEXT="Recursion" ID="ID_838142332" CREATED="1298333462579" MODIFIED="1298333472763">
<node TEXT="Stack is key data structure used in function calls" ID="ID_767430215" CREATED="1298333498891" MODIFIED="1298333511500"/>
<node TEXT="Push down automata" ID="ID_2492169" CREATED="1298333581106" MODIFIED="1298333586826"/>
</node>
<node TEXT="Parsing" ID="ID_117032094" CREATED="1298333558577" MODIFIED="1298333560718">
<node TEXT="Context Free Grammers" ID="ID_482710702" CREATED="1298333560719" MODIFIED="1298333953845"/>
<node TEXT="Post-fix Notation" ID="ID_290451334" CREATED="1298333472971" MODIFIED="1298333497947"/>
</node>
</node>
</node>
</node>
<node TEXT="Queues" POSITION="right" ID="ID_1764922108" CREATED="1298332267223" MODIFIED="1298332269190">
<node TEXT="Operations" ID="ID_628421687" CREATED="1298332358497" MODIFIED="1298332361008">
<node TEXT="FIFO" ID="ID_1419531060" CREATED="1298332283048" MODIFIED="1447102128163">
<attribute NAME="textbook" VALUE="18-04"/>
<node TEXT="First In -- First Out" ID="ID_1787410945" CREATED="1298333616966" MODIFIED="1298333621638"/>
<node TEXT="Only remove from the head" ID="ID_1630432994" CREATED="1298333621830" MODIFIED="1298333627239"/>
<node TEXT="Only add to the tail" ID="ID_1876626092" CREATED="1298333627446" MODIFIED="1298333631654"/>
</node>
<node TEXT="Enqueue" ID="ID_1410183472" CREATED="1298333634006" MODIFIED="1298333637887">
<node TEXT="Add an item to the tail" ID="ID_1593404596" CREATED="1298333637888" MODIFIED="1298333641655"/>
<node TEXT="Queue class keeps track of the tail" ID="ID_347558039" CREATED="1298333641854" MODIFIED="1298333652231"/>
</node>
<node TEXT="Dequeue" ID="ID_977488656" CREATED="1298333653071" MODIFIED="1298333660151">
<node TEXT="Remove an item from the head" ID="ID_17368801" CREATED="1298333660775" MODIFIED="1298333666334"/>
</node>
</node>
<node TEXT="Implementation" ID="ID_888070464" CREATED="1298332361201" MODIFIED="1298332364156">
<node TEXT="Linked List" ID="ID_898931840" CREATED="1298332367393" MODIFIED="1298333670319">
<node TEXT="Keep track of head and tail pointers" ID="ID_1668841904" CREATED="1298333673431" MODIFIED="1298333683398"/>
<node TEXT="Easy to write Enqueue and Dequeue" ID="ID_1969448259" CREATED="1298333683607" MODIFIED="1298333693624"/>
</node>
<node TEXT="Circular Queue" ID="ID_1239842094" CREATED="1298332364158" MODIFIED="1298332367208">
<node TEXT="Use and array instead of a linked list" ID="ID_890092147" CREATED="1298333694679" MODIFIED="1298333704104"/>
<node TEXT="Keep track of head and tail indices" ID="ID_1600404352" CREATED="1298333704312" MODIFIED="1298333986145"/>
<node TEXT="Wrap around in circular fashion" ID="ID_109390514" CREATED="1298333713056" MODIFIED="1298333725993"/>
<node TEXT="Finite, predetermined memory usage" ID="ID_1148212770" CREATED="1298333726184" MODIFIED="1298333744881"/>
</node>
</node>
<node TEXT="Uses" ID="ID_1685400365" CREATED="1298332371434" MODIFIED="1298332373072">
<node TEXT="Uses" ID="ID_1446104969" CREATED="1298333754521" MODIFIED="1298333757846">
<node TEXT="Network Communications" ID="ID_1935589662" CREATED="1298333757847" MODIFIED="1298333778582"/>
<node TEXT="Scheduling" ID="ID_1463774803" CREATED="1298333794265" MODIFIED="1298333800642">
<node TEXT="Keeping track of requests" ID="ID_478932382" CREATED="1298333778793" MODIFIED="1298333794050"/>
</node>
<node TEXT="Breadth First Tree Traversal" ID="ID_439169221" CREATED="1298333803498" MODIFIED="1298333828711">
<node TEXT="More on this later" ID="ID_1827958388" CREATED="1298333828713" MODIFIED="1298333842899"/>
</node>
</node>
</node>
</node>
<node TEXT="Exceptions" POSITION="right" ID="ID_1603587119" CREATED="1447101583690" MODIFIED="1447101590283">
<node TEXT="Throwing Exceptions" ID="ID_316695883" CREATED="1447101597961" MODIFIED="1447101617794">
<node TEXT="When things go wrong" ID="ID_113192952" CREATED="1447101678442" MODIFIED="1447102041906">
<attribute NAME="textbook" VALUE="16-01"/>
<node TEXT="What happens if you try to pop an empty stack?" ID="ID_1520508879" CREATED="1447101617800" MODIFIED="1447101638207"/>
<node TEXT="What happens if you try to dequeue an empty queue?" ID="ID_1315752050" CREATED="1447101638505" MODIFIED="1447101647583"/>
<node TEXT="A reasonable choice is to throw an exception" ID="ID_1355228790" CREATED="1447101647946" MODIFIED="1447101657447"/>
</node>
<node TEXT="Exception Behavior" ID="ID_796532219" CREATED="1447101693049" MODIFIED="1447101699266">
<node TEXT="After an exception is thrown the program begins looking for a catch statement" ID="ID_77383109" CREATED="1447101699269" MODIFIED="1447101733415"/>
<node TEXT="It starts in the current scope if no catch is found it looks in the parent scope" ID="ID_546152138" CREATED="1447101733857" MODIFIED="1447101757123"/>
<node TEXT="As exceptions leave a scope they still invoke destructors and other cleanup" ID="ID_601474676" CREATED="1447101757537" MODIFIED="1447101772401"/>
<node TEXT="If no catch is found in the program, the program terminates" ID="ID_177614869" CREATED="1447101773529" MODIFIED="1447101787479"/>
</node>
</node>
<node TEXT="Garuntees" ID="ID_326350949" CREATED="1447101821905" MODIFIED="1447101826922">
<node TEXT="No Throw" ID="ID_1584101482" CREATED="1447101826926" MODIFIED="1447101831843">
<node TEXT="The strongest garuntee a function can offer with respect to exceptions." ID="ID_441737033" CREATED="1447101831849" MODIFIED="1447101853807"/>
<node TEXT="A no throw function will never throw an exception under any circumstances" ID="ID_753201179" CREATED="1447101854234" MODIFIED="1447101868423"/>
<node TEXT="Destructors must be no throw" ID="ID_1141681423" CREATED="1447101871538" MODIFIED="1447101886760"/>
</node>
<node TEXT="The Strong Garuntee" ID="ID_1391884496" CREATED="1447101888065" MODIFIED="1447101896466">
<node TEXT="A strong garuntee says that if the function throws an exception then the function has no other side effect." ID="ID_1545117461" CREATED="1447101896471" MODIFIED="1447101930375"/>
<node TEXT="The function either succeeds completly or makes no changes." ID="ID_1206668463" CREATED="1447101930625" MODIFIED="1447101944311"/>
<node TEXT="This is the best option" ID="ID_1597440956" CREATED="1447101944561" MODIFIED="1447101949007"/>
</node>
<node TEXT="The Weak Garuntee" ID="ID_539972758" CREATED="1447101949969" MODIFIED="1447101955575">
<node TEXT="The week garuntee says that if the function throws all objects it has operated on still maintain their invariants." ID="ID_1214323347" CREATED="1447101956377" MODIFIED="1447101980888"/>
<node TEXT="Sometimes this is needed for efficiency of implementation but it should be avoided in favor of the Strong garuntee if possible." ID="ID_1933299316" CREATED="1447101981602" MODIFIED="1447102006791"/>
</node>
</node>
</node>
</node>
</map>
