
it: obj

include ../Makefile.template

VPATH = ../Bitwalker
CPPFLAGS += -I../Bitwalker


obj:\
	Adhesion_Factor_Init.o\
     	Adhesion_Factor_UpperBitsNotSet.o\
     	Adhesion_Factor_Decoder.o\
     	Adhesion_Factor_Encoder.o\
	Adhesion_Factor_DecoderThenEncoder.o\
	Adhesion_Factor_EncoderThenDecoder.o\


report-wp:\
	Adhesion_Factor_Init.report-wp\
	Adhesion_Factor_UpperBitsNotSet.report-wp\
	Adhesion_Factor_Decoder.report-wp\
	Adhesion_Factor_Encoder.report-wp\
	Adhesion_Factor_DecoderThenEncoder.report-wp\
	Adhesion_Factor_EncoderThenDecoder.report-wp\


format: FORCE
	@$(ASTYLE) *.c *.h
