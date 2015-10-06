
#MAKEFLAGS += --silent
#MAKEFLAGS += --no-print-directory

it: baseline2 baseline3

baseline2: FORCE
	(cd Baseline2          && $(MAKE) it)

baseline3: FORCE
	(cd Baseline3          && $(MAKE) it)

clean: FORCE
	(cd Baseline2         && $(MAKE) clean)
	(cd Baseline3         && $(MAKE) clean)


FORCE:

