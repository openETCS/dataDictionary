#include <stdint.h>
#include "opnETCS_Variables.h"
#include "subset026_7.h"
#include "Bitwalker.h"
#include "opnETCS_Decoder.h"
#include "opnETCS_DecoderBranch.h"


/* =============================================================================
Formalization of Subset-026-7 (Chapter 7: ERTMS/ETCS language)

- Name: opnETCS_Decoder.c
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


//Namespace TrackToTrain starts here

int TrackToTrain_Packet_000 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_TrackToTrain_Virtual_Balise_Cover_marker oETCS ) 
{  
//    TP_DATA_oETCS_TrackToTrain_Virtual_Balise_Cover_marker oETCS  = (TP_DATA_oETCS_TrackToTrain_Virtual_Balise_Cover_marker)void_oETCS;
    T_Bitwalker_Incremental_Locals PeekLocals;
    Bitwalker_IncrementalWalker_Init(&PeekLocals, p_Telegramm, i_akt_dim, bitindex);

// TransmissionMedia=Balise
// Packet Number = 0
	oETCS->aPacket[i_ArrayIndex].NID_PACKET                                  = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 8);
	oETCS->aPacket[i_ArrayIndex].NID_VBCMK                                   = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 6);
    return Bitwalker_IncrementalWalker_Peek_Finish (&PeekLocals);
    
    }
// =======================

int TrackToTrain_Packet_002 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_TrackToTrain_System_Version_order oETCS ) 
{  
//    TP_DATA_oETCS_TrackToTrain_System_Version_order oETCS  = (TP_DATA_oETCS_TrackToTrain_System_Version_order)void_oETCS;
    T_Bitwalker_Incremental_Locals PeekLocals;
    Bitwalker_IncrementalWalker_Init(&PeekLocals, p_Telegramm, i_akt_dim, bitindex);

// TransmissionMedia=Balise
// Packet Number = 2
	oETCS->aPacket[i_ArrayIndex].NID_PACKET                                  = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 8);
	oETCS->aPacket[i_ArrayIndex].Q_DIR                                       = (T_q_dir) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 2);
	oETCS->aPacket[i_ArrayIndex].L_PACKET                                    = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,13);
	oETCS->aPacket[i_ArrayIndex].M_VERSION                                   = (T_m_version) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 7);
    return Bitwalker_IncrementalWalker_Peek_Finish (&PeekLocals);
    
    }
// =======================

int TrackToTrain_Packet_003 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_TrackToTrain_National_Values oETCS ) 
{  
//    TP_DATA_oETCS_TrackToTrain_National_Values oETCS  = (TP_DATA_oETCS_TrackToTrain_National_Values)void_oETCS;
    T_Bitwalker_Incremental_Locals PeekLocals;
    Bitwalker_IncrementalWalker_Init(&PeekLocals, p_Telegramm, i_akt_dim, bitindex);

// TransmissionMedia=Balise, RBC
// Packet Number = 3
	oETCS->aPacket[i_ArrayIndex].NID_PACKET                                  = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 8);
	oETCS->aPacket[i_ArrayIndex].Q_DIR                                       = (T_q_dir) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 2);
	oETCS->aPacket[i_ArrayIndex].L_PACKET                                    = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,13);
	oETCS->aPacket[i_ArrayIndex].Q_SCALE                                     = (T_q_scale) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 2);
	oETCS->aPacket[i_ArrayIndex].D_VALIDNV                                   = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,15);
	oETCS->aPacket[i_ArrayIndex].NID_C                                       = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,10);
    uint32_t j = 0;
    do 
    {
        if ( j == 0 ) {
             oETCS->aPacket[i_ArrayIndex].p.used                = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 5) + 1;
        }
		oETCS->aPacket[i_ArrayIndex].p.a_data[j].NID_C                           = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,10);
    } while ( ++j < oETCS->aPacket[i_ArrayIndex].p.used );
	oETCS->aPacket[i_ArrayIndex].V_NVSHUNT                                   = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 7);
	oETCS->aPacket[i_ArrayIndex].V_NVSTFF                                    = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 7);
	oETCS->aPacket[i_ArrayIndex].V_NVONSIGHT                                 = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 7);
	oETCS->aPacket[i_ArrayIndex].V_NVLIMSUPERV                               = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 7);
	oETCS->aPacket[i_ArrayIndex].V_NVUNFIT                                   = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 7);
	oETCS->aPacket[i_ArrayIndex].V_NVREL                                     = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 7);
	oETCS->aPacket[i_ArrayIndex].D_NVROLL                                    = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,15);
	oETCS->aPacket[i_ArrayIndex].Q_NVSBTSMPERM                               = (T_q_nvsbtsmperm) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 1);
	oETCS->aPacket[i_ArrayIndex].Q_NVEMRRLS                                  = (T_q_nvemrrls) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 1);
	oETCS->aPacket[i_ArrayIndex].Q_NVGUIPERM                                 = (T_q_nvguiperm) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 1);
	oETCS->aPacket[i_ArrayIndex].Q_NVSBFBPERM                                = (T_q_nvsbfbperm) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 1);
	oETCS->aPacket[i_ArrayIndex].Q_NVINHSMICPERM                             = (T_q_nvinhsmicperm) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 1);
	oETCS->aPacket[i_ArrayIndex].V_NVALLOWOVTRP                              = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 7);
	oETCS->aPacket[i_ArrayIndex].V_NVSUPOVTRP                                = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 7);
	oETCS->aPacket[i_ArrayIndex].D_NVOVTRP                                   = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,15);
	oETCS->aPacket[i_ArrayIndex].T_NVOVTRP                                   = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 8);
	oETCS->aPacket[i_ArrayIndex].D_NVPOTRP                                   = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,15);
	oETCS->aPacket[i_ArrayIndex].M_NVCONTACT                                 = (T_m_nvcontact) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 2);
	oETCS->aPacket[i_ArrayIndex].T_NVCONTACT                                 = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 8);
	oETCS->aPacket[i_ArrayIndex].M_NVDERUN                                   = (T_m_nvderun) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 1);
	oETCS->aPacket[i_ArrayIndex].D_NVSTFF                                    = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,15);
	oETCS->aPacket[i_ArrayIndex].Q_NVDRIVER_ADHES                            = (T_q_nvdriver_adhes) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 1);
	oETCS->aPacket[i_ArrayIndex].A_NVMAXREDADH1                              = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 6);
	oETCS->aPacket[i_ArrayIndex].A_NVMAXREDADH2                              = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 6);
	oETCS->aPacket[i_ArrayIndex].A_NVMAXREDADH3                              = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 6);
	oETCS->aPacket[i_ArrayIndex].Q_NVLOCACC                                  = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 6);
	oETCS->aPacket[i_ArrayIndex].M_NVAVADH                                   = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 5);
	oETCS->aPacket[i_ArrayIndex].M_NVEBCL                                    = (T_m_nvebcl) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 4);
	oETCS->aPacket[i_ArrayIndex].Q_NVKINT                                    = (T_q_nvkint) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 1);
    if ( oETCS->aPacket[i_ArrayIndex].Q_NVKINT == 1 ) 
    {
	oETCS->aPacket[i_ArrayIndex].Q_NVKVINTSET                                = (T_q_nvkvintset) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 2);
    if ( oETCS->aPacket[i_ArrayIndex].Q_NVKVINTSET == 1 ) 
    {
	oETCS->aPacket[i_ArrayIndex].A_NVP12                                     = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 6);
	oETCS->aPacket[i_ArrayIndex].A_NVP23                                     = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 6);
	}
	oETCS->aPacket[i_ArrayIndex].V_NVKVINT                                   = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 7);
	oETCS->aPacket[i_ArrayIndex].M_NVKVINT                                   = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 7);
    j = 0;
    do 
    {
        if ( j == 0 ) {
             oETCS->aPacket[i_ArrayIndex].n.used                = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 5) + 1;
        }
		oETCS->aPacket[i_ArrayIndex].n.a_data[j].V_NVKVINT                       = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 7);
		oETCS->aPacket[i_ArrayIndex].n.a_data[j].M_NVKVINT                       = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 7);
    } while ( ++j < oETCS->aPacket[i_ArrayIndex].n.used );
    j = 0;
    do 
    {
        if ( j == 0 ) {
             oETCS->aPacket[i_ArrayIndex].k.used                = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 5) + 1;
        }
		oETCS->aPacket[i_ArrayIndex].k.a_data[j].Q_NVKVINTSET                    = (T_q_nvkvintset) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 2);
    if ( oETCS->aPacket[i_ArrayIndex].k.a_data[j].Q_NVKVINTSET == 1 ) 
    {
		oETCS->aPacket[i_ArrayIndex].k.a_data[j].A_NVP12                         = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 6);
		oETCS->aPacket[i_ArrayIndex].k.a_data[j].A_NVP23                         = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 6);
	}
		oETCS->aPacket[i_ArrayIndex].k.a_data[j].V_NVKVINT                       = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 7);
		oETCS->aPacket[i_ArrayIndex].k.a_data[j].M_NVKVINT                       = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 7);
        oETCS->aPacket[i_ArrayIndex].k.a_data[j].km.N_ITER = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 5);
        uint32_t Loopend  = oETCS->aPacket[i_ArrayIndex].k.a_data[j].km.N_ITER;      // das ist N_ITER(k)
        uint32_t i        = 0;
        for ( i=0; i < Loopend; i++ ) 
        {
        if ( i == 0 ) {
             oETCS->aPacket[i_ArrayIndex].k.used                = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 5) + 1;
        }
			oETCS->aPacket[i_ArrayIndex].k.a_data[j].km.a_data[i].V_NVKVINT           = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,  7);
			oETCS->aPacket[i_ArrayIndex].k.a_data[j].km.a_data[i].M_NVKVINT           = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,  7);
		}		// end for
    } while ( ++j < oETCS->aPacket[i_ArrayIndex].k.used );
	oETCS->aPacket[i_ArrayIndex].L_NVKRINT                                   = (T_l_nvkrint) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 5);
	oETCS->aPacket[i_ArrayIndex].M_NVKRINT                                   = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 5);
    j = 0;
    do 
    {
        if ( j == 0 ) {
             oETCS->aPacket[i_ArrayIndex].l.used                = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 5) + 1;
        }
		oETCS->aPacket[i_ArrayIndex].l.a_data[j].L_NVKRINT                       = (T_l_nvkrint) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 5);
		oETCS->aPacket[i_ArrayIndex].l.a_data[j].M_NVKRINT                       = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 5);
    } while ( ++j < oETCS->aPacket[i_ArrayIndex].l.used );
	oETCS->aPacket[i_ArrayIndex].M_NVKTINT                                   = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 5);
	}
    return Bitwalker_IncrementalWalker_Peek_Finish (&PeekLocals);
    
    }
// =======================

int TrackToTrain_Packet_005 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_TrackToTrain_Linking oETCS ) 
{  
//    TP_DATA_oETCS_TrackToTrain_Linking oETCS  = (TP_DATA_oETCS_TrackToTrain_Linking)void_oETCS;
    T_Bitwalker_Incremental_Locals PeekLocals;
    Bitwalker_IncrementalWalker_Init(&PeekLocals, p_Telegramm, i_akt_dim, bitindex);

// TransmissionMedia=Any
// Packet Number = 5
	oETCS->aPacket[i_ArrayIndex].NID_PACKET                                  = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 8);
	oETCS->aPacket[i_ArrayIndex].Q_DIR                                       = (T_q_dir) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 2);
	oETCS->aPacket[i_ArrayIndex].L_PACKET                                    = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,13);
	oETCS->aPacket[i_ArrayIndex].Q_SCALE                                     = (T_q_scale) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 2);
	oETCS->aPacket[i_ArrayIndex].D_LINK                                      = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,15);
	oETCS->aPacket[i_ArrayIndex].Q_NEWCOUNTRY                                = (T_q_newcountry) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 1);
    if ( oETCS->aPacket[i_ArrayIndex].Q_NEWCOUNTRY == 1 ) 
    {
	oETCS->aPacket[i_ArrayIndex].NID_C                                       = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,10);
	}
	oETCS->aPacket[i_ArrayIndex].NID_BG                                      = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,14);
	oETCS->aPacket[i_ArrayIndex].Q_LINKORIENTATION                           = (T_q_linkorientation) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 1);
	oETCS->aPacket[i_ArrayIndex].Q_LINKREACTION                              = (T_q_linkreaction) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 2);
	oETCS->aPacket[i_ArrayIndex].Q_LOCACC                                    = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 6);
    uint32_t j = 0;
    do 
    {
        if ( j == 0 ) {
             oETCS->aPacket[i_ArrayIndex].k.used                = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 5) + 1;
        }
		oETCS->aPacket[i_ArrayIndex].k.a_data[j].D_LINK                          = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,15);
		oETCS->aPacket[i_ArrayIndex].k.a_data[j].Q_NEWCOUNTRY                    = (T_q_newcountry) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 1);
    if ( oETCS->aPacket[i_ArrayIndex].k.a_data[j].Q_NEWCOUNTRY == 1 ) 
    {
		oETCS->aPacket[i_ArrayIndex].k.a_data[j].NID_C                           = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,10);
	}
		oETCS->aPacket[i_ArrayIndex].k.a_data[j].NID_BG                          = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,14);
		oETCS->aPacket[i_ArrayIndex].k.a_data[j].Q_LINKORIENTATION               = (T_q_linkorientation) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 1);
		oETCS->aPacket[i_ArrayIndex].k.a_data[j].Q_LINKREACTION                  = (T_q_linkreaction) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 2);
		oETCS->aPacket[i_ArrayIndex].k.a_data[j].Q_LOCACC                        = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 6);
    } while ( ++j < oETCS->aPacket[i_ArrayIndex].k.used );
    return Bitwalker_IncrementalWalker_Peek_Finish (&PeekLocals);
    
    }
// =======================

int TrackToTrain_Packet_006 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_TrackToTrain_Virtual_Balise_Cover_order oETCS ) 
{  
//    TP_DATA_oETCS_TrackToTrain_Virtual_Balise_Cover_order oETCS  = (TP_DATA_oETCS_TrackToTrain_Virtual_Balise_Cover_order)void_oETCS;
    T_Bitwalker_Incremental_Locals PeekLocals;
    Bitwalker_IncrementalWalker_Init(&PeekLocals, p_Telegramm, i_akt_dim, bitindex);

// TransmissionMedia=Balise
// Packet Number = 6
	oETCS->aPacket[i_ArrayIndex].NID_PACKET                                  = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 8);
	oETCS->aPacket[i_ArrayIndex].Q_DIR                                       = (T_q_dir) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 2);
	oETCS->aPacket[i_ArrayIndex].L_PACKET                                    = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,13);
	oETCS->aPacket[i_ArrayIndex].Q_VBCO                                      = (T_q_vbco) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 1);
	oETCS->aPacket[i_ArrayIndex].NID_VBCMK                                   = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 6);
	oETCS->aPacket[i_ArrayIndex].NID_C                                       = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,10);
    if ( oETCS->aPacket[i_ArrayIndex].Q_VBCO == 1 ) 
    {
	oETCS->aPacket[i_ArrayIndex].T_VBC                                       = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 8);
	}
    return Bitwalker_IncrementalWalker_Peek_Finish (&PeekLocals);
    
    }
// =======================

int TrackToTrain_Packet_012 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_TrackToTrain_Level_1_Movement_Authority oETCS ) 
{  
//    TP_DATA_oETCS_TrackToTrain_Level_1_Movement_Authority oETCS  = (TP_DATA_oETCS_TrackToTrain_Level_1_Movement_Authority)void_oETCS;
    T_Bitwalker_Incremental_Locals PeekLocals;
    Bitwalker_IncrementalWalker_Init(&PeekLocals, p_Telegramm, i_akt_dim, bitindex);

// TransmissionMedia=Balise, Loop, RIU
// Packet Number = 12
	oETCS->aPacket[i_ArrayIndex].NID_PACKET                                  = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 8);
	oETCS->aPacket[i_ArrayIndex].Q_DIR                                       = (T_q_dir) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 2);
	oETCS->aPacket[i_ArrayIndex].L_PACKET                                    = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,13);
	oETCS->aPacket[i_ArrayIndex].Q_SCALE                                     = (T_q_scale) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 2);
	oETCS->aPacket[i_ArrayIndex].V_MAIN                                      = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 7);
	oETCS->aPacket[i_ArrayIndex].V_LOA                                       = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 7);
	oETCS->aPacket[i_ArrayIndex].T_LOA                                       = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,10);
    uint32_t j = 0;
    do 
    {
        if ( j == 0 ) {
             oETCS->aPacket[i_ArrayIndex].k.used                = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 5) + 1;
        }
		oETCS->aPacket[i_ArrayIndex].k.a_data[j].L_SECTION                       = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,15);
		oETCS->aPacket[i_ArrayIndex].k.a_data[j].Q_SECTIONTIMER                  = (T_q_sectiontimer) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 1);
		oETCS->aPacket[i_ArrayIndex].k.a_data[j].T_SECTIONTIMER                  = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,10);
		oETCS->aPacket[i_ArrayIndex].k.a_data[j].D_SECTIONTIMERSTOPLOC           = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,15);
    } while ( ++j < oETCS->aPacket[i_ArrayIndex].k.used );
	oETCS->aPacket[i_ArrayIndex].L_ENDSECTION                                = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,15);
	oETCS->aPacket[i_ArrayIndex].Q_SECTIONTIMER                              = (T_q_sectiontimer) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 1);
	oETCS->aPacket[i_ArrayIndex].T_SECTIONTIMER                              = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,10);
	oETCS->aPacket[i_ArrayIndex].D_SECTIONTIMERSTOPLOC                       = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,15);
	oETCS->aPacket[i_ArrayIndex].Q_ENDTIMER                                  = (T_q_endtimer) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 1);
	oETCS->aPacket[i_ArrayIndex].T_ENDTIMER                                  = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,10);
	oETCS->aPacket[i_ArrayIndex].D_ENDTIMERSTARTLOC                          = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,15);
	oETCS->aPacket[i_ArrayIndex].Q_DANGERPOINT                               = (T_q_dangerpoint) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 1);
	oETCS->aPacket[i_ArrayIndex].D_DP                                        = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,15);
	oETCS->aPacket[i_ArrayIndex].V_RELEASEDP                                 = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 7);
	oETCS->aPacket[i_ArrayIndex].Q_OVERLAP                                   = (T_q_overlap) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 1);
	oETCS->aPacket[i_ArrayIndex].D_STARTOL                                   = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,15);
	oETCS->aPacket[i_ArrayIndex].T_OL                                        = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,10);
	oETCS->aPacket[i_ArrayIndex].D_OL                                        = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,15);
	oETCS->aPacket[i_ArrayIndex].V_RELEASEOL                                 = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 7);
    return Bitwalker_IncrementalWalker_Peek_Finish (&PeekLocals);
    
    }
// =======================

int TrackToTrain_Packet_013 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_TrackToTrain_Staff_Responsible_distance_Information_from_loop oETCS ) 
{  
//    TP_DATA_oETCS_TrackToTrain_Staff_Responsible_distance_Information_from_loop oETCS  = (TP_DATA_oETCS_TrackToTrain_Staff_Responsible_distance_Information_from_loop)void_oETCS;
    T_Bitwalker_Incremental_Locals PeekLocals;
    Bitwalker_IncrementalWalker_Init(&PeekLocals, p_Telegramm, i_akt_dim, bitindex);

// TransmissionMedia=Loop
// Packet Number = 13
	oETCS->aPacket[i_ArrayIndex].NID_PACKET                                  = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 8);
	oETCS->aPacket[i_ArrayIndex].Q_DIR                                       = (T_q_dir) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 2);
	oETCS->aPacket[i_ArrayIndex].L_PACKET                                    = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,13);
	oETCS->aPacket[i_ArrayIndex].Q_SCALE                                     = (T_q_scale) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 2);
	oETCS->aPacket[i_ArrayIndex].Q_NEWCOUNTRY0                               = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 1);
    if ( oETCS->aPacket[i_ArrayIndex].Q_NEWCOUNTRY0 == 1 ) 
    {
	oETCS->aPacket[i_ArrayIndex].NID_C0                                      = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,10);
	}
	oETCS->aPacket[i_ArrayIndex].NID_BG0                                     = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,14);
	oETCS->aPacket[i_ArrayIndex].Q_NEWCOUNTRY1                               = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 1);
    if ( oETCS->aPacket[i_ArrayIndex].Q_NEWCOUNTRY1 == 1 ) 
    {
	oETCS->aPacket[i_ArrayIndex].NID_C1                                      = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,10);
	}
	oETCS->aPacket[i_ArrayIndex].NID_BG1                                     = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,14);
	oETCS->aPacket[i_ArrayIndex].D_SR                                        = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,15);
    uint32_t j = 0;
    do 
    {
        if ( j == 0 ) {
             oETCS->aPacket[i_ArrayIndex].k.used                = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 5) + 1;
        }
		oETCS->aPacket[i_ArrayIndex].k.a_data[j].Q_NEWCOUNTRY                    = (T_q_newcountry) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 1);
    if ( oETCS->aPacket[i_ArrayIndex].k.a_data[j].Q_NEWCOUNTRY  == 1 ) 
    {
		oETCS->aPacket[i_ArrayIndex].k.a_data[j].NID_C                           = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,10);
	}
		oETCS->aPacket[i_ArrayIndex].k.a_data[j].NID_BG                          = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,14);
		oETCS->aPacket[i_ArrayIndex].k.a_data[j].D_SR                            = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,15);
    } while ( ++j < oETCS->aPacket[i_ArrayIndex].k.used );
    return Bitwalker_IncrementalWalker_Peek_Finish (&PeekLocals);
    
    }
// =======================

int TrackToTrain_Packet_015 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_TrackToTrain_Level_23_Movement_Authority oETCS ) 
{  
//    TP_DATA_oETCS_TrackToTrain_Level_23_Movement_Authority oETCS  = (TP_DATA_oETCS_TrackToTrain_Level_23_Movement_Authority)void_oETCS;
    T_Bitwalker_Incremental_Locals PeekLocals;
    Bitwalker_IncrementalWalker_Init(&PeekLocals, p_Telegramm, i_akt_dim, bitindex);

// TransmissionMedia=RBC
// Packet Number = 15
	oETCS->aPacket[i_ArrayIndex].NID_PACKET                                  = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 8);
	oETCS->aPacket[i_ArrayIndex].Q_DIR                                       = (T_q_dir) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 2);
	oETCS->aPacket[i_ArrayIndex].L_PACKET                                    = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,13);
	oETCS->aPacket[i_ArrayIndex].Q_SCALE                                     = (T_q_scale) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 2);
	oETCS->aPacket[i_ArrayIndex].V_LOA                                       = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 7);
	oETCS->aPacket[i_ArrayIndex].T_LOA                                       = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,10);
    uint32_t j = 0;
    do 
    {
        if ( j == 0 ) {
             oETCS->aPacket[i_ArrayIndex].k.used                = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 5) + 1;
        }
		oETCS->aPacket[i_ArrayIndex].k.a_data[j].L_SECTION                       = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,15);
		oETCS->aPacket[i_ArrayIndex].k.a_data[j].Q_SECTIONTIMER                  = (T_q_sectiontimer) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 1);
		oETCS->aPacket[i_ArrayIndex].k.a_data[j].T_SECTIONTIMER                  = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,10);
		oETCS->aPacket[i_ArrayIndex].k.a_data[j].D_SECTIONTIMERSTOPLOC           = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,15);
    } while ( ++j < oETCS->aPacket[i_ArrayIndex].k.used );
	oETCS->aPacket[i_ArrayIndex].L_ENDSECTION                                = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,15);
	oETCS->aPacket[i_ArrayIndex].Q_SECTIONTIMER                              = (T_q_sectiontimer) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 1);
	oETCS->aPacket[i_ArrayIndex].T_SECTIONTIMER                              = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,10);
	oETCS->aPacket[i_ArrayIndex].D_SECTIONTIMERSTOPLOC                       = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,15);
	oETCS->aPacket[i_ArrayIndex].Q_ENDTIMER                                  = (T_q_endtimer) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 1);
	oETCS->aPacket[i_ArrayIndex].T_ENDTIMER                                  = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,10);
	oETCS->aPacket[i_ArrayIndex].D_ENDTIMERSTARTLOC                          = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,15);
	oETCS->aPacket[i_ArrayIndex].Q_DANGERPOINT                               = (T_q_dangerpoint) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 1);
	oETCS->aPacket[i_ArrayIndex].D_DP                                        = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,15);
	oETCS->aPacket[i_ArrayIndex].V_RELEASEDP                                 = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 7);
	oETCS->aPacket[i_ArrayIndex].Q_OVERLAP                                   = (T_q_overlap) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 1);
	oETCS->aPacket[i_ArrayIndex].D_STARTOL                                   = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,15);
	oETCS->aPacket[i_ArrayIndex].T_OL                                        = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,10);
	oETCS->aPacket[i_ArrayIndex].D_OL                                        = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,15);
	oETCS->aPacket[i_ArrayIndex].V_RELEASEOL                                 = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 7);
    return Bitwalker_IncrementalWalker_Peek_Finish (&PeekLocals);
    
    }
// =======================

int TrackToTrain_Packet_016 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_TrackToTrain_Repositioning_Information oETCS ) 
{  
//    TP_DATA_oETCS_TrackToTrain_Repositioning_Information oETCS  = (TP_DATA_oETCS_TrackToTrain_Repositioning_Information)void_oETCS;
    T_Bitwalker_Incremental_Locals PeekLocals;
    Bitwalker_IncrementalWalker_Init(&PeekLocals, p_Telegramm, i_akt_dim, bitindex);

// TransmissionMedia=Balise
// Packet Number = 16
	oETCS->aPacket[i_ArrayIndex].NID_PACKET                                  = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 8);
	oETCS->aPacket[i_ArrayIndex].Q_DIR                                       = (T_q_dir) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 2);
	oETCS->aPacket[i_ArrayIndex].L_PACKET                                    = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,13);
	oETCS->aPacket[i_ArrayIndex].Q_SCALE                                     = (T_q_scale) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 2);
	oETCS->aPacket[i_ArrayIndex].L_SECTION                                   = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,15);
    return Bitwalker_IncrementalWalker_Peek_Finish (&PeekLocals);
    
    }
// =======================

int TrackToTrain_Packet_021 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_TrackToTrain_Gradient_Profile oETCS ) 
{  
//    TP_DATA_oETCS_TrackToTrain_Gradient_Profile oETCS  = (TP_DATA_oETCS_TrackToTrain_Gradient_Profile)void_oETCS;
    T_Bitwalker_Incremental_Locals PeekLocals;
    Bitwalker_IncrementalWalker_Init(&PeekLocals, p_Telegramm, i_akt_dim, bitindex);

// TransmissionMedia=Any
// Packet Number = 21
	oETCS->aPacket[i_ArrayIndex].NID_PACKET                                  = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 8);
	oETCS->aPacket[i_ArrayIndex].Q_DIR                                       = (T_q_dir) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 2);
	oETCS->aPacket[i_ArrayIndex].L_PACKET                                    = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,13);
	oETCS->aPacket[i_ArrayIndex].Q_SCALE                                     = (T_q_scale) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 2);
	oETCS->aPacket[i_ArrayIndex].D_GRADIENT                                  = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,15);
	oETCS->aPacket[i_ArrayIndex].Q_GDIR                                      = (T_q_gdir) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 1);
	oETCS->aPacket[i_ArrayIndex].G_A                                         = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 8);
    uint32_t j = 0;
    do 
    {
        if ( j == 0 ) {
             oETCS->aPacket[i_ArrayIndex].k.used                = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 5) + 1;
        }
		oETCS->aPacket[i_ArrayIndex].k.a_data[j].D_GRADIENT                      = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,15);
		oETCS->aPacket[i_ArrayIndex].k.a_data[j].Q_GDIR                          = (T_q_gdir) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 1);
		oETCS->aPacket[i_ArrayIndex].k.a_data[j].G_A                             = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 8);
    } while ( ++j < oETCS->aPacket[i_ArrayIndex].k.used );
    return Bitwalker_IncrementalWalker_Peek_Finish (&PeekLocals);
    
    }
// =======================

int TrackToTrain_Packet_027 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_TrackToTrain_International_Static_Speed_Profile oETCS ) 
{  
//    TP_DATA_oETCS_TrackToTrain_International_Static_Speed_Profile oETCS  = (TP_DATA_oETCS_TrackToTrain_International_Static_Speed_Profile)void_oETCS;
    T_Bitwalker_Incremental_Locals PeekLocals;
    Bitwalker_IncrementalWalker_Init(&PeekLocals, p_Telegramm, i_akt_dim, bitindex);

// TransmissionMedia=Any
// Packet Number = 27
	oETCS->aPacket[i_ArrayIndex].NID_PACKET                                  = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 8);
	oETCS->aPacket[i_ArrayIndex].Q_DIR                                       = (T_q_dir) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 2);
	oETCS->aPacket[i_ArrayIndex].L_PACKET                                    = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,13);
	oETCS->aPacket[i_ArrayIndex].Q_SCALE                                     = (T_q_scale) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 2);
	oETCS->aPacket[i_ArrayIndex].D_STATIC                                    = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,15);
	oETCS->aPacket[i_ArrayIndex].V_STATIC                                    = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 7);
	oETCS->aPacket[i_ArrayIndex].Q_FRONT                                     = (T_q_front) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 1);
    uint32_t j = 0;
    do 
    {
        if ( j == 0 ) {
             oETCS->aPacket[i_ArrayIndex].n.used                = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 5) + 1;
        }
		oETCS->aPacket[i_ArrayIndex].n.a_data[j].Q_DIFF                          = (T_q_diff) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 2);
    if ( oETCS->aPacket[i_ArrayIndex].n.a_data[j].Q_DIFF == 0 ) 
    {
		oETCS->aPacket[i_ArrayIndex].n.a_data[j].NC_CDDIFF                       = (T_nc_cddiff) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 4);
	}
    if (( oETCS->aPacket[i_ArrayIndex].n.a_data[j].Q_DIFF == 1 )  || ( oETCS->aPacket[i_ArrayIndex].n.a_data[j].Q_DIFF == 2 ))  
    {
		oETCS->aPacket[i_ArrayIndex].n.a_data[j].NC_DIFF                         = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 4);
	}
		oETCS->aPacket[i_ArrayIndex].n.a_data[j].V_DIFF                          = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 7);
    } while ( ++j < oETCS->aPacket[i_ArrayIndex].n.used );
    j = 0;
    do 
    {
        if ( j == 0 ) {
             oETCS->aPacket[i_ArrayIndex].k.used                = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 5) + 1;
        }
		oETCS->aPacket[i_ArrayIndex].k.a_data[j].D_STATIC                        = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,15);
		oETCS->aPacket[i_ArrayIndex].k.a_data[j].V_STATIC                        = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 7);
		oETCS->aPacket[i_ArrayIndex].k.a_data[j].Q_FRONT                         = (T_q_front) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 1);
        oETCS->aPacket[i_ArrayIndex].k.a_data[j].km.N_ITER = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 5);
        uint32_t Loopend  = oETCS->aPacket[i_ArrayIndex].k.a_data[j].km.N_ITER;      // das ist N_ITER(k)
        uint32_t i        = 0;
        for ( i=0; i < Loopend; i++ ) 
        {
        if ( i == 0 ) {
             oETCS->aPacket[i_ArrayIndex].k.used                = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 5) + 1;
        }
			oETCS->aPacket[i_ArrayIndex].k.a_data[j].km.a_data[i].Q_DIFF              = (T_q_diff) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,  2);
    if ( oETCS->aPacket[i_ArrayIndex].k.a_data[j].km.a_data[i].Q_DIFF == 0 ) 
    {
			oETCS->aPacket[i_ArrayIndex].k.a_data[j].km.a_data[i].NC_CDDIFF           = (T_nc_cddiff) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,  4);
	}
    if (( oETCS->aPacket[i_ArrayIndex].k.a_data[j].km.a_data[i].Q_DIFF == 1 )  || ( oETCS->aPacket[i_ArrayIndex].k.a_data[j].km.a_data[i].Q_DIFF == 2 ))  
    {
			oETCS->aPacket[i_ArrayIndex].k.a_data[j].km.a_data[i].NC_DIFF             = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,  4);
	}
			oETCS->aPacket[i_ArrayIndex].k.a_data[j].km.a_data[i].V_DIFF              = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,  7);
		}		// end for
    } while ( ++j < oETCS->aPacket[i_ArrayIndex].k.used );
    return Bitwalker_IncrementalWalker_Peek_Finish (&PeekLocals);
    
    }
// =======================

int TrackToTrain_Packet_039 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_TrackToTrain_Track_Condition_Change_of_traction_system oETCS ) 
{  
//    TP_DATA_oETCS_TrackToTrain_Track_Condition_Change_of_traction_system oETCS  = (TP_DATA_oETCS_TrackToTrain_Track_Condition_Change_of_traction_system)void_oETCS;
    T_Bitwalker_Incremental_Locals PeekLocals;
    Bitwalker_IncrementalWalker_Init(&PeekLocals, p_Telegramm, i_akt_dim, bitindex);

// TransmissionMedia=Any
// Packet Number = 39
	oETCS->aPacket[i_ArrayIndex].NID_PACKET                                  = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 8);
	oETCS->aPacket[i_ArrayIndex].Q_DIR                                       = (T_q_dir) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 2);
	oETCS->aPacket[i_ArrayIndex].L_PACKET                                    = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,13);
	oETCS->aPacket[i_ArrayIndex].Q_SCALE                                     = (T_q_scale) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 2);
	oETCS->aPacket[i_ArrayIndex].D_TRACTION                                  = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,15);
	oETCS->aPacket[i_ArrayIndex].M_VOLTAGE                                   = (T_m_voltage) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 4);
    if ( oETCS->aPacket[i_ArrayIndex].M_VOLTAGE != 0 ) 
    {
	oETCS->aPacket[i_ArrayIndex].NID_CTRACTION                               = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,10);
	}
    return Bitwalker_IncrementalWalker_Peek_Finish (&PeekLocals);
    
    }
// =======================

int TrackToTrain_Packet_040 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_TrackToTrain_Track_Condition_Change_of_allowed_current_consumption oETCS ) 
{  
//    TP_DATA_oETCS_TrackToTrain_Track_Condition_Change_of_allowed_current_consumption oETCS  = (TP_DATA_oETCS_TrackToTrain_Track_Condition_Change_of_allowed_current_consumption)void_oETCS;
    T_Bitwalker_Incremental_Locals PeekLocals;
    Bitwalker_IncrementalWalker_Init(&PeekLocals, p_Telegramm, i_akt_dim, bitindex);

// TransmissionMedia=Any
// Packet Number = 40
	oETCS->aPacket[i_ArrayIndex].NID_PACKET                                  = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 8);
	oETCS->aPacket[i_ArrayIndex].Q_DIR                                       = (T_q_dir) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 2);
	oETCS->aPacket[i_ArrayIndex].L_PACKET                                    = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,13);
	oETCS->aPacket[i_ArrayIndex].Q_SCALE                                     = (T_q_scale) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 2);
	oETCS->aPacket[i_ArrayIndex].D_CURRENT                                   = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,15);
	oETCS->aPacket[i_ArrayIndex].M_CURRENT                                   = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,10);
    return Bitwalker_IncrementalWalker_Peek_Finish (&PeekLocals);
    
    }
// =======================

int TrackToTrain_Packet_041 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_TrackToTrain_Level_Transition_Order oETCS ) 
{  
//    TP_DATA_oETCS_TrackToTrain_Level_Transition_Order oETCS  = (TP_DATA_oETCS_TrackToTrain_Level_Transition_Order)void_oETCS;
    T_Bitwalker_Incremental_Locals PeekLocals;
    Bitwalker_IncrementalWalker_Init(&PeekLocals, p_Telegramm, i_akt_dim, bitindex);

// TransmissionMedia=Any
// Packet Number = 41
	oETCS->aPacket[i_ArrayIndex].NID_PACKET                                  = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 8);
	oETCS->aPacket[i_ArrayIndex].Q_DIR                                       = (T_q_dir) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 2);
	oETCS->aPacket[i_ArrayIndex].L_PACKET                                    = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,13);
	oETCS->aPacket[i_ArrayIndex].Q_SCALE                                     = (T_q_scale) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 2);
	oETCS->aPacket[i_ArrayIndex].D_LEVELTR                                   = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,15);
	oETCS->aPacket[i_ArrayIndex].M_LEVELTR                                   = (T_m_leveltr) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 3);
    if ( oETCS->aPacket[i_ArrayIndex].M_LEVELTR == 1 ) 
    {
	oETCS->aPacket[i_ArrayIndex].NID_NTC                                     = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 8);
	}
	oETCS->aPacket[i_ArrayIndex].L_ACKLEVELTR                                = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,15);
    uint32_t j = 0;
    do 
    {
        if ( j == 0 ) {
             oETCS->aPacket[i_ArrayIndex].k.used                = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 5) + 1;
        }
		oETCS->aPacket[i_ArrayIndex].k.a_data[j].M_LEVELTR                       = (T_m_leveltr) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 3);
    if ( oETCS->aPacket[i_ArrayIndex].k.a_data[j].M_LEVELTR == 1 ) 
    {
		oETCS->aPacket[i_ArrayIndex].k.a_data[j].NID_NTC                         = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 8);
	}
		oETCS->aPacket[i_ArrayIndex].k.a_data[j].L_ACKLEVELTR                    = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,15);
    } while ( ++j < oETCS->aPacket[i_ArrayIndex].k.used );
    return Bitwalker_IncrementalWalker_Peek_Finish (&PeekLocals);
    
    }
// =======================

int TrackToTrain_Packet_042 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_TrackToTrain_Session_Management oETCS ) 
{  
//    TP_DATA_oETCS_TrackToTrain_Session_Management oETCS  = (TP_DATA_oETCS_TrackToTrain_Session_Management)void_oETCS;
    T_Bitwalker_Incremental_Locals PeekLocals;
    Bitwalker_IncrementalWalker_Init(&PeekLocals, p_Telegramm, i_akt_dim, bitindex);

// TransmissionMedia=Balise, RBC
// Packet Number = 42
	oETCS->aPacket[i_ArrayIndex].NID_PACKET                                  = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 8);
	oETCS->aPacket[i_ArrayIndex].Q_DIR                                       = (T_q_dir) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 2);
	oETCS->aPacket[i_ArrayIndex].L_PACKET                                    = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,13);
	oETCS->aPacket[i_ArrayIndex].Q_RBC                                       = (T_q_rbc) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 1);
	oETCS->aPacket[i_ArrayIndex].NID_C                                       = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,10);
	oETCS->aPacket[i_ArrayIndex].NID_RBC                                     = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,14);
	oETCS->aPacket[i_ArrayIndex].NID_RADIO                                   = Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,64);
	oETCS->aPacket[i_ArrayIndex].Q_SLEEPSESSION                              = (T_q_sleepsession) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 1);
    return Bitwalker_IncrementalWalker_Peek_Finish (&PeekLocals);
    
    }
// =======================

int TrackToTrain_Packet_044 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_TrackToTrain_Data_used_by_applications_outside_the_ERTMSETCS_system oETCS ) 
{  
//    TP_DATA_oETCS_TrackToTrain_Data_used_by_applications_outside_the_ERTMSETCS_system oETCS  = (TP_DATA_oETCS_TrackToTrain_Data_used_by_applications_outside_the_ERTMSETCS_system)void_oETCS;
    T_Bitwalker_Incremental_Locals PeekLocals;
    Bitwalker_IncrementalWalker_Init(&PeekLocals, p_Telegramm, i_akt_dim, bitindex);

// TransmissionMedia=Any
// Packet Number = 44
	oETCS->aPacket[i_ArrayIndex].NID_PACKET                                  = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 8);
	oETCS->aPacket[i_ArrayIndex].Q_DIR                                       = (T_q_dir) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 2);
	oETCS->aPacket[i_ArrayIndex].L_PACKET                                    = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,13);
	oETCS->aPacket[i_ArrayIndex].NID_XUSER                                   = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 9);
    if ( oETCS->aPacket[i_ArrayIndex].NID_XUSER == 102 ) 
    {
	oETCS->aPacket[i_ArrayIndex].NID_NTC                                     = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 8);
	}
	oETCS->aPacket[i_ArrayIndex].Other_data_depending_on__NID_XUSER          = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 0);
    return Bitwalker_IncrementalWalker_Peek_Finish (&PeekLocals);
    
    }
// =======================

int TrackToTrain_Packet_045 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_TrackToTrain_Radio_Network_registration oETCS ) 
{  
//    TP_DATA_oETCS_TrackToTrain_Radio_Network_registration oETCS  = (TP_DATA_oETCS_TrackToTrain_Radio_Network_registration)void_oETCS;
    T_Bitwalker_Incremental_Locals PeekLocals;
    Bitwalker_IncrementalWalker_Init(&PeekLocals, p_Telegramm, i_akt_dim, bitindex);

// TransmissionMedia=Balise, RBC, RIU
// Packet Number = 45
	oETCS->aPacket[i_ArrayIndex].NID_PACKET                                  = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 8);
	oETCS->aPacket[i_ArrayIndex].Q_DIR                                       = (T_q_dir) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 2);
	oETCS->aPacket[i_ArrayIndex].L_PACKET                                    = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,13);
	oETCS->aPacket[i_ArrayIndex].NID_MN                                      = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,24);
    return Bitwalker_IncrementalWalker_Peek_Finish (&PeekLocals);
    
    }
// =======================

int TrackToTrain_Packet_046 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_TrackToTrain_Conditional_Level_Transition_Order oETCS ) 
{  
//    TP_DATA_oETCS_TrackToTrain_Conditional_Level_Transition_Order oETCS  = (TP_DATA_oETCS_TrackToTrain_Conditional_Level_Transition_Order)void_oETCS;
    T_Bitwalker_Incremental_Locals PeekLocals;
    Bitwalker_IncrementalWalker_Init(&PeekLocals, p_Telegramm, i_akt_dim, bitindex);

// TransmissionMedia=Balise
// Packet Number = 46
	oETCS->aPacket[i_ArrayIndex].NID_PACKET                                  = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 8);
	oETCS->aPacket[i_ArrayIndex].Q_DIR                                       = (T_q_dir) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 2);
	oETCS->aPacket[i_ArrayIndex].L_PACKET                                    = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,13);
	oETCS->aPacket[i_ArrayIndex].M_LEVELTR                                   = (T_m_leveltr) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 3);
    if ( oETCS->aPacket[i_ArrayIndex].M_LEVELTR == 1 ) 
    {
	oETCS->aPacket[i_ArrayIndex].NID_NTC                                     = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 8);
	}
    uint32_t j = 0;
    do 
    {
        if ( j == 0 ) {
             oETCS->aPacket[i_ArrayIndex].k.used                = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 5) + 1;
        }
		oETCS->aPacket[i_ArrayIndex].k.a_data[j].M_LEVELTR                       = (T_m_leveltr) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 3);
    if ( oETCS->aPacket[i_ArrayIndex].k.a_data[j].M_LEVELTR == 1 ) 
    {
		oETCS->aPacket[i_ArrayIndex].k.a_data[j].NID_NTC                         = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 8);
	}
    } while ( ++j < oETCS->aPacket[i_ArrayIndex].k.used );
    return Bitwalker_IncrementalWalker_Peek_Finish (&PeekLocals);
    
    }
// =======================

int TrackToTrain_Packet_049 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_TrackToTrain_List_of_balises_for_SH_Area oETCS ) 
{  
//    TP_DATA_oETCS_TrackToTrain_List_of_balises_for_SH_Area oETCS  = (TP_DATA_oETCS_TrackToTrain_List_of_balises_for_SH_Area)void_oETCS;
    T_Bitwalker_Incremental_Locals PeekLocals;
    Bitwalker_IncrementalWalker_Init(&PeekLocals, p_Telegramm, i_akt_dim, bitindex);

// TransmissionMedia=Any
// Packet Number = 49
	oETCS->aPacket[i_ArrayIndex].NID_PACKET                                  = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 8);
	oETCS->aPacket[i_ArrayIndex].Q_DIR                                       = (T_q_dir) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 2);
	oETCS->aPacket[i_ArrayIndex].L_PACKET                                    = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,13);
    uint32_t j = 0;
    do 
    {
        if ( j == 0 ) {
             oETCS->aPacket[i_ArrayIndex].k.used                = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 5) + 1;
        }
		oETCS->aPacket[i_ArrayIndex].k.a_data[j].Q_NEWCOUNTRY                    = (T_q_newcountry) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 1);
    if ( oETCS->aPacket[i_ArrayIndex].k.a_data[j].Q_NEWCOUNTRY == 1 ) 
    {
		oETCS->aPacket[i_ArrayIndex].k.a_data[j].NID_C                           = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,10);
	}
		oETCS->aPacket[i_ArrayIndex].k.a_data[j].NID_BG                          = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,14);
    } while ( ++j < oETCS->aPacket[i_ArrayIndex].k.used );
    return Bitwalker_IncrementalWalker_Peek_Finish (&PeekLocals);
    
    }
// =======================

int TrackToTrain_Packet_051 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_TrackToTrain_Axle_Load_Speed_Profile oETCS ) 
{  
//    TP_DATA_oETCS_TrackToTrain_Axle_Load_Speed_Profile oETCS  = (TP_DATA_oETCS_TrackToTrain_Axle_Load_Speed_Profile)void_oETCS;
    T_Bitwalker_Incremental_Locals PeekLocals;
    Bitwalker_IncrementalWalker_Init(&PeekLocals, p_Telegramm, i_akt_dim, bitindex);

// TransmissionMedia=Any
// Packet Number = 51
	oETCS->aPacket[i_ArrayIndex].NID_PACKET                                  = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 8);
	oETCS->aPacket[i_ArrayIndex].Q_DIR                                       = (T_q_dir) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 2);
	oETCS->aPacket[i_ArrayIndex].L_PACKET                                    = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,13);
	oETCS->aPacket[i_ArrayIndex].Q_SCALE                                     = (T_q_scale) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 2);
	oETCS->aPacket[i_ArrayIndex].Q_TRACKINIT                                 = (T_q_trackinit) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 1);
    if ( oETCS->aPacket[i_ArrayIndex].Q_TRACKINIT == 1 ) 
    {
	oETCS->aPacket[i_ArrayIndex].D_TRACKINIT                                 = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,15);
	}
    if ( oETCS->aPacket[i_ArrayIndex].Q_TRACKINIT == 0 ) 
    {
	oETCS->aPacket[i_ArrayIndex].D_AXLELOAD                                  = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,15);
	oETCS->aPacket[i_ArrayIndex].L_AXLELOAD                                  = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,15);
	oETCS->aPacket[i_ArrayIndex].Q_FRONT                                     = (T_q_front) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 1);
    uint32_t j = 0;
    do 
    {
        if ( j == 0 ) {
             oETCS->aPacket[i_ArrayIndex].n.used                = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 5) + 1;
        }
		oETCS->aPacket[i_ArrayIndex].n.a_data[j].M_AXLELOADCAT                   = (T_m_axleloadcat) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 7);
		oETCS->aPacket[i_ArrayIndex].n.a_data[j].V_AXLELOAD                      = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 7);
    } while ( ++j < oETCS->aPacket[i_ArrayIndex].n.used );
    j = 0;
    do 
    {
        if ( j == 0 ) {
             oETCS->aPacket[i_ArrayIndex].k.used                = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 5) + 1;
        }
		oETCS->aPacket[i_ArrayIndex].k.a_data[j].D_AXLELOAD                      = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,15);
		oETCS->aPacket[i_ArrayIndex].k.a_data[j].L_AXLELOAD                      = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,15);
		oETCS->aPacket[i_ArrayIndex].k.a_data[j].Q_FRONT                         = (T_q_front) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 1);
        oETCS->aPacket[i_ArrayIndex].k.a_data[j].km.N_ITER = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 5);
        uint32_t Loopend  = oETCS->aPacket[i_ArrayIndex].k.a_data[j].km.N_ITER;      // das ist N_ITER(k)
        uint32_t i        = 0;
        for ( i=0; i < Loopend; i++ ) 
        {
        if ( i == 0 ) {
             oETCS->aPacket[i_ArrayIndex].k.used                = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 5) + 1;
        }
			oETCS->aPacket[i_ArrayIndex].k.a_data[j].km.a_data[i].M_AXLELOADCAT       = (T_m_axleloadcat) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,  7);
			oETCS->aPacket[i_ArrayIndex].k.a_data[j].km.a_data[i].V_AXLELOAD          = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,  7);
		}		// end for
    } while ( ++j < oETCS->aPacket[i_ArrayIndex].k.used );
	}
    return Bitwalker_IncrementalWalker_Peek_Finish (&PeekLocals);
    
    }
// =======================

int TrackToTrain_Packet_052 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_TrackToTrain_Permitted_Braking_Distance_Information oETCS ) 
{  
//    TP_DATA_oETCS_TrackToTrain_Permitted_Braking_Distance_Information oETCS  = (TP_DATA_oETCS_TrackToTrain_Permitted_Braking_Distance_Information)void_oETCS;
    T_Bitwalker_Incremental_Locals PeekLocals;
    Bitwalker_IncrementalWalker_Init(&PeekLocals, p_Telegramm, i_akt_dim, bitindex);

// TransmissionMedia=Any
// Packet Number = 52
	oETCS->aPacket[i_ArrayIndex].NID_PACKET                                  = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 8);
	oETCS->aPacket[i_ArrayIndex].Q_DIR                                       = (T_q_dir) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 2);
	oETCS->aPacket[i_ArrayIndex].L_PACKET                                    = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,13);
	oETCS->aPacket[i_ArrayIndex].Q_SCALE                                     = (T_q_scale) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 2);
	oETCS->aPacket[i_ArrayIndex].Q_TRACKINIT                                 = (T_q_trackinit) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 1);
    if ( oETCS->aPacket[i_ArrayIndex].Q_TRACKINIT == 1 ) 
    {
	oETCS->aPacket[i_ArrayIndex].D_TRACKINIT                                 = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,15);
	}
    if ( oETCS->aPacket[i_ArrayIndex].Q_TRACKINIT == 0 ) 
    {
	oETCS->aPacket[i_ArrayIndex].D_PBD                                       = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,15);
	oETCS->aPacket[i_ArrayIndex].Q_GDIR                                      = (T_q_gdir) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 1);
	oETCS->aPacket[i_ArrayIndex].G_PBDSR                                     = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 8);
	oETCS->aPacket[i_ArrayIndex].Q_PBDSR                                     = (T_q_pbdsr) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 1);
	oETCS->aPacket[i_ArrayIndex].D_PBDSR                                     = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,15);
	oETCS->aPacket[i_ArrayIndex].L_PBDSR                                     = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,15);
    uint32_t j = 0;
    do 
    {
        if ( j == 0 ) {
             oETCS->aPacket[i_ArrayIndex].k.used                = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 5) + 1;
        }
		oETCS->aPacket[i_ArrayIndex].k.a_data[j].D_PBD                           = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,15);
		oETCS->aPacket[i_ArrayIndex].k.a_data[j].Q_GDIR                          = (T_q_gdir) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 1);
		oETCS->aPacket[i_ArrayIndex].k.a_data[j].G_PBDSR                         = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 8);
		oETCS->aPacket[i_ArrayIndex].k.a_data[j].Q_PBDSR                         = (T_q_pbdsr) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 1);
		oETCS->aPacket[i_ArrayIndex].k.a_data[j].D_PBDSR                         = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,15);
		oETCS->aPacket[i_ArrayIndex].k.a_data[j].L_PBDSR                         = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,15);
    } while ( ++j < oETCS->aPacket[i_ArrayIndex].k.used );
	}
    return Bitwalker_IncrementalWalker_Peek_Finish (&PeekLocals);
    
    }
// =======================

int TrackToTrain_Packet_057 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_TrackToTrain_Movement_Authority_Request_Parameters oETCS ) 
{  
//    TP_DATA_oETCS_TrackToTrain_Movement_Authority_Request_Parameters oETCS  = (TP_DATA_oETCS_TrackToTrain_Movement_Authority_Request_Parameters)void_oETCS;
    T_Bitwalker_Incremental_Locals PeekLocals;
    Bitwalker_IncrementalWalker_Init(&PeekLocals, p_Telegramm, i_akt_dim, bitindex);

// TransmissionMedia=RBC
// Packet Number = 57
	oETCS->aPacket[i_ArrayIndex].NID_PACKET                                  = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 8);
	oETCS->aPacket[i_ArrayIndex].Q_DIR                                       = (T_q_dir) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 2);
	oETCS->aPacket[i_ArrayIndex].L_PACKET                                    = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,13);
	oETCS->aPacket[i_ArrayIndex].T_MAR                                       = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 8);
	oETCS->aPacket[i_ArrayIndex].T_TIMEOUTRQST                               = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,10);
	oETCS->aPacket[i_ArrayIndex].T_CYCRQST                                   = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 8);
    return Bitwalker_IncrementalWalker_Peek_Finish (&PeekLocals);
    
    }
// =======================

int TrackToTrain_Packet_058 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_TrackToTrain_Position_Report_Parameters oETCS ) 
{  
//    TP_DATA_oETCS_TrackToTrain_Position_Report_Parameters oETCS  = (TP_DATA_oETCS_TrackToTrain_Position_Report_Parameters)void_oETCS;
    T_Bitwalker_Incremental_Locals PeekLocals;
    Bitwalker_IncrementalWalker_Init(&PeekLocals, p_Telegramm, i_akt_dim, bitindex);

// TransmissionMedia=RBC
// Packet Number = 58
	oETCS->aPacket[i_ArrayIndex].NID_PACKET                                  = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 8);
	oETCS->aPacket[i_ArrayIndex].Q_DIR                                       = (T_q_dir) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 2);
	oETCS->aPacket[i_ArrayIndex].L_PACKET                                    = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,13);
	oETCS->aPacket[i_ArrayIndex].Q_SCALE                                     = (T_q_scale) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 2);
	oETCS->aPacket[i_ArrayIndex].T_CYCLOC                                    = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 8);
	oETCS->aPacket[i_ArrayIndex].D_CYCLOC                                    = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,15);
	oETCS->aPacket[i_ArrayIndex].M_LOC                                       = (T_m_loc) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 3);
    uint32_t j = 0;
    do 
    {
        if ( j == 0 ) {
             oETCS->aPacket[i_ArrayIndex].k.used                = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 5) + 1;
        }
		oETCS->aPacket[i_ArrayIndex].k.a_data[j].D_LOC                           = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,15);
		oETCS->aPacket[i_ArrayIndex].k.a_data[j].Q_LGTLOC                        = (T_q_lgtloc) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 1);
    } while ( ++j < oETCS->aPacket[i_ArrayIndex].k.used );
    return Bitwalker_IncrementalWalker_Peek_Finish (&PeekLocals);
    
    }
// =======================

int TrackToTrain_Packet_063 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_TrackToTrain_List_of_Balises_in_SR_Authority oETCS ) 
{  
//    TP_DATA_oETCS_TrackToTrain_List_of_Balises_in_SR_Authority oETCS  = (TP_DATA_oETCS_TrackToTrain_List_of_Balises_in_SR_Authority)void_oETCS;
    T_Bitwalker_Incremental_Locals PeekLocals;
    Bitwalker_IncrementalWalker_Init(&PeekLocals, p_Telegramm, i_akt_dim, bitindex);

// TransmissionMedia=RBC
// Packet Number = 63
	oETCS->aPacket[i_ArrayIndex].NID_PACKET                                  = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 8);
	oETCS->aPacket[i_ArrayIndex].Q_DIR                                       = (T_q_dir) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 2);
	oETCS->aPacket[i_ArrayIndex].L_PACKET                                    = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,13);
    uint32_t j = 0;
    do 
    {
        if ( j == 0 ) {
             oETCS->aPacket[i_ArrayIndex].k.used                = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 5) + 1;
        }
		oETCS->aPacket[i_ArrayIndex].k.a_data[j].Q_NEWCOUNTRY                    = (T_q_newcountry) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 1);
    if ( oETCS->aPacket[i_ArrayIndex].k.a_data[j].Q_NEWCOUNTRY == 1 ) 
    {
		oETCS->aPacket[i_ArrayIndex].k.a_data[j].NID_C                           = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,10);
	}
		oETCS->aPacket[i_ArrayIndex].k.a_data[j].NID_BG                          = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,14);
    } while ( ++j < oETCS->aPacket[i_ArrayIndex].k.used );
    return Bitwalker_IncrementalWalker_Peek_Finish (&PeekLocals);
    
    }
// =======================

int TrackToTrain_Packet_064 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_TrackToTrain_Inhibition_of_revocable_TSRs_from_balises_in_L23 oETCS ) 
{  
//    TP_DATA_oETCS_TrackToTrain_Inhibition_of_revocable_TSRs_from_balises_in_L23 oETCS  = (TP_DATA_oETCS_TrackToTrain_Inhibition_of_revocable_TSRs_from_balises_in_L23)void_oETCS;
    T_Bitwalker_Incremental_Locals PeekLocals;
    Bitwalker_IncrementalWalker_Init(&PeekLocals, p_Telegramm, i_akt_dim, bitindex);

// TransmissionMedia=RBC
// Packet Number = 64
	oETCS->aPacket[i_ArrayIndex].NID_PACKET                                  = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 8);
	oETCS->aPacket[i_ArrayIndex].Q_DIR                                       = (T_q_dir) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 2);
	oETCS->aPacket[i_ArrayIndex].L_PACKET                                    = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,13);
    return Bitwalker_IncrementalWalker_Peek_Finish (&PeekLocals);
    
    }
// =======================

int TrackToTrain_Packet_065 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_TrackToTrain_Temporary_Speed_Restriction oETCS ) 
{  
//    TP_DATA_oETCS_TrackToTrain_Temporary_Speed_Restriction oETCS  = (TP_DATA_oETCS_TrackToTrain_Temporary_Speed_Restriction)void_oETCS;
    T_Bitwalker_Incremental_Locals PeekLocals;
    Bitwalker_IncrementalWalker_Init(&PeekLocals, p_Telegramm, i_akt_dim, bitindex);

// TransmissionMedia=Any
// Packet Number = 65
	oETCS->aPacket[i_ArrayIndex].NID_PACKET                                  = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 8);
	oETCS->aPacket[i_ArrayIndex].Q_DIR                                       = (T_q_dir) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 2);
	oETCS->aPacket[i_ArrayIndex].L_PACKET                                    = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,13);
	oETCS->aPacket[i_ArrayIndex].Q_SCALE                                     = (T_q_scale) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 2);
	oETCS->aPacket[i_ArrayIndex].NID_TSR                                     = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 8);
	oETCS->aPacket[i_ArrayIndex].D_TSR                                       = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,15);
	oETCS->aPacket[i_ArrayIndex].L_TSR                                       = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,15);
	oETCS->aPacket[i_ArrayIndex].Q_FRONT                                     = (T_q_front) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 1);
	oETCS->aPacket[i_ArrayIndex].V_TSR                                       = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 7);
    return Bitwalker_IncrementalWalker_Peek_Finish (&PeekLocals);
    
    }
// =======================

int TrackToTrain_Packet_066 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_TrackToTrain_Temporary_Speed_Restriction_Revocation oETCS ) 
{  
//    TP_DATA_oETCS_TrackToTrain_Temporary_Speed_Restriction_Revocation oETCS  = (TP_DATA_oETCS_TrackToTrain_Temporary_Speed_Restriction_Revocation)void_oETCS;
    T_Bitwalker_Incremental_Locals PeekLocals;
    Bitwalker_IncrementalWalker_Init(&PeekLocals, p_Telegramm, i_akt_dim, bitindex);

// TransmissionMedia=Any
// Packet Number = 66
	oETCS->aPacket[i_ArrayIndex].NID_PACKET                                  = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 8);
	oETCS->aPacket[i_ArrayIndex].Q_DIR                                       = (T_q_dir) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 2);
	oETCS->aPacket[i_ArrayIndex].L_PACKET                                    = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,13);
	oETCS->aPacket[i_ArrayIndex].NID_TSR                                     = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 8);
    return Bitwalker_IncrementalWalker_Peek_Finish (&PeekLocals);
    
    }
// =======================

int TrackToTrain_Packet_067 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_TrackToTrain_Track_Condition_Big_Metal_Masses oETCS ) 
{  
//    TP_DATA_oETCS_TrackToTrain_Track_Condition_Big_Metal_Masses oETCS  = (TP_DATA_oETCS_TrackToTrain_Track_Condition_Big_Metal_Masses)void_oETCS;
    T_Bitwalker_Incremental_Locals PeekLocals;
    Bitwalker_IncrementalWalker_Init(&PeekLocals, p_Telegramm, i_akt_dim, bitindex);

// TransmissionMedia=Balise
// Packet Number = 67
	oETCS->aPacket[i_ArrayIndex].NID_PACKET                                  = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 8);
	oETCS->aPacket[i_ArrayIndex].Q_DIR                                       = (T_q_dir) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 2);
	oETCS->aPacket[i_ArrayIndex].L_PACKET                                    = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,13);
	oETCS->aPacket[i_ArrayIndex].Q_SCALE                                     = (T_q_scale) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 2);
	oETCS->aPacket[i_ArrayIndex].D_TRACKCOND                                 = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,15);
	oETCS->aPacket[i_ArrayIndex].L_TRACKCOND                                 = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,15);
    uint32_t j = 0;
    do 
    {
        if ( j == 0 ) {
             oETCS->aPacket[i_ArrayIndex].k.used                = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 5) + 1;
        }
		oETCS->aPacket[i_ArrayIndex].k.a_data[j].D_TRACKCOND                     = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,15);
		oETCS->aPacket[i_ArrayIndex].k.a_data[j].L_TRACKCOND                     = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,15);
    } while ( ++j < oETCS->aPacket[i_ArrayIndex].k.used );
    return Bitwalker_IncrementalWalker_Peek_Finish (&PeekLocals);
    
    }
// =======================

int TrackToTrain_Packet_068 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_TrackToTrain_Track_Condition oETCS ) 
{  
//    TP_DATA_oETCS_TrackToTrain_Track_Condition oETCS  = (TP_DATA_oETCS_TrackToTrain_Track_Condition)void_oETCS;
    T_Bitwalker_Incremental_Locals PeekLocals;
    Bitwalker_IncrementalWalker_Init(&PeekLocals, p_Telegramm, i_akt_dim, bitindex);

// TransmissionMedia=Any
// Packet Number = 68
	oETCS->aPacket[i_ArrayIndex].NID_PACKET                                  = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 8);
	oETCS->aPacket[i_ArrayIndex].Q_DIR                                       = (T_q_dir) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 2);
	oETCS->aPacket[i_ArrayIndex].L_PACKET                                    = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,13);
	oETCS->aPacket[i_ArrayIndex].Q_SCALE                                     = (T_q_scale) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 2);
	oETCS->aPacket[i_ArrayIndex].Q_TRACKINIT                                 = (T_q_trackinit) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 1);
    if ( oETCS->aPacket[i_ArrayIndex].Q_TRACKINIT == 1 ) 
    {
	oETCS->aPacket[i_ArrayIndex].D_TRACKINIT                                 = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,15);
	}
    if ( oETCS->aPacket[i_ArrayIndex].Q_TRACKINIT == 0 ) 
    {
	oETCS->aPacket[i_ArrayIndex].D_TRACKCOND                                 = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,15);
	oETCS->aPacket[i_ArrayIndex].L_TRACKCOND                                 = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,15);
	oETCS->aPacket[i_ArrayIndex].M_TRACKCOND                                 = (T_m_trackcond) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 4);
    uint32_t j = 0;
    do 
    {
        if ( j == 0 ) {
             oETCS->aPacket[i_ArrayIndex].k.used                = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 5) + 1;
        }
		oETCS->aPacket[i_ArrayIndex].k.a_data[j].D_TRACKCOND                     = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,15);
		oETCS->aPacket[i_ArrayIndex].k.a_data[j].L_TRACKCOND                     = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,15);
		oETCS->aPacket[i_ArrayIndex].k.a_data[j].M_TRACKCOND                     = (T_m_trackcond) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 4);
    } while ( ++j < oETCS->aPacket[i_ArrayIndex].k.used );
	}
    return Bitwalker_IncrementalWalker_Peek_Finish (&PeekLocals);
    
    }
// =======================

int TrackToTrain_Packet_069 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_TrackToTrain_Track_Condition_Station_Platforms oETCS ) 
{  
//    TP_DATA_oETCS_TrackToTrain_Track_Condition_Station_Platforms oETCS  = (TP_DATA_oETCS_TrackToTrain_Track_Condition_Station_Platforms)void_oETCS;
    T_Bitwalker_Incremental_Locals PeekLocals;
    Bitwalker_IncrementalWalker_Init(&PeekLocals, p_Telegramm, i_akt_dim, bitindex);

// TransmissionMedia=Any
// Packet Number = 69
	oETCS->aPacket[i_ArrayIndex].NID_PACKET                                  = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 8);
	oETCS->aPacket[i_ArrayIndex].Q_DIR                                       = (T_q_dir) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 2);
	oETCS->aPacket[i_ArrayIndex].L_PACKET                                    = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,13);
	oETCS->aPacket[i_ArrayIndex].Q_SCALE                                     = (T_q_scale) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 2);
	oETCS->aPacket[i_ArrayIndex].Q_TRACKINIT                                 = (T_q_trackinit) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 1);
    if ( oETCS->aPacket[i_ArrayIndex].Q_TRACKINIT == 1 ) 
    {
	oETCS->aPacket[i_ArrayIndex].D_TRACKINIT                                 = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,15);
	}
    if ( oETCS->aPacket[i_ArrayIndex].Q_TRACKINIT == 0 ) 
    {
	oETCS->aPacket[i_ArrayIndex].D_TRACKCOND                                 = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,15);
	oETCS->aPacket[i_ArrayIndex].L_TRACKCOND                                 = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,15);
	oETCS->aPacket[i_ArrayIndex].M_PLATFORM                                  = (T_m_platform) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 4);
	oETCS->aPacket[i_ArrayIndex].Q_PLATFORM                                  = (T_q_platform) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 2);
    uint32_t j = 0;
    do 
    {
        if ( j == 0 ) {
             oETCS->aPacket[i_ArrayIndex].k.used                = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 5) + 1;
        }
		oETCS->aPacket[i_ArrayIndex].k.a_data[j].D_TRACKCOND                     = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,15);
		oETCS->aPacket[i_ArrayIndex].k.a_data[j].L_TRACKCOND                     = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,15);
		oETCS->aPacket[i_ArrayIndex].k.a_data[j].M_PLATFORM                      = (T_m_platform) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 4);
		oETCS->aPacket[i_ArrayIndex].k.a_data[j].Q_PLATFORM                      = (T_q_platform) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 2);
    } while ( ++j < oETCS->aPacket[i_ArrayIndex].k.used );
	}
    return Bitwalker_IncrementalWalker_Peek_Finish (&PeekLocals);
    
    }
// =======================

int TrackToTrain_Packet_070 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_TrackToTrain_Route_Suitability_Data oETCS ) 
{  
//    TP_DATA_oETCS_TrackToTrain_Route_Suitability_Data oETCS  = (TP_DATA_oETCS_TrackToTrain_Route_Suitability_Data)void_oETCS;
    T_Bitwalker_Incremental_Locals PeekLocals;
    Bitwalker_IncrementalWalker_Init(&PeekLocals, p_Telegramm, i_akt_dim, bitindex);

// TransmissionMedia=Any
// Packet Number = 70
	oETCS->aPacket[i_ArrayIndex].NID_PACKET                                  = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 8);
	oETCS->aPacket[i_ArrayIndex].Q_DIR                                       = (T_q_dir) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 2);
	oETCS->aPacket[i_ArrayIndex].L_PACKET                                    = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,13);
	oETCS->aPacket[i_ArrayIndex].Q_SCALE                                     = (T_q_scale) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 2);
	oETCS->aPacket[i_ArrayIndex].Q_TRACKINIT                                 = (T_q_trackinit) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 1);
    if ( oETCS->aPacket[i_ArrayIndex].Q_TRACKINIT == 1 ) 
    {
	oETCS->aPacket[i_ArrayIndex].D_TRACKINIT                                 = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,15);
	}
    if ( oETCS->aPacket[i_ArrayIndex].Q_TRACKINIT == 0 ) 
    {
	oETCS->aPacket[i_ArrayIndex].D_SUITABILITY                               = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,15);
	oETCS->aPacket[i_ArrayIndex].Q_SUITABILITY                               = (T_q_suitability) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 2);
    if ( oETCS->aPacket[i_ArrayIndex].Q_SUITABILITY == 0 ) 
    {
	oETCS->aPacket[i_ArrayIndex].M_LINEGAUGE                                 = (T_m_linegauge) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 8);
	}
    if ( oETCS->aPacket[i_ArrayIndex].Q_SUITABILITY == 1 ) 
    {
	oETCS->aPacket[i_ArrayIndex].M_AXLELOADCAT                               = (T_m_axleloadcat) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 7);
	}
    if ( oETCS->aPacket[i_ArrayIndex].Q_SUITABILITY == 2 ) 
    {
	oETCS->aPacket[i_ArrayIndex].M_VOLTAGE                                   = (T_m_voltage) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 4);
	}
    if (( oETCS->aPacket[i_ArrayIndex].Q_SUITABILITY == 2 )  && ( oETCS->aPacket[i_ArrayIndex].M_VOLTAGE != 0 ))  
    {
	oETCS->aPacket[i_ArrayIndex].NID_CTRACTION                               = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,10);
	}
    uint32_t j = 0;
    do 
    {
        if ( j == 0 ) {
             oETCS->aPacket[i_ArrayIndex].k.used                = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 5) + 1;
        }
		oETCS->aPacket[i_ArrayIndex].k.a_data[j].D_SUITABILITY                   = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,15);
		oETCS->aPacket[i_ArrayIndex].k.a_data[j].Q_SUITABILITY                   = (T_q_suitability) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 2);
    if ( oETCS->aPacket[i_ArrayIndex].k.a_data[j].Q_SUITABILITY == 0 ) 
    {
		oETCS->aPacket[i_ArrayIndex].k.a_data[j].M_LINEGAUGE                     = (T_m_linegauge) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 8);
	}
    if ( oETCS->aPacket[i_ArrayIndex].k.a_data[j].Q_SUITABILITY == 1 ) 
    {
		oETCS->aPacket[i_ArrayIndex].k.a_data[j].M_AXLELOADCAT                   = (T_m_axleloadcat) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 7);
	}
    if ( oETCS->aPacket[i_ArrayIndex].k.a_data[j].Q_SUITABILITY == 2 ) 
    {
		oETCS->aPacket[i_ArrayIndex].k.a_data[j].M_VOLTAGE                       = (T_m_voltage) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 4);
	}
    if (( oETCS->aPacket[i_ArrayIndex].k.a_data[j].Q_SUITABILITY == 2 )  && ( oETCS->aPacket[i_ArrayIndex].k.a_data[j].M_VOLTAGE != 0 ))  
    {
		oETCS->aPacket[i_ArrayIndex].k.a_data[j].NID_CTRACTION                   = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,10);
	}
    } while ( ++j < oETCS->aPacket[i_ArrayIndex].k.used );
	}
    return Bitwalker_IncrementalWalker_Peek_Finish (&PeekLocals);
    
    }
// =======================

int TrackToTrain_Packet_071 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_TrackToTrain_Adhesion_Factor oETCS ) 
{  
//    TP_DATA_oETCS_TrackToTrain_Adhesion_Factor oETCS  = (TP_DATA_oETCS_TrackToTrain_Adhesion_Factor)void_oETCS;
    T_Bitwalker_Incremental_Locals PeekLocals;
    Bitwalker_IncrementalWalker_Init(&PeekLocals, p_Telegramm, i_akt_dim, bitindex);

// TransmissionMedia=Any
// Packet Number = 71
	oETCS->aPacket[i_ArrayIndex].NID_PACKET                                  = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 8);
	oETCS->aPacket[i_ArrayIndex].Q_DIR                                       = (T_q_dir) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 2);
	oETCS->aPacket[i_ArrayIndex].L_PACKET                                    = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,13);
	oETCS->aPacket[i_ArrayIndex].Q_SCALE                                     = (T_q_scale) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 2);
	oETCS->aPacket[i_ArrayIndex].D_ADHESION                                  = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,15);
	oETCS->aPacket[i_ArrayIndex].L_ADHESION                                  = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,15);
	oETCS->aPacket[i_ArrayIndex].M_ADHESION                                  = (T_m_adhesion) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 1);
    return Bitwalker_IncrementalWalker_Peek_Finish (&PeekLocals);
    
    }
// =======================

int TrackToTrain_Packet_072 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_TrackToTrain_Packet_for_sending_plain_text_messages oETCS ) 
{  
//    TP_DATA_oETCS_TrackToTrain_Packet_for_sending_plain_text_messages oETCS  = (TP_DATA_oETCS_TrackToTrain_Packet_for_sending_plain_text_messages)void_oETCS;
    T_Bitwalker_Incremental_Locals PeekLocals;
    Bitwalker_IncrementalWalker_Init(&PeekLocals, p_Telegramm, i_akt_dim, bitindex);

// TransmissionMedia=Balise, RBC
// Packet Number = 72
	oETCS->aPacket[i_ArrayIndex].NID_PACKET                                  = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 8);
	oETCS->aPacket[i_ArrayIndex].Q_DIR                                       = (T_q_dir) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 2);
	oETCS->aPacket[i_ArrayIndex].L_PACKET                                    = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,13);
	oETCS->aPacket[i_ArrayIndex].Q_SCALE                                     = (T_q_scale) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 2);
	oETCS->aPacket[i_ArrayIndex].Q_TEXTCLASS                                 = (T_q_textclass) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 2);
	oETCS->aPacket[i_ArrayIndex].Q_TEXTDISPLAY                               = (T_q_textdisplay) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 1);
	oETCS->aPacket[i_ArrayIndex].D_TEXTDISPLAY                               = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,15);
	oETCS->aPacket[i_ArrayIndex].M_MODETEXTDISPLAY0                          = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 4);
	oETCS->aPacket[i_ArrayIndex].M_LEVELTEXTDISPLAY0                         = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 3);
    if ( oETCS->aPacket[i_ArrayIndex].M_LEVELTEXTDISPLAY0 == 1 ) 
    {
	oETCS->aPacket[i_ArrayIndex].NID_NTC0                                    = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 8);
	}
	oETCS->aPacket[i_ArrayIndex].L_TEXTDISPLAY                               = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,15);
	oETCS->aPacket[i_ArrayIndex].T_TEXTDISPLAY                               = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,10);
	oETCS->aPacket[i_ArrayIndex].M_MODETEXTDISPLAY1                          = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 4);
	oETCS->aPacket[i_ArrayIndex].M_LEVELTEXTDISPLAY1                         = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 3);
    if ( oETCS->aPacket[i_ArrayIndex].M_LEVELTEXTDISPLAY1 == 1 ) 
    {
	oETCS->aPacket[i_ArrayIndex].NID_NTC1                                    = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 8);
	}
	oETCS->aPacket[i_ArrayIndex].Q_TEXTCONFIRM                               = (T_q_textconfirm) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 2);
    if ( oETCS->aPacket[i_ArrayIndex].Q_TEXTCONFIRM != 0 ) 
    {
	oETCS->aPacket[i_ArrayIndex].Q_CONFTEXTDISPLAY                           = (T_q_conftextdisplay) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 1);
	oETCS->aPacket[i_ArrayIndex].Q_TEXTREPORT                                = (T_q_textreport) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 1);
	}
    if ( oETCS->aPacket[i_ArrayIndex].Q_TEXTREPORT == 1 ) 
    {
	oETCS->aPacket[i_ArrayIndex].NID_TEXTMESSAGE                             = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 8);
	oETCS->aPacket[i_ArrayIndex].NID_C                                       = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,10);
	oETCS->aPacket[i_ArrayIndex].NID_RBC                                     = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,14);
	}
	oETCS->aPacket[i_ArrayIndex].L_TEXT                                      = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 8);
	oETCS->aPacket[i_ArrayIndex].X_TEXT                                      = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 8);
    return Bitwalker_IncrementalWalker_Peek_Finish (&PeekLocals);
    
    }
// =======================

int TrackToTrain_Packet_076 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_TrackToTrain_Packet_for_sending_fixed_text_messages oETCS ) 
{  
//    TP_DATA_oETCS_TrackToTrain_Packet_for_sending_fixed_text_messages oETCS  = (TP_DATA_oETCS_TrackToTrain_Packet_for_sending_fixed_text_messages)void_oETCS;
    T_Bitwalker_Incremental_Locals PeekLocals;
    Bitwalker_IncrementalWalker_Init(&PeekLocals, p_Telegramm, i_akt_dim, bitindex);

// TransmissionMedia=Balise, RBC
// Packet Number = 76
	oETCS->aPacket[i_ArrayIndex].NID_PACKET                                  = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 8);
	oETCS->aPacket[i_ArrayIndex].Q_DIR                                       = (T_q_dir) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 2);
	oETCS->aPacket[i_ArrayIndex].L_PACKET                                    = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,13);
	oETCS->aPacket[i_ArrayIndex].Q_SCALE                                     = (T_q_scale) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 2);
	oETCS->aPacket[i_ArrayIndex].Q_TEXTCLASS                                 = (T_q_textclass) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 2);
	oETCS->aPacket[i_ArrayIndex].Q_TEXTDISPLAY                               = (T_q_textdisplay) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 1);
	oETCS->aPacket[i_ArrayIndex].D_TEXTDISPLAY                               = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,15);
	oETCS->aPacket[i_ArrayIndex].M_MODETEXTDISPLAY0                          = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 4);
	oETCS->aPacket[i_ArrayIndex].M_LEVELTEXTDISPLAY0                         = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 3);
    if ( oETCS->aPacket[i_ArrayIndex].M_LEVELTEXTDISPLAY0 == 1 ) 
    {
	oETCS->aPacket[i_ArrayIndex].NID_NTC0                                    = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 8);
	}
	oETCS->aPacket[i_ArrayIndex].L_TEXTDISPLAY                               = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,15);
	oETCS->aPacket[i_ArrayIndex].T_TEXTDISPLAY                               = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,10);
	oETCS->aPacket[i_ArrayIndex].M_MODETEXTDISPLAY1                          = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 4);
	oETCS->aPacket[i_ArrayIndex].M_LEVELTEXTDISPLAY1                         = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 3);
    if ( oETCS->aPacket[i_ArrayIndex].M_LEVELTEXTDISPLAY1 == 1 ) 
    {
	oETCS->aPacket[i_ArrayIndex].NID_NTC1                                    = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 8);
	}
	oETCS->aPacket[i_ArrayIndex].Q_TEXTCONFIRM                               = (T_q_textconfirm) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 2);
    if ( oETCS->aPacket[i_ArrayIndex].Q_TEXTCONFIRM != 0 ) 
    {
	oETCS->aPacket[i_ArrayIndex].Q_CONFTEXTDISPLAY                           = (T_q_conftextdisplay) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 1);
	oETCS->aPacket[i_ArrayIndex].Q_TEXTREPORT                                = (T_q_textreport) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 1);
	}
    if ( oETCS->aPacket[i_ArrayIndex].Q_TEXTREPORT == 1 ) 
    {
	oETCS->aPacket[i_ArrayIndex].NID_TEXTMESSAGE                             = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 8);
	oETCS->aPacket[i_ArrayIndex].NID_C                                       = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,10);
	oETCS->aPacket[i_ArrayIndex].NID_RBC                                     = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,14);
	}
	oETCS->aPacket[i_ArrayIndex].Q_TEXT                                      = (T_q_text) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 8);
    return Bitwalker_IncrementalWalker_Peek_Finish (&PeekLocals);
    
    }
// =======================

int TrackToTrain_Packet_079 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_TrackToTrain_Geographical_Position_Information oETCS ) 
{  
//    TP_DATA_oETCS_TrackToTrain_Geographical_Position_Information oETCS  = (TP_DATA_oETCS_TrackToTrain_Geographical_Position_Information)void_oETCS;
    T_Bitwalker_Incremental_Locals PeekLocals;
    Bitwalker_IncrementalWalker_Init(&PeekLocals, p_Telegramm, i_akt_dim, bitindex);

// TransmissionMedia=Balise, RBC
// Packet Number = 79
	oETCS->aPacket[i_ArrayIndex].NID_PACKET                                  = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 8);
	oETCS->aPacket[i_ArrayIndex].Q_DIR                                       = (T_q_dir) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 2);
	oETCS->aPacket[i_ArrayIndex].L_PACKET                                    = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,13);
	oETCS->aPacket[i_ArrayIndex].Q_SCALE                                     = (T_q_scale) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 2);
	oETCS->aPacket[i_ArrayIndex].Q_NEWCOUNTRY                                = (T_q_newcountry) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 1);
    if ( oETCS->aPacket[i_ArrayIndex].Q_NEWCOUNTRY == 1 ) 
    {
	oETCS->aPacket[i_ArrayIndex].NID_C                                       = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,10);
	}
	oETCS->aPacket[i_ArrayIndex].NID_BG                                      = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,14);
	oETCS->aPacket[i_ArrayIndex].D_POSOFF                                    = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,15);
	oETCS->aPacket[i_ArrayIndex].Q_MPOSITION                                 = (T_q_mposition) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 1);
	oETCS->aPacket[i_ArrayIndex].M_POSITION                                  = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,24);
    uint32_t j = 0;
    do 
    {
        if ( j == 0 ) {
             oETCS->aPacket[i_ArrayIndex].k.used                = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 5) + 1;
        }
		oETCS->aPacket[i_ArrayIndex].k.a_data[j].Q_NEWCOUNTRY                    = (T_q_newcountry) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 1);
    if ( oETCS->aPacket[i_ArrayIndex].k.a_data[j].Q_NEWCOUNTRY == 1 ) 
    {
		oETCS->aPacket[i_ArrayIndex].k.a_data[j].NID_C                           = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,10);
	}
		oETCS->aPacket[i_ArrayIndex].k.a_data[j].NID_BG                          = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,14);
		oETCS->aPacket[i_ArrayIndex].k.a_data[j].D_POSOFF                        = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,15);
		oETCS->aPacket[i_ArrayIndex].k.a_data[j].Q_MPOSITION                     = (T_q_mposition) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 1);
		oETCS->aPacket[i_ArrayIndex].k.a_data[j].M_POSITION                      = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,24);
    } while ( ++j < oETCS->aPacket[i_ArrayIndex].k.used );
    return Bitwalker_IncrementalWalker_Peek_Finish (&PeekLocals);
    
    }
// =======================

int TrackToTrain_Packet_080 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_TrackToTrain_Mode_profile oETCS ) 
{  
//    TP_DATA_oETCS_TrackToTrain_Mode_profile oETCS  = (TP_DATA_oETCS_TrackToTrain_Mode_profile)void_oETCS;
    T_Bitwalker_Incremental_Locals PeekLocals;
    Bitwalker_IncrementalWalker_Init(&PeekLocals, p_Telegramm, i_akt_dim, bitindex);

// TransmissionMedia=Any
// Packet Number = 80
	oETCS->aPacket[i_ArrayIndex].NID_PACKET                                  = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 8);
	oETCS->aPacket[i_ArrayIndex].Q_DIR                                       = (T_q_dir) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 2);
	oETCS->aPacket[i_ArrayIndex].L_PACKET                                    = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,13);
	oETCS->aPacket[i_ArrayIndex].Q_SCALE                                     = (T_q_scale) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 2);
	oETCS->aPacket[i_ArrayIndex].D_MAMODE                                    = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,15);
	oETCS->aPacket[i_ArrayIndex].M_MAMODE                                    = (T_m_mamode) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 2);
	oETCS->aPacket[i_ArrayIndex].V_MAMODE                                    = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 7);
	oETCS->aPacket[i_ArrayIndex].L_MAMODE                                    = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,15);
	oETCS->aPacket[i_ArrayIndex].L_ACKMAMODE                                 = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,15);
	oETCS->aPacket[i_ArrayIndex].Q_MAMODE                                    = (T_q_mamode) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 1);
    uint32_t j = 0;
    do 
    {
        if ( j == 0 ) {
             oETCS->aPacket[i_ArrayIndex].k.used                = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 5) + 1;
        }
		oETCS->aPacket[i_ArrayIndex].k.a_data[j].D_MAMODE                        = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,15);
		oETCS->aPacket[i_ArrayIndex].k.a_data[j].M_MAMODE                        = (T_m_mamode) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 2);
		oETCS->aPacket[i_ArrayIndex].k.a_data[j].V_MAMODE                        = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 7);
		oETCS->aPacket[i_ArrayIndex].k.a_data[j].L_MAMODE                        = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,15);
		oETCS->aPacket[i_ArrayIndex].k.a_data[j].L_ACKMAMODE                     = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,15);
		oETCS->aPacket[i_ArrayIndex].k.a_data[j].Q_MAMODE                        = (T_q_mamode) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 1);
    } while ( ++j < oETCS->aPacket[i_ArrayIndex].k.used );
    return Bitwalker_IncrementalWalker_Peek_Finish (&PeekLocals);
    
    }
// =======================

int TrackToTrain_Packet_088 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_TrackToTrain_Level_Crossing_information oETCS ) 
{  
//    TP_DATA_oETCS_TrackToTrain_Level_Crossing_information oETCS  = (TP_DATA_oETCS_TrackToTrain_Level_Crossing_information)void_oETCS;
    T_Bitwalker_Incremental_Locals PeekLocals;
    Bitwalker_IncrementalWalker_Init(&PeekLocals, p_Telegramm, i_akt_dim, bitindex);

// TransmissionMedia=Any
// Packet Number = 88
	oETCS->aPacket[i_ArrayIndex].NID_PACKET                                  = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 8);
	oETCS->aPacket[i_ArrayIndex].Q_DIR                                       = (T_q_dir) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 2);
	oETCS->aPacket[i_ArrayIndex].L_PACKET                                    = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,13);
	oETCS->aPacket[i_ArrayIndex].Q_SCALE                                     = (T_q_scale) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 2);
	oETCS->aPacket[i_ArrayIndex].NID_LX                                      = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 8);
	oETCS->aPacket[i_ArrayIndex].D_LX                                        = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,15);
	oETCS->aPacket[i_ArrayIndex].L_LX                                        = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,15);
	oETCS->aPacket[i_ArrayIndex].Q_LXSTATUS                                  = (T_q_lxstatus) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 1);
    if ( oETCS->aPacket[i_ArrayIndex].Q_LXSTATUS == 1 ) 
    {
	oETCS->aPacket[i_ArrayIndex].V_LX                                        = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 7);
	oETCS->aPacket[i_ArrayIndex].Q_STOPLX                                    = (T_q_stoplx) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 1);
	}
    if ( oETCS->aPacket[i_ArrayIndex].Q_STOPLX == 1 ) 
    {
	oETCS->aPacket[i_ArrayIndex].L_STOPLX                                    = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,15);
	}
    return Bitwalker_IncrementalWalker_Peek_Finish (&PeekLocals);
    
    }
// =======================

int TrackToTrain_Packet_090 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_TrackToTrain_Track_Ahead_Free_up_to_level_23_transition_location oETCS ) 
{  
//    TP_DATA_oETCS_TrackToTrain_Track_Ahead_Free_up_to_level_23_transition_location oETCS  = (TP_DATA_oETCS_TrackToTrain_Track_Ahead_Free_up_to_level_23_transition_location)void_oETCS;
    T_Bitwalker_Incremental_Locals PeekLocals;
    Bitwalker_IncrementalWalker_Init(&PeekLocals, p_Telegramm, i_akt_dim, bitindex);

// TransmissionMedia=Balise
// Packet Number = 90
	oETCS->aPacket[i_ArrayIndex].NID_PACKET                                  = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 8);
	oETCS->aPacket[i_ArrayIndex].Q_DIR                                       = (T_q_dir) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 2);
	oETCS->aPacket[i_ArrayIndex].L_PACKET                                    = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,13);
	oETCS->aPacket[i_ArrayIndex].Q_NEWCOUNTRY                                = (T_q_newcountry) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 1);
    if ( oETCS->aPacket[i_ArrayIndex].Q_NEWCOUNTRY == 1 ) 
    {
	oETCS->aPacket[i_ArrayIndex].NID_C                                       = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,10);
	}
	oETCS->aPacket[i_ArrayIndex].NID_BG                                      = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,14);
    return Bitwalker_IncrementalWalker_Peek_Finish (&PeekLocals);
    
    }
// =======================

int TrackToTrain_Packet_131 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_TrackToTrain_RBC_transition_order oETCS ) 
{  
//    TP_DATA_oETCS_TrackToTrain_RBC_transition_order oETCS  = (TP_DATA_oETCS_TrackToTrain_RBC_transition_order)void_oETCS;
    T_Bitwalker_Incremental_Locals PeekLocals;
    Bitwalker_IncrementalWalker_Init(&PeekLocals, p_Telegramm, i_akt_dim, bitindex);

// TransmissionMedia=Balise, RBC
// Packet Number = 131
	oETCS->aPacket[i_ArrayIndex].NID_PACKET                                  = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 8);
	oETCS->aPacket[i_ArrayIndex].Q_DIR                                       = (T_q_dir) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 2);
	oETCS->aPacket[i_ArrayIndex].L_PACKET                                    = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,13);
	oETCS->aPacket[i_ArrayIndex].Q_SCALE                                     = (T_q_scale) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 2);
	oETCS->aPacket[i_ArrayIndex].D_RBCTR                                     = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,15);
	oETCS->aPacket[i_ArrayIndex].NID_C                                       = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,10);
	oETCS->aPacket[i_ArrayIndex].NID_RBC                                     = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,14);
	oETCS->aPacket[i_ArrayIndex].NID_RADIO                                   = Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,64);
	oETCS->aPacket[i_ArrayIndex].Q_SLEEPSESSION                              = (T_q_sleepsession) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 1);
    return Bitwalker_IncrementalWalker_Peek_Finish (&PeekLocals);
    
    }
// =======================

int TrackToTrain_Packet_132 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_TrackToTrain_Danger_for_Shunting_information oETCS ) 
{  
//    TP_DATA_oETCS_TrackToTrain_Danger_for_Shunting_information oETCS  = (TP_DATA_oETCS_TrackToTrain_Danger_for_Shunting_information)void_oETCS;
    T_Bitwalker_Incremental_Locals PeekLocals;
    Bitwalker_IncrementalWalker_Init(&PeekLocals, p_Telegramm, i_akt_dim, bitindex);

// TransmissionMedia=Balise
// Packet Number = 132
	oETCS->aPacket[i_ArrayIndex].NID_PACKET                                  = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 8);
	oETCS->aPacket[i_ArrayIndex].Q_DIR                                       = (T_q_dir) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 2);
	oETCS->aPacket[i_ArrayIndex].L_PACKET                                    = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,13);
	oETCS->aPacket[i_ArrayIndex].Q_ASPECT                                    = (T_q_aspect) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 1);
    return Bitwalker_IncrementalWalker_Peek_Finish (&PeekLocals);
    
    }
// =======================

int TrackToTrain_Packet_133 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_TrackToTrain_Radio_infill_area_information oETCS ) 
{  
//    TP_DATA_oETCS_TrackToTrain_Radio_infill_area_information oETCS  = (TP_DATA_oETCS_TrackToTrain_Radio_infill_area_information)void_oETCS;
    T_Bitwalker_Incremental_Locals PeekLocals;
    Bitwalker_IncrementalWalker_Init(&PeekLocals, p_Telegramm, i_akt_dim, bitindex);

// TransmissionMedia=Balise
// Packet Number = 133
	oETCS->aPacket[i_ArrayIndex].NID_PACKET                                  = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 8);
	oETCS->aPacket[i_ArrayIndex].Q_DIR                                       = (T_q_dir) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 2);
	oETCS->aPacket[i_ArrayIndex].L_PACKET                                    = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,13);
	oETCS->aPacket[i_ArrayIndex].Q_SCALE                                     = (T_q_scale) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 2);
	oETCS->aPacket[i_ArrayIndex].Q_RIU                                       = (T_q_riu) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 1);
	oETCS->aPacket[i_ArrayIndex].NID_C                                       = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,10);
	oETCS->aPacket[i_ArrayIndex].NID_RIU                                     = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,14);
	oETCS->aPacket[i_ArrayIndex].NID_RADIO                                   = Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,64);
	oETCS->aPacket[i_ArrayIndex].D_INFILL                                    = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,15);
	oETCS->aPacket[i_ArrayIndex].NID_BG                                      = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,14);
    return Bitwalker_IncrementalWalker_Peek_Finish (&PeekLocals);
    
    }
// =======================

int TrackToTrain_Packet_134 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_TrackToTrain_EOLM_Packet oETCS ) 
{  
//    TP_DATA_oETCS_TrackToTrain_EOLM_Packet oETCS  = (TP_DATA_oETCS_TrackToTrain_EOLM_Packet)void_oETCS;
    T_Bitwalker_Incremental_Locals PeekLocals;
    Bitwalker_IncrementalWalker_Init(&PeekLocals, p_Telegramm, i_akt_dim, bitindex);

// TransmissionMedia=Balise
// Packet Number = 134
	oETCS->aPacket[i_ArrayIndex].NID_PACKET                                  = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 8);
	oETCS->aPacket[i_ArrayIndex].Q_DIR                                       = (T_q_dir) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 2);
	oETCS->aPacket[i_ArrayIndex].L_PACKET                                    = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,13);
	oETCS->aPacket[i_ArrayIndex].Q_SCALE                                     = (T_q_scale) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 2);
	oETCS->aPacket[i_ArrayIndex].NID_LOOP                                    = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,14);
	oETCS->aPacket[i_ArrayIndex].D_LOOP                                      = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,15);
	oETCS->aPacket[i_ArrayIndex].L_LOOP                                      = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,15);
	oETCS->aPacket[i_ArrayIndex].Q_LOOPDIR                                   = (T_q_loopdir) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 1);
	oETCS->aPacket[i_ArrayIndex].Q_SSCODE                                    = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 4);
    return Bitwalker_IncrementalWalker_Peek_Finish (&PeekLocals);
    
    }
// =======================

int TrackToTrain_Packet_135 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_TrackToTrain_Stop_Shunting_on_desk_opening oETCS ) 
{  
//    TP_DATA_oETCS_TrackToTrain_Stop_Shunting_on_desk_opening oETCS  = (TP_DATA_oETCS_TrackToTrain_Stop_Shunting_on_desk_opening)void_oETCS;
    T_Bitwalker_Incremental_Locals PeekLocals;
    Bitwalker_IncrementalWalker_Init(&PeekLocals, p_Telegramm, i_akt_dim, bitindex);

// TransmissionMedia=Balise
// Packet Number = 135
	oETCS->aPacket[i_ArrayIndex].NID_PACKET                                  = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 8);
	oETCS->aPacket[i_ArrayIndex].Q_DIR                                       = (T_q_dir) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 2);
	oETCS->aPacket[i_ArrayIndex].L_PACKET                                    = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,13);
    return Bitwalker_IncrementalWalker_Peek_Finish (&PeekLocals);
    
    }
// =======================

int TrackToTrain_Packet_136 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_TrackToTrain_Infill_location_reference oETCS ) 
{  
//    TP_DATA_oETCS_TrackToTrain_Infill_location_reference oETCS  = (TP_DATA_oETCS_TrackToTrain_Infill_location_reference)void_oETCS;
    T_Bitwalker_Incremental_Locals PeekLocals;
    Bitwalker_IncrementalWalker_Init(&PeekLocals, p_Telegramm, i_akt_dim, bitindex);

// TransmissionMedia=Balise, Loop, RIU
// Packet Number = 136
	oETCS->aPacket[i_ArrayIndex].NID_PACKET                                  = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 8);
	oETCS->aPacket[i_ArrayIndex].Q_DIR                                       = (T_q_dir) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 2);
	oETCS->aPacket[i_ArrayIndex].L_PACKET                                    = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,13);
	oETCS->aPacket[i_ArrayIndex].Q_NEWCOUNTRY                                = (T_q_newcountry) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 1);
    if ( oETCS->aPacket[i_ArrayIndex].Q_NEWCOUNTRY == 1 ) 
    {
	oETCS->aPacket[i_ArrayIndex].NID_C                                       = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,10);
	}
	oETCS->aPacket[i_ArrayIndex].NID_BG                                      = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,14);
    return Bitwalker_IncrementalWalker_Peek_Finish (&PeekLocals);
    
    }
// =======================

int TrackToTrain_Packet_137 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_TrackToTrain_Stop_if_in_Staff_Responsible oETCS ) 
{  
//    TP_DATA_oETCS_TrackToTrain_Stop_if_in_Staff_Responsible oETCS  = (TP_DATA_oETCS_TrackToTrain_Stop_if_in_Staff_Responsible)void_oETCS;
    T_Bitwalker_Incremental_Locals PeekLocals;
    Bitwalker_IncrementalWalker_Init(&PeekLocals, p_Telegramm, i_akt_dim, bitindex);

// TransmissionMedia=Balise
// Packet Number = 137
	oETCS->aPacket[i_ArrayIndex].NID_PACKET                                  = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 8);
	oETCS->aPacket[i_ArrayIndex].Q_DIR                                       = (T_q_dir) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 2);
	oETCS->aPacket[i_ArrayIndex].L_PACKET                                    = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,13);
	oETCS->aPacket[i_ArrayIndex].Q_SRSTOP                                    = (T_q_srstop) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 1);
    return Bitwalker_IncrementalWalker_Peek_Finish (&PeekLocals);
    
    }
// =======================

int TrackToTrain_Packet_138 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_TrackToTrain_Reversing_area_information oETCS ) 
{  
//    TP_DATA_oETCS_TrackToTrain_Reversing_area_information oETCS  = (TP_DATA_oETCS_TrackToTrain_Reversing_area_information)void_oETCS;
    T_Bitwalker_Incremental_Locals PeekLocals;
    Bitwalker_IncrementalWalker_Init(&PeekLocals, p_Telegramm, i_akt_dim, bitindex);

// TransmissionMedia=Any
// Packet Number = 138
	oETCS->aPacket[i_ArrayIndex].NID_PACKET                                  = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 8);
	oETCS->aPacket[i_ArrayIndex].Q_DIR                                       = (T_q_dir) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 2);
	oETCS->aPacket[i_ArrayIndex].L_PACKET                                    = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,13);
	oETCS->aPacket[i_ArrayIndex].Q_SCALE                                     = (T_q_scale) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 2);
	oETCS->aPacket[i_ArrayIndex].D_STARTREVERSE                              = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,15);
	oETCS->aPacket[i_ArrayIndex].L_REVERSEAREA                               = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,15);
    return Bitwalker_IncrementalWalker_Peek_Finish (&PeekLocals);
    
    }
// =======================

int TrackToTrain_Packet_139 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_TrackToTrain_Reversing_supervision_information oETCS ) 
{  
//    TP_DATA_oETCS_TrackToTrain_Reversing_supervision_information oETCS  = (TP_DATA_oETCS_TrackToTrain_Reversing_supervision_information)void_oETCS;
    T_Bitwalker_Incremental_Locals PeekLocals;
    Bitwalker_IncrementalWalker_Init(&PeekLocals, p_Telegramm, i_akt_dim, bitindex);

// TransmissionMedia=Any
// Packet Number = 139
	oETCS->aPacket[i_ArrayIndex].NID_PACKET                                  = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 8);
	oETCS->aPacket[i_ArrayIndex].Q_DIR                                       = (T_q_dir) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 2);
	oETCS->aPacket[i_ArrayIndex].L_PACKET                                    = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,13);
	oETCS->aPacket[i_ArrayIndex].Q_SCALE                                     = (T_q_scale) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 2);
	oETCS->aPacket[i_ArrayIndex].D_REVERSE                                   = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,15);
	oETCS->aPacket[i_ArrayIndex].V_REVERSE                                   = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 7);
    return Bitwalker_IncrementalWalker_Peek_Finish (&PeekLocals);
    
    }
// =======================

int TrackToTrain_Packet_140 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_TrackToTrain_Train_running_number_from_RBC oETCS ) 
{  
//    TP_DATA_oETCS_TrackToTrain_Train_running_number_from_RBC oETCS  = (TP_DATA_oETCS_TrackToTrain_Train_running_number_from_RBC)void_oETCS;
    T_Bitwalker_Incremental_Locals PeekLocals;
    Bitwalker_IncrementalWalker_Init(&PeekLocals, p_Telegramm, i_akt_dim, bitindex);

// TransmissionMedia=RBC
// Packet Number = 140
	oETCS->aPacket[i_ArrayIndex].NID_PACKET                                  = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 8);
	oETCS->aPacket[i_ArrayIndex].Q_DIR                                       = (T_q_dir) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 2);
	oETCS->aPacket[i_ArrayIndex].L_PACKET                                    = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,13);
	oETCS->aPacket[i_ArrayIndex].NID_OPERATIONAL                             = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,32);
    return Bitwalker_IncrementalWalker_Peek_Finish (&PeekLocals);
    
    }
// =======================

int TrackToTrain_Packet_141 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_TrackToTrain_Default_Gradient_for_Temporary_Speed_Restriction oETCS ) 
{  
//    TP_DATA_oETCS_TrackToTrain_Default_Gradient_for_Temporary_Speed_Restriction oETCS  = (TP_DATA_oETCS_TrackToTrain_Default_Gradient_for_Temporary_Speed_Restriction)void_oETCS;
    T_Bitwalker_Incremental_Locals PeekLocals;
    Bitwalker_IncrementalWalker_Init(&PeekLocals, p_Telegramm, i_akt_dim, bitindex);

// TransmissionMedia=Balise
// Packet Number = 141
	oETCS->aPacket[i_ArrayIndex].NID_PACKET                                  = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 8);
	oETCS->aPacket[i_ArrayIndex].Q_DIR                                       = (T_q_dir) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 2);
	oETCS->aPacket[i_ArrayIndex].L_PACKET                                    = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,13);
	oETCS->aPacket[i_ArrayIndex].Q_GDIR                                      = (T_q_gdir) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 1);
	oETCS->aPacket[i_ArrayIndex].G_TSR                                       = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 8);
    return Bitwalker_IncrementalWalker_Peek_Finish (&PeekLocals);
    
    }
// =======================

int TrackToTrain_Packet_143 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_TrackToTrain_Session_Management_with_neighbouring_Radio_Infill_Unit oETCS ) 
{  
//    TP_DATA_oETCS_TrackToTrain_Session_Management_with_neighbouring_Radio_Infill_Unit oETCS  = (TP_DATA_oETCS_TrackToTrain_Session_Management_with_neighbouring_Radio_Infill_Unit)void_oETCS;
    T_Bitwalker_Incremental_Locals PeekLocals;
    Bitwalker_IncrementalWalker_Init(&PeekLocals, p_Telegramm, i_akt_dim, bitindex);

// TransmissionMedia=RIU
// Packet Number = 143
	oETCS->aPacket[i_ArrayIndex].NID_PACKET                                  = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 8);
	oETCS->aPacket[i_ArrayIndex].Q_DIR                                       = (T_q_dir) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 2);
	oETCS->aPacket[i_ArrayIndex].L_PACKET                                    = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,13);
	oETCS->aPacket[i_ArrayIndex].Q_RIU                                       = (T_q_riu) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 1);
	oETCS->aPacket[i_ArrayIndex].NID_C                                       = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,10);
	oETCS->aPacket[i_ArrayIndex].NID_RIU                                     = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,14);
	oETCS->aPacket[i_ArrayIndex].NID_RADIO                                   = Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,64);
    return Bitwalker_IncrementalWalker_Peek_Finish (&PeekLocals);
    
    }
// =======================

int TrackToTrain_Packet_145 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_TrackToTrain_Inhibition_of_balise_group_message_consistency_reaction oETCS ) 
{  
//    TP_DATA_oETCS_TrackToTrain_Inhibition_of_balise_group_message_consistency_reaction oETCS  = (TP_DATA_oETCS_TrackToTrain_Inhibition_of_balise_group_message_consistency_reaction)void_oETCS;
    T_Bitwalker_Incremental_Locals PeekLocals;
    Bitwalker_IncrementalWalker_Init(&PeekLocals, p_Telegramm, i_akt_dim, bitindex);

// TransmissionMedia=Balise
// Packet Number = 145
	oETCS->aPacket[i_ArrayIndex].NID_PACKET                                  = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 8);
	oETCS->aPacket[i_ArrayIndex].Q_DIR                                       = (T_q_dir) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 2);
	oETCS->aPacket[i_ArrayIndex].L_PACKET                                    = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,13);
    return Bitwalker_IncrementalWalker_Peek_Finish (&PeekLocals);
    
    }
// =======================

int TrackToTrain_Packet_254 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_TrackToTrain_Default_balise_or_Loop_or_RIU_information oETCS ) 
{  
//    TP_DATA_oETCS_TrackToTrain_Default_balise_or_Loop_or_RIU_information oETCS  = (TP_DATA_oETCS_TrackToTrain_Default_balise_or_Loop_or_RIU_information)void_oETCS;
    T_Bitwalker_Incremental_Locals PeekLocals;
    Bitwalker_IncrementalWalker_Init(&PeekLocals, p_Telegramm, i_akt_dim, bitindex);

// TransmissionMedia=Balise, Loop, RIU
// Packet Number = 254
	oETCS->aPacket[i_ArrayIndex].NID_PACKET                                  = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 8);
	oETCS->aPacket[i_ArrayIndex].Q_DIR                                       = (T_q_dir) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 2);
	oETCS->aPacket[i_ArrayIndex].L_PACKET                                    = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,13);
    return Bitwalker_IncrementalWalker_Peek_Finish (&PeekLocals);
    
    }
// =======================

//Namespace TrackToTrain ends here

//Namespace TrainToTrack starts here

int TrainToTrack_Packet_000 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_TrainToTrack_Position_Report oETCS ) 
{  
//    TP_DATA_oETCS_TrainToTrack_Position_Report oETCS  = (TP_DATA_oETCS_TrainToTrack_Position_Report)void_oETCS;
    T_Bitwalker_Incremental_Locals PeekLocals;
    Bitwalker_IncrementalWalker_Init(&PeekLocals, p_Telegramm, i_akt_dim, bitindex);

// TransmissionMedia=RBC, RIU
// Packet Number = 0
	oETCS->aPacket[i_ArrayIndex].NID_PACKET                                  = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 8);
	oETCS->aPacket[i_ArrayIndex].L_PACKET                                    = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,13);
	oETCS->aPacket[i_ArrayIndex].Q_SCALE                                     = (T_q_scale) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 2);
	oETCS->aPacket[i_ArrayIndex].NID_LRBG                                    = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,24);
	oETCS->aPacket[i_ArrayIndex].D_LRBG                                      = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,15);
	oETCS->aPacket[i_ArrayIndex].Q_DIRLRBG                                   = (T_q_dirlrbg) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 2);
	oETCS->aPacket[i_ArrayIndex].Q_DLRBG                                     = (T_q_dlrbg) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 2);
	oETCS->aPacket[i_ArrayIndex].L_DOUBTOVER                                 = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,15);
	oETCS->aPacket[i_ArrayIndex].L_DOUBTUNDER                                = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,15);
	oETCS->aPacket[i_ArrayIndex].Q_LENGTH                                    = (T_q_length) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 2);
    if (( oETCS->aPacket[i_ArrayIndex].Q_LENGTH == 1 )  || ( oETCS->aPacket[i_ArrayIndex].Q_LENGTH == 2 ))  
    {
	oETCS->aPacket[i_ArrayIndex].L_TRAININT                                  = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,15);
	}
	oETCS->aPacket[i_ArrayIndex].V_TRAIN                                     = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 7);
	oETCS->aPacket[i_ArrayIndex].Q_DIRTRAIN                                  = (T_q_dirtrain) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 2);
	oETCS->aPacket[i_ArrayIndex].M_MODE                                      = (T_m_mode) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 4);
	oETCS->aPacket[i_ArrayIndex].M_LEVEL                                     = (T_m_level) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 3);
    if ( oETCS->aPacket[i_ArrayIndex].M_LEVEL == 1 ) 
    {
	oETCS->aPacket[i_ArrayIndex].NID_NTC                                     = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 8);
	}
    return Bitwalker_IncrementalWalker_Peek_Finish (&PeekLocals);
    
    }
// =======================

int TrainToTrack_Packet_001 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_TrainToTrack_Position_Report_based_on_two_balise_groups oETCS ) 
{  
//    TP_DATA_oETCS_TrainToTrack_Position_Report_based_on_two_balise_groups oETCS  = (TP_DATA_oETCS_TrainToTrack_Position_Report_based_on_two_balise_groups)void_oETCS;
    T_Bitwalker_Incremental_Locals PeekLocals;
    Bitwalker_IncrementalWalker_Init(&PeekLocals, p_Telegramm, i_akt_dim, bitindex);

// TransmissionMedia=RBC, RIU
// Packet Number = 1
	oETCS->aPacket[i_ArrayIndex].NID_PACKET                                  = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 8);
	oETCS->aPacket[i_ArrayIndex].L_PACKET                                    = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,13);
	oETCS->aPacket[i_ArrayIndex].Q_SCALE                                     = (T_q_scale) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 2);
	oETCS->aPacket[i_ArrayIndex].NID_LRBG                                    = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,24);
	oETCS->aPacket[i_ArrayIndex].NID_PRVLRBG                                 = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,24);
	oETCS->aPacket[i_ArrayIndex].D_LRBG                                      = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,15);
	oETCS->aPacket[i_ArrayIndex].Q_DIRLRBG                                   = (T_q_dirlrbg) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 2);
	oETCS->aPacket[i_ArrayIndex].Q_DLRBG                                     = (T_q_dlrbg) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 2);
	oETCS->aPacket[i_ArrayIndex].L_DOUBTOVER                                 = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,15);
	oETCS->aPacket[i_ArrayIndex].L_DOUBTUNDER                                = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,15);
	oETCS->aPacket[i_ArrayIndex].Q_LENGTH                                    = (T_q_length) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 2);
    if (( oETCS->aPacket[i_ArrayIndex].Q_LENGTH == 1 )  || ( oETCS->aPacket[i_ArrayIndex].Q_LENGTH == 2 ))  
    {
	oETCS->aPacket[i_ArrayIndex].L_TRAININT                                  = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,15);
	}
	oETCS->aPacket[i_ArrayIndex].V_TRAIN                                     = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 7);
	oETCS->aPacket[i_ArrayIndex].Q_DIRTRAIN                                  = (T_q_dirtrain) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 2);
	oETCS->aPacket[i_ArrayIndex].M_MODE                                      = (T_m_mode) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 4);
	oETCS->aPacket[i_ArrayIndex].M_LEVEL                                     = (T_m_level) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 3);
    if ( oETCS->aPacket[i_ArrayIndex].M_LEVEL == 1 ) 
    {
	oETCS->aPacket[i_ArrayIndex].NID_NTC                                     = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 8);
	}
    return Bitwalker_IncrementalWalker_Peek_Finish (&PeekLocals);
    
    }
// =======================

int TrainToTrack_Packet_003 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_TrainToTrack_Onboard_telephone_numbers oETCS ) 
{  
//    TP_DATA_oETCS_TrainToTrack_Onboard_telephone_numbers oETCS  = (TP_DATA_oETCS_TrainToTrack_Onboard_telephone_numbers)void_oETCS;
    T_Bitwalker_Incremental_Locals PeekLocals;
    Bitwalker_IncrementalWalker_Init(&PeekLocals, p_Telegramm, i_akt_dim, bitindex);

// TransmissionMedia=RBC, RIU
// Packet Number = 3
	oETCS->aPacket[i_ArrayIndex].NID_PACKET                                  = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 8);
	oETCS->aPacket[i_ArrayIndex].L_PACKET                                    = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,13);
    uint32_t j = 0;
    do 
    {
        if ( j == 0 ) {
             oETCS->aPacket[i_ArrayIndex].k.used                = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 5) + 1;
        }
		oETCS->aPacket[i_ArrayIndex].k.a_data[j].NID_RADIO                       = Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,64);
    } while ( ++j < oETCS->aPacket[i_ArrayIndex].k.used );
    return Bitwalker_IncrementalWalker_Peek_Finish (&PeekLocals);
    
    }
// =======================

int TrainToTrack_Packet_004 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_TrainToTrack_Error_Reporting oETCS ) 
{  
//    TP_DATA_oETCS_TrainToTrack_Error_Reporting oETCS  = (TP_DATA_oETCS_TrainToTrack_Error_Reporting)void_oETCS;
    T_Bitwalker_Incremental_Locals PeekLocals;
    Bitwalker_IncrementalWalker_Init(&PeekLocals, p_Telegramm, i_akt_dim, bitindex);

// TransmissionMedia=RBC
// Packet Number = 4
	oETCS->aPacket[i_ArrayIndex].NID_PACKET                                  = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 8);
	oETCS->aPacket[i_ArrayIndex].L_PACKET                                    = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,13);
	oETCS->aPacket[i_ArrayIndex].M_ERROR                                     = (T_m_error) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 8);
    return Bitwalker_IncrementalWalker_Peek_Finish (&PeekLocals);
    
    }
// =======================

int TrainToTrack_Packet_005 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_TrainToTrack_Train_running_number oETCS ) 
{  
//    TP_DATA_oETCS_TrainToTrack_Train_running_number oETCS  = (TP_DATA_oETCS_TrainToTrack_Train_running_number)void_oETCS;
    T_Bitwalker_Incremental_Locals PeekLocals;
    Bitwalker_IncrementalWalker_Init(&PeekLocals, p_Telegramm, i_akt_dim, bitindex);

// TransmissionMedia=RBC
// Packet Number = 5
	oETCS->aPacket[i_ArrayIndex].NID_PACKET                                  = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 8);
	oETCS->aPacket[i_ArrayIndex].L_PACKET                                    = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,13);
	oETCS->aPacket[i_ArrayIndex].NID_OPERATIONAL                             = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,32);
    return Bitwalker_IncrementalWalker_Peek_Finish (&PeekLocals);
    
    }
// =======================

int TrainToTrack_Packet_009 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_TrainToTrack_Level_23_transition_information oETCS ) 
{  
//    TP_DATA_oETCS_TrainToTrack_Level_23_transition_information oETCS  = (TP_DATA_oETCS_TrainToTrack_Level_23_transition_information)void_oETCS;
    T_Bitwalker_Incremental_Locals PeekLocals;
    Bitwalker_IncrementalWalker_Init(&PeekLocals, p_Telegramm, i_akt_dim, bitindex);

// TransmissionMedia=RBC
// Packet Number = 9
	oETCS->aPacket[i_ArrayIndex].NID_PACKET                                  = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 8);
	oETCS->aPacket[i_ArrayIndex].L_PACKET                                    = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,13);
	oETCS->aPacket[i_ArrayIndex].NID_LTRBG                                   = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,24);
    return Bitwalker_IncrementalWalker_Peek_Finish (&PeekLocals);
    
    }
// =======================

int TrainToTrack_Packet_011 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_TrainToTrack_Validated_train_data oETCS ) 
{  
//    TP_DATA_oETCS_TrainToTrack_Validated_train_data oETCS  = (TP_DATA_oETCS_TrainToTrack_Validated_train_data)void_oETCS;
    T_Bitwalker_Incremental_Locals PeekLocals;
    Bitwalker_IncrementalWalker_Init(&PeekLocals, p_Telegramm, i_akt_dim, bitindex);

// TransmissionMedia=RBC
// Packet Number = 11
	oETCS->aPacket[i_ArrayIndex].NID_PACKET                                  = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 8);
	oETCS->aPacket[i_ArrayIndex].L_PACKET                                    = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,13);
	oETCS->aPacket[i_ArrayIndex].NC_CDTRAIN                                  = (T_nc_cdtrain) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 4);
	oETCS->aPacket[i_ArrayIndex].NC_TRAIN                                    = (T_nc_train) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,15);
	oETCS->aPacket[i_ArrayIndex].L_TRAIN                                     = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,12);
	oETCS->aPacket[i_ArrayIndex].V_MAXTRAIN                                  = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 7);
	oETCS->aPacket[i_ArrayIndex].M_LOADINGGAUGE                              = (T_m_loadinggauge) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 8);
	oETCS->aPacket[i_ArrayIndex].M_AXLELOADCAT                               = (T_m_axleloadcat) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 7);
	oETCS->aPacket[i_ArrayIndex].M_AIRTIGHT                                  = (T_m_airtight) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 2);
	oETCS->aPacket[i_ArrayIndex].N_AXLE                                      = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,10);
    uint32_t j = 0;
    do 
    {
        if ( j == 0 ) {
             oETCS->aPacket[i_ArrayIndex].k.used                = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 5) + 1;
        }
		oETCS->aPacket[i_ArrayIndex].k.a_data[j].M_VOLTAGE                       = (T_m_voltage) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 4);
    if (( oETCS->aPacket[i_ArrayIndex].k.a_data[j].M_VOLTAGE != 0 )  && ( oETCS->aPacket[i_ArrayIndex].k.a_data[j].NID_CTRACTION != 0 ))  
    {
		oETCS->aPacket[i_ArrayIndex].k.a_data[j].NID_CTRACTION                   = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,10);
	}
    } while ( ++j < oETCS->aPacket[i_ArrayIndex].k.used );
    j = 0;
    do 
    {
        if ( j == 0 ) {
             oETCS->aPacket[i_ArrayIndex].n.used                = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 5) + 1;
        }
		oETCS->aPacket[i_ArrayIndex].n.a_data[j].NID_NTC                         = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 8);
    } while ( ++j < oETCS->aPacket[i_ArrayIndex].n.used );
    return Bitwalker_IncrementalWalker_Peek_Finish (&PeekLocals);
    
    }
// =======================

int TrainToTrack_Packet_044 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_TrainToTrack_Data_used_by_applications_outside_the_ERTMS_or_ETCS_system oETCS ) 
{  
//    TP_DATA_oETCS_TrainToTrack_Data_used_by_applications_outside_the_ERTMS_or_ETCS_system oETCS  = (TP_DATA_oETCS_TrainToTrack_Data_used_by_applications_outside_the_ERTMS_or_ETCS_system)void_oETCS;
    T_Bitwalker_Incremental_Locals PeekLocals;
    Bitwalker_IncrementalWalker_Init(&PeekLocals, p_Telegramm, i_akt_dim, bitindex);

// TransmissionMedia=RBC, RIU
// Packet Number = 44
	oETCS->aPacket[i_ArrayIndex].NID_PACKET                                  = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 8);
	oETCS->aPacket[i_ArrayIndex].L_PACKET                                    = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals,13);
	oETCS->aPacket[i_ArrayIndex].NID_XUSER                                   = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 9);
	oETCS->aPacket[i_ArrayIndex].Other_data_depending_on__NID_XUSER          = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 0);
    return Bitwalker_IncrementalWalker_Peek_Finish (&PeekLocals);
    
    }
// =======================

//Namespace TrainToTrack ends here

//Namespace BothWays starts here

int BothWays_Packet_255 (void* p_Telegramm, uint32_t bitindex, uint32_t i_akt_dim, uint32_t i_ArrayIndex, TP_DATA_oETCS_BothWays_End_of_Information oETCS ) 
{  
//    TP_DATA_oETCS_BothWays_End_of_Information oETCS  = (TP_DATA_oETCS_BothWays_End_of_Information)void_oETCS;
    T_Bitwalker_Incremental_Locals PeekLocals;
    Bitwalker_IncrementalWalker_Init(&PeekLocals, p_Telegramm, i_akt_dim, bitindex);

// TransmissionMedia=Balise, Loop
// Packet Number = 255
	oETCS->aPacket[i_ArrayIndex].NID_PACKET                                  = (int) Bitwalker_IncrementalWalker_Peek_Next(&PeekLocals, 8);
    return Bitwalker_IncrementalWalker_Peek_Finish (&PeekLocals);
    
    }
// =======================

//Namespace BothWays ends here
