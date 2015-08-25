<map version="freeplane 1.2.0">
<!--To view this file, download free mind mapping software Freeplane from http://freeplane.sourceforge.net -->
<node TEXT="Advanced File Operations" ID="ID_1613209657" CREATED="1294183339516" MODIFIED="1294183406505">
<attribute NAME="theme" VALUE="Warsaw"/>
<attribute NAME="author" VALUE="Kenneth Sundberg"/>
<attribute NAME="subtitle" VALUE="CS 1410 -- Chapter 12"/>
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
<node TEXT="Fstream ADT" POSITION="right" ID="ID_350219439" CREATED="1294183698727" MODIFIED="1294183707314">
<node TEXT="Overview" ID="ID_1719203816" CREATED="1294197474368" MODIFIED="1294197482413">
<node TEXT="Types" ID="ID_166197721" CREATED="1294183431333" MODIFIED="1440109127275">
<attribute NAME="textbook" VALUE="13-01"/>
<node TEXT="ifstream -- Input file stream" ID="ID_348492561" CREATED="1294183441306" MODIFIED="1294183449805">
<node TEXT="may only be used for input from an existing file" ID="ID_1559907786" CREATED="1294183449807" MODIFIED="1294183457956"/>
</node>
<node TEXT="ofstream -- Output file stream" ID="ID_748993644" CREATED="1294183458912" MODIFIED="1294183464749">
<node TEXT="may only be used to create and output to a file" ID="ID_1312598167" CREATED="1294183464750" MODIFIED="1294183475909"/>
</node>
<node TEXT="fstream -- General file stream" ID="ID_913877115" CREATED="1294183476704" MODIFIED="1294183493908">
<node TEXT="may be used to create, read, and output to a file" ID="ID_451474148" CREATED="1294183493909" MODIFIED="1294183502082"/>
</node>
</node>
</node>
<node TEXT="Initialization" ID="ID_1845734534" CREATED="1294197482812" MODIFIED="1294197654618">
<node TEXT="Opening " ID="ID_505353048" CREATED="1294183515892" MODIFIED="1294195887679">
<node TEXT="A file must be opened prior to use" ID="ID_180360004" CREATED="1294195440572" MODIFIED="1294195454574"/>
<node TEXT="The \emph{open} member function uses two arguments" ID="ID_875658357" CREATED="1294195458713" MODIFIED="1294195470873">
<node TEXT="The file name" ID="ID_1870907862" CREATED="1294195470874" MODIFIED="1294195481492"/>
<node TEXT="The access flag" ID="ID_1794856353" CREATED="1294195481669" MODIFIED="1294195488775"/>
</node>
<hook URI="figures/fstreamOpen.png" SIZE="0.25" NAME="ExternalObject"/>
</node>
<node TEXT="Open at declaration" ID="ID_1638476141" CREATED="1294195891712" MODIFIED="1294195904638">
<node ID="ID_114306208" CREATED="1294196039754" MODIFIED="1294196056766"><richcontent TYPE="NODE">

<html>
  <head>
    
  </head>
  <body>
    <img src="fstreamOpenA.png" />
  </body>
</html>
</richcontent>
</node>
<node TEXT="Files may be opened as the fstream is declared" ID="ID_942114822" CREATED="1294196071266" MODIFIED="1294196080284"/>
</node>
<node TEXT="Open at declaration" ID="ID_1921803547" CREATED="1294196082872" MODIFIED="1294197576719">
<node ID="ID_212614331" CREATED="1294196083284" MODIFIED="1294196090435"><richcontent TYPE="NODE">

<html>
  <head>
    
  </head>
  <body>
    <img src="fstreamOpenB.png" />
  </body>
