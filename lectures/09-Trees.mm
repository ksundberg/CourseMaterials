<map version="0.9.0">
<!-- To view this file, download free mind mapping software FreeMind from http://freemind.sourceforge.net -->
<node CREATED="1300905623412" ID="ID_566861398" MODIFIED="1301069420097" TEXT="Trees">
<attribute NAME="author" VALUE="Kenneth Sundberg"/>
<attribute NAME="subtitle" VALUE="CS 1410 -- Chapter 20"/>
<attribute NAME="date" VALUE=""/>
<node CREATED="1300905629992" FOLDED="true" ID="ID_673279941" MODIFIED="1304360761195" POSITION="right" TEXT="Binary Search Trees">
<node CREATED="1301068716810" ID="ID_431711380" MODIFIED="1301068723505" TEXT="Purpose">
<node CREATED="1301070257218" ID="ID_1871927369" MODIFIED="1301070281841" TEXT="A Sorted Data Structure">
<node CREATED="1301070285883" ID="ID_758106511" MODIFIED="1301070310081" TEXT="It is more efficient to find information if data is sorted"/>
<node CREATED="1301070310443" ID="ID_770710559" MODIFIED="1301070329249" TEXT="Many applications need sorted data"/>
</node>
<node CREATED="1300905682469" ID="ID_632653566" MODIFIED="1300905692981" TEXT="Sorted Insertion">
<node CREATED="1300905692983" ID="ID_575125295" MODIFIED="1300905708325" TEXT="Linked List">
<node CREATED="1300905773418" ID="ID_659334626" MODIFIED="1300905784951" TEXT="Uses Linear Search"/>
<node CREATED="1300905708327" ID="ID_502824957" MODIFIED="1300905857419" TEXT="$O(n)$"/>
<node CREATED="1300905756954" ID="ID_192110172" MODIFIED="1300905766556" TEXT="Equivalent to Insertion Sort"/>
</node>
<node CREATED="1300905788762" ID="ID_979267507" MODIFIED="1300905794052" TEXT="Binary Search Tree">
<node CREATED="1300905794053" ID="ID_1171915265" MODIFIED="1300905799222" TEXT="Uses Binary Search"/>
<node CREATED="1300905799576" ID="ID_1548234315" MODIFIED="1300905850984" TEXT="$O(\log n)$"/>
<node CREATED="1300905810333" ID="ID_1801278308" MODIFIED="1300905830389" TEXT="Related to Quick Sort"/>
</node>
</node>
<node CREATED="1300905874407" ID="ID_675384963" MODIFIED="1300905894647" TEXT="Binary Search vs. Linear Search">
<node CREATED="1300905898483" ID="ID_725910460" MODIFIED="1300905903032" TEXT="Linear Search">
<node CREATED="1300905903034" ID="ID_44726351" MODIFIED="1300905913713" TEXT="Check item"/>
<node CREATED="1300905914139" ID="ID_351743677" MODIFIED="1300905917779" TEXT="Check next item"/>
<node CREATED="1300905918925" ID="ID_1722983876" MODIFIED="1300905934468" TEXT="Done in linked list with \emph{one} next pointer"/>
</node>
<node CREATED="1300905935493" ID="ID_50344684" MODIFIED="1300905945093" TEXT="Binary Search">
<node CREATED="1300905945095" ID="ID_1613138394" MODIFIED="1300905951916" TEXT="Check item"/>
<node CREATED="1300905985486" ID="ID_1578486283" MODIFIED="1300906428316" TEXT="Check next item">
<node CREATED="1300905964500" ID="ID_138515807" MODIFIED="1300905970822" TEXT="If too large check left list"/>
<node CREATED="1300905952654" ID="ID_669097490" MODIFIED="1300905964283" TEXT="If too small check right list"/>
</node>
<node CREATED="1300905999118" ID="ID_871438800" MODIFIED="1300906025601" TEXT="Done in binary search tree with \emph{two} pointers, left and right"/>
</node>
</node>
</node>
<node CREATED="1301068741943" ID="ID_492036574" MODIFIED="1301068744360" TEXT="Structure">
<node CREATED="1300906029444" ID="ID_1160454150" MODIFIED="1300906040070" TEXT="BST.h">
<node CREATED="1300906340709" ID="ID_480154316" MODIFIED="1300906386061">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <img src="BSTHeader.png" />
  </body>
