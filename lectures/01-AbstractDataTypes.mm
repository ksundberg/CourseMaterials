<map version="0.9.0">
<!-- To view this file, download free mind mapping software FreeMind from http://freemind.sourceforge.net -->
<node CREATED="1292602810896" ID="Freemind_Link_68755213" MODIFIED="1294183316214" TEXT="Abstract Data Types">
<attribute_layout VALUE_WIDTH="157"/>
<attribute NAME="theme" VALUE="Warsaw"/>
<attribute NAME="date" VALUE=""/>
<attribute NAME="author" VALUE="Kenneth Sundberg"/>
<attribute NAME="subtitle" VALUE="CS 1410 -- Chapter 11"/>
<node CREATED="1292602887302" ID="Freemind_Link_1199538202" MODIFIED="1294097936530" POSITION="right" TEXT="Purpose">
<node CREATED="1292602934245" ID="Freemind_Link_129679337" MODIFIED="1294097936531" TEXT="What is an ADT">
<node CREATED="1292603759919" ID="Freemind_Link_1158011342" MODIFIED="1294097936532" TEXT="What is Abstraction?">
<node CREATED="1292604070955" ID="Freemind_Link_53193319" MODIFIED="1292604096191" TEXT="An abstraction is a generalized model"/>
<node CREATED="1292604096651" ID="Freemind_Link_99670816" MODIFIED="1294097936534" TEXT="Example:">
<node CREATED="1292604104083" ID="Freemind_Link_113439728" MODIFIED="1292604110495" TEXT="Dog"/>
<node CREATED="1292604110891" ID="Freemind_Link_1159879507" MODIFIED="1292604112351" TEXT="Date"/>
<node CREATED="1292604112747" ID="Freemind_Link_1872003106" MODIFIED="1292604114991" TEXT="Person"/>
<node CREATED="1292604117499" ID="Freemind_Link_1772296718" MODIFIED="1292604119527" TEXT="Animal"/>
</node>
</node>
<node CREATED="1292603753061" ID="Freemind_Link_405850320" MODIFIED="1294097936535" TEXT="Definition">
<node CREATED="1292603797632" ID="Freemind_Link_1543330498" MODIFIED="1292603845652" TEXT="An Abstract Data Type is a type created by the programmer"/>
<node CREATED="1292603880625" ID="Freemind_Link_257812237" MODIFIED="1294097936537" TEXT="It contains:">
<node CREATED="1292603963339" ID="Freemind_Link_1529863994" MODIFIED="1292603994759" TEXT="set of preexisting data types"/>
<node CREATED="1292603995259" ID="Freemind_Link_1996624988" MODIFIED="1292604003711" TEXT="set of valid operations"/>
</node>
</node>
</node>
<node CREATED="1292603776744" ID="Freemind_Link_1519963036" MODIFIED="1294097936537" TEXT="Why use ADTs?">
<node CREATED="1292604159156" ID="Freemind_Link_1205207418" MODIFIED="1294097936538" TEXT="Why use abstraction?">
<node CREATED="1292604166004" ID="Freemind_Link_600799435" MODIFIED="1294097936539" TEXT="Divide and Conquer">
<node CREATED="1292604218965" ID="Freemind_Link_915281889" MODIFIED="1292604227568" TEXT="Good Problem Solving Strategy"/>
</node>
<node CREATED="1292604178108" ID="Freemind_Link_22792836" MODIFIED="1294097936540" TEXT="Simplifies code">
<node CREATED="1292604185716" ID="Freemind_Link_612269937" MODIFIED="1292604192936" TEXT="Less Error"/>
<node CREATED="1292604193140" ID="Freemind_Link_568614997" MODIFIED="1292604196504" TEXT="Faster Results"/>
<node CREATED="1292604196892" ID="Freemind_Link_62242235" MODIFIED="1292604204617" TEXT="Better Algorithims"/>
<node CREATED="1292604205157" ID="Freemind_Link_438925115" MODIFIED="1292604209288" TEXT="Easier Maintainance"/>
</node>
<node CREATED="1292605781579" ID="Freemind_Link_586636113" MODIFIED="1294097936541" TEXT="Information Hiding">
<node CREATED="1292605785451" ID="Freemind_Link_366257847" MODIFIED="1292605799583" TEXT="Implementation Details hidden from user"/>
<node CREATED="1292605822291" ID="Freemind_Link_1451864745" MODIFIED="1292605837265" TEXT="New programs can be designed without knowing details"/>
<node CREATED="1292605799963" ID="Freemind_Link_1546466802" MODIFIED="1292605818991" TEXT="Details can be changed without affecting user"/>
</node>
</node>
</node>
</node>
<node CREATED="1292626404151" ID="ID_1084085053" MODIFIED="1294097936543" POSITION="right" TEXT="Creating ADTs">
<node CREATED="1292602998710" ID="Freemind_Link_301459433" MODIFIED="1294097936544" TEXT="Declaration">
<node CREATED="1292604278332" ID="Freemind_Link_532767547" MODIFIED="1294097936556" TEXT="struct">
<node CREATED="1292626661840" ID="ID_1233962983" MODIFIED="1292627146663">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      <img src="structdate.png" scale="10%" />
    </p>
  </body>
