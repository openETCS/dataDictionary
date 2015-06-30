
#include "National_Values_Core_2.h"
#include "UpperBitsNotSet.h"
#include "Bitstream_Write.h"
#include "Bitstream_Read.h"

int National_Values_Core_2_UpperBitsNotSet(const National_Values_Core_2* p)
{
    bool status = true;

    status = status && UpperBitsNotSet64(p->V_NVKVINT_n,       7) ;
    status = status && UpperBitsNotSet64(p->M_NVKVINT_n,       7) ;

    if (status)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int National_Values_Core_2_Encoder(Bitstream* stream, const National_Values_Core_2* p)
{
    if (NormalBitstream(stream, NATIONAL_VALUES_CORE_2_CORE_BITSIZE))
    {
        if (National_Values_Core_2_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 7,  p->V_NVKVINT_n);
            Bitstream_Write(stream, 7,  p->M_NVKVINT_n);



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

int National_Values_Core_2_Decoder(Bitstream* stream, National_Values_Core_2* p)
{
    if (NormalBitstream(stream, NATIONAL_VALUES_CORE_2_CORE_BITSIZE))
    {
        //@ ghost const uint32_t pos = stream->bitpos;

	{ p->V_NVKVINT_n		= Bitstream_Read(stream, 7); }

	{ p->M_NVKVINT_n		= Bitstream_Read(stream, 7); }



	//@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

