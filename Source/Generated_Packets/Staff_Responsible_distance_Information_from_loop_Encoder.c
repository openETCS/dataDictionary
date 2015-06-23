
#include "Staff_Responsible_distance_Information_from_loop_Encoder.h"
#include "Staff_Responsible_distance_Information_from_loop_UpperBitsNotSet.h"
#include "Bitstream_Write.h"
#include "Staff_Responsible_distance_Information_from_loop_Core_1_Encoder.h"

int Staff_Responsible_distance_Information_from_loop_Encoder(Bitstream* stream, const Staff_Responsible_distance_Information_from_loop_Core* p)
{
    if (NormalBitstream(stream, STAFF_RESPONSIBLE_DISTANCE_INFORMATION_FROM_LOOP_CORE_BITSIZE))
    {
        if (Staff_Responsible_distance_Information_from_loop_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 2,  p->Q_DIR);
            Bitstream_Write(stream, 13, p->L_PACKET);
            Bitstream_Write(stream, 2,  p->Q_SCALE);
            Bitstream_Write(stream, 1,  p->Q_NEWCOUNTRY_0);
            if (p->Q_NEWCOUNTRY_0 == 1)
            {
            Bitstream_Write(stream, 10, p->NID_C_0);
            }

            Bitstream_Write(stream, 14, p->NID_BG_0);
            Bitstream_Write(stream, 1,  p->Q_NEWCOUNTRY_1);
            if (p->Q_NEWCOUNTRY_1 == 1)
            {
            Bitstream_Write(stream, 10, p->NID_C_1);
            }

            Bitstream_Write(stream, 14, p->NID_BG_1);
            Bitstream_Write(stream, 15, p->D_SR);
            Bitstream_Write(stream, 5,  p->N_ITER_1);
            for (uint32_t i = 0; i < p->N_ITER_1; ++i)
            {
                Staff_Responsible_distance_Information_from_loop_Core_1_Encoder(stream, &(p->sub_1[i]));
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

