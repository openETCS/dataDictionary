
MAKEFLAGS += --no-print-directory --silent

TOPDIR=../..

it: lib

include $(TOPDIR)/Makefile.template
export BITS=$(TOPDIR)/Foundation/Bits
export PACKETS_BASE=$(TOPDIR)/Foundation/Packets

CPPFLAGS += -I.

CPPFLAGS += -I$(BITS)
CPPFLAGS += -I$(PACKETS_BASE)
CPPFLAGS += -I../PacketsWithNITER

LDFLAGS += -L$(BITS) -lbits
LDFLAGS += -L../PacketsWithNITER -lgenerated_packetswithniter

SRC :=  $(wildcard *.c)

OBJ := $(SRC:.c=.o)

lib: libgenerated_packetswithoutniter.a

libgenerated_packetswithoutniter.a : $(OBJ)
	ar cru  $@ $^
	ranlib  $@

clean::
	$(RM) libgenerated_packetswithoutniter.a
	$(RM) *.o

format: FORCE
	@$(ASTYLE) *.c *.cpp *.h


report: AdhesionFactor.report\
	DangerForShuntingInformation.report\
	DataUsedByApplicationsOutsideTheERTMSETCSSystem.report\
	DefaultBaliseLoopOrRIUInformation.report\
	DefaultGradientForTemporarySpeedRestriction.report\
	EOLMPacket.report\
	EndOfInformation.report\
	ErrorReporting.report\
	InfillLocationReference.report\
	Level23TransitionInformation.report\
	MovementAuthorityRequestParameters.report\
	PacketForSendingFixedTextMessages.report\
	PacketForSendingPlainTextMessages.report\
	PositionReport.report\
	PositionReportBasedOnTwoBaliseGroups.report\
	RBCTransitionOrder.report\
	RadioInfillAreaInformation.report\
	RadioNetworkRegistration.report\
	RepositioningInformation.report\
	ReversingAreaInformation.report\
	ReversingSupervisionInformation.report\
	SessionManagement.report\
	StopIfInStaffResponsible.report\
	TemporarySpeedRestriction.report\
	TemporarySpeedRestrictionRevocation.report\
	TrackAheadFreeUpToLevel23TransitionLocation.report\
	TrackConditionChangeOfTractionPower.report\
	TrainRunningNumberFromRBC.report
