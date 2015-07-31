<map version="0.9.0">
<!-- To view this file, download free mind mapping software FreeMind from http://freemind.sourceforge.net -->
<node CREATED="1294253673659" ID="ID_194404459" MODIFIED="1294257209428" TEXT="Classes and Object Oriented Programming">
<attribute NAME="theme" VALUE="Warsaw"/>
<attribute NAME="author" VALUE="Kenneth Sundberg"/>
<attribute NAME="date" VALUE=""/>
<attribute NAME="subtitle" VALUE="CS 1410 -- Chapter 13"/>
<node CREATED="1294257210027" ID="ID_416897596" MODIFIED="1294257300741" POSITION="right" TEXT="Overview">
<node CREATED="1294257221008" ID="ID_677275867" MODIFIED="1294257222735" TEXT="OOP">
<node CREATED="1294253763269" ID="ID_1945987333" MODIFIED="1294253770275" TEXT="Object Oriented Programming">
<node CREATED="1294253771343" ID="ID_661155541" MODIFIED="1294253774078" TEXT="Encapsulation">
<node CREATED="1294253786244" ID="ID_364058992" MODIFIED="1294253802887" TEXT="The details of implementing and manipulating an ADT are under the control of the designer"/>
</node>
<node CREATED="1294253774264" ID="ID_1410163272" MODIFIED="1294253777071" TEXT="Data Hiding">
<node CREATED="1294253803555" ID="ID_7360091" MODIFIED="1294253816429" TEXT="The user of an ADT doesn&apos;t need to know the details of the data components"/>
</node>
<node CREATED="1294253777233" ID="ID_140532989" MODIFIED="1294253780184" TEXT="Code Reuse">
<node CREATED="1294253817351" ID="ID_861405574" MODIFIED="1294253828857" TEXT="An ADT can be used in multiple programs without re-design"/>
</node>
<node CREATED="1294253780418" ID="ID_1287246384" MODIFIED="1294253785053" TEXT="Polymorphism">
<node CREATED="1294253829700" ID="ID_1254458342" MODIFIED="1294253844760" TEXT="An ADT can be modified or adapted without needing to know the details of the original"/>
</node>
</node>
</node>
<node CREATED="1294257245601" ID="ID_256645995" MODIFIED="1294257667696" TEXT="Declarations">
<node CREATED="1294253845898" ID="ID_332640139" MODIFIED="1294253864831" TEXT="Class Declarations">
<node CREATED="1294253865177" ID="ID_1469617762" MODIFIED="1294253868981" TEXT="Components can be">
<node CREATED="1294253868982" ID="ID_862582107" MODIFIED="1294253873674" TEXT="data variable members"/>
<node CREATED="1294253874060" ID="ID_1225293293" MODIFIED="1294253889503" TEXT="function member prototypes"/>
</node>
<node CREATED="1294254059624" ID="ID_1320329704" MODIFIED="1294254197865">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      <img src="classDeclaration.png" />
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node CREATED="1294254212247" ID="ID_112925308" MODIFIED="1294254216787" TEXT="Public vs. Private">
<node CREATED="1294254216789" ID="ID_1426681055" MODIFIED="1294254234933" TEXT="Public -- Can be accessed or used by any program that has an instance of this ADT"/>
<node CREATED="1294254235135" ID="ID_1994135384" MODIFIED="1294254249330" TEXT="Private -- Can only be accessed or used by member functions of this ADT"/>
</node>
<node CREATED="1294255488676" ID="ID_1028639110" MODIFIED="1294255495962" TEXT="Inline Functions">
<node CREATED="1294255495963" ID="ID_625016919" MODIFIED="1294257693085" TEXT="It is syntacticly possible to put code in a header file"/>
<node CREATED="1294255527570" ID="ID_1946647329" MODIFIED="1294255567087" TEXT="It is very poor style -- \emph{Do Not Do It}"/>
<node CREATED="1294255604654" ID="ID_1896905459" MODIFIED="1294255628836" TEXT="This is only acceptable when syntacticly required"/>
</node>
<node CREATED="1294256375066" ID="ID_1787731671" MODIFIED="1294256378110" TEXT="Ambiguity">
<node CREATED="1294256378111" ID="ID_1195728733" MODIFIED="1294256397593" TEXT="If two functions have the same \emph{signature} they are ambiguous"/>
<node CREATED="1294256398234" ID="ID_1887389854" MODIFIED="1294256406256" TEXT="Function Signature:">
<node CREATED="1294256406258" ID="ID_1648709261" MODIFIED="1294256409432" TEXT="Function Name"/>
<node CREATED="1294256409838" ID="ID_923099330" MODIFIED="1294256415287" TEXT="Number of Function Arguments"/>
<node CREATED="1294256415504" ID="ID_1339289895" MODIFIED="1294256419992" TEXT="Type of Function Arguments"/>
</node>
<node CREATED="1294256428548" ID="ID_1524046549" MODIFIED="1294256433902" TEXT="Ambiguity is a syntax error"/>
</node>
</node>
</node>
<node CREATED="1294257105652" ID="ID_1613074619" MODIFIED="1294257361901" POSITION="right" TEXT="Member Functions">
<node CREATED="1294257174792" ID="ID_1279635358" MODIFIED="1294257189192" TEXT="Overview">
<node CREATED="1294254306796" ID="ID_309066322" MODIFIED="1294254309937" TEXT="Member Functions">
<node CREATED="1294254309938" ID="ID_282159279" MODIFIED="1294254321067" TEXT="Member functions belong to an ADT"/>
<node CREATED="1294254321297" ID="ID_1931759674" MODIFIED="1294254341164" TEXT="They are not in the global scope">
<node CREATED="1294254341165" ID="ID_763392732" MODIFIED="1294254364808" TEXT="Scope resolution must be used (::)"/>
<node CREATED="1294254365329" ID="ID_312089660" MODIFIED="1294254381629" TEXT="Add the name of the ADT before the function name"/>
</node>
<node CREATED="1294254426432" ID="ID_1930502200" MODIFIED="1294254445869">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <img src="memberFunction.png" />
  </body>
