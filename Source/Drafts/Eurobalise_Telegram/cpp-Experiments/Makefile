
MAKEFLAGS += --no-print-directory --silent

TOPDIR=../../..
export BITWALKER=$(TOPDIR)/Bitwalker
export GENERATED_PACKETS=Subset_Structs

include $(TOPDIR)/Makefile.template

#CXX = c++
CPPFLAGS += -I.

CPPFLAGS += -I$(BITWALKER)
LDFLAGS += -L$(BITWALKER) -lBitwalker

CPPFLAGS += -I$(GENERATED_PACKETS)
LDFLAGS += -L$(GENERATED_PACKETS) -lsubset_structs

CPPFLAGS += -I./Packet_Header

lib:
	@(cd $(BITWALKER) && $(MAKE) lib)
	@(cd $(GENERATED_PACKETS) && $(MAKE) lib)

it: lib decoder_test

decoder_test: decoder_test.o Eurobalise_Telegram.o\
	Eurobalise_Header_Encoder.o Eurobalise_Header_Decoder.o\
	Eurobalise_Header_UpperBitsNotSet.o Decoder_Branch.o\
        Packet_Header_Decoder.o Packet_Header_Encoder.o\
	Packet_Header_UpperBitsNotSet.o
	$(CXX) -o $@ $+ $(LDFLAGS)


clean::
	@$(RM) decoder_test
	@(cd $(BITWALKER) && $(MAKE) clean)
	@(cd $(GENERATED_PACKETS) && $(MAKE) clean)
