<map version="freeplane 1.3.0">
<!--To view this file, download free mind mapping software Freeplane from http://freeplane.sourceforge.net -->
<node TEXT="Threads" ID="ID_1224319479" CREATED="1389467818499" MODIFIED="1389506560738"><hook NAME="MapStyle">
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
<attribute NAME="author" VALUE="Kenneth Sundberg"/>
<attribute NAME="date" VALUE=""/>
<attribute NAME="subtitle" VALUE="CS 3100"/>
<node TEXT="Threads" POSITION="right" ID="ID_1949375327" CREATED="1389469355263" MODIFIED="1389469358300">
<node TEXT="Overview" ID="ID_761969273" CREATED="1389469366783" MODIFIED="1389469369748">
<node TEXT="Thread of Execution" ID="ID_1683046347" CREATED="1389483155829" MODIFIED="1389483162218">
<node TEXT="A stream of instructions executed in a sequentially consistent manner" ID="ID_362410487" CREATED="1389484663543" MODIFIED="1389484683172"/>
<node TEXT="A process may have many threads of execution" ID="ID_295811049" CREATED="1389484685679" MODIFIED="1389484696041"/>
<node TEXT="Provides" ID="ID_1786063697" CREATED="1389484735805" MODIFIED="1389484739454">
<node TEXT="Performance" ID="ID_1709588162" CREATED="1389484739458" MODIFIED="1389484742611"/>
<node TEXT="Responsiveness" ID="ID_1676666426" CREATED="1389484742909" MODIFIED="1389488536478"/>
</node>
</node>
<node TEXT="User Threads v. Kernel Threads" ID="ID_688537039" CREATED="1389484700942" MODIFIED="1389488554622">
<node TEXT="Threads can be managed by OS" ID="ID_1574031919" CREATED="1389484709573" MODIFIED="1389484719962"/>
<node TEXT="Threads can be managed by User Library" ID="ID_1677979122" CREATED="1389484720197" MODIFIED="1389484734520"/>
</node>
<node TEXT="Speedup" ID="ID_199821930" CREATED="1388734297463" MODIFIED="1388734302879">
<node TEXT="Compares the wall time of a parallel implementation to the wall time of the \emph{best} sequential implementation" ID="ID_1801922548" CREATED="1388734310982" MODIFIED="1388734344843"/>
<node TEXT="Speedup can not be better than linear" ID="ID_906403794" CREATED="1388734346293" MODIFIED="1388734359685">
<node TEXT="Hardware effects" ID="ID_98987003" CREATED="1388734359690" MODIFIED="1388734368466"/>
<node TEXT="Incorrect sequential implementation" ID="ID_1145666768" CREATED="1388734368732" MODIFIED="1388734377151"/>
<node TEXT="Search artifacts" ID="ID_756238986" CREATED="1388734377476" MODIFIED="1388734380457"/>
</node>
</node>
<node TEXT="Efficiency" ID="ID_1822733371" CREATED="1388732295365" MODIFIED="1388732301398">
<node TEXT="The fraction of time that a processor is usefully employed" ID="ID_1769246004" CREATED="1388732301402" MODIFIED="1388732315930"/>
<node TEXT="Speedup / p" ID="ID_1451298156" CREATED="1388732317133" MODIFIED="1388732324770"/>
</node>
<node TEXT="Amdahl&apos;s Law" ID="ID_728933875" CREATED="1388729137550" MODIFIED="1388729144715">
<node TEXT="Speedup has an asymtotic limit" ID="ID_1043217736" CREATED="1388732354956" MODIFIED="1388732377584"/>
<node TEXT="$S(n) = \frac{1}{(1-P) + \frac{P}{n}}$" ID="ID_865413355" CREATED="1388732460800" MODIFIED="1388732501931"/>
<node TEXT="$ \lim_{n \to \infty} S(n) = \frac{1}{1-P}$" ID="ID_1930737186" CREATED="1388732502814" MODIFIED="1388734779072"/>
</node>
</node>
<node TEXT="Syntax" ID="ID_963265821" CREATED="1389469874164" MODIFIED="1389469879578">
<node TEXT="std::thread" ID="ID_338675411" CREATED="1389469974641" MODIFIED="1473449264802">
<attribute NAME="textbook" VALUE="4.4" OBJECT="org.freeplane.features.format.FormattedNumber|4.4"/>
</node>
</node>
<node TEXT="Race Conditions" ID="ID_593024967" CREATED="1389469880076" MODIFIED="1389469885922">
<node TEXT="Data Race" ID="ID_1432955987" CREATED="1389505643191" MODIFIED="1389505658415">
<node TEXT="When two or more threads of execution access the same memory and at least one of them is a writer there is a data race" ID="ID_1395048375" CREATED="1389505658419" MODIFIED="1389505905698"/>
<node TEXT="Data Races (Race Conditions) are EVIL\texttrademark" ID="ID_275056715" CREATED="1389505905973" MODIFIED="1389506021976"/>
</node>
<node TEXT="const and copy" ID="ID_652604244" CREATED="1389506028633" MODIFIED="1389506107852">
<node TEXT="No race conditions if there are no writers" ID="ID_603807927" CREATED="1389506034793" MODIFIED="1389506083044"/>
<node TEXT="No race conditions if each thread has its own copy" ID="ID_1209021035" CREATED="1389506071599" MODIFIED="1389506122299"/>
</node>
</node>
<node TEXT="Synchronization" ID="ID_144797526" CREATED="1389469886300" MODIFIED="1389469892689">
<node TEXT="Critical-Section Problem" ID="ID_777547602" CREATED="1389482989244" MODIFIED="1473449287263">
<attribute NAME="textbook" VALUE="5.2" OBJECT="org.freeplane.features.format.FormattedNumber|5.2"/>
<node TEXT="If two or more threads must access the same memory, and one of them must write" ID="ID_1332102238" CREATED="1389506140645" MODIFIED="1389506159698"/>
<node TEXT="Then they must not use the memory at the same time" ID="ID_30874359" CREATED="1389506159996" MODIFIED="1389506169736"/>
<node TEXT="This conflicted access is the a \emph{critical section}" ID="ID_458453913" CREATED="1389506170124" MODIFIED="1389506188329"/>
</node>
<node TEXT="Critical-Section Solutions" ID="ID_1639643981" CREATED="1389506226658" MODIFIED="1389506232794">
<node TEXT="Mutual Exclusion - Only one thread in the section at a time" ID="ID_1458138809" CREATED="1389506232797" MODIFIED="1389506244065"/>
<node TEXT="Progress - Selection of which process can enter a critical section cannot be postponed indefinitely" ID="ID_181535215" CREATED="1389506244305" MODIFIED="1389506324148"/>
<node TEXT="Bounded Waiting - Once a thread has requested to enter the critical section there is a bound on how long it must wait to enter" ID="ID_1466536692" CREATED="1389506324534" MODIFIED="1389506361370"/>
</node>
<node TEXT="Atomic Swap Solution" ID="ID_221771033" CREATED="1389506435443" MODIFIED="1389506448599">
<node TEXT="Given an atomic swap solve the Critical-Section problem" ID="ID_952277199" CREATED="1389506449018" MODIFIED="1389506481446"/>
</node>
<node TEXT="Mutex" ID="ID_75956854" CREATED="1389469959545" MODIFIED="1389506495030">
<node TEXT="std::mutex" ID="ID_1293575007" CREATED="1389506495776" MODIFIED="1389506509637"/>
<node TEXT="std::lock\_guard  -- RAII object for holding a mutex" ID="ID_1201636313" CREATED="1389506510024" MODIFIED="1389506643268"/>
</node>
<node TEXT="Atomics" ID="ID_615699839" CREATED="1389506529095" MODIFIED="1389506533144">
<node TEXT="std::atomic&lt;T&gt;" ID="ID_424235031" CREATED="1389506533148" MODIFIED="1389506541020"/>
</node>
</node>
</node>
</node>
</map>
