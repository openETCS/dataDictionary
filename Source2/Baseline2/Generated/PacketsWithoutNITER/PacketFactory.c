
#include "PacketFactory.h"
#include "AllPackets.h"

PacketHeader* PacketFactory_BothWays(PacketHeader header)
{
    switch (header.NID_PACKET)
    {
        case 255 :
        {
            EndOfInformation* ptr = EndOfInformation_New();
            PacketHeader*   p = &(ptr->header);
            return p;
        }

        default :
        {
            return NULL;
        }
    };
}


PacketHeader* PacketFactory_TrackToTrain(PacketHeader header)
{
    switch (header.NID_PACKET)
    {
        case 3 :
        {
            NationalValues* ptr = NationalValues_New();
            PacketHeader*   p = &(ptr->header);
            return p;
        }

        case 5 :
        {
            Linking* ptr = Linking_New();
            PacketHeader*   p = &(ptr->header);
            return p;
        }

        case 12 :
        {
            Level1MovementAuthority* ptr = Level1MovementAuthority_New();
            PacketHeader*   p = &(ptr->header);
            return p;
        }

        case 15 :
        {
            Level23MovementAuthority* ptr = Level23MovementAuthority_New();
            PacketHeader*   p = &(ptr->header);
            return p;
        }

        case 16 :
        {
            RepositioningInformation* ptr = RepositioningInformation_New();
            PacketHeader*   p = &(ptr->header);
            return p;
        }

        case 21 :
        {
            GradientProfile* ptr = GradientProfile_New();
            PacketHeader*   p = &(ptr->header);
            return p;
        }

        case 27 :
        {
            InternationalStaticSpeedProfile* ptr = InternationalStaticSpeedProfile_New();
            PacketHeader*   p = &(ptr->header);
            return p;
        }

        case 39 :
        {
            TrackConditionChangeOfTractionPower* ptr = TrackConditionChangeOfTractionPower_New();
            PacketHeader*   p = &(ptr->header);
            return p;
        }

        case 41 :
        {
            LevelTransitionOrder* ptr = LevelTransitionOrder_New();
            PacketHeader*   p = &(ptr->header);
            return p;
        }

        case 42 :
        {
            SessionManagement* ptr = SessionManagement_New();
            PacketHeader*   p = &(ptr->header);
            return p;
        }

        case 44 :
        {
            DataUsedByApplicationsOutsideTheERTMSETCSSystem* ptr = DataUsedByApplicationsOutsideTheERTMSETCSSystem_New();
            PacketHeader*   p = &(ptr->header);
            return p;
        }

        case 45 :
        {
            RadioNetworkRegistration* ptr = RadioNetworkRegistration_New();
            PacketHeader*   p = &(ptr->header);
            return p;
        }

        case 46 :
        {
            ConditionalLevelTransitionOrder* ptr = ConditionalLevelTransitionOrder_New();
            PacketHeader*   p = &(ptr->header);
            return p;
        }

        case 49 :
        {
            ListOfBalisesForSHArea* ptr = ListOfBalisesForSHArea_New();
            PacketHeader*   p = &(ptr->header);
            return p;
        }

        case 51 :
        {
            AxleLoadSpeedProfile* ptr = AxleLoadSpeedProfile_New();
            PacketHeader*   p = &(ptr->header);
            return p;
        }

        case 57 :
        {
            MovementAuthorityRequestParameters* ptr = MovementAuthorityRequestParameters_New();
            PacketHeader*   p = &(ptr->header);
            return p;
        }

        case 58 :
        {
            PositionReportParameters* ptr = PositionReportParameters_New();
            PacketHeader*   p = &(ptr->header);
            return p;
        }

        case 63 :
        {
            ListOfBalisesInSRAuthority* ptr = ListOfBalisesInSRAuthority_New();
            PacketHeader*   p = &(ptr->header);
            return p;
        }

        case 65 :
        {
            TemporarySpeedRestriction* ptr = TemporarySpeedRestriction_New();
            PacketHeader*   p = &(ptr->header);
            return p;
        }

        case 66 :
        {
            TemporarySpeedRestrictionRevocation* ptr = TemporarySpeedRestrictionRevocation_New();
            PacketHeader*   p = &(ptr->header);
            return p;
        }

        case 67 :
        {
            TrackConditionBigMetalMasses* ptr = TrackConditionBigMetalMasses_New();
            PacketHeader*   p = &(ptr->header);
            return p;
        }

        case 68 :
        {
            TrackCondition* ptr = TrackCondition_New();
            PacketHeader*   p = &(ptr->header);
            return p;
        }

        case 70 :
        {
            RouteSuitabilityData* ptr = RouteSuitabilityData_New();
            PacketHeader*   p = &(ptr->header);
            return p;
        }

        case 71 :
        {
            AdhesionFactor* ptr = AdhesionFactor_New();
            PacketHeader*   p = &(ptr->header);
            return p;
        }

        case 72 :
        {
            PacketForSendingPlainTextMessages* ptr = PacketForSendingPlainTextMessages_New();
            PacketHeader*   p = &(ptr->header);
            return p;
        }

        case 76 :
        {
            PacketForSendingFixedTextMessages* ptr = PacketForSendingFixedTextMessages_New();
            PacketHeader*   p = &(ptr->header);
            return p;
        }

        case 79 :
        {
            GeographicalPositionInformation* ptr = GeographicalPositionInformation_New();
            PacketHeader*   p = &(ptr->header);
            return p;
        }

        case 80 :
        {
            ModeProfile* ptr = ModeProfile_New();
            PacketHeader*   p = &(ptr->header);
            return p;
        }

        case 90 :
        {
            TrackAheadFreeUpToLevel23TransitionLocation* ptr = TrackAheadFreeUpToLevel23TransitionLocation_New();
            PacketHeader*   p = &(ptr->header);
            return p;
        }

        case 131 :
        {
            RBCTransitionOrder* ptr = RBCTransitionOrder_New();
            PacketHeader*   p = &(ptr->header);
            return p;
        }

        case 132 :
        {
            DangerForShuntingInformation* ptr = DangerForShuntingInformation_New();
            PacketHeader*   p = &(ptr->header);
            return p;
        }

        case 133 :
        {
            RadioInfillAreaInformation* ptr = RadioInfillAreaInformation_New();
            PacketHeader*   p = &(ptr->header);
            return p;
        }

        case 134 :
        {
            EOLMPacket* ptr = EOLMPacket_New();
            PacketHeader*   p = &(ptr->header);
            return p;
        }

        case 136 :
        {
            InfillLocationReference* ptr = InfillLocationReference_New();
            PacketHeader*   p = &(ptr->header);
            return p;
        }

        case 137 :
        {
            StopIfInStaffResponsible* ptr = StopIfInStaffResponsible_New();
            PacketHeader*   p = &(ptr->header);
            return p;
        }

        case 138 :
        {
            ReversingAreaInformation* ptr = ReversingAreaInformation_New();
            PacketHeader*   p = &(ptr->header);
            return p;
        }

        case 139 :
        {
            ReversingSupervisionInformation* ptr = ReversingSupervisionInformation_New();
            PacketHeader*   p = &(ptr->header);
            return p;
        }

        case 140 :
        {
            TrainRunningNumberFromRBC* ptr = TrainRunningNumberFromRBC_New();
            PacketHeader*   p = &(ptr->header);
            return p;
        }

        case 141 :
        {
            DefaultGradientForTemporarySpeedRestriction* ptr = DefaultGradientForTemporarySpeedRestriction_New();
            PacketHeader*   p = &(ptr->header);
            return p;
        }

        case 254 :
        {
            DefaultBaliseLoopOrRIUInformation* ptr = DefaultBaliseLoopOrRIUInformation_New();
            PacketHeader*   p = &(ptr->header);
            return p;
        }

        default :
        {
            return NULL;
        }
    };
}

