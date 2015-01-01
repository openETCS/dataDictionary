
it: compile

BitLemmas.vo: BitLemmas.v
	@coqc -R $(FRAMAC_SHARE)/wp/coqwp -as "" BitLemmas.v

compile: BitLemmas.vo

proof: FORCE
	@(coqide -R $(FRAMAC_SHARE)/wp/coqwp -as "" BitLemmas.v &)

clean: FORCE
	@$(RM)	BitLemmas.glob
	@$(RM)	BitLemmas.vo

FORCE:

