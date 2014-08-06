#ifndef NESTINGMARK_Radio_Subset026_8H
#define NESTINGMARK_Radio_Subset026_8H
#include "subset026_8.h"


/* 
=============================================================================
Formalization of Subset-026-8 (Chapter 8: ERTMS/ETCS language)

- Name: Subset-026-8 / Radio_Decoder.h
- Description: UNISIG SUBSET-026-8, ISSUE : 3.3.0, 3.5 ERTMS/ETCS language) 
- Copyright (c) Siemens AG, 2014, All Rights Reserved
    
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

int TrainToTrack_Message_129 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_Radio_TrainToTrack_Validated_Train_Data Radio) ;
int TrainToTrack_Message_130 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_Radio_TrainToTrack_Request_for_Shunting Radio) ;
int TrainToTrack_Message_132 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_Radio_TrainToTrack_MA_Request Radio) ;
int TrainToTrack_Message_136 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_Radio_TrainToTrack_Train_Position_Report Radio) ;
int TrainToTrack_Message_137 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_Radio_TrainToTrack_Request_to_shorten_MA_is_granted Radio) ;
int TrainToTrack_Message_138 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_Radio_TrainToTrack_Request_to_shorten_MA_is_rejected Radio) ;
int TrainToTrack_Message_146 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_Radio_TrainToTrack_Acknowledgement Radio) ;
int TrainToTrack_Message_147 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_Radio_TrainToTrack_Acknowledgement_of_Emergency_Stop Radio) ;
int TrainToTrack_Message_149 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_Radio_TrainToTrack_Track_Ahead_Free_Granted Radio) ;
int TrainToTrack_Message_150 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_Radio_TrainToTrack_End_of_Mission Radio) ;
int TrainToTrack_Message_153 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_Radio_TrainToTrack_Radio_infill_request Radio) ;
int TrainToTrack_Message_154 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_Radio_TrainToTrack_No_compatible_version_supported Radio) ;
int TrainToTrack_Message_155 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_Radio_TrainToTrack_Initiation_of_a_communication_session Radio) ;
int TrainToTrack_Message_156 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_Radio_TrainToTrack_Termination_of_a_communication_session Radio) ;
int TrainToTrack_Message_157 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_Radio_TrainToTrack_SoM_Position_Report Radio) ;
int TrainToTrack_Message_158 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_Radio_TrainToTrack_Text_message_acknowledged_by_driver Radio) ;
int TrainToTrack_Message_159 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_Radio_TrainToTrack_Session_Established Radio) ;
int TrackToTrain_Message_002 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_Radio_TrackToTrain_SR_Authorisation Radio) ;
int TrackToTrain_Message_003 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_Radio_TrackToTrain_Movement_Authority Radio) ;
int TrackToTrain_Message_006 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_Radio_TrackToTrain_Recognition_of_exit_from_TRIP_mode Radio) ;
int TrackToTrain_Message_008 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_Radio_TrackToTrain_Acknowledgement_of_Train_Data Radio) ;
int TrackToTrain_Message_009 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_Radio_TrackToTrain_Request_to_Shorten_MA Radio) ;
int TrackToTrain_Message_015 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_Radio_TrackToTrain_Conditional_Emergency_Stop Radio) ;
int TrackToTrain_Message_016 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_Radio_TrackToTrain_Unconditional_Emergency_Stop Radio) ;
int TrackToTrain_Message_018 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_Radio_TrackToTrain_Revocation_of_Emergency_Stop Radio) ;
int TrackToTrain_Message_024 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_Radio_TrackToTrain_General_message Radio) ;
int TrackToTrain_Message_027 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_Radio_TrackToTrain_SH_Refused Radio) ;
int TrackToTrain_Message_028 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_Radio_TrackToTrain_SH_Authorised Radio) ;
int TrackToTrain_Message_032 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_Radio_TrackToTrain_RBC_or_RIU_System_Version Radio) ;
int TrackToTrain_Message_033 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_Radio_TrackToTrain_MA_with_Shifted_Location_Reference Radio) ;
int TrackToTrain_Message_034 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_Radio_TrackToTrain_Track_Ahead_Free_Request Radio) ;
int TrackToTrain_Message_037 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_Radio_TrackToTrain_Infill_MA Radio) ;
int TrackToTrain_Message_038 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_Radio_TrackToTrain_Initiation_of_a_communication_session Radio) ;
int TrackToTrain_Message_039 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_Radio_TrackToTrain_Acknowledgement_of_termination_of_a_communication_session Radio) ;
int TrackToTrain_Message_040 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_Radio_TrackToTrain_Train_Rejected Radio) ;
int TrackToTrain_Message_041 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_Radio_TrackToTrain_Train_Accepted Radio) ;
int TrackToTrain_Message_043 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_Radio_TrackToTrain_SoM_position_report_confirmed_by_RBC Radio) ;
int TrackToTrain_Message_045 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_Radio_TrackToTrain_Assignment_of_coordinate_system Radio) ;

#endif
    
