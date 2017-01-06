<map version="0.9.0">
<!--To view this file, download free mind mapping software Freeplane from http://freeplane.sourceforge.net -->
<node TEXT="Procedures and Functions" ID="ID_913002344" CREATED="1401765226736" MODIFIED="1401777565160">
<hook NAME="MapStyle" max_node_width="600"/>
<attribute NAME="date" VALUE=""/>
<attribute NAME="author" VALUE="Kenneth Sundberg"/>
<attribute NAME="subtitle" VALUE="CS 5300"/>
<node TEXT="Activation Record" POSITION="right" ID="ID_1522265010" CREATED="1401765238144" MODIFIED="1401765243510">
<node TEXT="Contents" ID="ID_817523626" CREATED="1401765252103" MODIFIED="1401765254935">
<node TEXT="Contents of activation record" ID="ID_611678958" CREATED="1401765254944" MODIFIED="1401765263533">
<node TEXT="Saved local registers" ID="ID_1943014493" CREATED="1401765264798" MODIFIED="1401765269053"/>
<node TEXT="Actual parameters" ID="ID_870213508" CREATED="1401765269373" MODIFIED="1401765273388"/>
<node TEXT="Return address" ID="ID_1933206316" CREATED="1401765273829" MODIFIED="1401765278269"/>
<node TEXT="Old frame pointer" ID="ID_1446380613" CREATED="1401765278613" MODIFIED="1401765282212"/>
<node TEXT="Local variables" ID="ID_1944327587" CREATED="1401765282557" MODIFIED="1401765286588"/>
</node>
<node TEXT="Calling Conventions" ID="ID_161762345" CREATED="1401765673063" MODIFIED="1401765698967">
<node TEXT="Calling Conventions determine who builds what parts of activation record" ID="ID_1311240569" CREATED="1401765698975" MODIFIED="1401765715708"/>
<node TEXT="Caller portion must be lower on stack than callee portion" ID="ID_916052492" CREATED="1401765762188" MODIFIED="1401765779362"/>
</node>
</node>
</node>
<node TEXT="Functions" POSITION="right" ID="ID_722449419" CREATED="1401765325859" MODIFIED="1401765428029">
<node TEXT="Code" ID="ID_614286702" CREATED="1401765330180" MODIFIED="1401765335428">
<node TEXT="Prolog Code" ID="ID_449450366" CREATED="1401765335435" MODIFIED="1401765339276">
<node TEXT="Save local registers" ID="ID_1653466416" CREATED="1401765339281" MODIFIED="1401765344746"/>
<node TEXT="Generate label for procedure" ID="ID_957242541" CREATED="1401765345514" MODIFIED="1401765363521"/>
<node TEXT="Push return address on stack" ID="ID_1368399865" CREATED="1401765364650" MODIFIED="1401765375729"/>
<node TEXT="Push frame pointer on stack" ID="ID_1714228970" CREATED="1401765376585" MODIFIED="1401765385520"/>
<node TEXT="Update the frame pointer to point to new record" ID="ID_855404908" CREATED="1401765385896" MODIFIED="1401765402120"/>
<node TEXT="Allocate space for local variables" ID="ID_417219195" CREATED="1401765402576" MODIFIED="1401765408335"/>
</node>
<node TEXT="Epilog Code" ID="ID_414453105" CREATED="1401765429143" MODIFIED="1401765446133">
<node TEXT="Generate epilog label" ID="ID_626027399" CREATED="1401765447631" MODIFIED="1401765551085"/>
<node TEXT="Update frame pointer" ID="ID_958064543" CREATED="1401765453447" MODIFIED="1401765460021"/>
<node TEXT="Replace value of return address from stack" ID="ID_1810686168" CREATED="1401765461647" MODIFIED="1401765479244"/>
<node TEXT="Deallocate parameters" ID="ID_960613626" CREATED="1401765480366" MODIFIED="1401765485211"/>
<node TEXT="Restore local registers" ID="ID_974296480" CREATED="1401765489501" MODIFIED="1401765495259"/>
<node TEXT="jump to return address" ID="ID_672922731" CREATED="1401765495541" MODIFIED="1401765501819"/>
</node>
<node TEXT="Return Statement" ID="ID_1771495749" CREATED="1401765553147" MODIFIED="1401765559036">
<node TEXT="Put return value in register" ID="ID_1800732925" CREATED="1401765586402" MODIFIED="1401765599061"/>
<node TEXT="Jump to epilog label" ID="ID_584215711" CREATED="1401765559042" MODIFIED="1401765574648"/>
</node>
<node TEXT="Formal Parameters" ID="ID_1442381064" CREATED="1401776351563" MODIFIED="1401776361708">
<node TEXT="Dual definitions" ID="ID_9258841" CREATED="1401776361713" MODIFIED="1401776391891">
<node TEXT="Part of signature" ID="ID_62376738" CREATED="1401776391897" MODIFIED="1401776395680"/>
<node TEXT="Identifiers at local scope" ID="ID_1077333049" CREATED="1401776396034" MODIFIED="1401776404767"/>
</node>
<node TEXT="Identifiers have positive offsets from frame pointer" ID="ID_605543784" CREATED="1401776405778" MODIFIED="1401776417255"/>
</node>
<node TEXT="Actual Parameters" ID="ID_1081232638" CREATED="1401776438416" MODIFIED="1401776442777">
<node TEXT="Found at call site" ID="ID_1785661250" CREATED="1401776442783" MODIFIED="1401777495134"/>
<node TEXT="Add to top of stack then move frame pointer" ID="ID_1526837592" CREATED="1401776448735" MODIFIED="1401776457958"/>
</node>
</node>
<node TEXT="Step by Step" ID="ID_1381257917" CREATED="1401777346985" MODIFIED="1401777357385">
<node TEXT="Current Record" ID="ID_1853571669" CREATED="1401777357389" MODIFIED="1401777369737">
<node ID="ID_146086077" CREATED="1401777473165" MODIFIED="1401777509398">
<richcontent TYPE="NODE">
<html>
  <head>
    
  </head>
  <body>
    <img src="lectures/figures/Call-01.png"/>
  </body>
