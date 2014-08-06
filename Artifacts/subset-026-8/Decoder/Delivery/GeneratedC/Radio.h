#include "Bitwalker.h"

// NAMESPACE = TrainToTrack
// TransmissionMedia=RBC

struct DATA_Validated_Train_Data {
// Packet Number = 129

	uint32_t NID_MESSAGE;                     		// # 8		// int
	uint32_t               L_MESSAGE             ;		// # 10		// int
	uint32_t               T_TRAIN               ;		// # 32		// real
	uint32_t               NID_ENGINE            ;		// # 24		// int
	uint32_t               PADDING0              ;		// # 6	
	uint32_t Validated_Train_Data_OptionalPackets;		 // # Length is unknown here; depends on current package number(s)


} 
//=============================================
// NAMESPACE = TrainToTrack
// TransmissionMedia=RBC

struct DATA_Request_for_Shunting {
// Packet Number = 130

	uint32_t NID_MESSAGE;                     		// # 8		// int
	uint32_t               L_MESSAGE             ;		// # 10		// int
	uint32_t               T_TRAIN               ;		// # 32		// float
	uint32_t               NID_ENGINE            ;		// # 24		// int
	uint32_t               PADDING1              ;		// # 6	
	uint32_t Request_for_Shunting_OptionalPackets;		 // # Length is unknown here; depends on current package number(s)


} 
//=============================================
// NAMESPACE = TrainToTrack
// TransmissionMedia=RBC

struct DATA_MA_Request {
// Packet Number = 132

	uint32_t NID_MESSAGE;                     		// # 8		// int
	uint32_t               L_MESSAGE             ;		// # 10		// int
	uint32_t               T_TRAIN               ;		// # 32		// float
	uint32_t               NID_ENGINE            ;		// # 24		// int
	T_q_marqstreason       Q_MARQSTREASON        ;		// # 5		// enum
	uint32_t               PADDING2              ;		// # 1	
	uint32_t MA_Request_OptionalPackets;		 // # Length is unknown here; depends on current package number(s)


} 
//=============================================
// NAMESPACE = TrainToTrack
// TransmissionMedia=RBC, RIU

struct DATA_Train_Position_Report {
// Packet Number = 136

	uint32_t NID_MESSAGE;                     		// # 8		// int
	uint32_t               L_MESSAGE             ;		// # 10		// int
	uint32_t               T_TRAIN               ;		// # 32		// float
	uint32_t               NID_ENGINE            ;		// # 24		// int
	uint32_t               PADDING3              ;		// # 6	
	uint32_t Train_Position_Report_OptionalPackets;		 // # Length is unknown here; depends on current package number(s)


} 
//=============================================
// NAMESPACE = TrainToTrack
// TransmissionMedia=RBC

struct DATA_Request_to_shorten_MA_is_granted {
// Packet Number = 137

	uint32_t NID_MESSAGE;                     		// # 8		// int
	uint32_t               L_MESSAGE             ;		// # 10		// int
	uint32_t               T_TRAIN               ;		// # 32		// float
	uint32_t               NID_ENGINE            ;		// # 24		// int
	uint32_t               PADDING4              ;		// # 6	
	uint32_t Request_to_shorten_MA_is_granted_OptionalPackets;		 // # Length is unknown here; depends on current package number(s)


} 
//=============================================
// NAMESPACE = TrainToTrack
// TransmissionMedia=RBC

struct DATA_Request_to_shorten_MA_is_rejected {
// Packet Number = 138

	uint32_t NID_MESSAGE;                     		// # 8		// int
	uint32_t               L_MESSAGE             ;		// # 10		// int
	uint32_t               T_TRAIN               ;		// # 32		// float
	uint32_t               NID_ENGINE            ;		// # 24		// int
	uint32_t               PADDING5              ;		// # 6	
	uint32_t Request_to_shorten_MA_is_rejected_OptionalPackets;		 // # Length is unknown here; depends on current package number(s)


} 
//=============================================
// NAMESPACE = TrainToTrack
// TransmissionMedia=RBC, RIU