</html></richcontent>
</node>
<node CREATED="1292977882367" ID="ID_819361727" MODIFIED="1292977888118" TEXT="Declare type"/>
<node CREATED="1292977888887" ID="ID_1198732866" MODIFIED="1292977899511" TEXT="Declare instances"/>
</node>
<node CREATED="1292604960308" ID="Freemind_Link_869549967" MODIFIED="1294097936561" TEXT="class">
<node CREATED="1292604963948" ID="Freemind_Link_82875368" MODIFIED="1292604980072" TEXT="struct is old fashioned"/>
<node CREATED="1292605024173" ID="Freemind_Link_1694184312" MODIFIED="1292605028376" TEXT="use class not struct"/>
<node CREATED="1292605028805" ID="Freemind_Link_1278524407" MODIFIED="1292605032345" TEXT="add public:"/>
<node CREATED="1292977811030" ID="ID_1344553592" MODIFIED="1292977830289">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <img src="classdate.png" />
  </body>
</html></richcontent>
</node>
</node>
<node CREATED="1292604400858" ID="Freemind_Link_310525138" MODIFIED="1294097936563" TEXT="Instances">
<node CREATED="1292604407506" ID="Freemind_Link_297323046" MODIFIED="1292604417774" TEXT="You can declare many instances of an ADT"/>
<node CREATED="1292604417962" ID="Freemind_Link_958126727" MODIFIED="1292604423966" TEXT="Date today, tomorrow;"/>
<node CREATED="1292604424162" ID="Freemind_Link_1806121368" MODIFIED="1294097936565" TEXT="ADT members">
<node CREATED="1292604441914" ID="Freemind_Link_927895323" MODIFIED="1292604444422" TEXT="month"/>
<node CREATED="1292604444619" ID="Freemind_Link_89259039" MODIFIED="1292604445566" TEXT="day"/>
<node CREATED="1292604445755" ID="Freemind_Link_1937082332" MODIFIED="1292604447495" TEXT="year"/>
</node>
<node CREATED="1292604451811" ID="Freemind_Link_1518336048" MODIFIED="1294097936565" TEXT="Instances">
<node CREATED="1292604456203" ID="Freemind_Link_1325883656" MODIFIED="1292604458198" TEXT="today"/>
<node CREATED="1292604459387" ID="Freemind_Link_1147902785" MODIFIED="1292604461527" TEXT="tomorrow"/>
</node>
</node>
<node CREATED="1292607080338" ID="Freemind_Link_1840803595" MODIFIED="1294097936566" TEXT="Enumerated Types">
<node CREATED="1292607086570" ID="Freemind_Link_1295904229" MODIFIED="1292607113310" TEXT="A data type that can only take a value from a predetermined set"/>
<node CREATED="1292607117995" ID="Freemind_Link_508211777" MODIFIED="1292607127609" TEXT="Useful for named constants"/>
</node>
</node>
<node CREATED="1292603037599" ID="Freemind_Link_1282739840" MODIFIED="1294097936567" TEXT="Initialization">
<node CREATED="1292605087569" ID="Freemind_Link_1506666939" MODIFIED="1294097936568" TEXT="Initialization">
<node CREATED="1292605096457" ID="Freemind_Link_228305795" MODIFIED="1292605120590" TEXT="Members can be initialized when an instance is declared"/>
<node CREATED="1292605208315" ID="Freemind_Link_662375323" MODIFIED="1294097936569" TEXT="Examples:">
<node COLOR="#cc6600" CREATED="1292605121034" ID="Freemind_Link_1542202139" MODIFIED="1292977600675" TEXT="Date today = \{&quot;Feb&quot;, 21, 2011\};"/>
<node COLOR="#cc6600" CREATED="1292605153755" ID="Freemind_Link_518704680" MODIFIED="1292977968186" TEXT="Date birthday = \{&quot;Mar&quot;,5\};"/>
<node COLOR="#cc6600" CREATED="1292605164723" ID="Freemind_Link_1263152060" MODIFIED="1292977977919" TEXT="Date summer = \{&quot;July&quot;\};"/>
</node>
<node CREATED="1292605220628" ID="Freemind_Link_1935217839" MODIFIED="1294097936569" TEXT="If one member is ommitted all following members must be omitted">
<node COLOR="#cc6600" CREATED="1292605274064" ID="Freemind_Link_792303233" MODIFIED="1292977987377" TEXT="Date today = \{&quot;Jan&quot;,,2011\};"/>
</node>
</node>
</node>
<node CREATED="1292603045607" ID="Freemind_Link_1621237655" MODIFIED="1294097936570" TEXT="Composites">
<node CREATED="1292603078487" ID="Freemind_Link_270113460" MODIFIED="1294097936576" TEXT="ADT Arrays">
<node CREATED="1292605345209" ID="Freemind_Link_596424513" MODIFIED="1292978336542" TEXT="Like other types, you can declare arrays of ADTs"/>
<node CREATED="1292978186956" ID="ID_278926883" MODIFIED="1292978191029">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <img src="ADTArray.png" />
  </body>
