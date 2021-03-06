#ifndef NESTINGMARK_oETCS_Packet_TrainToTrack_Position_Report
#define NESTINGMARK_oETCS_Packet_TrainToTrack_Position_Report
/* =============================================================================
Formalization of Subset-026-7 (Chapter 7: ERTMS/ETCS language)

- Name: Subset-026-7 / TrainToTrack_Position_Report
- Description: UNISIG SUBSET-026-7, ISSUE : 3.3.0, 3.5 ERTMS/ETCS language) 
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

struct DATA_oETCS_TrainToTrack_Position_Report {
  int vUsed_idx;                             // aktueller Fuellgrad von aPacket

  struct 
  {
          uint32_t v_TOccurence;            // Zeitpunkt des Empfangs
          uint64_t v_DOccurrence;           // Ort des Empfangs
          uint32_t vState;                  // Bearbeitungszustaende  
  } info;

  struct 
 { 
// TransmissionMedia=RBC, RIU
// This packet is used to report the train position and speed as well as some additional information (e.g. mode, level, etc.)
// Packet Number = 0

	uint32_t               NID_PACKET;            		// # 8	
	uint32_t               L_PACKET              ;		// # 13	
	T_q_scale              Q_SCALE               ;		// # 2	
	uint32_t               NID_LRBG              ;		// # 24	
	uint32_t               D_LRBG                ;		// # 15	
	T_q_dirlrbg            Q_DIRLRBG             ;		// # 2	
	T_q_dlrbg              Q_DLRBG               ;		// # 2	
	uint32_t               L_DOUBTOVER           ;		// # 15	
	uint32_t               L_DOUBTUNDER          ;		// # 15	
	T_q_length             Q_LENGTH              ;		// # 2		// if ((Q_LENGTH == 1) OR (Q_LENGTH == 2))
	uint32_t               L_TRAININT            ;		// # 15		// If Q_LENGTH = 1 OR 2
	uint32_t               V_TRAIN               ;		// # 7	
	T_q_dirtrain           Q_DIRTRAIN            ;		// # 2	
	T_m_mode               M_MODE                ;		// # 4	
	T_m_level              M_LEVEL               ;		// # 3		// if (M_LEVEL == 1)
	uint32_t               NID_NTC               ;		// # 8		// If M_LEVEL = 1
} 


   aPacket[2];       // Instanz der Sturkur mit dem content
};

// struct -> type
typedef struct DATA_oETCS_TrainToTrack_Position_Report T_DATA_oETCS_TrainToTrack_Position_Report;
// typ -> ptrtyp
typedef  T_DATA_oETCS_TrainToTrack_Position_Report* TP_DATA_oETCS_TrainToTrack_Position_Report;
// declaration of variable of ptrtyp
extern TP_DATA_oETCS_TrainToTrack_Position_Report  oETCS_Packet_TrainToTrack_Position_Report;
// instatiate this ptrtype variable like this: (get memory and fill memory)
// TP_DATA_oETCS_TrainToTrack_Position_Report  oETCS_Packet_TrainToTrack_Position_Report = new(T_DATA_oETCS_TrainToTrack_Position_Report);
// and now fill in the content to start with ...
// Access variable like this: oETCS_Packet_TrainToTrack_Position_Report->...
// maybe : memset(oETCS_Packet_TrainToTrack_Position_Report, 0, sizeof(T_DATA_oETCS_Packet_TrainToTrack_Position_Report));
// for complete 0 content.

#endif


