#include <stdint.h>
#include "subset026_8.h"
#include "Bitwalker.h"
#include "Radio_DecoderBranch8.h"
#include "Radio_Decoder.h"
#include "opnETCS_DecoderBranch.h"
#include "opnETCS_Decoder.h"
#include "subset026_7.h"


/* 
=============================================================================
Formalization of Subset-026-8 (Chapter 8: ERTMS/ETCS language)

- Name: Subset-026-8 / Radio_DecoderBranch8.c
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
============================================================================= 
*/

oETCS_Union  oETCS;
extern int TrackToTrain_PackageDecoder(void* Stream, int FirstBitPos,  oETCS_Union *oETCS );
extern int TrainToTrack_PackageDecoder(void* Stream, int FirstBitPos,  oETCS_Union *oETCS );
extern int BothWays_PackageDecoder(    void* Stream, int FirstBitPos,  oETCS_Union *oETCS );


int Radio_TrainToTrack_Decoder(void* Stream, int FirstBitPos, Radio_Union *Radio)
{
    int ArrayIndex  = 0;
    int NID_Message = (int) Bitwalker_Peek(FirstBitPos,        8, Stream, 3);
    int Messagelen  = (int) Bitwalker_Peek(FirstBitPos + 8,   10, Stream, 3);
    int ByteLength  = Messagelen / 8 + 1;
    
    switch(NID_Message)
    {
       case 129 :
       {
            Radio->MessTrainToTrack = E_DATA_Radio_TrainToTrack_Validated_Train_Data;
            Radio->MessNameSpace    = E_DATA_Radio_TrainToTrack;
            FirstBitPos             = TrainToTrack_Message_129(Stream, FirstBitPos, ByteLength, ArrayIndex, &(Radio->TrainM_129));
            while (FirstBitPos < Messagelen)
            {   // repeat for all optionalPackets of chapter 7
                FirstBitPos = TrainToTrack_PackageDecoder(Stream, FirstBitPos,  &oETCS);
            }            
            break;
       }    
       case 130 :
       {
            Radio->MessTrainToTrack = E_DATA_Radio_TrainToTrack_Request_for_Shunting;
            Radio->MessNameSpace    = E_DATA_Radio_TrainToTrack;
            FirstBitPos             = TrainToTrack_Message_130(Stream, FirstBitPos, ByteLength, ArrayIndex, &(Radio->TrainM_130));
            while (FirstBitPos < Messagelen)
            {   // repeat for all optionalPackets of chapter 7
                FirstBitPos = TrainToTrack_PackageDecoder(Stream, FirstBitPos,  &oETCS);
            }            
            break;
       }    
       case 132 :
       {
            Radio->MessTrainToTrack = E_DATA_Radio_TrainToTrack_MA_Request;
            Radio->MessNameSpace    = E_DATA_Radio_TrainToTrack;
            FirstBitPos             = TrainToTrack_Message_132(Stream, FirstBitPos, ByteLength, ArrayIndex, &(Radio->TrainM_132));
            while (FirstBitPos < Messagelen)
            {   // repeat for all optionalPackets of chapter 7
                FirstBitPos = TrainToTrack_PackageDecoder(Stream, FirstBitPos,  &oETCS);
            }            
            break;
       }    
       case 136 :
       {
            Radio->MessTrainToTrack = E_DATA_Radio_TrainToTrack_Train_Position_Report;
            Radio->MessNameSpace    = E_DATA_Radio_TrainToTrack;
            FirstBitPos             = TrainToTrack_Message_136(Stream, FirstBitPos, ByteLength, ArrayIndex, &(Radio->TrainM_136));
            while (FirstBitPos < Messagelen)
            {   // repeat for all optionalPackets of chapter 7
                FirstBitPos = TrainToTrack_PackageDecoder(Stream, FirstBitPos,  &oETCS);
            }            
            break;
       }    
       case 137 :
       {
            Radio->MessTrainToTrack = E_DATA_Radio_TrainToTrack_Request_to_shorten_MA_is_granted;
            Radio->MessNameSpace    = E_DATA_Radio_TrainToTrack;
            FirstBitPos             = TrainToTrack_Message_137(Stream, FirstBitPos, ByteLength, ArrayIndex, &(Radio->TrainM_137));
            while (FirstBitPos < Messagelen)
            {   // repeat for all optionalPackets of chapter 7
                FirstBitPos = TrainToTrack_PackageDecoder(Stream, FirstBitPos,  &oETCS);
            }            
            break;
       }    
       case 138 :
       {
            Radio->MessTrainToTrack = E_DATA_Radio_TrainToTrack_Request_to_shorten_MA_is_rejected;
            Radio->MessNameSpace    = E_DATA_Radio_TrainToTrack;
            FirstBitPos             = TrainToTrack_Message_138(Stream, FirstBitPos, ByteLength, ArrayIndex, &(Radio->TrainM_138));
            while (FirstBitPos < Messagelen)
            {   // repeat for all optionalPackets of chapter 7
                FirstBitPos = TrainToTrack_PackageDecoder(Stream, FirstBitPos,  &oETCS);
            }            
            break;
       }    
       case 146 :
       {
            Radio->MessTrainToTrack = E_DATA_Radio_TrainToTrack_Acknowledgement;
            Radio->MessNameSpace    = E_DATA_Radio_TrainToTrack;
            FirstBitPos             = TrainToTrack_Message_146(Stream, FirstBitPos, ByteLength, ArrayIndex, &(Radio->TrainM_146));
            break;
       }    
       case 147 :
       {
            Radio->MessTrainToTrack = E_DATA_Radio_TrainToTrack_Acknowledgement_of_Emergency_Stop;
            Radio->MessNameSpace    = E_DATA_Radio_TrainToTrack;
            FirstBitPos             = TrainToTrack_Message_147(Stream, FirstBitPos, ByteLength, ArrayIndex, &(Radio->TrainM_147));
            while (FirstBitPos < Messagelen)
            {   // repeat for all optionalPackets of chapter 7
                FirstBitPos = TrainToTrack_PackageDecoder(Stream, FirstBitPos,  &oETCS);
            }            
            break;
       }    
       case 149 :
       {
            Radio->MessTrainToTrack = E_DATA_Radio_TrainToTrack_Track_Ahead_Free_Granted;
            Radio->MessNameSpace    = E_DATA_Radio_TrainToTrack;
            FirstBitPos             = TrainToTrack_Message_149(Stream, FirstBitPos, ByteLength, ArrayIndex, &(Radio->TrainM_149));
            while (FirstBitPos < Messagelen)
            {   // repeat for all optionalPackets of chapter 7
                FirstBitPos = TrainToTrack_PackageDecoder(Stream, FirstBitPos,  &oETCS);
            }            
            break;
       }    
       case 150 :
       {
            Radio->MessTrainToTrack = E_DATA_Radio_TrainToTrack_End_of_Mission;
            Radio->MessNameSpace    = E_DATA_Radio_TrainToTrack;
            FirstBitPos             = TrainToTrack_Message_150(Stream, FirstBitPos, ByteLength, ArrayIndex, &(Radio->TrainM_150));
            while (FirstBitPos < Messagelen)
            {   // repeat for all optionalPackets of chapter 7
                FirstBitPos = TrainToTrack_PackageDecoder(Stream, FirstBitPos,  &oETCS);
            }            
            break;
       }    
       case 153 :
       {
            Radio->MessTrainToTrack = E_DATA_Radio_TrainToTrack_Radio_infill_request;
            Radio->MessNameSpace    = E_DATA_Radio_TrainToTrack;
            FirstBitPos             = TrainToTrack_Message_153(Stream, FirstBitPos, ByteLength, ArrayIndex, &(Radio->TrainM_153));
            while (FirstBitPos < Messagelen)
            {   // repeat for all optionalPackets of chapter 7
                FirstBitPos = TrainToTrack_PackageDecoder(Stream, FirstBitPos,  &oETCS);
            }            
            break;
       }    
       case 154 :
       {
            Radio->MessTrainToTrack = E_DATA_Radio_TrainToTrack_No_compatible_version_supported;
            Radio->MessNameSpace    = E_DATA_Radio_TrainToTrack;
            FirstBitPos             = TrainToTrack_Message_154(Stream, FirstBitPos, ByteLength, ArrayIndex, &(Radio->TrainM_154));
            break;
       }    
       case 155 :
       {
            Radio->MessTrainToTrack = E_DATA_Radio_TrainToTrack_Initiation_of_a_communication_session;
            Radio->MessNameSpace    = E_DATA_Radio_TrainToTrack;
            FirstBitPos             = TrainToTrack_Message_155(Stream, FirstBitPos, ByteLength, ArrayIndex, &(Radio->TrainM_155));
            break;
       }    
       case 156 :
       {
            Radio->MessTrainToTrack = E_DATA_Radio_TrainToTrack_Termination_of_a_communication_session;
            Radio->MessNameSpace    = E_DATA_Radio_TrainToTrack;
            FirstBitPos             = TrainToTrack_Message_156(Stream, FirstBitPos, ByteLength, ArrayIndex, &(Radio->TrainM_156));
            break;
       }    
       case 157 :
       {
            Radio->MessTrainToTrack = E_DATA_Radio_TrainToTrack_SoM_Position_Report;
            Radio->MessNameSpace    = E_DATA_Radio_TrainToTrack;
            FirstBitPos             = TrainToTrack_Message_157(Stream, FirstBitPos, ByteLength, ArrayIndex, &(Radio->TrainM_157));
            while (FirstBitPos < Messagelen)
            {   // repeat for all optionalPackets of chapter 7
                FirstBitPos = TrainToTrack_PackageDecoder(Stream, FirstBitPos,  &oETCS);
            }            
            break;
       }    
       case 158 :
       {
            Radio->MessTrainToTrack = E_DATA_Radio_TrainToTrack_Text_message_acknowledged_by_driver;
            Radio->MessNameSpace    = E_DATA_Radio_TrainToTrack;
            FirstBitPos             = TrainToTrack_Message_158(Stream, FirstBitPos, ByteLength, ArrayIndex, &(Radio->TrainM_158));
            while (FirstBitPos < Messagelen)
            {   // repeat for all optionalPackets of chapter 7
                FirstBitPos = TrainToTrack_PackageDecoder(Stream, FirstBitPos,  &oETCS);
            }            
            break;
       }    
       case 159 :
       {
            Radio->MessTrainToTrack = E_DATA_Radio_TrainToTrack_Session_Established;
            Radio->MessNameSpace    = E_DATA_Radio_TrainToTrack;
            FirstBitPos             = TrainToTrack_Message_159(Stream, FirstBitPos, ByteLength, ArrayIndex, &(Radio->TrainM_159));
            while (FirstBitPos < Messagelen)
            {   // repeat for all optionalPackets of chapter 7
                FirstBitPos = TrainToTrack_PackageDecoder(Stream, FirstBitPos,  &oETCS);
            }            
            break;
       }    
       default :
       {   
           FirstBitPos = FirstBitPos + Messagelen;	// address next Package
           printf ("!!! ERROR: NO branch defined for NID_Message = %d\n", NID_Message);
       }
    }  //  schliessen des switch
    return FirstBitPos;
};      //  schliessen des Name Space
//  #####################################


