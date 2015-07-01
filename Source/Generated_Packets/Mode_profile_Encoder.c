
#include "Mode_profile_Encoder.h"
#include "Mode_profile_UpperBitsNotSet.h"
#include "Bitstream_Write.h"
#include "Mode_profile_Core_1_Encoder.h"

int Mode_profile_Encoder(Bitstream* stream, const Mode_profile_Core* p)
{
    if (NormalBitstream(stream, MODE_PROFILE_CORE_BITSIZE))
    {
        if (Mode_profile_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 2,  p->Q_DIR);
            Bitstream_Write(stream, 13, p->L_PACKET);
            Bitstream_Write(stream, 2,  p->Q_SCALE);
            Bitstream_Write(stream, 15, p->D_MAMODE);
            Bitstream_Write(stream, 2,  p->M_MAMODE);
            Bitstream_Write(stream, 7,  p->V_MAMODE);
            Bitstream_Write(stream, 15, p->L_MAMODE);
            Bitstream_Write(stream, 15, p->L_ACKMAMODE);
            Bitstream_Write(stream, 1,  p->Q_MAMODE);
            Bitstream_Write(stream, 5,  p->N_ITER_1);
            for (uint32_t i = 0; i < p->N_ITER_1; ++i)
            {
                Mode_profile_Core_1_Encoder(stream, &(p->sub_1[i]));
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

