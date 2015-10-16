
MAKEFLAGS += --silent
MAKEFLAGS += --no-print-directory

it: lib test

lib:
	(cd Foundation       && $(MAKE) lib)
	(cd Generated        && $(MAKE) lib)

test:
	(cd Tests            && $(MAKE))

clean: 
	(cd Foundation       && $(MAKE) clean)
	(cd Generated        && $(MAKE) clean)
	(cd Tests            && $(MAKE) clean)
	(cd Experiment       && $(MAKE) clean)

