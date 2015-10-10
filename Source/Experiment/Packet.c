
#include "Packet.h"
#include "Error_reporting.h"
#include "Level_23_transition_information.h"
#include "Temporary_Speed_Restriction.h"
#include "Adhesion_Factor.h"
#include "End_of_Information.h"

int TrackToTrain_Decode(PacketHeader* header, Bitstream* stream)
{
    switch (header->NID_PACKET)
    {
        case 65 :
        {
            Temporary_Speed_Restriction* ptr = (Temporary_Speed_Restriction*)(header);
            return Temporary_Speed_Restriction_Decode_Bit(stream, ptr);
        }

        case 71 :
        {
            Adhesion_Factor* ptr = (Adhesion_Factor*)(header);
            return Adhesion_Factor_Decode_Bit(stream, ptr);
        }

        case 255 :
        {
            End_of_Information* ptr = (End_of_Information*)(header);
            return End_of_Information_Decode_Bit(stream, ptr);
        }

        default :
        {
            return 0;
        }
    };
}

int TrainToTrack_Decode(PacketHeader* header, Bitstream* stream)
{
    switch (header->NID_PACKET)
    {
        case 4 :
        {
            Error_reporting* ptr = (Error_reporting*)(header);
            return Error_reporting_Decode_Bit(stream, ptr);
        }

        case 9 :
        {
            Level_23_transition_information* ptr = (Level_23_transition_information*)(header);
            return Level_23_transition_information_Decode_Bit(stream, ptr);
        }

        case 255 :
        {
            End_of_Information* ptr = (End_of_Information*)(header);
            return End_of_Information_Decode_Bit(stream, ptr);
        }

        default :
        {
            return 0;
        }
    };
}

int TrainToTrack_Length(const PacketHeader* header)
{
    switch (header->NID_PACKET)
    {
        case 4 :
        {
            Error_reporting* ptr = (Error_reporting*)(header);
            return ptr->L_PACKET;
        }

        case 9 :
        {
            Level_23_transition_information* ptr = (Level_23_transition_information*)(header);
            return ptr->L_PACKET;
        }

        case 255 :
        {
            return 8;
        }

        default :
        {
            return 0;
        }
    };
}

int TrackToTrain_Length(const PacketHeader* header)
{
    switch (header->NID_PACKET)
    {
        case 65 :
        {
            Temporary_Speed_Restriction* ptr = (Temporary_Speed_Restriction*)(header);
            return ptr->L_PACKET;
        }

        case 71 :
        {
            Adhesion_Factor* ptr = (Adhesion_Factor*)(header);
            return ptr->L_PACKET;
        }

        case 255 :
        {
            return 8;
        }

        default :
        {
            return 0;
        }
    };
}

