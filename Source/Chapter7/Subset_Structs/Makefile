include Makefile.template

VPATH := $(BITWALKER)

CPPFLAGS= -I./ -I../ -I$(BITWALKER)
CFLAGS=-Wall  --std=c99

LIBS:= Bitwalker.a

SRC := $(wildcard *.c)
OBJ := $(SRC:.c=.o)

objects: $(OBJ)

AdhesionTest: Adhesion_Factor.o
OnboardTest: Onboard_telephone_numbers.o PokeNext.o PeekNext.o Init.o PeekFinish.o PokeFinish.o Peek.o Poke.o Bit8Array.o Bit64.o Bit8.o
