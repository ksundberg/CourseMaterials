<map version="0.9.0">
<!-- To view this file, download free mind mapping software FreeMind from http://freemind.sourceforge.net -->
<node CREATED="1294183339516" ID="ID_1613209657" MODIFIED="1294183406505" TEXT="Advanced File Operations">
<attribute NAME="theme" VALUE="Warsaw"/>
<attribute NAME="author" VALUE="Kenneth Sundberg"/>
<attribute NAME="subtitle" VALUE="CS 1410 -- Chapter 12"/>
<attribute NAME="date" VALUE=""/>
<node CREATED="1294183698727" ID="ID_350219439" MODIFIED="1294183707314" POSITION="right" TEXT="Fstream ADT">
<node CREATED="1294197474368" ID="ID_1719203816" MODIFIED="1294197482413" TEXT="Overview">
<node CREATED="1294183431333" ID="ID_166197721" MODIFIED="1294197602665" TEXT="Types">
<node CREATED="1294183441306" ID="ID_348492561" MODIFIED="1294183449805" TEXT="ifstream -- Input file stream">
<node CREATED="1294183449807" ID="ID_1559907786" MODIFIED="1294183457956" TEXT="may only be used for input from an existing file"/>
</node>
<node CREATED="1294183458912" ID="ID_748993644" MODIFIED="1294183464749" TEXT="ofstream -- Output file stream">
<node CREATED="1294183464750" ID="ID_1312598167" MODIFIED="1294183475909" TEXT="may only be used to create and output to a file"/>
</node>
<node CREATED="1294183476704" ID="ID_913877115" MODIFIED="1294183493908" TEXT="fstream -- General file stream">
<node CREATED="1294183493909" ID="ID_451474148" MODIFIED="1294183502082" TEXT="may be used to create, read, and output to a file"/>
</node>
</node>
</node>
<node CREATED="1294197482812" ID="ID_1845734534" MODIFIED="1294197654618" TEXT="Initialization">
<node CREATED="1294183515892" ID="ID_505353048" MODIFIED="1294195887679" TEXT="Opening ">
<node CREATED="1294195440572" ID="ID_180360004" MODIFIED="1294195454574" TEXT="A file must be opened prior to use"/>
<node CREATED="1294195458713" ID="ID_875658357" MODIFIED="1294195470873" TEXT="The \emph{open} member function uses two arguments">
<node CREATED="1294195470874" ID="ID_1870907862" MODIFIED="1294195481492" TEXT="The file name"/>
<node CREATED="1294195481669" ID="ID_1794856353" MODIFIED="1294195488775" TEXT="The access flag"/>
</node>
<node CREATED="1294195573595" ID="ID_226881086" MODIFIED="1294195616672">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <img src="fstreamOpen.png" />
  </body>
</html></richcontent>
</node>
</node>
<node CREATED="1294195891712" ID="ID_1638476141" MODIFIED="1294195904638" TEXT="Open at declaration">
<node CREATED="1294196039754" ID="ID_114306208" MODIFIED="1294196056766">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <img src="fstreamOpenA.png" />
  </body>
</html></richcontent>
</node>
<node CREATED="1294196071266" ID="ID_942114822" MODIFIED="1294196080284" TEXT="Files may be opened as the fstream is declared"/>
</node>
<node CREATED="1294196082872" ID="ID_1921803547" MODIFIED="1294197576719" TEXT="Open at declaration">
<node CREATED="1294196083284" ID="ID_212614331" MODIFIED="1294196090435">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <img src="fstreamOpenB.png" />
  </body>
