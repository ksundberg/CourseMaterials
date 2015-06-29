<map version="freeplane 1.2.0">
<!--To view this file, download free mind mapping software Freeplane from http://freeplane.sourceforge.net -->
<node TEXT="03 - Software Engineering" ID="ID_1419029305" CREATED="1430952274453" MODIFIED="1430952327272">
<attribute NAME="author" VALUE="Kenneth Sundberg"/>
<attribute NAME="date" VALUE=""/>
<attribute NAME="subtitle" VALUE="CS1400 - Lecture 03"/>
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
<node TEXT="Principles" POSITION="right" ID="ID_1322895697" CREATED="1431976283378" MODIFIED="1433039189659">
<node TEXT="Complexity" ID="ID_72778391" CREATED="1431976298898" MODIFIED="1431976313835">
<node TEXT="Style" ID="ID_256270475" CREATED="1433824953120" MODIFIED="1433824990292">
<attribute NAME="textbook" VALUE="2-17"/>
<node TEXT="In some ways programming is an art and leaves room for creative style" ID="ID_1807503895" CREATED="1433824996542" MODIFIED="1433825023570"/>
<node TEXT="Some people refer to style as the use of whitespace" ID="ID_1476288138" CREATED="1433825023942" MODIFIED="1433825047766">
<node TEXT="This is limiting and without value" ID="ID_1300723518" CREATED="1433825047782" MODIFIED="1433825056744"/>
<node TEXT="Just use clang-format for whitespace" ID="ID_98502964" CREATED="1433825057188" MODIFIED="1433825066183"/>
</node>
<node TEXT="Style is how you communicate semantic intent" ID="ID_1155538215" CREATED="1433825075875" MODIFIED="1433825124068"/>
</node>
<node TEXT="The Two Ways" ID="ID_1372040243" CREATED="1431976313835" MODIFIED="1433824960701">
<node TEXT="&quot;There are two ways of constructing a software design: One way is to make it so simple that there are obviously no deficiencies, and the other way is to make it so complicated that there are no obvious deficiencies.  The first method is far more difficult&quot; --C.A.R. Hoare" ID="ID_1168173989" CREATED="1431542086802" MODIFIED="1431542382162"/>
</node>
<node TEXT="Complexity" ID="ID_1515893605" CREATED="1433038914043" MODIFIED="1433038920324">
<node TEXT="Complexity is the Enemy" LOCALIZED_STYLE_REF="styles.topic" ID="ID_509237071" CREATED="1433038920339" MODIFIED="1435466256545"/>
<node TEXT="Watch out for:" LOCALIZED_STYLE_REF="styles.topic" ID="ID_1216034917" CREATED="1435466177265" MODIFIED="1435466256540">
<node TEXT="Computational Complexity" ID="ID_794784161" CREATED="1435466195663" MODIFIED="1435466201930"/>
<node TEXT="Semantic Complexity" ID="ID_319016294" CREATED="1435466202464" MODIFIED="1435466225954"/>
<node TEXT="Syntactic Complexity" ID="ID_13700322" CREATED="1435466226439" MODIFIED="1435466231506"/>
</node>
<node TEXT="Some complexity is irreducible" ID="ID_1251539923" CREATED="1435466236910" MODIFIED="1435466247500"/>
</node>
<node TEXT="Humility" ID="ID_541766509" CREATED="1431542470237" MODIFIED="1431542474017">
<node TEXT="&quot;The competent programmer is fully aware of the strictly limited size of his own skull; therefore he approaches the programming task in full humility, and amoung other things he avoids clever tricks like the plague.&quot; -- Edsger Dijkstra" LOCALIZED_STYLE_REF="styles.topic" ID="ID_1614960218" CREATED="1431542474018" MODIFIED="1433037189751"/>
<node TEXT="&quot;Debugging is twice as hard as writing the code in the first place.  Therefore, if you write the code as cleverly as possible, you are, by definition, not smart enough to debug it.&quot; --Brian W. Kernighan" ID="ID_17245134" CREATED="1431542536437" MODIFIED="1433037209674"/>
</node>
<node TEXT="Short Term Memory" ID="ID_1353138146" CREATED="1431976616970" MODIFIED="1431976622356">
<node TEXT="Psycologists say you have a working memory of 3-7 items" ID="ID_819584455" CREATED="1431976622357" MODIFIED="1431976646123"/>
<node TEXT="fMRI shows a working memory of 4 items" LOCALIZED_STYLE_REF="styles.topic" ID="ID_241623550" CREATED="1431976646442" MODIFIED="1433037248258"/>
<node TEXT="If you write monolithic code more than 7 lines long it is beyond human comprehension" ID="ID_922410571" CREATED="1431976657722" MODIFIED="1431976687708">
<node TEXT="Many good tools exist to work within this limitation" ID="ID_1150884052" CREATED="1431976689122" MODIFIED="1431976702707"/>
<node TEXT="Functions are your friend" ID="ID_1672733439" CREATED="1433037230325" MODIFIED="1433037236655"/>
</node>
<node TEXT="A computer is not nearly so limited -- use your tools" ID="ID_447217634" CREATED="1431976789498" MODIFIED="1435620924454"/>
</node>
<node TEXT="Don&apos;t Repeat Yourself" ID="ID_814408253" CREATED="1431976856234" MODIFIED="1431976871961">
<node TEXT="Don&apos;t do the same work twice" LOCALIZED_STYLE_REF="styles.topic" ID="ID_141338172" CREATED="1431976871962" MODIFIED="1433038980836">
<node TEXT="Each version will have its own unique bugs" ID="ID_162764017" CREATED="1431976909146" MODIFIED="1431976915784"/>
<node TEXT="Bugs will only happen sometimes depending on which version is used" ID="ID_1911504512" CREATED="1431976916042" MODIFIED="1431976930712"/>
</node>
<node TEXT="Copy and Paste is a sign of very bad design" ID="ID_1925365321" CREATED="1431976940442" MODIFIED="1431976951051">
<node TEXT="Write a function instead" ID="ID_1682065068" CREATED="1431976959618" MODIFIED="1431976963548"/>
</node>
</node>
<node TEXT="Don&apos;t Overbuild" ID="ID_194694876" CREATED="1431976148668" MODIFIED="1431976153842">
<node TEXT="No code is easier to debug and is faster than some code" ID="ID_398386788" CREATED="1431976967938" MODIFIED="1431976978776"/>
<node TEXT="Don&apos;t build code that you `might&apos; need" ID="ID_1593353391" CREATED="1431976979130" MODIFIED="1431976991563"/>
</node>
<node TEXT="Decide at the last responsible moment" ID="ID_409076508" CREATED="1431976155922" MODIFIED="1431976164004">
<node TEXT="Default decision making is bad" LOCALIZED_STYLE_REF="styles.topic" ID="ID_442046447" CREATED="1431976995242" MODIFIED="1435620995692"/>
<node TEXT="Decide at the moment that continuing to fail to decide would eliminate options" LOCALIZED_STYLE_REF="styles.topic" ID="ID_565731085" CREATED="1431977007426" MODIFIED="1435620995695">
<node TEXT="Lets you make decisions with the most information possible" ID="ID_893944415" CREATED="1431977026834" MODIFIED="1431977041050"/>
<node TEXT="Inexperience may lead you to need to decide earlier" ID="ID_1058263504" CREATED="1431977041787" MODIFIED="1431977063083"/>
</node>
<node TEXT="Some decisions are costly to unmake -- but not impossible" ID="ID_1137126550" CREATED="1431977076274" MODIFIED="1435620975581">
<node TEXT="Don&apos;t be afraid to commit" ID="ID_1795114436" CREATED="1431977115694" MODIFIED="1431977124232"/>
</node>
</node>
<node TEXT="Avoid Special Cases" ID="ID_817101577" CREATED="1433039053726" MODIFIED="1433039060567">
<node TEXT="There should be:" LOCALIZED_STYLE_REF="styles.topic" ID="ID_764223635" CREATED="1433039060580" MODIFIED="1433039149457">
<node TEXT="No exceptions" ID="ID_1610747657" CREATED="1433039068228" MODIFIED="1433039071199"/>
<node TEXT="One exception" ID="ID_651650763" CREATED="1433039071645" MODIFIED="1433039076173"/>
<node TEXT="Solution to the more general case" ID="ID_1965396214" CREATED="1433039076685" MODIFIED="1433039085901"/>
</node>
<node TEXT="When debugging don&apos;t assume that some input is special assume that your logic is flawed" ID="ID_591986870" CREATED="1433039119756" MODIFIED="1433039144476"/>
</node>
<node TEXT="Priorities" ID="ID_1069837863" CREATED="1435466329132" MODIFIED="1435466334933">
<node TEXT="Correctness" LOCALIZED_STYLE_REF="styles.topic" ID="ID_236948598" CREATED="1435466334947" MODIFIED="1435466579696">
<node TEXT="The code must be correct before anything else matters" ID="ID_175697511" CREATED="1435466417257" MODIFIED="1435466426667"/>
</node>
<node TEXT="Complexity" LOCALIZED_STYLE_REF="styles.topic" ID="ID_1935287792" CREATED="1435466351866" MODIFIED="1435466579694">
<node TEXT="The code is a complex as necessary, but no worse" ID="ID_953281033" CREATED="1435466439000" MODIFIED="1435466459287"/>
</node>
<node TEXT="Clarity" LOCALIZED_STYLE_REF="styles.topic" ID="ID_1786849546" CREATED="1435466355299" MODIFIED="1435466579691">
<node TEXT="The code is expressed in the most straightforward and readable way possible" ID="ID_1759500931" CREATED="1435466460591" MODIFIED="1435466477665"/>
</node>
<node TEXT="Efficiency" LOCALIZED_STYLE_REF="styles.topic" ID="ID_1161770352" CREATED="1435466433520" MODIFIED="1435466579687">
<node TEXT="The code performs no unnecessary work" ID="ID_13150369" CREATED="1435466479214" MODIFIED="1435466494025"/>
<node TEXT="Often a side effect of the first three priorities" ID="ID_1029400371" CREATED="1435466494606" MODIFIED="1435466506264"/>
</node>
<node TEXT="Performance" ID="ID_1199125301" CREATED="1435466359819" MODIFIED="1435466415258">
<node TEXT="The code performs the necessary work as quickly as possible" ID="ID_1382063270" CREATED="1435466507750" MODIFIED="1435466539533"/>
<node TEXT="Performance is rarely a concern -- but it can trump everything but correctness" ID="ID_117428471" CREATED="1435466539884" MODIFIED="1435466568742"/>
</node>
</node>
</node>
<node TEXT="Communication" ID="ID_1839035005" CREATED="1431976392066" MODIFIED="1431976397123">
<node TEXT="Information Hiding" ID="ID_570697475" CREATED="1431976485778" MODIFIED="1431976489592">
<node TEXT="Not everyone needs to know everything" LOCALIZED_STYLE_REF="styles.topic" ID="ID_753275332" CREATED="1431976495250" MODIFIED="1433038492784"/>
<node TEXT="Its hard to rely on what you don&apos;t know" LOCALIZED_STYLE_REF="styles.topic" ID="ID_1865997660" CREATED="1431976501978" MODIFIED="1433038492787"/>
<node TEXT="Its easy to change things that arn&apos;t relied on" LOCALIZED_STYLE_REF="styles.topic" ID="ID_973387226" CREATED="1431976513306" MODIFIED="1433038492780"/>
<node TEXT="Bugs flow along with information, protect yourself with good interfaces" ID="ID_1755151397" CREATED="1431976536002" MODIFIED="1431976560267"/>
</node>
<node TEXT="Information Sharing" ID="ID_128195360" CREATED="1431976489970" MODIFIED="1431976494376">
<node TEXT="Somethings have to be shared" ID="ID_499226194" CREATED="1431976576666" MODIFIED="1431976581824"/>
<node TEXT="Some information must be communicated clearly" ID="ID_387467906" CREATED="1431976582274" MODIFIED="1431976589752"/>
<node TEXT="Good design promotes this" ID="ID_752935426" CREATED="1431976590010" MODIFIED="1431976597703"/>
</node>
<node TEXT="Interfaces" ID="ID_696258564" CREATED="1433038513401" MODIFIED="1433038525675">
<node TEXT="Design interfaces first" LOCALIZED_STYLE_REF="styles.topic" ID="ID_727673070" CREATED="1433038580559" MODIFIED="1433038628594">
<node TEXT="What information must be shared" ID="ID_1123030830" CREATED="1433038586778" MODIFIED="1433038591607"/>
<node TEXT="How and in what formats" ID="ID_1236395273" CREATED="1433038591846" MODIFIED="1433038599110"/>
</node>
<node TEXT="Keep the surface area low" ID="ID_1541527336" CREATED="1433038525687" MODIFIED="1433038547296">
<node TEXT="Lots of small specialized interfaces are better than one large one" ID="ID_640909513" CREATED="1433038547309" MODIFIED="1433038568442"/>
<node TEXT="Less to test and verify" ID="ID_1654713197" CREATED="1433038572479" MODIFIED="1433038578617"/>
</node>
</node>
</node>
<node TEXT="Code Organization" ID="ID_1345430208" CREATED="1430952633379" MODIFIED="1430952638718">
<node TEXT="Reuse together then release together" ID="ID_65166687" CREATED="1430952647379" MODIFIED="1431977310344">
<node TEXT="What goes in a file?" LOCALIZED_STYLE_REF="styles.topic" ID="ID_1891814585" CREATED="1431977132298" MODIFIED="1433038649432"/>
<node TEXT="Things that are:" ID="ID_1479819209" CREATED="1431977136754" MODIFIED="1431977163397">
<node TEXT="Changed together" ID="ID_1824562441" CREATED="1431977147525" MODIFIED="1431977169195"/>
<node TEXT="Used together" ID="ID_1142029379" CREATED="1431977169610" MODIFIED="1431977174684"/>
<node TEXT="Released together" ID="ID_1199891985" CREATED="1431977174922" MODIFIED="1431977177865"/>
</node>
<node TEXT="If you can use one without the other they don&apos;t belong together" ID="ID_1983594682" CREATED="1431977179706" MODIFIED="1431977197029"/>
</node>
<node TEXT="Header Files" ID="ID_186518462" CREATED="1430952638719" MODIFIED="1430952642353">
<node TEXT="Communicate the interface of code" ID="ID_1394184482" CREATED="1431976410362" MODIFIED="1431976416988"/>
<node TEXT="Usually contains declarations, not definitions" ID="ID_518013254" CREATED="1433038697210" MODIFIED="1433038708794"/>
<node TEXT="To the extent possible hides implementation details" ID="ID_1512827899" CREATED="1431976417434" MODIFIED="1431976430053">
<node TEXT="Things that are hidden can be more easily changed" ID="ID_1105878482" CREATED="1431976430054" MODIFIED="1431976441235"/>
</node>
<node TEXT="Can be included in multiple files" ID="ID_10354648" CREATED="1431977324082" MODIFIED="1431977336314">
<node TEXT="Include Guards needed" ID="ID_827176793" CREATED="1431977336315" MODIFIED="1431977344768"/>
</node>
</node>
<node TEXT="Example" LOCALIZED_STYLE_REF="styles.important" ID="ID_203937412" CREATED="1433038713762" MODIFIED="1433038776040">
<node TEXT="#ifndef SOME_LONG_UNIQUE_IDENTIFIER" ID="ID_1164652924" CREATED="1433038718194" MODIFIED="1433038733346"/>
<node TEXT="#define SOME_LONG_UNIQUE_IDENTIFIER" ID="ID_1893265859" CREATED="1433038733921" MODIFIED="1433038743369"/>
<node TEXT="int foo(int,int);" ID="ID_354991157" CREATED="1433038743849" MODIFIED="1433038751972"/>
<node TEXT="double bar(double,int,bool);" ID="ID_368898957" CREATED="1433038752497" MODIFIED="1433038764961"/>
<node TEXT="#endif" ID="ID_1285619258" CREATED="1433038765488" MODIFIED="1433038768993"/>
</node>
<node TEXT="Source Files" ID="ID_1544439193" CREATED="1430952642780" MODIFIED="1430952646826">
<node TEXT="Contain implementation" ID="ID_1458979042" CREATED="1431976446455" MODIFIED="1431976453072"/>
<node TEXT="Limited in scope to a single task" ID="ID_767563259" CREATED="1431976453434" MODIFIED="1431976462283"/>
</node>
<node TEXT="Linker Errors" ID="ID_171920948" CREATED="1431977739722" MODIFIED="1431977745991">
<node TEXT="Linker Errors happen when you make a promise in a header file that you don&apos;t fulfill in a source file" ID="ID_469824200" CREATED="1431977745992" MODIFIED="1431977765880"/>
<node TEXT="The linker error will state what function is missing" ID="ID_1412533200" CREATED="1431977766506" MODIFIED="1431977777532">
<node TEXT="Due to a process known as name-mangling it may require some interpretation" ID="ID_1840288859" CREATED="1431977777533" MODIFIED="1431977805233"/>
<node TEXT="Somewhere in the mangled name you should be able to find the name that you gave the function" ID="ID_527063068" CREATED="1431977814674" MODIFIED="1431977831594"/>
</node>
</node>
<node TEXT="CMake" ID="ID_195628954" CREATED="1430952681516" MODIFIED="1430952683809">
<node TEXT="Somthing has to tell the compiler how to build all of these files" ID="ID_1609602119" CREATED="1431977223042" MODIFIED="1431977236115"/>
<node TEXT="Some options:" ID="ID_1552753643" CREATED="1431977237218" MODIFIED="1431977242311">
<node TEXT="UNIX make files" ID="ID_841494620" CREATED="1431977242312" MODIFIED="1431977246032"/>
<node TEXT="Visual Studio project files" ID="ID_282540826" CREATED="1431977246450" MODIFIED="1431977254616"/>
<node TEXT="Eclipse project files" ID="ID_876373793" CREATED="1431977256378" MODIFIED="1431977262296"/>
<node TEXT="Cross-Platform Make" ID="ID_978714658" CREATED="1431977262706" MODIFIED="1431977273680"/>
</node>
</node>
<node TEXT="CMake Example" LOCALIZED_STYLE_REF="styles.important" ID="ID_944225176" CREATED="1431977280082" MODIFIED="1435466840676">
<node TEXT="cmake_minimum_required (VERSION 2.8.11)" ID="ID_1134750223" CREATED="1435466729526" MODIFIED="1435466743862"/>
<node TEXT="project (HELLO)" ID="ID_207362516" CREATED="1435466744222" MODIFIED="1435466752007"/>
<node TEXT="add_executable(hello hello.cpp)" ID="ID_494623105" CREATED="1435466752493" MODIFIED="1435466778775"/>
</node>
</node>
</node>
<node TEXT="Tools" POSITION="right" ID="ID_1202616080" CREATED="1431976743050" MODIFIED="1431976745564">
<node TEXT="Functions" ID="ID_462060129" CREATED="1430952407388" MODIFIED="1430952690434">
<node TEXT="Pure Functions" ID="ID_468530218" CREATED="1430952338919" MODIFIED="1433826259568">
<attribute NAME="textbook" VALUE="6-01"/>
<node TEXT="The closer your functions are to pure the easier they are to reason about" ID="ID_1224200497" CREATED="1430952898155" MODIFIED="1430952912816"/>
<node TEXT="Pure functions are like math functions" ID="ID_602135547" CREATED="1430952913355" MODIFIED="1430952919867">
<node TEXT="Same input results in same output" ID="ID_871422145" CREATED="1430952919867" MODIFIED="1430952928413"/>
<node TEXT="No side effects" ID="ID_1193912553" CREATED="1430952928755" MODIFIED="1430952932068"/>
</node>
<node TEXT="Some important functions can not be made pure" ID="ID_1190006394" CREATED="1430952943691" MODIFIED="1435621502511"/>
</node>
<node TEXT="The Four Horsemen" ID="ID_789441773" CREATED="1430952342691" MODIFIED="1430952348247">
<node TEXT="Context" LOCALIZED_STYLE_REF="styles.topic" ID="ID_977400696" CREATED="1430952840899" MODIFIED="1433039734230">
<node TEXT="Some functions rely on context" ID="ID_1758855494" CREATED="1433039740414" MODIFIED="1433039773616"/>
<node TEXT="This can be eliminated by passing context as a parameter" ID="ID_1861629649" CREATED="1433039774020" MODIFIED="1433039808764"/>
<node TEXT="Its a judgment call whether the increased interface complexity is worth functional purity" ID="ID_253296630" CREATED="1435621527488" MODIFIED="1435621555253"/>
</node>
<node TEXT="Non-determinisim" LOCALIZED_STYLE_REF="styles.topic" ID="ID_1525589247" CREATED="1430952846995" MODIFIED="1433039734234">
<node TEXT="Some functions don&apos;t always return the same result" ID="ID_936840638" CREATED="1433039818267" MODIFIED="1433039831402"/>
<node TEXT="Example: rolling a die" ID="ID_1687823350" CREATED="1433039831907" MODIFIED="1433039838284"/>
</node>
<node TEXT="Error" LOCALIZED_STYLE_REF="styles.topic" ID="ID_1332373030" CREATED="1430952852491" MODIFIED="1433039734237">
<node TEXT="Some functions can have errors" ID="ID_893104307" CREATED="1433039846762" MODIFIED="1433039861636"/>
<node TEXT="Error handling is a complex topic" ID="ID_1721009515" CREATED="1433039862690" MODIFIED="1433039868802"/>
</node>
<node TEXT="Destruction" ID="ID_1371993920" CREATED="1430952858412" MODIFIED="1430952869855">
<node TEXT="Some functions can not be undone" ID="ID_1298978368" CREATED="1433039870513" MODIFIED="1433039890459"/>
<node TEXT="Output is critical and destructive" ID="ID_1492296977" CREATED="1433039890977" MODIFIED="1433039909857"/>
</node>
</node>
<node TEXT="Using &lt;random&gt;" LOCALIZED_STYLE_REF="styles.important" ID="ID_1262510173" CREATED="1435465770869" MODIFIED="1435465955371">
<node TEXT="#include &lt;random&gt;" ID="ID_1506661061" CREATED="1435465806518" MODIFIED="1435465817104"/>
<node TEXT="int roll()" ID="ID_175156756" CREATED="1435465817710" MODIFIED="1435465848854"/>
<node TEXT="{" ID="ID_1503923806" CREATED="1435465849373" MODIFIED="1435465850607"/>
<node TEXT="  static std::random_device rd;" ID="ID_1773997879" CREATED="1435465851285" MODIFIED="1435465894037"/>
<node TEXT="  static std::mt19937 engine(rd());" ID="ID_1924339745" CREATED="1435465894635" MODIFIED="1435465917276"/>
<node TEXT="  std::uniform_int_distribution&lt;&gt; die(1,6);" ID="ID_971173036" CREATED="1435465917729" MODIFIED="1435465939908"/>
<node TEXT="  return die(engine);" ID="ID_271928656" CREATED="1435465940545" MODIFIED="1435465946970"/>
<node TEXT="}" ID="ID_943100966" CREATED="1435465947345" MODIFIED="1435465950186"/>
</node>
<node TEXT="Contract Programming" ID="ID_1870975527" CREATED="1430952813339" MODIFIED="1430952820144">
<node TEXT="Preconditions" ID="ID_1184112357" CREATED="1430952820987" MODIFIED="1430952823505">
<node TEXT="The expectations that must be true before a function is called" ID="ID_1963781626" CREATED="1433039925479" MODIFIED="1433039945951"/>
</node>
<node TEXT="Post-conditions" ID="ID_12807614" CREATED="1430952827403" MODIFIED="1430952831402">
<node TEXT="What is true after a function is called" ID="ID_1874553240" CREATED="1433039947102" MODIFIED="1433039956177"/>
</node>
<node TEXT="This style can help write tests and to think about functions" ID="ID_1285941881" CREATED="1433039956942" MODIFIED="1433039967016"/>
</node>
<node TEXT="Scope" ID="ID_1651419366" CREATED="1433826290841" MODIFIED="1433826445926">
<attribute NAME="textbook" VALUE="6-10"/>
<node TEXT="Created using \{ and \}" ID="ID_1793526350" CREATED="1433826391422" MODIFIED="1435621880895"/>
<node TEXT="Local Values" ID="ID_1092413372" CREATED="1433826332325" MODIFIED="1433826360969">
<node TEXT="Declared in this scope" ID="ID_1048057846" CREATED="1433826360983" MODIFIED="1433826368382"/>
<node TEXT="Only exist within scope" ID="ID_1780516350" CREATED="1433826369607" MODIFIED="1433826389977"/>
</node>
<node TEXT="Non-local" ID="ID_317043670" CREATED="1433826455171" MODIFIED="1433826460654">
<node TEXT="Declared in enclosing scope" ID="ID_796266238" CREATED="1433826460664" MODIFIED="1433826466901"/>
<node TEXT="The outermost scope is the global scope" ID="ID_185823858" CREATED="1433826467467" MODIFIED="1433826476920"/>
<node TEXT="Declaring non-const variables in the global scope is EVIL" ID="ID_588433262" CREATED="1433826477502" MODIFIED="1435621854128"/>
</node>
<node TEXT="Static Values" ID="ID_1253064191" CREATED="1435622120675" MODIFIED="1435622127482">
<node TEXT="Created first time scope is entered" ID="ID_1549783391" CREATED="1435622127489" MODIFIED="1435622137424"/>
<node TEXT="Not destroyed on exit" ID="ID_1446196726" CREATED="1435622137688" MODIFIED="1435622158217">
<node TEXT="Implicitly couples every entry of a scope with every other entry" ID="ID_1670166322" CREATED="1435622158222" MODIFIED="1435622175096"/>
<node TEXT="Should be used with caution -- usually not the right choice" ID="ID_1711071446" CREATED="1435622175400" MODIFIED="1435622192136"/>
</node>
</node>
</node>
</node>
<node TEXT="Design Tools" ID="ID_1424652943" CREATED="1430952458531" MODIFIED="1431977654265">
<node TEXT="Psuedocode" ID="ID_169736980" CREATED="1430952464478" MODIFIED="1433809543463">
<attribute NAME="textbook" VALUE="1-06"/>
<node TEXT="Use english to describe the steps of your algorithim" ID="ID_1550703231" CREATED="1431978432123" MODIFIED="1431978444211"/>
<node TEXT="You can do this with comments, then fill out the code below" ID="ID_372903971" CREATED="1431978444610" MODIFIED="1431978452668"/>
<node TEXT="Helps you to think through the problem" ID="ID_285502207" CREATED="1431978462163" MODIFIED="1431978468675"/>
</node>
<node TEXT="Flow charts" ID="ID_330735397" CREATED="1430952468291" MODIFIED="1430952471329">
<node TEXT="Pictures can be more descriptive than words" ID="ID_1517979569" CREATED="1431978470555" MODIFIED="1431978485329"/>
<node TEXT="Especially with lots of decision points a flow chart may be best" ID="ID_1832402606" CREATED="1431978485626" MODIFIED="1431978498472"/>
</node>
<node TEXT="Call Graphs" ID="ID_526313540" CREATED="1430952471699" MODIFIED="1430952489337">
<node TEXT="A graph where:" ID="ID_409822316" CREATED="1431978500635" MODIFIED="1431978512101">
<node TEXT="Every function is a vertex" ID="ID_212366586" CREATED="1431978512102" MODIFIED="1431978517067"/>
<node TEXT="There is an edge from A to B if A calls B" ID="ID_1921324386" CREATED="1431978517362" MODIFIED="1431978527280"/>
</node>
<node TEXT="Help you see the structure of your program" ID="ID_1445516595" CREATED="1431978528266" MODIFIED="1431978538217"/>
<node TEXT="Top-Down design tends to produce this graph" ID="ID_1779399121" CREATED="1435621949728" MODIFIED="1435621964104"/>
</node>
<node TEXT="Data Flow Diagrams" ID="ID_1261287250" CREATED="1430952490012" MODIFIED="1430952495752">
<node TEXT="Take a bit of data&apos;s point of view as it goes through your system" ID="ID_1812559534" CREATED="1431978540834" MODIFIED="1431978559696"/>
<node TEXT="Where does it enter" ID="ID_174758737" CREATED="1431978559994" MODIFIED="1431978563545"/>
<node TEXT="How is it transformed from input to output" ID="ID_938557680" CREATED="1431978563826" MODIFIED="1431978571728"/>
</node>
<node TEXT="Comments" ID="ID_954427498" CREATED="1433824907032" MODIFIED="1433824929092">
<attribute NAME="textbook" VALUE="2-16"/>
<node TEXT="Comments are removed during preprocessing" ID="ID_913697769" CREATED="1433825130970" MODIFIED="1433825140317"/>
<node TEXT="They are only intended for human readers (probably future you)" LOCALIZED_STYLE_REF="styles.topic" ID="ID_1430690587" CREATED="1433825140840" MODIFIED="1435621994499"/>
<node TEXT="Used sparingly a powerful element of style" ID="ID_521567796" CREATED="1433825165713" MODIFIED="1433825185066"/>
<node TEXT="Lots of comments is symptomatic of bad code" ID="ID_293517347" CREATED="1433825185959" MODIFIED="1433825194705">
<node TEXT="Why does it need so much explanation?" ID="ID_539873742" CREATED="1433825194712" MODIFIED="1433825202906"/>
</node>
</node>
</node>
<node TEXT="Refactoring" ID="ID_1652512608" CREATED="1430952411099" MODIFIED="1431976261963">
<node TEXT="There are no good writers ..." ID="ID_263111282" CREATED="1431977408490" MODIFIED="1431977417750">
<node TEXT="You won&apos;t get everything right the first time" ID="ID_1258517764" CREATED="1431977419029" MODIFIED="1431977428984">
<node TEXT="Mature code has often been rewritten 4-8 times" ID="ID_284557488" CREATED="1431977428985" MODIFIED="1431977439528"/>
</node>
<node TEXT="Refactoring is taking code that works and writing it in a different way that works the same" ID="ID_924143054" CREATED="1431977451474" MODIFIED="1431977473768"/>
<node TEXT="Need good tests to do this safely" ID="ID_1154823560" CREATED="1431977474338" MODIFIED="1431977481136"/>
</node>
<node TEXT="Extract Method" ID="ID_1648242846" CREATED="1430952418158" MODIFIED="1430952422160">
<node TEXT="Take a bit of repeated or otherwise useful code out of one function and make another" ID="ID_578805438" CREATED="1431977486298" MODIFIED="1431977512884"/>
<node TEXT="The correct alternative to copy and paste" ID="ID_174109550" CREATED="1431977515658" MODIFIED="1431977523564"/>
<node TEXT="Eliminates implicit context by adding a scope" ID="ID_84781950" CREATED="1431977529442" MODIFIED="1431977585640"/>
<node TEXT="New function can be tested independently" ID="ID_255147753" CREATED="1431977586114" MODIFIED="1431977594488"/>
</node>
<node TEXT="Rename" ID="ID_1767812943" CREATED="1430952580579" MODIFIED="1430952589837">
<node TEXT="Good names are key to good code" ID="ID_1918670781" CREATED="1431977602218" MODIFIED="1431977608816"/>
<node TEXT="You won&apos;t always get names right the first time" ID="ID_1701415744" CREATED="1431977609154" MODIFIED="1431977621860"/>
<node TEXT="Don&apos;t be afraid to change a name" ID="ID_812377696" CREATED="1431977622130" MODIFIED="1431977633313">
<node TEXT="It can be tedious" ID="ID_210930128" CREATED="1431977633314" MODIFIED="1431977636684"/>
<node TEXT="Some IDEs have tools to do this for you" ID="ID_676303708" CREATED="1431977636882" MODIFIED="1431977645186"/>
</node>
</node>
</node>
</node>
</node>
</map>