struct DATA_Acknowledgement {
// Packet Number = 146

	uint32_t NID_MESSAGE;                     		// # 8		// int
	uint32_t               L_MESSAGE             ;		// # 10		// int
	uint32_t               T_TRAIN               ;		// # 32		// float
	uint32_t               NID_ENGINE            ;		// # 24		// int
} 
//=============================================
// NAMESPACE = TrainToTrack
// TransmissionMedia=RBC

struct DATA_Acknowledgement_of_Emergency_Stop {
// Packet Number = 147

	uint32_t NID_MESSAGE;                     		// # 8		// int
	uint32_t               L_MESSAGE             ;		// # 10		// int
	uint32_t               T_TRAIN               ;		// # 32		// float
	uint32_t               NID_ENGINE            ;		// # 24		// int
	uint32_t               NID_EM                ;		// # 4	
	T_q_emergencystop      Q_EMERGENCYSTOP       ;		// # 2		// enum
	uint32_t Acknowledgement_of_Emergency_Stop_OptionalPackets;		 // # Length is unknown here; depends on current package number(s)


} 
//=============================================
// NAMESPACE = TrainToTrack
// TransmissionMedia=RBC

struct DATA_Track_Ahead_Free_Granted {
// Packet Number = 149

	uint32_t NID_MESSAGE;                     		// # 8		// int
	uint32_t               L_MESSAGE             ;		// # 10		// int
	uint32_t               T_TRAIN               ;		// # 32		// float
	uint32_t               NID_ENGINE            ;		// # 24		// int
	uint32_t               PADDING6              ;		// # 6	
	uint32_t Track_Ahead_Free_Granted_OptionalPackets;		 // # Length is unknown here; depends on current package number(s)


} 
//=============================================
// NAMESPACE = TrainToTrack
// TransmissionMedia=RBC

struct DATA_End_of_Mission {
// Packet Number = 150

	uint32_t NID_MESSAGE;                     		// # 8		// int
	uint32_t               L_MESSAGE             ;		// # 10		// int
	uint32_t               T_TRAIN               ;		// # 32		// float
	uint32_t               NID_ENGINE            ;		// # 24		// int
	uint32_t               PADDING7              ;		// # 6	
	uint32_t End_of_Mission_OptionalPackets;		 // # Length is unknown here; depends on current package number(s)


} 
//=============================================
// NAMESPACE = TrainToTrack
// TransmissionMedia=RIU

struct DATA_Radio_infill_request {
// Packet Number = 153

	uint32_t NID_MESSAGE;                     		// # 8		// int
	uint32_t               L_MESSAGE             ;		// # 10		// int
	uint32_t               T_TRAIN               ;		// # 32		// float
	uint32_t               NID_ENGINE            ;		// # 24		// int
	uint32_t               NID_C                 ;		// # 10	
	uint32_t               NID_BG                ;		// # 14	
	T_q_infill             Q_INFILL              ;		// # 1	
	uint32_t               PADDING8              ;		// # 5	
	uint32_t Radio_infill_request_OptionalPackets;		 // # Length is unknown here; depends on current package number(s)


} 
//=============================================
// NAMESPACE = TrainToTrack
// TransmissionMedia=RBC, RIU

struct DATA_No_compatible_version_supported {
// Packet Number = 154

	uint32_t NID_MESSAGE;                     		// # 8		// int
	uint32_t               L_MESSAGE             ;		// # 10		// int
	uint32_t               T_TRAIN               ;		// # 32		// float
	uint32_t               NID_ENGINE            ;		// # 24		// int
} 
//=============================================
// NAMESPACE = TrainToTrack
// TransmissionMedia=RBC, RIU

struct DATA_Initiation_of_a_communication_session {
// Packet Number = 155

