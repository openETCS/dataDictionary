
MAKEFLAGS += --no-print-directory --silent

TOPDIR=..
export BITWALKER=$(TOPDIR)/Bitwalker
export GENERATED_PACKETS=$(TOPDIR)/Generated_Packets
export GENERATED_MESSAGES=$(TOPDIR)/Generated_Messages

it: libmessage_telegram.a

include $(TOPDIR)/Makefile.template

lib:	libmessage_telegram.a\
	$(GENERATED_MESSAGES)/libgenerated_messages.a\
	$(GENERATED_PACKETS)/libgenerated_packets.a\
	$(BITWALKER)/libBitwalker.a

#CXX = c++
CXXFLAGS += -std=c++11

CPPFLAGS += -I.
LDFLAGS += -L. -lmessage_telegram

CPPFLAGS += -I$(GENERATED_MESSAGES)
LDFLAGS += -L$(GENERATED_MESSAGES) -lgenerated_messages

CPPFLAGS += -I$(GENERATED_PACKETS)
LDFLAGS += -L$(GENERATED_PACKETS) -lgenerated_packets

CPPFLAGS += -I$(BITWALKER)
LDFLAGS += -L$(BITWALKER) -lBitwalker

LDFLAGS += -L. -lmessage_telegram

SRC= print_bits.cpp Eurobalise_Telegram.cpp\
     Euroradio_Message.cpp Message_Header.cpp


OBJ := $(SRC:.cpp=.o)

OBJ += Packet_Header.o Telegram_Header.o


libmessage_telegram.a : $(OBJ)
	ar cru  $@ $^
	ranlib  $@
	$(RM) $(OBJ)

print_bits: print_bits.o
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -o $@ $<
	$(RM) $<

bits: print_bits
	./print_bits


FORMAT := $(wildcard *.h) $(wildcard *.cpp) $(wildcard *.c)

format: FORCE
	$(ASTYLE) $(FORMAT)

clean::
	@$(RM) *.o
	@$(RM) *.a
	@$(RM) print_bits
	@$(RM) decoder_test
	@$(RM) encoder_test
	@$(RM) conditional_decoder_test
	@$(RM) conditional_encoder_test
	@$(RM) dynamic_decoder_test
	@$(RM) dynamic_encoder_test
	@$(RM) test_issue31_1
	@$(RM) test_issue31_2
	@$(RM) test_issue31_3
	@$(RM) test_messages

