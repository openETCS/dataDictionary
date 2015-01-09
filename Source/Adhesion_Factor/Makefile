
MAKEFLAGS += --silent --no-print-directory

WP_FLAGS += -wp-prop=DEF_equal
#WP_FLAGS += -wp-prop=-@lemma
#WP_FLAGS += -wp-prop=cea

it: obj

include ../Makefile.template

#SRC := $(wildcard *.c)
SRC :=  Adhesion_Factor_Init.c\
	Adhesion_Factor_UpperBitsNotSet.c\
	Adhesion_Factor_Decoder.c\
	Adhesion_Factor_Encoder.c\
	Adhesion_Factor_DecoderThenEncoder.c\
	Adhesion_Factor_EncoderThenDecoder.c

OBJ := $(SRC:.c=.o)
REPORT := $(SRC:.c=.report)

VPATH = ../Bitwalker
CPPFLAGS += -I../Bitwalker

format: FORCE
	@$(ASTYLE) *.c *.h 

obj: $(OBJ)

par:
	@time $(MAKE) -j 3 -O $(REPORT)

log: FORCE
	@(time $(MAKE) report > results.txt)

report: $(REPORT)

