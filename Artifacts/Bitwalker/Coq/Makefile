
it: compile

proof: FORCE
	@(coqide -R $(FRAMAC_SHARE)/wp/coqwp -as "" BitLemmas.v &)


compile: FORCE
	coqc -R $(FRAMAC_SHARE)/wp/coqwp -as "" BitLemmas.v


clean: FORCE
	$(RM)	BitLemmas.glob
	$(RM)	BitLemmas.vo


FORCE:

