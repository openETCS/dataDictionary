#ifndef NESTINGMARK_oETCS_Packet_Radio_TrainToTrack_Acknowledgement_of_Emergency_Stop
#define NESTINGMARK_oETCS_Packet_Radio_TrainToTrack_Acknowledgement_of_Emergency_Stop
/* =============================================================================
Formalization of Subset-026-8 (Chapter 8: ERTMS/ETCS language)

- Name: Subset-026-8 / Radio_TrainToTrack_Acknowledgement_of_Emergency_Stop
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
	Acknowledgement_of_Emergency_Stop_OptionalPacketNumber_0 = 0,
	Acknowledgement_of_Emergency_Stop_OptionalPacketNumber_1 = 1
} Acknowledgement_of_Emergency_Stop_OptionalPackets ;

struct DATA_oETCS_Radio_TrainToTrack_Acknowledgement_of_Emergency_Stop {
  int vUsed_idx;                             // aktueller Fuellgrad von aPacket

  struct 
  {
          uint32_t v_TOccurence;            // Zeitpunkt des Empfangs
          uint64_t v_DOccurrence;           // Ort des Empfangs
          uint32_t vState;                  // Bearbeitungszustände  
  } info;

  struct 
 { 
// TransmissionMedia=RBC

	uint32_t NID_MESSAGE;                            			// # 8		// int
	uint32_t L_MESSAGE;                              			// # 10		// int
	uint32_t T_TRAIN;                                			// # 32		// real
	uint32_t NID_ENGINE;                             			// # 24		// int
	uint32_t NID_EM;                                 			// # 4	
	uint32_t Q_EMERGENCYSTOP;                        			// # 2		// enum
	uint32_t Acknowledgement_of_Emergency_Stop_OptionalPackets;		 // # Length is unknown here; depends on current package number(s)


} 


   aPacket[2];       // Instanz der Sturkur mit dem content
};

// struct -> type
typedef struct DATA_oETCS_Radio_TrainToTrack_Acknowledgement_of_Emergency_Stop T_DATA_oETCS_Radio_TrainToTrack_Acknowledgement_of_Emergency_Stop;
// typ -> ptrtyp
typedef  T_DATA_oETCS_Radio_TrainToTrack_Acknowledgement_of_Emergency_Stop* TP_DATA_oETCS_Radio_TrainToTrack_Acknowledgement_of_Emergency_Stop;
// declaration of variable of ptrtyp
extern TP_DATA_oETCS_Radio_TrainToTrack_Acknowledgement_of_Emergency_Stop  oETCS_Packet_Radio_TrainToTrack_Acknowledgement_of_Emergency_Stop;
// instatiate this ptrtype variable like this: (get memory and fill memory)
// TP_DATA_oETCS_Radio_TrainToTrack_Acknowledgement_of_Emergency_Stop  oETCS_Packet_Radio_TrainToTrack_Acknowledgement_of_Emergency_Stop = new(T_DATA_oETCS_Radio_TrainToTrack_Acknowledgement_of_Emergency_Stop);
// and now fill in the content to start with ...
// Access variable like this: oETCS_Packet_Radio_TrainToTrack_Acknowledgement_of_Emergency_Stop->...
// maybe : memset(oETCS_Packet_Radio_TrainToTrack_Acknowledgement_of_Emergency_Stop, 0, sizeof(T_DATA_oETCS_Packet_Radio_TrainToTrack_Acknowledgement_of_Emergency_Stop));
// for complete 0 content.

#endif


