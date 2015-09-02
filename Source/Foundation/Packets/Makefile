
MAKEFLAGS += --no-print-directory --silent

TOPDIR=../..
export BITWALKER=$(TOPDIR)/Foundation/Bits

it: libbase_packets.a

include $(TOPDIR)/Makefile.template

lib:	libbase_packets.a\

#CXX = c++
CXXFLAGS += -std=c++11

CPPFLAGS += -I$(BITWALKER)

SRC= Packet_Header.cpp


OBJ := $(SRC:.cpp=.o)


libbase_packets.a : $(OBJ)
	ar cru  $@ $^
	ranlib  $@
	$(RM) $(OBJ)


FORMAT := $(wildcard *.h) $(wildcard *.cpp) $(wildcard *.c)

format: FORCE
	$(ASTYLE) $(FORMAT)

clean::
	@$(RM) *.o
	@$(RM) *.a

