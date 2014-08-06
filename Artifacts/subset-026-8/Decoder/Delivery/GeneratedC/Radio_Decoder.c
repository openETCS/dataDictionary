#include <stdint.h>
#include "subset026_8.h"
#include "Bitwalker.h"
#include "Radio_Decoder.h"
#include "Radio_DecoderBranch8.h"



/* 
=============================================================================
Formalization of Subset-026-8 (Chapter 8: ERTMS/ETCS language)

- Name: Subset-026-8 / Radio_Decoder.c
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


//NAMESPACE = TrainToTrack starts here

int TrainToTrack_Message_129 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_Radio_TrainToTrack_Validated_Train_Data Radio) 
{ 
 
    T_Bitwalker_Incremental_Locals PeekLocals;
    Bitwalker_IncrementalWalker_Init(&PeekLocals, p_Telegramm, i_akt_dim, bitindex);

// Packet Number = 129
	Radio->Message[i_ArrayIndex].NID_MESSAGE                                 = (int)   Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 8);
	Radio->Message[i_ArrayIndex].L_MESSAGE                                   = (int)   Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,10);
	Radio->Message[i_ArrayIndex].T_TRAIN                                     = (float) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,32);
	Radio->Message[i_ArrayIndex].NID_ENGINE                                  = (int)   Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,24);
	Radio->Message[i_ArrayIndex].PADDING0                                    = (int)   Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 6);
    return Bitwalker_IncrementalWalker_Peek_Finish (&PeekLocals);
    }
// =======================

int TrainToTrack_Message_130 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_Radio_TrainToTrack_Request_for_Shunting Radio) 
{ 
 
    T_Bitwalker_Incremental_Locals PeekLocals;
    Bitwalker_IncrementalWalker_Init(&PeekLocals, p_Telegramm, i_akt_dim, bitindex);

// Packet Number = 130
	Radio->Message[i_ArrayIndex].NID_MESSAGE                                 = (int)   Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 8);
	Radio->Message[i_ArrayIndex].L_MESSAGE                                   = (int)   Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,10);
	Radio->Message[i_ArrayIndex].T_TRAIN                                     = (float) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,32);
	Radio->Message[i_ArrayIndex].NID_ENGINE                                  = (int)   Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,24);
	Radio->Message[i_ArrayIndex].PADDING1                                    = (int)   Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 6);
    return Bitwalker_IncrementalWalker_Peek_Finish (&PeekLocals);
    }
// =======================

int TrainToTrack_Message_132 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_Radio_TrainToTrack_MA_Request Radio) 
{ 
 
    T_Bitwalker_Incremental_Locals PeekLocals;
    Bitwalker_IncrementalWalker_Init(&PeekLocals, p_Telegramm, i_akt_dim, bitindex);

// Packet Number = 132
	Radio->Message[i_ArrayIndex].NID_MESSAGE                                 = (int)   Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 8);
	Radio->Message[i_ArrayIndex].L_MESSAGE                                   = (int)   Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,10);
	Radio->Message[i_ArrayIndex].T_TRAIN                                     = (float) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,32);
	Radio->Message[i_ArrayIndex].NID_ENGINE                                  = (int)   Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,24);
	Radio->Message[i_ArrayIndex].Q_MARQSTREASON                              = (T_q_marqstreason) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 5);
	Radio->Message[i_ArrayIndex].PADDING2                                    = (int)   Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 1);
    return Bitwalker_IncrementalWalker_Peek_Finish (&PeekLocals);
    }
// =======================

int TrainToTrack_Message_136 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_Radio_TrainToTrack_Train_Position_Report Radio) 
{ 
 
    T_Bitwalker_Incremental_Locals PeekLocals;
    Bitwalker_IncrementalWalker_Init(&PeekLocals, p_Telegramm, i_akt_dim, bitindex);

// Packet Number = 136
	Radio->Message[i_ArrayIndex].NID_MESSAGE                                 = (int)   Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 8);
	Radio->Message[i_ArrayIndex].L_MESSAGE                                   = (int)   Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,10);
	Radio->Message[i_ArrayIndex].T_TRAIN                                     = (float) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,32);
	Radio->Message[i_ArrayIndex].NID_ENGINE                                  = (int)   Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,24);
	Radio->Message[i_ArrayIndex].PADDING3                                    = (int)   Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 6);
    return Bitwalker_IncrementalWalker_Peek_Finish (&PeekLocals);
    }
// =======================

int TrainToTrack_Message_137 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_Radio_TrainToTrack_Request_to_shorten_MA_is_granted Radio) 
{ 
 
    T_Bitwalker_Incremental_Locals PeekLocals;
    Bitwalker_IncrementalWalker_Init(&PeekLocals, p_Telegramm, i_akt_dim, bitindex);

// Packet Number = 137
	Radio->Message[i_ArrayIndex].NID_MESSAGE                                 = (int)   Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 8);
	Radio->Message[i_ArrayIndex].L_MESSAGE                                   = (int)   Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,10);
	Radio->Message[i_ArrayIndex].T_TRAIN                                     = (float) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,32);
	Radio->Message[i_ArrayIndex].NID_ENGINE                                  = (int)   Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,24);
	Radio->Message[i_ArrayIndex].PADDING4                                    = (int)   Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 6);
    return Bitwalker_IncrementalWalker_Peek_Finish (&PeekLocals);
    }
// =======================

int TrainToTrack_Message_138 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_Radio_TrainToTrack_Request_to_shorten_MA_is_rejected Radio) 
{ 
 
    T_Bitwalker_Incremental_Locals PeekLocals;
    Bitwalker_IncrementalWalker_Init(&PeekLocals, p_Telegramm, i_akt_dim, bitindex);

// Packet Number = 138
	Radio->Message[i_ArrayIndex].NID_MESSAGE                                 = (int)   Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 8);
	Radio->Message[i_ArrayIndex].L_MESSAGE                                   = (int)   Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,10);
	Radio->Message[i_ArrayIndex].T_TRAIN                                     = (float) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,32);
	Radio->Message[i_ArrayIndex].NID_ENGINE                                  = (int)   Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,24);
	Radio->Message[i_ArrayIndex].PADDING5                                    = (int)   Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 6);
    return Bitwalker_IncrementalWalker_Peek_Finish (&PeekLocals);
    }
// =======================

int TrainToTrack_Message_146 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_Radio_TrainToTrack_Acknowledgement Radio) 
{ 
 
    T_Bitwalker_Incremental_Locals PeekLocals;
    Bitwalker_IncrementalWalker_Init(&PeekLocals, p_Telegramm, i_akt_dim, bitindex);

// Packet Number = 146
	Radio->Message[i_ArrayIndex].NID_MESSAGE                                 = (int)   Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 8);
	Radio->Message[i_ArrayIndex].L_MESSAGE                                   = (int)   Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,10);
	Radio->Message[i_ArrayIndex].T_TRAIN                                     = (float) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,32);
	Radio->Message[i_ArrayIndex].NID_ENGINE                                  = (int)   Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,24);
    return Bitwalker_IncrementalWalker_Peek_Finish (&PeekLocals);
    }
// =======================

int TrainToTrack_Message_147 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_Radio_TrainToTrack_Acknowledgement_of_Emergency_Stop Radio) 
{ 
 
    T_Bitwalker_Incremental_Locals PeekLocals;
    Bitwalker_IncrementalWalker_Init(&PeekLocals, p_Telegramm, i_akt_dim, bitindex);

// Packet Number = 147
	Radio->Message[i_ArrayIndex].NID_MESSAGE                                 = (int)   Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 8);
	Radio->Message[i_ArrayIndex].L_MESSAGE                                   = (int)   Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,10);
	Radio->Message[i_ArrayIndex].T_TRAIN                                     = (float) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,32);
	Radio->Message[i_ArrayIndex].NID_ENGINE                                  = (int)   Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,24);
	Radio->Message[i_ArrayIndex].NID_EM                                      = (int)   Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 4);
	Radio->Message[i_ArrayIndex].Q_EMERGENCYSTOP                             = (T_q_emergencystop) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 2);
    return Bitwalker_IncrementalWalker_Peek_Finish (&PeekLocals);
    }
// =======================

int TrainToTrack_Message_149 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_Radio_TrainToTrack_Track_Ahead_Free_Granted Radio) 
{ 
 
    T_Bitwalker_Incremental_Locals PeekLocals;
    Bitwalker_IncrementalWalker_Init(&PeekLocals, p_Telegramm, i_akt_dim, bitindex);

// Packet Number = 149
	Radio->Message[i_ArrayIndex].NID_MESSAGE                                 = (int)   Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 8);
	Radio->Message[i_ArrayIndex].L_MESSAGE                                   = (int)   Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,10);
	Radio->Message[i_ArrayIndex].T_TRAIN                                     = (float) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,32);
	Radio->Message[i_ArrayIndex].NID_ENGINE                                  = (int)   Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,24);
	Radio->Message[i_ArrayIndex].PADDING6                                    = (int)   Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 6);
    return Bitwalker_IncrementalWalker_Peek_Finish (&PeekLocals);
    }
// =======================

int TrainToTrack_Message_150 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_Radio_TrainToTrack_End_of_Mission Radio) 
{ 
 
    T_Bitwalker_Incremental_Locals PeekLocals;
    Bitwalker_IncrementalWalker_Init(&PeekLocals, p_Telegramm, i_akt_dim, bitindex);

// Packet Number = 150
	Radio->Message[i_ArrayIndex].NID_MESSAGE                                 = (int)   Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 8);
	Radio->Message[i_ArrayIndex].L_MESSAGE                                   = (int)   Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,10);
	Radio->Message[i_ArrayIndex].T_TRAIN                                     = (float) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,32);
	Radio->Message[i_ArrayIndex].NID_ENGINE                                  = (int)   Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,24);
	Radio->Message[i_ArrayIndex].PADDING7                                    = (int)   Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 6);
    return Bitwalker_IncrementalWalker_Peek_Finish (&PeekLocals);
    }
// =======================

int TrainToTrack_Message_153 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_Radio_TrainToTrack_Radio_infill_request Radio) 
{ 
 
    T_Bitwalker_Incremental_Locals PeekLocals;
    Bitwalker_IncrementalWalker_Init(&PeekLocals, p_Telegramm, i_akt_dim, bitindex);

// Packet Number = 153
	Radio->Message[i_ArrayIndex].NID_MESSAGE                                 = (int)   Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 8);
	Radio->Message[i_ArrayIndex].L_MESSAGE                                   = (int)   Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,10);
	Radio->Message[i_ArrayIndex].T_TRAIN                                     = (float) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,32);
	Radio->Message[i_ArrayIndex].NID_ENGINE                                  = (int)   Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,24);
	Radio->Message[i_ArrayIndex].NID_C                                       = (int)   Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,10);
	Radio->Message[i_ArrayIndex].NID_BG                                      = (int)   Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,14);
	Radio->Message[i_ArrayIndex].Q_INFILL                                    = (T_q_infill) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 1);
	Radio->Message[i_ArrayIndex].PADDING8                                    = (int)   Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 5);
    return Bitwalker_IncrementalWalker_Peek_Finish (&PeekLocals);
    }
// =======================

int TrainToTrack_Message_154 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_Radio_TrainToTrack_No_compatible_version_supported Radio) 
{ 
 
    T_Bitwalker_Incremental_Locals PeekLocals;
    Bitwalker_IncrementalWalker_Init(&PeekLocals, p_Telegramm, i_akt_dim, bitindex);

// Packet Number = 154
	Radio->Message[i_ArrayIndex].NID_MESSAGE                                 = (int)   Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 8);
	Radio->Message[i_ArrayIndex].L_MESSAGE                                   = (int)   Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,10);
	Radio->Message[i_ArrayIndex].T_TRAIN                                     = (float) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,32);
	Radio->Message[i_ArrayIndex].NID_ENGINE                                  = (int)   Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,24);
    return Bitwalker_IncrementalWalker_Peek_Finish (&PeekLocals);
    }
// =======================

int TrainToTrack_Message_155 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_Radio_TrainToTrack_Initiation_of_a_communication_session Radio) 
{ 
 
    T_Bitwalker_Incremental_Locals PeekLocals;
    Bitwalker_IncrementalWalker_Init(&PeekLocals, p_Telegramm, i_akt_dim, bitindex);

// Packet Number = 155
	Radio->Message[i_ArrayIndex].NID_MESSAGE                                 = (int)   Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 8);
	Radio->Message[i_ArrayIndex].L_MESSAGE                                   = (int)   Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,10);
	Radio->Message[i_ArrayIndex].T_TRAIN                                     = (float) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,32);
	Radio->Message[i_ArrayIndex].NID_ENGINE                                  = (int)   Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,24);
    return Bitwalker_IncrementalWalker_Peek_Finish (&PeekLocals);
    }
// =======================

int TrainToTrack_Message_156 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_Radio_TrainToTrack_Termination_of_a_communication_session Radio) 
{ 
 
    T_Bitwalker_Incremental_Locals PeekLocals;
    Bitwalker_IncrementalWalker_Init(&PeekLocals, p_Telegramm, i_akt_dim, bitindex);

// Packet Number = 156
	Radio->Message[i_ArrayIndex].NID_MESSAGE                                 = (int)   Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 8);
	Radio->Message[i_ArrayIndex].L_MESSAGE                                   = (int)   Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,10);
	Radio->Message[i_ArrayIndex].T_TRAIN                                     = (float) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,32);
	Radio->Message[i_ArrayIndex].NID_ENGINE                                  = (int)   Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,24);
    return Bitwalker_IncrementalWalker_Peek_Finish (&PeekLocals);
    }
// =======================

int TrainToTrack_Message_157 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_Radio_TrainToTrack_SoM_Position_Report Radio) 
{ 
 
    T_Bitwalker_Incremental_Locals PeekLocals;
    Bitwalker_IncrementalWalker_Init(&PeekLocals, p_Telegramm, i_akt_dim, bitindex);

// Packet Number = 157
	Radio->Message[i_ArrayIndex].NID_MESSAGE                                 = (int)   Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 8);
	Radio->Message[i_ArrayIndex].L_MESSAGE                                   = (int)   Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,10);
	Radio->Message[i_ArrayIndex].T_TRAIN                                     = (float) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,32);
	Radio->Message[i_ArrayIndex].NID_ENGINE                                  = (int)   Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,24);
	Radio->Message[i_ArrayIndex].Q_STATUS                                    = (T_q_status) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 2);
	Radio->Message[i_ArrayIndex].PADDING9                                    = (int)   Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 4);
    return Bitwalker_IncrementalWalker_Peek_Finish (&PeekLocals);
    }
// =======================

int TrainToTrack_Message_158 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_Radio_TrainToTrack_Text_message_acknowledged_by_driver Radio) 
{ 
 
    T_Bitwalker_Incremental_Locals PeekLocals;
    Bitwalker_IncrementalWalker_Init(&PeekLocals, p_Telegramm, i_akt_dim, bitindex);

// Packet Number = 158
	Radio->Message[i_ArrayIndex].NID_MESSAGE                                 = (int)   Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 8);
	Radio->Message[i_ArrayIndex].L_MESSAGE                                   = (int)   Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,10);
	Radio->Message[i_ArrayIndex].T_TRAIN                                     = (float) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,32);
	Radio->Message[i_ArrayIndex].NID_ENGINE                                  = (int)   Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,24);
	Radio->Message[i_ArrayIndex].NID_TEXTMESSAGE                             = (int)   Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 8);
	Radio->Message[i_ArrayIndex].PADDING10                                   = (int)   Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 6);
    return Bitwalker_IncrementalWalker_Peek_Finish (&PeekLocals);
    }
// =======================

int TrainToTrack_Message_159 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_Radio_TrainToTrack_Session_Established Radio) 
{ 
 
    T_Bitwalker_Incremental_Locals PeekLocals;
    Bitwalker_IncrementalWalker_Init(&PeekLocals, p_Telegramm, i_akt_dim, bitindex);

// Packet Number = 159
	Radio->Message[i_ArrayIndex].NID_MESSAGE                                 = (int)   Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 8);
	Radio->Message[i_ArrayIndex].L_MESSAGE                                   = (int)   Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,10);
	Radio->Message[i_ArrayIndex].T_TRAIN                                     = (float) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,32);
	Radio->Message[i_ArrayIndex].NID_ENGINE                                  = (int)   Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,24);
	Radio->Message[i_ArrayIndex].PADDING11                                   = (int)   Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 6);
    return Bitwalker_IncrementalWalker_Peek_Finish (&PeekLocals);
    }
// =======================

//Namespace Radio_ ends here

//NAMESPACE = TrackToTrain starts here

int TrackToTrain_Message_002 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_Radio_TrackToTrain_SR_Authorisation Radio) 
{ 
 
    T_Bitwalker_Incremental_Locals PeekLocals;
    Bitwalker_IncrementalWalker_Init(&PeekLocals, p_Telegramm, i_akt_dim, bitindex);

// Packet Number = 2
	Radio->Message[i_ArrayIndex].NID_MESSAGE                                 = (int)   Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 8);
	Radio->Message[i_ArrayIndex].L_MESSAGE                                   = (int)   Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,10);
	Radio->Message[i_ArrayIndex].T_TRAIN                                     = (float) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,32);
	Radio->Message[i_ArrayIndex].M_ACK                                       = (T_m_ack) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 1);
	Radio->Message[i_ArrayIndex].NID_LRBG                                    = (int)   Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,24);
	Radio->Message[i_ArrayIndex].Q_SCALE                                     = (T_q_scale) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 2);
	Radio->Message[i_ArrayIndex].D_SR                                        = (int)   Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,15);
	Radio->Message[i_ArrayIndex].PADDING12                                   = (int)   Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 4);
    return Bitwalker_IncrementalWalker_Peek_Finish (&PeekLocals);
    }
// =======================

int TrackToTrain_Message_003 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_Radio_TrackToTrain_Movement_Authority Radio) 
{ 
 
    T_Bitwalker_Incremental_Locals PeekLocals;
    Bitwalker_IncrementalWalker_Init(&PeekLocals, p_Telegramm, i_akt_dim, bitindex);

// Packet Number = 3
	Radio->Message[i_ArrayIndex].NID_MESSAGE                                 = (int)   Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 8);
	Radio->Message[i_ArrayIndex].L_MESSAGE                                   = (int)   Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,10);
	Radio->Message[i_ArrayIndex].T_TRAIN                                     = (float) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,32);
	Radio->Message[i_ArrayIndex].M_ACK                                       = (T_m_ack) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 1);
	Radio->Message[i_ArrayIndex].NID_LRBG                                    = (int)   Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,24);
	Radio->Message[i_ArrayIndex].PADDING13                                   = (int)   Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 5);
    return Bitwalker_IncrementalWalker_Peek_Finish (&PeekLocals);
    }
// =======================

int TrackToTrain_Message_006 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_Radio_TrackToTrain_Recognition_of_exit_from_TRIP_mode Radio) 
{ 
 
    T_Bitwalker_Incremental_Locals PeekLocals;
    Bitwalker_IncrementalWalker_Init(&PeekLocals, p_Telegramm, i_akt_dim, bitindex);

// Packet Number = 6
	Radio->Message[i_ArrayIndex].NID_MESSAGE                                 = (int)   Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 8);
	Radio->Message[i_ArrayIndex].L_MESSAGE                                   = (int)   Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,10);
	Radio->Message[i_ArrayIndex].T_TRAIN                                     = (float) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,32);
	Radio->Message[i_ArrayIndex].M_ACK                                       = (T_m_ack) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 1);
	Radio->Message[i_ArrayIndex].NID_LRBG                                    = (int)   Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,24);
    return Bitwalker_IncrementalWalker_Peek_Finish (&PeekLocals);
    }
// =======================

int TrackToTrain_Message_008 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_Radio_TrackToTrain_Acknowledgement_of_Train_Data Radio) 
{ 
 
    T_Bitwalker_Incremental_Locals PeekLocals;
    Bitwalker_IncrementalWalker_Init(&PeekLocals, p_Telegramm, i_akt_dim, bitindex);

// Packet Number = 8
	Radio->Message[i_ArrayIndex].NID_MESSAGE                                 = (int)   Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 8);
	Radio->Message[i_ArrayIndex].L_MESSAGE                                   = (int)   Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,10);
	Radio->Message[i_ArrayIndex].T_TRAIN0                                    = (int)   Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,32);
	Radio->Message[i_ArrayIndex].M_ACK                                       = (T_m_ack) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 1);
	Radio->Message[i_ArrayIndex].NID_LRBG                                    = (int)   Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,24);
	Radio->Message[i_ArrayIndex].T_TRAIN1                                    = (int)   Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,32);
    return Bitwalker_IncrementalWalker_Peek_Finish (&PeekLocals);
    }
// =======================

int TrackToTrain_Message_009 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_Radio_TrackToTrain_Request_to_Shorten_MA Radio) 
{ 
 
    T_Bitwalker_Incremental_Locals PeekLocals;
    Bitwalker_IncrementalWalker_Init(&PeekLocals, p_Telegramm, i_akt_dim, bitindex);

// Packet Number = 9
	Radio->Message[i_ArrayIndex].NID_MESSAGE                                 = (int)   Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 8);
	Radio->Message[i_ArrayIndex].L_MESSAGE                                   = (int)   Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,10);
	Radio->Message[i_ArrayIndex].T_TRAIN                                     = (float) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,32);
	Radio->Message[i_ArrayIndex].M_ACK                                       = (T_m_ack) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 1);
	Radio->Message[i_ArrayIndex].NID_LRBG                                    = (int)   Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,24);
	Radio->Message[i_ArrayIndex].PADDING14                                   = (int)   Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 5);
    return Bitwalker_IncrementalWalker_Peek_Finish (&PeekLocals);
    }
// =======================

int TrackToTrain_Message_015 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_Radio_TrackToTrain_Conditional_Emergency_Stop Radio) 
{ 
 
    T_Bitwalker_Incremental_Locals PeekLocals;
    Bitwalker_IncrementalWalker_Init(&PeekLocals, p_Telegramm, i_akt_dim, bitindex);

// Packet Number = 15
	Radio->Message[i_ArrayIndex].NID_MESSAGE                                 = (int)   Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 8);
	Radio->Message[i_ArrayIndex].L_MESSAGE                                   = (int)   Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,10);
	Radio->Message[i_ArrayIndex].T_TRAIN                                     = (float) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,32);
	Radio->Message[i_ArrayIndex].M_ACK                                       = (T_m_ack) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 1);
	Radio->Message[i_ArrayIndex].NID_LRBG                                    = (int)   Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,24);
	Radio->Message[i_ArrayIndex].NID_EM                                      = (int)   Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 4);
	Radio->Message[i_ArrayIndex].Q_SCALE                                     = (T_q_scale) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 2);
	Radio->Message[i_ArrayIndex].D_REF                                       = (int)   Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,16);
	Radio->Message[i_ArrayIndex].Q_DIR                                       = (T_q_dir) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 2);
	Radio->Message[i_ArrayIndex].D_EMERGENCYSTOP                             = (int)   Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,15);
    return Bitwalker_IncrementalWalker_Peek_Finish (&PeekLocals);
    }
// =======================

int TrackToTrain_Message_016 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_Radio_TrackToTrain_Unconditional_Emergency_Stop Radio) 
{ 
 
    T_Bitwalker_Incremental_Locals PeekLocals;
    Bitwalker_IncrementalWalker_Init(&PeekLocals, p_Telegramm, i_akt_dim, bitindex);

// Packet Number = 16
	Radio->Message[i_ArrayIndex].NID_MESSAGE                                 = (int)   Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 8);
	Radio->Message[i_ArrayIndex].L_MESSAGE                                   = (int)   Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,10);
	Radio->Message[i_ArrayIndex].T_TRAIN                                     = (float) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,32);
	Radio->Message[i_ArrayIndex].M_ACK                                       = (T_m_ack) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 1);
	Radio->Message[i_ArrayIndex].NID_LRBG                                    = (int)   Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,24);
	Radio->Message[i_ArrayIndex].NID_EM                                      = (int)   Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 4);
    return Bitwalker_IncrementalWalker_Peek_Finish (&PeekLocals);
    }
// =======================

int TrackToTrain_Message_018 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_Radio_TrackToTrain_Revocation_of_Emergency_Stop Radio) 
{ 
 
    T_Bitwalker_Incremental_Locals PeekLocals;
    Bitwalker_IncrementalWalker_Init(&PeekLocals, p_Telegramm, i_akt_dim, bitindex);

// Packet Number = 18
	Radio->Message[i_ArrayIndex].NID_MESSAGE                                 = (int)   Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 8);
	Radio->Message[i_ArrayIndex].L_MESSAGE                                   = (int)   Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,10);
	Radio->Message[i_ArrayIndex].T_TRAIN                                     = (float) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,32);
	Radio->Message[i_ArrayIndex].M_ACK                                       = (T_m_ack) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 1);
	Radio->Message[i_ArrayIndex].NID_LRBG                                    = (int)   Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,24);
	Radio->Message[i_ArrayIndex].NID_EM                                      = (int)   Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 4);
    return Bitwalker_IncrementalWalker_Peek_Finish (&PeekLocals);
    }
// =======================

int TrackToTrain_Message_024 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_Radio_TrackToTrain_General_message Radio) 
{ 
 
    T_Bitwalker_Incremental_Locals PeekLocals;
    Bitwalker_IncrementalWalker_Init(&PeekLocals, p_Telegramm, i_akt_dim, bitindex);

// Packet Number = 24
	Radio->Message[i_ArrayIndex].NID_MESSAGE                                 = (int)   Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 8);
	Radio->Message[i_ArrayIndex].L_MESSAGE                                   = (int)   Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,10);
	Radio->Message[i_ArrayIndex].T_TRAIN                                     = (float) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,32);
	Radio->Message[i_ArrayIndex].M_ACK                                       = (T_m_ack) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 1);
	Radio->Message[i_ArrayIndex].NID_LRBG                                    = (int)   Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,24);
	Radio->Message[i_ArrayIndex].PADDING15                                   = (int)   Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 5);
    return Bitwalker_IncrementalWalker_Peek_Finish (&PeekLocals);
    }
// =======================

int TrackToTrain_Message_027 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_Radio_TrackToTrain_SH_Refused Radio) 
{ 
 
    T_Bitwalker_Incremental_Locals PeekLocals;
    Bitwalker_IncrementalWalker_Init(&PeekLocals, p_Telegramm, i_akt_dim, bitindex);

// Packet Number = 27
	Radio->Message[i_ArrayIndex].NID_MESSAGE                                 = (int)   Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 8);
	Radio->Message[i_ArrayIndex].L_MESSAGE                                   = (int)   Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,10);
	Radio->Message[i_ArrayIndex].T_TRAIN0                                    = (int)   Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,32);
	Radio->Message[i_ArrayIndex].M_ACK                                       = (T_m_ack) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 1);
	Radio->Message[i_ArrayIndex].NID_LRBG                                    = (int)   Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,24);
	Radio->Message[i_ArrayIndex].T_TRAIN1                                    = (int)   Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,32);
    return Bitwalker_IncrementalWalker_Peek_Finish (&PeekLocals);
    }
// =======================

int TrackToTrain_Message_028 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_Radio_TrackToTrain_SH_Authorised Radio) 
{ 
 
    T_Bitwalker_Incremental_Locals PeekLocals;
    Bitwalker_IncrementalWalker_Init(&PeekLocals, p_Telegramm, i_akt_dim, bitindex);

// Packet Number = 28
	Radio->Message[i_ArrayIndex].NID_MESSAGE                                 = (int)   Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 8);
	Radio->Message[i_ArrayIndex].L_MESSAGE                                   = (int)   Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,10);
	Radio->Message[i_ArrayIndex].T_TRAIN0                                    = (int)   Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,32);
	Radio->Message[i_ArrayIndex].M_ACK                                       = (T_m_ack) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 1);
	Radio->Message[i_ArrayIndex].NID_LRBG                                    = (int)   Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,24);
	Radio->Message[i_ArrayIndex].T_TRAIN1                                    = (int)   Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,32);
	Radio->Message[i_ArrayIndex].PADDING16                                   = (int)   Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 5);
    return Bitwalker_IncrementalWalker_Peek_Finish (&PeekLocals);
    }
// =======================

int TrackToTrain_Message_032 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_Radio_TrackToTrain_RBC_or_RIU_System_Version Radio) 
{ 
 
    T_Bitwalker_Incremental_Locals PeekLocals;
    Bitwalker_IncrementalWalker_Init(&PeekLocals, p_Telegramm, i_akt_dim, bitindex);

// Packet Number = 32
	Radio->Message[i_ArrayIndex].NID_MESSAGE                                 = (int)   Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 8);
	Radio->Message[i_ArrayIndex].L_MESSAGE                                   = (int)   Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,10);
	Radio->Message[i_ArrayIndex].T_TRAIN                                     = (float) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,32);
	Radio->Message[i_ArrayIndex].M_ACK                                       = (T_m_ack) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 1);
	Radio->Message[i_ArrayIndex].NID_LRBG                                    = (int)   Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,24);
	Radio->Message[i_ArrayIndex].M_VERSION                                   = (T_m_version) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 7);
    return Bitwalker_IncrementalWalker_Peek_Finish (&PeekLocals);
    }
// =======================

int TrackToTrain_Message_033 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_Radio_TrackToTrain_MA_with_Shifted_Location_Reference Radio) 
{ 
 
    T_Bitwalker_Incremental_Locals PeekLocals;
    Bitwalker_IncrementalWalker_Init(&PeekLocals, p_Telegramm, i_akt_dim, bitindex);

// Packet Number = 33
	Radio->Message[i_ArrayIndex].NID_MESSAGE                                 = (int)   Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 8);
	Radio->Message[i_ArrayIndex].L_MESSAGE                                   = (int)   Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,10);
	Radio->Message[i_ArrayIndex].T_TRAIN                                     = (float) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,32);
	Radio->Message[i_ArrayIndex].M_ACK                                       = (T_m_ack) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 1);
	Radio->Message[i_ArrayIndex].NID_LRBG                                    = (int)   Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,24);
	Radio->Message[i_ArrayIndex].Q_SCALE                                     = (T_q_scale) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 2);
	Radio->Message[i_ArrayIndex].D_REF                                       = (int)   Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,16);
	Radio->Message[i_ArrayIndex].PADDING17                                   = (int)   Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 3);
    return Bitwalker_IncrementalWalker_Peek_Finish (&PeekLocals);
    }
// =======================

int TrackToTrain_Message_034 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_Radio_TrackToTrain_Track_Ahead_Free_Request Radio) 
{ 
 
    T_Bitwalker_Incremental_Locals PeekLocals;
    Bitwalker_IncrementalWalker_Init(&PeekLocals, p_Telegramm, i_akt_dim, bitindex);

// Packet Number = 34
	Radio->Message[i_ArrayIndex].NID_MESSAGE                                 = (int)   Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 8);
	Radio->Message[i_ArrayIndex].L_MESSAGE                                   = (int)   Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,10);
	Radio->Message[i_ArrayIndex].T_TRAIN                                     = (float) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,32);
	Radio->Message[i_ArrayIndex].M_ACK                                       = (T_m_ack) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 1);
	Radio->Message[i_ArrayIndex].NID_LRBG                                    = (int)   Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,24);
	Radio->Message[i_ArrayIndex].Q_SCALE                                     = (T_q_scale) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 2);
	Radio->Message[i_ArrayIndex].D_REF                                       = (int)   Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,16);
	Radio->Message[i_ArrayIndex].Q_DIR                                       = (T_q_dir) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 2);
	Radio->Message[i_ArrayIndex].D_TAFDISPLAY                                = (int)   Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,15);
	Radio->Message[i_ArrayIndex].L_TAFDISPLAY                                = (int)   Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,15);
    return Bitwalker_IncrementalWalker_Peek_Finish (&PeekLocals);
    }
// =======================

int TrackToTrain_Message_037 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_Radio_TrackToTrain_Infill_MA Radio) 
{ 
 
    T_Bitwalker_Incremental_Locals PeekLocals;
    Bitwalker_IncrementalWalker_Init(&PeekLocals, p_Telegramm, i_akt_dim, bitindex);

// Packet Number = 37
	Radio->Message[i_ArrayIndex].NID_MESSAGE                                 = (int)   Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 8);
	Radio->Message[i_ArrayIndex].L_MESSAGE                                   = (int)   Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,10);
	Radio->Message[i_ArrayIndex].T_TRAIN                                     = (float) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,32);
	Radio->Message[i_ArrayIndex].M_ACK                                       = (T_m_ack) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 1);
	Radio->Message[i_ArrayIndex].NID_LRBG                                    = (int)   Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,24);
	Radio->Message[i_ArrayIndex].PADDING18                                   = (int)   Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 5);
    return Bitwalker_IncrementalWalker_Peek_Finish (&PeekLocals);
    }
// =======================

int TrackToTrain_Message_038 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_Radio_TrackToTrain_Initiation_of_a_communication_session Radio) 
{ 
 
    T_Bitwalker_Incremental_Locals PeekLocals;
    Bitwalker_IncrementalWalker_Init(&PeekLocals, p_Telegramm, i_akt_dim, bitindex);

// Packet Number = 38
	Radio->Message[i_ArrayIndex].NID_MESSAGE                                 = (int)   Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 8);
	Radio->Message[i_ArrayIndex].L_MESSAGE                                   = (int)   Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,10);
	Radio->Message[i_ArrayIndex].T_TRAIN                                     = (float) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,32);
	Radio->Message[i_ArrayIndex].M_ACK                                       = (T_m_ack) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 1);
	Radio->Message[i_ArrayIndex].NID_LRBG                                    = (int)   Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,24);
    return Bitwalker_IncrementalWalker_Peek_Finish (&PeekLocals);
    }
// =======================

int TrackToTrain_Message_039 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_Radio_TrackToTrain_Acknowledgement_of_termination_of_a_communication_session Radio) 
{ 
 
    T_Bitwalker_Incremental_Locals PeekLocals;
    Bitwalker_IncrementalWalker_Init(&PeekLocals, p_Telegramm, i_akt_dim, bitindex);

// Packet Number = 39
	Radio->Message[i_ArrayIndex].NID_MESSAGE                                 = (int)   Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 8);
	Radio->Message[i_ArrayIndex].L_MESSAGE                                   = (int)   Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,10);
	Radio->Message[i_ArrayIndex].T_TRAIN                                     = (float) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,32);
	Radio->Message[i_ArrayIndex].M_ACK                                       = (T_m_ack) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 1);
	Radio->Message[i_ArrayIndex].NID_LRBG                                    = (int)   Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,24);
    return Bitwalker_IncrementalWalker_Peek_Finish (&PeekLocals);
    }
// =======================

int TrackToTrain_Message_040 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_Radio_TrackToTrain_Train_Rejected Radio) 
{ 
 
    T_Bitwalker_Incremental_Locals PeekLocals;
    Bitwalker_IncrementalWalker_Init(&PeekLocals, p_Telegramm, i_akt_dim, bitindex);

// Packet Number = 40
	Radio->Message[i_ArrayIndex].NID_MESSAGE                                 = (int)   Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 8);
	Radio->Message[i_ArrayIndex].L_MESSAGE                                   = (int)   Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,10);
	Radio->Message[i_ArrayIndex].T_TRAIN                                     = (float) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,32);
	Radio->Message[i_ArrayIndex].M_ACK                                       = (T_m_ack) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 1);
	Radio->Message[i_ArrayIndex].NID_LRBG                                    = (int)   Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,24);
    return Bitwalker_IncrementalWalker_Peek_Finish (&PeekLocals);
    }
// =======================

int TrackToTrain_Message_041 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_Radio_TrackToTrain_Train_Accepted Radio) 
{ 
 
    T_Bitwalker_Incremental_Locals PeekLocals;
    Bitwalker_IncrementalWalker_Init(&PeekLocals, p_Telegramm, i_akt_dim, bitindex);

// Packet Number = 41
	Radio->Message[i_ArrayIndex].NID_MESSAGE                                 = (int)   Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 8);
	Radio->Message[i_ArrayIndex].L_MESSAGE                                   = (int)   Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,10);
	Radio->Message[i_ArrayIndex].T_TRAIN                                     = (float) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,32);
	Radio->Message[i_ArrayIndex].M_ACK                                       = (T_m_ack) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 1);
	Radio->Message[i_ArrayIndex].NID_LRBG                                    = (int)   Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,24);
    return Bitwalker_IncrementalWalker_Peek_Finish (&PeekLocals);
    }
// =======================

int TrackToTrain_Message_043 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_Radio_TrackToTrain_SoM_position_report_confirmed_by_RBC Radio) 
{ 
 
    T_Bitwalker_Incremental_Locals PeekLocals;
    Bitwalker_IncrementalWalker_Init(&PeekLocals, p_Telegramm, i_akt_dim, bitindex);

// Packet Number = 43
	Radio->Message[i_ArrayIndex].NID_MESSAGE                                 = (int)   Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 8);
	Radio->Message[i_ArrayIndex].L_MESSAGE                                   = (int)   Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,10);
	Radio->Message[i_ArrayIndex].T_TRAIN                                     = (float) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,32);
	Radio->Message[i_ArrayIndex].M_ACK                                       = (T_m_ack) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 1);
	Radio->Message[i_ArrayIndex].NID_LRBG                                    = (int)   Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,24);
    return Bitwalker_IncrementalWalker_Peek_Finish (&PeekLocals);
    }
// =======================

int TrackToTrain_Message_045 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_Radio_TrackToTrain_Assignment_of_coordinate_system Radio) 
{ 
 
    T_Bitwalker_Incremental_Locals PeekLocals;
    Bitwalker_IncrementalWalker_Init(&PeekLocals, p_Telegramm, i_akt_dim, bitindex);

// Packet Number = 45
	Radio->Message[i_ArrayIndex].NID_MESSAGE                                 = (int)   Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 8);
	Radio->Message[i_ArrayIndex].L_MESSAGE                                   = (int)   Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,10);
	Radio->Message[i_ArrayIndex].T_TRAIN                                     = (float) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,32);
	Radio->Message[i_ArrayIndex].M_ACK                                       = (T_m_ack) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 1);
	Radio->Message[i_ArrayIndex].NID_LRBG                                    = (int)   Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,24);
	Radio->Message[i_ArrayIndex].Q_ORIENTATION                               = (T_q_orientation) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 1);
    return Bitwalker_IncrementalWalker_Peek_Finish (&PeekLocals);
    }
// =======================

//Namespace Radio_ ends here
