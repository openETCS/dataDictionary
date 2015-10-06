#ifndef NESTINGMARK_oETCS_DecoderBranchH
#define NESTINGMARK_oETCS_DecoderBranchH

typedef enum    
{
    E_DATA_oETCS_undefined    = -1,
    E_DATA_oETCS_TrackToTrain =  1,
    E_DATA_oETCS_TrainToTrack =  2,
    E_DATA_oETCS_BothWays     =  3
} oETCS_Namespace;

typedef enum    
{
    E_DATA_oETCS_TrackToTrain_undefined                                               = -1,
	E_DATA_oETCS_TrackToTrain_Virtual_Balise_Cover_marker                             = 0,
	E_DATA_oETCS_TrackToTrain_System_Version_order                                    = 2,
	E_DATA_oETCS_TrackToTrain_National_Values                                         = 3,
	E_DATA_oETCS_TrackToTrain_Linking                                                 = 5,
	E_DATA_oETCS_TrackToTrain_Virtual_Balise_Cover_order                              = 6,
	E_DATA_oETCS_TrackToTrain_Level_1_Movement_Authority                              = 12,
	E_DATA_oETCS_TrackToTrain_Staff_Responsible_distance_Information_from_loop        = 13,
	E_DATA_oETCS_TrackToTrain_Level_23_Movement_Authority                             = 15,
	E_DATA_oETCS_TrackToTrain_Repositioning_Information                               = 16,
	E_DATA_oETCS_TrackToTrain_Gradient_Profile                                        = 21,
	E_DATA_oETCS_TrackToTrain_International_Static_Speed_Profile                      = 27,
	E_DATA_oETCS_TrackToTrain_Track_Condition_Change_of_traction_system               = 39,
	E_DATA_oETCS_TrackToTrain_Track_Condition_Change_of_allowed_current_consumption   = 40,
	E_DATA_oETCS_TrackToTrain_Level_Transition_Order                                  = 41,
	E_DATA_oETCS_TrackToTrain_Session_Management                                      = 42,
	E_DATA_oETCS_TrackToTrain_Radio_Network_registration                              = 45,
	E_DATA_oETCS_TrackToTrain_Conditional_Level_Transition_Order                      = 46,
	E_DATA_oETCS_TrackToTrain_List_of_balises_for_SH_Area                             = 49,
	E_DATA_oETCS_TrackToTrain_Axle_Load_Speed_Profile                                 = 51,
	E_DATA_oETCS_TrackToTrain_Permitted_Braking_Distance_Information                  = 52,
	E_DATA_oETCS_TrackToTrain_Movement_Authority_Request_Parameters                   = 57,
	E_DATA_oETCS_TrackToTrain_Position_Report_Parameters                              = 58,
	E_DATA_oETCS_TrackToTrain_List_of_Balises_in_SR_Authority                         = 63,
	E_DATA_oETCS_TrackToTrain_Inhibition_of_revocable_TSRs_from_balises_in_L23        = 64,
	E_DATA_oETCS_TrackToTrain_Temporary_Speed_Restriction                             = 65,
	E_DATA_oETCS_TrackToTrain_Temporary_Speed_Restriction_Revocation                  = 66,
	E_DATA_oETCS_TrackToTrain_Track_Condition_Big_Metal_Masses                        = 67,
	E_DATA_oETCS_TrackToTrain_Track_Condition                                         = 68,
	E_DATA_oETCS_TrackToTrain_Track_Condition_Station_Platforms                       = 69,
	E_DATA_oETCS_TrackToTrain_Route_Suitability_Data                                  = 70,
	E_DATA_oETCS_TrackToTrain_Adhesion_Factor                                         = 71,
	E_DATA_oETCS_TrackToTrain_Packet_for_sending_plain_text_messages                  = 72,
	E_DATA_oETCS_TrackToTrain_Packet_for_sending_fixed_text_messages                  = 76,
	E_DATA_oETCS_TrackToTrain_Geographical_Position_Information                       = 79,
	E_DATA_oETCS_TrackToTrain_Mode_profile                                            = 80,
	E_DATA_oETCS_TrackToTrain_Level_Crossing_information                              = 88,
	E_DATA_oETCS_TrackToTrain_Track_Ahead_Free_up_to_level_23_transition_location     = 90,
	E_DATA_oETCS_TrackToTrain_RBC_transition_order                                    = 131,
	E_DATA_oETCS_TrackToTrain_Danger_for_Shunting_information                         = 132,
	E_DATA_oETCS_TrackToTrain_Radio_infill_area_information                           = 133,
	E_DATA_oETCS_TrackToTrain_EOLM_Packet                                             = 134,
	E_DATA_oETCS_TrackToTrain_Stop_Shunting_on_desk_opening                           = 135,
	E_DATA_oETCS_TrackToTrain_Infill_location_reference                               = 136,
	E_DATA_oETCS_TrackToTrain_Stop_if_in_Staff_Responsible                            = 137,
	E_DATA_oETCS_TrackToTrain_Reversing_area_information                              = 138,
	E_DATA_oETCS_TrackToTrain_Reversing_supervision_information                       = 139,
	E_DATA_oETCS_TrackToTrain_Train_running_number_from_RBC                           = 140,
	E_DATA_oETCS_TrackToTrain_Default_Gradient_for_Temporary_Speed_Restriction        = 141,
	E_DATA_oETCS_TrackToTrain_Session_Management_with_neighbouring_Radio_Infill_Unit  = 143,
	E_DATA_oETCS_TrackToTrain_Inhibition_of_balise_group_message_consistency_reaction = 145,
	E_DATA_oETCS_TrackToTrain_Default_balise_or_Loop_or_RIU_information               = 254
} oETCS_TypeNamesTrackToTrain;