</html></richcontent>
</node>
</node>
<node CREATED="1292603083264" ID="Freemind_Link_1266134607" MODIFIED="1294097936581" TEXT="Nested ADTs">
<node CREATED="1292978279670" ID="ID_402654194" MODIFIED="1292978284844">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <img src="classReservation.png" />
  </body>
</html></richcontent>
</node>
<node CREATED="1292978308598" ID="ID_1239118232" MODIFIED="1292978331582" TEXT="Like other types, you can declare ADTs to be members of an ADT"/>
</node>
</node>
</node>
<node CREATED="1292602882318" ID="_" MODIFIED="1294097936583" POSITION="right" TEXT="Using ADTs">
<node CREATED="1292603021959" ID="Freemind_Link_1571756373" MODIFIED="1294097936584" TEXT="Operators">
<node CREATED="1292603012583" ID="Freemind_Link_358072499" MODIFIED="1294097936585" TEXT="Dot notation">
<node CREATED="1292604495916" ID="Freemind_Link_145576676" MODIFIED="1294097936587" TEXT="Dot notation">
<node CREATED="1292604502476" ID="Freemind_Link_75464767" MODIFIED="1292604522089" TEXT="Access to members through dot operator"/>
<node COLOR="#cc6600" CREATED="1292604522549" ID="Freemind_Link_718431032" MODIFIED="1292608203053" TEXT="Date today;&#xa;cin &gt;&gt; today.day &gt;&gt; today.month &gt;&gt; today.year;"/>
</node>
<node CREATED="1292604593302" ID="Freemind_Link_28090593" MODIFIED="1294097936588" TEXT="Dot represents membership">
<node CREATED="1292604610390" ID="Freemind_Link_1964115340" MODIFIED="1292604621823" TEXT="Think of . being equivalent to &apos;s"/>
<node CREATED="1292604652886" ID="Freemind_Link_1624560960" MODIFIED="1294097936593" TEXT="Examples:">
<node CREATED="1292604670118" ID="Freemind_Link_203165878" MODIFIED="1292604724221" TEXT="C++: cout &lt;&lt; today.day &lt;&lt; today.month;&#xa;&#xa;English: &quot;Output today&apos;s day then today&apos;s month&quot;"/>
<node CREATED="1292604730527" ID="Freemind_Link_1094263479" MODIFIED="1292604762201" TEXT="C++: today.day++;&#xa;&#xa;English: &quot;Increment today&apos;s day&quot;"/>
</node>
</node>
</node>
<node CREATED="1292604796272" ID="Freemind_Link_955006233" MODIFIED="1294097936594" TEXT="Other operators">
<node CREATED="1292604802048" ID="Freemind_Link_807196751" MODIFIED="1292604821668" TEXT="We have not yet defined any operations"/>
<node CREATED="1292604822513" ID="Freemind_Link_1621708099" MODIFIED="1294097936596" TEXT="These don&apos;t work">
<node CREATED="1292604837401" ID="Freemind_Link_389915379" MODIFIED="1292604842413" TEXT="cin &gt;&gt; today;"/>
<node CREATED="1292604842617" ID="Freemind_Link_408174576" MODIFIED="1292604849677" TEXT="tomorrow = today + 1;"/>
<node CREATED="1292604849841" ID="Freemind_Link_331908322" MODIFIED="1292604856861" TEXT="if (today &lt; tomorrow)"/>
</node>
<node CREATED="1292604863033" ID="Freemind_Link_51693246" MODIFIED="1292604895378" TEXT="We will cover defining operators later"/>
</node>
<node CREATED="1292604781216" ID="Freemind_Link_1043633651" MODIFIED="1294097936597" TEXT="Assignment operator">
<node CREATED="1292604904451" ID="Freemind_Link_1238942103" MODIFIED="1292604913647" TEXT="One operator is predefined"/>
<node CREATED="1292604914827" ID="Freemind_Link_1073937052" MODIFIED="1294097936597" TEXT="yesterday = today">
<node CREATED="1292604924851" ID="Freemind_Link_473570374" MODIFIED="1292604943519" TEXT="assigns all members of today to the corresponding member of yesterday"/>
</node>
</node>
</node>
<node CREATED="1292603162737" ID="Freemind_Link_167613805" MODIFIED="1294097936599" TEXT="Passing ADT">
<node CREATED="1292605665013" ID="Freemind_Link_1635055554" MODIFIED="1294097936603" TEXT="Passing an ADT instance">
<node CREATED="1292605679597" ID="Freemind_Link_1813090592" MODIFIED="1292605691163" TEXT="ADTs are passed like any other type"/>
<node CREATED="1292974954945" ID="ID_1850658746" MODIFIED="1292974964259">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <img src="payrate.png" />
  </body>
