
#include "Packet.h"
#include "AllPackets.h"
#include <assert.h>

void TrainToTrack_Print(FILE* stream, const PacketHeader* header)
{
    switch (header->NID_PACKET)
    {
        case 4 :
        {
            const ErrorReporting* ptr = (const ErrorReporting*)(header);
            ErrorReporting_Print(stream, ptr);
            break;
        }

        case 9 :
        {
            const Level23TransitionInformation* ptr = (const Level23TransitionInformation*)(header);
            Level23TransitionInformation_Print(stream, ptr);
            break;
        }

        default :
        {
            break;
        }
    };
}

void TrackToTrain_Print(FILE* stream, const PacketHeader* header)
{
    switch (header->NID_PACKET)
    {
        case 65 :
        {
            const TemporarySpeedRestriction* ptr = (const TemporarySpeedRestriction*)(header);
            TemporarySpeedRestriction_Print(stream, ptr);
            break;
        }

        case 71 :
        {
            const AdhesionFactor* ptr = (const AdhesionFactor*)(header);
            AdhesionFactor_Print(stream, ptr);
            break;
        }

        default :
        {
            break;
        }
    };
}

void BothWays_Print(FILE* stream, const PacketHeader* header)
{
    switch (header->NID_PACKET)
    {
        case 255 :
        {
            const EndOfInformation* ptr = (const EndOfInformation*)(header);
            EndOfInformation_Print(stream, ptr);
            break;
        }

        default :
        {
            break;
        }
    };
}

void Packet_Print(FILE* stream, const PacketHeader* header)
{
    switch (header->list)
    {
        case 0 :
        {
            TrainToTrack_Print(stream, header);
            break;
        }

        case 1 :
        {
            TrackToTrain_Print(stream, header);
            break;
        }

        case 2 :
        {
            BothWays_Print(stream, header);
            break;
        }

        default :
        {
            break;
        }
    };
}

uint32_t TrainToTrack_Length(const PacketHeader* header)
{
    switch (header->NID_PACKET)
    {
        case 4 :
        {
            const ErrorReporting* ptr = (const ErrorReporting*)(header);
            return (uint32_t) ptr->L_PACKET;
        }

        case 9 :
        {
            const Level23TransitionInformation* ptr = (const Level23TransitionInformation*)(header);
            return (uint32_t) ptr->L_PACKET;
        }

        default :
        {
            return 0;
        }
    };
}

uint32_t TrackToTrain_Length(const PacketHeader* header)
{
    switch (header->NID_PACKET)
    {
        case 65 :
        {
            const TemporarySpeedRestriction* ptr = (const TemporarySpeedRestriction*)(header);
            return (uint32_t) ptr->L_PACKET;
        }

        case 71 :
        {
            const AdhesionFactor* ptr = (const AdhesionFactor*)(header);
            return (uint32_t) ptr->L_PACKET;
        }

        default :
        {
            return 0;
        }
    };
}

uint32_t Packet_Length(const PacketHeader* header)
{
    switch (header->list)
    {
        case 0 :
        {
            return TrainToTrack_Length(header);
        }

        case 1 :
        {
            return TrackToTrain_Length(header);
        }

        default :
        {
            return 8; // for packet 255
        }
    };
}

