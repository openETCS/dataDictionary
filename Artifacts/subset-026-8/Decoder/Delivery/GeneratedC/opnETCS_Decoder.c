#include <stdint.h>
#include "subset026_8.h"
#include "Bitwalker.h"


/* 
=============================================================================
Formalization of Subset-026-8 (Chapter 8: ERTMS/ETCS language)

- Name: Subset-026-8 / opnETCS_Decoder.c
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


//Namespace TrainToTrack starts here

void Radio_TrainToTrack_Validated_Train_Data (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_Radio_TrainToTrack_Validated_Train_Data oETCS) 
{ 
 
    T_Bitwalker_Incremental_Locals PeekLocals;
    Bitwalker_IncrementalWalker_Init(&PeekLocals, p_Telegramm, i_akt_dim, bitindex);

// TransmissionMedia=RBC
// Packet Number = 129
	oETCS->aPacket[i_ArrayIndex].NID_MESSAGE                                 = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 8);
	oETCS->aPacket[i_ArrayIndex].L_MESSAGE                                   = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,10);
	oETCS->aPacket[i_ArrayIndex].T_TRAIN                                     = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,32);
	oETCS->aPacket[i_ArrayIndex].NID_ENGINE                                  = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,24);
	oETCS->aPacket[i_ArrayIndex].PADDING0                                    = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 6);
    Bitwalker_IncrementalWalker_Peek_Finish (&PeekLocals);
    return;
    }
// =======================

void Radio_TrainToTrack_Request_for_Shunting (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_Radio_TrainToTrack_Request_for_Shunting oETCS) 
{ 
 
    T_Bitwalker_Incremental_Locals PeekLocals;
    Bitwalker_IncrementalWalker_Init(&PeekLocals, p_Telegramm, i_akt_dim, bitindex);

// TransmissionMedia=RBC
// Packet Number = 130
	oETCS->aPacket[i_ArrayIndex].NID_MESSAGE                                 = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 8);
	oETCS->aPacket[i_ArrayIndex].L_MESSAGE                                   = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,10);
	oETCS->aPacket[i_ArrayIndex].T_TRAIN                                     = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,32);
	oETCS->aPacket[i_ArrayIndex].NID_ENGINE                                  = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,24);
	oETCS->aPacket[i_ArrayIndex].PADDING1                                    = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 6);
    Bitwalker_IncrementalWalker_Peek_Finish (&PeekLocals);
    return;
    }
// =======================

void Radio_TrainToTrack_MA_Request (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_Radio_TrainToTrack_MA_Request oETCS) 
{ 
 
    T_Bitwalker_Incremental_Locals PeekLocals;
    Bitwalker_IncrementalWalker_Init(&PeekLocals, p_Telegramm, i_akt_dim, bitindex);

// TransmissionMedia=RBC
// Packet Number = 132
	oETCS->aPacket[i_ArrayIndex].NID_MESSAGE                                 = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 8);
	oETCS->aPacket[i_ArrayIndex].L_MESSAGE                                   = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,10);
	oETCS->aPacket[i_ArrayIndex].T_TRAIN                                     = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,32);
	oETCS->aPacket[i_ArrayIndex].NID_ENGINE                                  = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,24);
	oETCS->aPacket[i_ArrayIndex].Q_MARQSTREASON                              = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 5);
	oETCS->aPacket[i_ArrayIndex].PADDING2                                    = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 1);
    Bitwalker_IncrementalWalker_Peek_Finish (&PeekLocals);
    return;
    }
// =======================

void Radio_TrainToTrack_Train_Position_Report (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_Radio_TrainToTrack_Train_Position_Report oETCS) 
{ 
 
    T_Bitwalker_Incremental_Locals PeekLocals;
    Bitwalker_IncrementalWalker_Init(&PeekLocals, p_Telegramm, i_akt_dim, bitindex);

// TransmissionMedia=RBC, RIU
// Packet Number = 136
	oETCS->aPacket[i_ArrayIndex].NID_MESSAGE                                 = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 8);
	oETCS->aPacket[i_ArrayIndex].L_MESSAGE                                   = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,10);
	oETCS->aPacket[i_ArrayIndex].T_TRAIN                                     = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,32);
	oETCS->aPacket[i_ArrayIndex].NID_ENGINE                                  = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,24);
	oETCS->aPacket[i_ArrayIndex].PADDING3                                    = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 6);
    Bitwalker_IncrementalWalker_Peek_Finish (&PeekLocals);
    return;
    }
// =======================

void Radio_TrainToTrack_Request_to_shorten_MA_is_granted (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_Radio_TrainToTrack_Request_to_shorten_MA_is_granted oETCS) 
{ 
 
    T_Bitwalker_Incremental_Locals PeekLocals;
    Bitwalker_IncrementalWalker_Init(&PeekLocals, p_Telegramm, i_akt_dim, bitindex);

// TransmissionMedia=RBC
// Packet Number = 137
	oETCS->aPacket[i_ArrayIndex].NID_MESSAGE                                 = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 8);
	oETCS->aPacket[i_ArrayIndex].L_MESSAGE                                   = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,10);
	oETCS->aPacket[i_ArrayIndex].T_TRAIN                                     = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,32);
	oETCS->aPacket[i_ArrayIndex].NID_ENGINE                                  = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,24);
	oETCS->aPacket[i_ArrayIndex].PADDING4                                    = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 6);
    Bitwalker_IncrementalWalker_Peek_Finish (&PeekLocals);
    return;
    }
// =======================

void Radio_TrainToTrack_Request_to_shorten_MA_is_rejected (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_Radio_TrainToTrack_Request_to_shorten_MA_is_rejected oETCS) 
{ 
 
    T_Bitwalker_Incremental_Locals PeekLocals;
    Bitwalker_IncrementalWalker_Init(&PeekLocals, p_Telegramm, i_akt_dim, bitindex);

// TransmissionMedia=RBC
// Packet Number = 138
	oETCS->aPacket[i_ArrayIndex].NID_MESSAGE                                 = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 8);
	oETCS->aPacket[i_ArrayIndex].L_MESSAGE                                   = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,10);
	oETCS->aPacket[i_ArrayIndex].T_TRAIN                                     = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,32);
	oETCS->aPacket[i_ArrayIndex].NID_ENGINE                                  = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,24);
	oETCS->aPacket[i_ArrayIndex].PADDING5                                    = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 6);
    Bitwalker_IncrementalWalker_Peek_Finish (&PeekLocals);
    return;
    }
// =======================

void Radio_TrainToTrack_Acknowledgement (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_Radio_TrainToTrack_Acknowledgement oETCS) 
{ 
 
    T_Bitwalker_Incremental_Locals PeekLocals;
    Bitwalker_IncrementalWalker_Init(&PeekLocals, p_Telegramm, i_akt_dim, bitindex);

// TransmissionMedia=RBC, RIU
// Packet Number = 146
	oETCS->aPacket[i_ArrayIndex].NID_MESSAGE                                 = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 8);
	oETCS->aPacket[i_ArrayIndex].L_MESSAGE                                   = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,10);
	oETCS->aPacket[i_ArrayIndex].T_TRAIN                                     = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,32);
	oETCS->aPacket[i_ArrayIndex].NID_ENGINE                                  = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,24);
    Bitwalker_IncrementalWalker_Peek_Finish (&PeekLocals);
    return;
    }
// =======================

void Radio_TrainToTrack_Acknowledgement_of_Emergency_Stop (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_Radio_TrainToTrack_Acknowledgement_of_Emergency_Stop oETCS) 
{ 
 
    T_Bitwalker_Incremental_Locals PeekLocals;
    Bitwalker_IncrementalWalker_Init(&PeekLocals, p_Telegramm, i_akt_dim, bitindex);

// TransmissionMedia=RBC
// Packet Number = 147
	oETCS->aPacket[i_ArrayIndex].NID_MESSAGE                                 = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 8);
	oETCS->aPacket[i_ArrayIndex].L_MESSAGE                                   = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,10);
	oETCS->aPacket[i_ArrayIndex].T_TRAIN                                     = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,32);
	oETCS->aPacket[i_ArrayIndex].NID_ENGINE                                  = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,24);
	oETCS->aPacket[i_ArrayIndex].NID_EM                                      = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 4);
	oETCS->aPacket[i_ArrayIndex].Q_EMERGENCYSTOP                             = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 2);
    Bitwalker_IncrementalWalker_Peek_Finish (&PeekLocals);
    return;
    }
// =======================

void Radio_TrainToTrack_Track_Ahead_Free_Granted (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_Radio_TrainToTrack_Track_Ahead_Free_Granted oETCS) 
{ 
 
    T_Bitwalker_Incremental_Locals PeekLocals;
    Bitwalker_IncrementalWalker_Init(&PeekLocals, p_Telegramm, i_akt_dim, bitindex);

// TransmissionMedia=RBC
// Packet Number = 149
	oETCS->aPacket[i_ArrayIndex].NID_MESSAGE                                 = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 8);
	oETCS->aPacket[i_ArrayIndex].L_MESSAGE                                   = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,10);
	oETCS->aPacket[i_ArrayIndex].T_TRAIN                                     = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,32);
	oETCS->aPacket[i_ArrayIndex].NID_ENGINE                                  = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,24);
	oETCS->aPacket[i_ArrayIndex].PADDING6                                    = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 6);
    Bitwalker_IncrementalWalker_Peek_Finish (&PeekLocals);
    return;
    }
// =======================

void Radio_TrainToTrack_End_of_Mission (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_Radio_TrainToTrack_End_of_Mission oETCS) 
{ 
 
    T_Bitwalker_Incremental_Locals PeekLocals;
    Bitwalker_IncrementalWalker_Init(&PeekLocals, p_Telegramm, i_akt_dim, bitindex);

// TransmissionMedia=RBC
// Packet Number = 150
	oETCS->aPacket[i_ArrayIndex].NID_MESSAGE                                 = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 8);
	oETCS->aPacket[i_ArrayIndex].L_MESSAGE                                   = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,10);
	oETCS->aPacket[i_ArrayIndex].T_TRAIN                                     = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,32);
	oETCS->aPacket[i_ArrayIndex].NID_ENGINE                                  = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,24);
	oETCS->aPacket[i_ArrayIndex].PADDING7                                    = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 6);
    Bitwalker_IncrementalWalker_Peek_Finish (&PeekLocals);
    return;
    }
// =======================

void Radio_TrainToTrack_Radio_infill_request (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_Radio_TrainToTrack_Radio_infill_request oETCS) 
{ 
 
    T_Bitwalker_Incremental_Locals PeekLocals;
    Bitwalker_IncrementalWalker_Init(&PeekLocals, p_Telegramm, i_akt_dim, bitindex);

// TransmissionMedia=RIU
// Packet Number = 153
	oETCS->aPacket[i_ArrayIndex].NID_MESSAGE                                 = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 8);
	oETCS->aPacket[i_ArrayIndex].L_MESSAGE                                   = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,10);
	oETCS->aPacket[i_ArrayIndex].T_TRAIN                                     = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,32);
	oETCS->aPacket[i_ArrayIndex].NID_ENGINE                                  = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,24);
	oETCS->aPacket[i_ArrayIndex].NID_C                                       = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,10);
	oETCS->aPacket[i_ArrayIndex].NID_BG                                      = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,14);
	oETCS->aPacket[i_ArrayIndex].Q_INFILL                                    = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 1);
	oETCS->aPacket[i_ArrayIndex].PADDING8                                    = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 5);
    Bitwalker_IncrementalWalker_Peek_Finish (&PeekLocals);
    return;
    }
// =======================

void Radio_TrainToTrack_No_compatible_version_supported (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_Radio_TrainToTrack_No_compatible_version_supported oETCS) 
{ 
 
    T_Bitwalker_Incremental_Locals PeekLocals;
    Bitwalker_IncrementalWalker_Init(&PeekLocals, p_Telegramm, i_akt_dim, bitindex);

// TransmissionMedia=RBC, RIU
// Packet Number = 154
	oETCS->aPacket[i_ArrayIndex].NID_MESSAGE                                 = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 8);
	oETCS->aPacket[i_ArrayIndex].L_MESSAGE                                   = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,10);
	oETCS->aPacket[i_ArrayIndex].T_TRAIN                                     = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,32);
	oETCS->aPacket[i_ArrayIndex].NID_ENGINE                                  = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,24);
    Bitwalker_IncrementalWalker_Peek_Finish (&PeekLocals);
    return;
    }
// =======================

void Radio_TrainToTrack_Initiation_of_a_communication_session (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_Radio_TrainToTrack_Initiation_of_a_communication_session oETCS) 
{ 
 
    T_Bitwalker_Incremental_Locals PeekLocals;
    Bitwalker_IncrementalWalker_Init(&PeekLocals, p_Telegramm, i_akt_dim, bitindex);

// TransmissionMedia=RBC, RIU
// Packet Number = 155
	oETCS->aPacket[i_ArrayIndex].NID_MESSAGE                                 = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 8);
	oETCS->aPacket[i_ArrayIndex].L_MESSAGE                                   = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,10);
	oETCS->aPacket[i_ArrayIndex].T_TRAIN                                     = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,32);
	oETCS->aPacket[i_ArrayIndex].NID_ENGINE                                  = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,24);
    Bitwalker_IncrementalWalker_Peek_Finish (&PeekLocals);
    return;
    }
// =======================

void Radio_TrainToTrack_Termination_of_a_communication_session (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_Radio_TrainToTrack_Termination_of_a_communication_session oETCS) 
{ 
 
    T_Bitwalker_Incremental_Locals PeekLocals;
    Bitwalker_IncrementalWalker_Init(&PeekLocals, p_Telegramm, i_akt_dim, bitindex);

// TransmissionMedia=RBC, RIU
// Packet Number = 156
	oETCS->aPacket[i_ArrayIndex].NID_MESSAGE                                 = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 8);
	oETCS->aPacket[i_ArrayIndex].L_MESSAGE                                   = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,10);
	oETCS->aPacket[i_ArrayIndex].T_TRAIN                                     = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,32);
	oETCS->aPacket[i_ArrayIndex].NID_ENGINE                                  = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,24);
    Bitwalker_IncrementalWalker_Peek_Finish (&PeekLocals);
    return;
    }
// =======================

void Radio_TrainToTrack_SoM_Position_Report (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_Radio_TrainToTrack_SoM_Position_Report oETCS) 
{ 
 
    T_Bitwalker_Incremental_Locals PeekLocals;
    Bitwalker_IncrementalWalker_Init(&PeekLocals, p_Telegramm, i_akt_dim, bitindex);

// TransmissionMedia=RBC
// Packet Number = 157
	oETCS->aPacket[i_ArrayIndex].NID_MESSAGE                                 = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 8);
	oETCS->aPacket[i_ArrayIndex].L_MESSAGE                                   = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,10);
	oETCS->aPacket[i_ArrayIndex].T_TRAIN                                     = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,32);
	oETCS->aPacket[i_ArrayIndex].NID_ENGINE                                  = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,24);
	oETCS->aPacket[i_ArrayIndex].Q_STATUS                                    = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 2);
	oETCS->aPacket[i_ArrayIndex].PADDING9                                    = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 4);
    Bitwalker_IncrementalWalker_Peek_Finish (&PeekLocals);
    return;
    }
// =======================

void Radio_TrainToTrack_Text_message_acknowledged_by_driver (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_Radio_TrainToTrack_Text_message_acknowledged_by_driver oETCS) 
{ 
 
    T_Bitwalker_Incremental_Locals PeekLocals;
    Bitwalker_IncrementalWalker_Init(&PeekLocals, p_Telegramm, i_akt_dim, bitindex);

// TransmissionMedia=RBC
// Packet Number = 158
	oETCS->aPacket[i_ArrayIndex].NID_MESSAGE                                 = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 8);
	oETCS->aPacket[i_ArrayIndex].L_MESSAGE                                   = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,10);
	oETCS->aPacket[i_ArrayIndex].T_TRAIN                                     = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,32);
	oETCS->aPacket[i_ArrayIndex].NID_ENGINE                                  = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,24);
	oETCS->aPacket[i_ArrayIndex].NID_TEXTMESSAGE                             = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 8);
	oETCS->aPacket[i_ArrayIndex].PADDING10                                   = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 6);
    Bitwalker_IncrementalWalker_Peek_Finish (&PeekLocals);
    return;
    }
// =======================

void Radio_TrainToTrack_Session_Established (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_Radio_TrainToTrack_Session_Established oETCS) 
{ 
 
    T_Bitwalker_Incremental_Locals PeekLocals;
    Bitwalker_IncrementalWalker_Init(&PeekLocals, p_Telegramm, i_akt_dim, bitindex);

// TransmissionMedia=RBC, RIU
// Packet Number = 159
	oETCS->aPacket[i_ArrayIndex].NID_MESSAGE                                 = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 8);
	oETCS->aPacket[i_ArrayIndex].L_MESSAGE                                   = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,10);
	oETCS->aPacket[i_ArrayIndex].T_TRAIN                                     = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,32);
	oETCS->aPacket[i_ArrayIndex].NID_ENGINE                                  = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,24);
	oETCS->aPacket[i_ArrayIndex].PADDING11                                   = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 6);
    Bitwalker_IncrementalWalker_Peek_Finish (&PeekLocals);
    return;
    }
// =======================

//Namespace Radio_TrainToTrack ends here

//Namespace TrackToTrain starts here

void Radio_TrackToTrain_SR_Authorisation (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_Radio_TrackToTrain_SR_Authorisation oETCS) 
{ 
 
    T_Bitwalker_Incremental_Locals PeekLocals;
    Bitwalker_IncrementalWalker_Init(&PeekLocals, p_Telegramm, i_akt_dim, bitindex);

// TransmissionMedia=RBC
// Packet Number = 2
	oETCS->aPacket[i_ArrayIndex].NID_MESSAGE                                 = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 8);
	oETCS->aPacket[i_ArrayIndex].L_MESSAGE                                   = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,10);
	oETCS->aPacket[i_ArrayIndex].T_TRAIN                                     = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,32);
	oETCS->aPacket[i_ArrayIndex].M_ACK                                       = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 1);
	oETCS->aPacket[i_ArrayIndex].NID_LRBG                                    = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,24);
	oETCS->aPacket[i_ArrayIndex].Q_SCALE                                     = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 2);
	oETCS->aPacket[i_ArrayIndex].D_SR                                        = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,15);
	oETCS->aPacket[i_ArrayIndex].PADDING12                                   = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 4);
    Bitwalker_IncrementalWalker_Peek_Finish (&PeekLocals);
    return;
    }
// =======================

void Radio_TrackToTrain_Movement_Authority (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_Radio_TrackToTrain_Movement_Authority oETCS) 
{ 
 
    T_Bitwalker_Incremental_Locals PeekLocals;
    Bitwalker_IncrementalWalker_Init(&PeekLocals, p_Telegramm, i_akt_dim, bitindex);

// TransmissionMedia=RBC
// Packet Number = 3
	oETCS->aPacket[i_ArrayIndex].NID_MESSAGE                                 = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 8);
	oETCS->aPacket[i_ArrayIndex].L_MESSAGE                                   = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,10);
	oETCS->aPacket[i_ArrayIndex].T_TRAIN                                     = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,32);
	oETCS->aPacket[i_ArrayIndex].M_ACK                                       = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 1);
	oETCS->aPacket[i_ArrayIndex].NID_LRBG                                    = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,24);
	oETCS->aPacket[i_ArrayIndex].PADDING13                                   = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 5);
    Bitwalker_IncrementalWalker_Peek_Finish (&PeekLocals);
    return;
    }
// =======================

void Radio_TrackToTrain_Recognition_of_exit_from_TRIP_mode (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_Radio_TrackToTrain_Recognition_of_exit_from_TRIP_mode oETCS) 
{ 
 
    T_Bitwalker_Incremental_Locals PeekLocals;
    Bitwalker_IncrementalWalker_Init(&PeekLocals, p_Telegramm, i_akt_dim, bitindex);

// TransmissionMedia=RBC
// Packet Number = 6
	oETCS->aPacket[i_ArrayIndex].NID_MESSAGE                                 = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 8);
	oETCS->aPacket[i_ArrayIndex].L_MESSAGE                                   = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,10);
	oETCS->aPacket[i_ArrayIndex].T_TRAIN                                     = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,32);
	oETCS->aPacket[i_ArrayIndex].M_ACK                                       = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 1);
	oETCS->aPacket[i_ArrayIndex].NID_LRBG                                    = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,24);
    Bitwalker_IncrementalWalker_Peek_Finish (&PeekLocals);
    return;
    }
// =======================

void Radio_TrackToTrain_Acknowledgement_of_Train_Data (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_Radio_TrackToTrain_Acknowledgement_of_Train_Data oETCS) 
{ 
 
    T_Bitwalker_Incremental_Locals PeekLocals;
    Bitwalker_IncrementalWalker_Init(&PeekLocals, p_Telegramm, i_akt_dim, bitindex);

// TransmissionMedia=RBC
// Packet Number = 8
	oETCS->aPacket[i_ArrayIndex].NID_MESSAGE                                 = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 8);
	oETCS->aPacket[i_ArrayIndex].L_MESSAGE                                   = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,10);
	oETCS->aPacket[i_ArrayIndex].T_TRAIN0                                    = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,32);
	oETCS->aPacket[i_ArrayIndex].M_ACK                                       = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 1);
	oETCS->aPacket[i_ArrayIndex].NID_LRBG                                    = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,24);
	oETCS->aPacket[i_ArrayIndex].T_TRAIN1                                    = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,32);
    Bitwalker_IncrementalWalker_Peek_Finish (&PeekLocals);
    return;
    }
// =======================

void Radio_TrackToTrain_Request_to_Shorten_MA (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_Radio_TrackToTrain_Request_to_Shorten_MA oETCS) 
{ 
 
    T_Bitwalker_Incremental_Locals PeekLocals;
    Bitwalker_IncrementalWalker_Init(&PeekLocals, p_Telegramm, i_akt_dim, bitindex);

// TransmissionMedia=RBC
// Packet Number = 9
	oETCS->aPacket[i_ArrayIndex].NID_MESSAGE                                 = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 8);
	oETCS->aPacket[i_ArrayIndex].L_MESSAGE                                   = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,10);
	oETCS->aPacket[i_ArrayIndex].T_TRAIN                                     = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,32);
	oETCS->aPacket[i_ArrayIndex].M_ACK                                       = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 1);
	oETCS->aPacket[i_ArrayIndex].NID_LRBG                                    = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,24);
	oETCS->aPacket[i_ArrayIndex].PADDING14                                   = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 5);
    Bitwalker_IncrementalWalker_Peek_Finish (&PeekLocals);
    return;
    }
// =======================

void Radio_TrackToTrain_Conditional_Emergency_Stop (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_Radio_TrackToTrain_Conditional_Emergency_Stop oETCS) 
{ 
 
    T_Bitwalker_Incremental_Locals PeekLocals;
    Bitwalker_IncrementalWalker_Init(&PeekLocals, p_Telegramm, i_akt_dim, bitindex);

// TransmissionMedia=RBC
// Packet Number = 15
	oETCS->aPacket[i_ArrayIndex].NID_MESSAGE                                 = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 8);
	oETCS->aPacket[i_ArrayIndex].L_MESSAGE                                   = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,10);
	oETCS->aPacket[i_ArrayIndex].T_TRAIN                                     = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,32);
	oETCS->aPacket[i_ArrayIndex].M_ACK                                       = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 1);
	oETCS->aPacket[i_ArrayIndex].NID_LRBG                                    = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,24);
	oETCS->aPacket[i_ArrayIndex].NID_EM                                      = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 4);
	oETCS->aPacket[i_ArrayIndex].Q_SCALE                                     = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 2);
	oETCS->aPacket[i_ArrayIndex].D_REF                                       = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,16);
	oETCS->aPacket[i_ArrayIndex].Q_DIR                                       = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 2);
	oETCS->aPacket[i_ArrayIndex].D_EMERGENCYSTOP                             = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,15);
    Bitwalker_IncrementalWalker_Peek_Finish (&PeekLocals);
    return;
    }
// =======================

void Radio_TrackToTrain_Unconditional_Emergency_Stop (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_Radio_TrackToTrain_Unconditional_Emergency_Stop oETCS) 
{ 
 
    T_Bitwalker_Incremental_Locals PeekLocals;
    Bitwalker_IncrementalWalker_Init(&PeekLocals, p_Telegramm, i_akt_dim, bitindex);

// TransmissionMedia=RBC
// Packet Number = 16
	oETCS->aPacket[i_ArrayIndex].NID_MESSAGE                                 = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 8);
	oETCS->aPacket[i_ArrayIndex].L_MESSAGE                                   = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,10);
	oETCS->aPacket[i_ArrayIndex].T_TRAIN                                     = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,32);
	oETCS->aPacket[i_ArrayIndex].M_ACK                                       = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 1);
	oETCS->aPacket[i_ArrayIndex].NID_LRBG                                    = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,24);
	oETCS->aPacket[i_ArrayIndex].NID_EM                                      = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 4);
    Bitwalker_IncrementalWalker_Peek_Finish (&PeekLocals);
    return;
    }
// =======================

void Radio_TrackToTrain_Revocation_of_Emergency_Stop (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_Radio_TrackToTrain_Revocation_of_Emergency_Stop oETCS) 
{ 
 
    T_Bitwalker_Incremental_Locals PeekLocals;
    Bitwalker_IncrementalWalker_Init(&PeekLocals, p_Telegramm, i_akt_dim, bitindex);

// TransmissionMedia=RBC
// Packet Number = 18
	oETCS->aPacket[i_ArrayIndex].NID_MESSAGE                                 = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 8);
	oETCS->aPacket[i_ArrayIndex].L_MESSAGE                                   = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,10);
	oETCS->aPacket[i_ArrayIndex].T_TRAIN                                     = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,32);
	oETCS->aPacket[i_ArrayIndex].M_ACK                                       = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 1);
	oETCS->aPacket[i_ArrayIndex].NID_LRBG                                    = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,24);
	oETCS->aPacket[i_ArrayIndex].NID_EM                                      = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 4);
    Bitwalker_IncrementalWalker_Peek_Finish (&PeekLocals);
    return;
    }
// =======================

void Radio_TrackToTrain_General_message (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_Radio_TrackToTrain_General_message oETCS) 
{ 
 
    T_Bitwalker_Incremental_Locals PeekLocals;
    Bitwalker_IncrementalWalker_Init(&PeekLocals, p_Telegramm, i_akt_dim, bitindex);

// TransmissionMedia=RBC, RIU
// Packet Number = 24
	oETCS->aPacket[i_ArrayIndex].NID_MESSAGE                                 = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 8);
	oETCS->aPacket[i_ArrayIndex].L_MESSAGE                                   = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,10);
	oETCS->aPacket[i_ArrayIndex].T_TRAIN                                     = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,32);
	oETCS->aPacket[i_ArrayIndex].M_ACK                                       = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 1);
	oETCS->aPacket[i_ArrayIndex].NID_LRBG                                    = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,24);
	oETCS->aPacket[i_ArrayIndex].PADDING15                                   = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 5);
    Bitwalker_IncrementalWalker_Peek_Finish (&PeekLocals);
    return;
    }
// =======================

void Radio_TrackToTrain_SH_Refused (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_Radio_TrackToTrain_SH_Refused oETCS) 
{ 
 
    T_Bitwalker_Incremental_Locals PeekLocals;
    Bitwalker_IncrementalWalker_Init(&PeekLocals, p_Telegramm, i_akt_dim, bitindex);

// TransmissionMedia=RBC
// Packet Number = 27
	oETCS->aPacket[i_ArrayIndex].NID_MESSAGE                                 = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 8);
	oETCS->aPacket[i_ArrayIndex].L_MESSAGE                                   = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,10);
	oETCS->aPacket[i_ArrayIndex].T_TRAIN0                                    = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,32);
	oETCS->aPacket[i_ArrayIndex].M_ACK                                       = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 1);
	oETCS->aPacket[i_ArrayIndex].NID_LRBG                                    = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,24);
	oETCS->aPacket[i_ArrayIndex].T_TRAIN1                                    = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,32);
    Bitwalker_IncrementalWalker_Peek_Finish (&PeekLocals);
    return;
    }
// =======================

void Radio_TrackToTrain_SH_Authorised (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_Radio_TrackToTrain_SH_Authorised oETCS) 
{ 
 
    T_Bitwalker_Incremental_Locals PeekLocals;
    Bitwalker_IncrementalWalker_Init(&PeekLocals, p_Telegramm, i_akt_dim, bitindex);

// TransmissionMedia=RBC
// Packet Number = 28
	oETCS->aPacket[i_ArrayIndex].NID_MESSAGE                                 = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 8);
	oETCS->aPacket[i_ArrayIndex].L_MESSAGE                                   = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,10);
	oETCS->aPacket[i_ArrayIndex].T_TRAIN0                                    = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,32);
	oETCS->aPacket[i_ArrayIndex].M_ACK                                       = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 1);
	oETCS->aPacket[i_ArrayIndex].NID_LRBG                                    = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,24);
	oETCS->aPacket[i_ArrayIndex].T_TRAIN1                                    = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,32);
	oETCS->aPacket[i_ArrayIndex].PADDING16                                   = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 5);
    Bitwalker_IncrementalWalker_Peek_Finish (&PeekLocals);
    return;
    }
// =======================

void Radio_TrackToTrain_RBC_or_RIU_System_Version (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_Radio_TrackToTrain_RBC_or_RIU_System_Version oETCS) 
{ 
 
    T_Bitwalker_Incremental_Locals PeekLocals;
    Bitwalker_IncrementalWalker_Init(&PeekLocals, p_Telegramm, i_akt_dim, bitindex);

// TransmissionMedia=RBC, RIU
// Packet Number = 32
	oETCS->aPacket[i_ArrayIndex].NID_MESSAGE                                 = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 8);
	oETCS->aPacket[i_ArrayIndex].L_MESSAGE                                   = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,10);
	oETCS->aPacket[i_ArrayIndex].T_TRAIN                                     = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,32);
	oETCS->aPacket[i_ArrayIndex].M_ACK                                       = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 1);
	oETCS->aPacket[i_ArrayIndex].NID_LRBG                                    = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,24);
	oETCS->aPacket[i_ArrayIndex].M_VERSION                                   = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 7);
    Bitwalker_IncrementalWalker_Peek_Finish (&PeekLocals);
    return;
    }
// =======================

void Radio_TrackToTrain_MA_with_Shifted_Location_Reference (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_Radio_TrackToTrain_MA_with_Shifted_Location_Reference oETCS) 
{ 
 
    T_Bitwalker_Incremental_Locals PeekLocals;
    Bitwalker_IncrementalWalker_Init(&PeekLocals, p_Telegramm, i_akt_dim, bitindex);

// TransmissionMedia=RBC
// Packet Number = 33
	oETCS->aPacket[i_ArrayIndex].NID_MESSAGE                                 = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 8);
	oETCS->aPacket[i_ArrayIndex].L_MESSAGE                                   = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,10);
	oETCS->aPacket[i_ArrayIndex].T_TRAIN                                     = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,32);
	oETCS->aPacket[i_ArrayIndex].M_ACK                                       = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 1);
	oETCS->aPacket[i_ArrayIndex].NID_LRBG                                    = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,24);
	oETCS->aPacket[i_ArrayIndex].Q_SCALE                                     = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 2);
	oETCS->aPacket[i_ArrayIndex].D_REF                                       = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,16);
	oETCS->aPacket[i_ArrayIndex].PADDING17                                   = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 3);
    Bitwalker_IncrementalWalker_Peek_Finish (&PeekLocals);
    return;
    }
// =======================

void Radio_TrackToTrain_Track_Ahead_Free_Request (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_Radio_TrackToTrain_Track_Ahead_Free_Request oETCS) 
{ 
 
    T_Bitwalker_Incremental_Locals PeekLocals;
    Bitwalker_IncrementalWalker_Init(&PeekLocals, p_Telegramm, i_akt_dim, bitindex);

// TransmissionMedia=RBC
// Packet Number = 34
	oETCS->aPacket[i_ArrayIndex].NID_MESSAGE                                 = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 8);
	oETCS->aPacket[i_ArrayIndex].L_MESSAGE                                   = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,10);
	oETCS->aPacket[i_ArrayIndex].T_TRAIN                                     = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,32);
	oETCS->aPacket[i_ArrayIndex].M_ACK                                       = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 1);
	oETCS->aPacket[i_ArrayIndex].NID_LRBG                                    = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,24);
	oETCS->aPacket[i_ArrayIndex].Q_SCALE                                     = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 2);
	oETCS->aPacket[i_ArrayIndex].D_REF                                       = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,16);
	oETCS->aPacket[i_ArrayIndex].Q_DIR                                       = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 2);
	oETCS->aPacket[i_ArrayIndex].D_TAFDISPLAY                                = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,15);
	oETCS->aPacket[i_ArrayIndex].L_TAFDISPLAY                                = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,15);
    Bitwalker_IncrementalWalker_Peek_Finish (&PeekLocals);
    return;
    }
// =======================

void Radio_TrackToTrain_Infill_MA (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_Radio_TrackToTrain_Infill_MA oETCS) 
{ 
 
    T_Bitwalker_Incremental_Locals PeekLocals;
    Bitwalker_IncrementalWalker_Init(&PeekLocals, p_Telegramm, i_akt_dim, bitindex);

// TransmissionMedia=RIU
// Packet Number = 37
	oETCS->aPacket[i_ArrayIndex].NID_MESSAGE                                 = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 8);
	oETCS->aPacket[i_ArrayIndex].L_MESSAGE                                   = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,10);
	oETCS->aPacket[i_ArrayIndex].T_TRAIN                                     = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,32);
	oETCS->aPacket[i_ArrayIndex].M_ACK                                       = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 1);
	oETCS->aPacket[i_ArrayIndex].NID_LRBG                                    = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,24);
	oETCS->aPacket[i_ArrayIndex].PADDING18                                   = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 5);
    Bitwalker_IncrementalWalker_Peek_Finish (&PeekLocals);
    return;
    }
// =======================

void Radio_TrackToTrain_Initiation_of_a_communication_session (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_Radio_TrackToTrain_Initiation_of_a_communication_session oETCS) 
{ 
 
    T_Bitwalker_Incremental_Locals PeekLocals;
    Bitwalker_IncrementalWalker_Init(&PeekLocals, p_Telegramm, i_akt_dim, bitindex);

// TransmissionMedia=RBC
// Packet Number = 38
	oETCS->aPacket[i_ArrayIndex].NID_MESSAGE                                 = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 8);
	oETCS->aPacket[i_ArrayIndex].L_MESSAGE                                   = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,10);
	oETCS->aPacket[i_ArrayIndex].T_TRAIN                                     = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,32);
	oETCS->aPacket[i_ArrayIndex].M_ACK                                       = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 1);
	oETCS->aPacket[i_ArrayIndex].NID_LRBG                                    = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,24);
    Bitwalker_IncrementalWalker_Peek_Finish (&PeekLocals);
    return;
    }
// =======================

void Radio_TrackToTrain_Acknowledgement_of_termination_of_a_communication_session (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_Radio_TrackToTrain_Acknowledgement_of_termination_of_a_communication_session oETCS) 
{ 
 
    T_Bitwalker_Incremental_Locals PeekLocals;
    Bitwalker_IncrementalWalker_Init(&PeekLocals, p_Telegramm, i_akt_dim, bitindex);

// TransmissionMedia=RBC, RIU
// Packet Number = 39
	oETCS->aPacket[i_ArrayIndex].NID_MESSAGE                                 = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 8);
	oETCS->aPacket[i_ArrayIndex].L_MESSAGE                                   = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,10);
	oETCS->aPacket[i_ArrayIndex].T_TRAIN                                     = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,32);
	oETCS->aPacket[i_ArrayIndex].M_ACK                                       = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 1);
	oETCS->aPacket[i_ArrayIndex].NID_LRBG                                    = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,24);
    Bitwalker_IncrementalWalker_Peek_Finish (&PeekLocals);
    return;
    }
// =======================

void Radio_TrackToTrain_Train_Rejected (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_Radio_TrackToTrain_Train_Rejected oETCS) 
{ 
 
    T_Bitwalker_Incremental_Locals PeekLocals;
    Bitwalker_IncrementalWalker_Init(&PeekLocals, p_Telegramm, i_akt_dim, bitindex);

// TransmissionMedia=RBC
// Packet Number = 40
	oETCS->aPacket[i_ArrayIndex].NID_MESSAGE                                 = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 8);
	oETCS->aPacket[i_ArrayIndex].L_MESSAGE                                   = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,10);
	oETCS->aPacket[i_ArrayIndex].T_TRAIN                                     = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,32);
	oETCS->aPacket[i_ArrayIndex].M_ACK                                       = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 1);
	oETCS->aPacket[i_ArrayIndex].NID_LRBG                                    = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,24);
    Bitwalker_IncrementalWalker_Peek_Finish (&PeekLocals);
    return;
    }
// =======================

void Radio_TrackToTrain_Train_Accepted (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_Radio_TrackToTrain_Train_Accepted oETCS) 
{ 
 
    T_Bitwalker_Incremental_Locals PeekLocals;
    Bitwalker_IncrementalWalker_Init(&PeekLocals, p_Telegramm, i_akt_dim, bitindex);

// TransmissionMedia=RBC
// Packet Number = 41
	oETCS->aPacket[i_ArrayIndex].NID_MESSAGE                                 = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 8);
	oETCS->aPacket[i_ArrayIndex].L_MESSAGE                                   = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,10);
	oETCS->aPacket[i_ArrayIndex].T_TRAIN                                     = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,32);
	oETCS->aPacket[i_ArrayIndex].M_ACK                                       = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 1);
	oETCS->aPacket[i_ArrayIndex].NID_LRBG                                    = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,24);
    Bitwalker_IncrementalWalker_Peek_Finish (&PeekLocals);
    return;
    }
// =======================

void Radio_TrackToTrain_SoM_position_report_confirmed_by_RBC (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_Radio_TrackToTrain_SoM_position_report_confirmed_by_RBC oETCS) 
{ 
 
    T_Bitwalker_Incremental_Locals PeekLocals;
    Bitwalker_IncrementalWalker_Init(&PeekLocals, p_Telegramm, i_akt_dim, bitindex);

// TransmissionMedia=RBC
// Packet Number = 43
	oETCS->aPacket[i_ArrayIndex].NID_MESSAGE                                 = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 8);
	oETCS->aPacket[i_ArrayIndex].L_MESSAGE                                   = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,10);
	oETCS->aPacket[i_ArrayIndex].T_TRAIN                                     = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,32);
	oETCS->aPacket[i_ArrayIndex].M_ACK                                       = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 1);
	oETCS->aPacket[i_ArrayIndex].NID_LRBG                                    = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,24);
    Bitwalker_IncrementalWalker_Peek_Finish (&PeekLocals);
    return;
    }
// =======================

void Radio_TrackToTrain_Assignment_of_coordinate_system (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_Radio_TrackToTrain_Assignment_of_coordinate_system oETCS) 
{ 
 
    T_Bitwalker_Incremental_Locals PeekLocals;
    Bitwalker_IncrementalWalker_Init(&PeekLocals, p_Telegramm, i_akt_dim, bitindex);

// TransmissionMedia=RBC
// Packet Number = 45
	oETCS->aPacket[i_ArrayIndex].NID_MESSAGE                                 = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 8);
	oETCS->aPacket[i_ArrayIndex].L_MESSAGE                                   = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,10);
	oETCS->aPacket[i_ArrayIndex].T_TRAIN                                     = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,32);
	oETCS->aPacket[i_ArrayIndex].M_ACK                                       = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 1);
	oETCS->aPacket[i_ArrayIndex].NID_LRBG                                    = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,24);
	oETCS->aPacket[i_ArrayIndex].Q_ORIENTATION                               = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 1);
    Bitwalker_IncrementalWalker_Peek_Finish (&PeekLocals);
    return;
    }
// =======================

//Namespace Radio_TrackToTrain ends here
