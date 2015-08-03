
MAKEFLAGS += --no-print-directory --silent

TOPDIR=..
export BITWALKER=$(TOPDIR)/Bitwalker
export GENERATED_PACKETS=$(TOPDIR)/Generated_Packets
export PACKET_HEADER=$(TOPDIR)/Packet_Header
export TELEGRAM_HEADER=$(TOPDIR)/Telegram_Header

#VPATH = Packet_Header

it: lib decoder_test encoder_test conditional_encoder_test conditional_decoder_test test_issue31_1 test_issue31_2

include $(TOPDIR)/Makefile.template

#CXX = c++
CPPFLAGS += -I.

CPPFLAGS += -I$(GENERATED_PACKETS)
LDFLAGS += -L$(GENERATED_PACKETS) -lgenerated_packets

CPPFLAGS += -I$(PACKET_HEADER)
LDFLAGS += -L$(PACKET_HEADER) -lpacket_header

CPPFLAGS += -I$(TELEGRAM_HEADER)
LDFLAGS += -L$(TELEGRAM_HEADER) -ltelegram_header

CPPFLAGS += -I$(BITWALKER)
LDFLAGS += -L$(BITWALKER) -lBitwalker

test: it
	./encoder_test
	./decoder_test
	./conditional_encoder_test
	./conditional_decoder_test
	./test_issue31_1
	./test_issue31_2

issue31: lib test_issue31_1 test_issue31_2
	./test_issue31_1
	./test_issue31_2
	

lib:
	@(cd $(BITWALKER) && $(MAKE) lib)
	@(cd $(GENERATED_PACKETS) && $(MAKE) lib)
	@(cd $(PACKET_HEADER) && $(MAKE) lib)
	@(cd $(TELEGRAM_HEADER) && $(MAKE) lib)

SRC= print_bits.cpp Eurobalise_Telegram.cpp create.cpp

OBJ := $(SRC:.cpp=.o)

decoder_test: decoder_test.o $(OBJ)
	$(CXX) -o $@ $+ $(LDFLAGS)

encoder_test: encoder_test.o $(OBJ)
	$(CXX) -o $@ $+ $(LDFLAGS)

conditional_decoder_test: conditional_decoder_test.o $(OBJ)
	$(CXX) -o $@ $+ $(LDFLAGS)

conditional_encoder_test: conditional_encoder_test.o $(OBJ)
	$(CXX) -o $@ $+ $(LDFLAGS)

test_issue31_1: test_issue31_1.o $(OBJ) 
	$(CXX) -o $@ $+ $(LDFLAGS)

test_issue31_2: test_issue31_2.o $(OBJ) 
	$(CXX) -o $@ $+ $(LDFLAGS)

print_bits: print_bits.o
	$(CXX) -o $@ $+

bits: print_bits
	./print_bits
	

FORMAT := $(wildcard *.h) $(wildcard *.cpp)

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
	@$(RM) dynamic_decoder_test
	@$(RM) dynamic_encoder_test
	@(cd $(BITWALKER) && $(MAKE) clean)
	@(cd $(GENERATED_PACKETS) && $(MAKE) clean)
	@(cd $(PACKET_HEADER) && $(MAKE) clean)
	@(cd $(TELEGRAM_HEADER) && $(MAKE) clean)

