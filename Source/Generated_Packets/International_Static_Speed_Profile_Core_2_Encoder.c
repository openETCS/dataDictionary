
#include "International_Static_Speed_Profile_Core_2_Encoder.h"
#include "International_Static_Speed_Profile_Core_2_UpperBitsNotSet.h"
#include "Bitstream_Write.h"
#include "International_Static_Speed_Profile_Core_2_1_Encoder.h"

int International_Static_Speed_Profile_Core_2_Encoder(Bitstream* stream, const International_Static_Speed_Profile_Core_2* p)
{
    if (NormalBitstream(stream, INTERNATIONAL_STATIC_SPEED_PROFILE_CORE_2_CORE_BITSIZE))
    {
        if (International_Static_Speed_Profile_Core_2_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 15, p->D_STATIC_k);
            Bitstream_Write(stream, 7,  p->V_STATIC_k);
            Bitstream_Write(stream, 1,  p->Q_FRONT_k);
            Bitstream_Write(stream, 5,  p->N_ITER_2_1);
            for (uint32_t i = 0; i < p->N_ITER_2_1; ++i)
            {
                International_Static_Speed_Profile_Core_2_1_Encoder(stream, &(p->sub_2_1[i]));
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

