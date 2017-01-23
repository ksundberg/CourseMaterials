<map version="freeplane 1.3.0">
<!--To view this file, download free mind mapping software Freeplane from http://freeplane.sourceforge.net -->
<node TEXT="Shapes" ID="ID_1723255651" CREATED="1283093380553" MODIFIED="1485024530616"><hook NAME="MapStyle">
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
<attribute NAME="subtitle" VALUE="CS6400"/>
<node TEXT="Shapes" POSITION="right" ID="ID_1507486254" CREATED="1485024683358" MODIFIED="1485024688028">
<edge COLOR="#ff0000"/>
<node TEXT="Interface" ID="ID_637469453" CREATED="1485024719326" MODIFIED="1485025703377">
<node TEXT="Intersections" ID="ID_1732444245" CREATED="1485025235634" MODIFIED="1485025838359">
<attribute NAME="textbook" VALUE="03-01"/>
<node TEXT="IntersectP - Predicate returns only that there is an intersection" ID="ID_812763223" CREATED="1485025244621" MODIFIED="1485025336257"/>
<node TEXT="Intersect - Returns if there is an intersection along with details of that intersection" ID="ID_1553212903" CREATED="1485025336630" MODIFIED="1485025355601"/>
</node>
<node TEXT="Bounding Box" ID="ID_1054751586" CREATED="1485024725604" MODIFIED="1485024733682">
<node TEXT="Shapes have an axis aligned bounding box" ID="ID_984760651" CREATED="1485024733687" MODIFIED="1485024750210"/>
<node TEXT="Intersecting the bounding box may be much cheaper" ID="ID_591957063" CREATED="1485024750544" MODIFIED="1485024769834"/>
</node>
<node TEXT="Plane Intersection" ID="ID_987118159" CREATED="1485024906354" MODIFIED="1485025957632">
<node TEXT="Plane : $ax +by +cz + d = 0$" ID="ID_776080503" CREATED="1485024921923" MODIFIED="1485024990512"/>
<node TEXT="Substitute $(x,y,z)$ with $o + td$" ID="ID_1486885357" CREATED="1485024991904" MODIFIED="1485025034708"/>
<node TEXT="Solve for $t = \frac{-d-((a,b,c) \cdot o)}{((a,b,c) \cdot d)}$" ID="ID_300656080" CREATED="1485025036520" MODIFIED="1485027002700"/>
<node TEXT="Because plane is axis aligned this simplifies to:" ID="ID_830426248" CREATED="1485025105144" MODIFIED="1485025957630"/>
<node TEXT="$t = \frac{x-o_x}{d_x}$" ID="ID_90032463" CREATED="1485025130699" MODIFIED="1485025173991"/>
</node>
<node TEXT="Bounding Boxes and Acceleration" ID="ID_1542484911" CREATED="1485025408822" MODIFIED="1485025417407">
<node TEXT="Combining plane intersections you can perform bounding box intersections" ID="ID_1805599800" CREATED="1485025419066" MODIFIED="1485025445135"/>
<node TEXT="The order of plane intersections determine if there is a box intersection" ID="ID_250858837" CREATED="1485025445367" MODIFIED="1485025552861"/>
<node TEXT="This is at the heart of the acceleration structures and is worth being optimized" ID="ID_586101820" CREATED="1485025553109" MODIFIED="1485025577983"/>
</node>
<node TEXT="Surface Area" ID="ID_37920025" CREATED="1485025634722" MODIFIED="1485025693557">
<node TEXT="Lights need to know their surface areas to be able to properly scale energy" ID="ID_1829298938" CREATED="1485025716458" MODIFIED="1485025743874"/>
<node TEXT="Each shape needs to be able to compute a surface area" ID="ID_1637928266" CREATED="1485025744134" MODIFIED="1485025753718"/>
</node>
<node TEXT="Sidedness" ID="ID_598968082" CREATED="1485025755725" MODIFIED="1485025760281">
<node TEXT="Back face culling does not happen in pbrt" ID="ID_520166608" CREATED="1485025760286" MODIFIED="1485025792830"/>
<node TEXT="It leads to physical inconsistencies and is not faster" ID="ID_1215941626" CREATED="1485025793140" MODIFIED="1485025810337"/>
</node>
</node>
<node TEXT="Quadrics" ID="ID_876220510" CREATED="1485025846068" MODIFIED="1485025865390">
<node TEXT="Sphere" ID="ID_106136888" CREATED="1485025865395" MODIFIED="1485025897252">
<attribute NAME="textbook" VALUE="03-02"/>
<node TEXT="Implicit: $x^2+y^2+z^2 -r^2 = 0$" ID="ID_645334540" CREATED="1485025899560" MODIFIED="1485025983488"/>
<node TEXT="Parametric:" ID="ID_318132581" CREATED="1485025984345" MODIFIED="1485025988616">
<node TEXT="$x=r \sin \theta \cos \phi$" ID="ID_1759203633" CREATED="1485025988621" MODIFIED="1485026007427"/>
<node TEXT="$y = r \sin \theta \sin \phi$" ID="ID_518815800" CREATED="1485026007752" MODIFIED="1485026024537"/>
<node TEXT="$z = r \cos \theta$" ID="ID_237824604" CREATED="1485026024993" MODIFIED="1485026033239"/>
</node>
<node TEXT="Both forms used depending on what is most natural" ID="ID_1795951243" CREATED="1485026034350" MODIFIED="1485026049506"/>
</node>
<node TEXT="Sphere bounds" ID="ID_185901723" CREATED="1485026054254" MODIFIED="1485026093238">
<node TEXT="Bounding box is straight forward" ID="ID_804806612" CREATED="1485026093242" MODIFIED="1485027145761"/>
<node TEXT="Bounding could be improved for partial spheres" ID="ID_788640044" CREATED="1485026105966" MODIFIED="1485026167620"/>
</node>
<node TEXT="Sphere intersection" ID="ID_1994154550" CREATED="1485026226263" MODIFIED="1485026240947">
<node TEXT="Substitute ray equation into implicit form and solve for t" ID="ID_1027991549" CREATED="1485026240951" MODIFIED="1485026312665"/>
<node TEXT="Quadratic equation has zero, one or two solution" ID="ID_804358387" CREATED="1485026313139" MODIFIED="1485026330646"/>
<node TEXT="$\frac{y}{x} = \tan \phi$" ID="ID_963657908" CREATED="1485026359252" MODIFIED="1485026391894"/>
<node TEXT="Check locations against partial sphere bounds" ID="ID_840829221" CREATED="1485026392419" MODIFIED="1485026410103"/>
</node>
<node TEXT="Normals" ID="ID_567819031" CREATED="1485026458235" MODIFIED="1485026463783">
<node TEXT="The surface normal and its partial derivatives follow from formula for a sphere" ID="ID_194345127" CREATED="1485026463787" MODIFIED="1485026490139"/>
</node>
<node TEXT="Cylinder" ID="ID_1659744469" CREATED="1485026492865" MODIFIED="1485026518842">
<attribute NAME="textbook" VALUE="03-03"/>
<node TEXT="Implicit: $x^2 +y^2 - r^2 = 0$" ID="ID_31134506" CREATED="1485026592830" MODIFIED="1485026611376"/>
<node TEXT="Parametric:" ID="ID_334278656" CREATED="1485026641100" MODIFIED="1485026650773">
<node TEXT="$x=r \cos \theta$" ID="ID_992437770" CREATED="1485026650777" MODIFIED="1485026663731"/>
<node TEXT="$y = r \sin \theta$" ID="ID_966182375" CREATED="1485026664190" MODIFIED="1485026692752"/>
<node TEXT="$\phi = u \phi_{max}$" ID="ID_1966632844" CREATED="1485026693578" MODIFIED="1485026715051"/>
<node TEXT="$z = z_{min} + v(z_{max} - z_{min}$" ID="ID_1194626039" CREATED="1485026715685" MODIFIED="1485026742887"/>
</node>
<node TEXT="Bounds and intersection very similar to Sphere" ID="ID_1482463705" CREATED="1485026746878" MODIFIED="1485026758286"/>
</node>
<node TEXT="Disk" ID="ID_510918384" CREATED="1485027180534" MODIFIED="1485027209088">
<attribute NAME="textbook" VALUE="03-04"/>
<node TEXT="$\phi = u \phi_{max}$" ID="ID_1929525389" CREATED="1485027561103" MODIFIED="1485027585949"/>
<node TEXT="$x = ((1-v)r_i +vr) \cos \phi$" ID="ID_1985897162" CREATED="1485027586359" MODIFIED="1485027659605"/>
<node TEXT="$y = ((1-v)r_i +vr)\sin\phi$" ID="ID_694053483" CREATED="1485027660107" MODIFIED="1485027690601"/>
<node TEXT="$z=h$" ID="ID_12867136" CREATED="1485027691043" MODIFIED="1485027694407"/>
</node>
<node TEXT="Other Quadrics" ID="ID_711402033" CREATED="1485027695592" MODIFIED="1485027737886">
<attribute NAME="textbook" VALUE="03-05"/>
<node TEXT="Cones, Paraboloids, and Hyperbolids also supported" ID="ID_567473353" CREATED="1485027739500" MODIFIED="1485027752789"/>
<node TEXT="The method is the same as for spheres" ID="ID_1499372455" CREATED="1485027753434" MODIFIED="1485027774943"/>
</node>
</node>
<node TEXT="Meshes" ID="ID_78597613" CREATED="1485038628085" MODIFIED="1485038637285">
<node TEXT="Triangle Mesh" ID="ID_1822371964" CREATED="1485038657815" MODIFIED="1485039354498">
<attribute NAME="textbook" VALUE="03-06"/>
<node TEXT="" ID="ID_1742846660" CREATED="1485038667594" MODIFIED="1485038667594"/>
</node>
<node TEXT="Barycentric Coordinates" ID="ID_1068122185" CREATED="1485039380442" MODIFIED="1485039386896"/>
<node TEXT="Triangle Intersection" ID="ID_1224674814" CREATED="1485039377296" MODIFIED="1485039400682"/>
</node>
<node TEXT="Curves" ID="ID_784884877" CREATED="1485038637705" MODIFIED="1485038640043"/>
</node>
<node TEXT="Acceleration" POSITION="right" ID="ID_431187148" CREATED="1485024688292" MODIFIED="1485024691344">
<edge COLOR="#0000ff"/>
</node>
</node>
</map>
