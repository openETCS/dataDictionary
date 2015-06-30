
#include "Onboard_telephone_numbers_Core.h"
#include "UpperBitsNotSet.h"
#include "Bitstream_Write.h"
#include "Bitstream_Read.h"

int Onboard_telephone_numbers_UpperBitsNotSet(const Onboard_telephone_numbers_Core* p)
{
    bool status = true;

    status = status && UpperBitsNotSet64(p->L_PACKET,          13);
    status = status && UpperBitsNotSet64(p->N_ITER_1,          5) ;
    for (uint32_t i = 0; i < p->N_ITER_1; ++i)
    {
        status = status && Onboard_telephone_numbers_Core_1_UpperBitsNotSet(&(p->sub_1[i]));
    }

    if (status)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

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

