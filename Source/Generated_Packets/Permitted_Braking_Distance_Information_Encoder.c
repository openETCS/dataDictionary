
#include "Permitted_Braking_Distance_Information_Encoder.h"
#include "Permitted_Braking_Distance_Information_UpperBitsNotSet.h"
#include "Bitstream_Write.h"
#include "Permitted_Braking_Distance_Information_Core_1_Encoder.h"

int Permitted_Braking_Distance_Information_Encoder(Bitstream* stream, const Permitted_Braking_Distance_Information_Core* p)
{
    if (NormalBitstream(stream, PERMITTED_BRAKING_DISTANCE_INFORMATION_CORE_BITSIZE))
    {
        if (Permitted_Braking_Distance_Information_UpperBitsNotSet(p))
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
            Bitstream_Write(stream, 15, p->D_PBD);
            Bitstream_Write(stream, 1,  p->Q_GDIR);
            Bitstream_Write(stream, 8,  p->G_PBDSR);
            Bitstream_Write(stream, 1,  p->Q_PBDSR);
            Bitstream_Write(stream, 15, p->D_PBDSR);
            Bitstream_Write(stream, 15, p->L_PBDSR);
            Bitstream_Write(stream, 5,  p->N_ITER_1);
            for (uint32_t i = 0; i < p->N_ITER_1; ++i)
            {
                Permitted_Braking_Distance_Information_Core_1_Encoder(stream, &(p->sub_1[i]));
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

