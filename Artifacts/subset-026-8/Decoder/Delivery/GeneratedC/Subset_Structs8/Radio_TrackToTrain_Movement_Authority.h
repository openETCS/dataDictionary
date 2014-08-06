#ifndef NESTINGMARK_Radio_Message_TrackToTrain_Movement_Authority
#define NESTINGMARK_Radio_Message_TrackToTrain_Movement_Authority
/* =============================================================================
Formalization of Subset-026-8 (Chapter 8: ERTMS/ETCS language)

- Name: Subset-026-7 / TrackToTrain_Movement_Authority
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
	Movement_Authority_OptionalPacketNumber_15 = 15,
	Movement_Authority_OptionalPacketNumber_21 = 21,
	Movement_Authority_OptionalPacketNumber_27 = 27,
	Movement_Authority_OptionalPacketNumber_49 = 49,
	Movement_Authority_OptionalPacketNumber_80 = 80,
	Movement_Authority_OptionalPacketNumber_3 = 3,
	Movement_Authority_OptionalPacketNumber_5 = 5,
	Movement_Authority_OptionalPacketNumber_39 = 39,
	Movement_Authority_OptionalPacketNumber_40 = 40,
	Movement_Authority_OptionalPacketNumber_51 = 51,
	Movement_Authority_OptionalPacketNumber_41 = 41,
	Movement_Authority_OptionalPacketNumber_42 = 42,
	Movement_Authority_OptionalPacketNumber_44 = 44,
	Movement_Authority_OptionalPacketNumber_45 = 45,
	Movement_Authority_OptionalPacketNumber_52 = 52,
	Movement_Authority_OptionalPacketNumber_57 = 57,
	Movement_Authority_OptionalPacketNumber_58 = 58,
	Movement_Authority_OptionalPacketNumber_64 = 64,
	Movement_Authority_OptionalPacketNumber_65 = 65,
	Movement_Authority_OptionalPacketNumber_66 = 66,
	Movement_Authority_OptionalPacketNumber_68 = 68,
	Movement_Authority_OptionalPacketNumber_69 = 69,
	Movement_Authority_OptionalPacketNumber_70 = 70,
	Movement_Authority_OptionalPacketNumber_71 = 71,
	Movement_Authority_OptionalPacketNumber_72 = 72,
	Movement_Authority_OptionalPacketNumber_76 = 76,
	Movement_Authority_OptionalPacketNumber_79 = 79,
	Movement_Authority_OptionalPacketNumber_88 = 88,
	Movement_Authority_OptionalPacketNumber_131 = 131,
	Movement_Authority_OptionalPacketNumber_138 = 138,
	Movement_Authority_OptionalPacketNumber_139 = 139,
	Movement_Authority_OptionalPacketNumber_140 = 140
} Movement_Authority_OptionalPackets ;

struct DATA_Radio_TrackToTrain_Movement_Authority {
  int vUsed_idx;                             // aktueller Fuellgrad von aPacket

  struct 
  {
          uint32_t v_TOccurence;            // Zeitpunkt des Empfangs
          uint64_t v_DOccurrence;           // Ort des Empfangs
          uint32_t vState;                  // Bearbeitungszustaende  
  } info;

  struct 
 { 
// Packet Number = 3

	uint32_t NID_MESSAGE;                     		// # 8		// int
	uint32_t               L_MESSAGE             ;		// # 10		// int
	uint32_t               T_TRAIN               ;		// # 32		// float
	T_m_ack                M_ACK                 ;		// # 1		// enum
	uint32_t               NID_LRBG              ;		// # 24		// int
	uint32_t               PADDING13             ;		// # 5	
	uint32_t Movement_Authority_OptionalPackets;		 // # Length is unknown here; depends on current package number(s)


} 


   Message[2];       // Instanz der Sturkur mit dem content
};

// struct -> type
typedef struct DATA_Radio_TrackToTrain_Movement_Authority T_DATA_Radio_TrackToTrain_Movement_Authority;
// typ -> ptrtyp
typedef  T_DATA_Radio_TrackToTrain_Movement_Authority* TP_DATA_Radio_TrackToTrain_Movement_Authority;
// declaration of variable of ptrtyp
extern TP_DATA_Radio_TrackToTrain_Movement_Authority  Radio_Packet_TrackToTrain_Movement_Authority;
// instatiate this ptrtype variable like this: (get memory and fill memory)
// TP_DATA_Radio_TrackToTrain_Movement_Authority  Radio_Packet_TrackToTrain_Movement_Authority = new(T_DATA_Radio_TrackToTrain_Movement_Authority);
// and now fill in the content to start with ...
// Access variable like this: Radio_Packet_TrackToTrain_Movement_Authority->...
// maybe : memset(Radio_Packet_TrackToTrain_Movement_Authority, 0, sizeof(T_DATA_Radio_Packet_TrackToTrain_Movement_Authority));
// for complete 0 content.

#endif


