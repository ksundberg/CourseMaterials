<map version="freeplane 1.3.0">
<!--To view this file, download free mind mapping software Freeplane from http://freeplane.sourceforge.net -->
<node TEXT="Sampling" ID="ID_1723255651" CREATED="1283093380553" MODIFIED="1486443295076"><hook NAME="MapStyle">
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
<hook NAME="AutomaticEdgeColor" COUNTER="3"/>
<node TEXT="Theory" POSITION="right" ID="ID_1552300802" CREATED="1486443382115" MODIFIED="1486443388882">
<edge COLOR="#ff0000"/>
<node TEXT="Functions" ID="ID_1406333542" CREATED="1486443388887" MODIFIED="1486443398615">
<node TEXT="Sampling an Image" ID="ID_1800839967" CREATED="1486443398624" MODIFIED="1486444036111">
<attribute NAME="textbook" VALUE="07-01"/>
<node TEXT="Image consists of a grid of color values" ID="ID_413180834" CREATED="1486443423735" MODIFIED="1486443442734"/>
<node TEXT="These values are a representation" ID="ID_1109882981" CREATED="1486443443144" MODIFIED="1486443488064"/>
<node TEXT="They are samples of the underlying continuous function" ID="ID_612085872" CREATED="1486443488483" MODIFIED="1486443535577"/>
</node>
<node TEXT="Fourier Transform" ID="ID_1065629157" CREATED="1486443537084" MODIFIED="1486443616650">
<node TEXT="$e^{ix} = /cos x + i /sin x$" ID="ID_1942867907" CREATED="1486443616656" MODIFIED="1486443672560"/>
<node TEXT="$F(\omega) = \int f(x) e^{-i2\pi\omega x} dx$" ID="ID_1807495397" CREATED="1486443672967" MODIFIED="1486443768671"/>
</node>
<node TEXT="Space vs Frequency" ID="ID_963598985" CREATED="1486443796632" MODIFIED="1486443805674"/>
</node>
<node TEXT="Sampling" ID="ID_1438127704" CREATED="1486443808543" MODIFIED="1486443813557">
<node TEXT="Shah Function" ID="ID_1705290071" CREATED="1486443813561" MODIFIED="1486443838440">
<node TEXT="Shah function $$ W_T(s) = T \sum_{i=-\infty}^{\infty} \delta(x-iT)$$" ID="ID_1852770797" CREATED="1486443838445" MODIFIED="1486444994330"/>
<node TEXT="Sampling $$W_T(s) f (x) = T\sum_i \delta(x-iT)f(iT)$$" ID="ID_970474247" CREATED="1486444994790" MODIFIED="1486445142407"/>
</node>
<node TEXT="Convolution" ID="ID_1431984910" CREATED="1486498989491" MODIFIED="1486498996817">
<node TEXT="$f(x) \otimes g(x) = \int_{-\infty}^{\infty}f(x&apos;)g(x-x&apos;)dx&apos;$" LOCALIZED_STYLE_REF="styles.topic" ID="ID_387892969" CREATED="1486506485375" MODIFIED="1486506903467"/>
<node TEXT="Multiplication in spatial domain is convolution in frequency domain" LOCALIZED_STYLE_REF="styles.topic" ID="ID_1261204035" CREATED="1486506826535" MODIFIED="1486506868656"/>
<node TEXT="Convolution in spatial domain is multiplication in frequency domain" ID="ID_1295693492" CREATED="1486506844014" MODIFIED="1486506862308"/>
</node>
<node TEXT="Reconstruction" ID="ID_944296548" CREATED="1486506680958" MODIFIED="1486506684999">
<node TEXT="Convolving the Shah with some filter gives" ID="ID_1671568869" CREATED="1486506685004" MODIFIED="1486506693828"/>
<node TEXT="$$ T\sum_{i=-\infty}^{\infty} f(iT)r(x-iT) $$" ID="ID_965702551" CREATED="1486506694278" MODIFIED="1486506738812"/>
<node TEXT="That is a sum of weighted and translated filter functions" LOCALIZED_STYLE_REF="styles.topic" ID="ID_1986558516" CREATED="1486506739070" MODIFIED="1486506927457"/>
<node TEXT="In otherwords we can interpolate between samples to reconstruct a function" LOCALIZED_STYLE_REF="default" ID="ID_365923647" CREATED="1486506759694" MODIFIED="1486506912931"/>
</node>
<node TEXT="Perfect Frequency Reconstruction" ID="ID_1156416869" CREATED="1486507100182" MODIFIED="1486507450092">
<node TEXT="Frequency representation of Shah with period T is Shah with period $\frac{1}{T}$" ID="ID_1816429521" CREATED="1486507107334" MODIFIED="1486507168916"/>
<node TEXT="Convolving frequency shah with function gives frequency representation of reconstructed function" ID="ID_180432953" CREATED="1486507129311" MODIFIED="1486507231148"/>
<node TEXT="This results in infinite copies of the function" ID="ID_1132632555" CREATED="1486507238111" MODIFIED="1486507253748"/>
<node TEXT="Multiply with box to throw away all but the center part of spectrum" ID="ID_1907306672" CREATED="1486507254207" MODIFIED="1486507268380"/>
<node TEXT="$\Pi_T(x) = \frac{1}{2T}  |x| &lt; T$ otherwise 0" ID="ID_1273074068" CREATED="1486507356007" MODIFIED="1486507399820"/>
<node TEXT="$ F&apos; = (F(\omega) \otimes W_{\frac{1}{T}}(\omega))\Pi_T(\omega)$" ID="ID_1738622535" CREATED="1486507293183" MODIFIED="1486507347380"/>
</node>
<node TEXT="Nyquist Frequency" ID="ID_90792276" CREATED="1486507526879" MODIFIED="1486507531647">
<node TEXT="If sampling frequency is twice the maximum frequency in signal then it can be recovered exactly" ID="ID_1314039401" CREATED="1486507531651" MODIFIED="1486507560980"/>
</node>
<node TEXT="Pixels" ID="ID_1996438287" CREATED="1486507805479" MODIFIED="1486507808852">
<node TEXT="Pixels are not areas but discrete points" ID="ID_1574152939" CREATED="1486507809647" MODIFIED="1486507824828"/>
</node>
</node>
<node TEXT="Aliasing" ID="ID_314584248" CREATED="1486507461631" MODIFIED="1486507464028">
<node TEXT="Perfect Spatial Reconstruction" ID="ID_1242053497" CREATED="1486507453711" MODIFIED="1486507460660">
<node TEXT="Works like frequency reconstruction but uses the dual of the box function the sinc function" ID="ID_850759535" CREATED="1486507468199" MODIFIED="1486507487500"/>
<node TEXT="Sinc has infinite support" ID="ID_1573634424" CREATED="1486507487903" MODIFIED="1486507519012"/>
<node TEXT="The central copy is isolated by multipling by sinc which does a bad job" ID="ID_1615722484" CREATED="1486507586047" MODIFIED="1486507614236"/>
</node>
<node TEXT="Aliasing" ID="ID_1501909065" CREATED="1486507615023" MODIFIED="1486507942868">
<node TEXT="If extra copies of spectrum are too close then they add together" ID="ID_1859593729" CREATED="1486507648463" MODIFIED="1486507662244"/>
<node TEXT="Then there is no way to extract them" ID="ID_1247091922" CREATED="1486507662583" MODIFIED="1486507672900"/>
<node TEXT="This is known as Aliasing" ID="ID_514955491" CREATED="1486507673134" MODIFIED="1486507677876"/>
<node TEXT="It can look surprisingly bad" ID="ID_1781293603" CREATED="1486507690231" MODIFIED="1486507695482"/>
</node>
<node TEXT="Sources of aliasing" ID="ID_194827998" CREATED="1486507722455" MODIFIED="1486507726943">
<node TEXT="Edges" ID="ID_358912498" CREATED="1486507726946" MODIFIED="1486507744892"/>
<node TEXT="Small objects" ID="ID_102142321" CREATED="1486507745270" MODIFIED="1486507783932"/>
<node TEXT="Noise looks better than aliasing so we&apos;ll try to convert where we can" ID="ID_1779969896" CREATED="1486507786567" MODIFIED="1486507799747"/>
</node>
</node>
</node>
<node TEXT="Sampler" POSITION="right" ID="ID_47848352" CREATED="1486507856487" MODIFIED="1486507861711">
<edge COLOR="#0000ff"/>
<node TEXT="Interface" ID="ID_836763725" CREATED="1486507861714" MODIFIED="1486507865591">
<node TEXT="Requirements" ID="ID_1426744208" CREATED="1486507865595" MODIFIED="1486507951191">
<attribute NAME="textbook" VALUE="07-02"/>
<node TEXT="A sampler generates n-dimensional points in $[0,1)^n$" ID="ID_1366459116" CREATED="1486507891274" MODIFIED="1486507911996"/>
<node TEXT="The first five dimensions are used by the camera" ID="ID_1241803249" CREATED="1486507912407" MODIFIED="1486507920796"/>
<node TEXT="In general samplers should put their best dimensions first" ID="ID_799960250" CREATED="1486507921079" MODIFIED="1486507935508"/>
</node>
</node>
<node TEXT="Strategies" ID="ID_851692336" CREATED="1486508032375" MODIFIED="1486508037623">
<node TEXT="Stratified Sampling" ID="ID_1828537321" CREATED="1486508037626" MODIFIED="1486508069446">
<attribute NAME="textbook" VALUE="07-03"/>
<node TEXT="Divide space into strata" ID="ID_423016001" CREATED="1486508079407" MODIFIED="1486508098820"/>
<node TEXT="Chose random sample within each strata" ID="ID_865527497" CREATED="1486508099055" MODIFIED="1486508124148"/>
<node TEXT="Prone to the curse of dimensionality" ID="ID_24809470" CREATED="1486508112215" MODIFIED="1486508120476"/>
</node>
<node TEXT="Padding" ID="ID_381908689" CREATED="1486508125319" MODIFIED="1486508129320">
<node TEXT="Modified stratified sampling method" ID="ID_1010996979" CREATED="1486508129322" MODIFIED="1486508135684"/>
<node TEXT="Scales better that straight sampling" ID="ID_910211493" CREATED="1486508135903" MODIFIED="1486508147204"/>
<node TEXT="Subsets of dimensions are stratified" ID="ID_1122829693" CREATED="1486508147591" MODIFIED="1486508174555"/>
<node TEXT="Samples choose one random part from each subset" ID="ID_1165976132" CREATED="1486508174887" MODIFIED="1486508187356"/>
</node>
<node TEXT="Latin Hypercube Sampling (LHS)" ID="ID_1040792764" CREATED="1486508226095" MODIFIED="1486508240576">
<node TEXT="Less restrictive than Stratified sampling in number of samples" ID="ID_1538249868" CREATED="1486508240579" MODIFIED="1486508280836"/>
<node TEXT="Also called n-rooks" ID="ID_16969860" CREATED="1486508281039" MODIFIED="1486508286108"/>
</node>
<node TEXT="Others" ID="ID_90137186" CREATED="1486508330943" MODIFIED="1486508334543">
<node TEXT="Halton" ID="ID_66355978" CREATED="1486508334547" MODIFIED="1486508338052"/>
<node TEXT="0,2" ID="ID_642800914" CREATED="1486508338447" MODIFIED="1486508341772"/>
<node TEXT="Sobal" ID="ID_940530384" CREATED="1486508342071" MODIFIED="1486508354804"/>
</node>
</node>
</node>
<node TEXT="Reconstruction" POSITION="right" ID="ID_1433594775" CREATED="1486508417951" MODIFIED="1486508427191">
<edge COLOR="#00ff00"/>
<node TEXT="Filters" ID="ID_1634322805" CREATED="1486508427194" MODIFIED="1486508432943">
<node TEXT="Filter" ID="ID_612281825" CREATED="1486508432946" MODIFIED="1486508537463">
<attribute NAME="textbook" VALUE="07-08"/>
<node TEXT="Reconstruction requires a filter function" ID="ID_179176787" CREATED="1486508481098" MODIFIED="1486508487188"/>
<node TEXT="Ideal reconstruction (sinc) is not ideal" ID="ID_748181068" CREATED="1486508487551" MODIFIED="1486508509252"/>
<node TEXT="Sinc has infinite support which leads to a number of artifacts with limited samples" ID="ID_670769998" CREATED="1486508509487" MODIFIED="1486508526108"/>
</node>
<node TEXT="Box Filter" ID="ID_919479048" CREATED="1486508540919" MODIFIED="1486508545664">
<node TEXT="De facto filter" ID="ID_243751206" CREATED="1486508545666" MODIFIED="1486508552836"/>
<node TEXT="Perhaps worst possible choice" ID="ID_1685053786" CREATED="1486508553087" MODIFIED="1486508563884"/>
</node>
<node TEXT="Triangle Filter" ID="ID_461786827" CREATED="1486508569111" MODIFIED="1486508572420">
<node TEXT="Better results" ID="ID_1626029140" CREATED="1486508573543" MODIFIED="1486508589764"/>
</node>
<node TEXT="Gaussian Filter" ID="ID_1152566590" CREATED="1486508621535" MODIFIED="1486508627096">
<node TEXT="Good results" ID="ID_150957110" CREATED="1486508627098" MODIFIED="1486508628916"/>
<node TEXT="Tends to blur image - which can hide other artifacts" ID="ID_645263629" CREATED="1486508629287" MODIFIED="1486508638795"/>
</node>
<node TEXT="Mitchell Filter" ID="ID_165573810" CREATED="1486508639751" MODIFIED="1486508654848">
<node TEXT="Similar to Gaussian" ID="ID_1516645579" CREATED="1486508654851" MODIFIED="1486508663036"/>
<node TEXT="Has negative lobes on sides that help to sharpen image" ID="ID_318453996" CREATED="1486508663999" MODIFIED="1486508681228"/>
<node TEXT="Developed with human test subjects" ID="ID_396774421" CREATED="1486508681591" MODIFIED="1486508687964"/>
</node>
</node>
<node TEXT="Film" ID="ID_1483340270" CREATED="1486508745239" MODIFIED="1486508749744">
<node TEXT="Film Class" ID="ID_1866516094" CREATED="1486508749746" MODIFIED="1486508760334">
<attribute NAME="textbook" VALUE="07-09"/>
<node TEXT="Stores XYZ value for each pixel" ID="ID_1369426248" CREATED="1486508761447" MODIFIED="1486508778036"/>
<node TEXT="Uses filter and spectrum samples to reconstruct these pixel values" ID="ID_1138786342" CREATED="1486508778239" MODIFIED="1486508790684"/>
<node TEXT="Also manages file format output" ID="ID_1255379581" CREATED="1486508796568" MODIFIED="1486508803084"/>
</node>
</node>
</node>
</node>
</map>
