<map version="freeplane 1.3.0">
<!--To view this file, download free mind mapping software Freeplane from http://freeplane.sourceforge.net -->
<node TEXT="03 - Basic Graphics Programming" ID="ID_729166855" CREATED="1430766178119" MODIFIED="1473352793478">
<attribute NAME="author" VALUE="Kenneth Sundberg"/>
<attribute NAME="date" VALUE=""/>
<attribute NAME="subtitle" VALUE="CS 5400"/>
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
<node TEXT="GL" POSITION="right" ID="ID_641306979" CREATED="1473352945048" MODIFIED="1473352979099">
<node TEXT="Primitives" ID="ID_1858479050" CREATED="1473352979104" MODIFIED="1473352983436">
<node TEXT=" Geometric Primatives" ID="ID_1089509533" CREATED="1473352983442" MODIFIED="1473353057606">
<node TEXT="Passed through pipeline" ID="ID_922652724" CREATED="1473353063915" MODIFIED="1473353070880"/>
<node TEXT="Consist of points and topology (optional)" ID="ID_1524388770" CREATED="1473353071199" MODIFIED="1473353082889"/>
<node TEXT="Can be manipulated with transformations" ID="ID_275325220" CREATED="1473353083278" MODIFIED="1473353091040"/>
</node>
<node TEXT="Draw Array" ID="ID_1587915476" CREATED="1473353092389" MODIFIED="1473353097564">
<node TEXT="GL Command for drawing primatives is drawArrays" ID="ID_1218246969" CREATED="1473353099330" MODIFIED="1473353110840"/>
<node TEXT="Takes a primative type and an array of points" ID="ID_1331506874" CREATED="1473353111836" MODIFIED="1473353167429"/>
</node>
<node TEXT="Points" ID="ID_1929747944" CREATED="1473353173545" MODIFIED="1473353185121">
<node TEXT="gl\_POINTS displays each point as a pixel" ID="ID_798079068" CREATED="1473353188352" MODIFIED="1473353240137"/>
</node>
<node TEXT="Lines" ID="ID_203501174" CREATED="1473353241323" MODIFIED="1473353243439">
<node TEXT="gl\_LINES draws a line between pairs" ID="ID_1844018213" CREATED="1473353246839" MODIFIED="1473353276272"/>
<node TEXT="gl\_LINE\_STRIP draws a line between adjacent points" ID="ID_270585651" CREATED="1473353276645" MODIFIED="1473355366328"/>
<node TEXT="gl\_LINE\_LOOP draws a line between adjacent points and between the first and last" ID="ID_241559736" CREATED="1473353301833" MODIFIED="1473355374530"/>
</node>
<node TEXT="Triangles" ID="ID_1925892520" CREATED="1473353363110" MODIFIED="1473354838546">
<attribute NAME="textbook" VALUE="2.4.2"/>
<node TEXT="gl\_TRIANGLES draws a triangle between triples" ID="ID_1390165280" CREATED="1473353416037" MODIFIED="1473353447946"/>
<node TEXT="gl\_TRIANGLE\_STRIP draws a triangle between all adjacent triples" ID="ID_1574033978" CREATED="1473353448555" MODIFIED="1473355381915"/>
<node TEXT="gl\_TRIANGLE\_FAN draws a triangle with the first point and all adjacent pairs" ID="ID_1810297067" CREATED="1473353476932" MODIFIED="1473355393035"/>
</node>
</node>
<node TEXT="Others" ID="ID_804385823" CREATED="1473353638655" MODIFIED="1473353680309">
<node TEXT="Triangulation" ID="ID_801676530" CREATED="1473353682219" MODIFIED="1473353687880">
<node TEXT="Other complex shapes are approximated with triangles" ID="ID_1008375404" CREATED="1473353690089" MODIFIED="1473353702106"/>
<node TEXT="More and smaller triangles can be used to improve the approximation" ID="ID_403903631" CREATED="1473353702561" MODIFIED="1473353717533"/>
<node TEXT="Often multiple triangulations are possible" ID="ID_465831787" CREATED="1473353766464" MODIFIED="1473353774878"/>
</node>
<node TEXT="Text" ID="ID_1457198412" CREATED="1473353776063" MODIFIED="1473354818399">
<attribute NAME="textbook" VALUE="2.4.5"/>
<node TEXT="Stroke Text formed from triangles like other complex shapes" ID="ID_441194276" CREATED="1473353784600" MODIFIED="1473353801082"/>
<node TEXT="Raster Text formed with pixels" ID="ID_1160111621" CREATED="1473353821999" MODIFIED="1473353917263"/>
<node TEXT="We&apos;ll just use HTML elements (which are raster text)" ID="ID_1688293026" CREATED="1473353917622" MODIFIED="1473353942525"/>
</node>
</node>
<node TEXT="Buffers" ID="ID_1470445260" CREATED="1473354095521" MODIFIED="1473354098214">
<node TEXT="Sending Data to GPU" ID="ID_1674041096" CREATED="1473354100519" MODIFIED="1473354108924">
<node TEXT="gl.createBuffer creates a space on the GPU" ID="ID_1818638236" CREATED="1473354176144" MODIFIED="1473354212544"/>
<node TEXT="gl.bindBuffer associates the GPU and CPU buffers" ID="ID_828505857" CREATED="1473354212899" MODIFIED="1473354225577"/>
<node TEXT="gl.bufferData is used to send data to GPU" ID="ID_1707251655" CREATED="1473354108929" MODIFIED="1473354134280"/>
</node>
<node TEXT="Hidden Surface Removal" ID="ID_1731180794" CREATED="1473354403878" MODIFIED="1473354673729">
<attribute NAME="textbook" VALUE="2.10.4"/>
<node TEXT="By default GL draws primatives in the order received (Painters Algorithm)" LOCALIZED_STYLE_REF="styles.topic" ID="ID_1785009759" CREATED="1473354458132" MODIFIED="1473354552842"/>
<node TEXT="gl.enable(gl.DEPTH\_TEST) turns on Hidden surface removal" ID="ID_1916199639" CREATED="1473354412316" MODIFIED="1473354456365"/>
<node TEXT="gl.clear(gl.COLOR\_BUFFER\_BIT | gl.DEPTH\_BUFFER\_BIT)" ID="ID_833250896" CREATED="1473354557421" MODIFIED="1473354590283"/>
</node>
</node>
</node>
</node>
</map>