</html></richcontent>
</node>
</node>
<node CREATED="1294260994200" ID="ID_1469640800" MODIFIED="1294260998270" TEXT="Constant Functions">
<node CREATED="1294260998271" ID="ID_1487454207" MODIFIED="1294261028703" TEXT="If a member function does not change any member variables it can be declared as a constant function"/>
<node CREATED="1294261029604" ID="ID_1386836979" MODIFIED="1294261094786" TEXT="Constant functions have the keyword \emph{const} at the end of their signature"/>
<node CREATED="1294261177465" ID="ID_969977250" MODIFIED="1294261185052" TEXT="If a function can be constant it should be constant"/>
</node>
<node CREATED="1294254464406" ID="ID_1457794965" MODIFIED="1294254474652" TEXT="Calling Member Functions">
<node CREATED="1294254474653" ID="ID_1838793079" MODIFIED="1294254485834" TEXT="A member function is called using `dot&apos; notation"/>
<node CREATED="1294254497198" ID="ID_987348226" MODIFIED="1294254522771" TEXT="A member function doesn&apos;t need a parameter to indicate which instance it should manipulate"/>
<node CREATED="1294254573745" ID="ID_282603062" MODIFIED="1294254580399">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <img src="memberFunctionCall.png" />
  </body>
</html></richcontent>
</node>
</node>
</node>
<node CREATED="1294256985468" ID="ID_134045682" MODIFIED="1294257395944" TEXT="Example">
<node CREATED="1294254619476" FOLDED="true" ID="ID_1305325806" MODIFIED="1294257539586" TEXT="Example: Rational.h">
<node CREATED="1294254633545" ID="ID_13318484" MODIFIED="1294254882885">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <img src="rationalH.png" />
  </body>
</html></richcontent>
</node>
</node>
<node CREATED="1294254884036" ID="ID_809870939" MODIFIED="1294254900672" TEXT="Example: Rational.cpp">
<node CREATED="1294254885451" ID="ID_352664732" MODIFIED="1294254891248">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <img src="rationalCPP.png" />
  </body>
</html></richcontent>
</node>
</node>
<node CREATED="1294255303480" ID="ID_643715113" MODIFIED="1294257059180" TEXT="this">
<node CREATED="1294255309266" ID="ID_1230779337" MODIFIED="1294255339423" TEXT="Each member function has a pointer to the instance it was called on"/>
<node CREATED="1294255339930" ID="ID_667148610" MODIFIED="1294255349916" TEXT="This pointer is called \emph{this}"/>
</node>
<node CREATED="1294255111920" ID="ID_667010988" MODIFIED="1294257059174" TEXT="Example: Rational::add">
<node CREATED="1294255114421" ID="ID_1408526879" MODIFIED="1294255122831">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <img src="rationalAdd.png" />
  </body>
</html></richcontent>
</node>
<node CREATED="1294255125012" ID="ID_1674938315" MODIFIED="1294255136103" TEXT=".add() only has one parameter"/>
<node CREATED="1294255136408" ID="ID_185247597" MODIFIED="1294255160928" TEXT="A member function automatically has access to the instance it is called on"/>
<node CREATED="1294255212178" ID="ID_1514713325" MODIFIED="1294257729645" TEXT="When a member is referred to without a dot -- it means the member of \emph{this}"/>
</node>
</node>
</node>
<node CREATED="1294257324141" ID="ID_1990364376" MODIFIED="1294257332351" POSITION="right" TEXT="Special Functions">
<node CREATED="1294257332824" ID="ID_447106320" MODIFIED="1294257336369" TEXT="Constructors">
<node CREATED="1294255635393" ID="ID_1897935186" MODIFIED="1294257280684" TEXT="Constructors">
<node CREATED="1294255641080" ID="ID_707562158" MODIFIED="1294255663843" TEXT="A class may contain a constructor"/>
<node CREATED="1294255664323" ID="ID_1733538135" MODIFIED="1294255677655" TEXT="A constructor is invoked whenever an instance is created"/>
<node CREATED="1294255677880" ID="ID_1196160187" MODIFIED="1294255713484" TEXT="A default constructor is provided if you do not declare one"/>
<node CREATED="1294255830248" ID="ID_1352735646" MODIFIED="1294255835726">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <img src="defaultConstructor.png" />
  </body>
