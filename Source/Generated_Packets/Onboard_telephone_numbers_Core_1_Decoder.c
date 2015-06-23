
#include "Onboard_telephone_numbers_Core_1_Decoder.h"
#include "Bitstream_Read.h"

int Onboard_telephone_numbers_Core_1_Decoder(Bitstream* stream, Onboard_telephone_numbers_Core_1* p)
{
    if (NormalBitstream(stream, ONBOARD_TELEPHONE_NUMBERS_CORE_1_CORE_BITSIZE))
    {
        //@ ghost const uint32_t pos = stream->bitpos;

	{ p->NID_RADIO_k		= Bitstream_Read(stream, 64); }



	//@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

