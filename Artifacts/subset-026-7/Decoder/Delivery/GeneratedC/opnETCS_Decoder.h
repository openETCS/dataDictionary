#include "subset026_7.h"
#include "subset026_7.h"
#include "opnETCS_DecoderBranch.h"
    

/* =============================================================================
Formalization of Subset-026-7 (Chapter 7: ERTMS/ETCS language)

- Name: opnETCS_Decoder.h
- Description: UNISIG SUBSET-026-7, ISSUE : 3.3.0, 3.5 ERTMS/ETCS language) 
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
============================================================================= */

int TrackToTrain_Packet_000 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_TrackToTrain_Virtual_Balise_Cover_marker oETCS ) ;
int TrackToTrain_Packet_002 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_TrackToTrain_System_Version_order oETCS ) ;
int TrackToTrain_Packet_003 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_TrackToTrain_National_Values oETCS ) ;
int TrackToTrain_Packet_005 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_TrackToTrain_Linking oETCS ) ;
int TrackToTrain_Packet_006 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_TrackToTrain_Virtual_Balise_Cover_order oETCS ) ;
int TrackToTrain_Packet_012 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_TrackToTrain_Level_1_Movement_Authority oETCS ) ;
int TrackToTrain_Packet_013 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_TrackToTrain_Staff_Responsible_distance_Information_from_loop oETCS ) ;
int TrackToTrain_Packet_015 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_TrackToTrain_Level_23_Movement_Authority oETCS ) ;
int TrackToTrain_Packet_016 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_TrackToTrain_Repositioning_Information oETCS ) ;
int TrackToTrain_Packet_021 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_TrackToTrain_Gradient_Profile oETCS ) ;
int TrackToTrain_Packet_027 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_TrackToTrain_International_Static_Speed_Profile oETCS ) ;
int TrackToTrain_Packet_039 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_TrackToTrain_Track_Condition_Change_of_traction_system oETCS ) ;
int TrackToTrain_Packet_040 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_TrackToTrain_Track_Condition_Change_of_allowed_current_consumption oETCS ) ;
int TrackToTrain_Packet_041 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_TrackToTrain_Level_Transition_Order oETCS ) ;
int TrackToTrain_Packet_042 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_TrackToTrain_Session_Management oETCS ) ;
int TrackToTrain_Packet_044 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_TrackToTrain_Data_used_by_applications_outside_the_ERTMSETCS_system oETCS ) ;
int TrackToTrain_Packet_045 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_TrackToTrain_Radio_Network_registration oETCS ) ;
int TrackToTrain_Packet_046 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_TrackToTrain_Conditional_Level_Transition_Order oETCS ) ;
int TrackToTrain_Packet_049 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_TrackToTrain_List_of_balises_for_SH_Area oETCS ) ;
int TrackToTrain_Packet_051 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_TrackToTrain_Axle_Load_Speed_Profile oETCS ) ;
int TrackToTrain_Packet_052 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_TrackToTrain_Permitted_Braking_Distance_Information oETCS ) ;
int TrackToTrain_Packet_057 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_TrackToTrain_Movement_Authority_Request_Parameters oETCS ) ;
int TrackToTrain_Packet_058 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_TrackToTrain_Position_Report_Parameters oETCS ) ;
int TrackToTrain_Packet_063 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_TrackToTrain_List_of_Balises_in_SR_Authority oETCS ) ;
int TrackToTrain_Packet_064 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_TrackToTrain_Inhibition_of_revocable_TSRs_from_balises_in_L23 oETCS ) ;
int TrackToTrain_Packet_065 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_TrackToTrain_Temporary_Speed_Restriction oETCS ) ;
int TrackToTrain_Packet_066 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_TrackToTrain_Temporary_Speed_Restriction_Revocation oETCS ) ;
int TrackToTrain_Packet_067 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_TrackToTrain_Track_Condition_Big_Metal_Masses oETCS ) ;
int TrackToTrain_Packet_068 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_TrackToTrain_Track_Condition oETCS ) ;
int TrackToTrain_Packet_069 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_TrackToTrain_Track_Condition_Station_Platforms oETCS ) ;
int TrackToTrain_Packet_070 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_TrackToTrain_Route_Suitability_Data oETCS ) ;
int TrackToTrain_Packet_071 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_TrackToTrain_Adhesion_Factor oETCS ) ;
int TrackToTrain_Packet_072 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_TrackToTrain_Packet_for_sending_plain_text_messages oETCS ) ;
int TrackToTrain_Packet_076 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_TrackToTrain_Packet_for_sending_fixed_text_messages oETCS ) ;
int TrackToTrain_Packet_079 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_TrackToTrain_Geographical_Position_Information oETCS ) ;
int TrackToTrain_Packet_080 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_TrackToTrain_Mode_profile oETCS ) ;
int TrackToTrain_Packet_088 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_TrackToTrain_Level_Crossing_information oETCS ) ;
int TrackToTrain_Packet_090 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_TrackToTrain_Track_Ahead_Free_up_to_level_23_transition_location oETCS ) ;
int TrackToTrain_Packet_131 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_TrackToTrain_RBC_transition_order oETCS ) ;
int TrackToTrain_Packet_132 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_TrackToTrain_Danger_for_Shunting_information oETCS ) ;
int TrackToTrain_Packet_133 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_TrackToTrain_Radio_infill_area_information oETCS ) ;
int TrackToTrain_Packet_134 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_TrackToTrain_EOLM_Packet oETCS ) ;
int TrackToTrain_Packet_135 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_TrackToTrain_Stop_Shunting_on_desk_opening oETCS ) ;
int TrackToTrain_Packet_136 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_TrackToTrain_Infill_location_reference oETCS ) ;
int TrackToTrain_Packet_137 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_TrackToTrain_Stop_if_in_Staff_Responsible oETCS ) ;
int TrackToTrain_Packet_138 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_TrackToTrain_Reversing_area_information oETCS ) ;
int TrackToTrain_Packet_139 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_TrackToTrain_Reversing_supervision_information oETCS ) ;
int TrackToTrain_Packet_140 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_TrackToTrain_Train_running_number_from_RBC oETCS ) ;
int TrackToTrain_Packet_141 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_TrackToTrain_Default_Gradient_for_Temporary_Speed_Restriction oETCS ) ;
int TrackToTrain_Packet_143 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_TrackToTrain_Session_Management_with_neighbouring_Radio_Infill_Unit oETCS ) ;
int TrackToTrain_Packet_145 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_TrackToTrain_Inhibition_of_balise_group_message_consistency_reaction oETCS ) ;
int TrackToTrain_Packet_254 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_TrackToTrain_Default_balise_or_Loop_or_RIU_information oETCS ) ;
int TrainToTrack_Packet_000 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_TrainToTrack_Position_Report oETCS ) ;
int TrainToTrack_Packet_001 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_TrainToTrack_Position_Report_based_on_two_balise_groups oETCS ) ;
int TrainToTrack_Packet_003 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_TrainToTrack_Onboard_telephone_numbers oETCS ) ;
int TrainToTrack_Packet_004 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_TrainToTrack_Error_Reporting oETCS ) ;
int TrainToTrack_Packet_005 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_TrainToTrack_Train_running_number oETCS ) ;
int TrainToTrack_Packet_009 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_TrainToTrack_Level_23_transition_information oETCS ) ;
int TrainToTrack_Packet_011 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_TrainToTrack_Validated_train_data oETCS ) ;
int TrainToTrack_Packet_044 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_TrainToTrack_Data_used_by_applications_outside_the_ERTMS_or_ETCS_system oETCS ) ;
int BothWays_Packet_255 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_BothWays_End_of_Information oETCS ) ;

int TrackToTrain_PackageDecoder(void* Stream, int FirstBitPos, oETCS_Union* oETCS);
int TrainToTrack_PackageDecoder(void* Stream, int FirstBitPos, oETCS_Union* oETCS);
int     BothWays_PackageDecoder(void* Stream, int FirstBitPos, oETCS_Union* oETCS);
    
