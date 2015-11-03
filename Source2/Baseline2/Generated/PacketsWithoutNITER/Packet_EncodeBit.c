
#include "Packet_EncodeBit.h"
#include "AllPackets.h"
#include <assert.h>

int Packet_EncodeBit(const PacketHeader* header, Bitstream* stream)
{
    switch (header->list)
    {
        case TRAINTOTRACK :
        {
            switch (header->NID_PACKET)
            {
                case 0 :
                {
                    PositionReport_EncodeBit((const PositionReport*)(header), stream);
                    return 1;
                }

                case 1 :
                {
                    PositionReportBasedOnTwoBaliseGroups_EncodeBit((const PositionReportBasedOnTwoBaliseGroups*)(header), stream);
                    return 1;
                }

                case 3 :
                {
                    OnboardTelephoneNumbers_EncodeBit((const OnboardTelephoneNumbers*)(header), stream);
                    return 1;
                }

                case 4 :
                {
                    ErrorReporting_EncodeBit((const ErrorReporting*)(header), stream);
                    return 1;
                }

                case 9 :
                {
                    Level23TransitionInformation_EncodeBit((const Level23TransitionInformation*)(header), stream);
                    return 1;
                }

                case 11 :
                {
                    ValidatedTrainData_EncodeBit((const ValidatedTrainData*)(header), stream);
                    return 1;
                }

                case 44 :
                {
                    DataUsedByApplicationsOutsideTheERTMSETCSSystem_EncodeBit((const DataUsedByApplicationsOutsideTheERTMSETCSSystem*)(header), stream);
                    return 1;
                }

                default :
                {
                    fprintf(stderr, "Packet_EncodeBit: unexpected value for header->NID_PACKET = %lu\n", header->NID_PACKET);
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
                    NationalValues_EncodeBit((const NationalValues*)(header), stream);
                    return 1;
                }

                case 5 :
                {
                    Linking_EncodeBit((const Linking*)(header), stream);
                    return 1;
                }

                case 12 :
                {
                    Level1MovementAuthority_EncodeBit((const Level1MovementAuthority*)(header), stream);
                    return 1;
                }

                case 15 :
                {
                    Level23MovementAuthority_EncodeBit((const Level23MovementAuthority*)(header), stream);
                    return 1;
                }

                case 16 :
                {
                    RepositioningInformation_EncodeBit((const RepositioningInformation*)(header), stream);
                    return 1;
                }

                case 21 :
                {
                    GradientProfile_EncodeBit((const GradientProfile*)(header), stream);
                    return 1;
                }

                case 27 :
                {
                    InternationalStaticSpeedProfile_EncodeBit((const InternationalStaticSpeedProfile*)(header), stream);
                    return 1;
                }

                case 39 :
                {
                    TrackConditionChangeOfTractionPower_EncodeBit((const TrackConditionChangeOfTractionPower*)(header), stream);
                    return 1;
                }

                case 41 :
                {
                    LevelTransitionOrder_EncodeBit((const LevelTransitionOrder*)(header), stream);
                    return 1;
                }

                case 42 :
                {
                    SessionManagement_EncodeBit((const SessionManagement*)(header), stream);
                    return 1;
                }

                case 44 :
                {
                    DataUsedByApplicationsOutsideTheERTMSETCSSystem_EncodeBit((const DataUsedByApplicationsOutsideTheERTMSETCSSystem*)(header), stream);
                    return 1;
                }

                case 45 :
                {
                    RadioNetworkRegistration_EncodeBit((const RadioNetworkRegistration*)(header), stream);
                    return 1;
                }

                case 46 :
                {
                    ConditionalLevelTransitionOrder_EncodeBit((const ConditionalLevelTransitionOrder*)(header), stream);
                    return 1;
                }

                case 49 :
                {
                    ListOfBalisesForSHArea_EncodeBit((const ListOfBalisesForSHArea*)(header), stream);
                    return 1;
                }

                case 51 :
                {
                    AxleLoadSpeedProfile_EncodeBit((const AxleLoadSpeedProfile*)(header), stream);
                    return 1;
                }

                case 57 :
                {
                    MovementAuthorityRequestParameters_EncodeBit((const MovementAuthorityRequestParameters*)(header), stream);
                    return 1;
                }

                case 58 :
                {
                    PositionReportParameters_EncodeBit((const PositionReportParameters*)(header), stream);
                    return 1;
                }

                case 63 :
                {
                    ListOfBalisesInSRAuthority_EncodeBit((const ListOfBalisesInSRAuthority*)(header), stream);
                    return 1;
                }

                case 65 :
                {
                    TemporarySpeedRestriction_EncodeBit((const TemporarySpeedRestriction*)(header), stream);
                    return 1;
                }

                case 66 :
                {
                    TemporarySpeedRestrictionRevocation_EncodeBit((const TemporarySpeedRestrictionRevocation*)(header), stream);
                    return 1;
                }

                case 67 :
                {
                    TrackConditionBigMetalMasses_EncodeBit((const TrackConditionBigMetalMasses*)(header), stream);
                    return 1;
                }

                case 68 :
                {
                    TrackCondition_EncodeBit((const TrackCondition*)(header), stream);
                    return 1;
                }

                case 70 :
                {
                    RouteSuitabilityData_EncodeBit((const RouteSuitabilityData*)(header), stream);
                    return 1;
                }

                case 71 :
                {
                    AdhesionFactor_EncodeBit((const AdhesionFactor*)(header), stream);
                    return 1;
                }

                case 72 :
                {
                    PacketForSendingPlainTextMessages_EncodeBit((const PacketForSendingPlainTextMessages*)(header), stream);
                    return 1;
                }

                case 76 :
                {
                    PacketForSendingFixedTextMessages_EncodeBit((const PacketForSendingFixedTextMessages*)(header), stream);
                    return 1;
                }

                case 79 :
                {
                    GeographicalPositionInformation_EncodeBit((const GeographicalPositionInformation*)(header), stream);
                    return 1;
                }

                case 80 :
                {
                    ModeProfile_EncodeBit((const ModeProfile*)(header), stream);
                    return 1;
                }

                case 90 :
                {
                    TrackAheadFreeUpToLevel23TransitionLocation_EncodeBit((const TrackAheadFreeUpToLevel23TransitionLocation*)(header), stream);
                    return 1;
                }

                case 131 :
                {
                    RBCTransitionOrder_EncodeBit((const RBCTransitionOrder*)(header), stream);
                    return 1;
                }

                case 132 :
                {
                    DangerForShuntingInformation_EncodeBit((const DangerForShuntingInformation*)(header), stream);
                    return 1;
                }

                case 133 :
                {
                    RadioInfillAreaInformation_EncodeBit((const RadioInfillAreaInformation*)(header), stream);
                    return 1;
                }

                case 134 :
                {
                    EOLMPacket_EncodeBit((const EOLMPacket*)(header), stream);
                    return 1;
                }

                case 136 :
                {
                    InfillLocationReference_EncodeBit((const InfillLocationReference*)(header), stream);
                    return 1;
                }

                case 137 :
                {
                    StopIfInStaffResponsible_EncodeBit((const StopIfInStaffResponsible*)(header), stream);
                    return 1;
                }

                case 138 :
                {
                    ReversingAreaInformation_EncodeBit((const ReversingAreaInformation*)(header), stream);
                    return 1;
                }

                case 139 :
                {
                    ReversingSupervisionInformation_EncodeBit((const ReversingSupervisionInformation*)(header), stream);
                    return 1;
                }

                case 140 :
                {
                    TrainRunningNumberFromRBC_EncodeBit((const TrainRunningNumberFromRBC*)(header), stream);
                    return 1;
                }

                case 141 :
                {
                    DefaultGradientForTemporarySpeedRestriction_EncodeBit((const DefaultGradientForTemporarySpeedRestriction*)(header), stream);
                    return 1;
                }

                case 254 :
                {
                    DefaultBaliseLoopOrRIUInformation_EncodeBit((const DefaultBaliseLoopOrRIUInformation*)(header), stream);
                    return 1;
                }

                default :
                {
                    fprintf(stderr, "Packet_EncodeBit: unexpected value for header->NID_PACKET = %lu\n", header->NID_PACKET);
                    return 0;
                }
            };
        }

        case BOTHWAYS :
        {
            assert(header->NID_PACKET == 255);
            EndOfInformation_EncodeBit((const EndOfInformation*)header, stream);
            return 1;
        }

        default:
        {
            fprintf(stderr, "Packet_EncodeBit: unexpected value for header->list = %lu\n", header->list);
            return 0;
        }
    };
}

