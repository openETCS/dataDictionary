
#include "Onboard_telephone_numbers_Core_1_Encoder.h"
#include "Onboard_telephone_numbers_Core_1_UpperBitsNotSet.h"
#include "Bitstream_Write.h"

int Onboard_telephone_numbers_Core_1_Encoder(Bitstream* stream, const Onboard_telephone_numbers_Core_1* p)
{
    if (NormalBitstream(stream, ONBOARD_TELEPHONE_NUMBERS_CORE_1_CORE_BITSIZE))
    {
        if (Onboard_telephone_numbers_Core_1_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 64, p->NID_RADIO_k);



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

