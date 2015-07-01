
#include "Gradient_Profile_Core_1_Encoder.h"
#include "Gradient_Profile_Core_1_UpperBitsNotSet.h"
#include "Bitstream_Write.h"

int Gradient_Profile_Core_1_Encoder(Bitstream* stream, const Gradient_Profile_Core_1* p)
{
    if (NormalBitstream(stream, GRADIENT_PROFILE_CORE_1_CORE_BITSIZE))
    {
        if (Gradient_Profile_Core_1_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 15, p->D_GRADIENT_k);
            Bitstream_Write(stream, 1,  p->Q_GDIR_k);
            Bitstream_Write(stream, 8,  p->G_A_k);



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

