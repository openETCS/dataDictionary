
#include "Axle_Load_Speed_Profile_Core_2_Encoder.h"
#include "Axle_Load_Speed_Profile_Core_2_UpperBitsNotSet.h"
#include "Bitstream_Write.h"
#include "Axle_Load_Speed_Profile_Core_2_1_Encoder.h"

int Axle_Load_Speed_Profile_Core_2_Encoder(Bitstream* stream, const Axle_Load_Speed_Profile_Core_2* p)
{
    if (NormalBitstream(stream, AXLE_LOAD_SPEED_PROFILE_CORE_2_CORE_BITSIZE))
    {
        if (Axle_Load_Speed_Profile_Core_2_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 15, p->D_AXLELOAD_k);
            Bitstream_Write(stream, 15, p->L_AXLELOAD_k);
            Bitstream_Write(stream, 1,  p->Q_FRONT_k);
            Bitstream_Write(stream, 5,  p->N_ITER_2_1);
            for (uint32_t i = 0; i < p->N_ITER_2_1; ++i)
            {
                Axle_Load_Speed_Profile_Core_2_1_Encoder(stream, &(p->sub_2_1[i]));
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