</html></richcontent>
</node>
</node>
<node CREATED="1292603215962" ID="Freemind_Link_988965829" MODIFIED="1294097936605" TEXT="Constant References">
<node CREATED="1292606501728" ID="Freemind_Link_37409504" MODIFIED="1292606505708" TEXT="ADTs can be large"/>
<node CREATED="1292606506384" ID="Freemind_Link_1474790329" MODIFIED="1292606518334" TEXT="Passing an ADT by value can reduce effeciency"/>
<node CREATED="1292606518952" ID="Freemind_Link_512476724" MODIFIED="1294097936605" TEXT="Pass by reference">
<node CREATED="1292606537641" ID="Freemind_Link_1901764641" MODIFIED="1292606544476" TEXT="Only passes a reference"/>
<node CREATED="1292606546529" ID="Freemind_Link_412849813" MODIFIED="1292606555493" TEXT="Possible to change argument"/>
</node>
</node>
<node CREATED="1292978512449" ID="ID_649214683" MODIFIED="1294097936611" TEXT="Pass by value">
<node CREATED="1292975314531" ID="ID_420924217" MODIFIED="1294097948207">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      <img src="someFuncByvalue.png" />
    </p>
  </body>
</html>
</richcontent>
</node>
<node CREATED="1292978559771" ID="ID_1419461608" MODIFIED="1292978567944" TEXT="Passes Person by value"/>
<node CREATED="1292978568417" ID="ID_1531517386" MODIFIED="1292978575994" TEXT="May be slow"/>
</node>
<node CREATED="1292606557377" ID="Freemind_Link_788747751" MODIFIED="1294097936615" TEXT="Pass by constant reference">
<node CREATED="1292975303932" ID="ID_874632908" MODIFIED="1294097954689">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      <img src="someFuncConstref.png" />
    </p>
  </body>
