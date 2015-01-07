
MAKEFLAGS += --silent --no-print-directory

it: 
	(cd Coq             && $(MAKE) it)
	(cd Bitwalker       && $(MAKE) it)
	(cd Adhesion_Factor && $(MAKE) it)

report: 
	(cd Bitwalker       && $(MAKE) report)
	(cd Adhesion_Factor && $(MAKE) report)

par: 
	(cd Bitwalker       && $(MAKE) par)
	(cd Adhesion_Factor && $(MAKE) par)

log: 
	(cd Bitwalker       && $(MAKE) log)
	(cd Adhesion_Factor && $(MAKE) log)

clean: 
	(cd Coq             && $(MAKE) clean)
	(cd Bitwalker       && $(MAKE) clean)
	(cd Package_Foo     && $(MAKE) clean)
	(cd Adhesion_Factor && $(MAKE) clean)
