
MAKEFLAGS += --no-print-directory --silent


CC=cc
CPPFLAGS+=-I../Baseline2/Foundation/Bits
CFLAGS += -std=c99 -Wall -pedantic 
CFLAGS += -Weverything -Werror -Wno-padded 
LDFLAGS += -L../Baseline2/Foundation/Bits -lbits

all: clean test_packets
	./test_packets

SRC := PacketFactory.o\
       PacketSequence.c\
       EurobaliseTelegram.c

FUNCTIONS := Packet_DecodeBit.c\
             Packet_Delete.c\
             Packet_EncodeBit.c\
             Packet_Equal.c\
             Packet_Length.c\
             Packet_Print.c

PACKETS := AdhesionFactor.o\
           EndOfInformation.o\
           ErrorReporting.o\
           Level23TransitionInformation.o\
           TemporarySpeedRestriction.o

TESTS := AdhesionFactor_Tests.o\
         ErrorReporting_Tests.o\
         Level23TransitionInformation_Tests.o\
         TemporarySpeedRestriction_Tests.o\
         EndOfInformation_Tests.o\

OBJ := $(SRC:.c=.o) $(FUNCTIONS:.c=.o) $(PACKETS:.c=.o) $(TESTS:.c=.o)

test_packets: test_packets.o $(OBJ)
	$(CC) -o $@ $+ $(LDFLAGS)


clean:
	$(RM) test_packets
	$(RM) *.o
	$(RM) *.orig


ASTYLEOPTIONS += -A1
ASTYLEOPTIONS += --break-blocks
ASTYLEOPTIONS += --pad-oper
ASTYLEOPTIONS += --pad-header
ASTYLEOPTIONS += --lineend=linux
ASTYLEOPTIONS += --add-brackets
ASTYLEOPTIONS += --indent=spaces=4
ASTYLEOPTIONS += --indent-classes
ASTYLEOPTIONS += --indent-switches
ASTYLEOPTIONS += --indent-col1-comments
ASTYLEOPTIONS += --min-conditional-indent=0

export ASTYLE=astyle $(ASTYLEOPTIONS)

%.format:%.c FORCE
	@$(ASTYLE) $<

%.format:%.h FORCE
	@$(ASTYLE) $<


format: FORCE
	@$(ASTYLE) *.c *.h


FORCE:

