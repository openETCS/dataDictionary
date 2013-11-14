#include "Bitwalker.h"


struct DATA_oETCS_Validated_Train_Data {
// NAMESPACE = Radio_TrainToTrack
// TransmissionMedia=RBC

	uint32_t NID_MESSAGE;                            			// # 8		// int
	uint32_t L_MESSAGE;                              			// # 10		// int
	uint32_t T_TRAIN;                                			// # 32		// real
	uint32_t NID_ENGINE;                             			// # 24		// int
	uint32_t PADDING0;                               			// # 6	
	uint32_t Validated_Train_Data_OptionalPackets;		 // # Length is unknown here; depends on current package number(s)


} 
//=============================================

struct DATA_oETCS_Request_for_Shunting {
// NAMESPACE = Radio_TrainToTrack
// TransmissionMedia=RBC

	uint32_t NID_MESSAGE;                            			// # 8		// int
	uint32_t L_MESSAGE;                              			// # 10		// int
	uint32_t T_TRAIN;                                			// # 32		// real
	uint32_t NID_ENGINE;                             			// # 24		// int
	uint32_t PADDING1;                               			// # 6	
	uint32_t Request_for_Shunting_OptionalPackets;		 // # Length is unknown here; depends on current package number(s)


} 
//=============================================

struct DATA_oETCS_MA_Request {
// NAMESPACE = Radio_TrainToTrack
// TransmissionMedia=RBC

	uint32_t NID_MESSAGE;                            			// # 8		// int
	uint32_t L_MESSAGE;                              			// # 10		// int
	uint32_t T_TRAIN;                                			// # 32		// real
	uint32_t NID_ENGINE;                             			// # 24		// int
	uint32_t Q_MARQSTREASON;                         			// # 5		// enum
	uint32_t PADDING2;                               			// # 1	
	uint32_t MA_Request_OptionalPackets;		 // # Length is unknown here; depends on current package number(s)


} 
//=============================================

struct DATA_oETCS_Train_Position_Report {
// NAMESPACE = Radio_TrainToTrack
// TransmissionMedia=RBC, RIU

	uint32_t NID_MESSAGE;                            			// # 8		// int
	uint32_t L_MESSAGE;                              			// # 10		// int
	uint32_t T_TRAIN;                                			// # 32		// real
	uint32_t NID_ENGINE;                             			// # 24		// int
	uint32_t PADDING3;                               			// # 6	
	uint32_t Train_Position_Report_OptionalPackets;		 // # Length is unknown here; depends on current package number(s)


} 
//=============================================

struct DATA_oETCS_Request_to_shorten_MA_is_granted {
// NAMESPACE = Radio_TrainToTrack
// TransmissionMedia=RBC

	uint32_t NID_MESSAGE;                            			// # 8		// int
	uint32_t L_MESSAGE;                              			// # 10		// int
	uint32_t T_TRAIN;                                			// # 32		// real
	uint32_t NID_ENGINE;                             			// # 24		// int
	uint32_t PADDING4;                               			// # 6	
	uint32_t Request_to_shorten_MA_is_granted_OptionalPackets;		 // # Length is unknown here; depends on current package number(s)


} 
//=============================================

struct DATA_oETCS_Request_to_shorten_MA_is_rejected {
// NAMESPACE = Radio_TrainToTrack
// TransmissionMedia=RBC

	uint32_t NID_MESSAGE;                            			// # 8		// int
	uint32_t L_MESSAGE;                              			// # 10		// int
	uint32_t T_TRAIN;                                			// # 32		// real
	uint32_t NID_ENGINE;                             			// # 24		// int
	uint32_t PADDING5;                               			// # 6	
	uint32_t Request_to_shorten_MA_is_rejected_OptionalPackets;		 // # Length is unknown here; depends on current package number(s)


} 
//=============================================

struct DATA_oETCS_Acknowledgement {
// NAMESPACE = Radio_TrainToTrack
// TransmissionMedia=RBC, RIU

	uint32_t NID_MESSAGE;                            			// # 8		// int
	uint32_t L_MESSAGE;                              			// # 10		// int
	uint32_t T_TRAIN;                                			// # 32		// real
	uint32_t NID_ENGINE;                             			// # 24		// int
} 
//=============================================

struct DATA_oETCS_Acknowledgement_of_Emergency_Stop {
// NAMESPACE = Radio_TrainToTrack
// TransmissionMedia=RBC

