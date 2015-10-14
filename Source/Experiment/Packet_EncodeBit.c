
#include "Packet_EncodeBit.h"
#include "AllPackets.h"
#include <assert.h>

int Packet_EncodeBit(const PacketHeader* header, Bitstream* stream)
{
    switch (header->list)
    {
        case TRAINTOTRACK :
        {
            switch (header->NID_PACKET)
            {
                case 4 :
                {
                    ErrorReporting_EncodeBit((const ErrorReporting*)(header), stream);
                    return 1;
                }

                case 9 :
                {
                    Level23TransitionInformation_EncodeBit((const Level23TransitionInformation*)(header), stream);
                    return 1;
                }

                default :
                {
                    fprintf(stderr, "Packet_EncodeBit: unexpected value for header->NID_PACKET = %llu\n", header->NID_PACKET);
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
                    TemporarySpeedRestriction_EncodeBit((const TemporarySpeedRestriction*)(header), stream);
                    return 1;
                }

                case 71 :
                {
                    AdhesionFactor_EncodeBit((const AdhesionFactor*)(header), stream);
                    return 1;
                }

                default :
                {
                    fprintf(stderr, "Packet_EncodeBit: unexpected value for header->NID_PACKET = %llu\n", header->NID_PACKET);
                    return 0;
                }
            };
        }

        case BOTHWAYS :
        {
            assert(header->NID_PACKET == 255);
            EndOfInformation_EncodeBit((const EndOfInformation*)header, stream);
            return 1;
        }

        default:
        {
            fprintf(stderr, "Packet_EncodeBit: unexpected value for header->list = %llu\n", header->list);
            return 0;
        }
    };
}

