
MAKEFLAGS += --no-print-directory --silent

TOPDIR=..
export BITS=$(TOPDIR)/Foundation/Bits
export BASE_PACKETS=$(TOPDIR)/Foundation/Packets
export GENERATED_PACKETS=$(TOPDIR)/Generated/Packets
export GENERATED_MESSAGES=$(TOPDIR)/Generated/Messages
export MESSAGE_TELEGRAM=$(TOPDIR)/Message_Telegram

test: general issue31

include $(TOPDIR)/Makefile.template

lib:	$(GENERATED_MESSAGES)/libgenerated_messages.a\
	$(MESSAGE_TELEGRAM)/libmessage_telegram.a\
	$(BITS)/libbits.a

CXXFLAGS += -std=c++11

CPPFLAGS += -I.

CPPFLAGS += -I$(MESSAGE_TELEGRAM)
LDFLAGS += -L$(MESSAGE_TELEGRAM) -lmessage_telegram

CPPFLAGS += -I$(GENERATED_MESSAGES)
LDFLAGS += -L$(GENERATED_MESSAGES) -lgenerated_messages

CPPFLAGS += -I$(GENERATED_PACKETS)
LDFLAGS += -L$(GENERATED_PACKETS) -lgenerated_packets

CPPFLAGS += -I$(BASE_PACKETS)

CPPFLAGS += -I$(BITS)
LDFLAGS += -L$(BITS) -lbits

LDFLAGS += -L$(MESSAGE_TELEGRAM) -lmessage_telegram

general:	lib\
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

decoder_test: decoder_test.o create.o
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -o $@ $+ $(LDFLAGS)
	$(RM) $<

encoder_test: encoder_test.o create.o
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -o $@ $+ $(LDFLAGS)

conditional_decoder_test: conditional_decoder_test.o create.o
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -o $@ $+ $(LDFLAGS)

conditional_encoder_test: conditional_encoder_test.o create.o
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -o $@ $+ $(LDFLAGS)

test_issue31_1: test_issue31_1.o create.o
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -o $@ $+ $(LDFLAGS)

test_issue31_2: test_issue31_2.o create.o
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -o $@ $+ $(LDFLAGS)

test_issue31_3: test_issue31_3.o create.o
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -o $@ $+ $(LDFLAGS)

test_messages: test_messages.o create.o
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -o $@ $+ $(LDFLAGS)


FORMAT := $(wildcard *.h) $(wildcard *.cpp) $(wildcard *.c)

format: FORCE
	$(ASTYLE) $(FORMAT)

clean::
	@$(RM) *.o
	@$(RM) *.a
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

