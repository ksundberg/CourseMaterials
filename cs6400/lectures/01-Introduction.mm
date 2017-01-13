<map version="freeplane 1.3.0">
<!--To view this file, download free mind mapping software Freeplane from http://freeplane.sourceforge.net -->
<node TEXT="Introduction" ID="ID_1723255651" CREATED="1283093380553" MODIFIED="1484347803202"><hook NAME="MapStyle">
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
<hook NAME="AutomaticEdgeColor" COUNTER="2"/>
<attribute NAME="author" VALUE="Kenneth Sundberg"/>
<attribute NAME="date" VALUE=""/>
<attribute NAME="subtitle" VALUE="CS 6400"/>
<node TEXT="Sylabus" POSITION="right" ID="ID_1893758557" CREATED="1388724830529" MODIFIED="1483743557752">
<edge COLOR="#ff0000"/>
<node TEXT="Topic" ID="ID_1859463312" CREATED="1388724860429" MODIFIED="1388724875730">
<node TEXT="Textbook" ID="ID_343747052" CREATED="1388724909739" MODIFIED="1388724912876">
<node TEXT="The text for the course is &quot;Physically Based Rendering&quot; by Pharr,Jakob, and Humphreys" ID="ID_1144774546" CREATED="1388724912881" MODIFIED="1483743631663"/>
<node TEXT="Third Edition" ID="ID_898662885" CREATED="1388881678527" MODIFIED="1483743599022"/>
</node>
<node TEXT="Literate Programming" ID="ID_298266981" CREATED="1483743691833" MODIFIED="1483743732609">
<attribute NAME="textbook" VALUE="01-01"/>
<node TEXT="Text is annotated source code for a fully functional ray tracer called pbrt" ID="ID_1731531756" CREATED="1483743752386" MODIFIED="1483743909334"/>
<node TEXT="You are responsible for all algorithms covered, even if we don&apos;t do an assignment on them" ID="ID_557394204" CREATED="1483743780705" MODIFIED="1483743798702"/>
<node TEXT="We will be modifying and extending existing code." ID="ID_323138638" CREATED="1483743801217" MODIFIED="1483743891422"/>
<node TEXT="Be sure to read and understand all code covered so far" ID="ID_383252150" CREATED="1484347621585" MODIFIED="1484347642908"/>
</node>
</node>
<node TEXT="Grading" ID="ID_1678855989" CREATED="1388724876309" MODIFIED="1388724885234">
<node TEXT="Grade Break Down" ID="ID_230602766" CREATED="1388724969018" MODIFIED="1388724978290">
<node TEXT="Programming Assignments - 60\%" ID="ID_1814846665" CREATED="1388724978294" MODIFIED="1388733545146"/>
<node TEXT="Final Project - 20\%" ID="ID_1433111007" CREATED="1483743642153" MODIFIED="1483743651590"/>
<node TEXT="Exams - 20\%" ID="ID_337805349" CREATED="1388724988985" MODIFIED="1483743641022"/>
</node>
<node TEXT="Late Policy" ID="ID_1889739863" CREATED="1388725028975" MODIFIED="1388725041760">
<node TEXT="10 \% per day late" ID="ID_299689484" CREATED="1388725041764" MODIFIED="1388733682881"/>
<node TEXT="No work accepted after 3 days" ID="ID_624640154" CREATED="1388725048623" MODIFIED="1388725055068"/>
<node TEXT="No exceptions - even if life happens" ID="ID_1219399267" CREATED="1388725055383" MODIFIED="1388725069035"/>
</node>
<node TEXT="Rendering Times" ID="ID_1908371286" CREATED="1483743869185" MODIFIED="1483744285929">
<node TEXT="Many assignments will require a rendered image" ID="ID_363970132" CREATED="1483744229058" MODIFIED="1483744239382"/>
<node TEXT="Rendering takes time (minutes to hours) be sure to leave enough time" ID="ID_45438291" CREATED="1483744239722" MODIFIED="1483744258927"/>
<node TEXT="pbrt does give an estimate of how long the process will take." ID="ID_581374318" CREATED="1483744259289" MODIFIED="1483744276318"/>
<node TEXT="pbrt also gives  a profile of how long was spent on various phases afterwards - this will be important for assignments that are about speeding up code" ID="ID_1686169812" CREATED="1483744294811" MODIFIED="1483744330924"/>
</node>
</node>
<node TEXT="Policies" ID="ID_805744572" CREATED="1388724886277" MODIFIED="1388724899857">
<node TEXT="ADA" ID="ID_1235370219" CREATED="1388725072150" MODIFIED="1388725075734">
<node TEXT="This course is ADA compliant as required" ID="ID_575281479" CREATED="1388725075739" MODIFIED="1388725084907"/>
<node TEXT="Discuss with the DRC for arrangments" ID="ID_963702389" CREATED="1388725085750" MODIFIED="1388725094155"/>
</node>
</node>
</node>
<node TEXT="Ray Tracing" POSITION="right" ID="ID_716653918" CREATED="1483743818745" MODIFIED="1483743827186">
<edge COLOR="#0000ff"/>
<node TEXT="Algorithm" ID="ID_110543559" CREATED="1483743827188" MODIFIED="1483743841014">
<node TEXT="Ray Tracing Algorithm" ID="ID_278529536" CREATED="1483744373594" MODIFIED="1483744406160">
<attribute NAME="textbook" VALUE="01-02"/>
</node>
<node TEXT="Physically Based Rendering" ID="ID_844540906" CREATED="1483744478674" MODIFIED="1483744487394">
<node TEXT="Trying to faithfully simulate light-scene interactions" ID="ID_736320384" CREATED="1483744487397" MODIFIED="1483744502375"/>
<node TEXT="Correctness could in theory be measured with a physical camera" ID="ID_240284789" CREATED="1483744502762" MODIFIED="1483744517735"/>
<node TEXT="Optimizations should not change values" ID="ID_691703606" CREATED="1483744529578" MODIFIED="1483744535494"/>
</node>
<node TEXT="Cameras" ID="ID_378350316" CREATED="1483744565722" MODIFIED="1483744570975">
<node TEXT="Simplest version is the pinhole camera" ID="ID_457117033" CREATED="1483744865090" MODIFIED="1483744878959"/>
<node TEXT="Defines what portion of a scenes energy is captured on film" ID="ID_1848746666" CREATED="1483744879362" MODIFIED="1483744906867"/>
</node>
<node TEXT="Ray-Object Intersection" ID="ID_1444996644" CREATED="1483744571330" MODIFIED="1483744577919">
<node TEXT="Given a ray $r(t) = o + td$" ID="ID_1016482044" CREATED="1483744925034" MODIFIED="1483744949017"/>
<node TEXT="Find what object in a scene is the first to be hit" ID="ID_335652213" CREATED="1483744949596" MODIFIED="1483744964529"/>
<node TEXT="Once the intersection is found various values are needed" ID="ID_348750914" CREATED="1483744977827" MODIFIED="1483744998439">
<node TEXT="Surface normal" ID="ID_1334928035" CREATED="1483745007271" MODIFIED="1483745011446"/>
<node TEXT="Material" ID="ID_1515199917" CREATED="1483745011922" MODIFIED="1483745020174"/>
<node TEXT="Texture coordinates" ID="ID_895142826" CREATED="1483745020578" MODIFIED="1483745027743"/>
<node TEXT="Various partial derivatives" ID="ID_1258516385" CREATED="1483745028106" MODIFIED="1483745040598"/>
</node>
</node>
<node TEXT="Lights" ID="ID_1231607575" CREATED="1483745044274" MODIFIED="1483745047994">
<node TEXT="Energy sources in scene" ID="ID_1515190394" CREATED="1483745047995" MODIFIED="1483745055926"/>
<node TEXT="Light sources have power $\Phi$" ID="ID_445833719" CREATED="1483745056386" MODIFIED="1483745162511"/>
<node TEXT="We usually care about differential irradiance" ID="ID_1270977360" CREATED="1483745162930" MODIFIED="1483745199807"/>
<node TEXT="$dE = \frac{\Phi \cos \theta}{4 \pi r^2}$" ID="ID_1324489494" CREATED="1483745200250" MODIFIED="1484342779554"/>
<node TEXT="Illumination is \emph{linear}" ID="ID_945033342" CREATED="1483745421053" MODIFIED="1483745432071"/>
</node>
<node TEXT="Visibility" ID="ID_1964562904" CREATED="1483745440011" MODIFIED="1483745444867">
<node TEXT="Illumination needs to consider occlusions" ID="ID_1379393262" CREATED="1483745444869" MODIFIED="1483745466079"/>
<node TEXT="Shadows are readily computed via ray-object intersections" ID="ID_1702818182" CREATED="1483745466675" MODIFIED="1483745507447"/>
</node>
<node TEXT="Surface Scattering" ID="ID_1386924588" CREATED="1483745509179" MODIFIED="1483745521651">
<node TEXT="Light interacts with surfaces in a variety of ways" ID="ID_1967244710" CREATED="1483745521654" MODIFIED="1483745718216"/>
<node TEXT="This is described by the \emph{bidirectional reflectance distribution function} or BRDF" ID="ID_136114947" CREATED="1483745718819" MODIFIED="1483745770152"/>
<node TEXT="There are a variety of ways to model this function" ID="ID_1509044617" CREATED="1483745775699" MODIFIED="1483745791855"/>
</node>
<node TEXT="Indirect Light Transport" ID="ID_867749925" CREATED="1483745793859" MODIFIED="1483745814059">
<node TEXT="Dielectric and Specular materials can be modeled using recursion" ID="ID_687266074" CREATED="1483745814062" MODIFIED="1483745861624"/>
</node>
<node TEXT="Participating Media" ID="ID_275039173" CREATED="1483745867283" MODIFIED="1483745872371">
<node TEXT="If light is not traveling through a vacuum the medium can affect it" ID="ID_1627901273" CREATED="1483745872373" MODIFIED="1483745928416"/>
<node TEXT="Light can attenuate (i.e. fog)" ID="ID_1476950832" CREATED="1483745928691" MODIFIED="1483745967288"/>
<node TEXT="Light can be added (i.e. flame)" ID="ID_1575758734" CREATED="1483745941418" MODIFIED="1483745959232"/>
</node>
</node>
<node TEXT="pbrt Overview" ID="ID_787065034" CREATED="1483743841417" MODIFIED="1483743847006">
<node TEXT="Main Abstractions" ID="ID_905192406" CREATED="1484342171515" MODIFIED="1484342248506">
<attribute NAME="textbook" VALUE="01-03"/>
<node TEXT="Shape" ID="ID_1637950983" CREATED="1484342187519" MODIFIED="1484342190451"/>
<node TEXT="Aggregate" ID="ID_1205002066" CREATED="1484342190881" MODIFIED="1484342194729"/>
<node TEXT="Camera" ID="ID_1447547931" CREATED="1484342195008" MODIFIED="1484342196383"/>
<node TEXT="Sampler" ID="ID_768899596" CREATED="1484342196616" MODIFIED="1484342198975"/>
<node TEXT="Filter" ID="ID_1810180086" CREATED="1484342199229" MODIFIED="1484342202233"/>
<node TEXT="Material" ID="ID_530799852" CREATED="1484342202499" MODIFIED="1484342205414"/>
<node TEXT="Texture" ID="ID_1801663009" CREATED="1484342205635" MODIFIED="1484342208417"/>
<node TEXT="Medium" ID="ID_874652134" CREATED="1484342208677" MODIFIED="1484342211752"/>
<node TEXT="Light" ID="ID_1266624244" CREATED="1484342212002" MODIFIED="1484342214683"/>
<node TEXT="Integrator" ID="ID_866816480" CREATED="1484342214938" MODIFIED="1484342218506"/>
</node>
<node TEXT="Thread Safety" ID="ID_1839013838" CREATED="1484342294627" MODIFIED="1484342308301">
<node TEXT="pbrt is multi-threaded" ID="ID_1559624168" CREATED="1484342309721" MODIFIED="1484342315912"/>
<node TEXT="Be sure when modifying to not introduce a data race" ID="ID_646390968" CREATED="1484342316353" MODIFIED="1484342401068"/>
<node TEXT="Most objects are read only to avoid this problem" ID="ID_1902807238" CREATED="1484342412907" MODIFIED="1484342442540"/>
</node>
</node>
</node>
</node>
</map>
