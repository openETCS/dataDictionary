#ifndef NESTINGMARK_oETCS_Packet_Radio_TrainToTrack_Train_Position_Report
#define NESTINGMARK_oETCS_Packet_Radio_TrainToTrack_Train_Position_Report
/* =============================================================================
Formalization of Subset-026-8 (Chapter 8: ERTMS/ETCS language)

- Name: Subset-026-8 / Radio_TrainToTrack_Train_Position_Report
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
	Train_Position_Report_OptionalPacketNumber_0 = 0,
	Train_Position_Report_OptionalPacketNumber_1 = 1,
	Train_Position_Report_OptionalPacketNumber_4 = 4,
	Train_Position_Report_OptionalPacketNumber_5 = 5,
	Train_Position_Report_OptionalPacketNumber_44 = 44
} Train_Position_Report_OptionalPackets ;

struct DATA_oETCS_Radio_TrainToTrack_Train_Position_Report {
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
	uint32_t NID_ENGINE;                             			// # 24		// int
	uint32_t PADDING3;                               			// # 6	
	uint32_t Train_Position_Report_OptionalPackets;		 // # Length is unknown here; depends on current package number(s)


} 


   aPacket[2];       // Instanz der Sturkur mit dem content
};

// struct -> type
typedef struct DATA_oETCS_Radio_TrainToTrack_Train_Position_Report T_DATA_oETCS_Radio_TrainToTrack_Train_Position_Report;
// typ -> ptrtyp
typedef  T_DATA_oETCS_Radio_TrainToTrack_Train_Position_Report* TP_DATA_oETCS_Radio_TrainToTrack_Train_Position_Report;
// declaration of variable of ptrtyp
extern TP_DATA_oETCS_Radio_TrainToTrack_Train_Position_Report  oETCS_Packet_Radio_TrainToTrack_Train_Position_Report;
// instatiate this ptrtype variable like this: (get memory and fill memory)
// TP_DATA_oETCS_Radio_TrainToTrack_Train_Position_Report  oETCS_Packet_Radio_TrainToTrack_Train_Position_Report = new(T_DATA_oETCS_Radio_TrainToTrack_Train_Position_Report);
// and now fill in the content to start with ...
// Access variable like this: oETCS_Packet_Radio_TrainToTrack_Train_Position_Report->...
// maybe : memset(oETCS_Packet_Radio_TrainToTrack_Train_Position_Report, 0, sizeof(T_DATA_oETCS_Packet_Radio_TrainToTrack_Train_Position_Report));
// for complete 0 content.

#endif


