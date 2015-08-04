
MAKEFLAGS += --no-print-directory --silent

TOPDIR=..
export BITWALKER=$(TOPDIR)/Bitwalker
export GENERATED_PACKETS=$(TOPDIR)/Generated_Packets
export PACKET_HEADER=$(TOPDIR)/Packet_Header
export TELEGRAM_HEADER=$(TOPDIR)/Telegram_Header

#VPATH = Packet_Header

it: lib test_issue31_3 test_messages

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
	./test_issue31_3
	./test_messages

issue31: lib test_issue31_3
	./test_issue31_3

lib:
	@(cd $(BITWALKER) && $(MAKE) lib)
	@(cd $(GENERATED_PACKETS) && $(MAKE) lib)
	@(cd $(PACKET_HEADER) && $(MAKE) lib)
	@(cd $(TELEGRAM_HEADER) && $(MAKE) lib)

SRC=Validated_Train_Data_Message.cpp MA_Request_Message.cpp Euroradio_Message.cpp

OBJ := $(SRC:.cpp=.o)

test_issue31_3: test_issue31_3.o $(OBJ)
	$(CXX) -o $@ $+ $(LDFLAGS)

test_messages: test_messages.o $(OBJ)
	$(CXX) -o $@ $+ $(LDFLAGS)

FORMAT := $(wildcard *.h) $(wildcard *.cpp)

format: FORCE
	$(ASTYLE) $(FORMAT)

clean::
	@$(RM) test_issue31_3
	@$(RM) test_messages
	@(cd $(BITWALKER) && $(MAKE) clean)
	@(cd $(GENERATED_PACKETS) && $(MAKE) clean)
	@(cd $(PACKET_HEADER) && $(MAKE) clean)
	@(cd $(TELEGRAM_HEADER) && $(MAKE) clean)

