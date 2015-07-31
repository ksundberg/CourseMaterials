<map version="0.9.0">
<!-- To view this file, download free mind mapping software FreeMind from http://freemind.sourceforge.net -->
<node CREATED="1294260495215" ID="ID_1925004900" MODIFIED="1294265767854" TEXT="More on Classes">
<attribute NAME="date" VALUE=""/>
<attribute NAME="author" VALUE="Kenneth Sundberg"/>
<attribute NAME="subtitle" VALUE="CS1410 -- Chapter 14"/>
<node CREATED="1294264640641" ID="ID_1548099472" MODIFIED="1294264932460" POSITION="right" TEXT="Operators">
<node CREATED="1294264769191" ID="ID_1711775524" MODIFIED="1294264880344" TEXT="Overloading">
<node CREATED="1294260740764" ID="ID_751504101" MODIFIED="1294264786186" TEXT="Operator Overloading">
<node CREATED="1294260767765" ID="ID_1726354945" MODIFIED="1294260780648" TEXT="Allows class designer to specify what an operator means"/>
<node CREATED="1294260969335" ID="ID_1211382113" MODIFIED="1294260978357">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <img src="operatorOverloading.png" />
  </body>
</html></richcontent>
</node>
</node>
<node CREATED="1294261233640" ID="ID_1500662169" MODIFIED="1294264799158" TEXT="Available Operators">
<node CREATED="1294261240074" ID="ID_1588198716" MODIFIED="1294261247639" TEXT="Most operators are available for overloading"/>
<node CREATED="1294261259945" ID="ID_800323557" MODIFIED="1294261276021" TEXT="Left side of operator becomes \emph{this}"/>
<node CREATED="1294261276231" ID="ID_563531068" MODIFIED="1294261288792" TEXT="Right side of operator becomes parameter"/>
<node CREATED="1294263586826" ID="ID_560379404" MODIFIED="1294263619877" TEXT="You can not redefine existing operators"/>
<node CREATED="1294261328674" ID="ID_271148021" MODIFIED="1294261335785">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <img src="operatorMangling.png" />
  </body>
</html></richcontent>
</node>
</node>
<node CREATED="1294261357448" ID="ID_1742421259" MODIFIED="1294264819812" TEXT="Operator Overloading Outside of a class">
<node CREATED="1294261367524" ID="ID_670429421" MODIFIED="1294261378653" TEXT="Operators may be overloaded outside of a class"/>
<node CREATED="1294261378896" ID="ID_1524494462" MODIFIED="1294261393159" TEXT="Left hand side becomes first parameter"/>
<node CREATED="1294261393341" ID="ID_206703477" MODIFIED="1294261399828" TEXT="Right hand side becomes second parameter"/>
<node CREATED="1294261465831" ID="ID_1527268186" MODIFIED="1294261471624">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <img src="operatorOverloadingString.png" />
  </body>
</html></richcontent>
</node>
</node>
</node>
<node CREATED="1294264864074" ID="ID_1058333611" MODIFIED="1294264890671" TEXT="Examples">
<node CREATED="1294264949434" ID="ID_850472504" MODIFIED="1294264956779" TEXT="Math Operators">
<node CREATED="1294264957893" ID="ID_608422615" MODIFIED="1294265495518" TEXT="Mathematical operators are formally defined in terms of each other"/>
<node CREATED="1294264980718" ID="ID_972047877" MODIFIED="1294265013572" TEXT="Use this pattern in your code"/>
<node CREATED="1294265122986" ID="ID_1237025423" MODIFIED="1294265130299">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <img src="operatorGE.png" />
  </body>
</html>
</richcontent>
</node>
</node>
<node CREATED="1294261494169" ID="ID_672942139" MODIFIED="1294264895741" TEXT="Assignment Operator">
<node CREATED="1294261622320" ID="ID_1630000812" MODIFIED="1294261626703">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <img src="assignmentOperator.png" />
  </body>
</html></richcontent>
</node>
</node>
<node CREATED="1294263305250" ID="ID_531547176" MODIFIED="1294263676332" TEXT="Insertion and Extraction">
<node CREATED="1294263313769" ID="ID_256707076" MODIFIED="1294263340581" TEXT="The left hand side of &lt;&lt; and &gt;&gt; is not an instance of your ADT"/>
<node CREATED="1294263343888" ID="ID_600541638" MODIFIED="1294263366958" TEXT="These operators cannot be overloaded as member functions"/>
<node CREATED="1294263524561" ID="ID_556595851" MODIFIED="1294263528441">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <img src="wrapperFunction.png" />
  </body>
