#ifndef NESTINGMARK_Radio_DecoderBranch8H
#define NESTINGMARK_Radio_DecoderBranch8H


/* 
=============================================================================
Formalization of Subset-026-8 (Chapter 8: ERTMS/ETCS language)

- Name: Subset-026-8 / Radio_DecoderBranch8.h
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

    
typedef enum    
{
    E_DATA_Radio_undefined    = -1,
    E_DATA_Radio_TrackToTrain =  1,
    E_DATA_Radio_TrainToTrack =  2

} Radio_Namespace;

typedef enum    
{
    E_DATA_Radio_TrainToTrack_undefined                                               = -1,
	E_DATA_Radio_TrainToTrack_Validated_Train_Data                                    = 129,
	E_DATA_Radio_TrainToTrack_Request_for_Shunting                                    = 130,
	E_DATA_Radio_TrainToTrack_MA_Request                                              = 132,
	E_DATA_Radio_TrainToTrack_Train_Position_Report                                   = 136,
	E_DATA_Radio_TrainToTrack_Request_to_shorten_MA_is_granted                        = 137,
	E_DATA_Radio_TrainToTrack_Request_to_shorten_MA_is_rejected                       = 138,
	E_DATA_Radio_TrainToTrack_Acknowledgement                                         = 146,
	E_DATA_Radio_TrainToTrack_Acknowledgement_of_Emergency_Stop                       = 147,
	E_DATA_Radio_TrainToTrack_Track_Ahead_Free_Granted                                = 149,
	E_DATA_Radio_TrainToTrack_End_of_Mission                                          = 150,
	E_DATA_Radio_TrainToTrack_Radio_infill_request                                    = 153,
	E_DATA_Radio_TrainToTrack_No_compatible_version_supported                         = 154,
	E_DATA_Radio_TrainToTrack_Initiation_of_a_communication_session                   = 155,
	E_DATA_Radio_TrainToTrack_Termination_of_a_communication_session                  = 156,
	E_DATA_Radio_TrainToTrack_SoM_Position_Report                                     = 157,
	E_DATA_Radio_TrainToTrack_Text_message_acknowledged_by_driver                     = 158,
	E_DATA_Radio_TrainToTrack_Session_Established                                     = 159
} Radio_TypeNamesTrainToTrack;

typedef enum    
{
    E_DATA_Radio_TrackToTrain_undefined                                               = -1,
	E_DATA_Radio_TrackToTrain_SR_Authorisation                                        = 2,
	E_DATA_Radio_TrackToTrain_Movement_Authority                                      = 3,
	E_DATA_Radio_TrackToTrain_Recognition_of_exit_from_TRIP_mode                      = 6,
	E_DATA_Radio_TrackToTrain_Acknowledgement_of_Train_Data                           = 8,
	E_DATA_Radio_TrackToTrain_Request_to_Shorten_MA                                   = 9,
	E_DATA_Radio_TrackToTrain_Conditional_Emergency_Stop                              = 15,
	E_DATA_Radio_TrackToTrain_Unconditional_Emergency_Stop                            = 16,
	E_DATA_Radio_TrackToTrain_Revocation_of_Emergency_Stop                            = 18,
	E_DATA_Radio_TrackToTrain_General_message                                         = 24,
	E_DATA_Radio_TrackToTrain_SH_Refused                                              = 27,
	E_DATA_Radio_TrackToTrain_SH_Authorised                                           = 28,
	E_DATA_Radio_TrackToTrain_RBC_or_RIU_System_Version                               = 32,
	E_DATA_Radio_TrackToTrain_MA_with_Shifted_Location_Reference                      = 33,
	E_DATA_Radio_TrackToTrain_Track_Ahead_Free_Request                                = 34,
	E_DATA_Radio_TrackToTrain_Infill_MA                                               = 37,
	E_DATA_Radio_TrackToTrain_Initiation_of_a_communication_session                   = 38,
	E_DATA_Radio_TrackToTrain_Acknowledgement_of_termination_of_a_communication_session = 39,
	E_DATA_Radio_TrackToTrain_Train_Rejected                                          = 40,
	E_DATA_Radio_TrackToTrain_Train_Accepted                                          = 41,
	E_DATA_Radio_TrackToTrain_SoM_position_report_confirmed_by_RBC                    = 43,
	E_DATA_Radio_TrackToTrain_Assignment_of_coordinate_system                         = 45
} Radio_TypeNamesTrackToTrain;


typedef struct  
{   
    Radio_TypeNamesTrackToTrain MessTrackToTrain;
    Radio_TypeNamesTrainToTrack MessTrainToTrack;    
    Radio_Namespace             MessNameSpace;
    
	struct DATA_Radio_TrackToTrain_SR_Authorisation                                          TrackM_002;
	struct DATA_Radio_TrackToTrain_Movement_Authority                                        TrackM_003;
	struct DATA_Radio_TrackToTrain_Recognition_of_exit_from_TRIP_mode                        TrackM_006;
	struct DATA_Radio_TrackToTrain_Acknowledgement_of_Train_Data                             TrackM_008;
	struct DATA_Radio_TrackToTrain_Request_to_Shorten_MA                                     TrackM_009;
	struct DATA_Radio_TrackToTrain_Conditional_Emergency_Stop                                TrackM_015;
	struct DATA_Radio_TrackToTrain_Unconditional_Emergency_Stop                              TrackM_016;
	struct DATA_Radio_TrackToTrain_Revocation_of_Emergency_Stop                              TrackM_018;
	struct DATA_Radio_TrackToTrain_General_message                                           TrackM_024;
	struct DATA_Radio_TrackToTrain_SH_Refused                                                TrackM_027;
	struct DATA_Radio_TrackToTrain_SH_Authorised                                             TrackM_028;
	struct DATA_Radio_TrackToTrain_RBC_or_RIU_System_Version                                 TrackM_032;
	struct DATA_Radio_TrackToTrain_MA_with_Shifted_Location_Reference                        TrackM_033;
	struct DATA_Radio_TrackToTrain_Track_Ahead_Free_Request                                  TrackM_034;
	struct DATA_Radio_TrackToTrain_Infill_MA                                                 TrackM_037;
	struct DATA_Radio_TrackToTrain_Initiation_of_a_communication_session                     TrackM_038;
	struct DATA_Radio_TrackToTrain_Acknowledgement_of_termination_of_a_communication_session   TrackM_039;
	struct DATA_Radio_TrackToTrain_Train_Rejected                                            TrackM_040;
	struct DATA_Radio_TrackToTrain_Train_Accepted                                            TrackM_041;
	struct DATA_Radio_TrackToTrain_SoM_position_report_confirmed_by_RBC                      TrackM_043;
	struct DATA_Radio_TrackToTrain_Assignment_of_coordinate_system                           TrackM_045;
	struct DATA_Radio_TrainToTrack_Validated_Train_Data                                      TrainM_129;
	struct DATA_Radio_TrainToTrack_Request_for_Shunting                                      TrainM_130;
	struct DATA_Radio_TrainToTrack_MA_Request                                                TrainM_132;
	struct DATA_Radio_TrainToTrack_Train_Position_Report                                     TrainM_136;
	struct DATA_Radio_TrainToTrack_Request_to_shorten_MA_is_granted                          TrainM_137;
	struct DATA_Radio_TrainToTrack_Request_to_shorten_MA_is_rejected                         TrainM_138;
	struct DATA_Radio_TrainToTrack_Acknowledgement                                           TrainM_146;
	struct DATA_Radio_TrainToTrack_Acknowledgement_of_Emergency_Stop                         TrainM_147;
	struct DATA_Radio_TrainToTrack_Track_Ahead_Free_Granted                                  TrainM_149;
	struct DATA_Radio_TrainToTrack_End_of_Mission                                            TrainM_150;
	struct DATA_Radio_TrainToTrack_Radio_infill_request                                      TrainM_153;
	struct DATA_Radio_TrainToTrack_No_compatible_version_supported                           TrainM_154;
	struct DATA_Radio_TrainToTrack_Initiation_of_a_communication_session                     TrainM_155;
	struct DATA_Radio_TrainToTrack_Termination_of_a_communication_session                    TrainM_156;
	struct DATA_Radio_TrainToTrack_SoM_Position_Report                                       TrainM_157;
	struct DATA_Radio_TrainToTrack_Text_message_acknowledged_by_driver                       TrainM_158;
	struct DATA_Radio_TrainToTrack_Session_Established                                       TrainM_159;

} Radio_Union;

#endif
    
