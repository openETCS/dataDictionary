
MAKEFLAGS += --no-print-directory --silent

include ../Makefile.template

#WP_FLAGS += -wp-prop=-rte
#WP_FLAGS += -wp-prop=-@lemma
#WP_FLAGS += -wp-prop=cea

SRC := $(wildcard *.c)
OBJ := $(SRC:.c=.o)
REPORT := $(SRC:.c=.report)

obj : $(OBJ)

clean::
	@$(RM) libBitwalker.a
	@$(RM) TestPeekThenPoke
	

format: FORCE
	@$(ASTYLE) *.c *.h

lib: libBitwalker.a

libBitwalker.a : Bit8.o Bit8Array.o Bit64.o\
		 Bitwalker_Peek_Normal.o Bitwalker_Peek.o\
                 Bitwalker_Poke_Normal.o Bitwalker_Poke.o\
		 Bitstream_Init.o\
                 Bitstream_Read_Normal.o Bitstream_Read.o\
                 Bitstream_Write_Normal.o Bitstream_Write.o 
	ar cru	$@ $^
	ranlib	$@

TestPeekThenPoke: TestPeekThenPoke.o PeekThenPoke.o libBitwalker.a
	$(CXX) -o $@ $^
	./$@

tests:	TestPeekThenPoke

par:
	@time $(MAKE) -j 3 -O $(REPORT)

log: FORCE
	@(time $(MAKE) report > results.txt&)
	

report:\
	Bit8.report\
	Bit8Array.report\
	Bit64.report\
        Bitwalker_Peek_Normal.report\
        Bitwalker_Peek.report\
        Bitwalker_Poke_Normal.report\
        Bitwalker_Poke.report\
	PeekThenPoke.report\
	PokeThenPeek.report\
	Bitstream_Init.report\
	Bitstream_Read_Normal.report\
	Bitstream_Read.report\
	Bitstream_Write_Normal.report\
	Bitstream_Write.report\
	Bitstream_ReadThenWrite.report\
	Bitstream_WriteThenRead.report\

