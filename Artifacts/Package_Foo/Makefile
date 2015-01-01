
MAKEFLAGS += --silent --no-print-directory

WP_FLAGS += -wp-prop=DEF_equal
#WP_FLAGS += -wp-prop=-@lemma
#WP_FLAGS += -wp-prop=cea

it: obj


SRC := $(wildcard *.c)
OBJ := $(SRC:.c=.o)
REPORT := $(SRC:.c=.report)


include ../Makefile.template

VPATH = ../Bitwalker
CPPFLAGS += -I../Bitwalker


format: FORCE
	@$(ASTYLE) *.c *.h

obj: $(OBJ)

par:
	@time $(MAKE) -j 3 -O $(REPORT)

log: FORCE
	@(time $(MAKE) report > results.txt&)

report: \
	Package_Foo_Init.report\
	Package_Foo_UpperBitsNotSet.report\
	Package_Foo_Decoder.report\
	Package_Foo_Encoder.report\
	Package_Foo_DecoderThenEncoder.report\
	Package_Foo_EncoderThenDecoder.report\

