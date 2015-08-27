
CPPFLAGS = -I../Source/Bitwalker
CXXFLAGS = -Wall -std=c++11

export BITWALKER=../Source/Bitwalker
export TELEGRAM=../Source/Message_Telegram
export GENERATED_PACKETS=../Source/Generated_Packets


VPATH=$(TELEGRAM)

CPPFLAGS += -I$(TELEGRAM)

CPPFLAGS += -I$(GENERATED_PACKETS)
LDFLAGS += -L$(GENERATED_PACKETS) -lgenerated_packets


CPPFLAGS += -I$(BITWALKER)
LDFLAGS += -L$(BITWALKER) -lBitwalker


server_BTM: server_BTM.o Eurobalise_Telegram.o Telegram_Header_Encoder.o Telegram_Header_Decoder.o Packet_Header.o Telegram_Header_UpperBitsNotSet.o print_bits.o
	$(CXX) -o $@ $+ $(LDFLAGS)



clean:
	$(RM) server_BTM
	$(RM) *.o

