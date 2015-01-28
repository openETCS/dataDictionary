
MAKEFLAGS += --silent --no-print-directory

TOPDIR=..

WP_FLAGS += -wp-prop=DEF_equal
#WP_FLAGS += -wp-prop=-@lemma
#WP_FLAGS += -wp-prop=cea

it: obj

include $(TOPDIR)/Makefile.template

VPATH = $(TOPDIR)/Bitwalker
CPPFLAGS += -I$(TOPDIR)/Bitwalker

#SRC := $(wildcard *.c)
SRC :=  Package_Foo_Init.c\
	Package_Foo_UpperBitsNotSet.c\
	Package_Foo_Decoder.c\
	Package_Foo_Encoder.c\
	Package_Foo_DecoderThenEncoder.c\
	Package_Foo_EncoderThenDecoder.c

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

