

include Makefile.template

SRC := $(wildcard *.c)
OBJ := $(SRC:.c=.o)

obj : $(OBJ)

clean::
	@$(RM) libBitwalker.a
	@$(RM) TestPeekThenPoke
	

lib: libBitwalker.a

libBitwalker.a : Bit8Array.o\
		 Bitwalker_Peek.o Bitwalker_Poke.o\
		 Bitstream_Init.o Bitstream_Read.o Bitstream_ReadInt32.o Bitstream_Write.o 
	ar cru	$@ $^
	ranlib	$@

TestPeekThenPoke: TestPeekThenPoke.o PeekThenPoke.o libBitwalker.a
	$(CXX) -o $@ $^
	./$@

tests:	TestPeekThenPoke

report-wp:\
	Bit8Array.report-wp\
        Bitwalker_Peek.report-wp\
        Bitwalker_Poke.report-wp\
	PeekThenPoke.report-wp\
	PokeThenPeek.report-wp\
	Bitstream_Init.report-wp\
	Bitstream_Read.report-wp\
	Bitstream_ReadInt32.report-wp\
	Bitstream_Write.report-wp\