	uint32_t NID_MESSAGE;                     		// # 8		// int
	uint32_t               L_MESSAGE             ;		// # 10		// int
	uint32_t               T_TRAIN               ;		// # 32		// float
	uint32_t               NID_ENGINE            ;		// # 24		// int
} 
//=============================================
// NAMESPACE = TrainToTrack
// TransmissionMedia=RBC, RIU

struct DATA_Termination_of_a_communication_session {
// Packet Number = 156

	uint32_t NID_MESSAGE;                     		// # 8		// int
	uint32_t               L_MESSAGE             ;		// # 10		// int
	uint32_t               T_TRAIN               ;		// # 32		// float
	uint32_t               NID_ENGINE            ;		// # 24		// int
} 
//=============================================
// NAMESPACE = TrainToTrack
// TransmissionMedia=RBC

struct DATA_SoM_Position_Report {
// Packet Number = 157

	uint32_t NID_MESSAGE;                     		// # 8		// int
	uint32_t               L_MESSAGE             ;		// # 10		// int
	uint32_t               T_TRAIN               ;		// # 32		// float
	uint32_t               NID_ENGINE            ;		// # 24		// int
	T_q_status             Q_STATUS              ;		// # 2		// enum
	uint32_t               PADDING9              ;		// # 4	
	uint32_t SoM_Position_Report_OptionalPackets;		 // # Length is unknown here; depends on current package number(s)


} 
//=============================================
// NAMESPACE = TrainToTrack
// TransmissionMedia=RBC

struct DATA_Text_message_acknowledged_by_driver {
// Packet Number = 158

	uint32_t NID_MESSAGE;                     		// # 8		// int
	uint32_t               L_MESSAGE             ;		// # 10		// int
	uint32_t               T_TRAIN               ;		// # 32		// float
	uint32_t               NID_ENGINE            ;		// # 24		// int
	uint32_t               NID_TEXTMESSAGE       ;		// # 8	
	uint32_t               PADDING10             ;		// # 6	
	uint32_t Text_message_acknowledged_by_driver_OptionalPackets;		 // # Length is unknown here; depends on current package number(s)


} 
//=============================================
// NAMESPACE = TrainToTrack
// TransmissionMedia=RBC, RIU

struct DATA_Session_Established {
// Packet Number = 159

	uint32_t NID_MESSAGE;                     		// # 8		// int
	uint32_t               L_MESSAGE             ;		// # 10		// int
	uint32_t               T_TRAIN               ;		// # 32		// float
	uint32_t               NID_ENGINE            ;		// # 24		// int
	uint32_t               PADDING11             ;		// # 6	
	uint32_t Session_Established_OptionalPackets;		 // # Length is unknown here; depends on current package number(s)


} 
//=============================================
// NAMESPACE = TrackToTrain
// TransmissionMedia=RBC

struct DATA_SR_Authorisation {
// Packet Number = 2

	uint32_t NID_MESSAGE;                     		// # 8		// int
	uint32_t               L_MESSAGE             ;		// # 10		// int
	uint32_t               T_TRAIN               ;		// # 32		// float
	T_m_ack                M_ACK                 ;		// # 1		// enum
	uint32_t               NID_LRBG              ;		// # 24		// int
	T_q_scale              Q_SCALE               ;		// # 2		// enum
	uint32_t               D_SR                  ;		// # 15		// int
	uint32_t               PADDING12             ;		// # 4	
	uint32_t SR_Authorisation_OptionalPackets;		 // # Length is unknown here; depends on current package number(s)


} 
//=============================================
// NAMESPACE = TrackToTrain
// TransmissionMedia=RBC

struct DATA_Movement_Authority {
// Packet Number = 3

	uint32_t NID_MESSAGE;                     		// # 8		// int
	uint32_t               L_MESSAGE             ;		// # 10		// int
	uint32_t               T_TRAIN               ;		// # 32		// float
	T_m_ack                M_ACK                 ;		// # 1		// enum
	uint32_t               NID_LRBG              ;		// # 24		// int
	uint32_t               PADDING13             ;		// # 5	
	uint32_t Movement_Authority_OptionalPackets;		 // # Length is unknown here; depends on current package number(s)


} 
//=============================================
// NAMESPACE = TrackToTrain
// TransmissionMedia=RBC

