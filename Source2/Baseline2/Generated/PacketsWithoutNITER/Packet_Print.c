
#include "Packet_Print.h"
#include "AllPackets.h"
#include <assert.h>

int Packet_Print(const PacketHeader* header, FILE* stream)
{
    switch (header->list)
    {
        case TRAINTOTRACK :
        {
            switch (header->NID_PACKET)
            {
                case 0 :
                {
                    PositionReport_Print((const PositionReport*)(header), stream);
                    return 1;
                }

                case 1 :
                {
                    PositionReportBasedOnTwoBaliseGroups_Print((const PositionReportBasedOnTwoBaliseGroups*)(header), stream);
                    return 1;
                }

                case 3 :
                {
                    OnboardTelephoneNumbers_Print((const OnboardTelephoneNumbers*)(header), stream);
                    return 1;
                }

                case 4 :
                {
                    ErrorReporting_Print((const ErrorReporting*)(header), stream);
                    return 1;
                }

                case 9 :
                {
                    Level23TransitionInformation_Print((const Level23TransitionInformation*)(header), stream);
                    return 1;
                }

                case 11 :
                {
                    ValidatedTrainData_Print((const ValidatedTrainData*)(header), stream);
                    return 1;
                }

                case 44 :
                {
                    DataUsedByApplicationsOutsideTheERTMSETCSSystem_Print((const DataUsedByApplicationsOutsideTheERTMSETCSSystem*)(header), stream);
                    return 1;
                }

                default :
                {
                    fprintf(stderr, "Packet_Print: unexpected value for header->NID_PACKET = %lu\n", header->NID_PACKET);
                    return 0;
                }
            };
        }

        case TRACKTOTRAIN :
        {
            switch (header->NID_PACKET)
            {
                case 3 :
                {
                    NationalValues_Print((const NationalValues*)(header), stream);
                    return 1;
                }

                case 5 :
                {
                    Linking_Print((const Linking*)(header), stream);
                    return 1;
                }

                case 12 :
                {
                    Level1MovementAuthority_Print((const Level1MovementAuthority*)(header), stream);
                    return 1;
                }

                case 15 :
                {
                    Level23MovementAuthority_Print((const Level23MovementAuthority*)(header), stream);
                    return 1;
                }

                case 16 :
                {
                    RepositioningInformation_Print((const RepositioningInformation*)(header), stream);
                    return 1;
                }

                case 21 :
                {
                    GradientProfile_Print((const GradientProfile*)(header), stream);
                    return 1;
                }

                case 27 :
                {
                    InternationalStaticSpeedProfile_Print((const InternationalStaticSpeedProfile*)(header), stream);
                    return 1;
                }

                case 39 :
                {
                    TrackConditionChangeOfTractionPower_Print((const TrackConditionChangeOfTractionPower*)(header), stream);
                    return 1;
                }

                case 41 :
                {
                    LevelTransitionOrder_Print((const LevelTransitionOrder*)(header), stream);
                    return 1;
                }

                case 42 :
                {
                    SessionManagement_Print((const SessionManagement*)(header), stream);
                    return 1;
                }

                case 44 :
                {
                    DataUsedByApplicationsOutsideTheERTMSETCSSystem_Print((const DataUsedByApplicationsOutsideTheERTMSETCSSystem*)(header), stream);
                    return 1;
                }

                case 45 :
                {
                    RadioNetworkRegistration_Print((const RadioNetworkRegistration*)(header), stream);
                    return 1;
                }

                case 46 :
                {
                    ConditionalLevelTransitionOrder_Print((const ConditionalLevelTransitionOrder*)(header), stream);
                    return 1;
                }

                case 49 :
                {
                    ListOfBalisesForSHArea_Print((const ListOfBalisesForSHArea*)(header), stream);
                    return 1;
                }

                case 51 :
                {
                    AxleLoadSpeedProfile_Print((const AxleLoadSpeedProfile*)(header), stream);
                    return 1;
                }

                case 57 :
                {
                    MovementAuthorityRequestParameters_Print((const MovementAuthorityRequestParameters*)(header), stream);
                    return 1;
                }

                case 58 :
                {
                    PositionReportParameters_Print((const PositionReportParameters*)(header), stream);
                    return 1;
                }

                case 63 :
                {
                    ListOfBalisesInSRAuthority_Print((const ListOfBalisesInSRAuthority*)(header), stream);
                    return 1;
                }

                case 65 :
                {
                    TemporarySpeedRestriction_Print((const TemporarySpeedRestriction*)(header), stream);
                    return 1;
                }

                case 66 :
                {
                    TemporarySpeedRestrictionRevocation_Print((const TemporarySpeedRestrictionRevocation*)(header), stream);
                    return 1;
                }

                case 67 :
                {
                    TrackConditionBigMetalMasses_Print((const TrackConditionBigMetalMasses*)(header), stream);
                    return 1;
                }

                case 68 :
                {
                    TrackCondition_Print((const TrackCondition*)(header), stream);
                    return 1;
                }

                case 70 :
                {
                    RouteSuitabilityData_Print((const RouteSuitabilityData*)(header), stream);
                    return 1;
                }

                case 71 :
                {
                    AdhesionFactor_Print((const AdhesionFactor*)(header), stream);
                    return 1;
                }

                case 72 :
                {
                    PacketForSendingPlainTextMessages_Print((const PacketForSendingPlainTextMessages*)(header), stream);
                    return 1;
                }

                case 76 :
                {
                    PacketForSendingFixedTextMessages_Print((const PacketForSendingFixedTextMessages*)(header), stream);
                    return 1;
                }

                case 79 :
                {
                    GeographicalPositionInformation_Print((const GeographicalPositionInformation*)(header), stream);
                    return 1;
                }

                case 80 :
                {
                    ModeProfile_Print((const ModeProfile*)(header), stream);
                    return 1;
                }

                case 90 :
                {
                    TrackAheadFreeUpToLevel23TransitionLocation_Print((const TrackAheadFreeUpToLevel23TransitionLocation*)(header), stream);
                    return 1;
                }

                case 131 :
                {
                    RBCTransitionOrder_Print((const RBCTransitionOrder*)(header), stream);
                    return 1;
                }

                case 132 :
                {
                    DangerForShuntingInformation_Print((const DangerForShuntingInformation*)(header), stream);
                    return 1;
                }

                case 133 :
                {
                    RadioInfillAreaInformation_Print((const RadioInfillAreaInformation*)(header), stream);
                    return 1;
                }

                case 134 :
                {
                    EOLMPacket_Print((const EOLMPacket*)(header), stream);
                    return 1;
                }

                case 136 :
                {
                    InfillLocationReference_Print((const InfillLocationReference*)(header), stream);
                    return 1;
                }

                case 137 :
                {
                    StopIfInStaffResponsible_Print((const StopIfInStaffResponsible*)(header), stream);
                    return 1;
                }

                case 138 :
                {
                    ReversingAreaInformation_Print((const ReversingAreaInformation*)(header), stream);
                    return 1;
                }

                case 139 :
                {
                    ReversingSupervisionInformation_Print((const ReversingSupervisionInformation*)(header), stream);
                    return 1;
                }

                case 140 :
                {
                    TrainRunningNumberFromRBC_Print((const TrainRunningNumberFromRBC*)(header), stream);
                    return 1;
                }

                case 141 :
                {
                    DefaultGradientForTemporarySpeedRestriction_Print((const DefaultGradientForTemporarySpeedRestriction*)(header), stream);
                    return 1;
                }

                case 254 :
                {
                    DefaultBaliseLoopOrRIUInformation_Print((const DefaultBaliseLoopOrRIUInformation*)(header), stream);
                    return 1;
                }

                default :
                {
                    fprintf(stderr, "Packet_Print: unexpected value for header->NID_PACKET = %lu\n", header->NID_PACKET);
                    return 0;
                }
            };
        }

        case BOTHWAYS :
        {
            assert(header->NID_PACKET == 255);
            EndOfInformation_Print((const EndOfInformation*)header, stream);
            return 1;
        }

        default:
        {
            fprintf(stderr, "Packet_Print: unexpected value for header->list = %lu\n", header->list);
            return 0;
        }
    };
}

