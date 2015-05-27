
MAKEFLAGS += --no-print-directory --silent

TOPDIR=..
export BITWALKER=$(TOPDIR)/Bitwalker

#VPATH = $(TOPDIR)/Bitwalker

include $(TOPDIR)/Makefile.template

#CXX = c++
CPPFLAGS += -I.

CPPFLAGS += -I$(BITWALKER)
LDFLAGS += -L$(BITWALKER) -lBitwalker

SRC :=  $(wildcard *.c)

OBJ := $(SRC:.c=.o)

lib: libtelegram_header.a

libtelegram_header.a : $(OBJ)
	ar cru  $@ $^
	ranlib  $@

clean::
	$(RM) libtelegram_header.a
	$(RM) *.o