</html></richcontent>
</node>
</node>
</node>
<node CREATED="1300917584698" ID="ID_1894210996" MODIFIED="1301069213228" TEXT="Insertion">
<node CREATED="1301070186601" FOLDED="true" ID="ID_1540039357" MODIFIED="1301070215607" TEXT="Algorithim">
<node CREATED="1301070194966" ID="ID_753531768" MODIFIED="1301070203883">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <img src="BSTInsert.png" />
  </body>
</html></richcontent>
</node>
</node>
<node CREATED="1300917595946" FOLDED="true" ID="ID_1042375546" MODIFIED="1301069275878" TEXT="Initial Tree">
<node CREATED="1300917609522" ID="ID_1597363400" MODIFIED="1300917617114">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <img src="BST0.png" />
  </body>
</html></richcontent>
</node>
</node>
<node CREATED="1300917599930" FOLDED="true" ID="ID_1194122883" MODIFIED="1301069274070" TEXT="Where to insert 44?">
<node CREATED="1300917619487" ID="ID_1313538019" MODIFIED="1300917625113">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <img src="BST1.png" />
  </body>
</html></richcontent>
</node>
</node>
<node CREATED="1300917601298" FOLDED="true" ID="ID_181885065" MODIFIED="1301069272846" TEXT="Insert 44">
<node CREATED="1300917628095" ID="ID_1034493752" MODIFIED="1300917634754">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <img src="BST2.png" />
  </body>
</html></richcontent>
</node>
</node>
<node CREATED="1300917602010" FOLDED="true" ID="ID_1160566357" MODIFIED="1301069342650" TEXT="Where to insert 21? (step 1)">
<node CREATED="1300917642726" ID="ID_389249653" MODIFIED="1300917650021">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <img src="BST3.png" />
  </body>
</html></richcontent>
</node>
</node>
<node CREATED="1300917602754" FOLDED="true" ID="ID_772178975" MODIFIED="1301069344447" TEXT="Where to insert 21? (step 2)">
<node CREATED="1300917654583" ID="ID_305551524" MODIFIED="1300917661282">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <img src="BST4.png" />
  </body>
</html></richcontent>
</node>
</node>
<node CREATED="1300917603346" FOLDED="true" ID="ID_129242676" MODIFIED="1301069372808" TEXT="Insert 21">
<node CREATED="1300917667711" ID="ID_139819293" MODIFIED="1300917672727">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <img src="BST5.png" />
  </body>
</html></richcontent>
</node>
</node>
<node CREATED="1300917603858" FOLDED="true" ID="ID_771673483" MODIFIED="1301069385080" TEXT="Where to insert 71 (step 1)">
<node CREATED="1300917674967" ID="ID_1698121426" MODIFIED="1300917680311">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <img src="BST6.png" />
  </body>
</html></richcontent>
</node>
</node>
<node CREATED="1300917604786" FOLDED="true" ID="ID_674979804" MODIFIED="1301069397010" TEXT="Where to insert 71 (step 2)">
<node CREATED="1300917684663" ID="ID_1068438174" MODIFIED="1300917690483">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <img src="BST7.png" />
  </body>
</html></richcontent>
</node>
</node>
<node CREATED="1300917605450" FOLDED="true" ID="ID_1723586165" MODIFIED="1301069402909" TEXT="Insert 71">
<node CREATED="1300917697271" ID="ID_1401235275" MODIFIED="1300917704549">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <img src="BST8.png" />
  </body>
</html></richcontent>
</node>
</node>
</node>
<node CREATED="1300917737890" ID="ID_835358855" MODIFIED="1302043203166" TEXT="Traversals">
<node CREATED="1300917743702" ID="ID_1436176238" MODIFIED="1300917751117" TEXT="Pre Order">
<node CREATED="1301068777983" ID="ID_64736237" MODIFIED="1301068795576" TEXT="Parent Node then Children"/>
<node CREATED="1301072119303" ID="ID_607431421" MODIFIED="1301072144143" TEXT="Common recursive pattern"/>
<node CREATED="1301071935772" ID="ID_1979747868" MODIFIED="1301071944491">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <img src="preorder.png" />
  </body>
