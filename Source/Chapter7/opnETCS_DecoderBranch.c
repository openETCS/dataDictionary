#include <stdint.h>
#include "opnETCS_Variables.h"
#include "subset026_7.h"
#include "Bitwalker.h"
#include "opnETCS_DecoderBranch.h"
#include "opnETCS_Decoder.h"


/* =============================================================================
Formalization of Subset-026-7 (Chapter 7: ERTMS/ETCS language)

- Name: opnETCS_DecoderBranch.c
- Description: UNISIG SUBSET-026-7, ISSUE : 3.3.0, 3.5 ERTMS/ETCS language) 
- Copyright (c) Siemens AG, 2015, All Rights Reserved
    
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


int TrackToTrain_PackageDecoder(void* Stream, int FirstBitPos,  oETCS_Union *oETCS )
{
    int PackID      = (int) Bitwalker_Peek(FirstBitPos,        8, Stream, 3);
    int Bitlen      = (int) Bitwalker_Peek(FirstBitPos + 10 , 13, Stream, 3);
    int ByteLength  = Bitlen / 8 + 1;
    
    T_Bitwalker_Incremental_Locals PeekLocals;
    Bitwalker_IncrementalWalker_Init(&PeekLocals, Stream, Bitlen, FirstBitPos);
    
    switch(PackID)
    {
       case 0 :
       {
            oETCS->TlgTrackToTrain = E_DATA_oETCS_TrackToTrain_Virtual_Balise_Cover_marker;
            oETCS->NameSpace       = E_DATA_oETCS_TrackToTrain;
            FirstBitPos = TrackToTrain_Packet_000(Stream, FirstBitPos, ByteLength, &(oETCS->TrackP_000));
            break;
       }    
       case 2 :
       {
            oETCS->TlgTrackToTrain = E_DATA_oETCS_TrackToTrain_System_Version_order;
            oETCS->NameSpace       = E_DATA_oETCS_TrackToTrain;
            FirstBitPos = TrackToTrain_Packet_002(Stream, FirstBitPos, ByteLength, &(oETCS->TrackP_002));
            break;
       }    
       case 3 :
       {
            oETCS->TlgTrackToTrain = E_DATA_oETCS_TrackToTrain_National_Values;
            oETCS->NameSpace       = E_DATA_oETCS_TrackToTrain;
            FirstBitPos = TrackToTrain_Packet_003(Stream, FirstBitPos, ByteLength, &(oETCS->TrackP_003));
            break;
       }    
       case 5 :
       {
            oETCS->TlgTrackToTrain = E_DATA_oETCS_TrackToTrain_Linking;
            oETCS->NameSpace       = E_DATA_oETCS_TrackToTrain;
            FirstBitPos = TrackToTrain_Packet_005(Stream, FirstBitPos, ByteLength, &(oETCS->TrackP_005));
            break;
       }    
       case 6 :
       {
            oETCS->TlgTrackToTrain = E_DATA_oETCS_TrackToTrain_Virtual_Balise_Cover_order;
            oETCS->NameSpace       = E_DATA_oETCS_TrackToTrain;
            FirstBitPos = TrackToTrain_Packet_006(Stream, FirstBitPos, ByteLength, &(oETCS->TrackP_006));
            break;
       }    
       case 12 :
       {
            oETCS->TlgTrackToTrain = E_DATA_oETCS_TrackToTrain_Level_1_Movement_Authority;
            oETCS->NameSpace       = E_DATA_oETCS_TrackToTrain;
            FirstBitPos = TrackToTrain_Packet_012(Stream, FirstBitPos, ByteLength, &(oETCS->TrackP_012));
            break;
       }    
       case 13 :
       {
            oETCS->TlgTrackToTrain = E_DATA_oETCS_TrackToTrain_Staff_Responsible_distance_Information_from_loop;
            oETCS->NameSpace       = E_DATA_oETCS_TrackToTrain;
            FirstBitPos = TrackToTrain_Packet_013(Stream, FirstBitPos, ByteLength, &(oETCS->TrackP_013));
            break;
       }    
       case 15 :
       {
            oETCS->TlgTrackToTrain = E_DATA_oETCS_TrackToTrain_Level_23_Movement_Authority;
            oETCS->NameSpace       = E_DATA_oETCS_TrackToTrain;
            FirstBitPos = TrackToTrain_Packet_015(Stream, FirstBitPos, ByteLength, &(oETCS->TrackP_015));
            break;
       }    
       case 16 :
       {
            oETCS->TlgTrackToTrain = E_DATA_oETCS_TrackToTrain_Repositioning_Information;
            oETCS->NameSpace       = E_DATA_oETCS_TrackToTrain;
            FirstBitPos = TrackToTrain_Packet_016(Stream, FirstBitPos, ByteLength, &(oETCS->TrackP_016));
            break;
       }    
       case 21 :
       {
            oETCS->TlgTrackToTrain = E_DATA_oETCS_TrackToTrain_Gradient_Profile;
            oETCS->NameSpace       = E_DATA_oETCS_TrackToTrain;
            FirstBitPos = TrackToTrain_Packet_021(Stream, FirstBitPos, ByteLength, &(oETCS->TrackP_021));
            break;
       }    
       case 27 :
       {
            oETCS->TlgTrackToTrain = E_DATA_oETCS_TrackToTrain_International_Static_Speed_Profile;
            oETCS->NameSpace       = E_DATA_oETCS_TrackToTrain;
            FirstBitPos = TrackToTrain_Packet_027(Stream, FirstBitPos, ByteLength, &(oETCS->TrackP_027));
            break;
       }    
       case 39 :
       {
            oETCS->TlgTrackToTrain = E_DATA_oETCS_TrackToTrain_Track_Condition_Change_of_traction_system;
            oETCS->NameSpace       = E_DATA_oETCS_TrackToTrain;
            FirstBitPos = TrackToTrain_Packet_039(Stream, FirstBitPos, ByteLength, &(oETCS->TrackP_039));
            break;
       }    
       case 40 :
       {
            oETCS->TlgTrackToTrain = E_DATA_oETCS_TrackToTrain_Track_Condition_Change_of_allowed_current_consumption;
            oETCS->NameSpace       = E_DATA_oETCS_TrackToTrain;
            FirstBitPos = TrackToTrain_Packet_040(Stream, FirstBitPos, ByteLength, &(oETCS->TrackP_040));
            break;
       }    
       case 41 :
       {
            oETCS->TlgTrackToTrain = E_DATA_oETCS_TrackToTrain_Level_Transition_Order;
            oETCS->NameSpace       = E_DATA_oETCS_TrackToTrain;
            FirstBitPos = TrackToTrain_Packet_041(Stream, FirstBitPos, ByteLength, &(oETCS->TrackP_041));
            break;
       }    
       case 42 :
       {
            oETCS->TlgTrackToTrain = E_DATA_oETCS_TrackToTrain_Session_Management;
            oETCS->NameSpace       = E_DATA_oETCS_TrackToTrain;
            FirstBitPos = TrackToTrain_Packet_042(Stream, FirstBitPos, ByteLength, &(oETCS->TrackP_042));
            break;
       }    
       case 45 :
       {
            oETCS->TlgTrackToTrain = E_DATA_oETCS_TrackToTrain_Radio_Network_registration;
            oETCS->NameSpace       = E_DATA_oETCS_TrackToTrain;
            FirstBitPos = TrackToTrain_Packet_045(Stream, FirstBitPos, ByteLength, &(oETCS->TrackP_045));
            break;
       }    
       case 46 :
       {
            oETCS->TlgTrackToTrain = E_DATA_oETCS_TrackToTrain_Conditional_Level_Transition_Order;
            oETCS->NameSpace       = E_DATA_oETCS_TrackToTrain;
            FirstBitPos = TrackToTrain_Packet_046(Stream, FirstBitPos, ByteLength, &(oETCS->TrackP_046));
            break;
       }    
       case 49 :
       {
            oETCS->TlgTrackToTrain = E_DATA_oETCS_TrackToTrain_List_of_balises_for_SH_Area;
            oETCS->NameSpace       = E_DATA_oETCS_TrackToTrain;
            FirstBitPos = TrackToTrain_Packet_049(Stream, FirstBitPos, ByteLength, &(oETCS->TrackP_049));
            break;
       }    
       case 51 :
       {
            oETCS->TlgTrackToTrain = E_DATA_oETCS_TrackToTrain_Axle_Load_Speed_Profile;
            oETCS->NameSpace       = E_DATA_oETCS_TrackToTrain;
            FirstBitPos = TrackToTrain_Packet_051(Stream, FirstBitPos, ByteLength, &(oETCS->TrackP_051));
            break;
       }    
       case 52 :
       {
            oETCS->TlgTrackToTrain = E_DATA_oETCS_TrackToTrain_Permitted_Braking_Distance_Information;
            oETCS->NameSpace       = E_DATA_oETCS_TrackToTrain;
            FirstBitPos = TrackToTrain_Packet_052(Stream, FirstBitPos, ByteLength, &(oETCS->TrackP_052));
            break;
       }    
       case 57 :
       {
            oETCS->TlgTrackToTrain = E_DATA_oETCS_TrackToTrain_Movement_Authority_Request_Parameters;
            oETCS->NameSpace       = E_DATA_oETCS_TrackToTrain;
            FirstBitPos = TrackToTrain_Packet_057(Stream, FirstBitPos, ByteLength, &(oETCS->TrackP_057));
            break;
       }    
       case 58 :
       {
            oETCS->TlgTrackToTrain = E_DATA_oETCS_TrackToTrain_Position_Report_Parameters;
            oETCS->NameSpace       = E_DATA_oETCS_TrackToTrain;
            FirstBitPos = TrackToTrain_Packet_058(Stream, FirstBitPos, ByteLength, &(oETCS->TrackP_058));
            break;
       }    
       case 63 :
       {
            oETCS->TlgTrackToTrain = E_DATA_oETCS_TrackToTrain_List_of_Balises_in_SR_Authority;
            oETCS->NameSpace       = E_DATA_oETCS_TrackToTrain;
            FirstBitPos = TrackToTrain_Packet_063(Stream, FirstBitPos, ByteLength, &(oETCS->TrackP_063));
            break;
       }    
       case 64 :
       {
            oETCS->TlgTrackToTrain = E_DATA_oETCS_TrackToTrain_Inhibition_of_revocable_TSRs_from_balises_in_L23;
            oETCS->NameSpace       = E_DATA_oETCS_TrackToTrain;
            FirstBitPos = TrackToTrain_Packet_064(Stream, FirstBitPos, ByteLength, &(oETCS->TrackP_064));
            break;
       }    
       case 65 :
       {
            oETCS->TlgTrackToTrain = E_DATA_oETCS_TrackToTrain_Temporary_Speed_Restriction;
            oETCS->NameSpace       = E_DATA_oETCS_TrackToTrain;
            FirstBitPos = TrackToTrain_Packet_065(Stream, FirstBitPos, ByteLength, &(oETCS->TrackP_065));
            break;
       }    
       case 66 :
       {
            oETCS->TlgTrackToTrain = E_DATA_oETCS_TrackToTrain_Temporary_Speed_Restriction_Revocation;
            oETCS->NameSpace       = E_DATA_oETCS_TrackToTrain;
            FirstBitPos = TrackToTrain_Packet_066(Stream, FirstBitPos, ByteLength, &(oETCS->TrackP_066));
            break;
       }    
       case 67 :
       {
            oETCS->TlgTrackToTrain = E_DATA_oETCS_TrackToTrain_Track_Condition_Big_Metal_Masses;
            oETCS->NameSpace       = E_DATA_oETCS_TrackToTrain;
            FirstBitPos = TrackToTrain_Packet_067(Stream, FirstBitPos, ByteLength, &(oETCS->TrackP_067));
            break;
       }    
       case 68 :
       {
            oETCS->TlgTrackToTrain = E_DATA_oETCS_TrackToTrain_Track_Condition;
            oETCS->NameSpace       = E_DATA_oETCS_TrackToTrain;
            FirstBitPos = TrackToTrain_Packet_068(Stream, FirstBitPos, ByteLength, &(oETCS->TrackP_068));
            break;
       }    
       case 69 :
       {
            oETCS->TlgTrackToTrain = E_DATA_oETCS_TrackToTrain_Track_Condition_Station_Platforms;
            oETCS->NameSpace       = E_DATA_oETCS_TrackToTrain;
            FirstBitPos = TrackToTrain_Packet_069(Stream, FirstBitPos, ByteLength, &(oETCS->TrackP_069));
            break;
       }    
       case 70 :
       {
            oETCS->TlgTrackToTrain = E_DATA_oETCS_TrackToTrain_Route_Suitability_Data;
            oETCS->NameSpace       = E_DATA_oETCS_TrackToTrain;
            FirstBitPos = TrackToTrain_Packet_070(Stream, FirstBitPos, ByteLength, &(oETCS->TrackP_070));
            break;
       }    
       case 71 :
       {
            oETCS->TlgTrackToTrain = E_DATA_oETCS_TrackToTrain_Adhesion_Factor;
            oETCS->NameSpace       = E_DATA_oETCS_TrackToTrain;
            FirstBitPos = TrackToTrain_Packet_071(Stream, FirstBitPos, ByteLength, &(oETCS->TrackP_071));
            break;
       }    
       case 72 :
       {
            oETCS->TlgTrackToTrain = E_DATA_oETCS_TrackToTrain_Packet_for_sending_plain_text_messages;
            oETCS->NameSpace       = E_DATA_oETCS_TrackToTrain;
            FirstBitPos = TrackToTrain_Packet_072(Stream, FirstBitPos, ByteLength, &(oETCS->TrackP_072));
            break;
       }    
       case 76 :
       {
            oETCS->TlgTrackToTrain = E_DATA_oETCS_TrackToTrain_Packet_for_sending_fixed_text_messages;
            oETCS->NameSpace       = E_DATA_oETCS_TrackToTrain;
            FirstBitPos = TrackToTrain_Packet_076(Stream, FirstBitPos, ByteLength, &(oETCS->TrackP_076));
            break;
       }    
       case 79 :
       {
            oETCS->TlgTrackToTrain = E_DATA_oETCS_TrackToTrain_Geographical_Position_Information;
            oETCS->NameSpace       = E_DATA_oETCS_TrackToTrain;
            FirstBitPos = TrackToTrain_Packet_079(Stream, FirstBitPos, ByteLength, &(oETCS->TrackP_079));
            break;
       }    
       case 80 :
       {
            oETCS->TlgTrackToTrain = E_DATA_oETCS_TrackToTrain_Mode_profile;
            oETCS->NameSpace       = E_DATA_oETCS_TrackToTrain;
            FirstBitPos = TrackToTrain_Packet_080(Stream, FirstBitPos, ByteLength, &(oETCS->TrackP_080));
            break;
       }    
       case 88 :
       {
            oETCS->TlgTrackToTrain = E_DATA_oETCS_TrackToTrain_Level_Crossing_information;
            oETCS->NameSpace       = E_DATA_oETCS_TrackToTrain;
            FirstBitPos = TrackToTrain_Packet_088(Stream, FirstBitPos, ByteLength, &(oETCS->TrackP_088));
            break;
       }    
       case 90 :
       {
            oETCS->TlgTrackToTrain = E_DATA_oETCS_TrackToTrain_Track_Ahead_Free_up_to_level_23_transition_location;
            oETCS->NameSpace       = E_DATA_oETCS_TrackToTrain;
            FirstBitPos = TrackToTrain_Packet_090(Stream, FirstBitPos, ByteLength, &(oETCS->TrackP_090));
            break;
       }    
       case 131 :
       {
            oETCS->TlgTrackToTrain = E_DATA_oETCS_TrackToTrain_RBC_transition_order;
            oETCS->NameSpace       = E_DATA_oETCS_TrackToTrain;
            FirstBitPos = TrackToTrain_Packet_131(Stream, FirstBitPos, ByteLength, &(oETCS->TrackP_131));
            break;
       }    
       case 132 :
       {
            oETCS->TlgTrackToTrain = E_DATA_oETCS_TrackToTrain_Danger_for_Shunting_information;
            oETCS->NameSpace       = E_DATA_oETCS_TrackToTrain;
            FirstBitPos = TrackToTrain_Packet_132(Stream, FirstBitPos, ByteLength, &(oETCS->TrackP_132));
            break;
       }    
       case 133 :
       {
            oETCS->TlgTrackToTrain = E_DATA_oETCS_TrackToTrain_Radio_infill_area_information;
            oETCS->NameSpace       = E_DATA_oETCS_TrackToTrain;
            FirstBitPos = TrackToTrain_Packet_133(Stream, FirstBitPos, ByteLength, &(oETCS->TrackP_133));
            break;
       }    
       case 134 :
       {
            oETCS->TlgTrackToTrain = E_DATA_oETCS_TrackToTrain_EOLM_Packet;
            oETCS->NameSpace       = E_DATA_oETCS_TrackToTrain;
            FirstBitPos = TrackToTrain_Packet_134(Stream, FirstBitPos, ByteLength, &(oETCS->TrackP_134));
            break;
       }    
       case 135 :
       {
            oETCS->TlgTrackToTrain = E_DATA_oETCS_TrackToTrain_Stop_Shunting_on_desk_opening;
            oETCS->NameSpace       = E_DATA_oETCS_TrackToTrain;
            FirstBitPos = TrackToTrain_Packet_135(Stream, FirstBitPos, ByteLength, &(oETCS->TrackP_135));
            break;
       }    
       case 136 :
       {
            oETCS->TlgTrackToTrain = E_DATA_oETCS_TrackToTrain_Infill_location_reference;
            oETCS->NameSpace       = E_DATA_oETCS_TrackToTrain;
            FirstBitPos = TrackToTrain_Packet_136(Stream, FirstBitPos, ByteLength, &(oETCS->TrackP_136));
            break;
       }    
       case 137 :
       {
            oETCS->TlgTrackToTrain = E_DATA_oETCS_TrackToTrain_Stop_if_in_Staff_Responsible;
            oETCS->NameSpace       = E_DATA_oETCS_TrackToTrain;
            FirstBitPos = TrackToTrain_Packet_137(Stream, FirstBitPos, ByteLength, &(oETCS->TrackP_137));
            break;
       }    
       case 138 :
       {
            oETCS->TlgTrackToTrain = E_DATA_oETCS_TrackToTrain_Reversing_area_information;
            oETCS->NameSpace       = E_DATA_oETCS_TrackToTrain;
            FirstBitPos = TrackToTrain_Packet_138(Stream, FirstBitPos, ByteLength, &(oETCS->TrackP_138));
            break;
       }    
       case 139 :
       {
            oETCS->TlgTrackToTrain = E_DATA_oETCS_TrackToTrain_Reversing_supervision_information;
            oETCS->NameSpace       = E_DATA_oETCS_TrackToTrain;
            FirstBitPos = TrackToTrain_Packet_139(Stream, FirstBitPos, ByteLength, &(oETCS->TrackP_139));
            break;
       }    
       case 140 :
       {
            oETCS->TlgTrackToTrain = E_DATA_oETCS_TrackToTrain_Train_running_number_from_RBC;
            oETCS->NameSpace       = E_DATA_oETCS_TrackToTrain;
            FirstBitPos = TrackToTrain_Packet_140(Stream, FirstBitPos, ByteLength, &(oETCS->TrackP_140));
            break;
       }    
       case 141 :
       {
            oETCS->TlgTrackToTrain = E_DATA_oETCS_TrackToTrain_Default_Gradient_for_Temporary_Speed_Restriction;
            oETCS->NameSpace       = E_DATA_oETCS_TrackToTrain;
            FirstBitPos = TrackToTrain_Packet_141(Stream, FirstBitPos, ByteLength, &(oETCS->TrackP_141));
            break;
       }    
       case 143 :
       {
            oETCS->TlgTrackToTrain = E_DATA_oETCS_TrackToTrain_Session_Management_with_neighbouring_Radio_Infill_Unit;
            oETCS->NameSpace       = E_DATA_oETCS_TrackToTrain;
            FirstBitPos = TrackToTrain_Packet_143(Stream, FirstBitPos, ByteLength, &(oETCS->TrackP_143));
            break;
       }    
       case 145 :
       {
            oETCS->TlgTrackToTrain = E_DATA_oETCS_TrackToTrain_Inhibition_of_balise_group_message_consistency_reaction;
            oETCS->NameSpace       = E_DATA_oETCS_TrackToTrain;
            FirstBitPos = TrackToTrain_Packet_145(Stream, FirstBitPos, ByteLength, &(oETCS->TrackP_145));
            break;
       }    
       case 254 :
       {
            oETCS->TlgTrackToTrain = E_DATA_oETCS_TrackToTrain_Default_balise_or_Loop_or_RIU_information;
            oETCS->NameSpace       = E_DATA_oETCS_TrackToTrain;
            FirstBitPos = TrackToTrain_Packet_254(Stream, FirstBitPos, ByteLength, &(oETCS->TrackP_254));
            break;
       }    
       default :
       {
            FirstBitPos = FirstBitPos + Bitlen; // address next Package
           // cout << "!!! ERROR: NO branch defined for Package_ID = " << PackID ;
       }
    };  //  schliessen des switch
    return FirstBitPos;
};      //  schliessen des Name Space
//  #####################################


int TrainToTrack_PackageDecoder(void* Stream, int FirstBitPos,  oETCS_Union *oETCS )
{
    int PackID      = (int) Bitwalker_Peek(FirstBitPos,        8, Stream, 3);
    int Bitlen      = (int) Bitwalker_Peek(FirstBitPos + 10 , 13, Stream, 3);
    int ByteLength  = Bitlen / 8 + 1;
    
    T_Bitwalker_Incremental_Locals PeekLocals;
    Bitwalker_IncrementalWalker_Init(&PeekLocals, Stream, Bitlen, FirstBitPos);
    
    switch(PackID)
    {
       case 0 :
       {
            oETCS->TlgTrainToTrack = E_DATA_oETCS_TrainToTrack_Position_Report;
            oETCS->NameSpace       = E_DATA_oETCS_TrainToTrack;
            FirstBitPos = TrainToTrack_Packet_000(Stream, FirstBitPos, ByteLength, &(oETCS->TrainP_000));
            break;
       }    
       case 1 :
       {
            oETCS->TlgTrainToTrack = E_DATA_oETCS_TrainToTrack_Position_Report_based_on_two_balise_groups;
            oETCS->NameSpace       = E_DATA_oETCS_TrainToTrack;
            FirstBitPos = TrainToTrack_Packet_001(Stream, FirstBitPos, ByteLength, &(oETCS->TrainP_001));
            break;
       }    
       case 3 :
       {
            oETCS->TlgTrainToTrack = E_DATA_oETCS_TrainToTrack_Onboard_telephone_numbers;
            oETCS->NameSpace       = E_DATA_oETCS_TrainToTrack;
            FirstBitPos = TrainToTrack_Packet_003(Stream, FirstBitPos, ByteLength, &(oETCS->TrainP_003));
            break;
       }    
       case 4 :
       {
            oETCS->TlgTrainToTrack = E_DATA_oETCS_TrainToTrack_Error_Reporting;
            oETCS->NameSpace       = E_DATA_oETCS_TrainToTrack;
            FirstBitPos = TrainToTrack_Packet_004(Stream, FirstBitPos, ByteLength, &(oETCS->TrainP_004));
            break;
       }    
       case 5 :
       {
            oETCS->TlgTrainToTrack = E_DATA_oETCS_TrainToTrack_Train_running_number;
            oETCS->NameSpace       = E_DATA_oETCS_TrainToTrack;
            FirstBitPos = TrainToTrack_Packet_005(Stream, FirstBitPos, ByteLength, &(oETCS->TrainP_005));
            break;
       }    
       case 9 :
       {
            oETCS->TlgTrainToTrack = E_DATA_oETCS_TrainToTrack_Level_23_transition_information;
            oETCS->NameSpace       = E_DATA_oETCS_TrainToTrack;
            FirstBitPos = TrainToTrack_Packet_009(Stream, FirstBitPos, ByteLength, &(oETCS->TrainP_009));
            break;
       }    
       case 11 :
       {
            oETCS->TlgTrainToTrack = E_DATA_oETCS_TrainToTrack_Validated_train_data;
            oETCS->NameSpace       = E_DATA_oETCS_TrainToTrack;
            FirstBitPos = TrainToTrack_Packet_011(Stream, FirstBitPos, ByteLength, &(oETCS->TrainP_011));
            break;
       }    
       default :
       {
            FirstBitPos = FirstBitPos + Bitlen; // address next Package
           // cout << "!!! ERROR: NO branch defined for Package_ID = " << PackID ;
       }
    };  //  schliessen des switch
    return FirstBitPos;
};      //  schliessen des Name Space
//  #####################################


int BothWays_PackageDecoder(void* Stream, int FirstBitPos,  oETCS_Union *oETCS )
{
    int PackID      = (int) Bitwalker_Peek(FirstBitPos,        8, Stream, 3);
    int Bitlen      = (int) Bitwalker_Peek(FirstBitPos + 10 , 13, Stream, 3);
    int ByteLength  = Bitlen / 8 + 1;
    
    T_Bitwalker_Incremental_Locals PeekLocals;
    Bitwalker_IncrementalWalker_Init(&PeekLocals, Stream, Bitlen, FirstBitPos);
    
    switch(PackID)
    {
       case 255 :
       {
            oETCS->TlgBothWays = E_DATA_oETCS_BothWays_End_of_Information;
            oETCS->NameSpace       = E_DATA_oETCS_BothWays;
            FirstBitPos = BothWays_Packet_255(Stream, FirstBitPos, ByteLength, &(oETCS->BothWP_255));
            break;
       }    
       default :
       {
            FirstBitPos = FirstBitPos + Bitlen; // address next Package
           // cout << "!!! ERROR: NO branch defined for Package_ID = " << PackID ;
       }
    };  //  schliessen des switch
    return FirstBitPos;
};      //  schliessen des Name Space
//  #####################################

