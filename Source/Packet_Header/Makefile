
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

lib: libpacket_header.a

libpacket_header.a : $(OBJ)
	ar cru  $@ $^
	ranlib  $@

clean::
	$(RM) libpacket_header.a
	$(RM) *.o

