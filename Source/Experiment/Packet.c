
#include "Packet.h"
#include "AllPackets.h"
#include <assert.h>



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

