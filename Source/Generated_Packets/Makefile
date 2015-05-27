
MAKEFLAGS += --no-print-directory --silent

TOPDIR=..

include $(TOPDIR)/Makefile.template
export BITWALKER=$(TOPDIR)/Bitwalker

#VPATH = $(TOPDIR)/Bitwalker

#CXX = c++
CPPFLAGS += -I.

CPPFLAGS += -I$(BITWALKER)
LDFLAGS += -L$(BITWALKER) -lBitwalker

SRC :=  $(wildcard *.c)

OBJ := $(SRC:.c=.o)

lib: libsubset_structs.a

libsubset_structs.a : $(OBJ)
	ar cru  $@ $^
	ranlib  $@

clean::
	$(RM) libsubset_structs.a
	$(RM) *.o