struct DATA_Recognition_of_exit_from_TRIP_mode {
// Packet Number = 6

	uint32_t NID_MESSAGE;                     		// # 8		// int
	uint32_t               L_MESSAGE             ;		// # 10		// int
	uint32_t               T_TRAIN               ;		// # 32		// float
	T_m_ack                M_ACK                 ;		// # 1		// enum
	uint32_t               NID_LRBG              ;		// # 24		// int
} 
//=============================================
// NAMESPACE = TrackToTrain
// TransmissionMedia=RBC

struct DATA_Acknowledgement_of_Train_Data {
// Packet Number = 8

	uint32_t NID_MESSAGE;                     		// # 8		// int
	uint32_t               L_MESSAGE             ;		// # 10		// int
		uint32_t T_TRAIN0;                        		// # 32		// float
	T_m_ack                M_ACK                 ;		// # 1		// enum
	uint32_t               NID_LRBG              ;		// # 24		// int
		uint32_t T_TRAIN1;                        		// # 32	
} 
//=============================================
// NAMESPACE = TrackToTrain
// TransmissionMedia=RBC

struct DATA_Request_to_Shorten_MA {
// Packet Number = 9

	uint32_t NID_MESSAGE;                     		// # 8		// int
	uint32_t               L_MESSAGE             ;		// # 10		// int
	uint32_t               T_TRAIN               ;		// # 32		// float
	T_m_ack                M_ACK                 ;		// # 1		// enum
	uint32_t               NID_LRBG              ;		// # 24		// int
	uint32_t               PADDING14             ;		// # 5	
	uint32_t Request_to_Shorten_MA_OptionalPackets;		 // # Length is unknown here; depends on current package number(s)


} 
//=============================================
// NAMESPACE = TrackToTrain
// TransmissionMedia=RBC

struct DATA_Conditional_Emergency_Stop {
// Packet Number = 15

	uint32_t NID_MESSAGE;                     		// # 8		// int
	uint32_t               L_MESSAGE             ;		// # 10		// int
	uint32_t               T_TRAIN               ;		// # 32		// float
	T_m_ack                M_ACK                 ;		// # 1		// enum
	uint32_t               NID_LRBG              ;		// # 24		// int
	uint32_t               NID_EM                ;		// # 4	
	T_q_scale              Q_SCALE               ;		// # 2		// enum
	uint32_t               D_REF                 ;		// # 16		// int
	T_q_dir                Q_DIR                 ;		// # 2		// enum
	uint32_t               D_EMERGENCYSTOP       ;		// # 15	
} 
//=============================================
// NAMESPACE = TrackToTrain
// TransmissionMedia=RBC

struct DATA_Unconditional_Emergency_Stop {
// Packet Number = 16

	uint32_t NID_MESSAGE;                     		// # 8		// int
	uint32_t               L_MESSAGE             ;		// # 10		// int
	uint32_t               T_TRAIN               ;		// # 32		// float
	T_m_ack                M_ACK                 ;		// # 1		// enum
	uint32_t               NID_LRBG              ;		// # 24		// int
	uint32_t               NID_EM                ;		// # 4	
} 
//=============================================
// NAMESPACE = TrackToTrain
// TransmissionMedia=RBC

struct DATA_Revocation_of_Emergency_Stop {
// Packet Number = 18

	uint32_t NID_MESSAGE;                     		// # 8		// int
	uint32_t               L_MESSAGE             ;		// # 10		// int
	uint32_t               T_TRAIN               ;		// # 32		// float
	T_m_ack                M_ACK                 ;		// # 1		// enum
	uint32_t               NID_LRBG              ;		// # 24		// int
	uint32_t               NID_EM                ;		// # 4	
} 
//=============================================
// NAMESPACE = TrackToTrain
// TransmissionMedia=RBC, RIU

