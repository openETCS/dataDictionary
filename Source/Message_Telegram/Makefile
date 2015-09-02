
MAKEFLAGS += --no-print-directory --silent

TOPDIR=..
export BITS=$(TOPDIR)/Foundation/Bits
export BASE_PACKETS=$(TOPDIR)/Foundation/Packets
export GENERATED_PACKETS=$(TOPDIR)/Generated/Packets
export GENERATED_MESSAGES=$(TOPDIR)/Generated/Messages

it: libmessage_telegram.a

include $(TOPDIR)/Makefile.template

lib:	libmessage_telegram.a

CXXFLAGS += -std=c++11

CPPFLAGS += -I.
CPPFLAGS += -I$(BITS)
CPPFLAGS += -I$(BASE_PACKETS)
CPPFLAGS += -I$(GENERATED_PACKETS)
CPPFLAGS += -I$(GENERATED_MESSAGES)

SRC= print_bits.cpp Eurobalise_Telegram.cpp\
     Euroradio_Message.cpp Message_Header.cpp

OBJ := $(SRC:.cpp=.o)

OBJ += Telegram_Header.o


libmessage_telegram.a : $(OBJ)
	ar cru  $@ $^
	ranlib  $@
	$(RM) $(OBJ)

print_bits: print_bits.o
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -o $@ $<
	$(RM) $<

bits: print_bits
	./print_bits


FORMAT := $(wildcard *.h) $(wildcard *.cpp) $(wildcard *.c)

format: FORCE
	$(ASTYLE) $(FORMAT)

clean::
	@$(RM) *.o
	@$(RM) *.a
	@$(RM) print_bits

