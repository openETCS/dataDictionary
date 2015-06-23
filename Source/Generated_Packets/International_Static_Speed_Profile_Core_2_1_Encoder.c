
#include "International_Static_Speed_Profile_Core_2_1_Encoder.h"
#include "International_Static_Speed_Profile_Core_2_1_UpperBitsNotSet.h"
#include "Bitstream_Write.h"

int International_Static_Speed_Profile_Core_2_1_Encoder(Bitstream* stream, const International_Static_Speed_Profile_Core_2_1* p)
{
    if (NormalBitstream(stream, INTERNATIONAL_STATIC_SPEED_PROFILE_CORE_2_1_CORE_BITSIZE))
    {
        if (International_Static_Speed_Profile_Core_2_1_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 2,  p->Q_DIFF_k_m);
            if (p->Q_DIFF_k_m == 0)
            {
            Bitstream_Write(stream, 4,  p->NC_CDDIFF_k_m);
            }

            if ((p->Q_DIFF_k_m == 1) || (p->Q_DIFF_k_m == 2))
            {
            Bitstream_Write(stream, 4,  p->NC_DIFF_k_m);
            }

            Bitstream_Write(stream, 7,  p->V_DIFF_k_m);



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

