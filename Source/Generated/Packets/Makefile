
MAKEFLAGS += --no-print-directory --silent

TOPDIR=../..

it: lib

include $(TOPDIR)/Makefile.template
export BITS=$(TOPDIR)/Foundation/Bits
export PACKETS_BASE=$(TOPDIR)/Foundation/Packets

CPPFLAGS += -I.

CPPFLAGS += -I$(BITS)
CPPFLAGS += -I$(PACKETS_BASE)

LDFLAGS += -L$(BITS) -lbits

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

format: FORCE
	@$(ASTYLE) *.c *.cpp *.h