</html>
</richcontent>
</node>
<node CREATED="1292978581283" ID="ID_670031188" MODIFIED="1292978588369" TEXT="Passes Person as constant reference"/>
<node CREATED="1292978588993" ID="ID_1173658555" MODIFIED="1292978590563" TEXT="Fast"/>
<node CREATED="1292978591314" ID="ID_1946179889" MODIFIED="1292978597665" TEXT="Does not allows Person to be changed"/>
</node>
</node>
<node CREATED="1292603169689" ID="Freemind_Link_1976357612" MODIFIED="1294097936617" TEXT="Pointers">
<node CREATED="1292606648451" ID="Freemind_Link_307601948" MODIFIED="1294097936621" TEXT="Pointers to ADTs">
<node CREATED="1292606656139" ID="Freemind_Link_983583363" MODIFIED="1292606671775" TEXT="Pointers to ADT instances work like other data types"/>
<node COLOR="#cc6600" CREATED="1292606672571" ID="Freemind_Link_1286115955" MODIFIED="1294097960961">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      <img src="empPtr.png" />
    </p>
  </body>
</html>
</richcontent>
</node>
</node>
<node CREATED="1292606837161" ID="Freemind_Link_1224959795" MODIFIED="1294097936626" TEXT="Dynamic Allocation">
<node CREATED="1292606842872" ID="Freemind_Link_374990268" MODIFIED="1292606890334" TEXT="ADT instances can be dynamically allocated"/>
<node CREATED="1292606890841" ID="Freemind_Link_1369613275" MODIFIED="1292606899751" TEXT="Done the same as other types"/>
<node CREATED="1292978715189" ID="ID_156377736" MODIFIED="1292978718977">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <img src="ADTPointers.png" />
  </body>
</html></richcontent>
</node>
</node>
<node CREATED="1292603238490" ID="Freemind_Link_874196958" MODIFIED="1294097936627" TEXT="Arrow notation">
<node CREATED="1292606739555" ID="Freemind_Link_163319766" MODIFIED="1294097936628" TEXT="Members can be accessed through a pointer using dot notation">
<node COLOR="#cc6600" CREATED="1292606756579" ID="Freemind_Link_1259262515" MODIFIED="1292608157141" TEXT="cout &lt;&lt; (*ptr).name;"/>
</node>
<node CREATED="1292606766571" ID="Freemind_Link_275921295" MODIFIED="1294097936628" TEXT="Members can be accessed using arrow notation">
<node COLOR="#cc6600" CREATED="1292606778780" ID="Freemind_Link_363697061" MODIFIED="1292608160940" TEXT="cout &lt;&lt; ptr-&gt;name;"/>
</node>
</node>
<node CREATED="1292603295626" ID="Freemind_Link_853052940" MODIFIED="1294097936629" TEXT="Pointer Members">
<node CREATED="1292606961130" ID="Freemind_Link_1987021323" MODIFIED="1292606980968" TEXT="Data members can be pointers"/>
<node CREATED="1292606981748" ID="Freemind_Link_1744329479" MODIFIED="1294097936631" TEXT="This is dangerous">
<node CREATED="1292607017448" ID="Freemind_Link_190294187" MODIFIED="1292607029007" TEXT="Doesn&apos;t work with predefined operators"/>
<node CREATED="1292607161967" ID="Freemind_Link_976443866" MODIFIED="1292607170883" TEXT="Doesn&apos;t work with .read() or .write()"/>
<node CREATED="1292607029801" ID="Freemind_Link_1745091133" MODIFIED="1292607037932" TEXT="Wait until we know more"/>
</node>
<node CREATED="1292603303011" ID="Freemind_Link_1708425487" MODIFIED="1294097936631" TEXT="Issues with string">
<node CREATED="1292607058545" ID="Freemind_Link_16223266" MODIFIED="1292607065429" TEXT="String class contains a pointer"/>
<node CREATED="1292607066169" ID="Freemind_Link_552152934" MODIFIED="1292607075013" TEXT="Doesn&apos;t always work the way you would expect"/>
</node>
</node>
</node>
<node CREATED="1292603107711" ID="Freemind_Link_733267827" MODIFIED="1294097936633" TEXT="File Structure">
<node CREATED="1292603121960" ID="Freemind_Link_1182199080" MODIFIED="1294097936634" TEXT="Conventional File Structure">
<node CREATED="1292605874510" ID="Freemind_Link_1610491657" MODIFIED="1292605890571" TEXT="It is good style to create two files for each class"/>
<node CREATED="1292605891223" ID="Freemind_Link_1085872970" MODIFIED="1292605894212" TEXT="Header file"/>
<node CREATED="1292605903983" ID="Freemind_Link_1313299130" MODIFIED="1292605910011" TEXT="Code file"/>
<node CREATED="1292605964832" ID="Freemind_Link_304138869" MODIFIED="1292605975188" TEXT="class Person would be in Person.h and Person.cpp"/>
</node>
<node CREATED="1292603137728" ID="Freemind_Link_1242008807" MODIFIED="1294097936636" TEXT="Header Files">
<node CREATED="1292605912167" ID="Freemind_Link_1673516059" MODIFIED="1292605916259" TEXT=".h extension"/>
<node CREATED="1292605916951" ID="Freemind_Link_623208886" MODIFIED="1292605928115" TEXT="Contains the definition"/>
<node CREATED="1292605928784" ID="Freemind_Link_1173059588" MODIFIED="1292605933459" TEXT="Does not contain the implementation"/>
</node>
<node CREATED="1292606004625" ID="Freemind_Link_1519806403" MODIFIED="1294097936640" TEXT="Preprocessor guards">
<node CREATED="1292978819237" ID="ID_264626067" MODIFIED="1292978848424" TEXT="Must not include file multiple times"/>
<node CREATED="1292978848790" ID="ID_309902460" MODIFIED="1292978855368" TEXT="Use preprocessor macros"/>
<node COLOR="#cc6600" CREATED="1292606027681" ID="Freemind_Link_582142949" MODIFIED="1294097970577">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      <img src="preprocessorGuards.png" />
    </p>
  </body>