</html></richcontent>
</node>
</node>
<node CREATED="1300917751322" ID="ID_1252710640" MODIFIED="1300917753665" TEXT="Post Order">
<node CREATED="1301068796952" ID="ID_1211114550" MODIFIED="1301068806550" TEXT="Children then Parent Node"/>
<node CREATED="1301072128463" ID="ID_1398700514" MODIFIED="1301072137511" TEXT="Also a common recursive pattern"/>
<node CREATED="1301071948444" ID="ID_1784382542" MODIFIED="1301071959346">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <img src="postorder.png" />
  </body>
</html></richcontent>
</node>
</node>
<node CREATED="1300917753858" ID="ID_168462241" MODIFIED="1301072090474" TEXT="In Order">
<node CREATED="1301068807288" ID="ID_607972345" MODIFIED="1301068832679" TEXT="Left Child then Parent then Right Child"/>
<node CREATED="1301072148504" ID="ID_828805896" MODIFIED="1301072167630" TEXT="Visits children in sorted order"/>
<node CREATED="1301072186920" ID="ID_273057733" MODIFIED="1301072191351" TEXT="Only well defined for BST"/>
<node CREATED="1301071964684" ID="ID_1628490989" MODIFIED="1301071976453">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <img src="inorder.png" />
  </body>
</html></richcontent>
</node>
</node>
<node CREATED="1300917755787" ID="ID_841424193" MODIFIED="1300917759121" TEXT="Breadth First">
<node CREATED="1301068834320" ID="ID_1734748102" MODIFIED="1301071436144" TEXT="Level by level"/>
<node CREATED="1301068854385" ID="ID_573011553" MODIFIED="1301068858289" TEXT="Uses a queue"/>
<node CREATED="1301071316910" ID="ID_848412529" MODIFIED="1301071323326">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <img src="breadth.png" />
  </body>
</html></richcontent>
</node>
</node>
</node>
</node>
<node CREATED="1302042982965" ID="ID_653385170" MODIFIED="1302042986730" POSITION="right" TEXT="Balanced Trees">
<node CREATED="1302042990689" ID="ID_454875750" MODIFIED="1302042998236" TEXT="Red-Black Trees"/>
</node>
<node CREATED="1300905634631" ID="ID_1211755749" MODIFIED="1300905654471" POSITION="right" TEXT="Non-binary Trees"/>
<node CREATED="1300905654882" ID="ID_1141976329" MODIFIED="1300905658946" POSITION="right" TEXT="Heaps">
<node CREATED="1302043000145" ID="ID_1334062592" MODIFIED="1302043013754" TEXT="What is a heap?">
<node CREATED="1302043013755" ID="ID_266355793" MODIFIED="1302043031218" TEXT="Binary Tree"/>
<node CREATED="1302043031993" ID="ID_323365407" MODIFIED="1302043073489" TEXT="MinHeap Property -- Parent is less than children"/>
<node CREATED="1302043074114" ID="ID_957289034" MODIFIED="1302043083857" TEXT="MaxHeap Property -- Parent is greater than children"/>
<node CREATED="1302043084346" ID="ID_1813264125" MODIFIED="1302043089194" TEXT="Balanced"/>
</node>
<node CREATED="1302043104191" ID="ID_1717623708" MODIFIED="1302043116836" TEXT="Uses">
<node CREATED="1302043116837" ID="ID_1485411188" MODIFIED="1302043140376" TEXT="Priority Queues"/>
<node CREATED="1302043140769" ID="ID_1004938142" MODIFIED="1302043143521" TEXT="HeapSort"/>
</node>
<node CREATED="1302043144873" ID="ID_635141199" MODIFIED="1302043150625" TEXT="Insertion">
<node CREATED="1302209738673" ID="ID_1298563743" MODIFIED="1302209746078" TEXT="0">
<node CREATED="1302209746079" ID="ID_427331311" MODIFIED="1302209746079" TEXT=""/>
</node>
</node>
<node CREATED="1302043151145" ID="ID_1708567009" MODIFIED="1302043153609" TEXT="Deletion"/>
</node>
</node>
</map>
