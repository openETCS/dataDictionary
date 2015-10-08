

it: FORCE
	latexmk -pdf Dynamic_Problem
	latexmk -pdf Conditionals

spell:
	aspell check --lang=en Dynamic_Problem.tex
	espell check --lang=en Conditionals.tex

clean:
	$(RM) Dynamic_Problem.pdf
	$(RM) Conditionals.pdf
	$(RM) *.aux
	$(RM) *.bak
	$(RM) *.log	
	$(RM) *.fdb_latexmk
	$(RM) *.fls	

FORCE:

