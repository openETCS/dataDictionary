
MAKEFLAGS += --no-print-directory --silent

include ../Makefile.template

#WP_FLAGS += -wp-prop=-rte
#WP_FLAGS += -wp-prop=-@lemma
#WP_FLAGS += -wp-prop=cea

SRC :=  Bitwalker.c\
        Bitwalker_Peek_Normal.c Bitwalker_Peek.c\
        Bitwalker_Poke_Normal.c Bitwalker_Poke.c\
	PeekThenPoke.c PokeThenPeek.c\
	Bitstream.c Bitstream_Init.c\
	Bitstream_Read_Normal.c Bitstream_Read.c\
	Bitstream_Write_Normal.c Bitstream_Write.c\
	Bitstream_ReadThenWrite.c Bitstream_WriteThenRead.c\

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
	@time $(MAKE) -j 2 -O $(REPORT)

log: FORCE
	@(time $(MAKE) report > results.txt)
	

report: $(REPORT)

