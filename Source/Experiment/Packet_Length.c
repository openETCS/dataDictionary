
#include "Packet_Length.h"
#include "AllPackets.h"

uint32_t Packet_Length(const PacketHeader* header)
{
    switch (header->list)
    {
        case TRAINTOTRACK :
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
                    fprintf(stderr, "Packet_Length: unexpected value for header->NID_PACKET = %llu\n", header->NID_PACKET);
                    return 0;
                }
            };
        }

        case TRACKTOTRAIN :
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
                    fprintf(stderr, "Packet_Length: unexpected value for header->NID_PACKET = %llu\n", header->NID_PACKET);
                    return 0;
                }
            };
        }

        case BOTHWAYS :
        {
            assert(header->NID_PACKET == 255);
            return 8;
        }

        default:
        {
            fprintf(stderr, "Packet_Length: unexpected value for header->list = %llu\n", header->list);
            return 0;
        }
    };
}

