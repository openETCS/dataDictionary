
#ifndef PACKETS_H_INCLUDED
#define PACKETS_H_INCLUDED

/* =============================================================================
Formalization of Subset-026-7 (Chapter 7: ERTMS/ETCS language)

- Name: Subset-026-7 / AllPackets
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


#include "NationalValues.h"
#include "Linking.h"
#include "Level1MovementAuthority.h"
#include "Level23MovementAuthority.h"
#include "RepositioningInformation.h"
#include "GradientProfile.h"
#include "InternationalStaticSpeedProfile.h"
#include "TrackConditionChangeOfTractionPower.h"
#include "LevelTransitionOrder.h"
#include "SessionManagement.h"
#include "DataUsedByApplicationsOutsideTheERTMSETCSSystem.h"
#include "RadioNetworkRegistration.h"
#include "ConditionalLevelTransitionOrder.h"
#include "ListOfBalisesForSHArea.h"
#include "AxleLoadSpeedProfile.h"
#include "MovementAuthorityRequestParameters.h"
#include "PositionReportParameters.h"
#include "ListOfBalisesInSRAuthority.h"
#include "TemporarySpeedRestriction.h"
#include "TemporarySpeedRestrictionRevocation.h"
#include "TrackConditionBigMetalMasses.h"
#include "TrackCondition.h"
#include "RouteSuitabilityData.h"
#include "AdhesionFactor.h"
#include "PacketForSendingPlainTextMessages.h"
#include "PacketForSendingFixedTextMessages.h"
#include "GeographicalPositionInformation.h"
#include "ModeProfile.h"
#include "TrackAheadFreeUpToLevel23TransitionLocation.h"
#include "RBCTransitionOrder.h"
#include "DangerForShuntingInformation.h"
#include "RadioInfillAreaInformation.h"
#include "EOLMPacket.h"
#include "InfillLocationReference.h"
#include "StopIfInStaffResponsible.h"
#include "ReversingAreaInformation.h"
#include "ReversingSupervisionInformation.h"
#include "TrainRunningNumberFromRBC.h"
#include "DefaultGradientForTemporarySpeedRestriction.h"
#include "DefaultBaliseLoopOrRIUInformation.h"
#include "PositionReport.h"
#include "PositionReportBasedOnTwoBaliseGroups.h"
#include "OnboardTelephoneNumbers.h"
#include "ErrorReporting.h"
#include "Level23TransitionInformation.h"
#include "ValidatedTrainData.h"
#include "DataUsedByApplicationsOutsideTheERTMSETCSSystem.h"
#include "EndOfInformation.h"

#endif // PACKETS_H_INCLUDED

