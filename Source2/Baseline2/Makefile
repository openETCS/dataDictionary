
MAKEFLAGS += --silent
MAKEFLAGS += --no-print-directory

it: lib test

lib:
	(cd Foundation       && $(MAKE) lib)
	(cd Generated        && $(MAKE) lib)

test:
	(cd Experiment       && $(MAKE))

clean: 
	(cd Foundation       && $(MAKE) clean)
	(cd Generated        && $(MAKE) clean)
	(cd Experiment       && $(MAKE) clean)

