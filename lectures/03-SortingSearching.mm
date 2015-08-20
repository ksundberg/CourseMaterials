<map version="freeplane 1.2.0">
<!--To view this file, download free mind mapping software Freeplane from http://freeplane.sourceforge.net -->
<node TEXT="Sorting and Searching" ID="ID_1723255651" CREATED="1283093380553" MODIFIED="1440104202947"><hook NAME="MapStyle">
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
<hook NAME="AutomaticEdgeColor" COUNTER="2"/>
<node TEXT="Searching" POSITION="right" ID="ID_1312423698" CREATED="1440104211045" MODIFIED="1440104213122">
<edge COLOR="#0000ff"/>
<node TEXT="Search Problem" ID="ID_1356656498" CREATED="1440105235912" MODIFIED="1440105240763">
<node TEXT="Definition" ID="ID_589290201" CREATED="1440105243792" MODIFIED="1440105246218">
<node TEXT="In a collection of objects find one that matches some criteria" ID="ID_32572710" CREATED="1440105246231" MODIFIED="1440105295179"/>
<node TEXT="If you have a standard collection" ID="ID_1520437932" CREATED="1440105295663" MODIFIED="1440105303415">
<node TEXT="std::find" ID="ID_1853788201" CREATED="1440105303424" MODIFIED="1440105307424"/>
<node TEXT="std::find\_if" ID="ID_361399701" CREATED="1440105307686" MODIFIED="1440105314816"/>
</node>
</node>
<node TEXT="Uses" ID="ID_354040142" CREATED="1440105510135" MODIFIED="1440105515153">
<node TEXT="Often used with a collection of structures" ID="ID_1622050046" CREATED="1440105515164" MODIFIED="1440105539840">
<node TEXT="Part of the structure is what you search on (key)" ID="ID_1446482442" CREATED="1440105539857" MODIFIED="1440105550138"/>
<node TEXT="Part of the structure is what you are looking for (value)" ID="ID_1677669172" CREATED="1440105550598" MODIFIED="1440105558984"/>
</node>
</node>
</node>
<node TEXT="Linear Search" ID="ID_1977225385" CREATED="1440104467164" MODIFIED="1440104479594">
<node TEXT="Linear Search Algorithm" ID="ID_403062777" CREATED="1440105006761" MODIFIED="1440105439769">
<attribute NAME="textbook" VALUE="09-01"/>
<node TEXT="Sometimes called sequential search" ID="ID_549896659" CREATED="1440105062351" MODIFIED="1440105071107"/>
<node TEXT="Only requires a collection of objects" ID="ID_217462049" CREATED="1440105071574" MODIFIED="1440105090658"/>
<node TEXT="The obvious algorithm - look at every object untill you find what you are looking for" ID="ID_650310683" CREATED="1440105091150" MODIFIED="1440105232612"/>
</node>
<node TEXT="Linear Search Code" ID="ID_1164393365" CREATED="1440105486592" MODIFIED="1440105492769"/>
</node>
<node TEXT="Binary Search" ID="ID_170914193" CREATED="1440104480124" MODIFIED="1440104483216">
<node TEXT="Adding Requirements" ID="ID_825017112" CREATED="1440105459577" MODIFIED="1440105469795">
<node TEXT="If we require that the collection is in order we can do better." ID="ID_1525422613" CREATED="1440105469805" MODIFIED="1440105483908"/>
<node TEXT="Imagine: If I think of an integer 0-100 what strategy should you use to guess the number?" ID="ID_771640838" CREATED="1440105692752" MODIFIED="1440105735523"/>
<node TEXT="This requires that a collection is sorted but allows faster searching" ID="ID_661626515" CREATED="1440105736375" MODIFIED="1440105907056"/>
</node>
<node TEXT="Recursive Algorithm" ID="ID_329091957" CREATED="1440105913505" MODIFIED="1440105937565">
<node TEXT="Divide collection in half" ID="ID_1309268189" CREATED="1440105930326" MODIFIED="1440105947547"/>
<node TEXT="Use sorted condition to determine which half must contain value" ID="ID_586991987" CREATED="1440105947976" MODIFIED="1440105967858"/>
<node TEXT="Recurse into selected half" ID="ID_1521020827" CREATED="1440105968294" MODIFIED="1440105973759"/>
</node>
<node TEXT="Binary Search Code" ID="ID_836114925" CREATED="1440105985182" MODIFIED="1440105993113"/>
</node>
</node>
<node TEXT="Sorting" POSITION="right" ID="ID_1664721746" CREATED="1440104205334" MODIFIED="1440104210763">
<edge COLOR="#ff0000"/>
<node TEXT="Overview" ID="ID_451312536" CREATED="1440106079851" MODIFIED="1440106081845">
<node TEXT="Overview" ID="ID_1277607554" CREATED="1440106083355" MODIFIED="1440106087420">
<node TEXT="Binary search and other algorithms need a collection to be sorted" ID="ID_1099865274" CREATED="1440106087438" MODIFIED="1440106101773"/>
<node TEXT="Sorting is the method of determining how to order a collection" ID="ID_1629994316" CREATED="1440106102219" MODIFIED="1440106120418"/>
<node TEXT="Most often based on less than operator" ID="ID_272341517" CREATED="1440106120705" MODIFIED="1440106134762"/>
<node TEXT="std::sort" ID="ID_259869733" CREATED="1440106135241" MODIFIED="1440106139778"/>
<node TEXT="Needs a way to swap values - std::swap" ID="ID_932830984" CREATED="1440106482789" MODIFIED="1440106492214"/>
</node>
<node TEXT="Sort properties" ID="ID_573033275" CREATED="1440106198415" MODIFIED="1440106205151">
<node TEXT="In-place" ID="ID_1900680920" CREATED="1440106205163" MODIFIED="1440106209088">
<node TEXT="In place algorithms don&apos;t require extra memory" ID="ID_642067112" CREATED="1440106269780" MODIFIED="1440106290101"/>
</node>
<node TEXT="Stable" ID="ID_1737937136" CREATED="1440106209598" MODIFIED="1440106214503">
<node TEXT="Stable algorithms preserve order of `equal&apos; elements" ID="ID_750912228" CREATED="1440106291363" MODIFIED="1440106309069"/>
</node>
</node>
</node>
<node TEXT="Quadratic Sorts" ID="ID_1633417942" CREATED="1440104726931" MODIFIED="1440104752734">
<node TEXT="Bubble Sort" ID="ID_1155957316" CREATED="1440106065420" MODIFIED="1440106068950">
<node TEXT="Scan through collection" ID="ID_741265239" CREATED="1440106383496" MODIFIED="1440106444046"/>
<node TEXT="If adjacent pairs are locally out of order swap them" ID="ID_1684462527" CREATED="1440106450126" MODIFIED="1440106477407"/>
</node>
<node TEXT="Insertion Sort" ID="ID_1458387983" CREATED="1440106069515" MODIFIED="1440106072750">
<node TEXT="Have a sorted collection - initially empty" ID="ID_1153932191" CREATED="1440106687077" MODIFIED="1440106701763"/>
<node TEXT="Insert each not yet sorted value at the correct spot" ID="ID_1458083488" CREATED="1440106702020" MODIFIED="1440106772286"/>
</node>
<node TEXT="Selection Sort" ID="ID_530711207" CREATED="1440106073228" MODIFIED="1440106075869">
<node TEXT="Have a sorted collection - initially empty" ID="ID_855658720" CREATED="1440106773978" MODIFIED="1440106786883"/>
<node TEXT="Insert the smallest unsorted element" ID="ID_1148310305" CREATED="1440106787338" MODIFIED="1440106799056"/>
</node>
</node>
<node TEXT="Loglinear Sorts" ID="ID_1095982368" CREATED="1440104732218" MODIFIED="1440104748597">
<node TEXT="Recursive Sorting" ID="ID_1028691405" CREATED="1440106826745" MODIFIED="1440106838933"/>
<node TEXT="Merge Sort" ID="ID_1643196750" CREATED="1440106181135" MODIFIED="1440106183952"/>
<node TEXT="Quick Sort" ID="ID_602844682" CREATED="1440106184222" MODIFIED="1440106186552"/>
</node>
</node>
</node>
</map>
