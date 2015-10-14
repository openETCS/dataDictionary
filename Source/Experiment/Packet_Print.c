
#include "Packet_Print.h"
#include "AllPackets.h"
#include <assert.h>

int Packet_Print(const PacketHeader* header, FILE* stream)
{
    switch (header->list)
    {
        case TRAINTOTRACK :
        {
            switch (header->NID_PACKET)
            {
                case 4 :
                {
                    ErrorReporting_Print((const ErrorReporting*)(header), stream);
                    return 1;
                }

                case 9 :
                {
                    Level23TransitionInformation_Print((const Level23TransitionInformation*)(header), stream);
                    return 1;
                }

                default :
                {
                    fprintf(stderr, "Packet_Print: unexpected value for header->NID_PACKET = %llu\n", header->NID_PACKET);
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
                    TemporarySpeedRestriction_Print((const TemporarySpeedRestriction*)(header), stream);
                    return 1;
                }

                case 71 :
                {
                    AdhesionFactor_Print((const AdhesionFactor*)(header), stream);
                    return 1;
                }

                default :
                {
                    fprintf(stderr, "Packet_Print: unexpected value for header->NID_PACKET = %llu\n", header->NID_PACKET);
                    return 0;
                }
            };
        }

        case BOTHWAYS :
        {
            assert(header->NID_PACKET == 255);
            EndOfInformation_Print((const EndOfInformation*)header, stream);
            return 1;
        }

        default:
        {
            fprintf(stderr, "Packet_Print: unexpected value for header->list = %llu\n", header->list);
            return 0;
        }
    };
}

