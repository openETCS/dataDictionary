
#include "Packet_Delete.h"
#include "AllPackets.h"
#include <assert.h>

int Packet_Delete(PacketHeader* header)
{
    switch (header->list)
    {
        case TRAINTOTRACK :
        {
            switch (header->NID_PACKET)
            {
                case 4 :
                {
                    ErrorReporting_Delete((ErrorReporting*)(header));
                    return 1;
                }

                case 9 :
                {
                    Level23TransitionInformation_Delete((Level23TransitionInformation*)(header));
                    return 1;
                }

                default :
                {
                    fprintf(stderr, "Packet_Delete: unexpected value for header->NID_PACKET = %"PRIu64"\n", header->NID_PACKET);
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
                    TemporarySpeedRestriction_Delete((TemporarySpeedRestriction*)(header));
                    return 1;
                }

                case 71 :
                {
                    AdhesionFactor_Delete((AdhesionFactor*)(header));
                    return 1;
                }

                default :
                {
                    fprintf(stderr, "Packet_Delete: unexpected value for header->NID_PACKET = %"PRIu64"\n", header->NID_PACKET);
                    return 0;
                }
            };
        }

        case BOTHWAYS :
        {
            assert(header->NID_PACKET == 255);
            EndOfInformation_Delete((EndOfInformation*)header);
            return 1;
        }

        default:
        {
            fprintf(stderr, "Packet_Delete: unexpected value for header->list = %"PRIu64"\n", header->list);
            return 0;
        }
    };
}

