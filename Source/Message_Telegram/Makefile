
MAKEFLAGS += --no-print-directory --silent

TOPDIR=..
export BITWALKER=$(TOPDIR)/Bitwalker
export GENERATED_PACKETS=$(TOPDIR)/Generated_Packets
export GENERATED_MESSAGES=$(TOPDIR)/Generated_Messages

it: test issue31

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

test:	lib\
	decoder_test encoder_test\
	conditional_encoder_test conditional_decoder_test\
	test_messages
	./encoder_test
	./decoder_test
	./conditional_encoder_test
	./conditional_decoder_test
	./test_messages

issue31: lib test_issue31_1 test_issue31_2 test_issue31_3
	./test_issue31_1
	./test_issue31_2
	./test_issue31_3

SRC= print_bits.cpp Eurobalise_Telegram.cpp create.cpp\
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

decoder_test: decoder_test.o
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -o $@ $< $(LDFLAGS)
	$(RM) $<

encoder_test: encoder_test.o
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -o $@ $< $(LDFLAGS)
	$(RM) $<

conditional_decoder_test: conditional_decoder_test.o
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -o $@ $< $(LDFLAGS)
	$(RM) $<

conditional_encoder_test: conditional_encoder_test.o
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -o $@ $< $(LDFLAGS)
	$(RM) $<

test_issue31_1: test_issue31_1.o
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -o $@ $< $(LDFLAGS)
	$(RM) $<

test_issue31_2: test_issue31_2.o
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -o $@ $< $(LDFLAGS)
	$(RM) $<

test_issue31_3: test_issue31_3.o
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -o $@ $< $(LDFLAGS)
	$(RM) $<

test_messages: test_messages.o
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -o $@ $< $(LDFLAGS)
	$(RM) $<


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

