all: 01-Introduction.pdf 02-ProjectManagement.pdf 03-HighLevelDesign.pdf 04-LowLevelDesign.pdf 05-Development.pdf 06-Testing.pdf 07-Maintainance.pdf 08-PredictiveModels.pdf 09-IterativeModels.pdf

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
