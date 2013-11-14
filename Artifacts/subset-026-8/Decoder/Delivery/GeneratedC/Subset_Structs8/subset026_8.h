
/* 
=============================================================================
Formalization of Subset-026-8 (Chapter 8: ERTMS/ETCS language)

- Name: Subset-026-8 / subset026_8.h
- Description: UNISIG SUBSET-026-8, ISSUE : 3.3.0, 3.5 ERTMS/ETCS language) 
- Copyright (c) Siemens AG, 2013, All Rights Reserved
    
- Licensed under the EUPL V.1.1 ( http://joinup.ec.europa.eu/software/page/eupl/licence-eupl )
- Gist URL: none
- Cryptography: No
- Author(s): SiemensRailAutomation

Disclaimer:

The use of this software is limited to NON-vital applications. 
It has NOT been developed for vital operation purposes and MUST NOT be used for applications 
which may cause harm to people, physical accidents or financial loss. 

THEREFORE, NO LIABILITY WILL BE GIVEN FOR SUCH AND ANY OTHER KIND OF USE.   
============================================================================= 
*/


 // please remember to include file 'opnETCS_Variables.h'  from Chapter7's directory
 #include "Radio_TrackToTrain_Acknowledgement_of_termination_of_a_communication_session.h"
#include "Radio_TrackToTrain_Acknowledgement_of_Train_Data.h"
#include "Radio_TrackToTrain_Assignment_of_coordinate_system.h"
#include "Radio_TrackToTrain_Conditional_Emergency_Stop.h"
#include "Radio_TrackToTrain_General_message.h"
#include "Radio_TrackToTrain_Infill_MA.h"
#include "Radio_TrackToTrain_Initiation_of_a_communication_session.h"
#include "Radio_TrackToTrain_MA_with_Shifted_Location_Reference.h"
#include "Radio_TrackToTrain_Movement_Authority.h"
#include "Radio_TrackToTrain_RBC_or_RIU_System_Version.h"
#include "Radio_TrackToTrain_Recognition_of_exit_from_TRIP_mode.h"
#include "Radio_TrackToTrain_Request_to_Shorten_MA.h"
#include "Radio_TrackToTrain_Revocation_of_Emergency_Stop.h"
#include "Radio_TrackToTrain_SH_Authorised.h"
#include "Radio_TrackToTrain_SH_Refused.h"
#include "Radio_TrackToTrain_SoM_position_report_confirmed_by_RBC.h"
#include "Radio_TrackToTrain_SR_Authorisation.h"
#include "Radio_TrackToTrain_Track_Ahead_Free_Request.h"
#include "Radio_TrackToTrain_Train_Accepted.h"
#include "Radio_TrackToTrain_Train_Rejected.h"
#include "Radio_TrackToTrain_Unconditional_Emergency_Stop.h"
#include "Radio_TrainToTrack_Acknowledgement.h"
#include "Radio_TrainToTrack_Acknowledgement_of_Emergency_Stop.h"
#include "Radio_TrainToTrack_End_of_Mission.h"
#include "Radio_TrainToTrack_Initiation_of_a_communication_session.h"
#include "Radio_TrainToTrack_MA_Request.h"
#include "Radio_TrainToTrack_No_compatible_version_supported.h"
#include "Radio_TrainToTrack_Radio_infill_request.h"
#include "Radio_TrainToTrack_Request_for_Shunting.h"
#include "Radio_TrainToTrack_Request_to_shorten_MA_is_granted.h"
#include "Radio_TrainToTrack_Request_to_shorten_MA_is_rejected.h"
#include "Radio_TrainToTrack_Session_Established.h"
#include "Radio_TrainToTrack_SoM_Position_Report.h"
#include "Radio_TrainToTrack_Termination_of_a_communication_session.h"
#include "Radio_TrainToTrack_Text_message_acknowledged_by_driver.h"
#include "Radio_TrainToTrack_Track_Ahead_Free_Granted.h"
#include "Radio_TrainToTrack_Train_Position_Report.h"
#include "Radio_TrainToTrack_Validated_Train_Data.h"