</html>
</richcontent>
</node>
</node>
<node TEXT="Spill Registers" ID="ID_1800344966" CREATED="1401777377320" MODIFIED="1401777381021">
<node ID="ID_380378117" CREATED="1401777632431" MODIFIED="1401777642294">
<richcontent TYPE="NODE">
<html>
  <head>
    
  </head>
  <body>
    <img src="lectures/figures/Call-02.png"/>
  </body>
</html>
</richcontent>
</node>
</node>
<node TEXT="Set Parameters" ID="ID_189393226" CREATED="1401777381231" MODIFIED="1401777676637">
<node ID="ID_978133610" CREATED="1401777646234" MODIFIED="1401777659744">
<richcontent TYPE="NODE">
<html>
  <head>
    
  </head>
  <body>
    <img src="lectures/figures/Call-03.png"/>
  </body>
</html>
</richcontent>
</node>
</node>
<node TEXT="Call Function" ID="ID_12410381" CREATED="1401777400159" MODIFIED="1401777421538">
<node ID="ID_116655228" CREATED="1401777693549" MODIFIED="1401777705101">
<richcontent TYPE="NODE">
<html>
  <head>
    
  </head>
  <body>
    <img src="lectures/figures/Call-04.png"/>
  </body>
</html>
</richcontent>
</node>
</node>
<node TEXT="Build new Activation Record" ID="ID_572926410" CREATED="1401777421967" MODIFIED="1401777426884">
<node ID="ID_776210203" CREATED="1401777712604" MODIFIED="1401777726703">
<richcontent TYPE="NODE">
<html>
  <head>
    
  </head>
  <body>
    <img src="lectures/figures/Call-05.png"/>
  </body>
</html>
</richcontent>
</node>
</node>
</node>
</node>
</node>
</map>
