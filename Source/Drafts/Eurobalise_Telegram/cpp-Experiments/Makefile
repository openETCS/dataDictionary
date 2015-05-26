TOPDIR=../../..

VPATH = $(TOPDIR)/Bitwalker
CXX = c++
CPPFLAGS += -I./Packet_Header -I./Subset_Structs -I. -I$(TOPDIR)/Bitwalker
CXXFLAGS += -std=c++11


it: decoder_test

decoder_test: Eurobalise_Telegram.o decoder_test.o

clean:
	$(RM) *.o


