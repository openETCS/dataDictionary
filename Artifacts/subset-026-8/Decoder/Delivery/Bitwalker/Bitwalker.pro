TEMPLATE = app
CONFIG += core console

SOURCES += main.c \
    Bitwalker.c \
    ../GeneratedC/Radio_Decoder.c \
    ../GeneratedC/Radio_DecoderBranch8.c \
    ../../../../SUBSET-026-7/Decoder/Delivery/GeneratedC/opnETCS_DecoderBranch.c \
    ../../../../SUBSET-026-7/Decoder/Delivery/GeneratedC/opnETCS_Decoder.c

INCLUDEPATH += ../GeneratedC \
    ../GeneratedC/Subset_Structs \
    ../../../../SUBSET-026-7/Decoder/Delivery/GeneratedC \
    ../../../../SUBSET-026-7/Decoder/Delivery/GeneratedC/Subset_Structs

HEADERS += Bitwalker.h \
    ../GeneratedC/Radio_DecoderBranch8.h \
    ../GeneratedC/Radio_Decoder.h \
    ../GeneratedC/Subset_Structs/subset026_8.h \
    ../GeneratedC/Subset_Structs/Radio_TrainToTrack_Validated_Train_Data.h \
    ../GeneratedC/Subset_Structs/Radio_TrainToTrack_Train_Position_Report.h \
    ../GeneratedC/Subset_Structs/Radio_TrainToTrack_Track_Ahead_Free_Granted.h \
    ../GeneratedC/Subset_Structs/Radio_TrainToTrack_Text_message_acknowledged_by_driver.h \
    ../GeneratedC/Subset_Structs/Radio_TrainToTrack_Termination_of_a_communication_session.h \
    ../GeneratedC/Subset_Structs/Radio_TrainToTrack_SoM_Position_Report.h \
    ../GeneratedC/Subset_Structs/Radio_TrainToTrack_Session_Established.h \
    ../GeneratedC/Subset_Structs/Radio_TrainToTrack_Request_to_shorten_MA_is_rejected.h \
    ../GeneratedC/Subset_Structs/Radio_TrainToTrack_Request_to_shorten_MA_is_granted.h \
    ../GeneratedC/Subset_Structs/Radio_TrainToTrack_Request_for_Shunting.h \
    ../GeneratedC/Subset_Structs/Radio_TrainToTrack_Radio_infill_request.h \
    ../GeneratedC/Subset_Structs/Radio_TrainToTrack_No_compatible_version_supported.h \
    ../GeneratedC/Subset_Structs/Radio_TrainToTrack_MA_Request.h \
    ../GeneratedC/Subset_Structs/Radio_TrainToTrack_Initiation_of_a_communication_session.h \
    ../GeneratedC/Subset_Structs/Radio_TrainToTrack_End_of_Mission.h \
    ../GeneratedC/Subset_Structs/Radio_TrainToTrack_Acknowledgement_of_Emergency_Stop.h \
    ../GeneratedC/Subset_Structs/Radio_TrainToTrack_Acknowledgement.h \
    ../GeneratedC/Subset_Structs/Radio_TrackToTrain_Unconditional_Emergency_Stop.h \
    ../GeneratedC/Subset_Structs/Radio_TrackToTrain_Train_Rejected.h \
    ../GeneratedC/Subset_Structs/Radio_TrackToTrain_Train_Accepted.h \
    ../GeneratedC/Subset_Structs/Radio_TrackToTrain_Track_Ahead_Free_Request.h \
    ../GeneratedC/Subset_Structs/Radio_TrackToTrain_SR_Authorisation.h \
    ../GeneratedC/Subset_Structs/Radio_TrackToTrain_SoM_position_report_confirmed_by_RBC.h \
    ../GeneratedC/Subset_Structs/Radio_TrackToTrain_SH_Refused.h \
    ../GeneratedC/Subset_Structs/Radio_TrackToTrain_SH_Authorised.h \
    ../GeneratedC/Subset_Structs/Radio_TrackToTrain_Revocation_of_Emergency_Stop.h \
    ../GeneratedC/Subset_Structs/Radio_TrackToTrain_Request_to_Shorten_MA.h \
    ../GeneratedC/Subset_Structs/Radio_TrackToTrain_Recognition_of_exit_from_TRIP_mode.h \
    ../GeneratedC/Subset_Structs/Radio_TrackToTrain_RBC_or_RIU_System_Version.h \
    ../GeneratedC/Subset_Structs/Radio_TrackToTrain_Movement_Authority.h \
    ../GeneratedC/Subset_Structs/Radio_TrackToTrain_MA_with_Shifted_Location_Reference.h \
    ../GeneratedC/Subset_Structs/Radio_TrackToTrain_Initiation_of_a_communication_session.h \
    ../GeneratedC/Subset_Structs/Radio_TrackToTrain_Infill_MA.h \
    ../GeneratedC/Subset_Structs/Radio_TrackToTrain_General_message.h \
    ../GeneratedC/Subset_Structs/Radio_TrackToTrain_Conditional_Emergency_Stop.h \
    ../GeneratedC/Subset_Structs/Radio_TrackToTrain_Assignment_of_coordinate_system.h \
    ../GeneratedC/Subset_Structs/Radio_TrackToTrain_Acknowledgement_of_Train_Data.h \
    ../GeneratedC/Subset_Structs/Radio_TrackToTrain_Acknowledgement_of_termination_of_a_communication_session.h \
    ../../../../SUBSET-026-7/Decoder/Delivery/GeneratedC/opnETCS_Variables.h \
    ../../../../SUBSET-026-7/Decoder/Delivery/GeneratedC/opnETCS_DecoderBranch.h \
    ../../../../SUBSET-026-7/Decoder/Delivery/GeneratedC/opnETCS_Decoder.h \
    ../../../../SUBSET-026-7/Decoder/Delivery/GeneratedC/Subset_Structs/Virtual_Balise_Cover_order.h \
    ../../../../SUBSET-026-7/Decoder/Delivery/GeneratedC/Subset_Structs/Virtual_Balise_Cover_marker.h \
    ../../../../SUBSET-026-7/Decoder/Delivery/GeneratedC/Subset_Structs/Validated_train_data.h \
    ../../../../SUBSET-026-7/Decoder/Delivery/GeneratedC/Subset_Structs/Train_running_number_from_RBC.h \
    ../../../../SUBSET-026-7/Decoder/Delivery/GeneratedC/Subset_Structs/Train_running_number.h \
    ../../../../SUBSET-026-7/Decoder/Delivery/GeneratedC/Subset_Structs/Track_Condition_Station_Platforms.h \
    ../../../../SUBSET-026-7/Decoder/Delivery/GeneratedC/Subset_Structs/Track_Condition_Change_of_traction_system.h \
    ../../../../SUBSET-026-7/Decoder/Delivery/GeneratedC/Subset_Structs/Track_Condition_Change_of_allowed_current_consumption.h \
    ../../../../SUBSET-026-7/Decoder/Delivery/GeneratedC/Subset_Structs/Track_Condition_Big_Metal_Masses.h \
    ../../../../SUBSET-026-7/Decoder/Delivery/GeneratedC/Subset_Structs/Track_Condition.h \
    ../../../../SUBSET-026-7/Decoder/Delivery/GeneratedC/Subset_Structs/Track_Ahead_Free_up_to_level_23_transition_location.h \
    ../../../../SUBSET-026-7/Decoder/Delivery/GeneratedC/Subset_Structs/Temporary_Speed_Restriction_Revocation.h \
    ../../../../SUBSET-026-7/Decoder/Delivery/GeneratedC/Subset_Structs/Temporary_Speed_Restriction.h \
    ../../../../SUBSET-026-7/Decoder/Delivery/GeneratedC/Subset_Structs/System_Version_order.h \
    ../../../../SUBSET-026-7/Decoder/Delivery/GeneratedC/Subset_Structs/Stop_Shunting_on_desk_opening.h \
    ../../../../SUBSET-026-7/Decoder/Delivery/GeneratedC/Subset_Structs/Stop_if_in_Staff_Responsible.h \
    ../../../../SUBSET-026-7/Decoder/Delivery/GeneratedC/Subset_Structs/Staff_Responsible_distance_Information_from_loop.h \
    ../../../../SUBSET-026-7/Decoder/Delivery/GeneratedC/Subset_Structs/Session_Management_with_neighbouring_Radio_Infill_Unit.h \
    ../../../../SUBSET-026-7/Decoder/Delivery/GeneratedC/Subset_Structs/Session_Management.h \
    ../../../../SUBSET-026-7/Decoder/Delivery/GeneratedC/Subset_Structs/Route_Suitability_Data.h \
    ../../../../SUBSET-026-7/Decoder/Delivery/GeneratedC/Subset_Structs/Reversing_supervision_information.h \
    ../../../../SUBSET-026-7/Decoder/Delivery/GeneratedC/Subset_Structs/Reversing_area_information.h \
    ../../../../SUBSET-026-7/Decoder/Delivery/GeneratedC/Subset_Structs/Repositioning_Information.h \
    ../../../../SUBSET-026-7/Decoder/Delivery/GeneratedC/Subset_Structs/RBC_transition_order.h \
    ../../../../SUBSET-026-7/Decoder/Delivery/GeneratedC/Subset_Structs/Radio_Network_registration.h \
    ../../../../SUBSET-026-7/Decoder/Delivery/GeneratedC/Subset_Structs/Radio_infill_area_information.h \
    ../../../../SUBSET-026-7/Decoder/Delivery/GeneratedC/Subset_Structs/Position_Report_Parameters.h \
    ../../../../SUBSET-026-7/Decoder/Delivery/GeneratedC/Subset_Structs/Position_Report_based_on_two_balise_groups.h \
    ../../../../SUBSET-026-7/Decoder/Delivery/GeneratedC/Subset_Structs/Position_Report.h \
    ../../../../SUBSET-026-7/Decoder/Delivery/GeneratedC/Subset_Structs/Permitted_Braking_Distance_Information.h \
    ../../../../SUBSET-026-7/Decoder/Delivery/GeneratedC/Subset_Structs/Packet_for_sending_plain_text_messages.h \
    ../../../../SUBSET-026-7/Decoder/Delivery/GeneratedC/Subset_Structs/Packet_for_sending_fixed_text_messages.h \
    ../../../../SUBSET-026-7/Decoder/Delivery/GeneratedC/Subset_Structs/Onboard_telephone_numbers.h \
    ../../../../SUBSET-026-7/Decoder/Delivery/GeneratedC/Subset_Structs/National_Values.h \
    ../../../../SUBSET-026-7/Decoder/Delivery/GeneratedC/Subset_Structs/Movement_Authority_Request_Parameters.h \
    ../../../../SUBSET-026-7/Decoder/Delivery/GeneratedC/Subset_Structs/Mode_profile.h \
    ../../../../SUBSET-026-7/Decoder/Delivery/GeneratedC/Subset_Structs/List_of_Balises_in_SR_Authority.h \
    ../../../../SUBSET-026-7/Decoder/Delivery/GeneratedC/Subset_Structs/List_of_balises_for_SH_Area.h \
    ../../../../SUBSET-026-7/Decoder/Delivery/GeneratedC/Subset_Structs/Linking.h \
    ../../../../SUBSET-026-7/Decoder/Delivery/GeneratedC/Subset_Structs/Level_Transition_Order.h \
    ../../../../SUBSET-026-7/Decoder/Delivery/GeneratedC/Subset_Structs/Level_Crossing_information.h \
    ../../../../SUBSET-026-7/Decoder/Delivery/GeneratedC/Subset_Structs/Level_23_transition_information.h \
    ../../../../SUBSET-026-7/Decoder/Delivery/GeneratedC/Subset_Structs/Level_23_Movement_Authority.h \
    ../../../../SUBSET-026-7/Decoder/Delivery/GeneratedC/Subset_Structs/Level_1_Movement_Authority.h \
    ../../../../SUBSET-026-7/Decoder/Delivery/GeneratedC/Subset_Structs/International_Static_Speed_Profile.h \
    ../../../../SUBSET-026-7/Decoder/Delivery/GeneratedC/Subset_Structs/Inhibition_of_revocable_TSRs_from_balises_in_L23.h \
    ../../../../SUBSET-026-7/Decoder/Delivery/GeneratedC/Subset_Structs/Inhibition_of_balise_group_message_consistency_reaction.h \
    ../../../../SUBSET-026-7/Decoder/Delivery/GeneratedC/Subset_Structs/Infill_location_reference.h \
    ../../../../SUBSET-026-7/Decoder/Delivery/GeneratedC/Subset_Structs/Gradient_Profile.h \
    ../../../../SUBSET-026-7/Decoder/Delivery/GeneratedC/Subset_Structs/Geographical_Position_Information.h \
    ../../../../SUBSET-026-7/Decoder/Delivery/GeneratedC/Subset_Structs/Error_Reporting.h \
    ../../../../SUBSET-026-7/Decoder/Delivery/GeneratedC/Subset_Structs/EOLM_Packet.h \
    ../../../../SUBSET-026-7/Decoder/Delivery/GeneratedC/Subset_Structs/End_of_Information.h \
    ../../../../SUBSET-026-7/Decoder/Delivery/GeneratedC/Subset_Structs/Default_Gradient_for_Temporary_Speed_Restriction.h \
    ../../../../SUBSET-026-7/Decoder/Delivery/GeneratedC/Subset_Structs/Default_balise_or_Loop_or_RIU_information.h \
    ../../../../SUBSET-026-7/Decoder/Delivery/GeneratedC/Subset_Structs/Data_used_by_applications_outside_the_ERTMSETCS_system.h \
    ../../../../SUBSET-026-7/Decoder/Delivery/GeneratedC/Subset_Structs/Data_used_by_applications_outside_the_ERTMS_or_ETCS_system.h \
    ../../../../SUBSET-026-7/Decoder/Delivery/GeneratedC/Subset_Structs/Danger_for_Shunting_information.h \
    ../../../../SUBSET-026-7/Decoder/Delivery/GeneratedC/Subset_Structs/Conditional_Level_Transition_Order.h \
    ../../../../SUBSET-026-7/Decoder/Delivery/GeneratedC/Subset_Structs/Axle_Load_Speed_Profile.h \
    ../../../../SUBSET-026-7/Decoder/Delivery/GeneratedC/Subset_Structs/Adhesion_Factor.h

