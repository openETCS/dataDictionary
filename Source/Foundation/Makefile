
MAKEFLAGS += --silent
MAKEFLAGS += --no-print-directory

it: lib 

lib:
	(cd Bits     && $(MAKE) lib)
	(cd Packets  && $(MAKE) lib)

clean: 
	(cd Coq      && $(MAKE) clean)
	(cd Bits     && $(MAKE) clean)
	(cd Packets  && $(MAKE) clean)

