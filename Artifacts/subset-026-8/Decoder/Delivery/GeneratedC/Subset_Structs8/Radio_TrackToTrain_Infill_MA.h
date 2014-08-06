#ifndef NESTINGMARK_Radio_Message_TrackToTrain_Infill_MA
#define NESTINGMARK_Radio_Message_TrackToTrain_Infill_MA
/* =============================================================================
Formalization of Subset-026-8 (Chapter 8: ERTMS/ETCS language)

- Name: Subset-026-7 / TrackToTrain_Infill_MA
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
	Infill_MA_OptionalPacketNumber_136 = 136,
	Infill_MA_OptionalPacketNumber_12 = 12,
	Infill_MA_OptionalPacketNumber_5 = 5,
	Infill_MA_OptionalPacketNumber_21 = 21,
	Infill_MA_OptionalPacketNumber_27 = 27,
	Infill_MA_OptionalPacketNumber_39 = 39,
	Infill_MA_OptionalPacketNumber_40 = 40,
	Infill_MA_OptionalPacketNumber_41 = 41,
	Infill_MA_OptionalPacketNumber_44 = 44,
	Infill_MA_OptionalPacketNumber_49 = 49,
	Infill_MA_OptionalPacketNumber_51 = 51,
	Infill_MA_OptionalPacketNumber_65 = 65,
	Infill_MA_OptionalPacketNumber_66 = 66,
	Infill_MA_OptionalPacketNumber_68 = 68,
	Infill_MA_OptionalPacketNumber_69 = 69,
	Infill_MA_OptionalPacketNumber_70 = 70,
	Infill_MA_OptionalPacketNumber_71 = 71,
	Infill_MA_OptionalPacketNumber_80 = 80,
	Infill_MA_OptionalPacketNumber_88 = 88,
	Infill_MA_OptionalPacketNumber_138 = 138,
	Infill_MA_OptionalPacketNumber_139 = 139
} Infill_MA_OptionalPackets ;

struct DATA_Radio_TrackToTrain_Infill_MA {
  int vUsed_idx;                             // aktueller Fuellgrad von aPacket

  struct 
  {
          uint32_t v_TOccurence;            // Zeitpunkt des Empfangs
          uint64_t v_DOccurrence;           // Ort des Empfangs
          uint32_t vState;                  // Bearbeitungszustaende  
  } info;

  struct 
 { 
// Packet Number = 37

	uint32_t NID_MESSAGE;                     		// # 8		// int
	uint32_t               L_MESSAGE             ;		// # 10		// int
	uint32_t               T_TRAIN               ;		// # 32		// float
	T_m_ack                M_ACK                 ;		// # 1		// enum
	uint32_t               NID_LRBG              ;		// # 24		// int
	uint32_t               PADDING18             ;		// # 5	
	uint32_t Infill_MA_OptionalPackets;		 // # Length is unknown here; depends on current package number(s)


} 


   Message[2];       // Instanz der Sturkur mit dem content
};

// struct -> type
typedef struct DATA_Radio_TrackToTrain_Infill_MA T_DATA_Radio_TrackToTrain_Infill_MA;
// typ -> ptrtyp
typedef  T_DATA_Radio_TrackToTrain_Infill_MA* TP_DATA_Radio_TrackToTrain_Infill_MA;
// declaration of variable of ptrtyp
extern TP_DATA_Radio_TrackToTrain_Infill_MA  Radio_Packet_TrackToTrain_Infill_MA;
// instatiate this ptrtype variable like this: (get memory and fill memory)
// TP_DATA_Radio_TrackToTrain_Infill_MA  Radio_Packet_TrackToTrain_Infill_MA = new(T_DATA_Radio_TrackToTrain_Infill_MA);
// and now fill in the content to start with ...
// Access variable like this: Radio_Packet_TrackToTrain_Infill_MA->...
// maybe : memset(Radio_Packet_TrackToTrain_Infill_MA, 0, sizeof(T_DATA_Radio_Packet_TrackToTrain_Infill_MA));
// for complete 0 content.

#endif


