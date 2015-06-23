
#include "Track_Condition_Station_Platforms_Core_1_Encoder.h"
#include "Track_Condition_Station_Platforms_Core_1_UpperBitsNotSet.h"
#include "Bitstream_Write.h"

int Track_Condition_Station_Platforms_Core_1_Encoder(Bitstream* stream, const Track_Condition_Station_Platforms_Core_1* p)
{
    if (NormalBitstream(stream, TRACK_CONDITION_STATION_PLATFORMS_CORE_1_CORE_BITSIZE))
    {
        if (Track_Condition_Station_Platforms_Core_1_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 15, p->D_TRACKCOND_k);
            Bitstream_Write(stream, 15, p->L_TRACKCOND_k);
            Bitstream_Write(stream, 4,  p->M_PLATFORM_k);
            Bitstream_Write(stream, 2,  p->Q_PLATFORM_k);



            return 1;
        }
        else
        {
            return -2;
        }
    }
    else
    {
        return -1;
    }
}