</html></richcontent>
</node>
<node CREATED="1294196091500" ID="ID_1602032218" MODIFIED="1294196100912" TEXT="This is equivalent"/>
</node>
</node>
<node CREATED="1294197618512" ID="ID_795649038" MODIFIED="1294197621522" TEXT="Access Flags">
<node CREATED="1294195625357" ID="ID_312648895" MODIFIED="1294197623439" TEXT="Access Flags">
<node CREATED="1294195630867" ID="ID_563288883" MODIFIED="1294195644003" TEXT="ios::app -- append to an existing file"/>
<node CREATED="1294195644278" ID="ID_282518408" MODIFIED="1294195653810" TEXT="ios::binary -- write data in binary format"/>
<node CREATED="1294195653995" ID="ID_41814471" MODIFIED="1294195667929" TEXT="ios::in -- file is to be used for input"/>
<node CREATED="1294195668090" ID="ID_58830195" MODIFIED="1294195676453" TEXT="ios::out -- file is to be used for output"/>
<node CREATED="1294195676614" ID="ID_1894909465" MODIFIED="1294195689794" TEXT="ios::trunc -- discard previous file contents"/>
<node CREATED="1294195689965" ID="ID_503231293" MODIFIED="1294195701202" TEXT="ios::text -- write data in text format"/>
<node CREATED="1294195701563" ID="ID_991486193" MODIFIED="1294195703595" TEXT="others"/>
</node>
<node CREATED="1294195716435" ID="ID_60589953" MODIFIED="1294195723561" TEXT="Combining file access flags">
<node CREATED="1294195723562" ID="ID_1229877160" MODIFIED="1294195744975" TEXT="Access flags may be combined using the bitwise-or operator"/>
<node CREATED="1294195783508" ID="ID_1326308343" MODIFIED="1294195789559">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <img src="combinedFlags.png" />
  </body>
</html></richcontent>
</node>
</node>
<node CREATED="1294195796347" ID="ID_427540954" MODIFIED="1294195822276" TEXT="ifstream and ofstream">
<node CREATED="1294195822438" ID="ID_39708023" MODIFIED="1294195841085" TEXT="ifstream and ofstream are limited instances of fstream"/>
<node CREATED="1294195841799" ID="ID_643772642" MODIFIED="1294195855805" TEXT="They have default file access modes"/>
<node CREATED="1294195856014" ID="ID_476303504" MODIFIED="1294195861528" TEXT="ifstream -- ios::in"/>
<node CREATED="1294195861665" ID="ID_267092669" MODIFIED="1294195873268" TEXT="ofstream -- ios::out | ios:trunc"/>
</node>
</node>
<node CREATED="1294197490808" ID="ID_1689076843" MODIFIED="1294197513852" TEXT="Other">
<node CREATED="1294196333413" ID="ID_1093186676" MODIFIED="1294196342894" TEXT="Testing for errors">
<node CREATED="1294196342895" ID="ID_349421045" MODIFIED="1294196368078" TEXT="fstream objects have several functions to test for errors">
<node CREATED="1294196368446" ID="ID_727305137" MODIFIED="1294196387445" TEXT=".eof() -- true if the end of file was encountered"/>
<node CREATED="1294196388328" ID="ID_1064635268" MODIFIED="1294196435337" TEXT=".fail() -- true if last operation failed"/>
<node CREATED="1294196435585" ID="ID_1144893787" MODIFIED="1294196454963" TEXT=".bad() -- true if invalid operation was attempted"/>
<node CREATED="1294196455163" ID="ID_682720584" MODIFIED="1294196464886" TEXT=".good() -- true if object is in a good state"/>
</node>
<node CREATED="1294196465712" ID="ID_1810194823" MODIFIED="1294196472672" TEXT="These flags can be cleared">
<node CREATED="1294196472673" ID="ID_967386445" MODIFIED="1294196481558" TEXT=".clear() -- reset all error state flags"/>
</node>
</node>
<node CREATED="1294196495343" ID="ID_407653633" MODIFIED="1294196520212" TEXT="Pre-opened fstreams">
<node CREATED="1294196499687" ID="ID_321272075" MODIFIED="1294196531824" TEXT="cin -- a pre-opened instance of ifstream"/>
<node CREATED="1294196531986" ID="ID_861697003" MODIFIED="1294196541965" TEXT="cout -- a pre-opened instance of ofstream"/>
<node CREATED="1294196542295" ID="ID_293645857" MODIFIED="1294196557995" TEXT="The member functions you have used with cin and cout are valid on other fstreams">
<node CREATED="1294196557996" ID="ID_1493761964" MODIFIED="1294196562625" TEXT=".getline()"/>
<node CREATED="1294196563017" ID="ID_706447477" MODIFIED="1294196565138" TEXT=".get()"/>
<node CREATED="1294196565923" ID="ID_1783203502" MODIFIED="1294196568051" TEXT=".put()"/>
<node CREATED="1294196568275" ID="ID_725333753" MODIFIED="1294196570437" TEXT="etc."/>
</node>
</node>
<node CREATED="1294196126245" ID="ID_663087480" MODIFIED="1294196131172" TEXT="Output formatting">
<node CREATED="1294196131173" ID="ID_433577624" MODIFIED="1294196148190" TEXT="File output may be formatted using output manipulators"/>
<node CREATED="1294196148457" ID="ID_728887498" MODIFIED="1294196160646" TEXT="Same manipulators used with \emph{cout}"/>
<node CREATED="1294196199226" ID="ID_1901675414" MODIFIED="1294196204964">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <img src="outputFormatting.png" />
  </body>
