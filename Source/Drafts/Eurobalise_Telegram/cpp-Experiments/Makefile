
MAKEFLAGS += --no-print-directory --silent

TOPDIR=../../..
export BITWALKER=$(TOPDIR)/Bitwalker
export GENERATED_PACKETS=Subset_Structs
export PACKET_HEADER=Packet_Header
export TELEGRAM_HEADER=Eurobalise_Header

#VPATH = Packet_Header

it: lib decoder_test

include $(TOPDIR)/Makefile.template

#CXX = c++
CPPFLAGS += -I.

CPPFLAGS += -I$(BITWALKER)
LDFLAGS += -L$(BITWALKER) -lBitwalker

CPPFLAGS += -I$(GENERATED_PACKETS)
LDFLAGS += -L$(GENERATED_PACKETS) -lsubset_structs

CPPFLAGS += -I$(PACKET_HEADER)
LDFLAGS += -L$(PACKET_HEADER) -lpacket_header

CPPFLAGS += -I$(TELEGRAM_HEADER)
LDFLAGS += -L$(TELEGRAM_HEADER) -ltelegram_header

lib:
	@(cd $(BITWALKER) && $(MAKE) lib)
	@(cd $(GENERATED_PACKETS) && $(MAKE) lib)
	@(cd $(PACKET_HEADER) && $(MAKE) lib)
	@(cd $(TELEGRAM_HEADER) && $(MAKE) lib)

decoder_test: decoder_test.o Eurobalise_Telegram.o\
		Decoder_Branch.o Encoder_Branch.o
	$(CXX) -o $@ $+ $(LDFLAGS)


clean::
	@$(RM) decoder_test
	@(cd $(BITWALKER) && $(MAKE) clean)
	@(cd $(GENERATED_PACKETS) && $(MAKE) clean)
	@(cd $(PACKET_HEADER) && $(MAKE) clean)
	@(cd $(TELEGRAM_HEADER) && $(MAKE) clean)
