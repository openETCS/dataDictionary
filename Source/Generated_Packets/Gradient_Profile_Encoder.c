
#include "Gradient_Profile_Encoder.h"
#include "Gradient_Profile_UpperBitsNotSet.h"
#include "Bitstream_Write.h"
#include "Gradient_Profile_Core_1_Encoder.h"

int Gradient_Profile_Encoder(Bitstream* stream, const Gradient_Profile_Core* p)
{
    if (NormalBitstream(stream, GRADIENT_PROFILE_CORE_BITSIZE))
    {
        if (Gradient_Profile_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 2,  p->Q_DIR);
            Bitstream_Write(stream, 13, p->L_PACKET);
            Bitstream_Write(stream, 2,  p->Q_SCALE);
            Bitstream_Write(stream, 15, p->D_GRADIENT);
            Bitstream_Write(stream, 1,  p->Q_GDIR);
            Bitstream_Write(stream, 8,  p->G_A);
            Bitstream_Write(stream, 5,  p->N_ITER_1);
            for (uint32_t i = 0; i < p->N_ITER_1; ++i)
            {
                Gradient_Profile_Core_1_Encoder(stream, &(p->sub_1[i]));
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

