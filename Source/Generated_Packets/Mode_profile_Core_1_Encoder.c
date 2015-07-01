
#include "Mode_profile_Core_1_Encoder.h"
#include "Mode_profile_Core_1_UpperBitsNotSet.h"
#include "Bitstream_Write.h"

int Mode_profile_Core_1_Encoder(Bitstream* stream, const Mode_profile_Core_1* p)
{
    if (NormalBitstream(stream, MODE_PROFILE_CORE_1_CORE_BITSIZE))
    {
        if (Mode_profile_Core_1_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 15, p->D_MAMODE_k);
            Bitstream_Write(stream, 2,  p->M_MAMODE_k);
            Bitstream_Write(stream, 7,  p->V_MAMODE_k);
            Bitstream_Write(stream, 15, p->L_MAMODE_k);
            Bitstream_Write(stream, 15, p->L_ACKMAMODE_k);
            Bitstream_Write(stream, 1,  p->Q_MAMODE_k);



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

