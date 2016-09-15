<map version="freeplane 1.3.0">
<!--To view this file, download free mind mapping software Freeplane from http://freeplane.sourceforge.net -->
<node TEXT="04 - Transformations" ID="ID_729166855" CREATED="1430766178119" MODIFIED="1473900973537">
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
<node TEXT="Coordinates" POSITION="right" ID="ID_477006610" CREATED="1473900977496" MODIFIED="1473901004425">
<node TEXT="Homogeneous Coordinates" ID="ID_964333491" CREATED="1473901226987" MODIFIED="1473901240275">
<node TEXT="Homogeneous Coordinates" ID="ID_361378674" CREATED="1473901240280" MODIFIED="1473973662042">
<attribute NAME="textbook" VALUE="4.3.4" OBJECT="org.freeplane.features.format.FormattedObject|4.3.4|number:decimal:#0.####"/>
<node TEXT="Sometimes called projective coordinates" ID="ID_325322025" CREATED="1473901250476" MODIFIED="1473901262084"/>
<node TEXT="Multiplying coordinates by a scalar does not change the meaning of the coordinates" ID="ID_768065314" CREATED="1473901262335" MODIFIED="1473901305925"/>
<node TEXT="Require one extra coordinate than the number of dimensions that can be represented" ID="ID_644033171" CREATED="1473901307694" MODIFIED="1473901327200"/>
<node TEXT="Can distinguish between directions and points" ID="ID_227878943" CREATED="1473901327534" MODIFIED="1473901341827"/>
</node>
<node TEXT="GL Coordinates" ID="ID_902817610" CREATED="1473901343760" MODIFIED="1473901353320">
<node TEXT="x,y,z have the same meaning as in euclidian coordinates" ID="ID_1927541763" CREATED="1473901353325" MODIFIED="1473901372046"/>
<node TEXT="Additional coordinate w distinguishes between directions (w=0) and lines" ID="ID_1966853051" CREATED="1473901372492" MODIFIED="1473901400674"/>
<node TEXT="As multipling by scalars does not change the point w is always normalized to 0 or 1" ID="ID_408279392" CREATED="1473901401078" MODIFIED="1473901423581"/>
</node>
<node TEXT="Barycentric Coordinates" ID="ID_1615879293" CREATED="1473901426946" MODIFIED="1473973636051">
<attribute NAME="textbook" VALUE="4.1.10"/>
<node TEXT="Two dimensional projective coordinate system for triangles" ID="ID_497681405" CREATED="1473901435272" MODIFIED="1473901455384"/>
<node TEXT="Used to interpolate values in fragment shader" ID="ID_1185450374" CREATED="1473901456552" MODIFIED="1473901495370"/>
</node>
</node>
</node>
<node TEXT="Linear Tranforamations" POSITION="right" ID="ID_1572309426" CREATED="1473901004739" MODIFIED="1473901010890">
<node TEXT="Primitives" ID="ID_270436693" CREATED="1473901648892" MODIFIED="1473901658269">
<node TEXT="Translation" ID="ID_558634934" CREATED="1473901664871" MODIFIED="1473901669684"/>
<node TEXT="Rotation in 2-D" ID="ID_1106115969" CREATED="1473973953596" MODIFIED="1473974277366">
<attribute NAME="textbook" VALUE="4.8.2"/>
<node TEXT="$x&apos;=x \cos \theta - y \sin \theta$" ID="ID_1284354090" CREATED="1473973959548" MODIFIED="1473973975745"/>
<node TEXT="$y&apos; = y \sin \theta + y \cos \theta$" ID="ID_1067152322" CREATED="1473973976083" MODIFIED="1473973997729"/>
</node>
<node TEXT="Rotation around x-axis" ID="ID_1132362849" CREATED="1473901670071" MODIFIED="1473901687670"/>
<node TEXT="Rotation around y-axis" ID="ID_1935543045" CREATED="1473901687981" MODIFIED="1473901692804"/>
<node TEXT="Rotation around z-axis" ID="ID_204956212" CREATED="1473901693191" MODIFIED="1473901698679"/>
<node TEXT="Ridged Body Tranformations" ID="ID_1803417569" CREATED="1473973794052" MODIFIED="1473973819268">
<node TEXT="Translation and Rotation are Ridged Body Transformations" ID="ID_958957531" CREATED="1473973819274" MODIFIED="1473973841361"/>
<node TEXT="In no combination can the change:" ID="ID_752264994" CREATED="1473973874244" MODIFIED="1473973881793">
<node TEXT="Shape" ID="ID_291296250" CREATED="1473973882283" MODIFIED="1473973883968"/>
<node TEXT="Volume" ID="ID_381205593" CREATED="1473973884243" MODIFIED="1473973885849"/>
</node>
</node>
<node TEXT="Scale" ID="ID_43570947" CREATED="1473901658273" MODIFIED="1473901664451"/>
<node TEXT="Reflection" ID="ID_1956164566" CREATED="1473901700940" MODIFIED="1473974260261">
<attribute NAME="textbook" VALUE="4.8.3"/>
<node TEXT="Negative scaling gives reflection" ID="ID_1095581870" CREATED="1473974051548" MODIFIED="1473974063626"/>
</node>
<node TEXT="Shear" ID="ID_709426676" CREATED="1473974118588" MODIFIED="1473974223237">
<attribute NAME="textbook" VALUE="4.9.4"/>
<node TEXT="$x&apos; = x + y \cot \theta$" ID="ID_1762873706" CREATED="1473974128769" MODIFIED="1473974149249"/>
</node>
<node TEXT="Projection" ID="ID_1411059053" CREATED="1473901945930" MODIFIED="1473901949570"/>
</node>
<node TEXT="Compositing" ID="ID_1858238687" CREATED="1473901724607" MODIFIED="1473901733454">
<node TEXT="Tranformation Composition" ID="ID_1306077188" CREATED="1473901733458" MODIFIED="1473901743594">
<node TEXT="Transformation can be combined using matrix multiplication" ID="ID_1880336353" CREATED="1473901743599" MODIFIED="1473901758933"/>
<node TEXT="Matix multiplication is does not commute" ID="ID_23885501" CREATED="1473901779706" MODIFIED="1473901793926"/>
<node TEXT="Given two transformations A and B:" ID="ID_540938183" CREATED="1473901759328" MODIFIED="1473901776610">
<node TEXT="The transformation AB is the same as applying B and then A" ID="ID_208264716" CREATED="1473901797859" MODIFIED="1473901819348"/>
<node TEXT="The transformation BA is the same as applying A and then B" ID="ID_333637138" CREATED="1473901819604" MODIFIED="1473901828941"/>
</node>
</node>
<node TEXT="Rotation about a point" ID="ID_1143540578" CREATED="1473901837935" MODIFIED="1473974321285">
<attribute NAME="textbook" VALUE="4.10.1"/>
<node TEXT="How can we rotate an object around an arbitrary point?" ID="ID_1273403144" CREATED="1473901914354" MODIFIED="1473901936021"/>
</node>
</node>
<node TEXT="Changing Coordinate Systems" ID="ID_286529461" CREATED="1473901968248" MODIFIED="1473901978982">
<node TEXT="Reversible Transformations" ID="ID_1924127697" CREATED="1473902034227" MODIFIED="1473902053900">
<node TEXT="If the matrix for a transformation is not rank deficient it is reversible" ID="ID_17222480" CREATED="1473902054421" MODIFIED="1473902071551"/>
</node>
<node TEXT="Coordinate Systems" ID="ID_707576143" CREATED="1473902106491" MODIFIED="1473902115571">
<node TEXT="There are three important coordinate systems with transformations between them" ID="ID_136221174" CREATED="1473902116267" MODIFIED="1473902136547"/>
<node TEXT="Object" ID="ID_1261182494" CREATED="1473902136864" MODIFIED="1473902139137"/>
<node TEXT="World" ID="ID_616795740" CREATED="1473902139556" MODIFIED="1473902142145"/>
<node TEXT="View" ID="ID_716168894" CREATED="1473902142529" MODIFIED="1473902143569"/>
</node>
</node>
</node>
<node TEXT="Quaternions" POSITION="right" ID="ID_724228516" CREATED="1473901011146" MODIFIED="1473901015407">
<node TEXT="Problems with Rotations" ID="ID_735279264" CREATED="1473902957421" MODIFIED="1473902970394">
<node TEXT="Gimbal Lock" ID="ID_226662553" CREATED="1473902970399" MODIFIED="1473974452077">
<attribute NAME="textbook" VALUE="4.14.3"/>
<node TEXT="Gimbals are circles mounted within each other and able to spin freely on some axis" ID="ID_1132842780" CREATED="1473902978654" MODIFIED="1473903032509"/>
<node TEXT="If the gimbal axis align then the degrees of freedom in the system drops" ID="ID_1018263147" CREATED="1473903032857" MODIFIED="1473903055591"/>
</node>
<node TEXT="Rotation Matrix" ID="ID_323786429" CREATED="1473903057649" MODIFIED="1473903067133">
<node TEXT="The rotation matricies suffer from gimbal lock" ID="ID_1474611263" CREATED="1473903068026" MODIFIED="1473903080725"/>
<node TEXT="Some combinations of x,y, and z rotations are rank deficient" ID="ID_553347320" CREATED="1473903081223" MODIFIED="1473903101785"/>
<node TEXT="No system based on Euler angles can avoid this problem" ID="ID_1671243264" CREATED="1473903129948" MODIFIED="1473903141872"/>
</node>
</node>
<node TEXT="Definitions" ID="ID_1932634953" CREATED="1473903147172" MODIFIED="1473903151165">
<node TEXT="Extension of complex numbers" ID="ID_20888771" CREATED="1473903499226" MODIFIED="1473974393997">
<attribute NAME="textbook" VALUE="4.14.1"/>
<node TEXT="$i^2=j^2=k^2=ijk=-1$" ID="ID_1674892560" CREATED="1473903510314" MODIFIED="1473903539872"/>
<node TEXT="Each quaternion has four components, one real and three imaginary" ID="ID_682079436" CREATED="1473903540969" MODIFIED="1473903561071"/>
<node TEXT="Quaternion multiplication does not commute" ID="ID_1083440923" CREATED="1473904718043" MODIFIED="1473904726424"/>
</node>
<node TEXT="Conjugation" ID="ID_474699227" CREATED="1473904642956" MODIFIED="1473904648227">
<node TEXT="$q^{*} = -\frac{1}{2}(q+iqi + jqj + kqk)$" ID="ID_173431150" CREATED="1473904649127" MODIFIED="1473904737918"/>
</node>
<node TEXT="Norm" ID="ID_1506515754" CREATED="1473904777358" MODIFIED="1473904781883">
<node TEXT="$\Vert q \Vert = \sqrt{qq^{*}}$" ID="ID_456012383" CREATED="1473904785615" MODIFIED="1473904878238"/>
<node TEXT="Works out to be the L-2 norm in $R^4$" ID="ID_972047930" CREATED="1473904881767" MODIFIED="1473904896443"/>
</node>
<node TEXT="Inverse" ID="ID_1457891848" CREATED="1473904899385" MODIFIED="1473904902176">
<node TEXT="$q^{-1} = \frac{q^{*}}{\Vert q \Vert ^2}$" ID="ID_1138944041" CREATED="1473904903482" MODIFIED="1473904955747"/>
</node>
</node>
<node TEXT="Representation" ID="ID_1374090858" CREATED="1473903582309" MODIFIED="1473903585208">
<node TEXT="Points" ID="ID_1180166467" CREATED="1473903586358" MODIFIED="1473903595552">
<node TEXT="$i,j,k$ are basis vectors for $R^3$" ID="ID_590867437" CREATED="1473903624014" MODIFIED="1473903638543"/>
<node TEXT="Points in $R^3$ have a 0 real component" ID="ID_601814673" CREATED="1473903595557" MODIFIED="1473903623377"/>
<node TEXT="Points have imaginary components determined by their location" ID="ID_166763188" CREATED="1473903648458" MODIFIED="1473903659506"/>
</node>
<node TEXT="Rotations" ID="ID_1755047629" CREATED="1473903660295" MODIFIED="1473903662970">
<node TEXT="Rotations expressed in an angle-axis format" ID="ID_521135775" CREATED="1473903667901" MODIFIED="1473904109255"/>
<node TEXT="$\cos{\frac{\theta}{2}} + ai + bj + ck$" ID="ID_1821812880" CREATED="1473903689674" MODIFIED="1473904009042"/>
<node TEXT="A point p can be rotated by $p&apos; = qpq^{-1}$" ID="ID_1991276218" CREATED="1473903746055" MODIFIED="1473903784077"/>
</node>
</node>
</node>
</node>
</map>
