#ifndef NESTINGMARK_oETCS_Packet_TrackToTrain_List_of_Balises_in_SR_Authority
#define NESTINGMARK_oETCS_Packet_TrackToTrain_List_of_Balises_in_SR_Authority
/* =============================================================================
Formalization of Subset-026-7 (Chapter 7: ERTMS/ETCS language)

- Name: Subset-026-7 / TrackToTrain_List_of_Balises_in_SR_Authority
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

struct DATA_oETCS_TrackToTrain_List_of_Balises_in_SR_Authority {
  int vUsed_idx;                             // aktueller Fuellgrad von aPacket

  struct 
  {
          uint32_t v_TOccurence;            // Zeitpunkt des Empfangs
          uint64_t v_DOccurrence;           // Ort des Empfangs
          uint32_t vState;                  // Bearbeitungszustaende  
  } info;

  struct 
 { 
// TransmissionMedia=RBC
// Used to list balise group(s) which the train can pass over in SR mode
// Packet Number = 63

	uint32_t               NID_PACKET;            		// # 8	
	T_q_dir                Q_DIR                 ;		// # 2	
	uint32_t               L_PACKET              ;		// # 13	    
        struct {
            uint32_t used;                        //N_ITER+1              // # 5
            struct {

		uint32_t Q_NEWCOUNTRY;                    		// # 1		// if (Q_NEWCOUNTRY(k) == 1)
		uint32_t NID_C;                           		// # 10		// if Q_NEWCOUNTRY(k) = 1
		uint32_t NID_BG;                          		// # 14	        
        } a_data[33];
        } k;

} 


   aPacket[2];       // Instanz der Sturkur mit dem content
};

// struct -> type
typedef struct DATA_oETCS_TrackToTrain_List_of_Balises_in_SR_Authority T_DATA_oETCS_TrackToTrain_List_of_Balises_in_SR_Authority;
// typ -> ptrtyp
typedef  T_DATA_oETCS_TrackToTrain_List_of_Balises_in_SR_Authority* TP_DATA_oETCS_TrackToTrain_List_of_Balises_in_SR_Authority;
// declaration of variable of ptrtyp
extern TP_DATA_oETCS_TrackToTrain_List_of_Balises_in_SR_Authority  oETCS_Packet_TrackToTrain_List_of_Balises_in_SR_Authority;
// instatiate this ptrtype variable like this: (get memory and fill memory)
// TP_DATA_oETCS_TrackToTrain_List_of_Balises_in_SR_Authority  oETCS_Packet_TrackToTrain_List_of_Balises_in_SR_Authority = new(T_DATA_oETCS_TrackToTrain_List_of_Balises_in_SR_Authority);
// and now fill in the content to start with ...
// Access variable like this: oETCS_Packet_TrackToTrain_List_of_Balises_in_SR_Authority->...
// maybe : memset(oETCS_Packet_TrackToTrain_List_of_Balises_in_SR_Authority, 0, sizeof(T_DATA_oETCS_Packet_TrackToTrain_List_of_Balises_in_SR_Authority));
// for complete 0 content.

#endif


