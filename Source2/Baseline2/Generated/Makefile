
MAKEFLAGS += --silent
MAKEFLAGS += --no-print-directory

it: lib

lib:
	(cd PacketsWithoutNITER    && $(MAKE) lib)
	(cd PacketsWithNITER       && $(MAKE) lib)

clean: 
	(cd PacketsWithoutNITER    && $(MAKE) clean)
	(cd PacketsWithNITER       && $(MAKE) clean)

