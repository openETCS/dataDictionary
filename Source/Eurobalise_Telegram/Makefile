
MAKEFLAGS += --no-print-directory --silent

TOPDIR=..
export BITWALKER=$(TOPDIR)/Bitwalker
export GENERATED_PACKETS=$(TOPDIR)/Generated_Packets
export PACKET_HEADER=$(TOPDIR)/Packet_Header
export TELEGRAM_HEADER=$(TOPDIR)/Telegram_Header

#VPATH = Packet_Header

it: lib decoder_test encoder_test

include $(TOPDIR)/Makefile.template

#CXX = c++
CPPFLAGS += -I.

CPPFLAGS += -I$(GENERATED_PACKETS)
LDFLAGS += -L$(GENERATED_PACKETS) -lsubset_structs

CPPFLAGS += -I$(PACKET_HEADER)
LDFLAGS += -L$(PACKET_HEADER) -lpacket_header

CPPFLAGS += -I$(TELEGRAM_HEADER)
LDFLAGS += -L$(TELEGRAM_HEADER) -ltelegram_header

CPPFLAGS += -I$(BITWALKER)
LDFLAGS += -L$(BITWALKER) -lBitwalker

test: it
	./encoder_test
	./decoder_test

lib:
	@(cd $(BITWALKER) && $(MAKE) lib)
	@(cd $(GENERATED_PACKETS) && $(MAKE) lib)
	@(cd $(PACKET_HEADER) && $(MAKE) lib)
	@(cd $(TELEGRAM_HEADER) && $(MAKE) lib)

SRC=Eurobalise_Telegram.cpp Decoder_Branch.cpp Encoder_Branch.cpp\
    create.cpp

OBJ := $(SRC:.cpp=.o)

decoder_test: decoder_test.o $(OBJ)
	$(CXX) -o $@ $+ $(LDFLAGS)

encoder_test: encoder_test.o $(OBJ)
	$(CXX) -o $@ $+ $(LDFLAGS)

FORMAT := $(wildcard *.h) $(wildcard *.cpp)

format: FORCE
	$(ASTYLE) $(FORMAT)

clean::
	@$(RM) decoder_test
	@$(RM) encoder_test
	@(cd $(BITWALKER) && $(MAKE) clean)
	@(cd $(GENERATED_PACKETS) && $(MAKE) clean)
	@(cd $(PACKET_HEADER) && $(MAKE) clean)
	@(cd $(TELEGRAM_HEADER) && $(MAKE) clean)
