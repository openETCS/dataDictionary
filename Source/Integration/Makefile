
MAKEFLAGS += --no-print-directory --silent

TOPDIR=..
export BITWALKER=$(TOPDIR)/Bitwalker
export GENERATED_PACKETS=$(TOPDIR)/Generated_Packets
export TELEGRAM=$(TOPDIR)/Message_Telegram

it: server_BTM

include ../Makefile.template

CPPFLAGS = -I../Source/Bitwalker
CXXFLAGS = -Wall -std=c++11

VPATH=$(TELEGRAM)

CPPFLAGS += -I$(TELEGRAM)

CPPFLAGS += -I$(GENERATED_PACKETS)
LDFLAGS += -L$(GENERATED_PACKETS) -lgenerated_packets


CPPFLAGS += -I$(BITWALKER)
LDFLAGS += -L$(BITWALKER) -lBitwalker


server_BTM: server_BTM.o Eurobalise_Telegram.o Telegram_Header_Encoder.o Telegram_Header_Decoder.o Packet_Header.o Telegram_Header_UpperBitsNotSet.o print_bits.o
	$(CXX) -o $@ $+ $(LDFLAGS)


format:
	$(ASTYLE) *.cpp *.c

clean::
	$(RM) server_BTM
	$(RM) *.o

