
MAKEFLAGS += --no-print-directory --silent


CC=cc
CPPFLAGS+=-I../Baseline2/Foundation/Bits
CFLAGS += -std=c99 -Wall -pedantic
CFLAGS += -W
LDFLAGS += -L../Baseline2/Foundation/Bits -lbits

all: clean test_packets
	./test_packets

SRC := AdhesionFactor.o AdhesionFactor_Tests.c\
       ErrorReporting.o EndOfInformation.o\
       Level23TransitionInformation.o TemporarySpeedRestriction.o\
       Packet.o PacketFactory.o EurobaliseTelegram.c

OBJ := $(SRC:.c=.o)

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

