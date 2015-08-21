
MAKEFLAGS += --silent --no-print-directory

export ASPELL=aspell check -p ./.dict --lang=en --encoding=utf-8

all: silent

#VPATH = ../Figures:nonmutating:maxmin:binary-search:mutating:numeric:stack:tables

clean:
	@$(RM) *.aux
	@$(RM) *.bak
	@$(RM) */*.bak
	@$(RM) report.pdf
	@$(RM) report.bbl
	@$(RM) report.blg
	@$(RM) report.fls
	@$(RM) report.fdb_latexmk
	@$(RM) report.lop2
	@$(RM) report.lof
	@$(RM) report.log
	@$(RM) report.lot
	@$(RM) report.lox
	@$(RM) report.out
	@$(RM) report.toc


silent: *.tex 
	latexmk -f -silent -pdf report	

verbose: *.tex
	latexmk -f -pdf report	

%.spell: %.tex
	$(ASPELL) $<

#far from optimal, depends on Tex directories in VPATH
spell:
	make $(shell find . -name "*.tex" | xargs -n 1 basename | sed "s/tex/spell/g")
	#didnt work...
	#make $(addsuffix spell, $(shell find . -name "*.tex" | xargs basename tex))
