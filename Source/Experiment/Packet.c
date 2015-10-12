
#include "Packet.h"
#include "ErrorReporting.h"
#include "Level23TransitionInformation.h"
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
            ErrorReporting* ptr = (ErrorReporting*)(header);
            return ErrorReporting_DecodeBit(stream, ptr);
        }

        case 9 :
        {
            Level23TransitionInformation* ptr = (Level23TransitionInformation*)(header);
            return Level23TransitionInformation_DecodeBit(stream, ptr);
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
            ErrorReporting* ptr = (ErrorReporting*)(header);
            return ptr->L_PACKET;
        }

        case 9 :
        {
            Level23TransitionInformation* ptr = (Level23TransitionInformation*)(header);
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
