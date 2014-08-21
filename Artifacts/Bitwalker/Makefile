

include Makefile.template

SRC := $(wildcard *.c)
OBJ := $(SRC:.c=*.o)

obj : $(OBJ)

Peek.report: Peek.c
	@(. ${SCRIPT_DIR}/script_functions.sh; reportWp Peek;);

Poke.report: Poke.c
	@(. ${SCRIPT_DIR}/script_functions.sh; reportWp Poke;);

PeekThenPoke.report: PeekThenPoke.c
	@(. ${SCRIPT_DIR}/script_functions.sh; reportWp PeekThenPoke;);

PokeThenPeek.report: PokeThenPeek.c
	@(. ${SCRIPT_DIR}/script_functions.sh; reportWp PokeThenPeek;);

PeekNext.report: PeekNext.c
	@(. ${SCRIPT_DIR}/script_functions.sh; reportWp PeekNext;);

PokeNext.report: PokeNext.c
	@(. ${SCRIPT_DIR}/script_functions.sh; reportWp PokeNext;);

Bit8.report: Bit8.c
	@(. ${SCRIPT_DIR}/script_functions.sh; reportWp Bit8;);

Bit8Array.report: Bit8Array.c
	@(. ${SCRIPT_DIR}/script_functions.sh; reportWp Bit8Array;);

Bit64.report: Bit64.c
	@(. ${SCRIPT_DIR}/script_functions.sh; reportWp Bit64;);

PeekFinish.report: PeekFinish.c
	@(. ${SCRIPT_DIR}/script_functions.sh; reportWp PeekFinish;);

PokeFinish.report: PokeFinish.c
	@(. ${SCRIPT_DIR}/script_functions.sh; reportWp PokeFinish;);

report:\
	Bit8.report\
	Bit8Array.report\
	Bit64.report\
        Peek.report\
        Poke.report\
	PeekThenPoke.report\
	PokeThenPeek.report\
	PeekNext.report\
	PokeNext.report\
	PeekFinish.report\
	PokeFinish.report\

