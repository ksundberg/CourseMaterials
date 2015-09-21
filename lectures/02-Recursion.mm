<map version="freeplane 1.2.0">
<!--To view this file, download free mind mapping software Freeplane from http://freeplane.sourceforge.net -->
<node TEXT="Recursion and Order Analysis" ID="ID_930749052" CREATED="1299179800922" MODIFIED="1439934050908">
<attribute NAME="Author" VALUE="Kenneth Sundberg"/>
<attribute NAME="subtitle" VALUE="CS 1410 -- Chapter 19"/>
<attribute NAME="date" VALUE=""/>
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
<node TEXT="Complexity Analysis" POSITION="right" ID="ID_1488829589" CREATED="1439934061106" MODIFIED="1439934070018">
<node TEXT="Comparing Algorithims" ID="ID_1887074853" CREATED="1439934071794" MODIFIED="1439934092315">
<node TEXT="Implementation Priorities" ID="ID_412020478" CREATED="1439934092321" MODIFIED="1439934113039">
<node TEXT="Correctness - Is correct output produced?" ID="ID_740308978" CREATED="1439934115338" MODIFIED="1439934163539"/>
<node TEXT="Complexity - How complex is the algorithim?" ID="ID_392751510" CREATED="1439934125873" MODIFIED="1439934188803">
<node TEXT="Cyclomatic Complexity" ID="ID_1760317103" CREATED="1439934188812" MODIFIED="1439934194215"/>
<node TEXT="Computational Complexity" ID="ID_888159301" CREATED="1439934194586" MODIFIED="1439934208379"/>
</node>
<node TEXT="Clarity - Does the algorithm achieve its goals in a straight-forward manner?" ID="ID_365374617" CREATED="1439934131361" MODIFIED="1439934239130"/>
<node TEXT="Efficiency - Does the algorithm do more work than is required?" ID="ID_1323657975" CREATED="1439934136346" MODIFIED="1439934254737"/>
<node TEXT="Performance - How quickly does the algorithm perform the required work?" ID="ID_908975550" CREATED="1439934139226" MODIFIED="1439934267359"/>
</node>
<node TEXT="Cyclomatic Complexity" ID="ID_353876762" CREATED="1440019572085" MODIFIED="1440019579261">
<node TEXT="Number of linearly independent paths through a function" ID="ID_993597455" CREATED="1440019579266" MODIFIED="1440019593562"/>
<node TEXT="Highly correlated with defects" ID="ID_1416263989" CREATED="1440019593988" MODIFIED="1440019666570"/>
<node TEXT="Keep it below 15 and preferably below 10" ID="ID_577073336" CREATED="1440019666820" MODIFIED="1440019696980"/>
</node>
<node TEXT="Computational Complexity" ID="ID_723770856" CREATED="1440023692823" MODIFIED="1440093471614">
<attribute NAME="textbook" VALUE="09-06"/>
<node TEXT="Measure of how much work an algorithm requires" ID="ID_1126026216" CREATED="1440023702329" MODIFIED="1440023718382"/>
<node TEXT="Big-O notation and friends the most common measurement" ID="ID_38582615" CREATED="1440023720239" MODIFIED="1440023759558"/>
</node>
</node>
<node TEXT="Big-O Notation" ID="ID_256807089" CREATED="1440023762799" MODIFIED="1440023808496">
<node TEXT="Big-O" ID="ID_482464415" CREATED="1440023808504" MODIFIED="1440023818736">
<node TEXT="$f(x) \in O(g(x)) iff \exists M \exists x_0 : f(x) \leq M g(x) \forall x &gt; x_0$" ID="ID_881285821" CREATED="1440023818744" MODIFIED="1440092738062"/>
</node>
<node TEXT="In Practice" ID="ID_241575953" CREATED="1440093232870" MODIFIED="1440093239068">
<node TEXT="Examine code to determine how many things must be done as a function of problem size" LOCALIZED_STYLE_REF="styles.topic" ID="ID_490755161" CREATED="1440093297047" MODIFIED="1440093345182"/>
<node TEXT="Simplification Rules:" ID="ID_80915292" CREATED="1440092930366" MODIFIED="1440092942238">
<node TEXT="Drop all but the highest growth term" ID="ID_64225282" CREATED="1440092942241" MODIFIED="1440092953596"/>
<node TEXT="Drop all constants" ID="ID_120651902" CREATED="1440092954030" MODIFIED="1440092961780"/>
</node>
</node>
<node TEXT="Common Classes" ID="ID_1754196741" CREATED="1440092965254" MODIFIED="1440092980183">
<node TEXT="$O(1)$ - Constant" ID="ID_303230079" CREATED="1440092980187" MODIFIED="1440093153797"/>
<node TEXT="$O(\log n)$ - Logarithmic" ID="ID_93781801" CREATED="1440093001286" MODIFIED="1440093148476"/>
<node TEXT="$O(n)$ - Linear" ID="ID_852996760" CREATED="1440093017526" MODIFIED="1440093140211"/>
<node TEXT="$O(n \log n)$ - Loglinear (other names)" ID="ID_226352205" CREATED="1440093030886" MODIFIED="1440093131966"/>
<node TEXT="$O(n^2)$ - Quadratic" ID="ID_929907916" CREATED="1440093051054" MODIFIED="1440093064756"/>
<node TEXT="$O(n^c), c &gt; 1$ - Polynomial" ID="ID_739026727" CREATED="1440093066222" MODIFIED="1440093097432"/>
<node TEXT="$O(c^n),c &gt; 1$ - Exponential" ID="ID_677862552" CREATED="1440093099014" MODIFIED="1440093123364"/>
</node>
</node>
</node>
<node TEXT="Recursion" POSITION="right" ID="ID_1403944028" CREATED="1440093600166" MODIFIED="1440093603940">
<node TEXT="Recursion" ID="ID_1994851168" CREATED="1299179806194" MODIFIED="1299179812910">
<node TEXT="Definition" ID="ID_1316665564" CREATED="1299180094200" MODIFIED="1440095102548">
<attribute NAME="textbook" VALUE="14-01"/>
<node TEXT="Many problems are defined in terms of themselves" ID="ID_1247535466" CREATED="1299180137785" MODIFIED="1299180146951">
<node TEXT="n! = n * (n-1)!" ID="ID_823867284" CREATED="1299180147185" MODIFIED="1299180160320"/>
<node TEXT="a*b = a+a*(b-1)" ID="ID_1365331428" CREATED="1299180160761" MODIFIED="1299180192000"/>
</node>
<node TEXT="Following the natural recursion of a problem leads to easier and better solutions" ID="ID_1545927960" CREATED="1299180194658" MODIFIED="1299180225097"/>
<node TEXT="Recursion and iteration are equivalent in capability" ID="ID_1519530862" CREATED="1299180228522" MODIFIED="1439848298059">
<node TEXT="Use whichever is most natural to the problem." ID="ID_1233415392" CREATED="1299180256231" MODIFIED="1299180265893"/>
</node>
</node>
<node TEXT="Process" ID="ID_890712723" CREATED="1299180098392" MODIFIED="1440095097830">
<attribute NAME="textbook" VALUE="14-04"/>
<node TEXT="Base Case" ID="ID_1265575995" CREATED="1299180103580" MODIFIED="1299180107734">
<node TEXT="A trivial case" ID="ID_479259321" CREATED="1299180271443" MODIFIED="1299180279866"/>
<node TEXT="A case so small there is no work left to be done" ID="ID_1377274641" CREATED="1299180280291" MODIFIED="1299180287768"/>
</node>
<node TEXT="Subdivide problem" ID="ID_1042063573" CREATED="1299180108088" MODIFIED="1299180117831">
<node TEXT="The problem needs to be divided into another instance of the problem" ID="ID_1222368390" CREATED="1299180288939" MODIFIED="1299180319169"/>
<node TEXT="Dividing in half tends to lead to the best performance" ID="ID_1740063507" CREATED="1299180320460" MODIFIED="1299180331354"/>
</node>
<node TEXT="Recursion" ID="ID_1192439432" CREATED="1299180118216" MODIFIED="1299180125642">
<node TEXT="One or more calls to the recursive function" ID="ID_1765314681" CREATED="1299180333724" MODIFIED="1299180342611"/>
<node TEXT="Fewer calls lead to better performance" ID="ID_1944245259" CREATED="1299180346453" MODIFIED="1299180353530"/>
</node>
<node TEXT="Combine Solutions" ID="ID_436309960" CREATED="1299180125856" MODIFIED="1299180130167"/>
</node>
<node TEXT="Complexity" ID="ID_620715653" CREATED="1440093679614" MODIFIED="1440093682982">
<node TEXT="Determining Big-O complexity of recursive algorithims can be challenging" ID="ID_841227784" CREATED="1440093682986" MODIFIED="1440093703253"/>
<node TEXT="Be especially careful of multiple recursive calls" ID="ID_1424248301" CREATED="1440093715159" MODIFIED="1440093728468"/>
<node TEXT="There is a technique called the ``Master Method&apos;&apos; that can be used to figure out complexity of any recursive algorithm." ID="ID_42281359" CREATED="1440093735847" MODIFIED="1440093772316"/>
<node TEXT="Its use is beyond the scope of this course" ID="ID_574942913" CREATED="1440093772814" MODIFIED="1440093782838"/>
</node>
</node>
</node>
<node TEXT="Examples of Recursion" POSITION="right" ID="ID_1077473866" CREATED="1299180005934" MODIFIED="1440093592471">
<node TEXT="Factorial" ID="ID_1509853009" CREATED="1439847160794" MODIFIED="1439847183031">
<node TEXT="Factorial - Definition" ID="ID_1161089311" CREATED="1439933872329" MODIFIED="1441061676569">
<attribute NAME="textbook" VALUE="14-02"/>
<node TEXT="$$n! = \prod_{i=1}^{n} i$$" ID="ID_752773206" CREATED="1439933888873" MODIFIED="1440014191181"/>
<node TEXT="$$n! = n  \times (n-1)!$$" ID="ID_1969981087" CREATED="1439933943930" MODIFIED="1440014262712"/>
</node>
<node TEXT="Recursive solution" LOCALIZED_STYLE_REF="styles.important" ID="ID_62968174" CREATED="1439933980026" MODIFIED="1440014480527">
<node TEXT="int factorial(int n)" ID="ID_160743658" CREATED="1440014435781" MODIFIED="1440014440381"/>
<node TEXT="{" ID="ID_375722353" CREATED="1440014440909" MODIFIED="1440014441882"/>
<node TEXT="  if(n &lt;= 0) return 1;" ID="ID_1249068854" CREATED="1440014442101" MODIFIED="1440014454346"/>
<node TEXT="  return factorial(n-1) * n;" ID="ID_295584596" CREATED="1440014454859" MODIFIED="1440014466029"/>
<node TEXT="}" ID="ID_1864969029" CREATED="1440014466509" MODIFIED="1440014469290"/>
</node>
<node TEXT="Analysis of solution" ID="ID_1314303453" CREATED="1441054452047" MODIFIED="1441054459009">
<node TEXT="How many steps does this algorithm take?" ID="ID_559993183" CREATED="1441054459016" MODIFIED="1441054469782"/>
<node TEXT="What order is it?" ID="ID_1947965251" CREATED="1441054470231" MODIFIED="1441054475095"/>
<node TEXT="How can it be improved?" ID="ID_972512813" CREATED="1441054475478" MODIFIED="1441054480803"/>
</node>
<node TEXT="Iterative solution" LOCALIZED_STYLE_REF="styles.important" ID="ID_212646772" CREATED="1439933966594" MODIFIED="1440014413986">
<node TEXT="int factorial(int n)" ID="ID_357984443" CREATED="1440014302340" MODIFIED="1440014310229"/>
<node TEXT="{" ID="ID_300075379" CREATED="1440014310941" MODIFIED="1440014312282"/>
<node TEXT="  auto result = 1;" ID="ID_195919590" CREATED="1440014312709" MODIFIED="1440014323442"/>
<node TEXT="  for(auto i=1;i&lt;=n;++i)" ID="ID_1303679653" CREATED="1440014323883" MODIFIED="1440014348045"/>
<node TEXT="  {" ID="ID_841203076" CREATED="1440014348493" MODIFIED="1440014350610"/>
<node TEXT="    result *= i;" ID="ID_300889464" CREATED="1440014351340" MODIFIED="1440014358562"/>
<node TEXT="  }" ID="ID_179535888" CREATED="1440014359005" MODIFIED="1440014361644"/>
<node TEXT="  return result;" ID="ID_574843690" CREATED="1440014362165" MODIFIED="1440014368450"/>
<node TEXT="}" ID="ID_812226925" CREATED="1440014368949" MODIFIED="1440014370541"/>
</node>
<node TEXT="Analysis of solution" ID="ID_688284431" CREATED="1441054452047" MODIFIED="1441054459009">
<node TEXT="How many steps does this algorithm take?" ID="ID_1463597623" CREATED="1441054459016" MODIFIED="1441054469782"/>
<node TEXT="What order is it?" ID="ID_299805272" CREATED="1441054470231" MODIFIED="1441054475095"/>
<node TEXT="How can it be improved?" ID="ID_36951296" CREATED="1441054475478" MODIFIED="1441054480803"/>
</node>
</node>
<node TEXT="GCD" ID="ID_1478517921" CREATED="1439848384883" MODIFIED="1440094510220">
<node TEXT="Greatest Common Divisor" ID="ID_1731200044" CREATED="1440094496990" MODIFIED="1440094505216">
<node TEXT="Given two integers find the largest integer that divides both evenly" ID="ID_1050608682" CREATED="1441052444665" MODIFIED="1441052461898"/>
<node TEXT="For convenience the smaller number will be listed second" ID="ID_1956153330" CREATED="1441053055829" MODIFIED="1441053071320"/>
</node>
<node TEXT="Subtraction Solution" ID="ID_344356744" CREATED="1441052463878" MODIFIED="1441053083600">
<hook URI="figures/euclid_subtraction.png" SIZE="1.0" NAME="ExternalObject"/>
<node TEXT="If a number divides A and B evenly" ID="ID_659181317" CREATED="1441052999294" MODIFIED="1441053010594"/>
<node TEXT="It must also divide (A-B) evenly" ID="ID_589486105" CREATED="1441053011013" MODIFIED="1441053022427"/>
</node>
<node TEXT="Modulo Solution" ID="ID_210497975" CREATED="1441052475237" MODIFIED="1441054027287">
<hook URI="figures/euclid_mod.png" SIZE="1.0" NAME="ExternalObject"/>
<node TEXT="A similar argument exists for (A mod B)" ID="ID_944168547" CREATED="1441054029999" MODIFIED="1441054053770"/>
</node>
<node TEXT="Euclid&apos;s Algorithm" LOCALIZED_STYLE_REF="styles.important" ID="ID_1412014222" CREATED="1440094407031" MODIFIED="1440094471679">
<attribute NAME="textbook" VALUE="14-03"/>
<node TEXT="int gcd(int x,int y)" ID="ID_1168107933" CREATED="1440094414299" MODIFIED="1440094422357"/>
<node TEXT="{" ID="ID_538881909" CREATED="1440094422851" MODIFIED="1440094424070"/>
<node TEXT="  if(x%y==0) return y;" ID="ID_319353692" CREATED="1440094424574" MODIFIED="1440094436748"/>
<node TEXT="  return gcd(y,x%y);" ID="ID_1538781479" CREATED="1440094437239" MODIFIED="1440094450109"/>
<node TEXT="}" ID="ID_50562964" CREATED="1440094450623" MODIFIED="1440094452716"/>
</node>
<node TEXT="Analysis of Euclid&apos;s Algorithm" ID="ID_713591293" CREATED="1441054085662" MODIFIED="1441054098310">
<node TEXT="How many steps does the algorithm take?" ID="ID_1672632956" CREATED="1441054098316" MODIFIED="1441054112659"/>
<node TEXT="What is the order of the algorithm?" ID="ID_539736158" CREATED="1441054113117" MODIFIED="1441054121246"/>
</node>
</node>
<node TEXT="Multiplication" ID="ID_1147841149" CREATED="1439847166362" MODIFIED="1440094522908">
<node TEXT="Define multiplication in terms of addition" ID="ID_1639969815" CREATED="1439847997176" MODIFIED="1440094535167">
<node TEXT="$$a \times b = \sum_{i=1}^{b} a$$" ID="ID_452246862" CREATED="1440094535959" MODIFIED="1440094676792"/>
<node TEXT="Like factorial this could lead to a linear algorithm" ID="ID_966325743" CREATED="1440094596967" MODIFIED="1440094610512"/>
<node TEXT="We can do better" ID="ID_646491256" CREATED="1440094610798" MODIFIED="1440094614634"/>
</node>
<node TEXT="Dividing the problem in half" ID="ID_1656291643" CREATED="1440094633046" MODIFIED="1440094639798">
<node TEXT="$$ a \times b =  a \times \frac{b}{2} + a \times \frac{b}{2}$$ if $b$ is even" ID="ID_339710504" CREATED="1440094639802" MODIFIED="1440094862584"/>
<node TEXT="$$ a \times b = a \times \frac{b}{2} + a \times \frac{b}{2} + a$$ if $b$ is odd" LOCALIZED_STYLE_REF="styles.topic" ID="ID_178473944" CREATED="1440094828176" MODIFIED="1440094989268"/>
<node TEXT="This algorithm is known as Egyptian Multiplication" ID="ID_302133121" CREATED="1440094918960" MODIFIED="1440094936648">
<node TEXT="It is perhaps the oldest known algorithm" ID="ID_664024094" CREATED="1440094937776" MODIFIED="1440094950808"/>
<node TEXT="It can be extended in many meaningful ways" ID="ID_1164425190" CREATED="1440094951183" MODIFIED="1440094964989"/>
<node TEXT="Its extensions are at the heart of modern encryption" ID="ID_953323575" CREATED="1440094965230" MODIFIED="1440094977031"/>
</node>
</node>
</node>
<node TEXT="Hanoi" ID="ID_1613392214" CREATED="1299179812911" MODIFIED="1441061705175">
<node TEXT="Towers of Hanoi" ID="ID_780588013" CREATED="1439847679354" MODIFIED="1439847686283">
<hook URI="figures/Hanoi.png" SIZE="0.25" NAME="ExternalObject"/>
<node TEXT="Move all discs from A to C" ID="ID_474284082" CREATED="1299180587881" MODIFIED="1299180598900">
<node TEXT="Only one disc can be moved at a time" ID="ID_1407370217" CREATED="1299180598901" MODIFIED="1299180606576"/>
<node TEXT="A larger disc can not be placed on a smaller disk" ID="ID_950225415" CREATED="1299180606849" MODIFIED="1299180616481"/>
</node>
</node>
<node TEXT="Solution:" ID="ID_432746651" CREATED="1299180667958" MODIFIED="1299180692600">
<node TEXT="How should this problem be solved?" ID="ID_1022508677" CREATED="1299180692601" MODIFIED="1299180704323"/>
</node>
<node TEXT="Recursive Solution:" ID="ID_1976694191" CREATED="1299180727046" MODIFIED="1439848459095">
<attribute NAME="textbook" VALUE="14-07"/>
<node TEXT="Move $n$ discs from A to C" ID="ID_1713675078" CREATED="1299180732185" MODIFIED="1299180789694">
<node TEXT="Move $n-1$ discs from A to B" ID="ID_830466996" CREATED="1299180769416" MODIFIED="1299180781649"/>
<node TEXT="Move disc from A to C" ID="ID_1226046627" CREATED="1299180790539" MODIFIED="1299180796850"/>
<node TEXT="Move $n-1$ discs from B to C" ID="ID_1483575735" CREATED="1299180797131" MODIFIED="1299180810971"/>
</node>
<node TEXT="How many steps for $n$ discs?" ID="ID_446847383" CREATED="1299180822316" MODIFIED="1299180833020"/>
</node>
<node TEXT="Hanoi Code" LOCALIZED_STYLE_REF="styles.important" ID="ID_381800737" CREATED="1440094080495" MODIFIED="1440094262133">
<node TEXT="void moveDisk(int n, std::string from," ID="ID_793285328" CREATED="1440094101187" MODIFIED="1442842699315"/>
<node TEXT="              std::string to, std::string other)" ID="ID_1230988816" CREATED="1442842672844" MODIFIED="1442842693128"/>
<node TEXT="{" ID="ID_1960202041" CREATED="1440094154270" MODIFIED="1440094155549"/>
<node TEXT="  if(n&lt;=0) return;" ID="ID_1199887003" CREATED="1440094156023" MODIFIED="1440094252412"/>
<node TEXT="  moveDisk(n-1,from,other,to);" ID="ID_277971833" CREATED="1440094172590" MODIFIED="1440094195324"/>
<node TEXT="  std::cout &lt;&lt; &quot;Move from &quot; &lt;&lt; from" ID="ID_1531832710" CREATED="1440094196222" MODIFIED="1440094329373"/>
<node TEXT="            &lt;&lt; &quot; to &quot; &lt;&lt; to &lt;&lt; std::endl;" ID="ID_657389465" CREATED="1440094303231" MODIFIED="1440094354567"/>
<node TEXT="  moveDisk(n-1,other,to,from);" ID="ID_674801532" CREATED="1440094225159" MODIFIED="1440094243352"/>
<node TEXT="}" ID="ID_1590241524" CREATED="1440094243862" MODIFIED="1440094246844"/>
</node>
</node>
<node TEXT="Maze" ID="ID_1085697973" CREATED="1299179822457" MODIFIED="1441061710792">
<node TEXT="Problem:" ID="ID_176516294" CREATED="1299180948794" MODIFIED="1299183800710">
<hook URI="figures/maze.png" SIZE="0.25" NAME="ExternalObject"/>
<node TEXT="Explorer starts at an arbitrary location" ID="ID_506228116" CREATED="1299180967362" MODIFIED="1299180979625"/>
<node TEXT="Find path to the treasure" ID="ID_1069332383" CREATED="1299180979866" MODIFIED="1299180986232"/>
</node>
<node TEXT="Solution:" ID="ID_595994675" CREATED="1299181000802" MODIFIED="1299181006444">
<node TEXT="Are any of the adjacent cells on the path?" ID="ID_1396391134" CREATED="1299181006445" MODIFIED="1299181042971"/>
<node TEXT="How do we avoid loops?" ID="ID_796338577" CREATED="1299181043437" MODIFIED="1299181049987"/>
<node TEXT="Note: Better path finding algorithms exist" ID="ID_764761019" CREATED="1441061909889" MODIFIED="1441061920800"/>
</node>
<node TEXT="Algorithim:" LOCALIZED_STYLE_REF="styles.important" ID="ID_1388605980" CREATED="1299181066200" MODIFIED="1440095196385">
<node TEXT="bool OnPath(Cell cell)" ID="ID_1354700238" CREATED="1299181069549" MODIFIED="1299181110513"/>
<node TEXT="{" ID="ID_1834511800" CREATED="1440095200816" MODIFIED="1440095202933"/>
<node TEXT="  if (cell == treasure) return true;" ID="ID_1210548023" CREATED="1299181092569" MODIFIED="1440095216128"/>
<node TEXT="  if (cell == wall) return false;" ID="ID_1913641605" CREATED="1299181121986" MODIFIED="1440095228480"/>
<node TEXT="  if (cell == explored) return false;" ID="ID_724947460" CREATED="1299181133090" MODIFIED="1440095239992"/>
<node TEXT="  cell = explored; //mark cell" ID="ID_1451232250" CREATED="1440095325672" MODIFIED="1440095337790"/>
<node TEXT="  for(auto&amp;&amp; adj:cell.adjacentCells())" ID="ID_16083079" CREATED="1440095259752" MODIFIED="1440095280599"/>
<node TEXT="  {" ID="ID_1886180413" CREATED="1440095281032" MODIFIED="1440095283528"/>
<node TEXT="    if(OnPath(adj)) return true;" ID="ID_989163105" CREATED="1440095289408" MODIFIED="1440095307320"/>
<node TEXT="  }" ID="ID_504716919" CREATED="1440095284136" MODIFIED="1440095285935"/>
<node TEXT="  return false;" ID="ID_1254364463" CREATED="1299181169355" MODIFIED="1440095255207"/>
<node TEXT="}" ID="ID_557401868" CREATED="1440095256208" MODIFIED="1440095257165"/>
</node>
</node>
</node>
</node>
</map>
