
#include "Packet_Length.h"
#include "AllPackets.h"

uint32_t Packet_Length(const PacketHeader* header)
{
    switch (header->list)
    {
        case TRAINTOTRACK :
        {
            switch (header->NID_PACKET)
            {
                case 0 :
                {
                    return PositionReport_Length((const PositionReport*)(header));
                }

                case 1 :
                {
                    return PositionReportBasedOnTwoBaliseGroups_Length((const PositionReportBasedOnTwoBaliseGroups*)(header));
                }

                case 3 :
                {
                    return OnboardTelephoneNumbers_Length((const OnboardTelephoneNumbers*)(header));
                }

                case 4 :
                {
                    return ErrorReporting_Length((const ErrorReporting*)(header));
                }

                case 9 :
                {
                    return Level23TransitionInformation_Length((const Level23TransitionInformation*)(header));
                }

                case 11 :
                {
                    return ValidatedTrainData_Length((const ValidatedTrainData*)(header));
                }

                case 44 :
                {
                    return DataUsedByApplicationsOutsideTheERTMSETCSSystem_Length((const DataUsedByApplicationsOutsideTheERTMSETCSSystem*)(header));
                }

                default :
                {
                    fprintf(stderr, "Packet_Length: unexpected value for header->NID_PACKET = %lu\n", header->NID_PACKET);
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
                    return NationalValues_Length((const NationalValues*)(header));
                }

                case 5 :
                {
                    return Linking_Length((const Linking*)(header));
                }

                case 12 :
                {
                    return Level1MovementAuthority_Length((const Level1MovementAuthority*)(header));
                }

                case 15 :
                {
                    return Level23MovementAuthority_Length((const Level23MovementAuthority*)(header));
                }

                case 16 :
                {
                    return RepositioningInformation_Length((const RepositioningInformation*)(header));
                }

                case 21 :
                {
                    return GradientProfile_Length((const GradientProfile*)(header));
                }

                case 27 :
                {
                    return InternationalStaticSpeedProfile_Length((const InternationalStaticSpeedProfile*)(header));
                }

                case 39 :
                {
                    return TrackConditionChangeOfTractionPower_Length((const TrackConditionChangeOfTractionPower*)(header));
                }

                case 41 :
                {
                    return LevelTransitionOrder_Length((const LevelTransitionOrder*)(header));
                }

                case 42 :
                {
                    return SessionManagement_Length((const SessionManagement*)(header));
                }

                case 44 :
                {
                    return DataUsedByApplicationsOutsideTheERTMSETCSSystem_Length((const DataUsedByApplicationsOutsideTheERTMSETCSSystem*)(header));
                }

                case 45 :
                {
                    return RadioNetworkRegistration_Length((const RadioNetworkRegistration*)(header));
                }

                case 46 :
                {
                    return ConditionalLevelTransitionOrder_Length((const ConditionalLevelTransitionOrder*)(header));
                }

                case 49 :
                {
                    return ListOfBalisesForSHArea_Length((const ListOfBalisesForSHArea*)(header));
                }

                case 51 :
                {
                    return AxleLoadSpeedProfile_Length((const AxleLoadSpeedProfile*)(header));
                }

                case 57 :
                {
                    return MovementAuthorityRequestParameters_Length((const MovementAuthorityRequestParameters*)(header));
                }

                case 58 :
                {
                    return PositionReportParameters_Length((const PositionReportParameters*)(header));
                }

                case 63 :
                {
                    return ListOfBalisesInSRAuthority_Length((const ListOfBalisesInSRAuthority*)(header));
                }

                case 65 :
                {
                    return TemporarySpeedRestriction_Length((const TemporarySpeedRestriction*)(header));
                }

                case 66 :
                {
                    return TemporarySpeedRestrictionRevocation_Length((const TemporarySpeedRestrictionRevocation*)(header));
                }

                case 67 :
                {
                    return TrackConditionBigMetalMasses_Length((const TrackConditionBigMetalMasses*)(header));
                }

                case 68 :
                {
                    return TrackCondition_Length((const TrackCondition*)(header));
                }

                case 70 :
                {
                    return RouteSuitabilityData_Length((const RouteSuitabilityData*)(header));
                }

                case 71 :
                {
                    return AdhesionFactor_Length((const AdhesionFactor*)(header));
                }

                case 72 :
                {
                    return PacketForSendingPlainTextMessages_Length((const PacketForSendingPlainTextMessages*)(header));
                }

                case 76 :
                {
                    return PacketForSendingFixedTextMessages_Length((const PacketForSendingFixedTextMessages*)(header));
                }

                case 79 :
                {
                    return GeographicalPositionInformation_Length((const GeographicalPositionInformation*)(header));
                }

                case 80 :
                {
                    return ModeProfile_Length((const ModeProfile*)(header));
                }

                case 90 :
                {
                    return TrackAheadFreeUpToLevel23TransitionLocation_Length((const TrackAheadFreeUpToLevel23TransitionLocation*)(header));
                }

                case 131 :
                {
                    return RBCTransitionOrder_Length((const RBCTransitionOrder*)(header));
                }

                case 132 :
                {
                    return DangerForShuntingInformation_Length((const DangerForShuntingInformation*)(header));
                }

                case 133 :
                {
                    return RadioInfillAreaInformation_Length((const RadioInfillAreaInformation*)(header));
                }

                case 134 :
                {
                    return EOLMPacket_Length((const EOLMPacket*)(header));
                }

                case 136 :
                {
                    return InfillLocationReference_Length((const InfillLocationReference*)(header));
                }

                case 137 :
                {
                    return StopIfInStaffResponsible_Length((const StopIfInStaffResponsible*)(header));
                }

                case 138 :
                {
                    return ReversingAreaInformation_Length((const ReversingAreaInformation*)(header));
                }

                case 139 :
                {
                    return ReversingSupervisionInformation_Length((const ReversingSupervisionInformation*)(header));
                }

                case 140 :
                {
                    return TrainRunningNumberFromRBC_Length((const TrainRunningNumberFromRBC*)(header));
                }

                case 141 :
                {
                    return DefaultGradientForTemporarySpeedRestriction_Length((const DefaultGradientForTemporarySpeedRestriction*)(header));
                }

                case 254 :
                {
                    return DefaultBaliseLoopOrRIUInformation_Length((const DefaultBaliseLoopOrRIUInformation*)(header));
                }

                default :
                {
                    fprintf(stderr, "Packet_Length: unexpected value for header->NID_PACKET = %lu\n", header->NID_PACKET);
                    return 0;
                }
            };
        }

        case BOTHWAYS :
        {
            assert(header->NID_PACKET == 255);
            return EndOfInformation_Length((const EndOfInformation*)header);
        }

        default:
        {
            fprintf(stderr, "Packet_Length: unexpected value for header->list = %lu\n", header->list);
            return 0;
        }
    };
}

