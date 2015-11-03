
#include "Packet_DecodeInt.h"
#include "AllPackets.h"
#include <assert.h>

int Packet_DecodeInt(PacketHeader* header, const Metadata* data, const kcg_int* stream)
{
    switch (header->list)
    {
        case TRAINTOTRACK :
        {
            switch (header->NID_PACKET)
            {
                case 0 :
                {
                    PositionReport_DecodeInt((PositionReport*)(header), data, stream);
                    return 1;
                }

                case 1 :
                {
                    PositionReportBasedOnTwoBaliseGroups_DecodeInt((PositionReportBasedOnTwoBaliseGroups*)(header), data, stream);
                    return 1;
                }

                case 3 :
                {
                    OnboardTelephoneNumbers_DecodeInt((OnboardTelephoneNumbers*)(header), data, stream);
                    return 1;
                }

                case 4 :
                {
                    ErrorReporting_DecodeInt((ErrorReporting*)(header), data, stream);
                    return 1;
                }

                case 9 :
                {
                    Level23TransitionInformation_DecodeInt((Level23TransitionInformation*)(header), data, stream);
                    return 1;
                }

                case 11 :
                {
                    ValidatedTrainData_DecodeInt((ValidatedTrainData*)(header), data, stream);
                    return 1;
                }

                case 44 :
                {
                    DataUsedByApplicationsOutsideTheERTMSETCSSystem_DecodeInt((DataUsedByApplicationsOutsideTheERTMSETCSSystem*)(header), data, stream);
                    return 1;
                }

                default :
                {
                    fprintf(stderr, "Packet_DecodeInt: unexpected value for header->NID_PACKET = %lu\n", header->NID_PACKET);
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
                    NationalValues_DecodeInt((NationalValues*)(header), data, stream);
                    return 1;
                }

                case 5 :
                {
                    Linking_DecodeInt((Linking*)(header), data, stream);
                    return 1;
                }

                case 12 :
                {
                    Level1MovementAuthority_DecodeInt((Level1MovementAuthority*)(header), data, stream);
                    return 1;
                }

                case 15 :
                {
                    Level23MovementAuthority_DecodeInt((Level23MovementAuthority*)(header), data, stream);
                    return 1;
                }

                case 16 :
                {
                    RepositioningInformation_DecodeInt((RepositioningInformation*)(header), data, stream);
                    return 1;
                }

                case 21 :
                {
                    GradientProfile_DecodeInt((GradientProfile*)(header), data, stream);
                    return 1;
                }

                case 27 :
                {
                    InternationalStaticSpeedProfile_DecodeInt((InternationalStaticSpeedProfile*)(header), data, stream);
                    return 1;
                }

                case 39 :
                {
                    TrackConditionChangeOfTractionPower_DecodeInt((TrackConditionChangeOfTractionPower*)(header), data, stream);
                    return 1;
                }

                case 41 :
                {
                    LevelTransitionOrder_DecodeInt((LevelTransitionOrder*)(header), data, stream);
                    return 1;
                }

                case 42 :
                {
                    SessionManagement_DecodeInt((SessionManagement*)(header), data, stream);
                    return 1;
                }

                case 44 :
                {
                    DataUsedByApplicationsOutsideTheERTMSETCSSystem_DecodeInt((DataUsedByApplicationsOutsideTheERTMSETCSSystem*)(header), data, stream);
                    return 1;
                }

                case 45 :
                {
                    RadioNetworkRegistration_DecodeInt((RadioNetworkRegistration*)(header), data, stream);
                    return 1;
                }

                case 46 :
                {
                    ConditionalLevelTransitionOrder_DecodeInt((ConditionalLevelTransitionOrder*)(header), data, stream);
                    return 1;
                }

                case 49 :
                {
                    ListOfBalisesForSHArea_DecodeInt((ListOfBalisesForSHArea*)(header), data, stream);
                    return 1;
                }

                case 51 :
                {
                    AxleLoadSpeedProfile_DecodeInt((AxleLoadSpeedProfile*)(header), data, stream);
                    return 1;
                }

                case 57 :
                {
                    MovementAuthorityRequestParameters_DecodeInt((MovementAuthorityRequestParameters*)(header), data, stream);
                    return 1;
                }

                case 58 :
                {
                    PositionReportParameters_DecodeInt((PositionReportParameters*)(header), data, stream);
                    return 1;
                }

                case 63 :
                {
                    ListOfBalisesInSRAuthority_DecodeInt((ListOfBalisesInSRAuthority*)(header), data, stream);
                    return 1;
                }

                case 65 :
                {
                    TemporarySpeedRestriction_DecodeInt((TemporarySpeedRestriction*)(header), data, stream);
                    return 1;
                }

                case 66 :
                {
                    TemporarySpeedRestrictionRevocation_DecodeInt((TemporarySpeedRestrictionRevocation*)(header), data, stream);
                    return 1;
                }

                case 67 :
                {
                    TrackConditionBigMetalMasses_DecodeInt((TrackConditionBigMetalMasses*)(header), data, stream);
                    return 1;
                }

                case 68 :
                {
                    TrackCondition_DecodeInt((TrackCondition*)(header), data, stream);
                    return 1;
                }

                case 70 :
                {
                    RouteSuitabilityData_DecodeInt((RouteSuitabilityData*)(header), data, stream);
                    return 1;
                }

                case 71 :
                {
                    AdhesionFactor_DecodeInt((AdhesionFactor*)(header), data, stream);
                    return 1;
                }

                case 72 :
                {
                    PacketForSendingPlainTextMessages_DecodeInt((PacketForSendingPlainTextMessages*)(header), data, stream);
                    return 1;
                }

                case 76 :
                {
                    PacketForSendingFixedTextMessages_DecodeInt((PacketForSendingFixedTextMessages*)(header), data, stream);
                    return 1;
                }

                case 79 :
                {
                    GeographicalPositionInformation_DecodeInt((GeographicalPositionInformation*)(header), data, stream);
                    return 1;
                }

                case 80 :
                {
                    ModeProfile_DecodeInt((ModeProfile*)(header), data, stream);
                    return 1;
                }

                case 90 :
                {
                    TrackAheadFreeUpToLevel23TransitionLocation_DecodeInt((TrackAheadFreeUpToLevel23TransitionLocation*)(header), data, stream);
                    return 1;
                }

                case 131 :
                {
                    RBCTransitionOrder_DecodeInt((RBCTransitionOrder*)(header), data, stream);
                    return 1;
                }

                case 132 :
                {
                    DangerForShuntingInformation_DecodeInt((DangerForShuntingInformation*)(header), data, stream);
                    return 1;
                }

                case 133 :
                {
                    RadioInfillAreaInformation_DecodeInt((RadioInfillAreaInformation*)(header), data, stream);
                    return 1;
                }

                case 134 :
                {
                    EOLMPacket_DecodeInt((EOLMPacket*)(header), data, stream);
                    return 1;
                }

                case 136 :
                {
                    InfillLocationReference_DecodeInt((InfillLocationReference*)(header), data, stream);
                    return 1;
                }

                case 137 :
                {
                    StopIfInStaffResponsible_DecodeInt((StopIfInStaffResponsible*)(header), data, stream);
                    return 1;
                }

                case 138 :
                {
                    ReversingAreaInformation_DecodeInt((ReversingAreaInformation*)(header), data, stream);
                    return 1;
                }

                case 139 :
                {
                    ReversingSupervisionInformation_DecodeInt((ReversingSupervisionInformation*)(header), data, stream);
                    return 1;
                }

                case 140 :
                {
                    TrainRunningNumberFromRBC_DecodeInt((TrainRunningNumberFromRBC*)(header), data, stream);
                    return 1;
                }

                case 141 :
                {
                    DefaultGradientForTemporarySpeedRestriction_DecodeInt((DefaultGradientForTemporarySpeedRestriction*)(header), data, stream);
                    return 1;
                }

                case 254 :
                {
                    DefaultBaliseLoopOrRIUInformation_DecodeInt((DefaultBaliseLoopOrRIUInformation*)(header), data, stream);
                    return 1;
                }

                default :
                {
                    fprintf(stderr, "Packet_DecodeInt: unexpected value for header->NID_PACKET = %lu\n", header->NID_PACKET);
                    return 0;
                }
            };
        }

        case BOTHWAYS :
        {
            assert(header->NID_PACKET == 255);
            EndOfInformation_DecodeInt((EndOfInformation*)header, data, stream);
            return 1;
        }

        default:
        {
            fprintf(stderr, "Packet_DecodeInt: unexpected value for header->list = %lu\n", header->list);
            return 0;
        }
    };
}

