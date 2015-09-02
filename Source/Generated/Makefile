
MAKEFLAGS += --silent
MAKEFLAGS += --no-print-directory

it: lib

lib:
	(cd Packets    && $(MAKE) -j 4 lib)
	(cd Messages   && $(MAKE) -j 4 lib)

clean: 
	(cd Packets    && $(MAKE) clean)
	(cd Messages   && $(MAKE) clean)

