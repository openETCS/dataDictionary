
MAKEFLAGS += --silent
MAKEFLAGS += --no-print-directory

it: lib

lib:
	(cd Packets    && $(MAKE) lib)
	(cd Messages   && $(MAKE) lib)

clean: 
	(cd Packets    && $(MAKE) clean)
	(cd Messages   && $(MAKE) clean)

