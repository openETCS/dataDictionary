
#include "Packet_Equal.h"
#include "AllPackets.h"
#include <assert.h>

int Packet_Equal(const PacketHeader* a, const PacketHeader* b)
{
    switch (a->list)
    {
        case TRAINTOTRACK :
        {
            switch (a->NID_PACKET)
            {
                case 0 :
                {
                    return PositionReport_Equal((const PositionReport*)(a), (const PositionReport*)(b));
                }

                case 1 :
                {
                    return PositionReportBasedOnTwoBaliseGroups_Equal((const PositionReportBasedOnTwoBaliseGroups*)(a), (const PositionReportBasedOnTwoBaliseGroups*)(b));
                }

                case 3 :
                {
                    return OnboardTelephoneNumbers_Equal((const OnboardTelephoneNumbers*)(a), (const OnboardTelephoneNumbers*)(b));
                }

                case 4 :
                {
                    return ErrorReporting_Equal((const ErrorReporting*)(a), (const ErrorReporting*)(b));
                }

                case 9 :
                {
                    return Level23TransitionInformation_Equal((const Level23TransitionInformation*)(a), (const Level23TransitionInformation*)(b));
                }

                case 11 :
                {
                    return ValidatedTrainData_Equal((const ValidatedTrainData*)(a), (const ValidatedTrainData*)(b));
                }

                case 44 :
                {
                    return DataUsedByApplicationsOutsideTheERTMSETCSSystem_Equal((const DataUsedByApplicationsOutsideTheERTMSETCSSystem*)(a), (const DataUsedByApplicationsOutsideTheERTMSETCSSystem*)(b));
                }

                default :
                {
                    fprintf(stderr, "Packet_Equal: unexpected value for a->NID_PACKET = %lu\n", a->NID_PACKET);
                    return 0;
                }
            };
        }

        case TRACKTOTRAIN :
        {
            switch (a->NID_PACKET)
            {
                case 3 :
                {
                    return NationalValues_Equal((const NationalValues*)(a), (const NationalValues*)(b));
                }

                case 5 :
                {
                    return Linking_Equal((const Linking*)(a), (const Linking*)(b));
                }

                case 12 :
                {
                    return Level1MovementAuthority_Equal((const Level1MovementAuthority*)(a), (const Level1MovementAuthority*)(b));
                }

                case 15 :
                {
                    return Level23MovementAuthority_Equal((const Level23MovementAuthority*)(a), (const Level23MovementAuthority*)(b));
                }

                case 16 :
                {
                    return RepositioningInformation_Equal((const RepositioningInformation*)(a), (const RepositioningInformation*)(b));
                }

                case 21 :
                {
                    return GradientProfile_Equal((const GradientProfile*)(a), (const GradientProfile*)(b));
                }

                case 27 :
                {
                    return InternationalStaticSpeedProfile_Equal((const InternationalStaticSpeedProfile*)(a), (const InternationalStaticSpeedProfile*)(b));
                }

                case 39 :
                {
                    return TrackConditionChangeOfTractionPower_Equal((const TrackConditionChangeOfTractionPower*)(a), (const TrackConditionChangeOfTractionPower*)(b));
                }

                case 41 :
                {
                    return LevelTransitionOrder_Equal((const LevelTransitionOrder*)(a), (const LevelTransitionOrder*)(b));
                }

                case 42 :
                {
                    return SessionManagement_Equal((const SessionManagement*)(a), (const SessionManagement*)(b));
                }

                case 44 :
                {
                    return DataUsedByApplicationsOutsideTheERTMSETCSSystem_Equal((const DataUsedByApplicationsOutsideTheERTMSETCSSystem*)(a), (const DataUsedByApplicationsOutsideTheERTMSETCSSystem*)(b));
                }

                case 45 :
                {
                    return RadioNetworkRegistration_Equal((const RadioNetworkRegistration*)(a), (const RadioNetworkRegistration*)(b));
                }

                case 46 :
                {
                    return ConditionalLevelTransitionOrder_Equal((const ConditionalLevelTransitionOrder*)(a), (const ConditionalLevelTransitionOrder*)(b));
                }

                case 49 :
                {
                    return ListOfBalisesForSHArea_Equal((const ListOfBalisesForSHArea*)(a), (const ListOfBalisesForSHArea*)(b));
                }

                case 51 :
                {
                    return AxleLoadSpeedProfile_Equal((const AxleLoadSpeedProfile*)(a), (const AxleLoadSpeedProfile*)(b));
                }

                case 57 :
                {
                    return MovementAuthorityRequestParameters_Equal((const MovementAuthorityRequestParameters*)(a), (const MovementAuthorityRequestParameters*)(b));
                }

                case 58 :
                {
                    return PositionReportParameters_Equal((const PositionReportParameters*)(a), (const PositionReportParameters*)(b));
                }

                case 63 :
                {
                    return ListOfBalisesInSRAuthority_Equal((const ListOfBalisesInSRAuthority*)(a), (const ListOfBalisesInSRAuthority*)(b));
                }

                case 65 :
                {
                    return TemporarySpeedRestriction_Equal((const TemporarySpeedRestriction*)(a), (const TemporarySpeedRestriction*)(b));
                }

                case 66 :
                {
                    return TemporarySpeedRestrictionRevocation_Equal((const TemporarySpeedRestrictionRevocation*)(a), (const TemporarySpeedRestrictionRevocation*)(b));
                }

                case 67 :
                {
                    return TrackConditionBigMetalMasses_Equal((const TrackConditionBigMetalMasses*)(a), (const TrackConditionBigMetalMasses*)(b));
                }

                case 68 :
                {
                    return TrackCondition_Equal((const TrackCondition*)(a), (const TrackCondition*)(b));
                }

                case 70 :
                {
                    return RouteSuitabilityData_Equal((const RouteSuitabilityData*)(a), (const RouteSuitabilityData*)(b));
                }

                case 71 :
                {
                    return AdhesionFactor_Equal((const AdhesionFactor*)(a), (const AdhesionFactor*)(b));
                }

                case 72 :
                {
                    return PacketForSendingPlainTextMessages_Equal((const PacketForSendingPlainTextMessages*)(a), (const PacketForSendingPlainTextMessages*)(b));
                }

                case 76 :
                {
                    return PacketForSendingFixedTextMessages_Equal((const PacketForSendingFixedTextMessages*)(a), (const PacketForSendingFixedTextMessages*)(b));
                }

                case 79 :
                {
                    return GeographicalPositionInformation_Equal((const GeographicalPositionInformation*)(a), (const GeographicalPositionInformation*)(b));
                }

                case 80 :
                {
                    return ModeProfile_Equal((const ModeProfile*)(a), (const ModeProfile*)(b));
                }

                case 90 :
                {
                    return TrackAheadFreeUpToLevel23TransitionLocation_Equal((const TrackAheadFreeUpToLevel23TransitionLocation*)(a), (const TrackAheadFreeUpToLevel23TransitionLocation*)(b));
                }

                case 131 :
                {
                    return RBCTransitionOrder_Equal((const RBCTransitionOrder*)(a), (const RBCTransitionOrder*)(b));
                }

                case 132 :
                {
                    return DangerForShuntingInformation_Equal((const DangerForShuntingInformation*)(a), (const DangerForShuntingInformation*)(b));
                }

                case 133 :
                {
                    return RadioInfillAreaInformation_Equal((const RadioInfillAreaInformation*)(a), (const RadioInfillAreaInformation*)(b));
                }

                case 134 :
                {
                    return EOLMPacket_Equal((const EOLMPacket*)(a), (const EOLMPacket*)(b));
                }

                case 136 :
                {
                    return InfillLocationReference_Equal((const InfillLocationReference*)(a), (const InfillLocationReference*)(b));
                }

                case 137 :
                {
                    return StopIfInStaffResponsible_Equal((const StopIfInStaffResponsible*)(a), (const StopIfInStaffResponsible*)(b));
                }

                case 138 :
                {
                    return ReversingAreaInformation_Equal((const ReversingAreaInformation*)(a), (const ReversingAreaInformation*)(b));
                }

                case 139 :
                {
                    return ReversingSupervisionInformation_Equal((const ReversingSupervisionInformation*)(a), (const ReversingSupervisionInformation*)(b));
                }

                case 140 :
                {
                    return TrainRunningNumberFromRBC_Equal((const TrainRunningNumberFromRBC*)(a), (const TrainRunningNumberFromRBC*)(b));
                }

                case 141 :
                {
                    return DefaultGradientForTemporarySpeedRestriction_Equal((const DefaultGradientForTemporarySpeedRestriction*)(a), (const DefaultGradientForTemporarySpeedRestriction*)(b));
                }

                case 254 :
                {
                    return DefaultBaliseLoopOrRIUInformation_Equal((const DefaultBaliseLoopOrRIUInformation*)(a), (const DefaultBaliseLoopOrRIUInformation*)(b));
                }

                default :
                {
                    fprintf(stderr, "Packet_Equal: unexpected value for a->NID_PACKET = %lu\n", a->NID_PACKET);
                    return 0;
                }
            };
        }

        case BOTHWAYS :
        {
            assert(a->NID_PACKET == 255);
            return EndOfInformation_Equal((const EndOfInformation*)(a), (const EndOfInformation*)b);
        }

        default:
        {
            fprintf(stderr, "Packet_Equal: unexpected value for a->list = %lu\n", a->list);
            return 0;
        }
    };
}