	uint32_t NID_MESSAGE;                            			// # 8		// int
	uint32_t L_MESSAGE;                              			// # 10		// int
	uint32_t T_TRAIN;                                			// # 32		// real
	uint32_t NID_ENGINE;                             			// # 24		// int
	uint32_t NID_EM;                                 			// # 4	
	uint32_t Q_EMERGENCYSTOP;                        			// # 2		// enum
	uint32_t Acknowledgement_of_Emergency_Stop_OptionalPackets;		 // # Length is unknown here; depends on current package number(s)


} 
//=============================================

struct DATA_oETCS_Track_Ahead_Free_Granted {
// NAMESPACE = Radio_TrainToTrack
// TransmissionMedia=RBC

	uint32_t NID_MESSAGE;                            			// # 8		// int
	uint32_t L_MESSAGE;                              			// # 10		// int
	uint32_t T_TRAIN;                                			// # 32		// real
	uint32_t NID_ENGINE;                             			// # 24		// int
	uint32_t PADDING6;                               			// # 6	
	uint32_t Track_Ahead_Free_Granted_OptionalPackets;		 // # Length is unknown here; depends on current package number(s)


} 
//=============================================

struct DATA_oETCS_End_of_Mission {
// NAMESPACE = Radio_TrainToTrack
// TransmissionMedia=RBC

	uint32_t NID_MESSAGE;                            			// # 8		// int
	uint32_t L_MESSAGE;                              			// # 10		// int
	uint32_t T_TRAIN;                                			// # 32		// real
	uint32_t NID_ENGINE;                             			// # 24		// int
	uint32_t PADDING7;                               			// # 6	
	uint32_t End_of_Mission_OptionalPackets;		 // # Length is unknown here; depends on current package number(s)


} 
//=============================================

struct DATA_oETCS_Radio_infill_request {
// NAMESPACE = Radio_TrainToTrack
// TransmissionMedia=RIU

	uint32_t NID_MESSAGE;                            			// # 8		// int
	uint32_t L_MESSAGE;                              			// # 10		// int
	uint32_t T_TRAIN;                                			// # 32		// real
	uint32_t NID_ENGINE;                             			// # 24		// int
	uint32_t NID_C;                                  			// # 10	
	uint32_t NID_BG;                                 			// # 14	
	uint32_t Q_INFILL;                               			// # 1	
	uint32_t PADDING8;                               			// # 5	
	uint32_t Radio_infill_request_OptionalPackets;		 // # Length is unknown here; depends on current package number(s)


} 
//=============================================

struct DATA_oETCS_No_compatible_version_supported {
// NAMESPACE = Radio_TrainToTrack
// TransmissionMedia=RBC, RIU

	uint32_t NID_MESSAGE;                            			// # 8		// int
	uint32_t L_MESSAGE;                              			// # 10		// int
	uint32_t T_TRAIN;                                			// # 32		// real
	uint32_t NID_ENGINE;                             			// # 24		// int
} 
//=============================================

struct DATA_oETCS_Initiation_of_a_communication_session {
// NAMESPACE = Radio_TrainToTrack
// TransmissionMedia=RBC, RIU

	uint32_t NID_MESSAGE;                            			// # 8		// int
	uint32_t L_MESSAGE;                              			// # 10		// int
	uint32_t T_TRAIN;                                			// # 32		// real
	uint32_t NID_ENGINE;                             			// # 24		// int
} 
//=============================================

struct DATA_oETCS_Termination_of_a_communication_session {
// NAMESPACE = Radio_TrainToTrack
// TransmissionMedia=RBC, RIU

	uint32_t NID_MESSAGE;                            			// # 8		// int
	uint32_t L_MESSAGE;                              			// # 10		// int
	uint32_t T_TRAIN;                                			// # 32		// real
	uint32_t NID_ENGINE;                             			// # 24		// int
} 
//=============================================

struct DATA_oETCS_SoM_Position_Report {
// NAMESPACE = Radio_TrainToTrack
// TransmissionMedia=RBC

	uint32_t NID_MESSAGE;                            			// # 8		// int
	uint32_t L_MESSAGE;                              			// # 10		// int
	uint32_t T_TRAIN;                                			// # 32		// real
	uint32_t NID_ENGINE;                             			// # 24		// int
	uint32_t Q_STATUS;                               			// # 2		// enum
	uint32_t PADDING9;                               			// # 4	
	uint32_t SoM_Position_Report_OptionalPackets;		 // # Length is unknown here; depends on current package number(s)


} 
//=============================================

struct DATA_oETCS_Text_message_acknowledged_by_driver {
// NAMESPACE = Radio_TrainToTrack
// TransmissionMedia=RBC

