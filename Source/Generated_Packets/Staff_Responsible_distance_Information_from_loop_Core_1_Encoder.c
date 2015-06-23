
#include "Staff_Responsible_distance_Information_from_loop_Core_1_Encoder.h"
#include "Staff_Responsible_distance_Information_from_loop_Core_1_UpperBitsNotSet.h"
#include "Bitstream_Write.h"

int Staff_Responsible_distance_Information_from_loop_Core_1_Encoder(Bitstream* stream, const Staff_Responsible_distance_Information_from_loop_Core_1* p)
{
    if (NormalBitstream(stream, STAFF_RESPONSIBLE_DISTANCE_INFORMATION_FROM_LOOP_CORE_1_CORE_BITSIZE))
    {
        if (Staff_Responsible_distance_Information_from_loop_Core_1_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 1,  p->Q_NEWCOUNTRY_k);
            if (p->Q_NEWCOUNTRY_k == 1)
            {
            Bitstream_Write(stream, 10, p->NID_C_k);
            }

            Bitstream_Write(stream, 14, p->NID_BG_k);
            Bitstream_Write(stream, 15, p->D_SR_k);



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

