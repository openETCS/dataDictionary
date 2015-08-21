
MAKEFLAGS += --no-print-directory --silent

TOPDIR=..

it: lib

include $(TOPDIR)/Makefile.template
export BITWALKER=$(TOPDIR)/Bitwalker

#VPATH = $(TOPDIR)/Bitwalker

#CXX = c++
CPPFLAGS += -I.

CPPFLAGS += -I$(BITWALKER)
CPPFLAGS += -I$(TOPDIR)/Eurobalise_Telegram
CPPFLAGS += -I$(TOPDIR)/Packet_Header

LDFLAGS += -L$(BITWALKER) -lBitwalker

SRC :=  $(wildcard *.c)
SRCXX :=  $(wildcard *.cpp)

OBJ := $(SRC:.c=.o) $(SRCXX:.cpp=.o)

lib: libgenerated_packets.a

libgenerated_packets.a : $(OBJ)
	ar cru  $@ $^
	ranlib  $@
	$(RM) $(OBJ)

clean::
	$(RM) libgenerated_packets.a
	$(RM) *.o

