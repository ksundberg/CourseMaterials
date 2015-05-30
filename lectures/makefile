all: 01-Introduction.pdf 02-BasicStatements.pdf 03-SoftwareEngineering.pdf 04-ControlFlow.pdf 05-UserDefinedDataTypes.pdf

.PHONY: clean all

clean:
	rm -f *.tex
	rm -f *.pdf
	rm -f *.aux
	rm -f *.toc
	rm -f *.log
	rm -f *.nav
	rm -f *.out
	rm -f *.snm

%.tex : %.mm lecture.xslt
	xsltproc lecture.xslt $< > $@

%.pdf : %.tex
	pdflatex $< -interaction=nonstopmode
	pdflatex $< -interaction=nonstopmode
