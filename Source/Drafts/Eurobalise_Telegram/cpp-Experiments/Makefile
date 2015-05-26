TOPDIR=../../..

VPATH = $(TOPDIR)/Bitwalker
#CXX = c++
CPPFLAGS += -I./Packet_Header -I./Subset_Structs -I. -I$(TOPDIR)/Bitwalker
CXXFLAGS += -std=c++11
LDFLAGS += -L $(TOPDIR)/Bitwalker -lBitwalker -LSubset_Structs -lsubset_structs

it: decoder_test

decoder_test: decoder_test.o Eurobalise_Telegram.o 
	$(CXX) -o $@ $+ $(LDFLAGS)

clean:
	$(RM) *.o


