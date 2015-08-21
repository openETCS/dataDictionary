
MAKEFLAGS += --no-print-directory --silent

TOPDIR=..

it: lib

include $(TOPDIR)/Makefile.template
export BITWALKER=$(TOPDIR)/Bitwalker
export GENERATED_PACKETS=$(TOPDIR)/Generated_Packets

#VPATH = $(TOPDIR)/Bitwalker

#CXX = c++
CPPFLAGS += -I.

CPPFLAGS += -I$(BITWALKER)
CPPFLAGS += -I$(TOPDIR)/Eurobalise_Telegram
CPPFLAGS += -I$(TOPDIR)/Packet_Header
CPPFLAGS += -I$(TOPDIR)/Euroradio_Message
CPPFLAGS += -I$(GENERATED_PACKETS)

LDFLAGS += -L$(BITWALKER) -lBitwalker
LDFLAGS += -L$(GENERATED_PACKETS) -lgenerated_packets

SRC :=  $(wildcard *.c)
SRCXX :=  $(wildcard *.cpp)

OBJ := $(SRC:.c=.o) $(SRCXX:.cpp=.o)

lib: libgenerated_messages.a

libgenerated_messages.a : $(OBJ)
	ar cru  $@ $^
	ranlib  $@

clean::
	$(RM) libgenerated_messages.a
	$(RM) *.o

