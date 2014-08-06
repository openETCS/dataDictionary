#ifndef NESTINGMARK_Radio_Message_TrainToTrack_Text_message_acknowledged_by_driver
#define NESTINGMARK_Radio_Message_TrainToTrack_Text_message_acknowledged_by_driver
/* =============================================================================
Formalization of Subset-026-8 (Chapter 8: ERTMS/ETCS language)

- Name: Subset-026-7 / TrainToTrack_Text_message_acknowledged_by_driver
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
	Text_message_acknowledged_by_driver_OptionalPacketNumber_0 = 0,
	Text_message_acknowledged_by_driver_OptionalPacketNumber_1 = 1
} Text_message_acknowledged_by_driver_OptionalPackets ;

struct DATA_Radio_TrainToTrack_Text_message_acknowledged_by_driver {
  int vUsed_idx;                             // aktueller Fuellgrad von aPacket

  struct 
  {
          uint32_t v_TOccurence;            // Zeitpunkt des Empfangs
          uint64_t v_DOccurrence;           // Ort des Empfangs
          uint32_t vState;                  // Bearbeitungszustaende  
  } info;

  struct 
 { 
// Packet Number = 158

	uint32_t NID_MESSAGE;                     		// # 8		// int
	uint32_t               L_MESSAGE             ;		// # 10		// int
	uint32_t               T_TRAIN               ;		// # 32		// float
	uint32_t               NID_ENGINE            ;		// # 24		// int
	uint32_t               NID_TEXTMESSAGE       ;		// # 8	
	uint32_t               PADDING10             ;		// # 6	
	uint32_t Text_message_acknowledged_by_driver_OptionalPackets;		 // # Length is unknown here; depends on current package number(s)


} 


   Message[2];       // Instanz der Sturkur mit dem content
};

// struct -> type
typedef struct DATA_Radio_TrainToTrack_Text_message_acknowledged_by_driver T_DATA_Radio_TrainToTrack_Text_message_acknowledged_by_driver;
// typ -> ptrtyp
typedef  T_DATA_Radio_TrainToTrack_Text_message_acknowledged_by_driver* TP_DATA_Radio_TrainToTrack_Text_message_acknowledged_by_driver;
// declaration of variable of ptrtyp
extern TP_DATA_Radio_TrainToTrack_Text_message_acknowledged_by_driver  Radio_Packet_TrainToTrack_Text_message_acknowledged_by_driver;
// instatiate this ptrtype variable like this: (get memory and fill memory)
// TP_DATA_Radio_TrainToTrack_Text_message_acknowledged_by_driver  Radio_Packet_TrainToTrack_Text_message_acknowledged_by_driver = new(T_DATA_Radio_TrainToTrack_Text_message_acknowledged_by_driver);
// and now fill in the content to start with ...
// Access variable like this: Radio_Packet_TrainToTrack_Text_message_acknowledged_by_driver->...
// maybe : memset(Radio_Packet_TrainToTrack_Text_message_acknowledged_by_driver, 0, sizeof(T_DATA_Radio_Packet_TrainToTrack_Text_message_acknowledged_by_driver));
// for complete 0 content.

#endif


