
#include "Track_Condition_Big_Metal_Masses_Encoder.h"
#include "Track_Condition_Big_Metal_Masses_UpperBitsNotSet.h"
#include "Bitstream_Write.h"
#include "Track_Condition_Big_Metal_Masses_Core_1_Encoder.h"

int Track_Condition_Big_Metal_Masses_Encoder(Bitstream* stream, const Track_Condition_Big_Metal_Masses_Core* p)
{
    if (NormalBitstream(stream, TRACK_CONDITION_BIG_METAL_MASSES_CORE_BITSIZE))
    {
        if (Track_Condition_Big_Metal_Masses_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 2,  p->Q_DIR);
            Bitstream_Write(stream, 13, p->L_PACKET);
            Bitstream_Write(stream, 2,  p->Q_SCALE);
            Bitstream_Write(stream, 15, p->D_TRACKCOND);
            Bitstream_Write(stream, 15, p->L_TRACKCOND);
            Bitstream_Write(stream, 5,  p->N_ITER_1);
            for (uint32_t i = 0; i < p->N_ITER_1; ++i)
            {
                Track_Condition_Big_Metal_Masses_Core_1_Encoder(stream, &(p->sub_1[i]));
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

