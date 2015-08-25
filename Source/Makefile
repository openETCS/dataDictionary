
#MAKEFLAGS += --silent --no-print-directory

it: lib test

lib:
	@(cd Bitwalker       && $(MAKE) lib)
	@(cd Generated_Packets && $(MAKE) lib)
	@(cd Generated_Messages && $(MAKE) lib)

test:
	@(cd Message_Telegram && $(MAKE))

clean: 
	@(cd Coq             && $(MAKE) clean)
	@(cd Bitwalker       && $(MAKE) clean)
	@(cd Generated_Packets && $(MAKE) clean)
	@(cd Generated_Messages && $(MAKE) clean)
	@(cd Message_Telegram && $(MAKE) clean)

format: 
	(cd Bitwalker       && $(MAKE) format)

report: 
	(cd Bitwalker       && $(MAKE) report)

par: 
	(cd Bitwalker       && $(MAKE) par)

log: 
	(cd Bitwalker       && $(MAKE) log)