</html></richcontent>
</node>
</node>
</node>
<node CREATED="1294264825731" ID="ID_1609693155" MODIFIED="1294264828987" TEXT="Casting">
<node CREATED="1294262340266" ID="ID_686281480" MODIFIED="1294262344322" TEXT="Converting Objects">
<node CREATED="1294261792043" ID="ID_825683613" MODIFIED="1294261817615" TEXT="A cast operator may be provided to convert an ADT object into something else."/>
<node CREATED="1294262356584" ID="ID_693430909" MODIFIED="1294262376983" TEXT="A constructor may be provided to convert something else to an instance of the ADT"/>
<node CREATED="1294262404617" ID="ID_1432342968" MODIFIED="1294262411497" TEXT="Both may be implicitly called"/>
</node>
<node CREATED="1294261786661" ID="ID_1438330884" MODIFIED="1294262389680" TEXT="Cast Operator">
<node CREATED="1294262298851" ID="ID_398133344" MODIFIED="1294262303563">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <img src="castOperator.png" />
  </body>
</html></richcontent>
</node>
</node>
<node CREATED="1294262391084" ID="ID_1506672336" MODIFIED="1294264847043" TEXT="Signature Matching">
<node CREATED="1294262699141" ID="ID_1929957159" MODIFIED="1294262729001" TEXT="The compiler will attempt to match signatures in the following order">
<node CREATED="1294262729002" ID="ID_1845802051" MODIFIED="1294262743786" TEXT="A member function in the same class"/>
<node CREATED="1294262744412" ID="ID_1136480465" MODIFIED="1294262765344" TEXT="A function in the global scope"/>
<node CREATED="1294262765827" ID="ID_752854483" MODIFIED="1294262787786" TEXT="A member function that matches after casting"/>
<node CREATED="1294262788219" ID="ID_1625461598" MODIFIED="1294262797068" TEXT="A global function that matches after casting"/>
</node>
</node>
<node CREATED="1294263209600" ID="ID_1107606365" MODIFIED="1294264848527" TEXT="Example">
<node CREATED="1294263214398" ID="ID_1318877335" MODIFIED="1294263220817">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <img src="multipySignatureMatch.png" />
  </body>
</html></richcontent>
</node>
</node>
<node CREATED="1294263187616" ID="ID_1638042934" MODIFIED="1294264849287" TEXT="Example">
<node CREATED="1294263201133" ID="ID_1289351990" MODIFIED="1294263207918">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <img src="assignmentSignatureMatch.png" />
  </body>
</html></richcontent>
</node>
</node>
</node>
</node>
<node CREATED="1294264649860" ID="ID_378751633" MODIFIED="1294354617770" POSITION="right" TEXT="Pointers">
<node CREATED="1294264657422" FOLDED="true" ID="ID_1578793927" MODIFIED="1294264694497" TEXT="File I/O">
<node CREATED="1294260535802" ID="ID_669325371" MODIFIED="1294260555967" TEXT="Writing a dynamic memory object to a file">
<node CREATED="1294260560171" ID="ID_1939921641" MODIFIED="1294260572057" TEXT="Avoid writing a shallow copy to disk">
<node CREATED="1294260572058" ID="ID_117876569" MODIFIED="1294260591749" TEXT="Pointers may no longer be valid when object is read in"/>
<node CREATED="1294260592190" ID="ID_193457308" MODIFIED="1294260604335" TEXT="dynamic memory will no longer be valid after a program exits"/>
</node>
<node CREATED="1294260618719" ID="ID_1804307271" MODIFIED="1294260621419" TEXT="Options">
<node CREATED="1294260621420" ID="ID_1727507645" MODIFIED="1294260655482" TEXT="Marshal object to a stream -- probably cannot be used for random access"/>
<node CREATED="1294260657814" ID="ID_810302647" MODIFIED="1294260682419" TEXT="Create a fixed size varient for binary files"/>
</node>
</node>
</node>
<node CREATED="1294264695445" ID="ID_377332595" MODIFIED="1294264698229" TEXT="Copies">
<node CREATED="1294263677209" ID="ID_251238117" MODIFIED="1294264573558" TEXT="Copy Types">
<node CREATED="1294264207352" ID="ID_1137458405" MODIFIED="1294264228034" TEXT="When coping an ADT with pointers there are two options:">
<node CREATED="1294264228035" ID="ID_1875277542" MODIFIED="1294264236088" TEXT="Shallow Copy -- Copy the pointer"/>
<node CREATED="1294264236609" ID="ID_1233262545" MODIFIED="1294264248821" TEXT="Deep Copy -- Copy the thing pointed to"/>
</node>
<node CREATED="1294264269117" ID="ID_1173547634" MODIFIED="1294264280589" TEXT="Copies are made in:">
<node CREATED="1294264280590" ID="ID_1321319161" MODIFIED="1294264285418" TEXT="The Copy Constructor"/>
<node CREATED="1294264285779" ID="ID_1649952547" MODIFIED="1294264291971" TEXT="The Assignment Operator"/>
</node>
</node>
<node CREATED="1294264536903" ID="ID_555524902" MODIFIED="1294264541576" TEXT="Shallow Copy">
<node CREATED="1294264559052" ID="ID_1271038809" MODIFIED="1294264598477">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <img src="shallowCopy.png" />
  </body>
