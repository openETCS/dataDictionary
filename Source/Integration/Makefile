
MAKEFLAGS += --no-print-directory --silent

TOPDIR=..
export BITWALKER=$(TOPDIR)/Bitwalker
export GENERATED_PACKETS=$(TOPDIR)/Generated_Packets
export MESSAGE_TELEGRAM=$(TOPDIR)/Message_Telegram


it: lib server_BTM

lib:    $(MESSAGE_TELEGRAM)/libmessage_telegram.a\
        $(GENERATED_PACKETS)/libgenerated_packets.a\
        $(BITWALKER)/libBitwalker.a

include ../Makefile.template

CPPFLAGS = -I../Source/Bitwalker
CXXFLAGS = -Wall -std=c++11

CPPFLAGS += -I$(MESSAGE_TELEGRAM)
LDFLAGS += -L$(MESSAGE_TELEGRAM) -lmessage_telegram

CPPFLAGS += -I$(GENERATED_PACKETS)
LDFLAGS += -L$(GENERATED_PACKETS) -lgenerated_packets

CPPFLAGS += -I$(BITWALKER)
LDFLAGS += -L$(BITWALKER) -lBitwalker


server_BTM: server_BTM.o
	$(CXX) -o $@ $+ $(LDFLAGS)
	$(RM) $<

format:
	$(ASTYLE) *.cpp *.c

clean::
	$(RM) server_BTM
	$(RM) *.o

