TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.c \
    Bitwalker.c \
    ../GeneratedC_Ch8/opnETCS_Decoder8.c

INCLUDEPATH += ../GeneratedC_Ch8 \
               ../GeneratedC
INCLUDEPATH += ../GeneratedC_Ch8/Subset_Structs8

HEADERS += \
    Bitwalker.h \
    ../GeneratedC/opnETCS_Variables.h \
    ../GeneratedC_Ch8/opnETCS_Decoder8.h \
    ../GeneratedC_Ch8/Subset_Structs8/subset026_8.h \
    ../GeneratedC_Ch8/Subset_Structs8/Acknowledgement.h \
    ../GeneratedC_Ch8/opnETCS8.h \
    ../GeneratedC_Ch8/Bitlen8.h \
    ../GeneratedC_Ch8/Subset_Structs8/Validated_Train_Data.h \
    ../GeneratedC_Ch8/Subset_Structs8/Unconditional_Emergency_Stop.h \
    ../GeneratedC_Ch8/Subset_Structs8/Train_Rejected.h \
    ../GeneratedC_Ch8/Subset_Structs8/Train_Position_Report.h \
    ../GeneratedC_Ch8/Subset_Structs8/Train_Accepted.h \
    ../GeneratedC_Ch8/Subset_Structs8/Track_Ahead_Free_Request.h \
    ../GeneratedC_Ch8/Subset_Structs8/Track_Ahead_Free_Granted.h \
    ../GeneratedC_Ch8/Subset_Structs8/Text_message_acknowledged_by_driver.h \
    ../GeneratedC_Ch8/Subset_Structs8/Termination_of_a_communication_session.h \
    ../GeneratedC_Ch8/Subset_Structs8/subset026_8.h \
    ../GeneratedC_Ch8/Subset_Structs8/SR_Authorisation.h \
    ../GeneratedC_Ch8/Subset_Structs8/SoM_position_report_confirmed_by_RBC.h \
    ../GeneratedC_Ch8/Subset_Structs8/SoM_Position_Report.h \
    ../GeneratedC_Ch8/Subset_Structs8/SH_Refused.h \
    ../GeneratedC_Ch8/Subset_Structs8/SH_Authorised.h \
    ../GeneratedC_Ch8/Subset_Structs8/Session_Established.h \
    ../GeneratedC_Ch8/Subset_Structs8/Revocation_of_Emergency_Stop.h \
    ../GeneratedC_Ch8/Subset_Structs8/Request_to_shorten_MA_is_rejected.h \
    ../GeneratedC_Ch8/Subset_Structs8/Request_to_shorten_MA_is_granted.h \
    ../GeneratedC_Ch8/Subset_Structs8/Request_to_Shorten_MA.h \
    ../GeneratedC_Ch8/Subset_Structs8/Request_for_Shunting.h \
    ../GeneratedC_Ch8/Subset_Structs8/Recognition_of_exit_from_TRIP_mode.h \
    ../GeneratedC_Ch8/Subset_Structs8/RBC_or_RIU_System_Version.h \
    ../GeneratedC_Ch8/Subset_Structs8/Radio_infill_request.h \
    ../GeneratedC_Ch8/Subset_Structs8/No_compatible_version_supported.h \
    ../GeneratedC_Ch8/Subset_Structs8/Movement_Authority.h \
    ../GeneratedC_Ch8/Subset_Structs8/MA_with_Shifted_Location_Reference.h \
    ../GeneratedC_Ch8/Subset_Structs8/MA_Request.h \
    ../GeneratedC_Ch8/Subset_Structs8/Initiation_of_a_communication_session.h \
    ../GeneratedC_Ch8/Subset_Structs8/Infill_MA.h \
    ../GeneratedC_Ch8/Subset_Structs8/General_message.h \
    ../GeneratedC_Ch8/Subset_Structs8/End_of_Mission.h \
    ../GeneratedC_Ch8/Subset_Structs8/Conditional_Emergency_Stop.h \
    ../GeneratedC_Ch8/Subset_Structs8/Assignment_of_coordinate_system.h \
    ../GeneratedC_Ch8/Subset_Structs8/Acknowledgement_of_Train_Data.h \
    ../GeneratedC_Ch8/Subset_Structs8/Acknowledgement_of_termination_of_a_communication_session.h \
    ../GeneratedC_Ch8/Subset_Structs8/Acknowledgement_of_Emergency_Stop.h
    ../GeneratedC_Ch8/Subset_Structs8/Acknowledgement_of_Emergency_Stop.h
    ../GeneratedC_Ch8/Subset_Structs8/Acknowledgement_of_termination_of_a_communication_session.h
    ../GeneratedC_Ch8/Subset_Structs8/Acknowledgement_of_Train_Data.h
    ../GeneratedC_Ch8/Subset_Structs8/Assignment_of_coordinate_system.h
    ../GeneratedC_Ch8/Subset_Structs8/Conditional_Emergency_Stop.h
    ../GeneratedC_Ch8/Subset_Structs8/End_of_Mission.h
    ../GeneratedC_Ch8/Subset_Structs8/General_message.h
    ../GeneratedC_Ch8/Subset_Structs8/Infill_MA.h
    ../GeneratedC_Ch8/Subset_Structs8/Initiation_of_a_communication_session.h
    ../GeneratedC_Ch8/Subset_Structs8/MA_Request.h
    ../GeneratedC_Ch8/Subset_Structs8/MA_with_Shifted_Location_Reference.h
    ../GeneratedC_Ch8/Subset_Structs8/Movement_Authority.h
    ../GeneratedC_Ch8/Subset_Structs8/No_compatible_version_supported.h
    ../GeneratedC_Ch8/Subset_Structs8/Radio_infill_request.h
    ../GeneratedC_Ch8/Subset_Structs8/RBC_or_RIU_System_Version.h
    ../GeneratedC_Ch8/Subset_Structs8/Recognition_of_exit_from_TRIP_mode.h
    ../GeneratedC_Ch8/Subset_Structs8/Request_for_Shunting.h
    ../GeneratedC_Ch8/Subset_Structs8/Request_to_Shorten_MA.h
    ../GeneratedC_Ch8/Subset_Structs8/Request_to_shorten_MA_is_granted.h
    ../GeneratedC_Ch8/Subset_Structs8/Request_to_shorten_MA_is_rejected.h
    ../GeneratedC_Ch8/Subset_Structs8/Revocation_of_Emergency_Stop.h
    ../GeneratedC_Ch8/Subset_Structs8/Session_Established.h
    ../GeneratedC_Ch8/Subset_Structs8/SH_Authorised.h
    ../GeneratedC_Ch8/Subset_Structs8/SH_Refused.h
    ../GeneratedC_Ch8/Subset_Structs8/SoM_Position_Report.h
    ../GeneratedC_Ch8/Subset_Structs8/SoM_position_report_confirmed_by_RBC.h
    ../GeneratedC_Ch8/Subset_Structs8/SR_Authorisation.h
    ../GeneratedC_Ch8/Subset_Structs8/Termination_of_a_communication_session.h
    ../GeneratedC_Ch8/Subset_Structs8/Text_message_acknowledged_by_driver.h
    ../GeneratedC_Ch8/Subset_Structs8/Track_Ahead_Free_Granted.h
    ../GeneratedC_Ch8/Subset_Structs8/Track_Ahead_Free_Request.h
    ../GeneratedC_Ch8/Subset_Structs8/Train_Accepted.h
    ../GeneratedC_Ch8/Subset_Structs8/Train_Position_Report.h
    ../GeneratedC_Ch8/Subset_Structs8/Train_Rejected.h
    ../GeneratedC_Ch8/Subset_Structs8/Unconditional_Emergency_Stop.h
    ../GeneratedC_Ch8/Subset_Structs8/Validated_Train_Data.h


