<map version="0.9.0">
<!-- To view this file, download free mind mapping software FreeMind from http://freemind.sourceforge.net -->
<node CREATED="1296084486369" ID="ID_192246125" MODIFIED="1296673483709" TEXT="Inheritance and Polymorphism">
<attribute NAME="date" VALUE=""/>
<attribute NAME="author" VALUE="Kenneth Sundberg"/>
<attribute NAME="subtitle" VALUE="CS1410 -- Chapter 15"/>
<node CREATED="1296672310757" ID="ID_1688227044" MODIFIED="1296672370945" POSITION="right" TEXT="Inheritance">
<node CREATED="1296672329981" ID="ID_1931714396" MODIFIED="1296672337436" TEXT="Concept">
<node CREATED="1296084514872" ID="ID_101996156" MODIFIED="1296673917054" TEXT="IS A inheritance">
<node CREATED="1296670755865" ID="ID_1852561177" MODIFIED="1296670770068" TEXT="A derived class is an extension or enhancement of a base class"/>
<node CREATED="1296670780668" ID="ID_1316416886" MODIFIED="1296670784308" TEXT="Examples:">
<node CREATED="1296670791460" ID="ID_1153713998" MODIFIED="1296670806877" TEXT="A Student \emph{is a} Person"/>
<node CREATED="1296670807084" ID="ID_270664378" MODIFIED="1296670822948" TEXT="A GpsPosition \emph{is a} Point"/>
</node>
<node CREATED="1296670784948" ID="ID_1590546155" MODIFIED="1296670856244" TEXT="All public members of a base class are available in the derived class"/>
</node>
<node CREATED="1296673910740" ID="ID_1480321237" MODIFIED="1296673915508" TEXT="Key Ideas">
<node CREATED="1296670934923" ID="ID_914402069" MODIFIED="1296670948836" TEXT="Derived class is an enhanced base class"/>
<node CREATED="1296670948974" ID="ID_1660821046" MODIFIED="1296670964933" TEXT="Public members of base class become public members of derived class"/>
<node CREATED="1296670965103" ID="ID_578424740" MODIFIED="1296670982381" TEXT="Programmer of derived class needs only be concerned with enhancements"/>
<node CREATED="1296670982591" ID="ID_144338771" MODIFIED="1296670993597" TEXT="Private members of base class are still private"/>
</node>
<node CREATED="1296084572913" ID="ID_721482710" MODIFIED="1296084579279" TEXT="Inheritance and parameters">
<node CREATED="1296671251613" ID="ID_149853938" MODIFIED="1296671270036" TEXT="An instance of a derived class \emph{is a} instance of the base class"/>
<node CREATED="1296671270388" ID="ID_1886362761" MODIFIED="1296671286795" TEXT="A function taking an instance of a base class as a parameter can also take an instance of a derived class"/>
</node>
</node>
<node CREATED="1296672337685" ID="ID_1654668286" MODIFIED="1296672341845" TEXT="Syntax">
<node CREATED="1296084499465" FOLDED="true" ID="ID_276647782" MODIFIED="1296673982483" TEXT="Protection from multiple includes">
<node CREATED="1296670671813" ID="ID_1240593976" MODIFIED="1296670696008" TEXT="If a class definition is included multiple times it causes a syntax error"/>
<node CREATED="1296670696178" ID="ID_1746011878" MODIFIED="1296670707874" TEXT="Use preprocessor macros to prevent"/>
<node CREATED="1296670708106" ID="ID_1942982430" MODIFIED="1296673573879" TEXT="Inheritance nearly guarantees this problem if macros are not used."/>
</node>
<node CREATED="1296673983453" ID="ID_1663744755" MODIFIED="1296673986365" TEXT="Syntax">
<node CREATED="1296673987236" ID="ID_1055668676" MODIFIED="1296674014408" TEXT="class Derived : public Base"/>
</node>
<node CREATED="1296084544321" ID="ID_661185392" MODIFIED="1296084548807" TEXT="Constructors and inheritance">
<node CREATED="1296671031500" ID="ID_1584743269" MODIFIED="1296671037438" TEXT="Use member initialization lists"/>
<node CREATED="1296671053049" ID="ID_915385331" MODIFIED="1296671061055" TEXT="First item in list is constructor for the base class"/>
</node>
<node CREATED="1296084549201" ID="ID_1301395925" MODIFIED="1296084556559" TEXT="Destructors">
<node CREATED="1296671096010" ID="ID_1923599081" MODIFIED="1296671114551" TEXT="Base class destructor is automatically invoked after the derived classes destructor"/>
<node CREATED="1296671117786" ID="ID_1825352809" MODIFIED="1296671125070" TEXT="Like a tower:">
<node CREATED="1296671125071" ID="ID_1898182567" MODIFIED="1296671137169" TEXT="Build base first"/>
<node CREATED="1296671137578" ID="ID_1083039533" MODIFIED="1296671140553" TEXT="Remove base last"/>
</node>
</node>
<node CREATED="1296084556737" ID="ID_1748187937" MODIFIED="1296084564095" TEXT="Eclipsing base members">
<node CREATED="1296671149442" ID="ID_1191765765" MODIFIED="1296671186587" TEXT="Base public members are \emph{eclipsed} by derived public members of the same name "/>
<node CREATED="1296671186779" ID="ID_1911584606" MODIFIED="1296671226209" TEXT="Use scope resolution to access base member"/>
</node>
</node>
<node CREATED="1296672416894" ID="ID_1359947166" MODIFIED="1296672418470" TEXT="Types">
<node CREATED="1296084579490" ID="ID_811135062" MODIFIED="1296084582447" TEXT="Protected members">
<node CREATED="1296671297746" ID="ID_1212026783" MODIFIED="1296671310865" TEXT="There are three levels of access protection:">
<node CREATED="1296671310866" ID="ID_622382220" MODIFIED="1296673599583" TEXT="Public -- Globally available"/>
<node CREATED="1296671323853" ID="ID_471983272" MODIFIED="1296671331605" TEXT="Private -- Available only to class"/>
<node CREATED="1296671331894" ID="ID_573055" MODIFIED="1296673613360" TEXT="Protected -- Available to class and derived classes"/>
</node>
</node>
<node CREATED="1296084587274" ID="ID_1418591752" MODIFIED="1296673877574" TEXT="Types of Inheritance">
<node CREATED="1296671363011" ID="ID_1120723864" MODIFIED="1296671369868" TEXT="There are three types of inheritance"/>
<node CREATED="1296671370807" ID="ID_576696513" MODIFIED="1296671375782" TEXT="The default is private"/>
<node CREATED="1296671376094" ID="ID_483299897" MODIFIED="1296671394918" TEXT="Public inheritance is usually correct"/>
</node>
<node CREATED="1296673871283" ID="ID_1933785533" MODIFIED="1296673876459" TEXT="Type of Inheritance">
<node CREATED="1296672108394" ID="ID_1703930970" MODIFIED="1296672171855">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <img src="Inheritance.png" />
  </body>
