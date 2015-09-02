
MAKEFLAGS += --silent
MAKEFLAGS += --no-print-directory

it: lib 

lib:
	(cd Bits     && $(MAKE) -j 4 lib)
	(cd Packets  && $(MAKE) -j 4 lib)

clean: 
	(cd Coq      && $(MAKE) clean)
	(cd Bits     && $(MAKE) clean)
	(cd Packets  && $(MAKE) clean)