</html>
</richcontent>
</node>
</node>
<node CREATED="1292603148705" ID="Freemind_Link_408956804" MODIFIED="1294097936641" TEXT="Cpp Files">
<node CREATED="1292605935367" ID="Freemind_Link_1359738648" MODIFIED="1292605938740" TEXT=".cpp extension"/>
<node CREATED="1292605938960" ID="Freemind_Link_1406287107" MODIFIED="1292605944307" TEXT="Contains the implementation"/>
</node>
</node>
</node>
<node CREATED="1292606074403" ID="Freemind_Link_233001810" MODIFIED="1294097936642" POSITION="right" TEXT="Review">
<node CREATED="1292606077259" ID="Freemind_Link_1395017966" MODIFIED="1294097936643" TEXT="BubbleSort">
<node CREATED="1292606083891" ID="Freemind_Link_1928837657" MODIFIED="1294097936648" TEXT="Integer BubbleSort">
<node COLOR="#cc6600" CREATED="1292606102923" ID="Freemind_Link_704339326" MODIFIED="1294097452815">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      <img src="bubbleSortInt.png" />
    </p>
  </body>
</html>
</richcontent>
</node>
</node>
<node CREATED="1292603186809" ID="Freemind_Link_1720103020" MODIFIED="1294097936655" TEXT="ADT BubbleSort">
<node COLOR="#cc6600" CREATED="1292606295213" ID="Freemind_Link_924410776" MODIFIED="1294097463528">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      <img src="bubbleSortPerson.png" />
    </p>
  </body>
</html>
</richcontent>
</node>
</node>
</node>
<node CREATED="1292977378001" ID="ID_603433983" MODIFIED="1294097936656" TEXT="Swap">
<node CREATED="1292975931540" ID="ID_551303814" MODIFIED="1294097936662" TEXT="Integer Swap">
<node COLOR="#cc6600" CREATED="1292606422702" ID="Freemind_Link_462506343" MODIFIED="1294097512209">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      <img src="intSwap.png" />
    </p>
  </body>
</html>
</richcontent>
</node>
</node>
<node CREATED="1292606412702" ID="Freemind_Link_1584810960" MODIFIED="1294097936668" TEXT="ADT Swap">
<node COLOR="#cc6600" CREATED="1292606466599" ID="Freemind_Link_914334934" MODIFIED="1294097518449">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      <img src="personSwap.png" />
    </p>
  </body>
</html>
</richcontent>
</node>
</node>
</node>
</node>
</node>
</map>