struct DATA_General_message {
// Packet Number = 24

	uint32_t NID_MESSAGE;                     		// # 8		// int
	uint32_t               L_MESSAGE             ;		// # 10		// int
	uint32_t               T_TRAIN               ;		// # 32		// float
	T_m_ack                M_ACK                 ;		// # 1		// enum
	uint32_t               NID_LRBG              ;		// # 24		// int
	uint32_t               PADDING15             ;		// # 5	
	uint32_t General_message_OptionalPackets;		 // # Length is unknown here; depends on current package number(s)


} 
//=============================================
// NAMESPACE = TrackToTrain
// TransmissionMedia=RBC

struct DATA_SH_Refused {
// Packet Number = 27

	uint32_t NID_MESSAGE;                     		// # 8		// int
	uint32_t               L_MESSAGE             ;		// # 10		// int
		uint32_t T_TRAIN0;                        		// # 32		// float
	T_m_ack                M_ACK                 ;		// # 1		// enum
	uint32_t               NID_LRBG              ;		// # 24		// int
		uint32_t T_TRAIN1;                        		// # 32	
} 
//=============================================
// NAMESPACE = TrackToTrain
// TransmissionMedia=RBC

struct DATA_SH_Authorised {
// Packet Number = 28

	uint32_t NID_MESSAGE;                     		// # 8		// int
	uint32_t               L_MESSAGE             ;		// # 10		// int
		uint32_t T_TRAIN0;                        		// # 32		// float
	T_m_ack                M_ACK                 ;		// # 1		// enum
	uint32_t               NID_LRBG              ;		// # 24		// int
		uint32_t T_TRAIN1;                        		// # 32	
	uint32_t               PADDING16             ;		// # 5	
	uint32_t SH_Authorised_OptionalPackets;		 // # Length is unknown here; depends on current package number(s)


} 
//=============================================
// NAMESPACE = TrackToTrain
// TransmissionMedia=RBC, RIU

struct DATA_RBC_or_RIU_System_Version {
// Packet Number = 32

	uint32_t NID_MESSAGE;                     		// # 8		// int
	uint32_t               L_MESSAGE             ;		// # 10		// int
	uint32_t               T_TRAIN               ;		// # 32		// float
	T_m_ack                M_ACK                 ;		// # 1		// enum
	uint32_t               NID_LRBG              ;		// # 24		// int
	T_m_version            M_VERSION             ;		// # 7	
} 
//=============================================
// NAMESPACE = TrackToTrain
// TransmissionMedia=RBC

struct DATA_MA_with_Shifted_Location_Reference {
// Packet Number = 33

	uint32_t NID_MESSAGE;                     		// # 8		// int
	uint32_t               L_MESSAGE             ;		// # 10		// int
	uint32_t               T_TRAIN               ;		// # 32		// float
	T_m_ack                M_ACK                 ;		// # 1		// enum
	uint32_t               NID_LRBG              ;		// # 24		// int
	T_q_scale              Q_SCALE               ;		// # 2		// enum
	uint32_t               D_REF                 ;		// # 16	
	uint32_t               PADDING17             ;		// # 3	
	uint32_t MA_with_Shifted_Location_Reference_OptionalPackets;		 // # Length is unknown here; depends on current package number(s)


} 
//=============================================
// NAMESPACE = TrackToTrain
// TransmissionMedia=RBC

struct DATA_Track_Ahead_Free_Request {
// Packet Number = 34

	uint32_t NID_MESSAGE;                     		// # 8		// int
	uint32_t               L_MESSAGE             ;		// # 10		// int
	uint32_t               T_TRAIN               ;		// # 32		// float
	T_m_ack                M_ACK                 ;		// # 1		// enum
	uint32_t               NID_LRBG              ;		// # 24		// int
	T_q_scale              Q_SCALE               ;		// # 2		// enum
	uint32_t               D_REF                 ;		// # 16		// int
	T_q_dir                Q_DIR                 ;		// # 2		// enum
	uint32_t               D_TAFDISPLAY          ;		// # 15		// int
	uint32_t               L_TAFDISPLAY          ;		// # 15		// int
} 
//=============================================
// NAMESPACE = TrackToTrain
// TransmissionMedia=RIU

