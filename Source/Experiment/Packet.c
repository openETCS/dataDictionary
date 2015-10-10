
#include "Packet.h"
#include "Error_reporting.h"
#include "Level_23_transition_information.h"
#include "TemporarySpeedRestriction.h"
#include "AdhesionFactor.h"
#include "EndOfInformation.h"

int TrackToTrain_DecodeBit(PacketHeader* header, Bitstream* stream)
{
    switch (header->NID_PACKET)
    {
        case 65 :
        {
            TemporarySpeedRestriction* ptr = (TemporarySpeedRestriction*)(header);
            return TemporarySpeedRestriction_DecodeBit(stream, ptr);
        }

        case 71 :
        {
            AdhesionFactor* ptr = (AdhesionFactor*)(header);
            return AdhesionFactor_DecodeBit(stream, ptr);
        }

        case 255 :
        {
            EndOfInformation* ptr = (EndOfInformation*)(header);
            return EndOfInformation_DecodeBit(stream, ptr);
        }

        default :
        {
            return 0;
        }
    };
}

int TrainToTrack_DecodeBit(PacketHeader* header, Bitstream* stream)
{
    switch (header->NID_PACKET)
    {
        case 4 :
        {
            Error_reporting* ptr = (Error_reporting*)(header);
            return Error_reporting_DecodeBit(stream, ptr);
        }

        case 9 :
        {
            Level_23_transition_information* ptr = (Level_23_transition_information*)(header);
            return Level_23_transition_information_DecodeBit(stream, ptr);
        }

        case 255 :
        {
            EndOfInformation* ptr = (EndOfInformation*)(header);
            return EndOfInformation_DecodeBit(stream, ptr);
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
            TemporarySpeedRestriction* ptr = (TemporarySpeedRestriction*)(header);
            return ptr->L_PACKET;
        }

        case 71 :
        {
            AdhesionFactor* ptr = (AdhesionFactor*)(header);
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

