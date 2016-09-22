all: 01-Introduction.pdf 03-BasicGraphics.pdf 02-SystemsAndModels.pdf 03-BasicGraphics.pdf 04-Transformations.pdf 05-Viewing.pdf 07-Lighting.pdf 08-Textures.pdf 09-Modeling.pdf 10-SceneGraphs.pdf 11-ParticleSystems.pdf 12-RecursiveMethods.pdf

.PHONY: clean all

clean:
	rm -f *.tex
	rm -f *.vrb
	rm -f *.aux
	rm -f *.toc
	rm -f *.log
	rm -f *.nav
	rm -f *.out
	rm -f *.snm

distclean: clean
	rm -f *.pdf

%.tex : %.mm lecture.xslt
	xsltproc lecture.xslt $< > $@

%.pdf : %.tex
	pdflatex -halt-on-error $<
	pdflatex -halt-on-error $<