	uint32_t NID_MESSAGE;                            			// # 8		// int
	uint32_t L_MESSAGE;                              			// # 10		// int
	uint32_t T_TRAIN;                                			// # 32		// real
	uint32_t NID_ENGINE;                             			// # 24		// int
	uint32_t NID_TEXTMESSAGE;                        			// # 8	
	uint32_t PADDING10;                              			// # 6	
	uint32_t Text_message_acknowledged_by_driver_OptionalPackets;		 // # Length is unknown here; depends on current package number(s)


} 
//=============================================

struct DATA_oETCS_Session_Established {
// NAMESPACE = Radio_TrainToTrack
// TransmissionMedia=RBC, RIU

	uint32_t NID_MESSAGE;                            			// # 8		// int
	uint32_t L_MESSAGE;                              			// # 10		// int
	uint32_t T_TRAIN;                                			// # 32		// real
	uint32_t NID_ENGINE;                             			// # 24		// int
	uint32_t PADDING11;                              			// # 6	
	uint32_t Session_Established_OptionalPackets;		 // # Length is unknown here; depends on current package number(s)


} 
//=============================================

struct DATA_oETCS_SR_Authorisation {
// NAMESPACE = Radio_TrackToTrain
// TransmissionMedia=RBC

	uint32_t NID_MESSAGE;                            			// # 8		// int
	uint32_t L_MESSAGE;                              			// # 10		// int
	uint32_t T_TRAIN;                                			// # 32		// real
	uint32_t M_ACK;                                  			// # 1		// enum
	uint32_t NID_LRBG;                               			// # 24		// int
	uint32_t Q_SCALE;                                			// # 2		// enum
	uint32_t D_SR;                                   			// # 15		// int
	uint32_t PADDING12;                              			// # 4	
	uint32_t SR_Authorisation_OptionalPackets;		 // # Length is unknown here; depends on current package number(s)


} 
//=============================================

struct DATA_oETCS_Movement_Authority {
// NAMESPACE = Radio_TrackToTrain
// TransmissionMedia=RBC

	uint32_t NID_MESSAGE;                            			// # 8		// int
	uint32_t L_MESSAGE;                              			// # 10		// int
	uint32_t T_TRAIN;                                			// # 32		// real
	uint32_t M_ACK;                                  			// # 1		// enum
	uint32_t NID_LRBG;                               			// # 24		// int
	uint32_t PADDING13;                              			// # 5	
	uint32_t Movement_Authority_OptionalPackets;		 // # Length is unknown here; depends on current package number(s)


} 
//=============================================

struct DATA_oETCS_Recognition_of_exit_from_TRIP_mode {
// NAMESPACE = Radio_TrackToTrain
// TransmissionMedia=RBC

	uint32_t NID_MESSAGE;                            			// # 8		// int
	uint32_t L_MESSAGE;                              			// # 10		// int
	uint32_t T_TRAIN;                                			// # 32		// real
	uint32_t M_ACK;                                  			// # 1		// enum
	uint32_t NID_LRBG;                               			// # 24		// int
} 
//=============================================

struct DATA_oETCS_Acknowledgement_of_Train_Data {
// NAMESPACE = Radio_TrackToTrain
// TransmissionMedia=RBC

	uint32_t NID_MESSAGE;                            			// # 8		// int
	uint32_t L_MESSAGE;                              			// # 10		// int
		uint32_t T_TRAIN0;                        		// # 32		// real
	uint32_t M_ACK;                                  			// # 1		// enum
	uint32_t NID_LRBG;                               			// # 24		// int
		uint32_t T_TRAIN1;                        		// # 32	
} 
//=============================================

struct DATA_oETCS_Request_to_Shorten_MA {
// NAMESPACE = Radio_TrackToTrain
// TransmissionMedia=RBC

	uint32_t NID_MESSAGE;                            			// # 8		// int
	uint32_t L_MESSAGE;                              			// # 10		// int
	uint32_t T_TRAIN;                                			// # 32		// real
	uint32_t M_ACK;                                  			// # 1		// enum
	uint32_t NID_LRBG;                               			// # 24		// int
	uint32_t PADDING14;                              			// # 5	
	uint32_t Request_to_Shorten_MA_OptionalPackets;		 // # Length is unknown here; depends on current package number(s)


} 
//=============================================

struct DATA_oETCS_Conditional_Emergency_Stop {
// NAMESPACE = Radio_TrackToTrain
// TransmissionMedia=RBC

