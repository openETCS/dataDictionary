
MAKEFLAGS += --no-print-directory --silent

TOPDIR=..

include $(TOPDIR)/Makefile.template

#WP_FLAGS += -wp-prop=-rte
#WP_FLAGS += -wp-prop=-@lemma
#WP_FLAGS += -wp-prop=cea

SRC :=  UpperBitsNotSet.c\
        Bitwalker.c\
        Bitwalker_Peek_Normal.c Bitwalker_Poke_Normal.c\
	PeekThenPoke.c PokeThenPeek.c\
	Bitstream.c Bitstream_Init.c\

OBJ := $(SRC:.c=.o)
REPORT := $(SRC:.c=.report)

it : $(OBJ)

clean::
	@$(RM) $(OBJ)
	@$(RM) libBitwalker.a
	@$(RM) TestPeekThenPoke
	

format: FORCE
	@$(ASTYLE) *.c *.h

lib: libBitwalker.a

libBitwalker.a : $(OBJ)
	ar cru	$@ $^
	ranlib	$@

TestPeekThenPoke: TestPeekThenPoke.o PeekThenPoke.o libBitwalker.a
	$(CXX) -o $@ $^
	./$@

tests:	TestPeekThenPoke

par:
	@time $(MAKE) -j 3 -O $(REPORT)

log: FORCE
	@(time $(MAKE) report > results.txt)
	

report: $(REPORT)

