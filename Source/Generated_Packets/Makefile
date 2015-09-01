
MAKEFLAGS += --no-print-directory --silent

TOPDIR=..

it: lib

include $(TOPDIR)/Makefile.template
export BITWALKER=$(TOPDIR)/Bitwalker
export MESSAGE_TELEGRAM=$(TOPDIR)/Message_Telegram

#VPATH = $(TOPDIR)/Bitwalker

#CXX = c++
CPPFLAGS += -I.

CPPFLAGS += -I$(BITWALKER)
CPPFLAGS += -I$(MESSAGE_TELEGRAM)

LDFLAGS += -L$(BITWALKER) -lBitwalker

SRC :=  $(wildcard *.c)
SRCXX :=  $(wildcard *.cpp)

OBJ := $(SRC:.c=.o) $(SRCXX:.cpp=.o)

lib: libgenerated_packets.a

libgenerated_packets.a : $(OBJ)
	ar cru  $@ $^
	ranlib  $@

clean::
	$(RM) libgenerated_packets.a
	$(RM) *.o

