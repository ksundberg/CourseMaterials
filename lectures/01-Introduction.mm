<map version="freeplane 1.2.0">
<!--To view this file, download free mind mapping software Freeplane from http://freeplane.sourceforge.net -->
<node TEXT="01- Introduction" ID="ID_729166855" CREATED="1430766178119" MODIFIED="1430766894971">
<attribute NAME="author" VALUE="Kenneth Sundberg"/>
<attribute NAME="date" VALUE=""/>
<attribute NAME="subtitle" VALUE="CS1400 - Lecture 1"/>
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
<node TEXT="Syllabus" POSITION="right" ID="ID_405778426" CREATED="1430766242153" MODIFIED="1432567614206">
<node TEXT="Topic Overview" ID="ID_1478149906" CREATED="1430766266105" MODIFIED="1430766274717"/>
<node TEXT="Policies" ID="ID_1049242193" CREATED="1430766258561" MODIFIED="1430766265555"/>
<node TEXT="Grading" ID="ID_565993697" CREATED="1430766279625" MODIFIED="1430766291435"/>
</node>
<node TEXT="Introduction" POSITION="right" ID="ID_1555719218" CREATED="1430766293248" MODIFIED="1430766339763">
<node TEXT="Computer Science" ID="ID_1563878077" CREATED="1430766339764" MODIFIED="1430766356052">
<node TEXT="What is Computer Science?" ID="ID_428361757" CREATED="1430766356053" MODIFIED="1430766368074"/>
<node TEXT="What do you expect to get out of this course?" ID="ID_284384720" CREATED="1430766388776" MODIFIED="1430766398589"/>
<node TEXT="What do I expect you to get out of this course?" ID="ID_1332364881" CREATED="1430766399080" MODIFIED="1430766408608">
<node TEXT="Focus on Principles not on Spelling" ID="ID_311307422" CREATED="1431978643619" MODIFIED="1431978650416"/>
</node>
</node>
<node TEXT="Problem Solving" ID="ID_1077799941" CREATED="1430766416273" MODIFIED="1430766426934">
<node TEXT="Dealing with Complexity" ID="ID_529324932" CREATED="1430766454944" MODIFIED="1432567796512">
<node TEXT="Explicit is better than Implicit" ID="ID_475719618" CREATED="1430766467353" MODIFIED="1430766486498"/>
<node TEXT="Reduce Coupling" ID="ID_1612250957" CREATED="1430766488625" MODIFIED="1430766498477"/>
<node TEXT="Use Abstraction" ID="ID_189445116" CREATED="1430766514064" MODIFIED="1430766532154"/>
<node TEXT="Keep It Simple ..." ID="ID_1897207451" CREATED="1430766532936" MODIFIED="1430766547292"/>
</node>
<node TEXT="Explicit v. Implicit" ID="ID_992880961" CREATED="1430767013681" MODIFIED="1430767023735">
<node TEXT="Much more time is spent reading/understanding code than writing" ID="ID_1458600406" CREATED="1430767023736" MODIFIED="1430767041547"/>
<node TEXT="Clarity and Correctness trump almost all other concerns" ID="ID_1309610245" CREATED="1430767042129" MODIFIED="1430767069169"/>
<node TEXT="It is usually clearer to be explicit and detailed than to assume that the reader knows what is going on" ID="ID_573137599" CREATED="1430767070001" MODIFIED="1430767091976"/>
</node>
<node TEXT="Reduce Coupling" ID="ID_1122115901" CREATED="1430767093504" MODIFIED="1430767097392">
<node TEXT="Coupling happens when one part of a program interacts with another part of a program" ID="ID_174535510" CREATED="1430767097393" MODIFIED="1430767116978"/>
<node TEXT="Interactions can be a source of subtle bugs" ID="ID_1539520271" CREATED="1430767117417" MODIFIED="1430767129770">
<node TEXT="Problems in one part of a program can manifest in another" ID="ID_1973139754" CREATED="1430767129771" MODIFIED="1430767141922"/>
</node>
<node TEXT="Coupling should be closely controlled and well understood" ID="ID_1363414419" CREATED="1430767145193" MODIFIED="1430767161070"/>
<node TEXT="Spooky action at a distance" ID="ID_913101335" CREATED="1430772308939" MODIFIED="1430772325013">
<node TEXT="Some forms of coupling are considered EVIL" ID="ID_256894946" CREATED="1430772325014" MODIFIED="1430772345105"/>
</node>
</node>
<node TEXT="Use Abstraction" ID="ID_961328050" CREATED="1430767162945" MODIFIED="1430767167698">
<node TEXT="Not every detail matters" ID="ID_1730653724" CREATED="1430767167699" MODIFIED="1430767173992"/>
<node TEXT="Assume as little as possible" ID="ID_907783709" CREATED="1430767175145" MODIFIED="1430767190370"/>
<node TEXT="Leads to more generic and more correct programs" ID="ID_733759796" CREATED="1430767190625" MODIFIED="1430767198434"/>
</node>
<node TEXT="Keep It Simple ..." ID="ID_979291179" CREATED="1430767200481" MODIFIED="1430767207591">
<node TEXT="It is harder to debug a program than it is to write a program" ID="ID_657783241" CREATED="1430767207592" MODIFIED="1430767219930">
<node TEXT="If you write at the limits of your ability, your code will be beyond your ability to debug" ID="ID_777733953" CREATED="1430767219931" MODIFIED="1430767240146"/>
</node>
<node TEXT="Don&apos;t be clever, be correct" ID="ID_546355644" CREATED="1430767242736" MODIFIED="1430767256748"/>
</node>
<node TEXT="Top-down Approach" ID="ID_712677728" CREATED="1430766427512" MODIFIED="1430766932246">
<node TEXT="Break big problems into smaller problems" ID="ID_763725384" CREATED="1430766589265" MODIFIED="1430766817772"/>
<node TEXT="Eventually the problems are small enough to be easy" ID="ID_572969213" CREATED="1430766830929" MODIFIED="1430766842603"/>
</node>
<node TEXT="Test Driven Development" ID="ID_144164745" CREATED="1430768039177" MODIFIED="1430768045168">
<node TEXT="How do you know you are done?" ID="ID_194770557" CREATED="1430768045168" MODIFIED="1430768050610"/>
<node TEXT="Make your test plan first" ID="ID_1061242595" CREATED="1430768051457" MODIFIED="1430768060852">
<node TEXT="Convince yourself that any program that can satisfy your test plan is correct" ID="ID_130443352" CREATED="1430768061865" MODIFIED="1430768080199"/>
<node TEXT="Then write code, when it satisfies the test it is complete" ID="ID_209351331" CREATED="1430768084713" MODIFIED="1430768099656"/>
</node>
</node>
</node>
<node TEXT="Programming" ID="ID_1632116103" CREATED="1430767302425" MODIFIED="1430767320139">
<node TEXT="The problem of programming" ID="ID_832156336" CREATED="1430767320140" MODIFIED="1430767345734">
<node TEXT="Computers only understand machine language" ID="ID_1505356907" CREATED="1430767345735" MODIFIED="1430767355647">
<node TEXT="Different for every archetecture" ID="ID_593865913" CREATED="1430767355648" MODIFIED="1430767363072"/>
<node TEXT="Very difficult for humans to read and write" ID="ID_1533887267" CREATED="1430767363625" MODIFIED="1430767373174"/>
</node>
<node TEXT="Humans use natural languages" ID="ID_172239796" CREATED="1430767400505" MODIFIED="1430767416960">
<node TEXT="Ambiguity is prevalent" ID="ID_599967934" CREATED="1430767416960" MODIFIED="1432567903099"/>
<node TEXT="Very difficult for computers to understand" ID="ID_644154898" CREATED="1430767428865" MODIFIED="1430767439483"/>
</node>
<node TEXT="Programming languages are a compromise" ID="ID_1826226160" CREATED="1430767441513" MODIFIED="1430767448514">
<node TEXT="Difficult for everyone to understand" ID="ID_115419559" CREATED="1430767448515" MODIFIED="1430767455645"/>
<node TEXT="Unambiguous" ID="ID_1851953833" CREATED="1430767456289" MODIFIED="1430767468715"/>
<node TEXT="Can be written by humans and mechanically translated to machine language" ID="ID_73306193" CREATED="1430767469097" MODIFIED="1430767486330"/>
</node>
</node>
<node TEXT="Some Programming Languages" ID="ID_1448786895" CREATED="1430773888683" MODIFIED="1430773894685">
<node TEXT="BASIC" ID="ID_1735024604" CREATED="1430773936132" MODIFIED="1430773941054"/>
<node TEXT="C/C++" ID="ID_325730571" CREATED="1430773894685" MODIFIED="1430773897840"/>
<node TEXT="C\#" ID="ID_1924452264" CREATED="1430773914947" MODIFIED="1432567576336"/>
<node TEXT="COBOL" ID="ID_581760" CREATED="1430773922539" MODIFIED="1430773947525"/>
<node TEXT="FORTRAN" ID="ID_1285879007" CREATED="1430773898251" MODIFIED="1430773900803"/>
<node TEXT="Java" ID="ID_145878727" CREATED="1430773901155" MODIFIED="1430773904280"/>
<node TEXT="JavaScript" ID="ID_1371082224" CREATED="1430773904595" MODIFIED="1430773908057"/>
<node TEXT="Pascal" ID="ID_966661636" CREATED="1430773933933" MODIFIED="1430773954247"/>
<node TEXT="Python" ID="ID_666901771" CREATED="1430773908315" MODIFIED="1430773910432"/>
<node TEXT="Ruby" ID="ID_149680642" CREATED="1430773910683" MODIFIED="1430773912976"/>
</node>
<node TEXT="Steps in Programming (parts you do)" ID="ID_1592689298" CREATED="1430767491737" MODIFIED="1432568106013">
<node TEXT="Design" ID="ID_955013882" CREATED="1430767504314" MODIFIED="1430767507218">
<node TEXT="Very important, spend more time than you think you need to here" ID="ID_1434621556" CREATED="1430767507219" MODIFIED="1430767517872"/>
</node>
<node TEXT="Development" ID="ID_1326838342" CREATED="1430767519168" MODIFIED="1430767528131">
<node TEXT="Actually writing the code" ID="ID_318739306" CREATED="1430767528132" MODIFIED="1430767533702"/>
</node>
</node>
<node TEXT="Steps in Programming (parts the tools do)" ID="ID_1746891623" CREATED="1432568087016" MODIFIED="1432568098563">
<node TEXT="Compilation" ID="ID_1441795666" CREATED="1430767537041" MODIFIED="1430767541499">
<node TEXT="A Compiler translates high level code to intermediate language (assembly code)" ID="ID_886863919" CREATED="1430767541500" MODIFIED="1430767576950"/>
</node>
<node TEXT="Optimization" ID="ID_1394602393" CREATED="1430767577945" MODIFIED="1430767580939">
<node TEXT="Optimizing compilers modify code for performance" ID="ID_334741715" CREATED="1430767580940" MODIFIED="1430767595160"/>
</node>
<node TEXT="Assembly" ID="ID_990931428" CREATED="1430767596136" MODIFIED="1430767657334">
<node TEXT="Intermediate language is translated to machine language" ID="ID_213792435" CREATED="1430767657335" MODIFIED="1432567925906"/>
</node>
<node TEXT="Linking" ID="ID_982122595" CREATED="1430767670633" MODIFIED="1430767674735">
<node TEXT="Different parts of a program are linked into one executable" ID="ID_1132258039" CREATED="1430767674736" MODIFIED="1430767689929"/>
</node>
<node TEXT="Loading" ID="ID_531586518" CREATED="1430767691032" MODIFIED="1430767693767">
<node TEXT="Operating system loads executable code" ID="ID_1943341826" CREATED="1430767693769" MODIFIED="1430767701014"/>
</node>
<node TEXT="Execution" ID="ID_1684454759" CREATED="1430767701737" MODIFIED="1430767703577">
<node TEXT="Program executes on the computer" ID="ID_1374523692" CREATED="1430767704569" MODIFIED="1430767710083"/>
</node>
</node>
<node TEXT="Toolchain" ID="ID_676963731" CREATED="1430767764025" MODIFIED="1430767767582">
<node TEXT="Editor (vim, kate, notepad++)" ID="ID_524162164" CREATED="1430767767583" MODIFIED="1430767920302"/>
<node TEXT="Compiler and Linker (g++, VC12)" ID="ID_640658987" CREATED="1430767810721" MODIFIED="1430767915445"/>
<node TEXT="Build management (CMake, Project Files)" ID="ID_118794786" CREATED="1430767856785" MODIFIED="1432567943266"/>
<node TEXT="Debugger (gdb, ddd)" ID="ID_1860128102" CREATED="1430767976977" MODIFIED="1430767987703"/>
<node TEXT="Integrated Development Environment" ID="ID_110485493" CREATED="1430767819696" MODIFIED="1432567955633">
<node TEXT="Some packages (Visual Studio) bundle all of these together" ID="ID_1384348446" CREATED="1430767831753" MODIFIED="1430767975872"/>
</node>
</node>
<node TEXT="Compiler Warnings And Errors" ID="ID_430047525" CREATED="1430858955675" MODIFIED="1430858964199">
<node TEXT="You must fix all compile errors" ID="ID_819013735" CREATED="1430858964200" MODIFIED="1430858976115"/>
<node TEXT="You should fix all compile warnings" ID="ID_49577163" CREATED="1430858976371" MODIFIED="1430858982313"/>
<node TEXT="Your compiler is your greatest ally . . . use it" ID="ID_573454005" CREATED="1430858982522" MODIFIED="1430858991987"/>
</node>
</node>
</node>
</node>
</map>
