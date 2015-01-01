
MAKEFLAGS += --no-print-directory

it: obj

include ../Makefile.template

VPATH = ../Bitwalker
CPPFLAGS += -I../Bitwalker


obj:\
	Package_Foo_Init.o\
     	Package_Foo_UpperBitsNotSet.o\
     	Package_Foo_Decoder.o\
     	Package_Foo_Encoder.o\
	Package_Foo_DecoderThenEncoder.o\
	Package_Foo_EncoderThenDecoder.o\


report:\
	Package_Foo_Init.report\
	Package_Foo_UpperBitsNotSet.report\
	Package_Foo_Decoder.report\
	Package_Foo_Encoder.report\
	Package_Foo_DecoderThenEncoder.report\
	Package_Foo_EncoderThenDecoder.report\


format: FORCE
	@$(ASTYLE) *.c *.h
