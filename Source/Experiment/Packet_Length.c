
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
                    return ErrorReporting_Length((const ErrorReporting*)(header));
                }

                case 9 :
                {
                    return Level23TransitionInformation_Length((const Level23TransitionInformation*)(header));
                }

                default :
                {
                    fprintf(stderr, "Packet_Length: unexpected value for header->NID_PACKET = %"PRIu64"\n", header->NID_PACKET);
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
                    return TemporarySpeedRestriction_Length((const TemporarySpeedRestriction*)(header));
                }

                case 71 :
                {
                    return AdhesionFactor_Length((const AdhesionFactor*)(header));
                }

                default :
                {
                    fprintf(stderr, "Packet_Length: unexpected value for header->NID_PACKET = %"PRIu64"\n", header->NID_PACKET);
                    return 0;
                }
            };
        }

        case BOTHWAYS :
        {
            assert(header->NID_PACKET == 255);
            return EndOfInformation_Length((const EndOfInformation*)header);
        }

        default:
        {
            fprintf(stderr, "Packet_Length: unexpected value for header->list = %"PRIu64"\n", header->list);
            return 0;
        }
    };
}