struct DATA_Infill_MA {
// Packet Number = 37

	uint32_t NID_MESSAGE;                     		// # 8		// int
	uint32_t               L_MESSAGE             ;		// # 10		// int
	uint32_t               T_TRAIN               ;		// # 32		// float
	T_m_ack                M_ACK                 ;		// # 1		// enum
	uint32_t               NID_LRBG              ;		// # 24		// int
	uint32_t               PADDING18             ;		// # 5	
	uint32_t Infill_MA_OptionalPackets;		 // # Length is unknown here; depends on current package number(s)


} 
//=============================================
// NAMESPACE = TrackToTrain
// TransmissionMedia=RBC

struct DATA_Initiation_of_a_communication_session {
// Packet Number = 38

	uint32_t NID_MESSAGE;                     		// # 8		// int
	uint32_t               L_MESSAGE             ;		// # 10		// int
	uint32_t               T_TRAIN               ;		// # 32	
	T_m_ack                M_ACK                 ;		// # 1		// enum
	uint32_t               NID_LRBG              ;		// # 24	
} 
//=============================================
// NAMESPACE = TrackToTrain
// TransmissionMedia=RBC, RIU

struct DATA_Acknowledgement_of_termination_of_a_communication_session {
// Packet Number = 39

	uint32_t NID_MESSAGE;                     		// # 8		// int
	uint32_t               L_MESSAGE             ;		// # 10		// int
	uint32_t               T_TRAIN               ;		// # 32		// float
	T_m_ack                M_ACK                 ;		// # 1	
	uint32_t               NID_LRBG              ;		// # 24		// int
} 
//=============================================
// NAMESPACE = TrackToTrain
// TransmissionMedia=RBC

struct DATA_Train_Rejected {
// Packet Number = 40

	uint32_t NID_MESSAGE;                     		// # 8		// int
	uint32_t               L_MESSAGE             ;		// # 10		// int
	uint32_t               T_TRAIN               ;		// # 32		// float
	T_m_ack                M_ACK                 ;		// # 1		// enum
	uint32_t               NID_LRBG              ;		// # 24		// int
} 
//=============================================
// NAMESPACE = TrackToTrain
// TransmissionMedia=RBC

struct DATA_Train_Accepted {
// Packet Number = 41

	uint32_t NID_MESSAGE;                     		// # 8		// int
	uint32_t               L_MESSAGE             ;		// # 10		// int
	uint32_t               T_TRAIN               ;		// # 32		// float
	T_m_ack                M_ACK                 ;		// # 1		// enum
	uint32_t               NID_LRBG              ;		// # 24		// int
} 
//=============================================
// NAMESPACE = TrackToTrain
// TransmissionMedia=RBC

struct DATA_SoM_position_report_confirmed_by_RBC {
// Packet Number = 43

	uint32_t NID_MESSAGE;                     		// # 8		// int
	uint32_t               L_MESSAGE             ;		// # 10		// int
	uint32_t               T_TRAIN               ;		// # 32		// float
	T_m_ack                M_ACK                 ;		// # 1		// enum
	uint32_t               NID_LRBG              ;		// # 24		// int
} 
//=============================================
// NAMESPACE = TrackToTrain
// TransmissionMedia=RBC

struct DATA_Assignment_of_coordinate_system {
// Packet Number = 45

	uint32_t NID_MESSAGE;                     		// # 8		// int
	uint32_t               L_MESSAGE             ;		// # 10		// int
	uint32_t               T_TRAIN               ;		// # 32		// float
	T_m_ack                M_ACK                 ;		// # 1		// enum
	uint32_t               NID_LRBG              ;		// # 24		// int
	T_q_orientation        Q_ORIENTATION         ;		// # 1		// enum
} 
//=============================================
