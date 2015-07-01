
#include "International_Static_Speed_Profile_Encoder.h"
#include "International_Static_Speed_Profile_UpperBitsNotSet.h"
#include "Bitstream_Write.h"
#include "International_Static_Speed_Profile_Core_1_Encoder.h"
#include "International_Static_Speed_Profile_Core_2_Encoder.h"

int International_Static_Speed_Profile_Encoder(Bitstream* stream, const International_Static_Speed_Profile_Core* p)
{
    if (NormalBitstream(stream, INTERNATIONAL_STATIC_SPEED_PROFILE_CORE_BITSIZE))
    {
        if (International_Static_Speed_Profile_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 2,  p->Q_DIR);
            Bitstream_Write(stream, 13, p->L_PACKET);
            Bitstream_Write(stream, 2,  p->Q_SCALE);
            Bitstream_Write(stream, 15, p->D_STATIC);
            Bitstream_Write(stream, 7,  p->V_STATIC);
            Bitstream_Write(stream, 1,  p->Q_FRONT);
            Bitstream_Write(stream, 5,  p->N_ITER_1);
            for (uint32_t i = 0; i < p->N_ITER_1; ++i)
            {
                International_Static_Speed_Profile_Core_1_Encoder(stream, &(p->sub_1[i]));
            }
            Bitstream_Write(stream, 5,  p->N_ITER_2);
            for (uint32_t i = 0; i < p->N_ITER_2; ++i)
            {
                International_Static_Speed_Profile_Core_2_Encoder(stream, &(p->sub_2[i]));
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

