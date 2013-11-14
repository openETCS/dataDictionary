#ifndef NESTINGMARK_oETCS_Packet_Radio_TrackToTrain_General_message
#define NESTINGMARK_oETCS_Packet_Radio_TrackToTrain_General_message
/* =============================================================================
Formalization of Subset-026-8 (Chapter 8: ERTMS/ETCS language)

- Name: Subset-026-8 / Radio_TrackToTrain_General_message
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
============================================================================= */

#include <stdint.h>

typedef enum { 
	General_message_OptionalPacketNumber_21 = 21,
	General_message_OptionalPacketNumber_27 = 27,
	General_message_OptionalPacketNumber_45 = 45,
	General_message_OptionalPacketNumber_143 = 143,
	General_message_OptionalPacketNumber_254 = 254,
	General_message_OptionalPacketNumber_3 = 3,
	General_message_OptionalPacketNumber_5 = 5,
	General_message_OptionalPacketNumber_39 = 39,
	General_message_OptionalPacketNumber_40 = 40,
	General_message_OptionalPacketNumber_51 = 51,
	General_message_OptionalPacketNumber_41 = 41,
	General_message_OptionalPacketNumber_42 = 42,
	General_message_OptionalPacketNumber_44 = 44,
	General_message_OptionalPacketNumber_52 = 52,
	General_message_OptionalPacketNumber_57 = 57,
	General_message_OptionalPacketNumber_58 = 58,
	General_message_OptionalPacketNumber_64 = 64,
	General_message_OptionalPacketNumber_65 = 65,
	General_message_OptionalPacketNumber_66 = 66,
	General_message_OptionalPacketNumber_68 = 68,
	General_message_OptionalPacketNumber_69 = 69,
	General_message_OptionalPacketNumber_70 = 70,
	General_message_OptionalPacketNumber_71 = 71,
	General_message_OptionalPacketNumber_72 = 72,
	General_message_OptionalPacketNumber_76 = 76,
	General_message_OptionalPacketNumber_79 = 79,
	General_message_OptionalPacketNumber_88 = 88,
	General_message_OptionalPacketNumber_131 = 131,
	General_message_OptionalPacketNumber_138 = 138,
	General_message_OptionalPacketNumber_139 = 139,
	General_message_OptionalPacketNumber_140 = 140
} General_message_OptionalPackets ;

struct DATA_oETCS_Radio_TrackToTrain_General_message {
  int vUsed_idx;                             // aktueller Fuellgrad von aPacket

  struct 
  {
          uint32_t v_TOccurence;            // Zeitpunkt des Empfangs
          uint64_t v_DOccurrence;           // Ort des Empfangs
          uint32_t vState;                  // Bearbeitungszustände  
  } info;

  struct 
 { 
// TransmissionMedia=RBC, RIU

	uint32_t NID_MESSAGE;                            			// # 8		// int
	uint32_t L_MESSAGE;                              			// # 10		// int
	uint32_t T_TRAIN;                                			// # 32		// real
	uint32_t M_ACK;                                  			// # 1		// enum
	uint32_t NID_LRBG;                               			// # 24		// int
	uint32_t PADDING15;                              			// # 5	
	uint32_t General_message_OptionalPackets;		 // # Length is unknown here; depends on current package number(s)


} 


   aPacket[2];       // Instanz der Sturkur mit dem content
};

// struct -> type
typedef struct DATA_oETCS_Radio_TrackToTrain_General_message T_DATA_oETCS_Radio_TrackToTrain_General_message;
// typ -> ptrtyp
typedef  T_DATA_oETCS_Radio_TrackToTrain_General_message* TP_DATA_oETCS_Radio_TrackToTrain_General_message;
// declaration of variable of ptrtyp
extern TP_DATA_oETCS_Radio_TrackToTrain_General_message  oETCS_Packet_Radio_TrackToTrain_General_message;
// instatiate this ptrtype variable like this: (get memory and fill memory)
// TP_DATA_oETCS_Radio_TrackToTrain_General_message  oETCS_Packet_Radio_TrackToTrain_General_message = new(T_DATA_oETCS_Radio_TrackToTrain_General_message);
// and now fill in the content to start with ...
// Access variable like this: oETCS_Packet_Radio_TrackToTrain_General_message->...
// maybe : memset(oETCS_Packet_Radio_TrackToTrain_General_message, 0, sizeof(T_DATA_oETCS_Packet_Radio_TrackToTrain_General_message));
// for complete 0 content.

#endif


