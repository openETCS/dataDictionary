
MAKEFLAGS += --silent --no-print-directory

it: 
	(cd Coq             && $(MAKE) it)
	(cd Bitwalker       && $(MAKE) it)

format: 
	(cd Bitwalker       && $(MAKE) format)

report: 
	(cd Bitwalker       && $(MAKE) report)

par: 
	(cd Bitwalker       && $(MAKE) par)

log: 
	(cd Bitwalker       && $(MAKE) log)

clean: 
	(cd Coq             && $(MAKE) clean)
	(cd Bitwalker       && $(MAKE) clean)
	(cd Generated_Packets && $(MAKE) clean)
	(cd Generated_Messages && $(MAKE) clean)
	(cd Eurobalise_Telegram && $(MAKE) clean)
	(cd Euroradio_Message && $(MAKE) clean)
