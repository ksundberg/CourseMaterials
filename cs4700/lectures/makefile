all: 01-Introduction.pdf 02-Evaluation.pdf 03-SyntaxSemantics.pdf 04-Names.pdf A-Postscript.pdf 05-TypeAbstraction.pdf 06-Expressions.pdf B-Prolog.pdf C-Haskel.pdf 07-Control.pdf

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