	uint32_t NID_MESSAGE;                            			// # 8		// int
	uint32_t L_MESSAGE;                              			// # 10		// int
	uint32_t T_TRAIN;                                			// # 32		// real
	uint32_t M_ACK;                                  			// # 1		// enum
	uint32_t NID_LRBG;                               			// # 24		// int
	uint32_t NID_EM;                                 			// # 4	
	uint32_t Q_SCALE;                                			// # 2		// enum
	uint32_t D_REF;                                  			// # 16		// int
	uint32_t Q_DIR;                                  			// # 2		// enum
	uint32_t D_EMERGENCYSTOP;                        			// # 15	
} 
//=============================================

struct DATA_oETCS_Unconditional_Emergency_Stop {
// NAMESPACE = Radio_TrackToTrain
// TransmissionMedia=RBC

	uint32_t NID_MESSAGE;                            			// # 8		// int
	uint32_t L_MESSAGE;                              			// # 10		// int
	uint32_t T_TRAIN;                                			// # 32		// real
	uint32_t M_ACK;                                  			// # 1		// enum
	uint32_t NID_LRBG;                               			// # 24		// int
	uint32_t NID_EM;                                 			// # 4	
} 
//=============================================

struct DATA_oETCS_Revocation_of_Emergency_Stop {
// NAMESPACE = Radio_TrackToTrain
// TransmissionMedia=RBC

	uint32_t NID_MESSAGE;                            			// # 8		// int
	uint32_t L_MESSAGE;                              			// # 10		// int
	uint32_t T_TRAIN;                                			// # 32		// real
	uint32_t M_ACK;                                  			// # 1		// enum
	uint32_t NID_LRBG;                               			// # 24		// int
	uint32_t NID_EM;                                 			// # 4	
} 
//=============================================

struct DATA_oETCS_General_message {
// NAMESPACE = Radio_TrackToTrain
// TransmissionMedia=RBC, RIU

	uint32_t NID_MESSAGE;                            			// # 8		// int
	uint32_t L_MESSAGE;                              			// # 10		// int
	uint32_t T_TRAIN;                                			// # 32		// real
	uint32_t M_ACK;                                  			// # 1		// enum
	uint32_t NID_LRBG;                               			// # 24		// int
	uint32_t PADDING15;                              			// # 5	
	uint32_t General_message_OptionalPackets;		 // # Length is unknown here; depends on current package number(s)


} 
//=============================================

struct DATA_oETCS_SH_Refused {
// NAMESPACE = Radio_TrackToTrain
// TransmissionMedia=RBC

	uint32_t NID_MESSAGE;                            			// # 8		// int
	uint32_t L_MESSAGE;                              			// # 10		// int
		uint32_t T_TRAIN0;                        		// # 32		// real
	uint32_t M_ACK;                                  			// # 1		// enum
	uint32_t NID_LRBG;                               			// # 24		// int
		uint32_t T_TRAIN1;                        		// # 32	
} 
//=============================================

struct DATA_oETCS_SH_Authorised {
// NAMESPACE = Radio_TrackToTrain
// TransmissionMedia=RBC

	uint32_t NID_MESSAGE;                            			// # 8		// int
	uint32_t L_MESSAGE;                              			// # 10		// int
		uint32_t T_TRAIN0;                        		// # 32		// real
	uint32_t M_ACK;                                  			// # 1		// enum
	uint32_t NID_LRBG;                               			// # 24		// int
		uint32_t T_TRAIN1;                        		// # 32	
	uint32_t PADDING16;                              			// # 5	
	uint32_t SH_Authorised_OptionalPackets;		 // # Length is unknown here; depends on current package number(s)


} 
//=============================================

struct DATA_oETCS_RBC_or_RIU_System_Version {
// NAMESPACE = Radio_TrackToTrain
// TransmissionMedia=RBC, RIU

	uint32_t NID_MESSAGE;                            			// # 8		// int
	uint32_t L_MESSAGE;                              			// # 10		// int
	uint32_t T_TRAIN;                                			// # 32		// real
	uint32_t M_ACK;                                  			// # 1		// enum
	uint32_t NID_LRBG;                               			// # 24		// int
	uint32_t M_VERSION;                              			// # 7	
} 
//=============================================

struct DATA_oETCS_MA_with_Shifted_Location_Reference {
// NAMESPACE = Radio_TrackToTrain
// TransmissionMedia=RBC

	uint32_t NID_MESSAGE;                            			// # 8		// int
	uint32_t L_MESSAGE;                              			// # 10		// int
	uint32_t T_TRAIN;                                			// # 32		// real
	uint32_t M_ACK;                                  			// # 1		// enum
	uint32_t NID_LRBG;                               			// # 24		// int
	uint32_t Q_SCALE;                                			// # 2		// enum
	uint32_t D_REF;                                  			// # 16	
	uint32_t PADDING17;                              			// # 3	
	uint32_t MA_with_Shifted_Location_Reference_OptionalPackets;		 // # Length is unknown here; depends on current package number(s)


} 
//=============================================