</html>
</richcontent>
</node>
<node TEXT="This is equivalent" ID="ID_1602032218" CREATED="1294196091500" MODIFIED="1294196100912"/>
</node>
</node>
<node TEXT="Access Flags" ID="ID_795649038" CREATED="1294197618512" MODIFIED="1294197621522">
<node TEXT="Access Flags" ID="ID_312648895" CREATED="1294195625357" MODIFIED="1294197623439">
<node TEXT="ios::app -- append to an existing file" ID="ID_563288883" CREATED="1294195630867" MODIFIED="1294195644003"/>
<node TEXT="ios::binary -- write data in binary format" ID="ID_282518408" CREATED="1294195644278" MODIFIED="1294195653810"/>
<node TEXT="ios::in -- file is to be used for input" ID="ID_41814471" CREATED="1294195653995" MODIFIED="1294195667929"/>
<node TEXT="ios::out -- file is to be used for output" ID="ID_58830195" CREATED="1294195668090" MODIFIED="1294195676453"/>
<node TEXT="ios::trunc -- discard previous file contents" ID="ID_1894909465" CREATED="1294195676614" MODIFIED="1294195689794"/>
<node TEXT="ios::text -- write data in text format" ID="ID_503231293" CREATED="1294195689965" MODIFIED="1294195701202"/>
<node TEXT="others" ID="ID_991486193" CREATED="1294195701563" MODIFIED="1294195703595"/>
</node>
<node TEXT="Combining file access flags" ID="ID_60589953" CREATED="1294195716435" MODIFIED="1294195723561">
<node TEXT="Access flags may be combined using the bitwise-or operator" ID="ID_1229877160" CREATED="1294195723562" MODIFIED="1294195744975"/>
<node ID="ID_1326308343" CREATED="1294195783508" MODIFIED="1294195789559"><richcontent TYPE="NODE">

<html>
  <head>
    
  </head>
  <body>
    <img src="combinedFlags.png" />
  </body>
</html>
</richcontent>
</node>
</node>
<node TEXT="ifstream and ofstream" ID="ID_427540954" CREATED="1294195796347" MODIFIED="1294195822276">
<node TEXT="ifstream and ofstream are limited instances of fstream" ID="ID_39708023" CREATED="1294195822438" MODIFIED="1294195841085"/>
<node TEXT="They have default file access modes" ID="ID_643772642" CREATED="1294195841799" MODIFIED="1294195855805"/>
<node TEXT="ifstream -- ios::in" ID="ID_476303504" CREATED="1294195856014" MODIFIED="1294195861528"/>
<node TEXT="ofstream -- ios::out | ios:trunc" ID="ID_267092669" CREATED="1294195861665" MODIFIED="1294195873268"/>
</node>
</node>
<node TEXT="Other" ID="ID_1689076843" CREATED="1294197490808" MODIFIED="1294197513852">
<node TEXT="Testing for errors" ID="ID_1093186676" CREATED="1294196333413" MODIFIED="1294196342894">
<node TEXT="fstream objects have several functions to test for errors" ID="ID_349421045" CREATED="1294196342895" MODIFIED="1294196368078">
<node TEXT=".eof() -- true if the end of file was encountered" ID="ID_727305137" CREATED="1294196368446" MODIFIED="1294196387445"/>
<node TEXT=".fail() -- true if last operation failed" ID="ID_1064635268" CREATED="1294196388328" MODIFIED="1294196435337"/>
<node TEXT=".bad() -- true if invalid operation was attempted" ID="ID_1144893787" CREATED="1294196435585" MODIFIED="1294196454963"/>
<node TEXT=".good() -- true if object is in a good state" ID="ID_682720584" CREATED="1294196455163" MODIFIED="1294196464886"/>
</node>
<node TEXT="These flags can be cleared" ID="ID_1810194823" CREATED="1294196465712" MODIFIED="1294196472672">
<node TEXT=".clear() -- reset all error state flags" ID="ID_967386445" CREATED="1294196472673" MODIFIED="1294196481558"/>
</node>
</node>
<node TEXT="Pre-opened fstreams" ID="ID_407653633" CREATED="1294196495343" MODIFIED="1294196520212">
<node TEXT="cin -- a pre-opened instance of ifstream" ID="ID_321272075" CREATED="1294196499687" MODIFIED="1294196531824"/>
<node TEXT="cout -- a pre-opened instance of ofstream" ID="ID_861697003" CREATED="1294196531986" MODIFIED="1294196541965"/>
<node TEXT="The member functions you have used with cin and cout are valid on other fstreams" ID="ID_293645857" CREATED="1294196542295" MODIFIED="1294196557995">
<node TEXT=".getline()" ID="ID_1493761964" CREATED="1294196557996" MODIFIED="1294196562625"/>
<node TEXT=".get()" ID="ID_706447477" CREATED="1294196563017" MODIFIED="1294196565138"/>
<node TEXT=".put()" ID="ID_1783203502" CREATED="1294196565923" MODIFIED="1294196568051"/>
<node TEXT="etc." ID="ID_725333753" CREATED="1294196568275" MODIFIED="1294196570437"/>
</node>
</node>
<node TEXT="Output formatting" ID="ID_663087480" CREATED="1294196126245" MODIFIED="1294196131172">
<node TEXT="File output may be formatted using output manipulators" ID="ID_433577624" CREATED="1294196131173" MODIFIED="1294196148190"/>
<node TEXT="Same manipulators used with \emph{cout}" ID="ID_728887498" CREATED="1294196148457" MODIFIED="1294196160646"/>
<node ID="ID_1901675414" CREATED="1294196199226" MODIFIED="1294196204964"><richcontent TYPE="NODE">