</html></richcontent>
<attribute NAME="caption" VALUE="Copy the Pointer"/>
</node>
</node>
<node CREATED="1294264541937" ID="ID_368905245" MODIFIED="1294264544553" TEXT="Deep Copy">
<node CREATED="1294264545266" ID="ID_1642747545" MODIFIED="1294264615324">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <img src="deepCopy.png" />
  </body>
</html></richcontent>
<attribute NAME="caption" VALUE="Copy the thing pointed to"/>
</node>
</node>
<node CREATED="1294263682146" ID="ID_1609962182" MODIFIED="1294263690717" TEXT="Rule of Three">
<node CREATED="1294263923930" ID="ID_745146723" MODIFIED="1294263935273" TEXT="If an ADT has pointer members it needs:">
<node CREATED="1294263935274" ID="ID_1592010730" MODIFIED="1294263939729" TEXT="A Destructor"/>
<node CREATED="1294263939903" ID="ID_1129106330" MODIFIED="1294263943920" TEXT="A Copy Constructor"/>
<node CREATED="1294263944097" ID="ID_241911437" MODIFIED="1294264295582" TEXT="An Assignment Operator"/>
</node>
</node>
</node>
</node>
<node CREATED="1294264741205" ID="ID_1918761129" MODIFIED="1294264743293" POSITION="right" TEXT="Other">
<node CREATED="1294264743846" ID="ID_148994153" MODIFIED="1294354531078" TEXT="Static Keyword">
<node CREATED="1294263692054" ID="ID_1895889388" MODIFIED="1294263699128" TEXT="Static Member Variables">
<node CREATED="1294263805687" ID="ID_1680269811" MODIFIED="1294263841257" TEXT="All instances of a class share \emph{one global} instances of a static member variable"/>
<node CREATED="1294263841924" ID="ID_1876050706" MODIFIED="1294263854500" TEXT="Static member variables:">
<node CREATED="1294263854501" ID="ID_203845523" MODIFIED="1294263861004" TEXT="Must be declared in the .cpp"/>
<node CREATED="1294263861203" ID="ID_1016604929" MODIFIED="1294263869797" TEXT="Should be initialized"/>
</node>
</node>
<node CREATED="1294263699401" ID="ID_218353612" MODIFIED="1294263702913" TEXT="Static Member Functions">
<node CREATED="1294263889605" ID="ID_494970022" MODIFIED="1294263899183" TEXT="Can only access static member variables"/>
<node CREATED="1294263899441" ID="ID_1927782193" MODIFIED="1294263912405" TEXT="Are called on the class, not on an instance of the class"/>
</node>
</node>
<node CREATED="1294264924844" ID="ID_370117442" MODIFIED="1294264927183" TEXT="Friends">
<node CREATED="1294260692570" ID="ID_1509311296" MODIFIED="1294260697338" TEXT="Friends of Classes">
<node CREATED="1294260697796" ID="ID_849263679" MODIFIED="1294260718122" TEXT="Allows non-member function access to private members"/>
<node CREATED="1294260718476" ID="ID_508415049" MODIFIED="1294260728237" TEXT="This is a \emph{very bad} idea"/>
<node CREATED="1294260728663" ID="ID_1913472359" MODIFIED="1294260739784" TEXT="Friends of classes are not friends of programmers"/>
</node>
</node>
</node>
</node>
</map>
