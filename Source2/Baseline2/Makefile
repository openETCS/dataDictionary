
MAKEFLAGS += --silent
MAKEFLAGS += --no-print-directory

it: lib test

lib:
	(cd Foundation       && $(MAKE) lib)

test:
	(cd Experiment       && $(MAKE))

clean: 
	(cd Foundation       && $(MAKE) clean)
	(cd Experiment       && $(MAKE) clean)