<html>
  <head>
    
  </head>
  <body>
    <img src="outputFormatting.png" />
  </body>
</html>
</richcontent>
</node>
</node>
<node TEXT="Passing an fstream instance" ID="ID_407090765" CREATED="1294196219172" MODIFIED="1294197644545">
<node TEXT="A file stream should always be passed by reference" ID="ID_1030739315" CREATED="1294196228421" MODIFIED="1294196242151"/>
<node TEXT="Almost all file operations change the file instance" ID="ID_597711624" CREATED="1294196242808" MODIFIED="1294196254660"/>
<node ID="ID_1076913643" CREATED="1294196313339" MODIFIED="1294196319820"><richcontent TYPE="NODE">

<html>
  <head>
    
  </head>
  <body>
    <img src="passingFstreams.png" />
  </body>
</html>
</richcontent>
</node>
</node>
</node>
</node>
<node TEXT="Binary Files" POSITION="right" ID="ID_1675316563" CREATED="1294183686521" MODIFIED="1294197710698">
<node TEXT="Overview" ID="ID_129796749" CREATED="1294197672563" MODIFIED="1440109014131">
<node TEXT="Binary files" ID="ID_569848767" CREATED="1294196611481" MODIFIED="1440109154262">
<attribute NAME="textbook" VALUE="13-04"/>
<node TEXT="Binary files are not restricted to ASCII text" ID="ID_447624858" CREATED="1294196616916" MODIFIED="1294196625306"/>
<node TEXT="Binary files are stored in a raw form" ID="ID_677525883" CREATED="1294196625738" MODIFIED="1294196636376">
<node TEXT="fileA.txt = `1&apos;,`2&apos;,`3&apos;,`4&apos;,`.&apos;,`5&apos;,`6&apos;,`7&apos;" ID="ID_775528197" CREATED="1294196657090" MODIFIED="1294196708692"/>
<node TEXT="fileB.txt = 0x7342AB09" ID="ID_1463114160" CREATED="1294196709740" MODIFIED="1294196718562"/>
</node>
<node TEXT="They cannot be printed or edited with a text editor" ID="ID_1663914271" CREATED="1294196637144" MODIFIED="1294196656130"/>
<node ID="ID_1945690146" CREATED="1294196813280" MODIFIED="1294196816168"><richcontent TYPE="NODE">

<html>
  <head>
    
  </head>
  <body>
    <img src="binaryOutput.png" />
  </body>
