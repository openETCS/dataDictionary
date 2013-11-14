#include "subset026_8.h"

/* 
=============================================================================
Formalization of Subset-026-8 (Chapter 8: ERTMS/ETCS language)

- Name: Subset-026-8 / opnETCS_Decoder.h
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

void Radio_TrainToTrack_Validated_Train_Data (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_Radio_TrainToTrack_Validated_Train_Data oETCS) ;
void Radio_TrainToTrack_Request_for_Shunting (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_Radio_TrainToTrack_Request_for_Shunting oETCS) ;
void Radio_TrainToTrack_MA_Request (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_Radio_TrainToTrack_MA_Request oETCS) ;
void Radio_TrainToTrack_Train_Position_Report (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_Radio_TrainToTrack_Train_Position_Report oETCS) ;
void Radio_TrainToTrack_Request_to_shorten_MA_is_granted (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_Radio_TrainToTrack_Request_to_shorten_MA_is_granted oETCS) ;
void Radio_TrainToTrack_Request_to_shorten_MA_is_rejected (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_Radio_TrainToTrack_Request_to_shorten_MA_is_rejected oETCS) ;
void Radio_TrainToTrack_Acknowledgement (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_Radio_TrainToTrack_Acknowledgement oETCS) ;
void Radio_TrainToTrack_Acknowledgement_of_Emergency_Stop (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_Radio_TrainToTrack_Acknowledgement_of_Emergency_Stop oETCS) ;
void Radio_TrainToTrack_Track_Ahead_Free_Granted (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_Radio_TrainToTrack_Track_Ahead_Free_Granted oETCS) ;
void Radio_TrainToTrack_End_of_Mission (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_Radio_TrainToTrack_End_of_Mission oETCS) ;
void Radio_TrainToTrack_Radio_infill_request (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_Radio_TrainToTrack_Radio_infill_request oETCS) ;
void Radio_TrainToTrack_No_compatible_version_supported (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_Radio_TrainToTrack_No_compatible_version_supported oETCS) ;
void Radio_TrainToTrack_Initiation_of_a_communication_session (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_Radio_TrainToTrack_Initiation_of_a_communication_session oETCS) ;
void Radio_TrainToTrack_Termination_of_a_communication_session (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_Radio_TrainToTrack_Termination_of_a_communication_session oETCS) ;
void Radio_TrainToTrack_SoM_Position_Report (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_Radio_TrainToTrack_SoM_Position_Report oETCS) ;
void Radio_TrainToTrack_Text_message_acknowledged_by_driver (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_Radio_TrainToTrack_Text_message_acknowledged_by_driver oETCS) ;
void Radio_TrainToTrack_Session_Established (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_Radio_TrainToTrack_Session_Established oETCS) ;
void Radio_TrackToTrain_SR_Authorisation (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_Radio_TrackToTrain_SR_Authorisation oETCS) ;
void Radio_TrackToTrain_Movement_Authority (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_Radio_TrackToTrain_Movement_Authority oETCS) ;
void Radio_TrackToTrain_Recognition_of_exit_from_TRIP_mode (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_Radio_TrackToTrain_Recognition_of_exit_from_TRIP_mode oETCS) ;
void Radio_TrackToTrain_Acknowledgement_of_Train_Data (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_Radio_TrackToTrain_Acknowledgement_of_Train_Data oETCS) ;
void Radio_TrackToTrain_Request_to_Shorten_MA (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_Radio_TrackToTrain_Request_to_Shorten_MA oETCS) ;
void Radio_TrackToTrain_Conditional_Emergency_Stop (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_Radio_TrackToTrain_Conditional_Emergency_Stop oETCS) ;
void Radio_TrackToTrain_Unconditional_Emergency_Stop (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_Radio_TrackToTrain_Unconditional_Emergency_Stop oETCS) ;
void Radio_TrackToTrain_Revocation_of_Emergency_Stop (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_Radio_TrackToTrain_Revocation_of_Emergency_Stop oETCS) ;
void Radio_TrackToTrain_General_message (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_Radio_TrackToTrain_General_message oETCS) ;
void Radio_TrackToTrain_SH_Refused (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_Radio_TrackToTrain_SH_Refused oETCS) ;
void Radio_TrackToTrain_SH_Authorised (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_Radio_TrackToTrain_SH_Authorised oETCS) ;
void Radio_TrackToTrain_RBC_or_RIU_System_Version (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_Radio_TrackToTrain_RBC_or_RIU_System_Version oETCS) ;
void Radio_TrackToTrain_MA_with_Shifted_Location_Reference (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_Radio_TrackToTrain_MA_with_Shifted_Location_Reference oETCS) ;
void Radio_TrackToTrain_Track_Ahead_Free_Request (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_Radio_TrackToTrain_Track_Ahead_Free_Request oETCS) ;
void Radio_TrackToTrain_Infill_MA (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_Radio_TrackToTrain_Infill_MA oETCS) ;
void Radio_TrackToTrain_Initiation_of_a_communication_session (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_Radio_TrackToTrain_Initiation_of_a_communication_session oETCS) ;
void Radio_TrackToTrain_Acknowledgement_of_termination_of_a_communication_session (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_Radio_TrackToTrain_Acknowledgement_of_termination_of_a_communication_session oETCS) ;
void Radio_TrackToTrain_Train_Rejected (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_Radio_TrackToTrain_Train_Rejected oETCS) ;
void Radio_TrackToTrain_Train_Accepted (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_Radio_TrackToTrain_Train_Accepted oETCS) ;
void Radio_TrackToTrain_SoM_position_report_confirmed_by_RBC (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_Radio_TrackToTrain_SoM_position_report_confirmed_by_RBC oETCS) ;
void Radio_TrackToTrain_Assignment_of_coordinate_system (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_Radio_TrackToTrain_Assignment_of_coordinate_system oETCS) ;
