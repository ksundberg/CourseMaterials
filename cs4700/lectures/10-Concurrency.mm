<map version="freeplane 1.3.0">
<!--To view this file, download free mind mapping software Freeplane from http://freeplane.sourceforge.net -->
<node TEXT="Concurrency" ID="ID_1723255651" CREATED="1283093380553" MODIFIED="1501546902246"><hook NAME="MapStyle">
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
<node TEXT="Concurrency" POSITION="right" ID="ID_217740431" CREATED="1511888598573" MODIFIED="1511888601690">
<edge COLOR="#007c00"/>
<node TEXT="Intro" ID="ID_1813968889" CREATED="1511890107594" MODIFIED="1511890111132">
<node TEXT="Motivations" ID="ID_134364928" CREATED="1501546902249" MODIFIED="1511888610723">
<attribute NAME="textbook" VALUE="13-01"/>
<node TEXT="Exploit concurrent hardware" ID="ID_576862885" CREATED="1511888373680" MODIFIED="1511888385579">
<node TEXT="Multi-core systems" ID="ID_1102534857" CREATED="1511888385602" MODIFIED="1511888393177"/>
<node TEXT="I/O bound processing" ID="ID_791953633" CREATED="1511888393619" MODIFIED="1511888402323"/>
</node>
<node TEXT="Concurrent design fits some domains very well" ID="ID_285252478" CREATED="1511888403947" MODIFIED="1511888429659"/>
<node TEXT="Distributed Processing" ID="ID_1010203500" CREATED="1511888430055" MODIFIED="1511888436483"/>
</node>
</node>
<node TEXT="Concepts" ID="ID_1738654698" CREATED="1501546987952" MODIFIED="1511890107090">
<node TEXT="Threads and processes" ID="ID_153240299" CREATED="1501547005872" MODIFIED="1511888559225">
<attribute NAME="textbook" VALUE="13-02"/>
<node TEXT="A Thread is a sequence of executed statements" ID="ID_267515744" CREATED="1511888621284" MODIFIED="1511889230680"/>
<node TEXT="A process is a collection of threads" ID="ID_1035802152" CREATED="1511889231558" MODIFIED="1511889240303"/>
</node>
<node TEXT="Synchronization" ID="ID_952469345" CREATED="1501547010912" MODIFIED="1501547017176">
<node TEXT="Co-operative" ID="ID_471626075" CREATED="1501547017178" MODIFIED="1501547022333">
<node TEXT="Producer-Consumer" ID="ID_1146565940" CREATED="1511889259913" MODIFIED="1511889264799"/>
</node>
<node TEXT="Competitive" ID="ID_681752239" CREATED="1501547022648" MODIFIED="1501547024997">
<node TEXT="Resource contention" ID="ID_295164528" CREATED="1511889266373" MODIFIED="1511889272924"/>
</node>
</node>
<node TEXT="Race Conditions" ID="ID_283067735" CREATED="1501547035752" MODIFIED="1501547039021"/>
<node TEXT="Synchronization Quadrants" ID="ID_1953451115" CREATED="1501547060760" MODIFIED="1501547066669"/>
<node TEXT="Liveness and Deadlock" ID="ID_1546352596" CREATED="1501547075552" MODIFIED="1501547081453"/>
</node>
<node TEXT="Techniques" ID="ID_1761631621" CREATED="1511888567267" MODIFIED="1511888604315">
<node TEXT="Semaphores" ID="ID_421164151" CREATED="1501547086752" MODIFIED="1511888580021">
<attribute NAME="textbook" VALUE="13-03"/>
<node TEXT="The Anti-thread" ID="ID_952276761" CREATED="1501547094340" MODIFIED="1501547097781"/>
<node TEXT="Low-level" ID="ID_1428903869" CREATED="1501547136888" MODIFIED="1501547140781"/>
<node TEXT="Considered unsafe" ID="ID_137998276" CREATED="1501547141168" MODIFIED="1501547144437"/>
</node>
<node TEXT="Monitors" ID="ID_1069609971" CREATED="1501547145936" MODIFIED="1511888581788">
<attribute NAME="textbook" VALUE="13-04"/>
<node TEXT="Manditory mutexes" ID="ID_1207325789" CREATED="1501547160320" MODIFIED="1501547178165"/>
<node TEXT="Language inserts locks as needed" ID="ID_523267591" CREATED="1511889349812" MODIFIED="1511889374620"/>
<node TEXT="Generally conservative" ID="ID_1925317837" CREATED="1511889374882" MODIFIED="1511889379783"/>
</node>
<node TEXT="Message Passing" ID="ID_582063919" CREATED="1501547179151" MODIFIED="1511888583643">
<attribute NAME="textbook" VALUE="13-05"/>
<node TEXT="Relies on a thread safe message queue" ID="ID_1880987726" CREATED="1511889383159" MODIFIED="1511889397680"/>
<node TEXT="No shared state outside of queues" ID="ID_1059179737" CREATED="1511889398663" MODIFIED="1511889422933"/>
</node>
<node TEXT="Statement Level Concurrency" ID="ID_436240024" CREATED="1501547285224" MODIFIED="1511888586804">
<attribute NAME="textbook" VALUE="13-10"/>
<node TEXT="Statements that express parallelism" ID="ID_1883803882" CREATED="1511889436705" MODIFIED="1511889489712"/>
<node TEXT="Such statements can be automatically mapped to concurrent forms" ID="ID_178191286" CREATED="1511889490125" MODIFIED="1511889515858"/>
<node TEXT="OpenMP" ID="ID_209950495" CREATED="1511889452080" MODIFIED="1511889459327"/>
</node>
</node>
</node>
</node>
</map>
