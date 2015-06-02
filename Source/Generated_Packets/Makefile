
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

lib: libgenerated_packets.a

libgenerated_packets.a : $(OBJ)
	ar cru  $@ $^
	ranlib  $@
	$(RM) $(OBJ)

clean::
	$(RM) libgenerated_packets.a
	$(RM) *.o

