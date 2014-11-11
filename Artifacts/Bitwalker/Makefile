

include Makefile.template

SRC := $(wildcard *.c)
OBJ := $(SRC:.c=.o)

obj : $(OBJ)

clean::
	@$(RM) libBitwalker.a
	@$(RM) TestPeekThenPoke
	

lib: libBitwalker.a

libBitwalker.a : Bit8Array.o\
		 Peek.o Poke.o\
		 Init.o PeekNext.o PokeNext.o 
	ar cru	$@ $^
	ranlib	$@

TestPeekThenPoke: TestPeekThenPoke.o PeekThenPoke.o libBitwalker.a
	$(CXX) -o $@ $^
	./$@

tests:	TestPeekThenPoke

report-wp:\
	Bit8Array.report-wp\
        Peek.report-wp\
        Poke.report-wp\
	PeekThenPoke.report-wp\
	PokeThenPeek.report-wp\
	Init.report-wp\
	PeekNext.report-wp\
	PokeNext.report-wp\

