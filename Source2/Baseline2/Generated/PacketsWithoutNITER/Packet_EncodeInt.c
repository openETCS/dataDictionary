
/* =============================================================================
Formalization of Subset-026-7 (Chapter 7: ERTMS/ETCS language)

- Name: Subset-026-7 / Packet_EncodeInt
- Description: UNISIG SUBSET-026-7, ISSUE : 3.3.0, 3.5 ERTMS/ETCS language) 
- Copyright (c) 

- Licensed under the EUPL V.1.1 ( http://joinup.ec.europa.eu/software/page/eupl/licence-eupl )
- Gist URL: none
- Cryptography: No
- Author(s): Fraunhofer FOKUS

Disclaimer:

The use of this software is limited to NON-vital applications. 
It has NOT been developed for vital operation purposes and MUST NOT be used for applications 
which may cause harm to people, physical accidents or financial loss. 

THEREFORE, NO LIABILITY WILL BE GIVEN FOR SUCH AND ANY OTHER KIND OF USE.       
============================================================================= */

#include "Packet_EncodeInt.h"
#include "AllPackets.h"
#include <assert.h>

int Packet_EncodeInt(const PacketHeader* header, Metadata* data, kcg_int* stream)
{
    switch (header->list)
    {
        case TRAINTOTRACK :
        {
            switch (header->NID_PACKET)
            {
                case 0 :
                {
                    PositionReport_EncodeInt((const PositionReport*)(header), data, stream);
                    return 1;
                }

                case 1 :
                {
                    PositionReportBasedOnTwoBaliseGroups_EncodeInt((const PositionReportBasedOnTwoBaliseGroups*)(header), data, stream);
                    return 1;
                }

                case 3 :
                {
                    OnboardTelephoneNumbers_EncodeInt((const OnboardTelephoneNumbers*)(header), data, stream);
                    return 1;
                }

                case 4 :
                {
                    ErrorReporting_EncodeInt((const ErrorReporting*)(header), data, stream);
                    return 1;
                }

                case 9 :
                {
                    Level23TransitionInformation_EncodeInt((const Level23TransitionInformation*)(header), data, stream);
                    return 1;
                }

                case 11 :
                {
                    ValidatedTrainData_EncodeInt((const ValidatedTrainData*)(header), data, stream);
                    return 1;
                }

                case 44 :
                {
                    DataUsedByApplicationsOutsideTheERTMSETCSSystem_EncodeInt((const DataUsedByApplicationsOutsideTheERTMSETCSSystem*)(header), data, stream);
                    return 1;
                }

                default :
                {
                    fprintf(stderr, "Packet_EncodeInt: unexpected value for header->NID_PACKET = %lu\n", header->NID_PACKET);
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
                    NationalValues_EncodeInt((const NationalValues*)(header), data, stream);
                    return 1;
                }

                case 5 :
                {
                    Linking_EncodeInt((const Linking*)(header), data, stream);
                    return 1;
                }

                case 12 :
                {
                    Level1MovementAuthority_EncodeInt((const Level1MovementAuthority*)(header), data, stream);
                    return 1;
                }

                case 15 :
                {
                    Level23MovementAuthority_EncodeInt((const Level23MovementAuthority*)(header), data, stream);
                    return 1;
                }

                case 16 :
                {
                    RepositioningInformation_EncodeInt((const RepositioningInformation*)(header), data, stream);
                    return 1;
                }

                case 21 :
                {
                    GradientProfile_EncodeInt((const GradientProfile*)(header), data, stream);
                    return 1;
                }

                case 27 :
                {
                    InternationalStaticSpeedProfile_EncodeInt((const InternationalStaticSpeedProfile*)(header), data, stream);
                    return 1;
                }

                case 39 :
                {
                    TrackConditionChangeOfTractionPower_EncodeInt((const TrackConditionChangeOfTractionPower*)(header), data, stream);
                    return 1;
                }

                case 41 :
                {
                    LevelTransitionOrder_EncodeInt((const LevelTransitionOrder*)(header), data, stream);
                    return 1;
                }

                case 42 :
                {
                    SessionManagement_EncodeInt((const SessionManagement*)(header), data, stream);
                    return 1;
                }

                case 44 :
                {
                    DataUsedByApplicationsOutsideTheERTMSETCSSystem_EncodeInt((const DataUsedByApplicationsOutsideTheERTMSETCSSystem*)(header), data, stream);
                    return 1;
                }

                case 45 :
                {
                    RadioNetworkRegistration_EncodeInt((const RadioNetworkRegistration*)(header), data, stream);
                    return 1;
                }

                case 46 :
                {
                    ConditionalLevelTransitionOrder_EncodeInt((const ConditionalLevelTransitionOrder*)(header), data, stream);
                    return 1;
                }

                case 49 :
                {
                    ListOfBalisesForSHArea_EncodeInt((const ListOfBalisesForSHArea*)(header), data, stream);
                    return 1;
                }

                case 51 :
                {
                    AxleLoadSpeedProfile_EncodeInt((const AxleLoadSpeedProfile*)(header), data, stream);
                    return 1;
                }

                case 57 :
                {
                    MovementAuthorityRequestParameters_EncodeInt((const MovementAuthorityRequestParameters*)(header), data, stream);
                    return 1;
                }

                case 58 :
                {
                    PositionReportParameters_EncodeInt((const PositionReportParameters*)(header), data, stream);
                    return 1;
                }

                case 63 :
                {
                    ListOfBalisesInSRAuthority_EncodeInt((const ListOfBalisesInSRAuthority*)(header), data, stream);
                    return 1;
                }

                case 65 :
                {
                    TemporarySpeedRestriction_EncodeInt((const TemporarySpeedRestriction*)(header), data, stream);
                    return 1;
                }

                case 66 :
                {
                    TemporarySpeedRestrictionRevocation_EncodeInt((const TemporarySpeedRestrictionRevocation*)(header), data, stream);
                    return 1;
                }

                case 67 :
                {
                    TrackConditionBigMetalMasses_EncodeInt((const TrackConditionBigMetalMasses*)(header), data, stream);
                    return 1;
                }

                case 68 :
                {
                    TrackCondition_EncodeInt((const TrackCondition*)(header), data, stream);
                    return 1;
                }

                case 70 :
                {
                    RouteSuitabilityData_EncodeInt((const RouteSuitabilityData*)(header), data, stream);
                    return 1;
                }

                case 71 :
                {
                    AdhesionFactor_EncodeInt((const AdhesionFactor*)(header), data, stream);
                    return 1;
                }

                case 72 :
                {
                    PacketForSendingPlainTextMessages_EncodeInt((const PacketForSendingPlainTextMessages*)(header), data, stream);
                    return 1;
                }

                case 76 :
                {
                    PacketForSendingFixedTextMessages_EncodeInt((const PacketForSendingFixedTextMessages*)(header), data, stream);
                    return 1;
                }

                case 79 :
                {
                    GeographicalPositionInformation_EncodeInt((const GeographicalPositionInformation*)(header), data, stream);
                    return 1;
                }

                case 80 :
                {
                    ModeProfile_EncodeInt((const ModeProfile*)(header), data, stream);
                    return 1;
                }

                case 90 :
                {
                    TrackAheadFreeUpToLevel23TransitionLocation_EncodeInt((const TrackAheadFreeUpToLevel23TransitionLocation*)(header), data, stream);
                    return 1;
                }

                case 131 :
                {
                    RBCTransitionOrder_EncodeInt((const RBCTransitionOrder*)(header), data, stream);
                    return 1;
                }

                case 132 :
                {
                    DangerForShuntingInformation_EncodeInt((const DangerForShuntingInformation*)(header), data, stream);
                    return 1;
                }

                case 133 :
                {
                    RadioInfillAreaInformation_EncodeInt((const RadioInfillAreaInformation*)(header), data, stream);
                    return 1;
                }

                case 134 :
                {
                    EOLMPacket_EncodeInt((const EOLMPacket*)(header), data, stream);
                    return 1;
                }

                case 136 :
                {
                    InfillLocationReference_EncodeInt((const InfillLocationReference*)(header), data, stream);
                    return 1;
                }

                case 137 :
                {
                    StopIfInStaffResponsible_EncodeInt((const StopIfInStaffResponsible*)(header), data, stream);
                    return 1;
                }

                case 138 :
                {
                    ReversingAreaInformation_EncodeInt((const ReversingAreaInformation*)(header), data, stream);
                    return 1;
                }

                case 139 :
                {
                    ReversingSupervisionInformation_EncodeInt((const ReversingSupervisionInformation*)(header), data, stream);
                    return 1;
                }

                case 140 :
                {
                    TrainRunningNumberFromRBC_EncodeInt((const TrainRunningNumberFromRBC*)(header), data, stream);
                    return 1;
                }

                case 141 :
                {
                    DefaultGradientForTemporarySpeedRestriction_EncodeInt((const DefaultGradientForTemporarySpeedRestriction*)(header), data, stream);
                    return 1;
                }

                case 254 :
                {
                    DefaultBaliseLoopOrRIUInformation_EncodeInt((const DefaultBaliseLoopOrRIUInformation*)(header), data, stream);
                    return 1;
                }

                default :
                {
                    fprintf(stderr, "Packet_EncodeInt: unexpected value for header->NID_PACKET = %lu\n", header->NID_PACKET);
                    return 0;
                }
            };
        }

        case BOTHWAYS :
        {
            assert(header->NID_PACKET == 255);
            EndOfInformation_EncodeInt((const EndOfInformation*)header, data, stream);
            return 1;
        }

        default:
        {
            fprintf(stderr, "Packet_EncodeInt: unexpected value for header->list = %lu\n", header->list);
            return 0;
        }
    };
}

