
#include "Track_Condition_Big_Metal_Masses_Core_1_Encoder.h"
#include "Track_Condition_Big_Metal_Masses_Core_1_UpperBitsNotSet.h"
#include "Bitstream_Write.h"

int Track_Condition_Big_Metal_Masses_Core_1_Encoder(Bitstream* stream, const Track_Condition_Big_Metal_Masses_Core_1* p)
{
    if (NormalBitstream(stream, TRACK_CONDITION_BIG_METAL_MASSES_CORE_1_CORE_BITSIZE))
    {
        if (Track_Condition_Big_Metal_Masses_Core_1_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 15, p->D_TRACKCOND_k);
            Bitstream_Write(stream, 15, p->L_TRACKCOND_k);



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

