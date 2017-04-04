<map version="freeplane 1.3.0">
<!--To view this file, download free mind mapping software Freeplane from http://freeplane.sourceforge.net -->
<node TEXT="Monte Carlo Integration" ID="ID_1723255651" CREATED="1283093380553" MODIFIED="1491337106537"><hook NAME="MapStyle">
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
<hook NAME="AutomaticEdgeColor" COUNTER="7"/>
<node TEXT="Integration" POSITION="right" ID="ID_14293811" CREATED="1491339110909" MODIFIED="1491339114605">
<edge COLOR="#7c0000"/>
<node TEXT="Randomness" ID="ID_667921911" CREATED="1491339120966" MODIFIED="1491339128527">
<node TEXT="Random Methods" ID="ID_1279420740" CREATED="1491337107992" MODIFIED="1491339137391">
<node TEXT="Las Vegas - Random choices lead to identical results" ID="ID_311584989" CREATED="1491337124155" MODIFIED="1491337144637"/>
<node TEXT="Monte Carlo - Random choices lead to different results" ID="ID_1459187858" CREATED="1491337145032" MODIFIED="1491337166721"/>
</node>
<node TEXT="Probability Review" ID="ID_1618402376" CREATED="1491337168594" MODIFIED="1491339140853">
<attribute NAME="textbook" VALUE="13-01"/>
<node TEXT="Cumulative Distribution Function (CDF) - probability that a value from distribution is less than x" ID="ID_326885583" CREATED="1491337223733" MODIFIED="1491337373514"/>
<node TEXT="Probability Density Function (PDF) -probability that a value from the distribution take a given value." ID="ID_880583197" CREATED="1491337373881" MODIFIED="1491337439710"/>
<node TEXT="PDF is the derivative of CDF" ID="ID_937334725" CREATED="1491337439926" MODIFIED="1491337491680"/>
<node TEXT="$p(x) = \frac{dP(x)}{dx}$" ID="ID_193923392" CREATED="1491337577324" MODIFIED="1491337598240"/>
</node>
<node TEXT="Expected Values" ID="ID_1256779155" CREATED="1491337560198" MODIFIED="1491339144654">
<node TEXT="The average value of a function given a distribution is the expected value" ID="ID_1952597356" CREATED="1491337610526" MODIFIED="1491337625085"/>
<node TEXT="$E(f(x)) = \int f(x)p(x)dx$" ID="ID_1114041210" CREATED="1491337625415" MODIFIED="1491337678823"/>
<node TEXT="The variance of a function is a measure of how far it deviates from the expected value" ID="ID_1012895449" CREATED="1491337679237" MODIFIED="1491337694442"/>
<node TEXT="$V(f(x)) = E((f(x)-E(f(x)))^2)$" ID="ID_1928951375" CREATED="1491337694849" MODIFIED="1491337819331"/>
</node>
</node>
<node TEXT="Monte Carlo" ID="ID_1472363320" CREATED="1491339128935" MODIFIED="1491339133629">
<node TEXT="Monte Carlo Estimator" ID="ID_1872614717" CREATED="1491337820810" MODIFIED="1491339147940">
<attribute NAME="textbook" VALUE="13-02"/>
<node TEXT="$F_N = \frac{1}{N} \Sigma_{i=1}{N} \frac{f(X_i)}{p(X_i)}$" ID="ID_812197998" CREATED="1491337890340" MODIFIED="1491340504487"/>
<node TEXT="The expected value of this estimator is the integral of $f(x)$" ID="ID_1782372781" CREATED="1491338021162" MODIFIED="1491338047358"/>
<node TEXT="$E(F_N) = \frac{1}{N} \Sigma_{i=1}{N} \int \frac{f(x)}{p(x)} p(x) dx$" ID="ID_1720357257" CREATED="1491338047691" MODIFIED="1491340508717"/>
<node TEXT="$E(F_N) = \frac{1}{N} \Sigma_{i=1}{N} \int f(x) dx$" ID="ID_735618305" CREATED="1491338096445" MODIFIED="1491340512227"/>
<node TEXT="$E(F_N) = \int f(x) dx$" ID="ID_564475876" CREATED="1491338118966" MODIFIED="1491338134721"/>
</node>
<node TEXT="Quadrature" ID="ID_922285158" CREATED="1491338187507" MODIFIED="1491339151558">
<node TEXT="Quadrature is the numeric evaluation of integrals" ID="ID_1626287358" CREATED="1491338199687" MODIFIED="1491338210439"/>
<node TEXT="Other techniques such as Runga-Kutta methods suffer from the curse of dimensionallity" ID="ID_510696690" CREATED="1491338210750" MODIFIED="1491338269543"/>
<node TEXT="Monte Carlo converges is $O(\sqrt N)$ without regard to dimension" ID="ID_937535163" CREATED="1491338269953" MODIFIED="1491338314569"/>
<node TEXT="Monte Carlo is the only known practical method for high dimension quadrature" ID="ID_1920932296" CREATED="1491338315026" MODIFIED="1491338343151"/>
</node>
</node>
<node TEXT="Sampling Methods" ID="ID_867011354" CREATED="1491338395171" MODIFIED="1491339154871">
<node TEXT="Evaluating Monte Carlo" ID="ID_443495546" CREATED="1491338499116" MODIFIED="1491338722932">
<attribute NAME="textbook" VALUE="13-03"/>
<node TEXT="In order to use monte carlo integration we must be able to sample from a known distribution" ID="ID_1974711823" CREATED="1491338525508" MODIFIED="1491338546497"/>
<node TEXT="For uniform distributions a high quality PRNG will work" ID="ID_339484818" CREATED="1491338546858" MODIFIED="1491338561256"/>
<node TEXT="Sampling from geometry, BRDF&apos;s and other complex functions must also be handled" ID="ID_1673151441" CREATED="1491338561619" MODIFIED="1491338584807"/>
</node>
<node TEXT="Inversion Method" ID="ID_814399764" CREATED="1491338586723" MODIFIED="1491338599510">
<node TEXT="If the CDF is known and can be inverted then:" ID="ID_4521334" CREATED="1491338599515" MODIFIED="1491338650416"/>
<node TEXT="$X = P^{-1}(\xi)$" ID="ID_628927028" CREATED="1491338650894" MODIFIED="1491338696393"/>
</node>
<node TEXT="Rejection Method" ID="ID_748598999" CREATED="1491338726299" MODIFIED="1491338764350">
<node TEXT="If integrading the PDF to the CDF is impractical rejection can be used instead" ID="ID_161106589" CREATED="1491338764354" MODIFIED="1491338782693"/>
<node TEXT="To sample f(x) we need some p(x)" ID="ID_537818591" CREATED="1491338783269" MODIFIED="1491338951401"/>
<node TEXT="Choose X from p until" ID="ID_843558370" CREATED="1491339038107" MODIFIED="1491339047056"/>
<node TEXT="$\xi &lt; \frac{f(X)}{c p(X)}$" ID="ID_1965716977" CREATED="1491338951882" MODIFIED="1491339034998"/>
</node>
<node TEXT="Metropolis Sampling" ID="ID_677024079" CREATED="1491338697745" MODIFIED="1491339196390">
<node TEXT="Need a mutator that takes a sample and converts it to some other sample" ID="ID_43478319" CREATED="1491339196394" MODIFIED="1491339215234"/>
<node TEXT="Need the transition probability between any two samples" ID="ID_827607772" CREATED="1491339215613" MODIFIED="1491339270202"/>
<node TEXT="From this an acceptance probability is defined so as to not introduce bias" ID="ID_1247100643" CREATED="1491339270519" MODIFIED="1491339286628"/>
<node TEXT="At each iteration a sample is mutated and if accepted becomes the starting sample for the next iteration" ID="ID_1069659196" CREATED="1491339328197" MODIFIED="1491339361756"/>
</node>
<node TEXT="Sampling Geometry" ID="ID_1232134903" CREATED="1491339380138" MODIFIED="1491339453977">
<node TEXT="Each primitive shape needs a unique sampling procedure" ID="ID_1306746169" CREATED="1491339453982" MODIFIED="1491339473924"/>
<node TEXT="It is important to avoid distortions in both area and probability" ID="ID_1316930959" CREATED="1491339474198" MODIFIED="1491339491196"/>
<node TEXT="Consider the disk:" ID="ID_1995905648" CREATED="1491339491667" MODIFIED="1491339499507"/>
</node>
</node>
<node TEXT="Quality Improvements" ID="ID_46159721" CREATED="1491339569124" MODIFIED="1491339577282">
<node TEXT="Efficiency" ID="ID_252898035" CREATED="1491339577286" MODIFIED="1491339581248">
<node TEXT="$e(F) = \frac{1}{V(F)T(F)}$" ID="ID_1856079495" CREATED="1491339581253" MODIFIED="1491339608033"/>
<node TEXT="A method is more efficient if it produces less variance in the same amount of time" ID="ID_1435607879" CREATED="1491339608536" MODIFIED="1491339626774"/>
<node TEXT="A method is more efficient if it produces the same variance in less time" ID="ID_1404841642" CREATED="1491339627044" MODIFIED="1491339639425"/>
</node>
<node TEXT="Russian Roulette" ID="ID_7394605" CREATED="1491339642021" MODIFIED="1491339648450">
<node TEXT="Seeks to improve time, always introduces variance" ID="ID_23839110" CREATED="1491339648454" MODIFIED="1491339664454"/>
<node TEXT="Choose a termination probability q and constant value c (often 0)" ID="ID_389074419" CREATED="1491339664874" MODIFIED="1491339858506"/>
<node TEXT="Given an estimator F create a new estimator F&apos;" ID="ID_220565612" CREATED="1491339859230" MODIFIED="1491339899989"/>
<node TEXT="$F&apos; = \frac{F-qc}{1-q}$ with probability q otherwise $F&apos; = c$" ID="ID_446758425" CREATED="1491339900559" MODIFIED="1491339950205"/>
<node TEXT="$E(F) = E(F&apos;)$" ID="ID_246772636" CREATED="1491339950623" MODIFIED="1491339967760"/>
</node>
<node TEXT="Splitting" ID="ID_821103432" CREATED="1491339969114" MODIFIED="1491340013280">
<node TEXT="Seeks to reduce variance" ID="ID_876457770" CREATED="1491340013285" MODIFIED="1491340044316"/>
<node TEXT="Split ray at high variance locations into multiple rays" ID="ID_1732425894" CREATED="1491340044697" MODIFIED="1491340056426"/>
<node TEXT="Allows effort to be concentrated into some dimensions" ID="ID_245551611" CREATED="1491340056798" MODIFIED="1491340090770"/>
</node>
<node TEXT="Stratified Sampling" ID="ID_195264959" CREATED="1491340098633" MODIFIED="1491340184230">
<attribute NAME="textbook" VALUE="13-08"/>
<node TEXT="Always reduces variance" ID="ID_1417021693" CREATED="1491340105418" MODIFIED="1491340144229"/>
<node TEXT="Suffers from curse of dimensionality" ID="ID_1731684190" CREATED="1491340144647" MODIFIED="1491340152601"/>
</node>
<node TEXT="Importance Sampling" ID="ID_831967127" CREATED="1491340215681" MODIFIED="1491340233144">
<attribute NAME="textbook" VALUE="13-10"/>
<node TEXT="The Monte Carlo Estimator converges more quickly if p(x) is close to f(x)" ID="ID_1336777758" CREATED="1491340246889" MODIFIED="1491340292549"/>
<node TEXT="In many rendering contexts p(x) can be chosen in such a way as to reduce variance" ID="ID_995340847" CREATED="1491340293057" MODIFIED="1491340328532"/>
<node TEXT="For example cosine distributions occur frequently" ID="ID_792550933" CREATED="1491340328919" MODIFIED="1491340355410"/>
</node>
</node>
</node>
</node>
</map>
