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
<node TEXT="$V - E + F = 2(1-g)$ - Euler-Poncar\&apos;{e} formula" ID="ID_1742846660" CREATED="1485038667594" MODIFIED="1485198170050"/>
<node TEXT="$E = \frac{3}{2} F$ - for a triangle mesh" ID="ID_1546496006" CREATED="1485197942235" MODIFIED="1485197972608"/>
<node TEXT="$g \approx 0$ for most meshes" ID="ID_344401052" CREATED="1485198207191" MODIFIED="1485198229885"/>
<node TEXT="$V \approx 2F$" ID="ID_945211723" CREATED="1485198230399" MODIFIED="1485198258267"/>
<node TEXT="Most vertices participate in 6 triangles, so it is a good idea to share vertex information" ID="ID_1446715994" CREATED="1485198293385" MODIFIED="1485198340415"/>
</node>
<node TEXT="Triangle Mesh" ID="ID_839600685" CREATED="1485198356999" MODIFIED="1485198360873">
<node TEXT="Consists of" ID="ID_197309836" CREATED="1485198618583" MODIFIED="1485198621702">
<node TEXT="a vector of points (vertices)" ID="ID_1615673926" CREATED="1485198621707" MODIFIED="1485198629832"/>
<node TEXT="a vector of triangles" ID="ID_851122421" CREATED="1485198630256" MODIFIED="1485198637625"/>
</node>
<node TEXT="Triangles are triples of offsets" ID="ID_363338295" CREATED="1485198579820" MODIFIED="1485198614283"/>
</node>
<node TEXT="Triangle Intersection" ID="ID_1224674814" CREATED="1485039377296" MODIFIED="1485039400682">
<node TEXT="Transform into 2-D problem" ID="ID_639017303" CREATED="1485198880069" MODIFIED="1485198898249"/>
<node TEXT="Check intersection with edges" ID="ID_924413233" CREATED="1485198898629" MODIFIED="1485198913839"/>
<node TEXT="Fallback to double if ray falls along edge" ID="ID_1239270469" CREATED="1485198914195" MODIFIED="1485198953492"/>
</node>
</node>
<node TEXT="Curves" ID="ID_784884877" CREATED="1485038637705" MODIFIED="1485038640043">
<node TEXT="B\&apos;{e}zier splines" ID="ID_191881879" CREATED="1485199020920" MODIFIED="1485199651937">
<attribute NAME="textbook" VALUE="03-07"/>
<node TEXT="$p(u) = (1-u)^3p_0 + 3(1-u)^2up_1+3(1-u)u^2p_2 +u^3p_3$" ID="ID_1663565953" CREATED="1485199045377" MODIFIED="1485199130847"/>
<node TEXT="Curve is flat shape with width interpolated along length" ID="ID_285244111" CREATED="1485199131673" MODIFIED="1485199182762"/>
<node TEXT="Types:" ID="ID_129037176" CREATED="1485199230913" MODIFIED="1485199235010">
<node TEXT="Flat - always oriented to face ray (good if very small)" ID="ID_51875421" CREATED="1485199235014" MODIFIED="1485199250764"/>
<node TEXT="Cylinder - round profile" ID="ID_1781204708" CREATED="1485199251103" MODIFIED="1485199263829"/>
<node TEXT="Ribbon - Flat, but not always oriented to face ray, normal is interpolated along length" ID="ID_1014017593" CREATED="1485199264248" MODIFIED="1485199372525"/>
</node>
</node>
<node TEXT="Bounding curves" ID="ID_2900311" CREATED="1485199307149" MODIFIED="1485199314608">
<node TEXT="B\&apos;{e}zier splines lie within the convex hull of the control points" ID="ID_245600315" CREATED="1485199314613" MODIFIED="1485199344394"/>
<node TEXT="Blossom function can generate control points for sub-curves" ID="ID_1091909251" CREATED="1485199344954" MODIFIED="1485199587910"/>
<node TEXT="Better bounds can be made by subdividing curve.  This is also the basis of curve intersection." ID="ID_1673999934" CREATED="1485199588423" MODIFIED="1485199617424"/>
</node>
<node TEXT="Subdivision Surfaces" ID="ID_781486016" CREATED="1485199666244" MODIFIED="1485199811926">
<attribute NAME="textbook" VALUE="03-08"/>
<node TEXT="Triangle mesh is refined with more and smaller triangles" ID="ID_1957293219" CREATED="1485199813420" MODIFIED="1485199838461"/>
<node TEXT="The limit surface of this process is what we render" ID="ID_1808367095" CREATED="1485199838947" MODIFIED="1485199865994"/>
<node TEXT="Every triangle become four smaller triangles" ID="ID_1252093723" CREATED="1485199915403" MODIFIED="1485199925558"/>
<node TEXT="New vertices are weighted averages of neighbors" ID="ID_1812011031" CREATED="1485199926246" MODIFIED="1485199983989"/>
</node>
<node TEXT="Valance" ID="ID_779435533" CREATED="1485200025837" MODIFIED="1485200034099">
<node TEXT="The weights for new vertices depend on valance (number of edges)" ID="ID_461203498" CREATED="1485200034104" MODIFIED="1485200058783"/>
<node TEXT="Valance 6 - are interior faces and become progressivly smoother" ID="ID_224088013" CREATED="1485200059216" MODIFIED="1485200087725"/>
<node TEXT="Valance 4 and 5 - are edges or points and remain sharp" ID="ID_1916232297" CREATED="1485200088159" MODIFIED="1485200124858"/>
</node>
</node>
<node TEXT="CSG" ID="ID_1180131616" CREATED="1485200229864" MODIFIED="1485200238654">
<node TEXT="Constructive Solid Geometry" ID="ID_1550158512" CREATED="1485200238658" MODIFIED="1485200245206">
<node TEXT="An alternative to method of modeling complex surfaces" ID="ID_332794367" CREATED="1485200247215" MODIFIED="1485200301066"/>
<node TEXT="Contains positive and negative surfaces" ID="ID_1183965920" CREATED="1485200301410" MODIFIED="1485200317362"/>
<node TEXT="Negative surfaces make &apos;holes&apos; in positive surfaces" ID="ID_1682840045" CREATED="1485200318088" MODIFIED="1485200341334"/>
<node TEXT="Example: A positive and negative sphere lightly intersecting will make a Death Star shape." ID="ID_203444178" CREATED="1485200341734" MODIFIED="1485200368379"/>
</node>
</node>
</node>
<node TEXT="Acceleration" POSITION="right" ID="ID_431187148" CREATED="1485024688292" MODIFIED="1485024691344">
<edge COLOR="#0000ff"/>
<node TEXT="Instancing" ID="ID_427040450" CREATED="1485200411836" MODIFIED="1485200425035">
<node TEXT="Object Instancing" ID="ID_215896626" CREATED="1485200425039" MODIFIED="1485200562048">
<attribute NAME="textbook" VALUE="04-01"/>
<node TEXT="Reuse geometry multiple times" ID="ID_1498467757" CREATED="1485200446513" MODIFIED="1485200474178"/>
<node TEXT="Different transformations for each instance" ID="ID_851739503" CREATED="1485200474531" MODIFIED="1485200487354"/>
<node TEXT="Forwards all shape function to underlying geometry and applies tranformations to inputs and outputs" ID="ID_72752125" CREATED="1485200487791" MODIFIED="1485200539697"/>
</node>
</node>
<node TEXT="Aggregates" ID="ID_1062638911" CREATED="1485200566803" MODIFIED="1485203244758">
<node TEXT="Bounding Volume Hierarchies" ID="ID_1062712928" CREATED="1485203244762" MODIFIED="1485203266715">
<attribute NAME="textbook" VALUE="04-03"/>
<node TEXT="Primatives stored in leaves" ID="ID_639563376" CREATED="1485203342998" MODIFIED="1485203350337"/>
<node TEXT="Interior nodes have bounding box for all children" ID="ID_334986439" CREATED="1485203350804" MODIFIED="1485203362643"/>
<node TEXT="Subdivides the objects not the space" ID="ID_1066032664" CREATED="1485203362903" MODIFIED="1485203381565"/>
<node TEXT="Easier to build, slower to traverse" ID="ID_236233306" CREATED="1485203383431" MODIFIED="1485203395083"/>
</node>
<node TEXT="Construction" ID="ID_1565299184" CREATED="1485203580639" MODIFIED="1485203584451">
<node TEXT="Compute centroid and bounding box for all primitives" ID="ID_1930245155" CREATED="1485203584455" MODIFIED="1485203604530"/>
<node TEXT="Choose an axis (x,y,z)" ID="ID_1330155750" CREATED="1485203605057" MODIFIED="1485203672041"/>
<node TEXT="Partition primitives based on midpoint of centroids" ID="ID_508970551" CREATED="1485203672401" MODIFIED="1485203752508"/>
<node TEXT="For some distributions this strategy works poorly leading to large overlapping boxes" ID="ID_739354175" CREATED="1485203753099" MODIFIED="1485203794487"/>
</node>
<node TEXT="Surface Area Hueristic" ID="ID_1494817070" CREATED="1485204021336" MODIFIED="1485204028702">
<node TEXT="Provide a cost metric to make well founded partition decisions" ID="ID_1899121847" CREATED="1485204028706" MODIFIED="1485204063946"/>
<node TEXT="$\Sigma^N_{i=1} t_{isect}(i)$ - Cost of intersecting all remaining primitives" ID="ID_1479761957" CREATED="1485204064276" MODIFIED="1485204127074"/>
<node TEXT="$t_{trav} + p_A \Sigma^{N_A}_{i=1} t_{isect}(a_i) + p_B \Sigma^{N_B}_{i=1} t_{isect}(b_i)$" ID="ID_1026275619" CREATED="1485204128133" MODIFIED="1485204233812"/>
<node TEXT="$p(A|B) = \frac{S_A}{S_B}$" ID="ID_1334586955" CREATED="1485204235292" MODIFIED="1485205157970"/>
</node>
<node TEXT="Using the SAH" ID="ID_1719774332" CREATED="1485204265921" MODIFIED="1485204278295">
<node TEXT="Divide primitives into buckets based on centroid" ID="ID_152293924" CREATED="1485204278299" MODIFIED="1485204295796"/>
<node TEXT="Consider only partitions along bucket boundaries" ID="ID_1634997703" CREATED="1485204296362" MODIFIED="1485204319865"/>
<node TEXT="Use SAH to estimate quality of partition" ID="ID_497270159" CREATED="1485204320321" MODIFIED="1485204332802"/>
<node TEXT="Use the best available partition at each level" ID="ID_855928834" CREATED="1485204333073" MODIFIED="1485204341960"/>
</node>
<node TEXT="KD-Tree" ID="ID_919615900" CREATED="1485204391930" MODIFIED="1485204414737">
<attribute NAME="textbook" VALUE="04-04"/>
<node TEXT="Binary Space partitioning" ID="ID_1269107971" CREATED="1485204448747" MODIFIED="1485204460028"/>
<node TEXT="If there are too many primitives in a space it is divided in two" ID="ID_602371676" CREATED="1485204460475" MODIFIED="1485204476231"/>
<node TEXT="Dividing planes are axis aligned (with out this restriction you have an octtree)" ID="ID_315201797" CREATED="1485204476637" MODIFIED="1485204501390"/>
<node TEXT="If plane intersects a primitive that primative is associated with both partitions" ID="ID_1913855337" CREATED="1485204502436" MODIFIED="1485204525795"/>
</node>
<node TEXT="Construction" ID="ID_71200841" CREATED="1485204527366" MODIFIED="1485204818351">
<node TEXT="Similar to BVH" ID="ID_539817375" CREATED="1485204818354" MODIFIED="1485204825777"/>
<node TEXT="Prefer splits that leave no primitives on one side" ID="ID_821116788" CREATED="1485204826264" MODIFIED="1485204869819"/>
</node>
<node TEXT="Traversal" ID="ID_1554048746" CREATED="1485204998886" MODIFIED="1485205002773">
<node TEXT="Trace Rays through partitions (like bounding boxes)" ID="ID_306981698" CREATED="1485205007440" MODIFIED="1485205105920"/>
<node TEXT="Test primitives in low level partitions in spatial order" ID="ID_150793965" CREATED="1485205106255" MODIFIED="1485205121913"/>
</node>
</node>
</node>
</node>
</map>