int Radio_TrackToTrain_Decoder(void* Stream, int FirstBitPos, Radio_Union *Radio)
{
    int ArrayIndex  = 0;
    int NID_Message = (int) Bitwalker_Peek(FirstBitPos,        8, Stream, 3);
    int Messagelen  = (int) Bitwalker_Peek(FirstBitPos + 8,   10, Stream, 3);
    int ByteLength  = Messagelen / 8 + 1;
    
    switch(NID_Message)
    {
       case 2 :
       {
            Radio->MessTrackToTrain = E_DATA_Radio_TrackToTrain_SR_Authorisation;
            Radio->MessNameSpace    = E_DATA_Radio_TrackToTrain;
            FirstBitPos             = TrackToTrain_Message_002(Stream, FirstBitPos, ByteLength, ArrayIndex, &(Radio->TrackM_002));
            while (FirstBitPos < Messagelen)
            {   // repeat for all optionalPackets of chapter 7
                FirstBitPos = TrackToTrain_PackageDecoder(Stream, FirstBitPos,  &oETCS);
            }            
            break;
       }    
       case 3 :
       {
            Radio->MessTrackToTrain = E_DATA_Radio_TrackToTrain_Movement_Authority;
            Radio->MessNameSpace    = E_DATA_Radio_TrackToTrain;
            FirstBitPos             = TrackToTrain_Message_003(Stream, FirstBitPos, ByteLength, ArrayIndex, &(Radio->TrackM_003));
            while (FirstBitPos < Messagelen)
            {   // repeat for all optionalPackets of chapter 7
                FirstBitPos = TrackToTrain_PackageDecoder(Stream, FirstBitPos,  &oETCS);
            }            
            break;
       }    
       case 6 :
       {
            Radio->MessTrackToTrain = E_DATA_Radio_TrackToTrain_Recognition_of_exit_from_TRIP_mode;
            Radio->MessNameSpace    = E_DATA_Radio_TrackToTrain;
            FirstBitPos             = TrackToTrain_Message_006(Stream, FirstBitPos, ByteLength, ArrayIndex, &(Radio->TrackM_006));
            break;
       }    
       case 8 :
       {
            Radio->MessTrackToTrain = E_DATA_Radio_TrackToTrain_Acknowledgement_of_Train_Data;
            Radio->MessNameSpace    = E_DATA_Radio_TrackToTrain;
            FirstBitPos             = TrackToTrain_Message_008(Stream, FirstBitPos, ByteLength, ArrayIndex, &(Radio->TrackM_008));
            break;
       }    
       case 9 :
       {
            Radio->MessTrackToTrain = E_DATA_Radio_TrackToTrain_Request_to_Shorten_MA;
            Radio->MessNameSpace    = E_DATA_Radio_TrackToTrain;
            FirstBitPos             = TrackToTrain_Message_009(Stream, FirstBitPos, ByteLength, ArrayIndex, &(Radio->TrackM_009));
            while (FirstBitPos < Messagelen)
            {   // repeat for all optionalPackets of chapter 7
                FirstBitPos = TrackToTrain_PackageDecoder(Stream, FirstBitPos,  &oETCS);
            }            
            break;
       }    
       case 15 :
       {
            Radio->MessTrackToTrain = E_DATA_Radio_TrackToTrain_Conditional_Emergency_Stop;
            Radio->MessNameSpace    = E_DATA_Radio_TrackToTrain;
            FirstBitPos             = TrackToTrain_Message_015(Stream, FirstBitPos, ByteLength, ArrayIndex, &(Radio->TrackM_015));
            break;
       }    
       case 16 :
       {
            Radio->MessTrackToTrain = E_DATA_Radio_TrackToTrain_Unconditional_Emergency_Stop;
            Radio->MessNameSpace    = E_DATA_Radio_TrackToTrain;
            FirstBitPos             = TrackToTrain_Message_016(Stream, FirstBitPos, ByteLength, ArrayIndex, &(Radio->TrackM_016));
            break;
       }    
       case 18 :
       {
            Radio->MessTrackToTrain = E_DATA_Radio_TrackToTrain_Revocation_of_Emergency_Stop;
            Radio->MessNameSpace    = E_DATA_Radio_TrackToTrain;
            FirstBitPos             = TrackToTrain_Message_018(Stream, FirstBitPos, ByteLength, ArrayIndex, &(Radio->TrackM_018));
            break;
       }    
       case 24 :
       {
            Radio->MessTrackToTrain = E_DATA_Radio_TrackToTrain_General_message;
            Radio->MessNameSpace    = E_DATA_Radio_TrackToTrain;
            FirstBitPos             = TrackToTrain_Message_024(Stream, FirstBitPos, ByteLength, ArrayIndex, &(Radio->TrackM_024));
            while (FirstBitPos < Messagelen)
            {   // repeat for all optionalPackets of chapter 7
                FirstBitPos = TrackToTrain_PackageDecoder(Stream, FirstBitPos,  &oETCS);
            }            
            break;
       }    
       case 27 :
       {
            Radio->MessTrackToTrain = E_DATA_Radio_TrackToTrain_SH_Refused;
            Radio->MessNameSpace    = E_DATA_Radio_TrackToTrain;
            FirstBitPos             = TrackToTrain_Message_027(Stream, FirstBitPos, ByteLength, ArrayIndex, &(Radio->TrackM_027));
            break;
       }    
       case 28 :
       {
            Radio->MessTrackToTrain = E_DATA_Radio_TrackToTrain_SH_Authorised;
            Radio->MessNameSpace    = E_DATA_Radio_TrackToTrain;
            FirstBitPos             = TrackToTrain_Message_028(Stream, FirstBitPos, ByteLength, ArrayIndex, &(Radio->TrackM_028));
            while (FirstBitPos < Messagelen)
            {   // repeat for all optionalPackets of chapter 7
                FirstBitPos = TrackToTrain_PackageDecoder(Stream, FirstBitPos,  &oETCS);
            }            
            break;
       }    
       case 32 :
       {
            Radio->MessTrackToTrain = E_DATA_Radio_TrackToTrain_RBC_or_RIU_System_Version;
            Radio->MessNameSpace    = E_DATA_Radio_TrackToTrain;
            FirstBitPos             = TrackToTrain_Message_032(Stream, FirstBitPos, ByteLength, ArrayIndex, &(Radio->TrackM_032));
            break;
       }    
       case 33 :
       {
            Radio->MessTrackToTrain = E_DATA_Radio_TrackToTrain_MA_with_Shifted_Location_Reference;
            Radio->MessNameSpace    = E_DATA_Radio_TrackToTrain;
            FirstBitPos             = TrackToTrain_Message_033(Stream, FirstBitPos, ByteLength, ArrayIndex, &(Radio->TrackM_033));
            while (FirstBitPos < Messagelen)
            {   // repeat for all optionalPackets of chapter 7
                FirstBitPos = TrackToTrain_PackageDecoder(Stream, FirstBitPos,  &oETCS);
            }            
            break;
       }    
       case 34 :
       {
            Radio->MessTrackToTrain = E_DATA_Radio_TrackToTrain_Track_Ahead_Free_Request;
            Radio->MessNameSpace    = E_DATA_Radio_TrackToTrain;
            FirstBitPos             = TrackToTrain_Message_034(Stream, FirstBitPos, ByteLength, ArrayIndex, &(Radio->TrackM_034));
            break;
       }    
       case 37 :
       {
            Radio->MessTrackToTrain = E_DATA_Radio_TrackToTrain_Infill_MA;
            Radio->MessNameSpace    = E_DATA_Radio_TrackToTrain;
            FirstBitPos             = TrackToTrain_Message_037(Stream, FirstBitPos, ByteLength, ArrayIndex, &(Radio->TrackM_037));
            while (FirstBitPos < Messagelen)
            {   // repeat for all optionalPackets of chapter 7
                FirstBitPos = TrackToTrain_PackageDecoder(Stream, FirstBitPos,  &oETCS);
            }            
            break;
       }    
       case 38 :
       {
            Radio->MessTrackToTrain = E_DATA_Radio_TrackToTrain_Initiation_of_a_communication_session;
            Radio->MessNameSpace    = E_DATA_Radio_TrackToTrain;
            FirstBitPos             = TrackToTrain_Message_038(Stream, FirstBitPos, ByteLength, ArrayIndex, &(Radio->TrackM_038));
            break;
       }    
       case 39 :
       {
            Radio->MessTrackToTrain = E_DATA_Radio_TrackToTrain_Acknowledgement_of_termination_of_a_communication_session;
            Radio->MessNameSpace    = E_DATA_Radio_TrackToTrain;
            FirstBitPos             = TrackToTrain_Message_039(Stream, FirstBitPos, ByteLength, ArrayIndex, &(Radio->TrackM_039));
            break;
       }    
       case 40 :
       {
            Radio->MessTrackToTrain = E_DATA_Radio_TrackToTrain_Train_Rejected;
            Radio->MessNameSpace    = E_DATA_Radio_TrackToTrain;
            FirstBitPos             = TrackToTrain_Message_040(Stream, FirstBitPos, ByteLength, ArrayIndex, &(Radio->TrackM_040));
            break;
       }    
       case 41 :
       {
            Radio->MessTrackToTrain = E_DATA_Radio_TrackToTrain_Train_Accepted;
            Radio->MessNameSpace    = E_DATA_Radio_TrackToTrain;
            FirstBitPos             = TrackToTrain_Message_041(Stream, FirstBitPos, ByteLength, ArrayIndex, &(Radio->TrackM_041));
            break;
       }    
       case 43 :
       {
            Radio->MessTrackToTrain = E_DATA_Radio_TrackToTrain_SoM_position_report_confirmed_by_RBC;
            Radio->MessNameSpace    = E_DATA_Radio_TrackToTrain;
            FirstBitPos             = TrackToTrain_Message_043(Stream, FirstBitPos, ByteLength, ArrayIndex, &(Radio->TrackM_043));
            break;
       }    
       case 45 :
       {
            Radio->MessTrackToTrain = E_DATA_Radio_TrackToTrain_Assignment_of_coordinate_system;
            Radio->MessNameSpace    = E_DATA_Radio_TrackToTrain;
            FirstBitPos             = TrackToTrain_Message_045(Stream, FirstBitPos, ByteLength, ArrayIndex, &(Radio->TrackM_045));
            break;
       }    
       default :
       {   
           FirstBitPos = FirstBitPos + Messagelen;	// address next Package
           printf ("!!! ERROR: NO branch defined for NID_Message = %d\n", NID_Message);
       }
    }  //  schliessen des switch
    return FirstBitPos;
};      //  schliessen des Name Space
//  #####################################

