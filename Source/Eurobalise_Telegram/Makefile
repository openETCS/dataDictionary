
MAKEFLAGS += --no-print-directory --silent

TOPDIR=..
export BITWALKER=$(TOPDIR)/Bitwalker
export GENERATED_PACKETS=$(TOPDIR)/Generated_Packets
export GENERATED_MESSAGES=$(TOPDIR)/Generated_Messages


it:	lib\
	decoder_test encoder_test\
	conditional_encoder_test conditional_decoder_test\
	test_issue31_1 test_issue31_2\
	test_issue31_3 test_messages

include $(TOPDIR)/Makefile.template

#CXX = c++
CPPFLAGS += -I.

CXXFLAGS += -std=c++11

CPPFLAGS += -I$(GENERATED_MESSAGES)
LDFLAGS += -L$(GENERATED_MESSAGES) -lgenerated_messages

CPPFLAGS += -I$(GENERATED_PACKETS)
LDFLAGS += -L$(GENERATED_PACKETS) -lgenerated_packets

CPPFLAGS += -I$(BITWALKER)
LDFLAGS += -L$(BITWALKER) -lBitwalker

test: it issue31
	./encoder_test
	./decoder_test
	./conditional_encoder_test
	./conditional_decoder_test
	./test_messages

issue31: lib test_issue31_1 test_issue31_2 test_issue31_3
	./test_issue31_1
	./test_issue31_2
	./test_issue31_3
	./test_messages


lib:
	@(cd $(BITWALKER) && $(MAKE) lib)
	@(cd $(GENERATED_PACKETS) && $(MAKE) lib)
	@(cd $(GENERATED_MESSAGES) && $(MAKE) lib)


SRC= print_bits.cpp Eurobalise_Telegram.cpp create.cpp\
     Euroradio_Message.cpp Message_Header.cpp


OBJ := $(SRC:.cpp=.o)

OBJ += Packet_Header.o\
	Telegram_Header_Decoder.o\
	Telegram_Header_UpperBitsNotSet.o\
	Telegram_Header_Encoder.o

print_bits: print_bits.o
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -o $@ $+

bits: print_bits
	./print_bits
	

decoder_test: decoder_test.o $(OBJ)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -o $@ $+ $(LDFLAGS)

encoder_test: encoder_test.o $(OBJ)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -o $@ $+ $(LDFLAGS)

conditional_decoder_test: conditional_decoder_test.o $(OBJ)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -o $@ $+ $(LDFLAGS)

conditional_encoder_test: conditional_encoder_test.o $(OBJ)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -o $@ $+ $(LDFLAGS)

test_issue31_1: test_issue31_1.o $(OBJ) 
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -o $@ $+ $(LDFLAGS)

test_issue31_2: test_issue31_2.o $(OBJ) 
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -o $@ $+ $(LDFLAGS)

test_issue31_3: test_issue31_3.o $(OBJ)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -o $@ $+ $(LDFLAGS)

test_messages: test_messages.o $(OBJ)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -o $@ $+ $(LDFLAGS)


FORMAT := $(wildcard *.h) $(wildcard *.cpp) $(wildcard *.c)

format: FORCE
	$(ASTYLE) $(FORMAT)

clean::
	@$(RM) print_bits
	@$(RM) decoder_test
	@$(RM) encoder_test
	@$(RM) conditional_decoder_test
	@$(RM) conditional_encoder_test
	@$(RM) test_issue31_1
	@$(RM) test_issue31_2
	@$(RM) test_issue31_3
	@$(RM) dynamic_decoder_test
	@$(RM) dynamic_encoder_test
	@(cd $(BITWALKER) && $(MAKE) clean)
	@(cd $(GENERATED_PACKETS) && $(MAKE) clean)
	@(cd $(GENERATED_MESSAGES) && $(MAKE) clean)

