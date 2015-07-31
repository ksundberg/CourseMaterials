<map version="0.9.0">
<!-- To view this file, download free mind mapping software FreeMind from http://freemind.sourceforge.net -->
<node CREATED="1297446792313" ID="ID_221379038" MODIFIED="1297449603564" TEXT="Exceptions, Templates, and the STL">
<attribute NAME="subtitle" VALUE="CS 1410 -- Chapter 16"/>
<attribute NAME="author" VALUE="Kenneth Sundberg"/>
<attribute NAME="date" VALUE=""/>
<node CREATED="1297446887804" ID="ID_1349566991" MODIFIED="1297446890311" POSITION="right" TEXT="Exceptions">
<node CREATED="1297446899181" ID="ID_257500694" MODIFIED="1297447106697" TEXT="Purpose">
<node CREATED="1297447107459" ID="ID_15476987" MODIFIED="1297449684061" TEXT="What is an exception?">
<node CREATED="1297446932182" ID="ID_1818425714" MODIFIED="1297446970854" TEXT="Exceptions are used to handle exceptional cases"/>
<node CREATED="1297446971184" ID="ID_1751767088" MODIFIED="1297447007714" TEXT="Clarify code by localizing exceptions"/>
<node CREATED="1297447010844" ID="ID_1535909031" MODIFIED="1297447030082" TEXT="Many system calls like new use exceptions"/>
</node>
<node CREATED="1297447126997" ID="ID_852703500" MODIFIED="1297447380667" TEXT="Example - Without Exceptions">
<node CREATED="1297447129066" ID="ID_1021384950" MODIFIED="1297448170969">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      <img src="ExeptionExample1.png" />
    </p>
  </body>
</html>
</richcontent>
</node>
</node>
<node CREATED="1297447358326" ID="ID_133442054" MODIFIED="1297449850211" TEXT="Example - With Exceptions">
<node CREATED="1297449858564" ID="ID_1515894170" MODIFIED="1297449866546">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <img src="exeptionExample2.png" />
  </body>
</html>
</richcontent>
</node>
</node>
<node CREATED="1297447501152" ID="ID_843318273" MODIFIED="1297447505339" TEXT="Why Complicate?">
<node CREATED="1297447505340" ID="ID_757555236" MODIFIED="1297447528055" TEXT="mySqrt may call many other functions"/>
<node CREATED="1297447528352" ID="ID_516672705" MODIFIED="1297449712288" TEXT="Any exception in these functions can be handled here"/>
</node>
</node>
<node CREATED="1297446904928" ID="ID_546690467" MODIFIED="1297446907192" TEXT="Syntax">
<node CREATED="1297447048670" ID="ID_942904727" MODIFIED="1297447641650" TEXT="try and catch">
<node CREATED="1297447643042" ID="ID_1267063322" MODIFIED="1297447715370" TEXT="The try block contains code to be executed normally"/>
<node CREATED="1297447772316" ID="ID_295372229" MODIFIED="1297447783163" TEXT="The catch block contains code to handle exceptions"/>
<node CREATED="1297448152458" ID="ID_757013222" MODIFIED="1297448159017">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <img src="exeptionExample2.png" />
  </body>
</html>
</richcontent>
</node>
</node>
<node CREATED="1297447031934" ID="ID_1054099100" MODIFIED="1297447048308" TEXT="throw">
<node CREATED="1297447796196" ID="ID_1602963207" MODIFIED="1297447857244" TEXT="throw syntax like return"/>
<node CREATED="1297447857597" ID="ID_1058808454" MODIFIED="1297447917803" TEXT="Can throw any defined type"/>
<node CREATED="1297447875949" ID="ID_1924377066" MODIFIED="1297447911220" TEXT="A throw will be caught by the nearest enclosing try-catch"/>
<node CREATED="1297447891061" ID="ID_676625910" MODIFIED="1297447905181" TEXT="If an exception is not caught it will terminate the program"/>
</node>
<node CREATED="1297447925046" ID="ID_362598558" MODIFIED="1297447933218" TEXT="Declaring Throws">
<node CREATED="1297447933219" ID="ID_1350843303" MODIFIED="1297447948958" TEXT="A function can declare what types of exceptions it can through"/>
<node CREATED="1297447949310" ID="ID_738212064" MODIFIED="1297447964168" TEXT="Includes void -- meaning that the function will never through an exception"/>
<node CREATED="1297447964479" ID="ID_52207410" MODIFIED="1297447973022" TEXT="Compiler will enforce these declarations"/>
<node CREATED="1297448182106" ID="ID_1457270829" MODIFIED="1297448193013">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <img src="declareThrows.png" />
  </body>