struct DATA_oETCS_Track_Ahead_Free_Request {
// NAMESPACE = Radio_TrackToTrain
// TransmissionMedia=RBC

	uint32_t NID_MESSAGE;                            			// # 8		// int
	uint32_t L_MESSAGE;                              			// # 10		// int
	uint32_t T_TRAIN;                                			// # 32		// real
	uint32_t M_ACK;                                  			// # 1		// enum
	uint32_t NID_LRBG;                               			// # 24		// int
	uint32_t Q_SCALE;                                			// # 2		// enum
	uint32_t D_REF;                                  			// # 16		// int
	uint32_t Q_DIR;                                  			// # 2		// enum
	uint32_t D_TAFDISPLAY;                           			// # 15		// int
	uint32_t L_TAFDISPLAY;                           			// # 15		// int
} 
//=============================================

struct DATA_oETCS_Infill_MA {
// NAMESPACE = Radio_TrackToTrain
// TransmissionMedia=RIU

	uint32_t NID_MESSAGE;                            			// # 8		// int
	uint32_t L_MESSAGE;                              			// # 10		// int
	uint32_t T_TRAIN;                                			// # 32		// real
	uint32_t M_ACK;                                  			// # 1		// enum
	uint32_t NID_LRBG;                               			// # 24		// int
	uint32_t PADDING18;                              			// # 5	
	uint32_t Infill_MA_OptionalPackets;		 // # Length is unknown here; depends on current package number(s)


} 
//=============================================

struct DATA_oETCS_Initiation_of_a_communication_session {
// NAMESPACE = Radio_TrackToTrain
// TransmissionMedia=RBC

	uint32_t NID_MESSAGE;                            			// # 8		// int
	uint32_t L_MESSAGE;                              			// # 10		// int
	uint32_t T_TRAIN;                                			// # 32	
	uint32_t M_ACK;                                  			// # 1		// enum
	uint32_t NID_LRBG;                               			// # 24	
} 
//=============================================

struct DATA_oETCS_Acknowledgement_of_termination_of_a_communication_session {
// NAMESPACE = Radio_TrackToTrain
// TransmissionMedia=RBC, RIU

	uint32_t NID_MESSAGE;                            			// # 8		// int
	uint32_t L_MESSAGE;                              			// # 10		// int
	uint32_t T_TRAIN;                                			// # 32		// real
	uint32_t M_ACK;                                  			// # 1	
	uint32_t NID_LRBG;                               			// # 24		// int
} 
//=============================================

struct DATA_oETCS_Train_Rejected {
// NAMESPACE = Radio_TrackToTrain
// TransmissionMedia=RBC

	uint32_t NID_MESSAGE;                            			// # 8		// int
	uint32_t L_MESSAGE;                              			// # 10		// int
	uint32_t T_TRAIN;                                			// # 32		// real
	uint32_t M_ACK;                                  			// # 1		// enum
	uint32_t NID_LRBG;                               			// # 24		// int
} 
//=============================================

struct DATA_oETCS_Train_Accepted {
// NAMESPACE = Radio_TrackToTrain
// TransmissionMedia=RBC

	uint32_t NID_MESSAGE;                            			// # 8		// int
	uint32_t L_MESSAGE;                              			// # 10		// int
	uint32_t T_TRAIN;                                			// # 32		// real
	uint32_t M_ACK;                                  			// # 1		// enum
	uint32_t NID_LRBG;                               			// # 24		// int
} 
//=============================================

struct DATA_oETCS_SoM_position_report_confirmed_by_RBC {
// NAMESPACE = Radio_TrackToTrain
// TransmissionMedia=RBC

	uint32_t NID_MESSAGE;                            			// # 8		// int
	uint32_t L_MESSAGE;                              			// # 10		// int
	uint32_t T_TRAIN;                                			// # 32		// real
	uint32_t M_ACK;                                  			// # 1		// enum
	uint32_t NID_LRBG;                               			// # 24		// int
} 
//=============================================

struct DATA_oETCS_Assignment_of_coordinate_system {
// NAMESPACE = Radio_TrackToTrain
// TransmissionMedia=RBC

	uint32_t NID_MESSAGE;                            			// # 8		// int
	uint32_t L_MESSAGE;                              			// # 10		// int
	uint32_t T_TRAIN;                                			// # 32		// real
	uint32_t M_ACK;                                  			// # 1		// enum
	uint32_t NID_LRBG;                               			// # 24		// int
	uint32_t Q_ORIENTATION;                          			// # 1		// enum
} 
//=============================================
