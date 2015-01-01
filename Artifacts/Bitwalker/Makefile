

include ../Makefile.template

#WP_FLAGS += -wp-prop=-rte
#WP_FLAGS += -wp-prop=-@lemma
#WP_FLAGS += -wp-prop=cea

SRC := $(wildcard *.c)
OBJ := $(SRC:.c=.o)

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

log: FORCE
	@(time make report-wp > results.txt&)
	

report-wp:\
	Bit8.report-wp\
	Bit8Array.report-wp\
	Bit64.report-wp\
        Bitwalker_Peek_Normal.report-wp\
        Bitwalker_Peek.report-wp\
        Bitwalker_Poke_Normal.report-wp\
        Bitwalker_Poke.report-wp\
	PeekThenPoke.report-wp\
	PokeThenPeek.report-wp\
	Bitstream_Init.report-wp\
	Bitstream_Read_Normal.report-wp\
	Bitstream_Read.report-wp\
	Bitstream_Write_Normal.report-wp\
	Bitstream_Write.report-wp\
	Bitstream_ReadThenWrite.report-wp\
	Bitstream_WriteThenRead.report-wp\