</html></richcontent>
</node>
</node>
</node>
</node>
<node CREATED="1296672318060" ID="ID_477197575" MODIFIED="1296673705949" POSITION="right" TEXT="Polymorphism">
<node CREATED="1296672446014" ID="ID_1511383066" MODIFIED="1296672449830" TEXT="Using Inheritance">
<node CREATED="1296084609434" ID="ID_351221538" MODIFIED="1296672859020" TEXT="Dynamic vs Static Binding">
<node CREATED="1296672510831" ID="ID_1014740491" MODIFIED="1296672532095" TEXT="If a function is defined in both the base and derived class which is called?"/>
<node CREATED="1296672532760" ID="ID_978989688" MODIFIED="1296672541084" TEXT="When is this decision made?">
<node CREATED="1296672541085" ID="ID_1536828756" MODIFIED="1296672862981" TEXT="Static Binding -- At compile time"/>
<node CREATED="1296672557160" ID="ID_225254545" MODIFIED="1296672866269" TEXT="Dynamic Binding -- At run time"/>
</node>
<node CREATED="1296672591304" ID="ID_1051343039" MODIFIED="1296673513979" TEXT="If the decision is made at run time then the same call can have multiple forms -- \emph{Polymorphism}"/>
</node>
<node CREATED="1296084594282" ID="ID_35784076" MODIFIED="1296673715240" TEXT="Virtual Member Functions">
<node CREATED="1296672636591" ID="ID_17007049" MODIFIED="1296673710554" TEXT="Polymorphism is accomplished with the keyword virtual"/>
<node CREATED="1296672647521" ID="ID_920628510" MODIFIED="1296672685530" TEXT="A call virtual function is resolved at run time"/>
<node CREATED="1296672685946" ID="ID_369227627" MODIFIED="1296672698082" TEXT="The call must be made through a pointer or a reference"/>
</node>
<node CREATED="1296084619658" ID="ID_1105752764" MODIFIED="1296084648297" TEXT="Abstract Base Classes">
<node CREATED="1296672703831" ID="ID_1236115100" MODIFIED="1296672721171" TEXT="A virtual function may be declared to be \emph{pure}"/>
<node CREATED="1296672721578" ID="ID_1680550793" MODIFIED="1296672745747" TEXT="A pure virtual function has no implementation in the base class"/>
<node CREATED="1296672747275" ID="ID_1743454431" MODIFIED="1296672768748" TEXT="A class with a pure virtual function is called an Abstract Base Class"/>
<node CREATED="1296672768955" ID="ID_1418394091" MODIFIED="1296672780953" TEXT="An Abstract Base Class cannot be instantiated"/>
<node CREATED="1296672789611" ID="ID_1943670115" MODIFIED="1296672806148" TEXT="All derived classes \emph{must} implement the pure virtual function of they are also abstract"/>
</node>
</node>
<node CREATED="1296672450014" ID="ID_894394637" MODIFIED="1296672456998" TEXT="C-Style">
<node CREATED="1296673116376" ID="ID_1170873687" MODIFIED="1296673177850" TEXT="Overview">
<node CREATED="1296673120758" ID="ID_671851417" MODIFIED="1296673748410" TEXT="Function pointers and Void pointers can be used to accomplish polymorphism"/>
<node CREATED="1296673134528" ID="ID_960427594" MODIFIED="1296673760851" TEXT="Using classes and inheritance is generally preferred"/>
<node CREATED="1296673160656" ID="ID_874105801" MODIFIED="1296673777971" TEXT="You will likely see code like this at some time"/>
</node>
<node CREATED="1296084698364" ID="ID_187067486" MODIFIED="1296084703214" TEXT="Void Pointers">
<node CREATED="1296673180081" ID="ID_973246711" MODIFIED="1296673204033" TEXT="A void pointer is only a memory location"/>
<node CREATED="1296673205849" ID="ID_1340154095" MODIFIED="1296673208654" TEXT="It has no type">
<node CREATED="1296673208656" ID="ID_611599358" MODIFIED="1296673221506" TEXT="It can not be dereferenced"/>
<node CREATED="1296673221889" ID="ID_997248928" MODIFIED="1296673230779" TEXT="Any type of pointer can be assigned to it"/>
</node>
<node CREATED="1296673231721" ID="ID_1721362080" MODIFIED="1296673239945" TEXT="It can be cast to a pointer of any type"/>
</node>
<node CREATED="1296084703404" ID="ID_1383332968" MODIFIED="1296084709043" TEXT="Function Pointers">
<node CREATED="1296673247440" ID="ID_853323412" MODIFIED="1296673272401" TEXT="The name of a function is actually a pointer to a memory location where the code is stored"/>
<node CREATED="1296673277170" ID="ID_1954017028" MODIFIED="1296673282609" TEXT="Function pointers can be declared"/>
<node CREATED="1296673284946" ID="ID_1101722264" MODIFIED="1296673308962" TEXT="Function pointers can be used in the same way as any other pointer"/>
</node>
</node>
</node>
</node>
</map>