</html></richcontent>
</node>
</node>
<node CREATED="1294196219172" ID="ID_407090765" MODIFIED="1294197644545" TEXT="Passing an fstream instance">
<node CREATED="1294196228421" ID="ID_1030739315" MODIFIED="1294196242151" TEXT="A file stream should always be passed by reference"/>
<node CREATED="1294196242808" ID="ID_597711624" MODIFIED="1294196254660" TEXT="Almost all file operations change the file instance"/>
<node CREATED="1294196313339" ID="ID_1076913643" MODIFIED="1294196319820">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <img src="passingFstreams.png" />
  </body>
</html></richcontent>
</node>
</node>
</node>
</node>
<node CREATED="1294183686521" ID="ID_1675316563" MODIFIED="1294197710698" POSITION="right" TEXT="Binary Files">
<node CREATED="1294197672563" ID="ID_129796749" MODIFIED="1294197686516" TEXT="Overview">
<node CREATED="1294196611481" FOLDED="true" ID="ID_569848767" MODIFIED="1294197684210" TEXT="Binary files">
<node CREATED="1294196616916" ID="ID_447624858" MODIFIED="1294196625306" TEXT="Binary files are not restricted to ASCII text"/>
<node CREATED="1294196625738" ID="ID_677525883" MODIFIED="1294196636376" TEXT="Binary files are stored in a raw form">
<node CREATED="1294196657090" ID="ID_775528197" MODIFIED="1294196708692" TEXT="fileA.txt = `1&apos;,`2&apos;,`3&apos;,`4&apos;,`.&apos;,`5&apos;,`6&apos;,`7&apos;"/>
<node CREATED="1294196709740" ID="ID_1463114160" MODIFIED="1294196718562" TEXT="fileB.txt = 0x7342AB09"/>
</node>
<node CREATED="1294196637144" ID="ID_1663914271" MODIFIED="1294196656130" TEXT="They cannot be printed or edited with a text editor"/>
<node CREATED="1294196813280" ID="ID_1945690146" MODIFIED="1294196816168">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <img src="binaryOutput.png" />
  </body>