typedef enum    
{
    E_DATA_oETCS_TrainToTrack_undefined                                               = -1,
	E_DATA_oETCS_TrainToTrack_Position_Report                                         = 0,
	E_DATA_oETCS_TrainToTrack_Position_Report_based_on_two_balise_groups              = 1,
	E_DATA_oETCS_TrainToTrack_Onboard_telephone_numbers                               = 3,
	E_DATA_oETCS_TrainToTrack_Error_Reporting                                         = 4,
	E_DATA_oETCS_TrainToTrack_Train_running_number                                    = 5,
	E_DATA_oETCS_TrainToTrack_Level_23_transition_information                         = 9,
	E_DATA_oETCS_TrainToTrack_Validated_train_data                                    = 11
} oETCS_TypeNamesTrainToTrack;

typedef enum    
{
    E_DATA_oETCS_BothWays_undefined                                               = -1,
	E_DATA_oETCS_BothWays_End_of_Information                                      = 255
} oETCS_TypeNamesBothWays;


typedef struct  
{   
    oETCS_TypeNamesTrackToTrain TlgTrackToTrain;
    oETCS_TypeNamesTrainToTrack TlgTrainToTrack;    
    oETCS_TypeNamesBothWays     TlgBothWays;
    oETCS_Namespace             NameSpace;
    
	struct DATA_oETCS_TrackToTrain_Virtual_Balise_Cover_marker                               TrackP_000;
	struct DATA_oETCS_TrackToTrain_System_Version_order                                      TrackP_002;
	struct DATA_oETCS_TrackToTrain_National_Values                                           TrackP_003;
	struct DATA_oETCS_TrackToTrain_Linking                                                   TrackP_005;
	struct DATA_oETCS_TrackToTrain_Virtual_Balise_Cover_order                                TrackP_006;
	struct DATA_oETCS_TrackToTrain_Level_1_Movement_Authority                                TrackP_012;
	struct DATA_oETCS_TrackToTrain_Staff_Responsible_distance_Information_from_loop          TrackP_013;
	struct DATA_oETCS_TrackToTrain_Level_23_Movement_Authority                               TrackP_015;
	struct DATA_oETCS_TrackToTrain_Repositioning_Information                                 TrackP_016;
	struct DATA_oETCS_TrackToTrain_Gradient_Profile                                          TrackP_021;
	struct DATA_oETCS_TrackToTrain_International_Static_Speed_Profile                        TrackP_027;
	struct DATA_oETCS_TrackToTrain_Track_Condition_Change_of_traction_system                 TrackP_039;
	struct DATA_oETCS_TrackToTrain_Track_Condition_Change_of_allowed_current_consumption     TrackP_040;
	struct DATA_oETCS_TrackToTrain_Level_Transition_Order                                    TrackP_041;
	struct DATA_oETCS_TrackToTrain_Session_Management                                        TrackP_042;
	struct DATA_oETCS_TrackToTrain_Radio_Network_registration                                TrackP_045;
	struct DATA_oETCS_TrackToTrain_Conditional_Level_Transition_Order                        TrackP_046;
	struct DATA_oETCS_TrackToTrain_List_of_balises_for_SH_Area                               TrackP_049;
	struct DATA_oETCS_TrackToTrain_Axle_Load_Speed_Profile                                   TrackP_051;
	struct DATA_oETCS_TrackToTrain_Permitted_Braking_Distance_Information                    TrackP_052;
	struct DATA_oETCS_TrackToTrain_Movement_Authority_Request_Parameters                     TrackP_057;
	struct DATA_oETCS_TrackToTrain_Position_Report_Parameters                                TrackP_058;
	struct DATA_oETCS_TrackToTrain_List_of_Balises_in_SR_Authority                           TrackP_063;
	struct DATA_oETCS_TrackToTrain_Inhibition_of_revocable_TSRs_from_balises_in_L23          TrackP_064;
	struct DATA_oETCS_TrackToTrain_Temporary_Speed_Restriction                               TrackP_065;
	struct DATA_oETCS_TrackToTrain_Temporary_Speed_Restriction_Revocation                    TrackP_066;
	struct DATA_oETCS_TrackToTrain_Track_Condition_Big_Metal_Masses                          TrackP_067;
	struct DATA_oETCS_TrackToTrain_Track_Condition                                           TrackP_068;
	struct DATA_oETCS_TrackToTrain_Track_Condition_Station_Platforms                         TrackP_069;
	struct DATA_oETCS_TrackToTrain_Route_Suitability_Data                                    TrackP_070;
	struct DATA_oETCS_TrackToTrain_Adhesion_Factor                                           TrackP_071;
	struct DATA_oETCS_TrackToTrain_Packet_for_sending_plain_text_messages                    TrackP_072;
	struct DATA_oETCS_TrackToTrain_Packet_for_sending_fixed_text_messages                    TrackP_076;
	struct DATA_oETCS_TrackToTrain_Geographical_Position_Information                         TrackP_079;
	struct DATA_oETCS_TrackToTrain_Mode_profile                                              TrackP_080;
	struct DATA_oETCS_TrackToTrain_Level_Crossing_information                                TrackP_088;
	struct DATA_oETCS_TrackToTrain_Track_Ahead_Free_up_to_level_23_transition_location       TrackP_090;
	struct DATA_oETCS_TrackToTrain_RBC_transition_order                                      TrackP_131;
	struct DATA_oETCS_TrackToTrain_Danger_for_Shunting_information                           TrackP_132;
	struct DATA_oETCS_TrackToTrain_Radio_infill_area_information                             TrackP_133;
	struct DATA_oETCS_TrackToTrain_EOLM_Packet                                               TrackP_134;
	struct DATA_oETCS_TrackToTrain_Stop_Shunting_on_desk_opening                             TrackP_135;
	struct DATA_oETCS_TrackToTrain_Infill_location_reference                                 TrackP_136;
	struct DATA_oETCS_TrackToTrain_Stop_if_in_Staff_Responsible                              TrackP_137;
	struct DATA_oETCS_TrackToTrain_Reversing_area_information                                TrackP_138;
	struct DATA_oETCS_TrackToTrain_Reversing_supervision_information                         TrackP_139;
	struct DATA_oETCS_TrackToTrain_Train_running_number_from_RBC                             TrackP_140;
	struct DATA_oETCS_TrackToTrain_Default_Gradient_for_Temporary_Speed_Restriction          TrackP_141;
	struct DATA_oETCS_TrackToTrain_Session_Management_with_neighbouring_Radio_Infill_Unit    TrackP_143;
	struct DATA_oETCS_TrackToTrain_Inhibition_of_balise_group_message_consistency_reaction   TrackP_145;
	struct DATA_oETCS_TrackToTrain_Default_balise_or_Loop_or_RIU_information                 TrackP_254;
	struct DATA_oETCS_TrainToTrack_Position_Report                                           TrainP_000;
	struct DATA_oETCS_TrainToTrack_Position_Report_based_on_two_balise_groups                TrainP_001;
	struct DATA_oETCS_TrainToTrack_Onboard_telephone_numbers                                 TrainP_003;
	struct DATA_oETCS_TrainToTrack_Error_Reporting                                           TrainP_004;
	struct DATA_oETCS_TrainToTrack_Train_running_number                                      TrainP_005;
	struct DATA_oETCS_TrainToTrack_Level_23_transition_information                           TrainP_009;
	struct DATA_oETCS_TrainToTrack_Validated_train_data                                      TrainP_011;
	struct DATA_oETCS_BothWays_End_of_Information                                        BothWP_255;

} oETCS_Union;

#endif
    
