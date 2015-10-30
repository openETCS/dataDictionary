
#include "Packet_DecodeBit.h"
#include "AllPackets.h"
#include <assert.h>

int Packet_DecodeBit(PacketHeader* header, Bitstream* stream)
{
    switch (header->list)
    {
        case TRAINTOTRACK :
        {
            switch (header->NID_PACKET)
            {
                case 0 :
                {
                    PositionReport_DecodeBit((PositionReport*)(header), stream);
                    return 1;
                }

                case 1 :
                {
                    PositionReportBasedOnTwoBaliseGroups_DecodeBit((PositionReportBasedOnTwoBaliseGroups*)(header), stream);
                    return 1;
                }

                case 3 :
                {
                    OnboardTelephoneNumbers_DecodeBit((OnboardTelephoneNumbers*)(header), stream);
                    return 1;
                }

                case 4 :
                {
                    ErrorReporting_DecodeBit((ErrorReporting*)(header), stream);
                    return 1;
                }

                case 9 :
                {
                    Level23TransitionInformation_DecodeBit((Level23TransitionInformation*)(header), stream);
                    return 1;
                }

                case 11 :
                {
                    ValidatedTrainData_DecodeBit((ValidatedTrainData*)(header), stream);
                    return 1;
                }

                case 44 :
                {
                    DataUsedByApplicationsOutsideTheERTMSETCSSystem_DecodeBit((DataUsedByApplicationsOutsideTheERTMSETCSSystem*)(header), stream);
                    return 1;
                }

                default :
                {
                    fprintf(stderr, "Packet_DecodeBit: unexpected value for header->NID_PACKET = %"PRIu64"\n", header->NID_PACKET);
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
                    NationalValues_DecodeBit((NationalValues*)(header), stream);
                    return 1;
                }

                case 5 :
                {
                    Linking_DecodeBit((Linking*)(header), stream);
                    return 1;
                }

                case 12 :
                {
                    Level1MovementAuthority_DecodeBit((Level1MovementAuthority*)(header), stream);
                    return 1;
                }

                case 15 :
                {
                    Level23MovementAuthority_DecodeBit((Level23MovementAuthority*)(header), stream);
                    return 1;
                }

                case 16 :
                {
                    RepositioningInformation_DecodeBit((RepositioningInformation*)(header), stream);
                    return 1;
                }

                case 21 :
                {
                    GradientProfile_DecodeBit((GradientProfile*)(header), stream);
                    return 1;
                }

                case 27 :
                {
                    InternationalStaticSpeedProfile_DecodeBit((InternationalStaticSpeedProfile*)(header), stream);
                    return 1;
                }

                case 39 :
                {
                    TrackConditionChangeOfTractionPower_DecodeBit((TrackConditionChangeOfTractionPower*)(header), stream);
                    return 1;
                }

                case 41 :
                {
                    LevelTransitionOrder_DecodeBit((LevelTransitionOrder*)(header), stream);
                    return 1;
                }

                case 42 :
                {
                    SessionManagement_DecodeBit((SessionManagement*)(header), stream);
                    return 1;
                }

                case 44 :
                {
                    DataUsedByApplicationsOutsideTheERTMSETCSSystem_DecodeBit((DataUsedByApplicationsOutsideTheERTMSETCSSystem*)(header), stream);
                    return 1;
                }

                case 45 :
                {
                    RadioNetworkRegistration_DecodeBit((RadioNetworkRegistration*)(header), stream);
                    return 1;
                }

                case 46 :
                {
                    ConditionalLevelTransitionOrder_DecodeBit((ConditionalLevelTransitionOrder*)(header), stream);
                    return 1;
                }

                case 49 :
                {
                    ListOfBalisesForSHArea_DecodeBit((ListOfBalisesForSHArea*)(header), stream);
                    return 1;
                }

                case 51 :
                {
                    AxleLoadSpeedProfile_DecodeBit((AxleLoadSpeedProfile*)(header), stream);
                    return 1;
                }

                case 57 :
                {
                    MovementAuthorityRequestParameters_DecodeBit((MovementAuthorityRequestParameters*)(header), stream);
                    return 1;
                }

                case 58 :
                {
                    PositionReportParameters_DecodeBit((PositionReportParameters*)(header), stream);
                    return 1;
                }

                case 63 :
                {
                    ListOfBalisesInSRAuthority_DecodeBit((ListOfBalisesInSRAuthority*)(header), stream);
                    return 1;
                }

                case 65 :
                {
                    TemporarySpeedRestriction_DecodeBit((TemporarySpeedRestriction*)(header), stream);
                    return 1;
                }

                case 66 :
                {
                    TemporarySpeedRestrictionRevocation_DecodeBit((TemporarySpeedRestrictionRevocation*)(header), stream);
                    return 1;
                }

                case 67 :
                {
                    TrackConditionBigMetalMasses_DecodeBit((TrackConditionBigMetalMasses*)(header), stream);
                    return 1;
                }

                case 68 :
                {
                    TrackCondition_DecodeBit((TrackCondition*)(header), stream);
                    return 1;
                }

                case 70 :
                {
                    RouteSuitabilityData_DecodeBit((RouteSuitabilityData*)(header), stream);
                    return 1;
                }

                case 71 :
                {
                    AdhesionFactor_DecodeBit((AdhesionFactor*)(header), stream);
                    return 1;
                }

                case 72 :
                {
                    PacketForSendingPlainTextMessages_DecodeBit((PacketForSendingPlainTextMessages*)(header), stream);
                    return 1;
                }

                case 76 :
                {
                    PacketForSendingFixedTextMessages_DecodeBit((PacketForSendingFixedTextMessages*)(header), stream);
                    return 1;
                }

                case 79 :
                {
                    GeographicalPositionInformation_DecodeBit((GeographicalPositionInformation*)(header), stream);
                    return 1;
                }

                case 80 :
                {
                    ModeProfile_DecodeBit((ModeProfile*)(header), stream);
                    return 1;
                }

                case 90 :
                {
                    TrackAheadFreeUpToLevel23TransitionLocation_DecodeBit((TrackAheadFreeUpToLevel23TransitionLocation*)(header), stream);
                    return 1;
                }

                case 131 :
                {
                    RBCTransitionOrder_DecodeBit((RBCTransitionOrder*)(header), stream);
                    return 1;
                }

                case 132 :
                {
                    DangerForShuntingInformation_DecodeBit((DangerForShuntingInformation*)(header), stream);
                    return 1;
                }

                case 133 :
                {
                    RadioInfillAreaInformation_DecodeBit((RadioInfillAreaInformation*)(header), stream);
                    return 1;
                }

                case 134 :
                {
                    EOLMPacket_DecodeBit((EOLMPacket*)(header), stream);
                    return 1;
                }

                case 136 :
                {
                    InfillLocationReference_DecodeBit((InfillLocationReference*)(header), stream);
                    return 1;
                }

                case 137 :
                {
                    StopIfInStaffResponsible_DecodeBit((StopIfInStaffResponsible*)(header), stream);
                    return 1;
                }

                case 138 :
                {
                    ReversingAreaInformation_DecodeBit((ReversingAreaInformation*)(header), stream);
                    return 1;
                }

                case 139 :
                {
                    ReversingSupervisionInformation_DecodeBit((ReversingSupervisionInformation*)(header), stream);
                    return 1;
                }

                case 140 :
                {
                    TrainRunningNumberFromRBC_DecodeBit((TrainRunningNumberFromRBC*)(header), stream);
                    return 1;
                }

                case 141 :
                {
                    DefaultGradientForTemporarySpeedRestriction_DecodeBit((DefaultGradientForTemporarySpeedRestriction*)(header), stream);
                    return 1;
                }

                case 254 :
                {
                    DefaultBaliseLoopOrRIUInformation_DecodeBit((DefaultBaliseLoopOrRIUInformation*)(header), stream);
                    return 1;
                }

                default :
                {
                    fprintf(stderr, "Packet_DecodeBit: unexpected value for header->NID_PACKET = %"PRIu64"\n", header->NID_PACKET);
                    return 0;
                }
            };
        }

        case BOTHWAYS :
        {
            assert(header->NID_PACKET == 255);
            EndOfInformation_DecodeBit((EndOfInformation*)header, stream);
            return 1;
        }

        default:
        {
            fprintf(stderr, "Packet_DecodeBit: unexpected value for header->list = %"PRIu64"\n", header->list);
            return 0;
        }
    };
}

