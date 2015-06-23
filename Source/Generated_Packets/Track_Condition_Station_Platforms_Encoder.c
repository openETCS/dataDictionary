
#include "Track_Condition_Station_Platforms_Encoder.h"
#include "Track_Condition_Station_Platforms_UpperBitsNotSet.h"
#include "Bitstream_Write.h"
#include "Track_Condition_Station_Platforms_Core_1_Encoder.h"

int Track_Condition_Station_Platforms_Encoder(Bitstream* stream, const Track_Condition_Station_Platforms_Core* p)
{
    if (NormalBitstream(stream, TRACK_CONDITION_STATION_PLATFORMS_CORE_BITSIZE))
    {
        if (Track_Condition_Station_Platforms_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 2,  p->Q_DIR);
            Bitstream_Write(stream, 13, p->L_PACKET);
            Bitstream_Write(stream, 2,  p->Q_SCALE);
            Bitstream_Write(stream, 1,  p->Q_TRACKINIT);
            if (p->Q_TRACKINIT == 1)
            {
            Bitstream_Write(stream, 15, p->D_TRACKINIT);
            }

            if (p->Q_TRACKINIT == 0)
            {
            Bitstream_Write(stream, 15, p->D_TRACKCOND);
            Bitstream_Write(stream, 15, p->L_TRACKCOND);
            Bitstream_Write(stream, 4,  p->M_PLATFORM);
            Bitstream_Write(stream, 2,  p->Q_PLATFORM);
            Bitstream_Write(stream, 5,  p->N_ITER_1);
            for (uint32_t i = 0; i < p->N_ITER_1; ++i)
            {
                Track_Condition_Station_Platforms_Core_1_Encoder(stream, &(p->sub_1[i]));
            }
            }




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

