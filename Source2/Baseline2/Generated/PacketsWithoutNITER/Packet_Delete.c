
#include "Packet_Delete.h"
#include "AllPackets.h"
#include <assert.h>

int Packet_Delete(PacketHeader* header)
{
    switch (header->list)
    {
        case TRAINTOTRACK :
        {
            switch (header->NID_PACKET)
            {
                case 0 :
                {
                    PositionReport_Delete((PositionReport*)(header));
                    return 1;
                }

                case 1 :
                {
                    PositionReportBasedOnTwoBaliseGroups_Delete((PositionReportBasedOnTwoBaliseGroups*)(header));
                    return 1;
                }

                case 3 :
                {
                    OnboardTelephoneNumbers_Delete((OnboardTelephoneNumbers*)(header));
                    return 1;
                }

                case 4 :
                {
                    ErrorReporting_Delete((ErrorReporting*)(header));
                    return 1;
                }

                case 9 :
                {
                    Level23TransitionInformation_Delete((Level23TransitionInformation*)(header));
                    return 1;
                }

                case 11 :
                {
                    ValidatedTrainData_Delete((ValidatedTrainData*)(header));
                    return 1;
                }

                case 44 :
                {
                    DataUsedByApplicationsOutsideTheERTMSETCSSystem_Delete((DataUsedByApplicationsOutsideTheERTMSETCSSystem*)(header));
                    return 1;
                }

                default :
                {
                    fprintf(stderr, "Packet_Delete: unexpected value for header->NID_PACKET = %lu\n", header->NID_PACKET);
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
                    NationalValues_Delete((NationalValues*)(header));
                    return 1;
                }

                case 5 :
                {
                    Linking_Delete((Linking*)(header));
                    return 1;
                }

                case 12 :
                {
                    Level1MovementAuthority_Delete((Level1MovementAuthority*)(header));
                    return 1;
                }

                case 15 :
                {
                    Level23MovementAuthority_Delete((Level23MovementAuthority*)(header));
                    return 1;
                }

                case 16 :
                {
                    RepositioningInformation_Delete((RepositioningInformation*)(header));
                    return 1;
                }

                case 21 :
                {
                    GradientProfile_Delete((GradientProfile*)(header));
                    return 1;
                }

                case 27 :
                {
                    InternationalStaticSpeedProfile_Delete((InternationalStaticSpeedProfile*)(header));
                    return 1;
                }

                case 39 :
                {
                    TrackConditionChangeOfTractionPower_Delete((TrackConditionChangeOfTractionPower*)(header));
                    return 1;
                }

                case 41 :
                {
                    LevelTransitionOrder_Delete((LevelTransitionOrder*)(header));
                    return 1;
                }

                case 42 :
                {
                    SessionManagement_Delete((SessionManagement*)(header));
                    return 1;
                }

                case 44 :
                {
                    DataUsedByApplicationsOutsideTheERTMSETCSSystem_Delete((DataUsedByApplicationsOutsideTheERTMSETCSSystem*)(header));
                    return 1;
                }

                case 45 :
                {
                    RadioNetworkRegistration_Delete((RadioNetworkRegistration*)(header));
                    return 1;
                }

                case 46 :
                {
                    ConditionalLevelTransitionOrder_Delete((ConditionalLevelTransitionOrder*)(header));
                    return 1;
                }

                case 49 :
                {
                    ListOfBalisesForSHArea_Delete((ListOfBalisesForSHArea*)(header));
                    return 1;
                }

                case 51 :
                {
                    AxleLoadSpeedProfile_Delete((AxleLoadSpeedProfile*)(header));
                    return 1;
                }

                case 57 :
                {
                    MovementAuthorityRequestParameters_Delete((MovementAuthorityRequestParameters*)(header));
                    return 1;
                }

                case 58 :
                {
                    PositionReportParameters_Delete((PositionReportParameters*)(header));
                    return 1;
                }

                case 63 :
                {
                    ListOfBalisesInSRAuthority_Delete((ListOfBalisesInSRAuthority*)(header));
                    return 1;
                }

                case 65 :
                {
                    TemporarySpeedRestriction_Delete((TemporarySpeedRestriction*)(header));
                    return 1;
                }

                case 66 :
                {
                    TemporarySpeedRestrictionRevocation_Delete((TemporarySpeedRestrictionRevocation*)(header));
                    return 1;
                }

                case 67 :
                {
                    TrackConditionBigMetalMasses_Delete((TrackConditionBigMetalMasses*)(header));
                    return 1;
                }

                case 68 :
                {
                    TrackCondition_Delete((TrackCondition*)(header));
                    return 1;
                }

                case 70 :
                {
                    RouteSuitabilityData_Delete((RouteSuitabilityData*)(header));
                    return 1;
                }

                case 71 :
                {
                    AdhesionFactor_Delete((AdhesionFactor*)(header));
                    return 1;
                }

                case 72 :
                {
                    PacketForSendingPlainTextMessages_Delete((PacketForSendingPlainTextMessages*)(header));
                    return 1;
                }

                case 76 :
                {
                    PacketForSendingFixedTextMessages_Delete((PacketForSendingFixedTextMessages*)(header));
                    return 1;
                }

                case 79 :
                {
                    GeographicalPositionInformation_Delete((GeographicalPositionInformation*)(header));
                    return 1;
                }

                case 80 :
                {
                    ModeProfile_Delete((ModeProfile*)(header));
                    return 1;
                }

                case 90 :
                {
                    TrackAheadFreeUpToLevel23TransitionLocation_Delete((TrackAheadFreeUpToLevel23TransitionLocation*)(header));
                    return 1;
                }

                case 131 :
                {
                    RBCTransitionOrder_Delete((RBCTransitionOrder*)(header));
                    return 1;
                }

                case 132 :
                {
                    DangerForShuntingInformation_Delete((DangerForShuntingInformation*)(header));
                    return 1;
                }

                case 133 :
                {
                    RadioInfillAreaInformation_Delete((RadioInfillAreaInformation*)(header));
                    return 1;
                }

                case 134 :
                {
                    EOLMPacket_Delete((EOLMPacket*)(header));
                    return 1;
                }

                case 136 :
                {
                    InfillLocationReference_Delete((InfillLocationReference*)(header));
                    return 1;
                }

                case 137 :
                {
                    StopIfInStaffResponsible_Delete((StopIfInStaffResponsible*)(header));
                    return 1;
                }

                case 138 :
                {
                    ReversingAreaInformation_Delete((ReversingAreaInformation*)(header));
                    return 1;
                }

                case 139 :
                {
                    ReversingSupervisionInformation_Delete((ReversingSupervisionInformation*)(header));
                    return 1;
                }

                case 140 :
                {
                    TrainRunningNumberFromRBC_Delete((TrainRunningNumberFromRBC*)(header));
                    return 1;
                }

                case 141 :
                {
                    DefaultGradientForTemporarySpeedRestriction_Delete((DefaultGradientForTemporarySpeedRestriction*)(header));
                    return 1;
                }

                case 254 :
                {
                    DefaultBaliseLoopOrRIUInformation_Delete((DefaultBaliseLoopOrRIUInformation*)(header));
                    return 1;
                }

                default :
                {
                    fprintf(stderr, "Packet_Delete: unexpected value for header->NID_PACKET = %lu\n", header->NID_PACKET);
                    return 0;
                }
            };
        }

        case BOTHWAYS :
        {
            assert(header->NID_PACKET == 255);
            EndOfInformation_Delete((EndOfInformation*)header);
            return 1;
        }

        default:
        {
            fprintf(stderr, "Packet_Delete: unexpected value for header->list = %lu\n", header->list);
            return 0;
        }
    };
}

