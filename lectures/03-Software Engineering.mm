<map version="0.9.0">
<!-- To view this file, download free mind mapping software FreeMind from http://freemind.sourceforge.net -->
<node CREATED="1430952274453" ID="ID_1419029305" MODIFIED="1430952327272" TEXT="03 - Software Engineering">
<attribute NAME="author" VALUE="Kenneth Sundberg"/>
<attribute NAME="date" VALUE=""/>
<attribute NAME="subtitle" VALUE="CS1400 - Lecture 03"/>
<node CREATED="1431976283378" ID="ID_1322895697" MODIFIED="1431976296953" POSITION="right" TEXT="Purpose">
<node CREATED="1431976298898" ID="ID_72778391" MODIFIED="1431976313835" TEXT="Complexity">
<node CREATED="1431976313835" ID="ID_1372040243" MODIFIED="1431976322515" TEXT="The Two Ways">
<node CREATED="1431542086802" ID="ID_1168173989" MODIFIED="1431542382162" TEXT="&quot;There are two ways of constructing a software design: One way is to make it so simple that there are obviously no deficiencies, and the other way is to make it so complicated that there are no obvious deficiencies.  The first method is far more difficult&quot; --C.A.R. Hoare"/>
</node>
<node CREATED="1431542470237" ID="ID_541766509" MODIFIED="1431542474017" TEXT="Humility">
<node CREATED="1431542474018" ID="ID_1614960218" MODIFIED="1431542515988" TEXT="&quot;The competent programmer is fully aware of the strictly limited size of his own skull; therefore he approaches the programming task in full humility, and amoung other things he avoids clever tricks like the plague.&quot; -- Edsger Dijkstra"/>
<node CREATED="1431542536437" ID="ID_17245134" MODIFIED="1431542574588" TEXT="&quot;Debugging is twice as hard as writing the code in the first place.  Therefore, if you write the code as cleverly as possible, you are, by definition, not smare enough to debug it.&quot; --Brian W. Kernighan"/>
</node>
<node CREATED="1431976616970" ID="ID_1353138146" MODIFIED="1431976622356" TEXT="Short Term Memory">
<node CREATED="1431976622357" ID="ID_819584455" MODIFIED="1431976646123" TEXT="Psycologists say you have a working memory of 3-7 items"/>
<node CREATED="1431976646442" ID="ID_241623550" MODIFIED="1431976657291" TEXT="fMRI shows a working memory of 4 items"/>
<node CREATED="1431976657722" ID="ID_922410571" MODIFIED="1431976687708" TEXT="If you write monolithic code more than 7 lines long it is beyond human comprehension">
<node CREATED="1431976689122" ID="ID_1150884052" MODIFIED="1431976702707" TEXT="Many good tools exist to work within this limitation"/>
</node>
<node CREATED="1431976789498" ID="ID_447217634" MODIFIED="1431976796842" TEXT="A computer is not nearly so limited use your tools"/>
</node>
</node>
<node CREATED="1431976392066" ID="ID_1839035005" MODIFIED="1431976397123" TEXT="Communication">
<node CREATED="1431976485778" ID="ID_570697475" MODIFIED="1431976489592" TEXT="Information Hiding">
<node CREATED="1431976495250" ID="ID_753275332" MODIFIED="1431976501559" TEXT="Not everyone needs to know everything"/>
<node CREATED="1431976501978" ID="ID_1865997660" MODIFIED="1431976512985" TEXT="Its hard to rely on what you don&apos;t know"/>
<node CREATED="1431976513306" ID="ID_973387226" MODIFIED="1431976522472" TEXT="Its easy to change things that arn&apos;t relied on"/>
<node CREATED="1431976536002" ID="ID_1755151397" MODIFIED="1431976560267" TEXT="Bugs flow along with information, protect yourself with good interfaces"/>
</node>
<node CREATED="1431976489970" ID="ID_128195360" MODIFIED="1431976494376" TEXT="Information Sharing">
<node CREATED="1431976576666" ID="ID_499226194" MODIFIED="1431976581824" TEXT="Somethings have to be shared"/>
<node CREATED="1431976582274" ID="ID_387467906" MODIFIED="1431976589752" TEXT="Some information must be communicated clearly"/>
<node CREATED="1431976590010" ID="ID_752935426" MODIFIED="1431976597703" TEXT="Good design promotes this"/>
</node>
</node>
<node CREATED="1430952633379" ID="ID_1345430208" MODIFIED="1430952638718" TEXT="Code Organization">
<node CREATED="1430952647379" ID="ID_65166687" MODIFIED="1431977310344" TEXT="Reuse together then release together">
<node CREATED="1431977132298" ID="ID_1891814585" MODIFIED="1431977136508" TEXT="What goes in a file?"/>
<node CREATED="1431977136754" ID="ID_1479819209" MODIFIED="1431977163397" TEXT="Things that are:">
<node CREATED="1431977147525" ID="ID_1824562441" MODIFIED="1431977169195" TEXT="Changed together"/>
<node CREATED="1431977169610" ID="ID_1142029379" MODIFIED="1431977174684" TEXT="Used together"/>
<node CREATED="1431977174922" ID="ID_1199891985" MODIFIED="1431977177865" TEXT="Released together"/>
</node>
<node CREATED="1431977179706" ID="ID_1983594682" MODIFIED="1431977197029" TEXT="If you can use one without the other they don&apos;t belong together"/>
</node>
<node CREATED="1430952638719" ID="ID_186518462" MODIFIED="1430952642353" TEXT="Header Files">
<node CREATED="1431976410362" ID="ID_1394184482" MODIFIED="1431976416988" TEXT="Communicate the interface of code"/>
<node CREATED="1431976417434" ID="ID_1512827899" MODIFIED="1431976430053" TEXT="To the extent possible hides implementation details">
<node CREATED="1431976430054" ID="ID_1105878482" MODIFIED="1431976441235" TEXT="Things that are hidden can be more easily changed"/>
</node>
<node CREATED="1431977324082" ID="ID_10354648" MODIFIED="1431977336314" TEXT="Can be included in multiple files">
<node CREATED="1431977336315" ID="ID_827176793" MODIFIED="1431977344768" TEXT="Include Guards needed"/>
</node>
</node>
<node CREATED="1430952642780" ID="ID_1544439193" MODIFIED="1430952646826" TEXT="Source Files">
<node CREATED="1431976446455" ID="ID_1458979042" MODIFIED="1431976453072" TEXT="Contain implementation"/>
<node CREATED="1431976453434" ID="ID_767563259" MODIFIED="1431976462283" TEXT="Limited in scope to a single task"/>
</node>
<node CREATED="1430952681516" ID="ID_195628954" MODIFIED="1430952683809" TEXT="CMake">
<node CREATED="1431977223042" ID="ID_1609602119" MODIFIED="1431977236115" TEXT="Somthing has to tell the compiler how to build all of these files"/>
<node CREATED="1431977237218" ID="ID_1552753643" MODIFIED="1431977242311" TEXT="Some options:">
<node CREATED="1431977242312" ID="ID_841494620" MODIFIED="1431977246032" TEXT="UNIX make files"/>
<node CREATED="1431977246450" ID="ID_282540826" MODIFIED="1431977254616" TEXT="Visual Studio project files"/>
<node CREATED="1431977256378" ID="ID_876373793" MODIFIED="1431977262296" TEXT="Eclipse project files"/>
<node CREATED="1431977262706" ID="ID_978714658" MODIFIED="1431977273680" TEXT="Cross-Platform Make"/>
</node>
</node>
<node CREATED="1431977280082" ID="ID_944225176" MODIFIED="1431977283347" TEXT="CMake Example"/>
</node>
</node>
<node CREATED="1431976739666" ID="ID_1842148797" MODIFIED="1431976742591" POSITION="right" TEXT="Principles">
<node CREATED="1431976144474" ID="ID_1877426316" MODIFIED="1431976148667" TEXT="Avoid Waste">
<node CREATED="1431976148668" ID="ID_194694876" MODIFIED="1431976153842" TEXT="Don&apos;t Overbuild">
<node CREATED="1431976967938" ID="ID_398386788" MODIFIED="1431976978776" TEXT="No code is easier to debug and is faster than some code"/>
<node CREATED="1431976979130" ID="ID_1593353391" MODIFIED="1431976991563" TEXT="Don&apos;t build code that you `might&apos; need"/>
</node>
<node CREATED="1431976155922" ID="ID_409076508" MODIFIED="1431976164004" TEXT="Decide at the last responsible moment">
<node CREATED="1431976995242" ID="ID_442046447" MODIFIED="1431977007176" TEXT="Default decision making is bad"/>
<node CREATED="1431977007426" ID="ID_565731085" MODIFIED="1431977026833" TEXT="Decide at the moment that continuing to fail to decide would eliminate options">
<node CREATED="1431977026834" ID="ID_893944415" MODIFIED="1431977041050" TEXT="Lets you make decisions with the most information possible"/>
<node CREATED="1431977041787" ID="ID_1058263504" MODIFIED="1431977063083" TEXT="Inexperience may lead you to need to decide earlier"/>
</node>
<node CREATED="1431977076274" ID="ID_1137126550" MODIFIED="1431977115693" TEXT="Some decisions are costly, but not impossible,to unmake">
<node CREATED="1431977115694" ID="ID_1795114436" MODIFIED="1431977124232" TEXT="Don&apos;t be afraid to commit"/>
</node>
</node>
</node>
<node CREATED="1430952335965" ID="ID_805498886" MODIFIED="1430952338632" TEXT="DRY">
<node CREATED="1431976856234" ID="ID_814408253" MODIFIED="1431976871961" TEXT="Don&apos;t Repeat Yourself">
<node CREATED="1431976871962" ID="ID_141338172" MODIFIED="1431976901552" TEXT="Don&apos;t do the same work twice">
<node CREATED="1431976909146" ID="ID_162764017" MODIFIED="1431976915784" TEXT="Each version will have its own unique bugs"/>
<node CREATED="1431976916042" ID="ID_1911504512" MODIFIED="1431976930712" TEXT="Bugs will only happen sometimes depending on which version is used"/>
</node>
<node CREATED="1431976940442" ID="ID_1925365321" MODIFIED="1431976951051" TEXT="Copy and Paste is a sign of very bad design">
<node CREATED="1431976959618" ID="ID_1682065068" MODIFIED="1431976963548" TEXT="Write a function instead"/>
</node>
</node>
</node>
</node>
<node CREATED="1431976743050" ID="ID_1202616080" MODIFIED="1431976745564" POSITION="right" TEXT="Tools">
<node CREATED="1430952407388" ID="ID_462060129" MODIFIED="1430952690434" TEXT="Functions">
<node CREATED="1430952338919" ID="ID_468530218" MODIFIED="1430952342410" TEXT="Pure Functions">
<node CREATED="1430952898155" ID="ID_1224200497" MODIFIED="1430952912816" TEXT="The closer your functions are to pure the easier they are to reason about"/>
<node CREATED="1430952913355" ID="ID_602135547" MODIFIED="1430952919867" TEXT="Pure functions are like math functions">
<node CREATED="1430952919867" ID="ID_871422145" MODIFIED="1430952928413" TEXT="Same input results in same output"/>
<node CREATED="1430952928755" ID="ID_1193912553" MODIFIED="1430952932068" TEXT="No side effects"/>
</node>
<node CREATED="1430952943691" ID="ID_1190006394" MODIFIED="1430952951563" TEXT="Some important functions can not be made to be pure"/>
</node>
<node CREATED="1430952342691" ID="ID_789441773" MODIFIED="1430952348247" TEXT="The Four Horsemen">
<node CREATED="1430952840899" ID="ID_977400696" MODIFIED="1430952846625" TEXT="Context"/>
<node CREATED="1430952846995" ID="ID_1525589247" MODIFIED="1430952851520" TEXT="Non-determinisim"/>
<node CREATED="1430952852491" ID="ID_1332373030" MODIFIED="1430952857969" TEXT="Error"/>
<node CREATED="1430952858412" ID="ID_1371993920" MODIFIED="1430952869855" TEXT="Destruction"/>
</node>
<node CREATED="1430952813339" ID="ID_1870975527" MODIFIED="1430952820144" TEXT="Contract Programming">
<node CREATED="1430952820987" ID="ID_1184112357" MODIFIED="1430952823505" TEXT="Preconditions"/>
<node CREATED="1430952827403" ID="ID_12807614" MODIFIED="1430952831402" TEXT="Post-conditions"/>
</node>
<node CREATED="1431977670674" ID="ID_222764260" MODIFIED="1431977672131" TEXT="Syntax">
<node CREATED="1431977687906" ID="ID_82909262" MODIFIED="1431977701500" TEXT="Name"/>
<node CREATED="1431977702058" ID="ID_741814542" MODIFIED="1431977704709" TEXT="Return Type"/>
<node CREATED="1431977705018" ID="ID_103526091" MODIFIED="1431977707528" TEXT="Parameters"/>
</node>
<node CREATED="1431977708986" ID="ID_1653124000" MODIFIED="1431977719040" TEXT="Definitions and Declarations">
<node CREATED="1431977725282" ID="ID_1844353295" MODIFIED="1431977731996" TEXT="Definitions - go in header file"/>
<node CREATED="1431977732378" ID="ID_793748326" MODIFIED="1431977738796" TEXT="Declarations - go in source file"/>
</node>
<node CREATED="1431977739722" ID="ID_171920948" MODIFIED="1431977745991" TEXT="Linker Errors">
<node CREATED="1431977745992" ID="ID_469824200" MODIFIED="1431977765880" TEXT="Linker Errors happen when you make a promise in a header file that you don&apos;t fulfill in a source file"/>
<node CREATED="1431977766506" ID="ID_1412533200" MODIFIED="1431977777532" TEXT="The linker error will state what function is missing">
<node CREATED="1431977777533" ID="ID_1840288859" MODIFIED="1431977805233" TEXT="Due to a process known as name-mangling it may require some interpretation"/>
<node CREATED="1431977814674" ID="ID_527063068" MODIFIED="1431977831594" TEXT="Somewhere in the mangled name you should be able to find the name that you gave the function"/>
</node>
</node>
</node>
<node CREATED="1430952458531" ID="ID_1424652943" MODIFIED="1431977654265" TEXT="Design Tools">
<node CREATED="1430952464478" ID="ID_169736980" MODIFIED="1430952467790" TEXT="Psuedocode">
<node CREATED="1431978432123" ID="ID_1550703231" MODIFIED="1431978444211" TEXT="Use english to describe the steps of your algorithim"/>
<node CREATED="1431978444610" ID="ID_372903971" MODIFIED="1431978452668" TEXT="You can do this with comments, then fill out the code below"/>
<node CREATED="1431978462163" ID="ID_285502207" MODIFIED="1431978468675" TEXT="Helps you to think through the problem"/>
</node>
<node CREATED="1430952468291" ID="ID_330735397" MODIFIED="1430952471329" TEXT="Flow charts">
<node CREATED="1431978470555" ID="ID_1517979569" MODIFIED="1431978485329" TEXT="Pictures can be more descriptive than words"/>
<node CREATED="1431978485626" ID="ID_1832402606" MODIFIED="1431978498472" TEXT="Especially with lots of decision points a flow chart may be best"/>
</node>
<node CREATED="1430952471699" ID="ID_526313540" MODIFIED="1430952489337" TEXT="Call Graphs">
<node CREATED="1431978500635" ID="ID_409822316" MODIFIED="1431978512101" TEXT="A graph where:">
<node CREATED="1431978512102" ID="ID_212366586" MODIFIED="1431978517067" TEXT="Every function is a vertex"/>
<node CREATED="1431978517362" ID="ID_1921324386" MODIFIED="1431978527280" TEXT="There is an edge from A to B if A calls B"/>
</node>
<node CREATED="1431978528266" ID="ID_1445516595" MODIFIED="1431978538217" TEXT="Help you see the structure of your program"/>
</node>
<node CREATED="1430952490012" ID="ID_1261287250" MODIFIED="1430952495752" TEXT="Data Flow Diagrams">
<node CREATED="1431978540834" ID="ID_1812559534" MODIFIED="1431978559696" TEXT="Take a bit of data&apos;s point of view as it goes through your system"/>
<node CREATED="1431978559994" ID="ID_174758737" MODIFIED="1431978563545" TEXT="Where does it enter"/>
<node CREATED="1431978563826" ID="ID_938557680" MODIFIED="1431978571728" TEXT="How is it transformed from input to output"/>
</node>
</node>
<node CREATED="1430952411099" ID="ID_1652512608" MODIFIED="1431976261963" TEXT="Refactoring">
<node CREATED="1431977408490" ID="ID_263111282" MODIFIED="1431977417750" TEXT="There are no good writers ...">
<node CREATED="1431977419029" ID="ID_1258517764" MODIFIED="1431977428984" TEXT="You won&apos;t get everything right the first time">
<node CREATED="1431977428985" ID="ID_284557488" MODIFIED="1431977439528" TEXT="Mature code has often been rewritten 4-8 times"/>
</node>
<node CREATED="1431977451474" ID="ID_924143054" MODIFIED="1431977473768" TEXT="Refactoring is taking code that works and writing it in a different way that works the same"/>
<node CREATED="1431977474338" ID="ID_1154823560" MODIFIED="1431977481136" TEXT="Need good tests to do this safely"/>
</node>
<node CREATED="1430952418158" ID="ID_1648242846" MODIFIED="1430952422160" TEXT="Extract Method">
<node CREATED="1431977486298" ID="ID_578805438" MODIFIED="1431977512884" TEXT="Take a bit of repeated or otherwise useful code out of one function and make another"/>
<node CREATED="1431977515658" ID="ID_174109550" MODIFIED="1431977523564" TEXT="The correct alternative to copy and paste"/>
<node CREATED="1431977529442" ID="ID_84781950" MODIFIED="1431977585640" TEXT="Eliminates implicit context by adding a scope"/>
<node CREATED="1431977586114" ID="ID_255147753" MODIFIED="1431977594488" TEXT="New function can be tested independently"/>
</node>
<node CREATED="1430952580579" ID="ID_1767812943" MODIFIED="1430952589837" TEXT="Rename">
<node CREATED="1431977602218" ID="ID_1918670781" MODIFIED="1431977608816" TEXT="Good names are key to good code"/>
<node CREATED="1431977609154" ID="ID_1701415744" MODIFIED="1431977621860" TEXT="You won&apos;t always get names right the first time"/>
<node CREATED="1431977622130" ID="ID_812377696" MODIFIED="1431977633313" TEXT="Don&apos;t be afraid to change a name">
<node CREATED="1431977633314" ID="ID_210930128" MODIFIED="1431977636684" TEXT="It can be tedious"/>
<node CREATED="1431977636882" ID="ID_676303708" MODIFIED="1431977645186" TEXT="Some IDEs have tools to do this for you"/>
</node>
</node>
</node>
</node>
</node>
</map>
