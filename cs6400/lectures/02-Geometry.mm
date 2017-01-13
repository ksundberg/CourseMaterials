<map version="freeplane 1.3.0">
<!--To view this file, download free mind mapping software Freeplane from http://freeplane.sourceforge.net -->
<node TEXT="Geometry and Coordinate Systems" ID="ID_1723255651" CREATED="1283093380553" MODIFIED="1484347792602"><hook NAME="MapStyle">
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
<hook NAME="AutomaticEdgeColor" COUNTER="4"/>
<attribute NAME="author" VALUE="Kenneth Sundberg"/>
<attribute NAME="date" VALUE=""/>
<attribute NAME="subtitle" VALUE="CS 6400"/>
<node TEXT="Geometry" POSITION="right" ID="ID_1017130000" CREATED="1484349968866" MODIFIED="1484349971813">
<edge COLOR="#ff00ff"/>
<node TEXT="Building Blocks" ID="ID_1769370574" CREATED="1484349729668" MODIFIED="1484349982316">
<node TEXT="Handedness" ID="ID_1312158024" CREATED="1484347864285" MODIFIED="1484349788866">
<node TEXT="There are two ways to organize three dimensions" ID="ID_728434662" CREATED="1484347876346" MODIFIED="1484347932635"/>
<node TEXT="The choice is somewhat arbitrary" ID="ID_855295679" CREATED="1484347933016" MODIFIED="1484347943746"/>
<node TEXT="pbrt is \emph{left-handed}" ID="ID_1928483485" CREATED="1484347944100" MODIFIED="1484347956305"/>
</node>
<node TEXT="Vectors" ID="ID_1695825010" CREATED="1484347960373" MODIFIED="1484349752814">
<attribute NAME="textbook" VALUE="02-02"/>
<node TEXT="2 and 3 dimensional vectors are available" ID="ID_336887064" CREATED="1484347984726" MODIFIED="1484348009459"/>
<node TEXT="Both array access and named accessors are available" ID="ID_880571111" CREATED="1484348026078" MODIFIED="1484348055446"/>
<node TEXT="Data members are public for performance and lack of need for encapsulation" ID="ID_664574257" CREATED="1484348066744" MODIFIED="1484348103738"/>
</node>
<node TEXT="Vector operations" ID="ID_840764077" CREATED="1484348118579" MODIFIED="1484349805252">
<node TEXT="Dot and Cross products available as free functions" ID="ID_1454029731" CREATED="1484348130459" MODIFIED="1484348168395"/>
<node TEXT="Normalize available as free function" ID="ID_610095791" CREATED="1484348199375" MODIFIED="1484348218626"/>
<node TEXT="Min, Max, MinElement, and MaxElement also available" ID="ID_1440260751" CREATED="1484348234075" MODIFIED="1484348248568"/>
</node>
<node TEXT="Points" ID="ID_1333297591" CREATED="1484348329275" MODIFIED="1484349758930">
<attribute NAME="textbook" VALUE="02-03"/>
<node TEXT="Points are implemented identically to Vectors" ID="ID_1824607260" CREATED="1484348332469" MODIFIED="1484348341967"/>
<node TEXT="pbrt only uses homogeneous coordinates for transformations" ID="ID_850263078" CREATED="1484348342417" MODIFIED="1484348361981"/>
</node>
<node TEXT="Normals" ID="ID_1085333680" CREATED="1484348388446" MODIFIED="1484349760938">
<attribute NAME="textbook" VALUE="02-04"/>
<node TEXT="A vector that is perpendicular to a surface" ID="ID_415294629" CREATED="1484348393693" MODIFIED="1484348405315"/>
<node TEXT="Implemented like a Vector" ID="ID_694220338" CREATED="1484348405613" MODIFIED="1484348433506"/>
<node TEXT="Behaves differently under transformation" ID="ID_1241245826" CREATED="1484348433510" MODIFIED="1484348444442"/>
<node TEXT="-Note: Normals may not be normal - length may not be 1" ID="ID_260449983" CREATED="1484348489011" MODIFIED="1484350159853"/>
</node>
<node TEXT="Rays" ID="ID_564165617" CREATED="1484348568566" MODIFIED="1484349763443">
<attribute NAME="textbook" VALUE="02-05"/>
<node TEXT="Contains a point and a vector" ID="ID_660226815" CREATED="1484348648533" MODIFIED="1484348654847"/>
<node TEXT="$r(t) = o + td$" ID="ID_157749364" CREATED="1484348655158" MODIFIED="1484348668829"/>
<node TEXT="Also has a time parameter for animation and scenes with moving objects" ID="ID_408352372" CREATED="1484348670992" MODIFIED="1484348688332"/>
<node TEXT="Knows the medium that contains the origin" ID="ID_715263654" CREATED="1484348744381" MODIFIED="1484348754669"/>
</node>
<node TEXT="Ray-Differentials" ID="ID_1396772973" CREATED="1484348756131" MODIFIED="1484349766040">
<node TEXT="RayDifferential is a subclass of Ray" ID="ID_4972442" CREATED="1484348764536" MODIFIED="1484348782384"/>
<node TEXT="Used to track uncertainty in a ray" ID="ID_414763496" CREATED="1484348782797" MODIFIED="1484348819184"/>
<node TEXT="Anti-aliasing and texturing require a RayDifferential" ID="ID_126126200" CREATED="1484348819782" MODIFIED="1484348836679"/>
</node>
</node>
<node TEXT="Transformations" ID="ID_66351779" CREATED="1484349699569" MODIFIED="1484350158797">
<node TEXT="Homogeneous Coordinates" ID="ID_1724232482" CREATED="1484349101291" MODIFIED="1484349713793">
<node TEXT="Uses a fourth dimension to distinguish between points and vectors" ID="ID_705209797" CREATED="1484349115219" MODIFIED="1484349134607"/>
<node TEXT="Needed for translation transformations" ID="ID_1610146506" CREATED="1484349135060" MODIFIED="1484349182366"/>
</node>
<node TEXT="Transformations" ID="ID_1144371378" CREATED="1484349206127" MODIFIED="1484350158796">
<node TEXT="Translations" ID="ID_49818039" CREATED="1484349212182" MODIFIED="1484349214809"/>
<node TEXT="Rotation" ID="ID_1200523061" CREATED="1484349215209" MODIFIED="1484349217165"/>
<node TEXT="Scale" ID="ID_940774054" CREATED="1484349217493" MODIFIED="1484349220645"/>
<node TEXT="Look At" ID="ID_662719005" CREATED="1484349221147" MODIFIED="1484349242089"/>
</node>
<node TEXT="Transforming Normals" ID="ID_1008935718" CREATED="1484349243459" MODIFIED="1484349721098">
<node TEXT="normals don&apos;t transform the way tangents do" ID="ID_908933582" CREATED="1484349252869" MODIFIED="1484349306419"/>
<node TEXT="To maintain orthogonality after transform M" ID="ID_850603590" CREATED="1484349453812" MODIFIED="1484349496207"/>
<node TEXT="Normal must be transformed by $(M^{-1})^T$" ID="ID_271896080" CREATED="1484349496626" MODIFIED="1484349525442"/>
<node TEXT="For this reason transforms will contain their inverse" ID="ID_177688425" CREATED="1484349525798" MODIFIED="1484349536977"/>
</node>
</node>
<node TEXT="Utilities" ID="ID_351180032" CREATED="1484349818101" MODIFIED="1484349975462">
<node TEXT="Bounding Boxes" ID="ID_1965507562" CREATED="1484348862181" MODIFIED="1484349826403">
<attribute NAME="textbook" VALUE="02-06"/>
<node TEXT="pbrt uses axis aligned bounding boxes in a variety of contexts" ID="ID_302896996" CREATED="1484348975507" MODIFIED="1484348994414"/>
<node TEXT="Union and intersection functions" ID="ID_1464987336" CREATED="1484348994874" MODIFIED="1484349076622"/>
<node TEXT="Other utility functions" ID="ID_1168049502" CREATED="1484349059170" MODIFIED="1484349067243"/>
</node>
<node TEXT="Quaternions" ID="ID_599576900" CREATED="1484349882056" MODIFIED="1484349910145">
<attribute NAME="textbook" VALUE="02-09"/>
<node TEXT="Avoids gimbal lock" ID="ID_1793141673" CREATED="1484349888330" MODIFIED="1484349928021"/>
<node TEXT="Much smoother interpolations for animation" ID="ID_1208672092" CREATED="1484349928365" MODIFIED="1484349956270"/>
</node>
<node TEXT="Interactions" ID="ID_489703744" CREATED="1484349600488" MODIFIED="1484349828281">
<attribute NAME="textbook" VALUE="02-10"/>
<node TEXT="Represensts local geometry of a point on a surface" ID="ID_1386678447" CREATED="1484349624637" MODIFIED="1484349637043"/>
<node TEXT="Texture cordinates and normals" ID="ID_1691880527" CREATED="1484349637408" MODIFIED="1484349668569"/>
<node TEXT="Also partial derivatives of these values" ID="ID_620330749" CREATED="1484349669002" MODIFIED="1484349684318"/>
</node>
</node>
</node>
</node>
</map>
