
MAKEFLAGS += --silent --no-print-directory

it: obj

TOPDIR=../../..

include $(TOPDIR)/Makefile.template
VPATH = $(TOPDIR)/Bitwalker
CPPFLAGS += -I$(TOPDIR)/Bitwalker

#SRC := $(wildcard *.c)
SRC :=  Adhesion_Factor_Init.c\
	Adhesion_Factor_UpperBitsNotSet.c\
	Adhesion_Factor_Decoder.c\
	Adhesion_Factor_Encoder.c\

#Adhesion_Factor_DecoderThenEncoder.c\
#Adhesion_Factor_EncoderThenDecoder.c

OBJ := $(SRC:.c=.o)
REPORT := $(SRC:.c=.report)

format: FORCE
	@$(ASTYLE) *.c *.h 

obj: $(OBJ)

par:
	@time $(MAKE) -j 3 -O $(REPORT)

log: FORCE
	@(time $(MAKE) report > results.txt)

report: $(REPORT)

