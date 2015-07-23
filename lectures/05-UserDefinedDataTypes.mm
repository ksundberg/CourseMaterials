<map version="freeplane 1.2.0">
<!--To view this file, download free mind mapping software Freeplane from http://freeplane.sourceforge.net -->
<node TEXT="05 - User Defined Data Types" ID="ID_335894322" CREATED="1432062936004" MODIFIED="1433195760859">
<attribute NAME="author" VALUE="Kenneth Sundberg"/>
<attribute NAME="date" VALUE=""/>
<attribute NAME="subtitle" VALUE="CS 1400 - Lecture 5"/>
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
<node TEXT="Abstraction" POSITION="right" ID="ID_990208093" CREATED="1436898895704" MODIFIED="1436898903938">
<node TEXT="Why" ID="ID_1977769798" CREATED="1436898903948" MODIFIED="1436898913249">
<node TEXT="Basic Types" ID="ID_885932014" CREATED="1436898920913" MODIFIED="1436898927658">
<node TEXT="Built in types map well to what is available in hardware" ID="ID_1193757515" CREATED="1436898927670" MODIFIED="1436898962337"/>
<node TEXT="They are low-level and detail oriented" ID="ID_886533561" CREATED="1436898963097" MODIFIED="1436898987786">
<node TEXT="Increases length and complexity of code" ID="ID_1599001398" CREATED="1436898987796" MODIFIED="1436898995990"/>
<node TEXT="Can become a design limitation" ID="ID_1705889948" CREATED="1436898996441" MODIFIED="1436899004521"/>
</node>
</node>
<node TEXT="Abstract Data Types" ID="ID_1326108307" CREATED="1436899015073" MODIFIED="1436899027794">
<node TEXT="User defined" ID="ID_1037475825" CREATED="1436899027800" MODIFIED="1436899060872">
<node TEXT="Map well to problem domain" ID="ID_1967368591" CREATED="1436899060877" MODIFIED="1436899067636"/>
</node>
<node TEXT="They are high-level and problem domain oriented" ID="ID_676757292" CREATED="1436899074223" MODIFIED="1436899090032">
<node TEXT="Hide complexity in a useful way" ID="ID_298973286" CREATED="1436899090037" MODIFIED="1436899100264"/>
<node TEXT="Can be central to design" ID="ID_614587963" CREATED="1436899100961" MODIFIED="1436899110569"/>
</node>
</node>
</node>
<node TEXT="How" ID="ID_1036110627" CREATED="1436899130257" MODIFIED="1436899146633">
<node TEXT="Object Oriented Programming" ID="ID_1739451542" CREATED="1433195762024" MODIFIED="1435363945981">
<attribute NAME="textbook" VALUE="7-02"/>
<node TEXT="Design method that focuses on types in the system" ID="ID_1587257719" CREATED="1436899156737" MODIFIED="1436899168986"/>
<node TEXT="Domain Modeling" ID="ID_1669446672" CREATED="1436899176344" MODIFIED="1436899188694">
<node TEXT="What types exist in the problem domain" ID="ID_1977582359" CREATED="1436899190648" MODIFIED="1436899222312"/>
<node TEXT="What are their relationships" ID="ID_70319045" CREATED="1436899222631" MODIFIED="1436899228232"/>
<node TEXT="What are their responsibilities" ID="ID_375475118" CREATED="1436899228785" MODIFIED="1436899234937"/>
</node>
</node>
<node TEXT="CRC Cards" ID="ID_148765140" CREATED="1436899273785" MODIFIED="1436899289010">
<node TEXT="Class - Responsibility - Collaborator" ID="ID_215007481" CREATED="1436899289016" MODIFIED="1436899304662"/>
<node TEXT="For every kind of type (a \emph{class}) needed by the system it should have:" ID="ID_1371763161" CREATED="1436899318617" MODIFIED="1436899344902">
<node TEXT="A name" ID="ID_732684206" CREATED="1436899345905" MODIFIED="1436899347838"/>
<node TEXT="A responsibility" ID="ID_938184213" CREATED="1436899348217" MODIFIED="1436899351366"/>
<node TEXT="A clear list of other objects it needs to know about to do its job" ID="ID_1411035519" CREATED="1436899351711" MODIFIED="1436899364742"/>
</node>
<node TEXT="Like functions classes should:" ID="ID_1621168975" CREATED="1436899367569" MODIFIED="1436899374777">
<node TEXT="Have a clear and limited responsibility" ID="ID_45261586" CREATED="1436899374783" MODIFIED="1436899382121"/>
<node TEXT="Have the smallest surface area possible while still being effective" ID="ID_112610326" CREATED="1436899382383" MODIFIED="1436899403201"/>
</node>
</node>
<node TEXT="Class Relationships" ID="ID_1129579473" CREATED="1436899406545" MODIFIED="1436899413274">
<node TEXT="Friendship" ID="ID_573201249" CREATED="1437096180437" MODIFIED="1437096184507">
<node TEXT="A very strong relation to be used with caution" ID="ID_1442368188" CREATED="1437096184512" MODIFIED="1437096208086"/>
<node TEXT="Of limited general utility" ID="ID_268832197" CREATED="1437096208386" MODIFIED="1437096232506"/>
</node>
<node TEXT="Inheritance" ID="ID_1275056911" CREATED="1436899413281" MODIFIED="1436899422666">
<node TEXT="More on this next semester" ID="ID_987918726" CREATED="1436899422672" MODIFIED="1436899429070"/>
<node TEXT="A very strong relation to be used with caution" ID="ID_18452065" CREATED="1436899429295" MODIFIED="1436899436614"/>
</node>
<node TEXT="Composition" ID="ID_1964044384" CREATED="1436899437415" MODIFIED="1436899442625">
<node TEXT="When an object is made of other objects" ID="ID_1252636559" CREATED="1436899442631" MODIFIED="1436899463863"/>
</node>
<node TEXT="Aggregation" ID="ID_87165993" CREATED="1436899464793" MODIFIED="1436899468546">
<node TEXT="When an object knows of other objects" ID="ID_1616015034" CREATED="1436899468554" MODIFIED="1436899476505"/>
</node>
</node>
<node TEXT="UML Class Diagrams" ID="ID_1480301900" CREATED="1436899482393" MODIFIED="1436899491722">
<node TEXT="A standard way to draw classes and their relationships" ID="ID_1705770925" CREATED="1436899491730" MODIFIED="1436899503904"/>
</node>
</node>
</node>
<node TEXT="Strategies" POSITION="right" ID="ID_1697542487" CREATED="1436907852186" MODIFIED="1436907878946">
<node TEXT="Simple Types" ID="ID_1779262952" CREATED="1436907878950" MODIFIED="1436907890514">
<node TEXT="Finite Types" ID="ID_366280937" CREATED="1436907890520" MODIFIED="1436908244572">
<attribute NAME="textbook" VALUE="4-13"/>
<node TEXT="Some types can only take a finite number of values" ID="ID_1939701487" CREATED="1436907898741" MODIFIED="1436907920489"/>
<node TEXT="Only viable if it is reasonable to list all possible values" ID="ID_406671500" CREATED="1436907945433" MODIFIED="1436907965447"/>
<node TEXT="Also called \emph{enumerations}" ID="ID_457595933" CREATED="1436908219442" MODIFIED="1436908233558"/>
<node TEXT="Two ways:" ID="ID_830851880" CREATED="1436907965689" MODIFIED="1436907971882">
<node TEXT="enum" ID="ID_1075101286" CREATED="1436907971887" MODIFIED="1436907976185"/>
<node TEXT="enum class" ID="ID_1227498326" CREATED="1436907976626" MODIFIED="1436907978983"/>
</node>
</node>
<node TEXT="Enum example" LOCALIZED_STYLE_REF="styles.important" ID="ID_266218296" CREATED="1436907982849" MODIFIED="1436908154464">
<node TEXT="enum Color" ID="ID_2558188" CREATED="1436907990815" MODIFIED="1436908024775"/>
<node TEXT="{" ID="ID_884538084" CREATED="1436907998530" MODIFIED="1436907999618"/>
<node TEXT="  RED," ID="ID_797033604" CREATED="1436908000154" MODIFIED="1436908004495"/>
<node TEXT="  ORANGE," ID="ID_136211836" CREATED="1436908030538" MODIFIED="1436908034647"/>
<node TEXT="  YELLOW," ID="ID_934718132" CREATED="1436908035345" MODIFIED="1436908038235"/>
<node TEXT="  GREEN," ID="ID_401293092" CREATED="1436908004953" MODIFIED="1436908007735"/>
<node TEXT="  BLUE," ID="ID_1183753966" CREATED="1436908008146" MODIFIED="1436908050160"/>
<node TEXT="  VIOLET" ID="ID_1773839767" CREATED="1436908050690" MODIFIED="1436908055376"/>
<node TEXT="};" ID="ID_232458415" CREATED="1436908012081" MODIFIED="1436908413823"/>
<node TEXT="Color c = RED;" ID="ID_364013233" CREATED="1436908069201" MODIFIED="1436908089320"/>
</node>
<node TEXT="Enum class example" LOCALIZED_STYLE_REF="styles.important" ID="ID_995707005" CREATED="1436908091361" MODIFIED="1436908154460">
<node TEXT="enum class Color" ID="ID_1779440242" CREATED="1436908098244" MODIFIED="1436908102295"/>
<node TEXT="{" ID="ID_1305868092" CREATED="1436907998530" MODIFIED="1436907999618"/>
<node TEXT="  RED," ID="ID_397939131" CREATED="1436908000154" MODIFIED="1436908004495"/>
<node TEXT="  ORANGE," ID="ID_1507445003" CREATED="1436908030538" MODIFIED="1436908034647"/>
<node TEXT="  YELLOW," ID="ID_1158237601" CREATED="1436908035345" MODIFIED="1436908038235"/>
<node TEXT="  GREEN," ID="ID_1667753770" CREATED="1436908004953" MODIFIED="1436908007735"/>
<node TEXT="  BLUE," ID="ID_1055527695" CREATED="1436908008146" MODIFIED="1436908050160"/>
<node TEXT="  VIOLET" ID="ID_1301244019" CREATED="1436908050690" MODIFIED="1436908055376"/>
<node TEXT="};" ID="ID_4055148" CREATED="1436908012081" MODIFIED="1436908409255"/>
<node TEXT="Color c = Color::RED;" ID="ID_931953906" CREATED="1436908131153" MODIFIED="1436908143769"/>
</node>
<node TEXT="Structures" ID="ID_573913726" CREATED="1436908277850" MODIFIED="1436908321674">
<node TEXT="A simple composition of types" ID="ID_1124816444" CREATED="1436908321677" MODIFIED="1436908352464"/>
<node TEXT="Use the . operator to access member types" ID="ID_1234551607" CREATED="1436908354098" MODIFIED="1436908373208"/>
<node TEXT="Parts of a structure are called \emph{members}" ID="ID_1216403273" CREATED="1436908471098" MODIFIED="1436908480156"/>
</node>
<node TEXT="struct example" LOCALIZED_STYLE_REF="styles.important" ID="ID_708480638" CREATED="1436908378497" MODIFIED="1436908438124">
<node TEXT="struct Point" ID="ID_715832003" CREATED="1436908383991" MODIFIED="1436908388534"/>
<node TEXT="{" ID="ID_1631633956" CREATED="1436908389033" MODIFIED="1436908390331"/>
<node TEXT="  double x;" ID="ID_659425914" CREATED="1436908390770" MODIFIED="1436908394400"/>
<node TEXT="  double y;" ID="ID_681706126" CREATED="1436908394793" MODIFIED="1436908397375"/>
<node TEXT="};" ID="ID_1913308316" CREATED="1436908397841" MODIFIED="1436908402439"/>
<node TEXT="" ID="ID_1955377787" CREATED="1436908418641" MODIFIED="1436908418641"/>
<node TEXT="Point p;" ID="ID_279155696" CREATED="1436908419553" MODIFIED="1436908423207"/>
<node TEXT="p.x = 1.3;" ID="ID_334376659" CREATED="1436908423610" MODIFIED="1436908430727"/>
</node>
<node TEXT="Type Aliasing" ID="ID_1338027272" CREATED="1433195990263" MODIFIED="1436996954630">
<attribute NAME="textbook" VALUE="8-07"/>
<node TEXT="Sometimes you just want to call a type a different name" ID="ID_1215159304" CREATED="1436996991223" MODIFIED="1436997001663"/>
<node TEXT="This is of somewhat limited utility" ID="ID_1167276596" CREATED="1436997002136" MODIFIED="1436997028488"/>
<node TEXT="Two styles" ID="ID_1347110539" CREATED="1436997028815" MODIFIED="1436997032824">
<node TEXT="typedef" ID="ID_970571600" CREATED="1436996924769" MODIFIED="1436996930496"/>
<node TEXT="using" ID="ID_76207983" CREATED="1436996930920" MODIFIED="1436996932015"/>
</node>
</node>
<node TEXT="Typedef and Using Example" LOCALIZED_STYLE_REF="styles.important" ID="ID_395441793" CREATED="1436997041919" MODIFIED="1436997092744">
<node TEXT="typedef int MyInt1;" ID="ID_135221190" CREATED="1436997051511" MODIFIED="1436997064317"/>
<node TEXT="using MyInt2 = int;" ID="ID_1541137231" CREATED="1436997064726" MODIFIED="1436997073677"/>
</node>
</node>
<node TEXT="Classes" ID="ID_1884267436" CREATED="1432063021768" MODIFIED="1432063029774">
<node TEXT="Defining Classes" ID="ID_543411180" CREATED="1433195797031" MODIFIED="1435363985188">
<attribute NAME="textbook" VALUE="7-01"/>
<attribute NAME="textbook" VALUE="7-03"/>
<node TEXT="A class defines a new kind of type" ID="ID_564038045" CREATED="1437096289225" MODIFIED="1437096303873"/>
<node TEXT="Two parts:" ID="ID_1650544595" CREATED="1437096305617" MODIFIED="1437096351794">
<node TEXT="Data -- What is stored in memory" ID="ID_449293464" CREATED="1437096351801" MODIFIED="1437096362273"/>
<node TEXT="Methods -- What actions are defined for this type?" ID="ID_1367325162" CREATED="1437096362744" MODIFIED="1437096381359"/>
</node>
<node TEXT="Parts of a class are called \emph{members} of the class" ID="ID_1787159008" CREATED="1437096403304" MODIFIED="1437096415346"/>
</node>
<node TEXT="Access Control" ID="ID_1592366107" CREATED="1433195821975" MODIFIED="1433195830012">
<node TEXT="Classes provide access control in three levels" ID="ID_427524858" CREATED="1437096452042" MODIFIED="1437096463769">
<node TEXT="Public -- Any code can access" ID="ID_829925859" CREATED="1433195830013" MODIFIED="1437096478092"/>
<node TEXT="Protected -- Only member code of this class or any class derived from it can access" ID="ID_1199762848" CREATED="1433195834207" MODIFIED="1437096507569"/>
<node TEXT="Private -- Only member code can access" ID="ID_659375602" CREATED="1433195832327" MODIFIED="1437096486574"/>
</node>
<node TEXT="While not syntactically required the order should be public, protected then private" LOCALIZED_STYLE_REF="styles.topic" ID="ID_1862844231" CREATED="1437097229649" MODIFIED="1437097259060"/>
<node TEXT="Member functions can be at any access level" ID="ID_52244882" CREATED="1437096513018" MODIFIED="1437096528489"/>
<node TEXT="Member data should be only at the private access level" ID="ID_699493821" CREATED="1437096528720" MODIFIED="1437096539382"/>
</node>
<node TEXT="Class v Struct" ID="ID_78780773" CREATED="1437097717106" MODIFIED="1437097721867">
<node TEXT="The only difference between class and struct is the default access level" ID="ID_172527311" CREATED="1437097721875" MODIFIED="1437097732591"/>
<node TEXT="The default for struct is public" ID="ID_66462122" CREATED="1437097732840" MODIFIED="1437097738511"/>
<node TEXT="The default for class is private" ID="ID_813906036" CREATED="1437097738866" MODIFIED="1437097743297"/>
</node>
<node TEXT="Constructors" ID="ID_134877493" CREATED="1433195776823" MODIFIED="1435363916247">
<attribute NAME="textbook" VALUE="7-06"/>
<node TEXT="Special function called when an instance of a class is created" LOCALIZED_STYLE_REF="styles.topic" ID="ID_1020007836" CREATED="1437096637354" MODIFIED="1437096886435">
<node TEXT="Insures that all member data is initialized correctly" ID="ID_1554494363" CREATED="1437096652978" MODIFIED="1437096662801"/>
<node TEXT="Body should be empty" ID="ID_972133961" CREATED="1437096847642" MODIFIED="1437096855305"/>
<node TEXT="Initialization occurs in member initialization list" ID="ID_1535261480" CREATED="1437096857106" MODIFIED="1437096866994"/>
</node>
<node TEXT="There are a number of important variations" LOCALIZED_STYLE_REF="styles.topic" ID="ID_1751375226" CREATED="1437096663273" MODIFIED="1437096886438">
<node TEXT="Default constructor -- takes no arguments, may not be present" ID="ID_1577638040" CREATED="1437096671570" MODIFIED="1437096688600"/>
<node TEXT="Copy constructor -- takes another instance of the class, called when class is passed as argument or returned from function" ID="ID_156912287" CREATED="1437096689064" MODIFIED="1437096716065"/>
<node TEXT="Others ... more on them next semester" ID="ID_970979880" CREATED="1437096725210" MODIFIED="1437096734626"/>
</node>
<node TEXT="If your class is \emph{Plain Old Data} (POD) then several of these are provided by default" ID="ID_241115040" CREATED="1437096766906" MODIFIED="1437096793089"/>
</node>
<node TEXT="Destructors" ID="ID_385699024" CREATED="1433195792207" MODIFIED="1433195794412">
<node TEXT="Contains all of the magic of C++" LOCALIZED_STYLE_REF="styles.topic" ID="ID_232100801" CREATED="1437096559218" MODIFIED="1437096628185"/>
<node TEXT="Destructors are a special function that is called whenever an instance of a class goes out of scope" ID="ID_538926148" CREATED="1437096567850" MODIFIED="1437096587903"/>
<node TEXT="Used to clean up any resources used by the class" ID="ID_1806878971" CREATED="1437096588369" MODIFIED="1437096612313"/>
</node>
<node TEXT="Functions" ID="ID_441223382" CREATED="1433195810695" MODIFIED="1435364027337">
<attribute NAME="textbook" VALUE="7-08"/>
<attribute NAME="textbook" VALUE="7-05"/>
<node TEXT="Member functions are invoked using . operator" ID="ID_1938558335" CREATED="1437096998730" MODIFIED="1437097008094"/>
<node TEXT="Responsible for maintaining class invariants" ID="ID_576015165" CREATED="1437097053103" MODIFIED="1437097061926"/>
<node TEXT="Represent the valid actions with this object" ID="ID_999483462" CREATED="1437097008344" MODIFIED="1437097019161"/>
<node TEXT="Prefer non-member non-friend functions when possible" ID="ID_1969402031" CREATED="1437097019697" MODIFIED="1437097044225"/>
</node>
<node TEXT="Variables" ID="ID_560001136" CREATED="1433195812871" MODIFIED="1435364073196">
<attribute NAME="textbook" VALUE="7-04"/>
<attribute NAME="textbook" VALUE="7-10"/>
<node TEXT="Represent the state or value of the object" ID="ID_1856589471" CREATED="1437097064569" MODIFIED="1437097072025"/>
<node TEXT="State should be private unless all possible combinations of all possible values and all possible transitions between these combinations are acceptable.  If so just use a struct" ID="ID_1827757786" CREATED="1437097076130" MODIFIED="1437097128482"/>
<node TEXT="Mutator and Accessor functions should be provided to inspect and modify the state of an object" ID="ID_722319905" CREATED="1437097131473" MODIFIED="1437097173565"/>
</node>
<node TEXT="Circle Example" LOCALIZED_STYLE_REF="styles.important" ID="ID_1131980773" CREATED="1437097277736" MODIFIED="1437097416366">
<node TEXT="class Circle" ID="ID_1211753363" CREATED="1437097285232" MODIFIED="1437097289096"/>
<node TEXT="{ public:" ID="ID_1748673526" CREATED="1437097289344" MODIFIED="1437097294073"/>
<node TEXT="  void setRadius(double radius)" ID="ID_1590155037" CREATED="1437097294602" MODIFIED="1437499518565"/>
<node TEXT="    {m_r2 = radius * radius;}" ID="ID_1759477777" CREATED="1437499519048" MODIFIED="1437499525031"/>
<node TEXT="  double getArea(){return m_r2 * 3.14159;}" ID="ID_525139746" CREATED="1437097345567" MODIFIED="1437097362583"/>
<node TEXT="private:" ID="ID_830765245" CREATED="1437097363161" MODIFIED="1437097368110"/>
<node TEXT="  double m_r2; //radius squared" ID="ID_444390941" CREATED="1437097368826" MODIFIED="1437097378704"/>
<node TEXT="};" ID="ID_905568414" CREATED="1437097379408" MODIFIED="1437097381530"/>
<node TEXT="" ID="ID_988959974" CREATED="1437097381986" MODIFIED="1437097381986"/>
<node TEXT="Circle c;" ID="ID_1345161586" CREATED="1437097382761" MODIFIED="1437097386353"/>
<node TEXT="c.setRadius(1.0);" ID="ID_1751252698" CREATED="1437097386642" MODIFIED="1437097393593"/>
<node TEXT="std::cout &lt;&lt; c.getArea() &lt;&lt; std::endl;" ID="ID_1002867438" CREATED="1437097394002" MODIFIED="1437097408808"/>
</node>
</node>
</node>
</node>
</map>
