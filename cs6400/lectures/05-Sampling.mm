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
<hook NAME="AutomaticEdgeColor" COUNTER="1"/>
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
</node>
</node>
</node>
</map>
