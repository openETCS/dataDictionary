
#include "Packet_Equal.h"
#include "AllPackets.h"
#include <assert.h>

int Packet_Equal(const PacketHeader* a, const PacketHeader* b)
{
    switch (a->list)
    {
        case TRAINTOTRACK :
        {
            switch (a->NID_PACKET)
            {
                case 4 :
                {
                    return ErrorReporting_Equal((const ErrorReporting*)(a), (const ErrorReporting*)(b));
                }

                case 9 :
                {
                    return Level23TransitionInformation_Equal((const Level23TransitionInformation*)(a), (const Level23TransitionInformation*)(b));
                }

                default :
                {
                    fprintf(stderr, "Packet_Equal: unexpected value for a->NID_PACKET = %"PRIu64"\n", a->NID_PACKET);
                    return 0;
                }
            };
        }

        case TRACKTOTRAIN :
        {
            switch (a->NID_PACKET)
            {
                case 65 :
                {
                    return TemporarySpeedRestriction_Equal((const TemporarySpeedRestriction*)(a), (const TemporarySpeedRestriction*)(b));
                }

                case 71 :
                {
                    return AdhesionFactor_Equal((const AdhesionFactor*)(a), (const AdhesionFactor*)(a));
                }

                default :
                {
                    fprintf(stderr, "Packet_Equal: unexpected value for a->NID_PACKET = %"PRIu64"\n", a->NID_PACKET);
                    return 0;
                }
            };
        }

        case BOTHWAYS :
        {
            assert(a->NID_PACKET == 255);
            return EndOfInformation_Equal((const EndOfInformation*)(a), (const EndOfInformation*)b);
        }

        default:
        {
            fprintf(stderr, "Packet_Equal: unexpected value for a->list = %"PRIu64"\n", a->list);
            return 0;
        }
    };
}

