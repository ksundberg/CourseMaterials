<map version="freeplane 1.3.0">
<!--To view this file, download free mind mapping software Freeplane from http://freeplane.sourceforge.net -->
<node TEXT="05 - Viewing" ID="ID_729166855" CREATED="1430766178119" MODIFIED="1474564521631">
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
<node TEXT="WebGL" POSITION="right" ID="ID_1198514430" CREATED="1474565639603" MODIFIED="1474565649097">
<node TEXT="Communication" ID="ID_501553995" CREATED="1474565649101" MODIFIED="1474565659410">
<node TEXT="Attribute" ID="ID_1822279122" CREATED="1474565659414" MODIFIED="1474580910625">
<node TEXT="Input from CPU to vertex shader" ID="ID_350469625" CREATED="1474580911140" MODIFIED="1474580919808"/>
<node TEXT="One value per vertex" ID="ID_982930493" CREATED="1474580920124" MODIFIED="1474580929369"/>
<node TEXT="In Shader: attribute \emph{type name}" ID="ID_482543862" CREATED="1474580930252" MODIFIED="1474580948889"/>
<node TEXT="In JavaScript: bind buffer and attribute location" ID="ID_378089123" CREATED="1474580949420" MODIFIED="1474580973865"/>
</node>
<node TEXT="Uniforms" ID="ID_555893408" CREATED="1474565666417" MODIFIED="1474565671453">
<node TEXT="Input from CPU to vertex / fragment shader" ID="ID_354549525" CREATED="1474581018620" MODIFIED="1474581031521"/>
<node TEXT="One value everywhere" ID="ID_1026074108" CREATED="1474581031780" MODIFIED="1474581067889"/>
<node TEXT="In Shader: uniform \emph{type name}" ID="ID_1707969693" CREATED="1474581068332" MODIFIED="1474581080137"/>
<node TEXT="In JavaScript: getUniformLocation and uniform" ID="ID_552014710" CREATED="1474581080516" MODIFIED="1474581130578"/>
</node>
<node TEXT="Varying" ID="ID_889008562" CREATED="1474565672689" MODIFIED="1474565677221">
<node TEXT="Output from vertex shader" ID="ID_896161494" CREATED="1474581501334" MODIFIED="1474581507778"/>
<node TEXT="Input to fragment shader" ID="ID_727459436" CREATED="1474581508102" MODIFIED="1474581515682"/>
<node TEXT="In Shader: varying \emph{type name}" ID="ID_404615982" CREATED="1474581516022" MODIFIED="1474581525506"/>
<node TEXT="Must match between the shaders" ID="ID_1817318231" CREATED="1474581525878" MODIFIED="1474581582419"/>
</node>
</node>
</node>
<node TEXT="Projections" POSITION="right" ID="ID_309863385" CREATED="1474565729409" MODIFIED="1474565906856">
<node TEXT="Parallel" ID="ID_305464694" CREATED="1474565734679" MODIFIED="1474565909199">
<node TEXT="Orthographic" ID="ID_1140807844" CREATED="1474565737471" MODIFIED="1474582204592">
<attribute NAME="textbook" VALUE="5.1.2"/>
<node TEXT="Projectors perpendicular to projection plane" ID="ID_1971831934" CREATED="1474581676111" MODIFIED="1474582067245"/>
<node TEXT="Projection plane perpendicular to an axis" ID="ID_1276240553" CREATED="1474582067632" MODIFIED="1474582096477"/>
</node>
<node TEXT="Axonometric" ID="ID_1619942459" CREATED="1474565743057" MODIFIED="1474582193591">
<attribute NAME="textbook" VALUE="5.1.3"/>
<node TEXT="Projectors perpendicular  to projection plane, but any plane" ID="ID_1142243434" CREATED="1474582101856" MODIFIED="1474582125484"/>
<node TEXT="isometric - symmetric to all three axis" ID="ID_1901870979" CREATED="1474582125816" MODIFIED="1474582164413"/>
<node TEXT="dimetric -symetric to two axis" ID="ID_1330831926" CREATED="1474582164896" MODIFIED="1474582177837"/>
</node>
<node TEXT="Oblique" ID="ID_801689262" CREATED="1474565766129" MODIFIED="1474582240246">
<attribute NAME="textbook" VALUE="5.1.4"/>
<node TEXT="Projectors are all co-parallel" ID="ID_458259257" CREATED="1474582241295" MODIFIED="1474582264149"/>
<node TEXT="Most generic form" ID="ID_1288760285" CREATED="1474582264368" MODIFIED="1474582283664"/>
</node>
</node>
<node TEXT="Perspective" ID="ID_900968782" CREATED="1474565909458" MODIFIED="1474565911655">
<node TEXT="Vanishing Points" ID="ID_1613341568" CREATED="1474565932434" MODIFIED="1474582409459">
<attribute NAME="textbook" VALUE="5.1.5"/>
<node TEXT="Objects that are farther away appear smaller" ID="ID_1070451183" CREATED="1474582294409" MODIFIED="1474582309461"/>
<node TEXT="Apperance of 1,2,3 vanishing points" ID="ID_1250156068" CREATED="1474582310369" MODIFIED="1474582377229"/>
<node TEXT="Happens automatically when we do the math" ID="ID_1620661882" CREATED="1474582377633" MODIFIED="1474582384956"/>
</node>
</node>
<node TEXT="Camera" ID="ID_1994430878" CREATED="1474565967770" MODIFIED="1474565969894">
<node TEXT="Changing Frames" ID="ID_498150271" CREATED="1474565976026" MODIFIED="1474582574776">
<attribute NAME="textbook" VALUE="5.3.1"/>
<node TEXT="In WebGL the camera is fixed" ID="ID_1760869716" CREATED="1474582414857" MODIFIED="1474582424005"/>
<node TEXT="To move the &apos;camera&apos; we move the entire scene" ID="ID_823726043" CREATED="1474582424369" MODIFIED="1474582441417"/>
</node>
<node TEXT="Look At" ID="ID_774954" CREATED="1474566023034" MODIFIED="1474582744632">
<attribute NAME="textbook" VALUE="5.3.2"/>
<node TEXT="u-v-n coordinate system" ID="ID_274358048" CREATED="1474582662671" MODIFIED="1474582669702"/>
<node TEXT="Up vector, View vector, and their cross product" ID="ID_903045746" CREATED="1474582670145" MODIFIED="1474582691508"/>
</node>
</node>
<node TEXT="Shadows" ID="ID_1931123190" CREATED="1474579506407" MODIFIED="1474579509356">
<node TEXT="Projected Shadows" ID="ID_1424977784" CREATED="1474579626072" MODIFIED="1474579757312">
<attribute NAME="textbook" VALUE="5.10.1"/>
<node TEXT="Shadows are important visual clues" ID="ID_399371341" CREATED="1474579634368" MODIFIED="1474579646780"/>
<node TEXT="Full shadow calculations are hard" ID="ID_139603462" CREATED="1474579647119" MODIFIED="1474579660909"/>
<node TEXT="If we just want shadows on a plane we can do it" ID="ID_1992048270" CREATED="1474579661496" MODIFIED="1474579738149"/>
</node>
<node TEXT="Shadow Maps" ID="ID_1301152309" CREATED="1474579942418" MODIFIED="1474580424054">
<attribute NAME="textbppl" VALUE="5.11" OBJECT="org.freeplane.features.format.FormattedNumber|5.11"/>
<node TEXT="Render depth from light source to scene" ID="ID_498291096" CREATED="1474579948009" MODIFIED="1474580119045"/>
<node TEXT="When rendering scene check distance to light source" ID="ID_130692940" CREATED="1474580119521" MODIFIED="1474580193103"/>
<node TEXT="Compare with depth from light source to determine if you are in shadow" ID="ID_1676229153" CREATED="1474580193442" MODIFIED="1474580204375"/>
</node>
</node>
</node>
</node>
</map>
