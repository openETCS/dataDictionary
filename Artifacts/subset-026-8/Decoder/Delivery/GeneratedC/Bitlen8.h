
/* 
=============================================================================
Formalization of Subset-026-8 (Chapter 8: ERTMS/ETCS language)

- Name: Subset-026-8 / Bitlen8.h
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

    const char         a_Var_Namen_Request_to_Shorten_MA[] = { "NID_MESSAGE", "L_MESSAGE", "T_TRAIN", "M_ACK", "NID_LRBG", "PADDING14" };
    const unsigned int a_Bit_Laeng_Request_to_Shorten_MA[] = { 8, 10, 32, 1, 24, 5 }; 
    const unsigned int a_Start_Bit_Request_to_Shorten_MA[] = { 0, 8, 18, 50, 51, 75 };
// ================

    const char         a_Var_Namen_Acknowledgement[] = { "NID_MESSAGE", "L_MESSAGE", "T_TRAIN", "NID_ENGINE" };
    const unsigned int a_Bit_Laeng_Acknowledgement[] = { 8, 10, 32, 24 }; 
    const unsigned int a_Start_Bit_Acknowledgement[] = { 0, 8, 18, 50 };
// ================

    const char         a_Var_Namen_SoM_Position_Report[] = { "NID_MESSAGE", "L_MESSAGE", "T_TRAIN", "NID_ENGINE", "Q_STATUS", "PADDING9" };
    const unsigned int a_Bit_Laeng_SoM_Position_Report[] = { 8, 10, 32, 24, 2, 4 }; 
    const unsigned int a_Start_Bit_SoM_Position_Report[] = { 0, 8, 18, 50, 74, 76 };
// ================

    const char         a_Var_Namen_MA_with_Shifted_Location_Reference[] = { "NID_MESSAGE", "L_MESSAGE", "T_TRAIN", "M_ACK", "NID_LRBG", "Q_SCALE", "D_REF", "PADDING17" };
    const unsigned int a_Bit_Laeng_MA_with_Shifted_Location_Reference[] = { 8, 10, 32, 1, 24, 2, 16, 3 }; 
    const unsigned int a_Start_Bit_MA_with_Shifted_Location_Reference[] = { 0, 8, 18, 50, 51, 75, 77, 93 };
// ================

    const char         a_Var_Namen_Text_message_acknowledged_by_driver[] = { "NID_MESSAGE", "L_MESSAGE", "T_TRAIN", "NID_ENGINE", "NID_TEXTMESSAGE", "PADDING10" };
    const unsigned int a_Bit_Laeng_Text_message_acknowledged_by_driver[] = { 8, 10, 32, 24, 8, 6 }; 
    const unsigned int a_Start_Bit_Text_message_acknowledged_by_driver[] = { 0, 8, 18, 50, 74, 82 };
// ================

    const char         a_Var_Namen_SH_Authorised[] = { "NID_MESSAGE", "L_MESSAGE", "T_TRAIN0", "M_ACK", "NID_LRBG", "T_TRAIN1", "PADDING16" };
    const unsigned int a_Bit_Laeng_SH_Authorised[] = { 8, 10, 32, 1, 24, 32, 5 }; 
    const unsigned int a_Start_Bit_SH_Authorised[] = { 0, 8, 18, 50, 51, 75, 107 };
// ================

    const char         a_Var_Namen_Termination_of_a_communication_session[] = { "NID_MESSAGE", "L_MESSAGE", "T_TRAIN", "NID_ENGINE" };
    const unsigned int a_Bit_Laeng_Termination_of_a_communication_session[] = { 8, 10, 32, 24 }; 
    const unsigned int a_Start_Bit_Termination_of_a_communication_session[] = { 0, 8, 18, 50 };
// ================

    const char         a_Var_Namen_MA_Request[] = { "NID_MESSAGE", "L_MESSAGE", "T_TRAIN", "NID_ENGINE", "Q_MARQSTREASON", "PADDING2" };
    const unsigned int a_Bit_Laeng_MA_Request[] = { 8, 10, 32, 24, 5, 1 }; 
    const unsigned int a_Start_Bit_MA_Request[] = { 0, 8, 18, 50, 74, 79 };
// ================

    const char         a_Var_Namen_Infill_MA[] = { "NID_MESSAGE", "L_MESSAGE", "T_TRAIN", "M_ACK", "NID_LRBG", "PADDING18" };
    const unsigned int a_Bit_Laeng_Infill_MA[] = { 8, 10, 32, 1, 24, 5 }; 
    const unsigned int a_Start_Bit_Infill_MA[] = { 0, 8, 18, 50, 51, 75 };
// ================

    const char         a_Var_Namen_General_message[] = { "NID_MESSAGE", "L_MESSAGE", "T_TRAIN", "M_ACK", "NID_LRBG", "PADDING15" };
    const unsigned int a_Bit_Laeng_General_message[] = { 8, 10, 32, 1, 24, 5 }; 
    const unsigned int a_Start_Bit_General_message[] = { 0, 8, 18, 50, 51, 75 };
// ================

    const char         a_Var_Namen_Request_for_Shunting[] = { "NID_MESSAGE", "L_MESSAGE", "T_TRAIN", "NID_ENGINE", "PADDING1" };
    const unsigned int a_Bit_Laeng_Request_for_Shunting[] = { 8, 10, 32, 24, 6 }; 
    const unsigned int a_Start_Bit_Request_for_Shunting[] = { 0, 8, 18, 50, 74 };
// ================

    const char         a_Var_Namen_Train_Position_Report[] = { "NID_MESSAGE", "L_MESSAGE", "T_TRAIN", "NID_ENGINE", "PADDING3" };
    const unsigned int a_Bit_Laeng_Train_Position_Report[] = { 8, 10, 32, 24, 6 }; 
    const unsigned int a_Start_Bit_Train_Position_Report[] = { 0, 8, 18, 50, 74 };
// ================

    const char         a_Var_Namen_RBC_or_RIU_System_Version[] = { "NID_MESSAGE", "L_MESSAGE", "T_TRAIN", "M_ACK", "NID_LRBG", "M_VERSION" };
    const unsigned int a_Bit_Laeng_RBC_or_RIU_System_Version[] = { 8, 10, 32, 1, 24, 7 }; 
    const unsigned int a_Start_Bit_RBC_or_RIU_System_Version[] = { 0, 8, 18, 50, 51, 75 };
// ================

    const char         a_Var_Namen_Acknowledgement_of_Train_Data[] = { "NID_MESSAGE", "L_MESSAGE", "T_TRAIN0", "M_ACK", "NID_LRBG", "T_TRAIN1" };
    const unsigned int a_Bit_Laeng_Acknowledgement_of_Train_Data[] = { 8, 10, 32, 1, 24, 32 }; 
    const unsigned int a_Start_Bit_Acknowledgement_of_Train_Data[] = { 0, 8, 18, 50, 51, 75 };
// ================

    const char         a_Var_Namen_Acknowledgement_of_termination_of_a_communication_session[] = { "NID_MESSAGE", "L_MESSAGE", "T_TRAIN", "M_ACK", "NID_LRBG" };
    const unsigned int a_Bit_Laeng_Acknowledgement_of_termination_of_a_communication_session[] = { 8, 10, 32, 1, 24 }; 
    const unsigned int a_Start_Bit_Acknowledgement_of_termination_of_a_communication_session[] = { 0, 8, 18, 50, 51 };
// ================

    const char         a_Var_Namen_Session_Established[] = { "NID_MESSAGE", "L_MESSAGE", "T_TRAIN", "NID_ENGINE", "PADDING11" };
    const unsigned int a_Bit_Laeng_Session_Established[] = { 8, 10, 32, 24, 6 }; 
    const unsigned int a_Start_Bit_Session_Established[] = { 0, 8, 18, 50, 74 };
// ================

    const char         a_Var_Namen_Validated_Train_Data[] = { "NID_MESSAGE", "L_MESSAGE", "T_TRAIN", "NID_ENGINE", "PADDING0" };
    const unsigned int a_Bit_Laeng_Validated_Train_Data[] = { 8, 10, 32, 24, 6 }; 
    const unsigned int a_Start_Bit_Validated_Train_Data[] = { 0, 8, 18, 50, 74 };
// ================

    const char         a_Var_Namen_Recognition_of_exit_from_TRIP_mode[] = { "NID_MESSAGE", "L_MESSAGE", "T_TRAIN", "M_ACK", "NID_LRBG" };
    const unsigned int a_Bit_Laeng_Recognition_of_exit_from_TRIP_mode[] = { 8, 10, 32, 1, 24 }; 
    const unsigned int a_Start_Bit_Recognition_of_exit_from_TRIP_mode[] = { 0, 8, 18, 50, 51 };
// ================

    const char         a_Var_Namen_Request_to_shorten_MA_is_rejected[] = { "NID_MESSAGE", "L_MESSAGE", "T_TRAIN", "NID_ENGINE", "PADDING5" };
    const unsigned int a_Bit_Laeng_Request_to_shorten_MA_is_rejected[] = { 8, 10, 32, 24, 6 }; 
    const unsigned int a_Start_Bit_Request_to_shorten_MA_is_rejected[] = { 0, 8, 18, 50, 74 };
// ================

    const char         a_Var_Namen_Train_Accepted[] = { "NID_MESSAGE", "L_MESSAGE", "T_TRAIN", "M_ACK", "NID_LRBG" };
    const unsigned int a_Bit_Laeng_Train_Accepted[] = { 8, 10, 32, 1, 24 }; 
    const unsigned int a_Start_Bit_Train_Accepted[] = { 0, 8, 18, 50, 51 };
// ================

    const char         a_Var_Namen_SoM_position_report_confirmed_by_RBC[] = { "NID_MESSAGE", "L_MESSAGE", "T_TRAIN", "M_ACK", "NID_LRBG" };
    const unsigned int a_Bit_Laeng_SoM_position_report_confirmed_by_RBC[] = { 8, 10, 32, 1, 24 }; 
    const unsigned int a_Start_Bit_SoM_position_report_confirmed_by_RBC[] = { 0, 8, 18, 50, 51 };
// ================

    const char         a_Var_Namen_Track_Ahead_Free_Granted[] = { "NID_MESSAGE", "L_MESSAGE", "T_TRAIN", "NID_ENGINE", "PADDING6" };
    const unsigned int a_Bit_Laeng_Track_Ahead_Free_Granted[] = { 8, 10, 32, 24, 6 }; 
    const unsigned int a_Start_Bit_Track_Ahead_Free_Granted[] = { 0, 8, 18, 50, 74 };
// ================

    const char         a_Var_Namen_Track_Ahead_Free_Request[] = { "NID_MESSAGE", "L_MESSAGE", "T_TRAIN", "M_ACK", "NID_LRBG", "Q_SCALE", "D_REF", "Q_DIR", "D_TAFDISPLAY", "L_TAFDISPLAY" };
    const unsigned int a_Bit_Laeng_Track_Ahead_Free_Request[] = { 8, 10, 32, 1, 24, 2, 16, 2, 15, 15 }; 
    const unsigned int a_Start_Bit_Track_Ahead_Free_Request[] = { 0, 8, 18, 50, 51, 75, 77, 93, 95, 110 };
// ================

    const char         a_Var_Namen_Conditional_Emergency_Stop[] = { "NID_MESSAGE", "L_MESSAGE", "T_TRAIN", "M_ACK", "NID_LRBG", "NID_EM", "Q_SCALE", "D_REF", "Q_DIR", "D_EMERGENCYSTOP" };
    const unsigned int a_Bit_Laeng_Conditional_Emergency_Stop[] = { 8, 10, 32, 1, 24, 4, 2, 16, 2, 15 }; 
    const unsigned int a_Start_Bit_Conditional_Emergency_Stop[] = { 0, 8, 18, 50, 51, 75, 79, 81, 97, 99 };
// ================

    const char         a_Var_Namen_End_of_Mission[] = { "NID_MESSAGE", "L_MESSAGE", "T_TRAIN", "NID_ENGINE", "PADDING7" };
    const unsigned int a_Bit_Laeng_End_of_Mission[] = { 8, 10, 32, 24, 6 }; 
    const unsigned int a_Start_Bit_End_of_Mission[] = { 0, 8, 18, 50, 74 };
// ================

    const char         a_Var_Namen_Assignment_of_coordinate_system[] = { "NID_MESSAGE", "L_MESSAGE", "T_TRAIN", "M_ACK", "NID_LRBG", "Q_ORIENTATION" };
    const unsigned int a_Bit_Laeng_Assignment_of_coordinate_system[] = { 8, 10, 32, 1, 24, 1 }; 
    const unsigned int a_Start_Bit_Assignment_of_coordinate_system[] = { 0, 8, 18, 50, 51, 75 };
// ================

    const char         a_Var_Namen_SR_Authorisation[] = { "NID_MESSAGE", "L_MESSAGE", "T_TRAIN", "M_ACK", "NID_LRBG", "Q_SCALE", "D_SR", "PADDING12" };
    const unsigned int a_Bit_Laeng_SR_Authorisation[] = { 8, 10, 32, 1, 24, 2, 15, 4 }; 
    const unsigned int a_Start_Bit_SR_Authorisation[] = { 0, 8, 18, 50, 51, 75, 77, 92 };
// ================

    const char         a_Var_Namen_Initiation_of_a_communication_session[] = { "NID_MESSAGE", "L_MESSAGE", "T_TRAIN", "NID_ENGINE", "NID_MESSAGE", "L_MESSAGE", "T_TRAIN", "M_ACK", "NID_LRBG" };
    const unsigned int a_Bit_Laeng_Initiation_of_a_communication_session[] = { 8, 10, 32, 24, 8, 10, 32, 1, 24 }; 
    const unsigned int a_Start_Bit_Initiation_of_a_communication_session[] = { 0, 8, 18, 50, 0, 8, 18, 50, 51 };
// ================

    const char         a_Var_Namen_Movement_Authority[] = { "NID_MESSAGE", "L_MESSAGE", "T_TRAIN", "M_ACK", "NID_LRBG", "PADDING13" };
    const unsigned int a_Bit_Laeng_Movement_Authority[] = { 8, 10, 32, 1, 24, 5 }; 
    const unsigned int a_Start_Bit_Movement_Authority[] = { 0, 8, 18, 50, 51, 75 };
// ================

    const char         a_Var_Namen_Unconditional_Emergency_Stop[] = { "NID_MESSAGE", "L_MESSAGE", "T_TRAIN", "M_ACK", "NID_LRBG", "NID_EM" };
    const unsigned int a_Bit_Laeng_Unconditional_Emergency_Stop[] = { 8, 10, 32, 1, 24, 4 }; 
    const unsigned int a_Start_Bit_Unconditional_Emergency_Stop[] = { 0, 8, 18, 50, 51, 75 };
// ================

    const char         a_Var_Namen_No_compatible_version_supported[] = { "NID_MESSAGE", "L_MESSAGE", "T_TRAIN", "NID_ENGINE" };
    const unsigned int a_Bit_Laeng_No_compatible_version_supported[] = { 8, 10, 32, 24 }; 
    const unsigned int a_Start_Bit_No_compatible_version_supported[] = { 0, 8, 18, 50 };
// ================

    const char         a_Var_Namen_SH_Refused[] = { "NID_MESSAGE", "L_MESSAGE", "T_TRAIN0", "M_ACK", "NID_LRBG", "T_TRAIN1" };
    const unsigned int a_Bit_Laeng_SH_Refused[] = { 8, 10, 32, 1, 24, 32 }; 
    const unsigned int a_Start_Bit_SH_Refused[] = { 0, 8, 18, 50, 51, 75 };
// ================

    const char         a_Var_Namen_Revocation_of_Emergency_Stop[] = { "NID_MESSAGE", "L_MESSAGE", "T_TRAIN", "M_ACK", "NID_LRBG", "NID_EM" };
    const unsigned int a_Bit_Laeng_Revocation_of_Emergency_Stop[] = { 8, 10, 32, 1, 24, 4 }; 
    const unsigned int a_Start_Bit_Revocation_of_Emergency_Stop[] = { 0, 8, 18, 50, 51, 75 };
// ================

    const char         a_Var_Namen_Radio_infill_request[] = { "NID_MESSAGE", "L_MESSAGE", "T_TRAIN", "NID_ENGINE", "NID_C", "NID_BG", "Q_INFILL", "PADDING8" };
    const unsigned int a_Bit_Laeng_Radio_infill_request[] = { 8, 10, 32, 24, 10, 14, 1, 5 }; 
    const unsigned int a_Start_Bit_Radio_infill_request[] = { 0, 8, 18, 50, 74, 84, 98, 99 };
// ================

    const char         a_Var_Namen_Acknowledgement_of_Emergency_Stop[] = { "NID_MESSAGE", "L_MESSAGE", "T_TRAIN", "NID_ENGINE", "NID_EM", "Q_EMERGENCYSTOP" };
    const unsigned int a_Bit_Laeng_Acknowledgement_of_Emergency_Stop[] = { 8, 10, 32, 24, 4, 2 }; 
    const unsigned int a_Start_Bit_Acknowledgement_of_Emergency_Stop[] = { 0, 8, 18, 50, 74, 78 };
// ================

    const char         a_Var_Namen_Train_Rejected[] = { "NID_MESSAGE", "L_MESSAGE", "T_TRAIN", "M_ACK", "NID_LRBG" };
    const unsigned int a_Bit_Laeng_Train_Rejected[] = { 8, 10, 32, 1, 24 }; 
    const unsigned int a_Start_Bit_Train_Rejected[] = { 0, 8, 18, 50, 51 };
// ================

    const char         a_Var_Namen_Request_to_shorten_MA_is_granted[] = { "NID_MESSAGE", "L_MESSAGE", "T_TRAIN", "NID_ENGINE", "PADDING4" };
    const unsigned int a_Bit_Laeng_Request_to_shorten_MA_is_granted[] = { 8, 10, 32, 24, 6 }; 
    const unsigned int a_Start_Bit_Request_to_shorten_MA_is_granted[] = { 0, 8, 18, 50, 74 };
// ================

