
MAKEFLAGS += --no-print-directory --silent

TOPDIR=..
export BITS=$(TOPDIR)/Foundation/Bits
export BASE_PACKETS=$(TOPDIR)/Foundation/Packets
export GENERATED_PACKETS=$(TOPDIR)/Generated/Packets
export MESSAGE_TELEGRAM=$(TOPDIR)/Message_Telegram


it: lib server_BTM

lib:	$(BITS)/libbits.a\
        $(GENERATED_PACKETS)/libgenerated_packets.a\
	$(MESSAGE_TELEGRAM)/libmessage_telegram.a\


include $(TOPDIR)/Makefile.template

CXXFLAGS = -Wall -std=c++11

CPPFLAGS += -I$(MESSAGE_TELEGRAM)
LDFLAGS += -L$(MESSAGE_TELEGRAM) -lmessage_telegram

CPPFLAGS += -I$(GENERATED_PACKETS)
LDFLAGS += -L$(GENERATED_PACKETS) -lgenerated_packets

CPPFLAGS += -I$(BASE_PACKETS)

CPPFLAGS += -I$(BITS)
LDFLAGS += -L$(BITS) -lbits


server_BTM: server_BTM.o
	$(CXX) -o $@ $+ $(LDFLAGS)
	$(RM) $<

format:
	$(ASTYLE) *.cpp *.c

clean::
	$(RM) server_BTM
	$(RM) *.o

