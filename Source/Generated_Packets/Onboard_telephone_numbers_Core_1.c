
#include "Onboard_telephone_numbers_Core_1.h"
#include "UpperBitsNotSet.h"
#include "Bitstream_Write.h"
#include "Bitstream_Read.h"

int Onboard_telephone_numbers_Core_1_UpperBitsNotSet(const Onboard_telephone_numbers_Core_1* p)
{
    bool status = true;

    status = status && UpperBitsNotSet64(p->NID_RADIO_k,       64);

    if (status)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

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

