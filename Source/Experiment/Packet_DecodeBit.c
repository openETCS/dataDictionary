
#include "Packet_DecodeBit.h"
#include "AllPackets.h"
#include <assert.h>

int Packet_DecodeBit(PacketHeader* header, Bitstream* stream)
{
    switch (header->list)
    {
        case TRAINTOTRACK :
        {
            switch (header->NID_PACKET)
            {
                case 4 :
                {
                    ErrorReporting_DecodeBit((ErrorReporting*)(header), stream);
                    return 1;
                }

                case 9 :
                {
                    Level23TransitionInformation_DecodeBit((Level23TransitionInformation*)(header), stream);
                    return 1;
                }

                default :
                {
                    fprintf(stderr, "Packet_DecodeBit: unexpected value for header->NID_PACKET = %llu\n", header->NID_PACKET);
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
                    TemporarySpeedRestriction_DecodeBit((TemporarySpeedRestriction*)(header), stream);
                    return 1;
                }

                case 71 :
                {
                    AdhesionFactor_DecodeBit((AdhesionFactor*)(header), stream);
                    return 1;
                }

                default :
                {
                    fprintf(stderr, "Packet_DecodeBit: unexpected value for header->NID_PACKET = %llu\n", header->NID_PACKET);
                    return 0;
                }
            };
        }

        case BOTHWAYS :
        {
            assert(header->NID_PACKET == 255);
            EndOfInformation_DecodeBit((EndOfInformation*)header, stream);
            return 1;
        }

        default:
        {
            fprintf(stderr, "Packet_DecodeBit: unexpected value for header->list = %llu\n", header->list);
            return 0;
        }
    };
}