</html>
</richcontent>
</node>
</node>
</node>
<node CREATED="1297447082767" ID="ID_988291763" MODIFIED="1297448219602" TEXT="Exception Objects">
<node CREATED="1297448224114" ID="ID_226579525" MODIFIED="1297448227870" TEXT="Catch Blocks">
<node CREATED="1297448227871" ID="ID_981629475" MODIFIED="1297448235602" TEXT="A try block can have multiple catch blocks"/>
<node CREATED="1297448235786" ID="ID_190724704" MODIFIED="1297448246401" TEXT="Each catch block can handle a different type of exception"/>
<node CREATED="1297448258323" ID="ID_1888503198" MODIFIED="1297448272684" TEXT="A common approach is to define a class for each exception"/>
<node CREATED="1297448272979" ID="ID_488742303" MODIFIED="1297448284164" TEXT="Often these classes are related through inheritance"/>
</node>
<node CREATED="1297447574381" ID="ID_1961822646" MODIFIED="1297449843675" TEXT="Named Exceptions">
<node CREATED="1297447579689" ID="ID_1870783205" MODIFIED="1297447594808" TEXT="Some system functions throw exceptions"/>
<node CREATED="1297447595041" ID="ID_1496783209" MODIFIED="1297449918000" TEXT="If new can not allocate memory it throws std::bad\_alloc"/>
</node>
</node>
</node>
<node CREATED="1297446890513" ID="ID_1655743122" MODIFIED="1297446892208" POSITION="right" TEXT="Templates">
<node CREATED="1297448435374" ID="ID_1261479894" MODIFIED="1297448849676" TEXT="Purpose">
<node CREATED="1297448444131" ID="ID_1584049864" MODIFIED="1297450037733" TEXT="Busy Work">
<node CREATED="1297448454043" ID="ID_1626936326" MODIFIED="1297448466756">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <img src="twoSwaps.png" />
  </body>
</html>
</richcontent>
</node>
<node CREATED="1297450053262" ID="ID_379971639" MODIFIED="1297450076607" TEXT="These two functions are too simalar"/>
<node CREATED="1297450076950" ID="ID_1529573682" MODIFIED="1297450084833" TEXT="Writing both violates the DRY principle"/>
</node>
<node CREATED="1297448546239" ID="ID_123741914" MODIFIED="1297448578915" TEXT="Templates">
<node CREATED="1297448580704" ID="ID_1354294070" MODIFIED="1297448586774" TEXT="A template is a form or outline of code"/>
<node CREATED="1297448586952" ID="ID_736582937" MODIFIED="1297448627717" TEXT="The compiler will use this template to write an appropriate function if an exact match is not found"/>
<node CREATED="1297448549948" ID="ID_1399245397" MODIFIED="1297448631204">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <img src="templateSwap.png" />
  </body>
</html>
</richcontent>
</node>
</node>
</node>
<node CREATED="1297448844044" ID="ID_1150115643" MODIFIED="1297448846323" TEXT="Examples">
<node CREATED="1297448847140" ID="ID_1256725341" MODIFIED="1297448848459" TEXT="Swap">
<node CREATED="1297448709946" ID="ID_518062598" MODIFIED="1297448714840">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <img src="swapExamples.png" />
  </body>
