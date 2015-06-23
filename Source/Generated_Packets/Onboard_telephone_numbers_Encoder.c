
#include "Onboard_telephone_numbers_Encoder.h"
#include "Onboard_telephone_numbers_UpperBitsNotSet.h"
#include "Bitstream_Write.h"
#include "Onboard_telephone_numbers_Core_1_Encoder.h"

int Onboard_telephone_numbers_Encoder(Bitstream* stream, const Onboard_telephone_numbers_Core* p)
{
    if (NormalBitstream(stream, ONBOARD_TELEPHONE_NUMBERS_CORE_BITSIZE))
    {
        if (Onboard_telephone_numbers_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 13, p->L_PACKET);
            Bitstream_Write(stream, 5,  p->N_ITER_1);
            for (uint32_t i = 0; i < p->N_ITER_1; ++i)
            {
                Onboard_telephone_numbers_Core_1_Encoder(stream, &(p->sub_1[i]));
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

