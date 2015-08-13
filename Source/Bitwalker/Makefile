
#.SECONDARY:

MAKEFLAGS += --no-print-directory --silent

TOPDIR=..

include $(TOPDIR)/Makefile.template

#WP_FLAGS += -wp-prop=-rte
#WP_FLAGS += -wp-prop=-@lemma
#WP_FLAGS += -wp-prop=cea


SRC :=  UpperBitsNotSet.c\
        Bitwalker.c\
        Bitwalker_Read.c Bitwalker_Write.c\
	Bitstream.c Bitstream_Init.c\
	Bitstream_Read.c Bitstream_Write.c\
	Bitstream_ReadThenWrite.c Bitstream_WriteThenRead.c\

OBJ := $(SRC:.c=.o)
REPORT := $(SRC:.c=.report)
CHECK :=  $(SRC:.c=.check)

it : $(OBJ)

check: $(CHECK)

clean::
	@$(RM) $(OBJ)
	@$(RM) libBitwalker.a
	

format: FORCE
	@$(ASTYLE) *.c *.h

lib: libBitwalker.a

libBitwalker.a : $(OBJ)
	ar cru	$@ $^
	ranlib	$@


par:
	@time $(MAKE) -j 3 -O $(REPORT)

log: FORCE
	@(time $(MAKE) report > results.txt)
	

report: $(REPORT)