</html></richcontent>
</node>
</node>
<node CREATED="1294256136529" ID="ID_1002278811" MODIFIED="1294256140174" TEXT="Constructors">
<node CREATED="1294256140175" ID="ID_714191621" MODIFIED="1294256151532" TEXT="A constructor&apos;s name is always the same as the class"/>
<node CREATED="1294256151782" ID="ID_1613306569" MODIFIED="1294256158503" TEXT="Constructors do not have a return type"/>
<node CREATED="1294256158737" ID="ID_853331417" MODIFIED="1294256170900" TEXT="Constructors are automatically invoked"/>
<node CREATED="1294256171117" ID="ID_549612116" MODIFIED="1294256180967" TEXT="A constructor \emph{cannot} be directly invoked"/>
</node>
<node CREATED="1294256331170" ID="ID_1646656918" MODIFIED="1294256338035" TEXT="Overloading Constructors">
<node CREATED="1294256338420" ID="ID_1633172341" MODIFIED="1294256357634" TEXT="It is common to provide overloaded constructors for different creation circumstances"/>
</node>
<node CREATED="1294256434783" ID="ID_1118977949" MODIFIED="1294264022064" TEXT="The Default Constructor">
<node CREATED="1294256451757" ID="ID_528194770" MODIFIED="1294257759082" TEXT="If no constructor is provided, the system provides a default"/>
<node CREATED="1294256472356" ID="ID_1111258287" MODIFIED="1294257788431" TEXT="If any constructors are provided there is no default constructor"/>
<node CREATED="1294256499382" ID="ID_839691887" MODIFIED="1294256508037" TEXT="The default constructor">
<node CREATED="1294256508039" ID="ID_1962065526" MODIFIED="1294256512190" TEXT="Take no arguments"/>
<node CREATED="1294256512595" ID="ID_1259358873" MODIFIED="1294256514771" TEXT="Does nothing"/>
</node>
</node>
<node CREATED="1294264014054" ID="ID_557305644" MODIFIED="1294264019056" TEXT="The Copy Constructor">
<node CREATED="1294264019607" ID="ID_453726146" MODIFIED="1294264040401" TEXT="This constructor is called when a copy is made">
<node CREATED="1294264104150" ID="ID_1921709711" MODIFIED="1294264114835" TEXT="return"/>
<node CREATED="1294264115218" ID="ID_1022354563" MODIFIED="1294264118036" TEXT="pass by value"/>
</node>
<node CREATED="1294264040807" ID="ID_341053618" MODIFIED="1294264051828" TEXT="If not provided, the system provides a default"/>
<node CREATED="1294264052347" ID="ID_852461385" MODIFIED="1294264086709" TEXT="The default copy constructor makes a copy of the memory image">
<node CREATED="1294264086855" ID="ID_1900136950" MODIFIED="1294264101741" TEXT="This is correct \emph{unless} there is a pointer in the class"/>
</node>
<node CREATED="1294264176355" ID="ID_26914872" MODIFIED="1294264183421">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <img src="copyConstructor.png" />
  </body>
</html>
</richcontent>
</node>
</node>
</node>
<node CREATED="1294257336657" ID="ID_1827240828" MODIFIED="1294257338802" TEXT="Destructors">
<node CREATED="1294256578529" ID="ID_1637651414" MODIFIED="1294256582446" TEXT="Destructors">
<node CREATED="1294256582954" ID="ID_1587879208" MODIFIED="1294256616703" TEXT="A function that is automatically invoked when an object is deleted">
<node CREATED="1294256617191" ID="ID_394629425" MODIFIED="1294256626915" TEXT="Using the delete operator"/>
<node CREATED="1294256627090" ID="ID_631056593" MODIFIED="1294256633539" TEXT="When an instance goes out of scope"/>
</node>
<node CREATED="1294256644713" ID="ID_811361134" MODIFIED="1294256654818" TEXT="Only one destructor for each class"/>
<node CREATED="1294256655164" ID="ID_1719734474" MODIFIED="1294256734297" TEXT="Destructors are named as the class name proceeded by a \~{}"/>
</node>
</node>
</node>
</node>
</map>