</html></richcontent>
</node>
<node CREATED="1297450143392" ID="ID_1391879013" MODIFIED="1297450154423" TEXT="With the template function all these calls are valid"/>
</node>
<node CREATED="1297448753586" ID="ID_320103903" MODIFIED="1297448763194" TEXT="Binary Search">
<node CREATED="1297448821835" ID="ID_311773577" MODIFIED="1297448828521">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <img src="templateBinarySearch.png" />
  </body>
</html></richcontent>
</node>
</node>
</node>
<node CREATED="1297448873684" ID="ID_1788039689" MODIFIED="1297448876388" TEXT="Classes">
<node CREATED="1297448876828" ID="ID_1674981925" MODIFIED="1297448882604" TEXT="Class Templates">
<node CREATED="1297448883044" ID="ID_448667047" MODIFIED="1297450243122" TEXT="Classes can also be templatized"/>
<node CREATED="1297448987606" ID="ID_893264358" MODIFIED="1297450231321" TEXT="Implementation goes in header file"/>
<node CREATED="1297449009758" ID="ID_1536340599" MODIFIED="1297450218503" TEXT="No .cpp file"/>
<node CREATED="1297449017710" ID="ID_192352299" MODIFIED="1297449023479">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <img src="templateClass.png" />
  </body>
</html>
</richcontent>
</node>
</node>
<node CREATED="1297449217769" FOLDED="true" ID="ID_1597132697" MODIFIED="1297449323985" TEXT="Class Templates">
<node CREATED="1297449222463" ID="ID_1581522111" MODIFIED="1297449232825" TEXT="All of this code goes in the header file"/>
<node CREATED="1297449233089" ID="ID_711906584" MODIFIED="1297449240738" TEXT="No class has actually been written yet"/>
<node CREATED="1297449241097" ID="ID_1143654683" MODIFIED="1297449249326">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <img src="superArray.png" />
  </body>
</html>
</richcontent>
</node>
</node>
<node CREATED="1297449325251" ID="ID_491376741" MODIFIED="1297449332331" TEXT="Using Template Class">
<node CREATED="1297449332731" ID="ID_1864686984" MODIFIED="1297449337817">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <img src="usingSuperArray.png" />
  </body>
</html>
</richcontent>
</node>
</node>
<node CREATED="1297449352492" ID="ID_237908612" MODIFIED="1297449813177" TEXT="Coding Tip">
<node CREATED="1297449358017" ID="ID_955652459" MODIFIED="1297449797599" TEXT="Debugging templatized classes and functions can be frustrating"/>
<node CREATED="1297449382516" ID="ID_490369122" MODIFIED="1297449399340" TEXT="Implement and test the class or function for a specific type"/>
<node CREATED="1297449399548" ID="ID_220357545" MODIFIED="1297449406266" TEXT="Modify this implementation to be a template"/>
</node>
</node>
</node>
<node CREATED="1297446892410" ID="ID_1107883212" MODIFIED="1297446897739" POSITION="right" TEXT="STL">
<node CREATED="1297449459125" ID="ID_1765853760" MODIFIED="1297449465637" TEXT="Standard Template Library">
<node CREATED="1297449465638" ID="ID_325690306" MODIFIED="1297449476386" TEXT="STL">
<node CREATED="1297449515965" ID="ID_86393848" MODIFIED="1297449526598" TEXT="The Standard Template Library contains templates for:">
<node CREATED="1297449476387" ID="ID_1693776202" MODIFIED="1297449514270" TEXT="Many common data structures"/>
<node CREATED="1297449495637" ID="ID_1708961862" MODIFIED="1297449509958" TEXT="Many common algorithims"/>
</node>
<node CREATED="1297449532158" ID="ID_859959438" MODIFIED="1297449537108" TEXT="Commonly used in practice"/>
<node CREATED="1297449537446" ID="ID_1594074240" MODIFIED="1297449543975" TEXT="You may not use it in this course"/>
</node>
</node>
</node>
</node>
</map>
