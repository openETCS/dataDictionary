
MAKEFLAGS += --silent --no-print-directory

it:
	while read dir; do \
		echo $$dir; \
		$(MAKE) -C $$dir it -n; \
	done < ./Static

report:
	while read dir; do \
		echo $$dir; \
		$(MAKE) -C $$dir report; \
	done < ./Static

clean:
	while read dir; do \
		$(MAKE) -C $$dir clean; \
	done < ./Static
#it: 
#	(cd Coq             && $(MAKE) it)
#	(cd Bitwalker       && $(MAKE) it)
#	(cd Package_Foo     && $(MAKE) it)
#	(cd Adhesion_Factor && $(MAKE) it)

#format: 
#	(cd Bitwalker       && $(MAKE) format)
#	(cd Package_Foo     && $(MAKE) format)
#	(cd Adhesion_Factor && $(MAKE) format)

#report: 
#	(cd Bitwalker       && $(MAKE) report)
#	(cd Package_Foo     && $(MAKE) report)
#	(cd Adhesion_Factor && $(MAKE) report)

#par: 
#	(cd Bitwalker       && $(MAKE) par)
#	(cd Package_Foo     && $(MAKE) par)
#	(cd Adhesion_Factor && $(MAKE) par)

#log: 
#	(cd Bitwalker       && $(MAKE) log)
#	(cd Package_Foo     && $(MAKE) log)
#	(cd Adhesion_Factor && $(MAKE) log)

#clean: 
#	(cd Coq             && $(MAKE) clean)
#	(cd Bitwalker       && $(MAKE) clean)
#	(cd Package_Foo     && $(MAKE) clean)
#	(cd Adhesion_Factor && $(MAKE) clean)