PacketHeader* PacketFactory_TrainToTrack(PacketHeader header)
{
    switch (header.NID_PACKET)
    {
        case 0 :
        {
            PositionReport* ptr = PositionReport_New();
            PacketHeader*   p = &(ptr->header);
            return p;
        }

        case 1 :
        {
            PositionReportBasedOnTwoBaliseGroups* ptr = PositionReportBasedOnTwoBaliseGroups_New();
            PacketHeader*   p = &(ptr->header);
            return p;
        }

        case 3 :
        {
            OnboardTelephoneNumbers* ptr = OnboardTelephoneNumbers_New();
            PacketHeader*   p = &(ptr->header);
            return p;
        }

        case 4 :
        {
            ErrorReporting* ptr = ErrorReporting_New();
            PacketHeader*   p = &(ptr->header);
            return p;
        }

        case 9 :
        {
            Level23TransitionInformation* ptr = Level23TransitionInformation_New();
            PacketHeader*   p = &(ptr->header);
            return p;
        }

        case 11 :
        {
            ValidatedTrainData* ptr = ValidatedTrainData_New();
            PacketHeader*   p = &(ptr->header);
            return p;
        }

        case 44 :
        {
            DataUsedByApplicationsOutsideTheERTMSETCSSystem* ptr = DataUsedByApplicationsOutsideTheERTMSETCSSystem_New();
            PacketHeader*   p = &(ptr->header);
            return p;
        }

        default :
        {
            return 0;
        }
    };
}

