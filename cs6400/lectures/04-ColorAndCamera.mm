<map version="freeplane 1.3.0">
<!--To view this file, download free mind mapping software Freeplane from http://freeplane.sourceforge.net -->
<node TEXT="Color and Cameras" ID="ID_1723255651" CREATED="1283093380553" MODIFIED="1485905853149"><hook NAME="MapStyle">
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
<hook NAME="AutomaticEdgeColor" COUNTER="6"/>
<attribute NAME="author" VALUE="Kenneth Sundberg"/>
<attribute NAME="date" VALUE=""/>
<attribute NAME="subtitle" VALUE="CS6400"/>
<node TEXT="Color" POSITION="right" ID="ID_513834499" CREATED="1485906057718" MODIFIED="1485906059663">
<edge COLOR="#00ffff"/>
<node TEXT="Representation" ID="ID_790476943" CREATED="1485906059665" MODIFIED="1485906062531">
<node TEXT="Spectral Representation" ID="ID_475671664" CREATED="1485905854719" MODIFIED="1485906065130">
<attribute NAME="textbook" VALUE="05-01"/>
<node TEXT="Represent light as a spectral power distribution (SPD)" ID="ID_581149700" CREATED="1485905893750" MODIFIED="1485905905283"/>
<node TEXT="Two supported options" ID="ID_1487656719" CREATED="1485905905726" MODIFIED="1485905910991">
<node TEXT="RGB (faster but less accurate)" ID="ID_296091627" CREATED="1485905910995" MODIFIED="1485905918843">
<node TEXT="3 samples, red green and blue" ID="ID_241978025" CREATED="1485905993766" MODIFIED="1485906000931"/>
</node>
<node TEXT="SampledSpectrum" ID="ID_507159270" CREATED="1485905922366" MODIFIED="1485905928595">
<node TEXT="60 samples from 400 - 700 nm" ID="ID_1405304363" CREATED="1485905961310" MODIFIED="1485905972315"/>
</node>
</node>
</node>
<node TEXT="Coefficient Spectrum" ID="ID_25267770" CREATED="1485906047710" MODIFIED="1485906066971">
<node TEXT="Base class for both SPDs" ID="ID_1176733852" CREATED="1485906069374" MODIFIED="1485906080091"/>
<node TEXT="Set of n samples" ID="ID_655215454" CREATED="1485906080334" MODIFIED="1485906096914"/>
<node TEXT="Arithmetic is defined component-wise" ID="ID_959137068" CREATED="1485906097254" MODIFIED="1485906149403"/>
<node TEXT="Predicate for zero everywhere - IsBlack to avoid tracing rays with no effect" ID="ID_722562073" CREATED="1485906151822" MODIFIED="1485906172451"/>
</node>
<node TEXT="Irregular Samples" ID="ID_1502332585" CREATED="1485906300446" MODIFIED="1485906318991">
<node TEXT="Measured SPDS (found in some sample files) have irregular sample spacing" ID="ID_1994255159" CREATED="1485906318995" MODIFIED="1485906332619"/>
<node TEXT="Determine average values of piecewise linear function" ID="ID_411740668" CREATED="1485906332870" MODIFIED="1485906353891"/>
</node>
</node>
<node TEXT="XYZ" ID="ID_134593630" CREATED="1485906368726" MODIFIED="1485906373215">
<node TEXT="The XYZ color space" ID="ID_281339377" CREATED="1485906373219" MODIFIED="1485906379271">
<node TEXT="Human visual system has three inputs (rods and two cones)" ID="ID_1030394245" CREATED="1485906379273" MODIFIED="1485906418579"/>
<node TEXT="These three components are called X,Y,Z" ID="ID_1159723524" CREATED="1485906419070" MODIFIED="1485906430819"/>
<node TEXT="X,Y,Z response curves for different wavelengths determined with human test subjects" ID="ID_1742071696" CREATED="1485906436798" MODIFIED="1485906461683"/>
</node>
<node TEXT="Response" ID="ID_1172059426" CREATED="1485906464303" MODIFIED="1485906491758">
<node TEXT="$x_\lambda = \frac{1}{\int Y(\lambda)d\lambda}\int S(\lambda)X(\lambda)d\lambda$" ID="ID_1249525180" CREATED="1485906491760" MODIFIED="1485906593924"/>
<node TEXT="Very different SPDs can have identical XYZ representations" ID="ID_1121473614" CREATED="1485906595895" MODIFIED="1485906611659"/>
</node>
</node>
<node TEXT="RGB" ID="ID_695100501" CREATED="1485906647679" MODIFIED="1485906652543">
<node TEXT="RGB color space" ID="ID_909539573" CREATED="1485906652545" MODIFIED="1485906661430">
<node TEXT="Determined by spectral distribution of RGB lights in monitor" ID="ID_1079336221" CREATED="1485906661432" MODIFIED="1485906674595"/>
</node>
</node>
<node TEXT="Radiometry" ID="ID_938611724" CREATED="1485906815327" MODIFIED="1485906818947">
<node TEXT="Basic Quantities" ID="ID_1287571475" CREATED="1485906821599" MODIFIED="1485906914389">
<attribute NAME="textbook" VALUE="05-04"/>
<node TEXT="Energy" ID="ID_1491143505" CREATED="1485906826257" MODIFIED="1485906830131"/>
<node TEXT="Flux (Power) - instantaneous J/s" ID="ID_1421343023" CREATED="1485906830502" MODIFIED="1485906872435"/>
<node TEXT="Irradience - Flux/A" ID="ID_1440226504" CREATED="1485906872886" MODIFIED="1485906884571"/>
<node TEXT="Radiance - Irradience with respect to solid angle" ID="ID_1633519418" CREATED="1485906952735" MODIFIED="1485906966323"/>
</node>
<node TEXT="Lumenance" ID="ID_730453394" CREATED="1485906987862" MODIFIED="1485906991775">
<node TEXT="How bright a color appears to the human visual system (green maters most)" ID="ID_469120899" CREATED="1485906991779" MODIFIED="1485907006851"/>
<node TEXT="$Y = \int L(\lambda) V(\lambda) d\lambda$" ID="ID_1398242744" CREATED="1485907008942" MODIFIED="1485907029579"/>
<node TEXT="V is a scaled version of Y" ID="ID_731896940" CREATED="1485907055815" MODIFIED="1485907063764"/>
</node>
</node>
<node TEXT="Surface" ID="ID_1706098225" CREATED="1485907088671" MODIFIED="1485907094327">
<node TEXT="BRDF" ID="ID_1029648860" CREATED="1485907094328" MODIFIED="1485907114349">
<attribute NAME="textbook" VALUE="05-06"/>
<node TEXT="Bidirectional reflectance distribution function" ID="ID_841194857" CREATED="1485907118791" MODIFIED="1485907154795"/>
<node TEXT="Reciprocity" ID="ID_1042860203" CREATED="1485907304815" MODIFIED="1485907308467"/>
<node TEXT="Energy Conservation" ID="ID_1095503028" CREATED="1485907308822" MODIFIED="1485907314012"/>
</node>
<node TEXT="BRSSDF" ID="ID_522470539" CREATED="1485907100383" MODIFIED="1485907103307">
<node TEXT="Bidirectional Scattering Surface Reflectance Distribution Function" ID="ID_1038803989" CREATED="1485907322503" MODIFIED="1485907338132"/>
</node>
</node>
</node>
<node TEXT="Camera" POSITION="right" ID="ID_33433418" CREATED="1485907345287" MODIFIED="1485907350060">
<edge COLOR="#ffff00"/>
<node TEXT="Model" ID="ID_220623346" CREATED="1485907359439" MODIFIED="1485907378735">
<node TEXT="Orthographic" ID="ID_52501823" CREATED="1485907378739" MODIFIED="1485907383723"/>
<node TEXT="Perspective" ID="ID_905390254" CREATED="1485907384071" MODIFIED="1485907387132"/>
<node TEXT="Depth of Field" ID="ID_1519635085" CREATED="1485907388647" MODIFIED="1485907397259"/>
<node TEXT="Environment Camera" ID="ID_376899253" CREATED="1485907406127" MODIFIED="1485907410723"/>
</node>
<node TEXT="Realistic Camera" ID="ID_1567878304" CREATED="1485907417383" MODIFIED="1485907422031">
<node TEXT="Lens System" ID="ID_726570084" CREATED="1485907422034" MODIFIED="1485907432499"/>
<node TEXT="Exit Pupil" ID="ID_503748191" CREATED="1485907557319" MODIFIED="1485907560188"/>
</node>
</node>
</node>
</map>
