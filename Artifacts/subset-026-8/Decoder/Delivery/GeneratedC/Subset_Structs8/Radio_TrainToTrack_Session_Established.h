#ifndef NESTINGMARK_Radio_Message_TrainToTrack_Session_Established
#define NESTINGMARK_Radio_Message_TrainToTrack_Session_Established
/* =============================================================================
Formalization of Subset-026-8 (Chapter 8: ERTMS/ETCS language)

- Name: Subset-026-7 / TrainToTrack_Session_Established
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
	Session_Established_OptionalPacketNumber_3 = 3
} Session_Established_OptionalPackets ;

struct DATA_Radio_TrainToTrack_Session_Established {
  int vUsed_idx;                             // aktueller Fuellgrad von aPacket

  struct 
  {
          uint32_t v_TOccurence;            // Zeitpunkt des Empfangs
          uint64_t v_DOccurrence;           // Ort des Empfangs
          uint32_t vState;                  // Bearbeitungszustaende  
  } info;

  struct 
 { 
// Packet Number = 159

	uint32_t NID_MESSAGE;                     		// # 8		// int
	uint32_t               L_MESSAGE             ;		// # 10		// int
	uint32_t               T_TRAIN               ;		// # 32		// float
	uint32_t               NID_ENGINE            ;		// # 24		// int
	uint32_t               PADDING11             ;		// # 6	
	uint32_t Session_Established_OptionalPackets;		 // # Length is unknown here; depends on current package number(s)


} 


   Message[2];       // Instanz der Sturkur mit dem content
};

// struct -> type
typedef struct DATA_Radio_TrainToTrack_Session_Established T_DATA_Radio_TrainToTrack_Session_Established;
// typ -> ptrtyp
typedef  T_DATA_Radio_TrainToTrack_Session_Established* TP_DATA_Radio_TrainToTrack_Session_Established;
// declaration of variable of ptrtyp
extern TP_DATA_Radio_TrainToTrack_Session_Established  Radio_Packet_TrainToTrack_Session_Established;
// instatiate this ptrtype variable like this: (get memory and fill memory)
// TP_DATA_Radio_TrainToTrack_Session_Established  Radio_Packet_TrainToTrack_Session_Established = new(T_DATA_Radio_TrainToTrack_Session_Established);
// and now fill in the content to start with ...
// Access variable like this: Radio_Packet_TrainToTrack_Session_Established->...
// maybe : memset(Radio_Packet_TrainToTrack_Session_Established, 0, sizeof(T_DATA_Radio_Packet_TrainToTrack_Session_Established));
// for complete 0 content.

#endif


