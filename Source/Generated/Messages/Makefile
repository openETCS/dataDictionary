
MAKEFLAGS += --no-print-directory --silent

TOPDIR=../..

it: lib

include $(TOPDIR)/Makefile.template
export BITS=$(TOPDIR)/Foundation/Bits
export BASE_PACKETS=$(TOPDIR)/Foundation/Packets
export GENERATED_PACKETS=$(TOPDIR)/Generated/Packets
export MESSAGE_TELEGRAM=$(TOPDIR)/Message_Telegram

CPPFLAGS += -I.

CPPFLAGS += -I$(BITS)
CPPFLAGS += -I$(BASE_PACKETS)
CPPFLAGS += -I$(GENERATED_PACKETS)
CPPFLAGS += -I$(MESSAGE_TELEGRAM)

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