</html></richcontent>
</node>
</node>
<node CREATED="1294196827479" FOLDED="true" ID="ID_884042638" MODIFIED="1294196917753" TEXT="What good are binary files">
<node CREATED="1294196832208" ID="ID_668415252" MODIFIED="1294196836264" TEXT="Faster">
<node CREATED="1294196836265" ID="ID_1828379019" MODIFIED="1294196843712" TEXT="Data does not have to be converted to text"/>
</node>
<node CREATED="1294196846200" ID="ID_1345167794" MODIFIED="1294196848541" TEXT="Smaller">
<node CREATED="1294196854356" ID="ID_632476217" MODIFIED="1294196864394" TEXT="Raw data storage is more compact"/>
</node>
<node CREATED="1294196848737" ID="ID_1824913216" MODIFIED="1294196850787" TEXT="More Secure">
<node CREATED="1294196866098" ID="ID_283583166" MODIFIED="1294196882465" TEXT="Raw data cannot be viewed with a text editor or printed"/>
</node>
<node CREATED="1294196850971" ID="ID_672529752" MODIFIED="1294196853469" TEXT="More Versatile">
<node CREATED="1294196883379" ID="ID_342267002" MODIFIED="1294196899450" TEXT="Any ADT can be output or input using a binary file"/>
</node>
</node>
</node>
<node CREATED="1294197697591" ID="ID_1578344649" MODIFIED="1294197702283" TEXT="Member Functions">
<node CREATED="1294196918188" ID="ID_1289153312" MODIFIED="1294196929473" TEXT="Binary file member functions">
<node CREATED="1294196929794" ID="ID_889708133" MODIFIED="1294196951301" TEXT="A general read or write"/>
<node CREATED="1294196951725" ID="ID_494380223" MODIFIED="1294196957865" TEXT="Start at a given address"/>
<node CREATED="1294196958160" ID="ID_78726576" MODIFIED="1294196965075" TEXT="Read or write size bytes"/>
<node CREATED="1294197029820" ID="ID_985380229" MODIFIED="1294197041727" TEXT="Do not use with pointers">
<node CREATED="1294197041728" ID="ID_1645772142" MODIFIED="1294197052992" TEXT="The pointer may not be valid when read"/>
<node CREATED="1294197053256" ID="ID_447706862" MODIFIED="1294197059308" TEXT="String contains pointers"/>
</node>
<node CREATED="1294197018127" ID="ID_876187141" MODIFIED="1294197022114">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <img src="readWrite.png" />
  </body>
</html></richcontent>
</node>
</node>
<node CREATED="1294197194470" FOLDED="true" ID="ID_214398641" MODIFIED="1294197410318" TEXT="Random Access">
<node CREATED="1294197199511" ID="ID_137346709" MODIFIED="1294197216576" TEXT="Files of struct or class instances can be accessed randomly">
<node CREATED="1294197217338" ID="ID_793100614" MODIFIED="1294197223796" TEXT="Instances must be the same size"/>
</node>
<node CREATED="1294197227103" FOLDED="true" ID="ID_494900088" MODIFIED="1294197358649" TEXT="Two member functions">
<node CREATED="1294197239252" ID="ID_579570816" MODIFIED="1294197345353" TEXT=".seekg(position,relativeFlag) -- sets the position of the get pointer"/>
<node CREATED="1294197249450" ID="ID_1658651558" MODIFIED="1294197357826" TEXT=".seekp(position,relativeFlag) -- sets the position of the put pointer"/>
<node CREATED="1294197261296" ID="ID_1339384164" MODIFIED="1294197307942" TEXT="Note -- \emph{In most implementations there is only one pointer, so both functions affect both reading and writing}"/>
</node>
<node CREATED="1294197359217" ID="ID_838724143" MODIFIED="1294197366714" TEXT="Possible Relative Flags are:">
<node CREATED="1294197366715" ID="ID_427974604" MODIFIED="1294197383476" TEXT="ios::beg -- position relative to the file beginning"/>
<node CREATED="1294197383701" ID="ID_265334590" MODIFIED="1294197391808" TEXT="ios::end -- position relative to the file end"/>
<node CREATED="1294197391969" ID="ID_1226529169" MODIFIED="1294197403434" TEXT="ios::cur -- position relative to the current file position"/>
</node>
</node>
</node>
<node CREATED="1294197710698" ID="ID_241057774" MODIFIED="1294197712952" TEXT="Example">
<node CREATED="1294197169850" ID="ID_1810165804" MODIFIED="1294197172724" TEXT="Example">
<node CREATED="1294197173164" ID="ID_446410658" MODIFIED="1294197176222">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <img src="binaryFileExample.png" />
  </body>
</html></richcontent>
</node>
</node>
</node>
</node>
</node>
</map>
