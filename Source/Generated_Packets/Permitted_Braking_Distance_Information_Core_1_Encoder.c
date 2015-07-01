
#include "Permitted_Braking_Distance_Information_Core_1_Encoder.h"
#include "Permitted_Braking_Distance_Information_Core_1_UpperBitsNotSet.h"
#include "Bitstream_Write.h"

int Permitted_Braking_Distance_Information_Core_1_Encoder(Bitstream* stream, const Permitted_Braking_Distance_Information_Core_1* p)
{
    if (NormalBitstream(stream, PERMITTED_BRAKING_DISTANCE_INFORMATION_CORE_1_CORE_BITSIZE))
    {
        if (Permitted_Braking_Distance_Information_Core_1_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 15, p->D_PBD_k);
            Bitstream_Write(stream, 1,  p->Q_GDIR_k);
            Bitstream_Write(stream, 8,  p->G_PBDSR_k);
            Bitstream_Write(stream, 1,  p->Q_PBDSR_k);
            Bitstream_Write(stream, 15, p->D_PBDSR_k);
            Bitstream_Write(stream, 15, p->L_PBDSR_k);



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