</html>
</richcontent>
</node>
</node>
<node TEXT="What good are binary files" ID="ID_884042638" CREATED="1294196827479" MODIFIED="1294196917753">
<node TEXT="Faster" ID="ID_668415252" CREATED="1294196832208" MODIFIED="1294196836264">
<node TEXT="Data does not have to be converted to text" ID="ID_1828379019" CREATED="1294196836265" MODIFIED="1294196843712"/>
</node>
<node TEXT="Smaller" ID="ID_1345167794" CREATED="1294196846200" MODIFIED="1294196848541">
<node TEXT="Raw data storage is more compact" ID="ID_632476217" CREATED="1294196854356" MODIFIED="1294196864394"/>
</node>
<node TEXT="More Secure" ID="ID_1824913216" CREATED="1294196848737" MODIFIED="1294196850787">
<node TEXT="Raw data cannot be viewed with a text editor or printed" ID="ID_283583166" CREATED="1294196866098" MODIFIED="1294196882465"/>
</node>
<node TEXT="More Versatile" ID="ID_672529752" CREATED="1294196850971" MODIFIED="1294196853469">
<node TEXT="Any ADT can be output or input using a binary file" ID="ID_342267002" CREATED="1294196883379" MODIFIED="1294196899450"/>
</node>
</node>
</node>
<node TEXT="Member Functions" ID="ID_1578344649" CREATED="1294197697591" MODIFIED="1294197702283">
<node TEXT="Binary file member functions" ID="ID_1289153312" CREATED="1294196918188" MODIFIED="1294196929473">
<node TEXT="A general read or write" ID="ID_889708133" CREATED="1294196929794" MODIFIED="1294196951301"/>
<node TEXT="Start at a given address" ID="ID_494380223" CREATED="1294196951725" MODIFIED="1294196957865"/>
<node TEXT="Read or write size bytes" ID="ID_78726576" CREATED="1294196958160" MODIFIED="1294196965075"/>
<node TEXT="Do not use with pointers" ID="ID_985380229" CREATED="1294197029820" MODIFIED="1294197041727">
<node TEXT="The pointer may not be valid when read" ID="ID_1645772142" CREATED="1294197041728" MODIFIED="1294197052992"/>
<node TEXT="String contains pointers" ID="ID_447706862" CREATED="1294197053256" MODIFIED="1294197059308"/>
</node>
<node ID="ID_876187141" CREATED="1294197018127" MODIFIED="1294197022114"><richcontent TYPE="NODE">

<html>
  <head>
    
  </head>
  <body>
    <img src="readWrite.png" />
  </body>
</html>
</richcontent>
</node>
</node>
<node TEXT="Random Access" ID="ID_214398641" CREATED="1294197194470" MODIFIED="1440109180058">
<attribute NAME="textbook" VALUE="13-06"/>
<node TEXT="Files of struct or class instances can be accessed randomly" ID="ID_137346709" CREATED="1294197199511" MODIFIED="1294197216576">
<node TEXT="Instances must be the same size" ID="ID_793100614" CREATED="1294197217338" MODIFIED="1294197223796"/>
</node>
<node TEXT="Two member functions" ID="ID_494900088" CREATED="1294197227103" MODIFIED="1294197358649">
<node TEXT=".seekg(position,relativeFlag) -- sets the position of the get pointer" ID="ID_579570816" CREATED="1294197239252" MODIFIED="1294197345353"/>
<node TEXT=".seekp(position,relativeFlag) -- sets the position of the put pointer" ID="ID_1658651558" CREATED="1294197249450" MODIFIED="1294197357826"/>
<node TEXT="Note -- \emph{In most implementations there is only one pointer, so both functions affect both reading and writing}" ID="ID_1339384164" CREATED="1294197261296" MODIFIED="1294197307942"/>
</node>
<node TEXT="Possible Relative Flags are:" ID="ID_838724143" CREATED="1294197359217" MODIFIED="1294197366714">
<node TEXT="ios::beg -- position relative to the file beginning" ID="ID_427974604" CREATED="1294197366715" MODIFIED="1294197383476"/>
<node TEXT="ios::end -- position relative to the file end" ID="ID_265334590" CREATED="1294197383701" MODIFIED="1294197391808"/>
<node TEXT="ios::cur -- position relative to the current file position" ID="ID_1226529169" CREATED="1294197391969" MODIFIED="1294197403434"/>
</node>
</node>
</node>
<node TEXT="Example" ID="ID_241057774" CREATED="1294197710698" MODIFIED="1294197712952">
<node TEXT="Example" ID="ID_1810165804" CREATED="1294197169850" MODIFIED="1294197172724">
<node ID="ID_446410658" CREATED="1294197173164" MODIFIED="1294197176222"><richcontent TYPE="NODE">

<html>
  <head>
    
  </head>
  <body>
    <img src="binaryFileExample.png" />
  </body>
</html>
</richcontent>
</node>
</node>
</node>
</node>
</node>
</map>
