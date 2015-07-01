
#include "Onboard_telephone_numbers_Decoder.h"
#include "Bitstream_Read.h"
#include "Onboard_telephone_numbers_Core_1_Decoder.h"

int Onboard_telephone_numbers_Decoder(Bitstream* stream, Onboard_telephone_numbers_Core* p)
{
    if (NormalBitstream(stream, ONBOARD_TELEPHONE_NUMBERS_CORE_BITSIZE))
    {
        //@ ghost const uint32_t pos = stream->bitpos;

	{ p->L_PACKET		= Bitstream_Read(stream, 13); }

	{ p->N_ITER_1		= Bitstream_Read(stream, 5); }

        for (uint32_t i = 0; i < p->N_ITER_1; ++i)
        {
            Onboard_telephone_numbers_Core_1_Decoder(stream, &(p->sub_1[i]));
        }


	//@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

