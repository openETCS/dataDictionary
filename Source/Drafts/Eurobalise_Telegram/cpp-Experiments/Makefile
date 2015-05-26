TOPDIR=../../..

VPATH = $(TOPDIR)/Bitwalker

include $(TOPDIR)/Makefile.template

#CXX = c++
CPPFLAGS += -I./Packet_Header -I./Subset_Structs -I. -I$(TOPDIR)/Bitwalker
LDFLAGS += -L $(TOPDIR)/Bitwalker -lBitwalker -LSubset_Structs -lsubset_structs

it: decoder_test

decoder_test: decoder_test.o Eurobalise_Telegram.o\
	Eurobalise_Header_Encoder.o Eurobalise_Header_Decoder.o\
	Eurobalise_Header_UpperBitsNotSet.o Decoder_Branch.o\
        Packet_Header/Packet_Header_Decoder.o
	$(CXX) -o $@ $+ $(LDFLAGS)


