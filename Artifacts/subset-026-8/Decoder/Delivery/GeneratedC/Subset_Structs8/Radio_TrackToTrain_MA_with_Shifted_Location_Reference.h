#ifndef NESTINGMARK_Radio_Message_TrackToTrain_MA_with_Shifted_Location_Reference
#define NESTINGMARK_Radio_Message_TrackToTrain_MA_with_Shifted_Location_Reference
/* =============================================================================
Formalization of Subset-026-8 (Chapter 8: ERTMS/ETCS language)

- Name: Subset-026-7 / TrackToTrain_MA_with_Shifted_Location_Reference
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
============================================================================= */
#include <stdint.h>
#include "opnETCS_Variables.h"

typedef enum { 
	MA_with_Shifted_Location_Reference_OptionalPacketNumber_15 = 15,
	MA_with_Shifted_Location_Reference_OptionalPacketNumber_21 = 21,
	MA_with_Shifted_Location_Reference_OptionalPacketNumber_27 = 27,
	MA_with_Shifted_Location_Reference_OptionalPacketNumber_49 = 49,
	MA_with_Shifted_Location_Reference_OptionalPacketNumber_80 = 80,
	MA_with_Shifted_Location_Reference_OptionalPacketNumber_3 = 3,
	MA_with_Shifted_Location_Reference_OptionalPacketNumber_5 = 5,
	MA_with_Shifted_Location_Reference_OptionalPacketNumber_39 = 39,
	MA_with_Shifted_Location_Reference_OptionalPacketNumber_40 = 40,
	MA_with_Shifted_Location_Reference_OptionalPacketNumber_51 = 51,
	MA_with_Shifted_Location_Reference_OptionalPacketNumber_41 = 41,
	MA_with_Shifted_Location_Reference_OptionalPacketNumber_42 = 42,
	MA_with_Shifted_Location_Reference_OptionalPacketNumber_44 = 44,
	MA_with_Shifted_Location_Reference_OptionalPacketNumber_45 = 45,
	MA_with_Shifted_Location_Reference_OptionalPacketNumber_52 = 52,
	MA_with_Shifted_Location_Reference_OptionalPacketNumber_57 = 57,
	MA_with_Shifted_Location_Reference_OptionalPacketNumber_58 = 58,
	MA_with_Shifted_Location_Reference_OptionalPacketNumber_64 = 64,
	MA_with_Shifted_Location_Reference_OptionalPacketNumber_65 = 65,
	MA_with_Shifted_Location_Reference_OptionalPacketNumber_66 = 66,
	MA_with_Shifted_Location_Reference_OptionalPacketNumber_68 = 68,
	MA_with_Shifted_Location_Reference_OptionalPacketNumber_69 = 69,
	MA_with_Shifted_Location_Reference_OptionalPacketNumber_70 = 70,
	MA_with_Shifted_Location_Reference_OptionalPacketNumber_71 = 71,
	MA_with_Shifted_Location_Reference_OptionalPacketNumber_72 = 72,
	MA_with_Shifted_Location_Reference_OptionalPacketNumber_76 = 76,
	MA_with_Shifted_Location_Reference_OptionalPacketNumber_79 = 79,
	MA_with_Shifted_Location_Reference_OptionalPacketNumber_88 = 88,
	MA_with_Shifted_Location_Reference_OptionalPacketNumber_131 = 131,
	MA_with_Shifted_Location_Reference_OptionalPacketNumber_138 = 138,
	MA_with_Shifted_Location_Reference_OptionalPacketNumber_139 = 139,
	MA_with_Shifted_Location_Reference_OptionalPacketNumber_140 = 140
} MA_with_Shifted_Location_Reference_OptionalPackets ;

struct DATA_Radio_TrackToTrain_MA_with_Shifted_Location_Reference {
  int vUsed_idx;                             // aktueller Fuellgrad von aPacket

  struct 
  {
          uint32_t v_TOccurence;            // Zeitpunkt des Empfangs
          uint64_t v_DOccurrence;           // Ort des Empfangs
          uint32_t vState;                  // Bearbeitungszustaende  
  } info;

  struct 
 { 
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


   Message[2];       // Instanz der Sturkur mit dem content
};

// struct -> type
typedef struct DATA_Radio_TrackToTrain_MA_with_Shifted_Location_Reference T_DATA_Radio_TrackToTrain_MA_with_Shifted_Location_Reference;
// typ -> ptrtyp
typedef  T_DATA_Radio_TrackToTrain_MA_with_Shifted_Location_Reference* TP_DATA_Radio_TrackToTrain_MA_with_Shifted_Location_Reference;
// declaration of variable of ptrtyp
extern TP_DATA_Radio_TrackToTrain_MA_with_Shifted_Location_Reference  Radio_Packet_TrackToTrain_MA_with_Shifted_Location_Reference;
// instatiate this ptrtype variable like this: (get memory and fill memory)
// TP_DATA_Radio_TrackToTrain_MA_with_Shifted_Location_Reference  Radio_Packet_TrackToTrain_MA_with_Shifted_Location_Reference = new(T_DATA_Radio_TrackToTrain_MA_with_Shifted_Location_Reference);
// and now fill in the content to start with ...
// Access variable like this: Radio_Packet_TrackToTrain_MA_with_Shifted_Location_Reference->...
// maybe : memset(Radio_Packet_TrackToTrain_MA_with_Shifted_Location_Reference, 0, sizeof(T_DATA_Radio_Packet_TrackToTrain_MA_with_Shifted_Location_Reference));
// for complete 0 content.

#endif


