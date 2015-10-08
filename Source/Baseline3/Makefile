
MAKEFLAGS += --silent
MAKEFLAGS += --no-print-directory

it: lib test

lib:
	(cd Foundation          && $(MAKE) -j 4 lib)
	(cd Generated           && $(MAKE) -j 4 lib)
	(cd Message_Telegram    && $(MAKE))

test:
	(cd Tests       && $(MAKE))
	(cd Integration && $(MAKE))

clean: 
	(cd Foundation         && $(MAKE) clean)
	(cd Generated          && $(MAKE) clean)
	(cd Message_Telegram   && $(MAKE) clean)
	(cd Tests              && $(MAKE) clean)
	(cd Integration        && $(MAKE) clean)

