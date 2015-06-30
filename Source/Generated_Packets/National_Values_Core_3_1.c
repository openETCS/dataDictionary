
#include "National_Values_Core_3_1.h"
#include "UpperBitsNotSet.h"
#include "Bitstream_Write.h"
#include "Bitstream_Read.h"

int National_Values_Core_3_1_UpperBitsNotSet(const National_Values_Core_3_1* p)
{
    bool status = true;

    status = status && UpperBitsNotSet64(p->V_NVKVINT_k_m,     7) ;
    status = status && UpperBitsNotSet64(p->M_NVKVINT_k_m,     7) ;

    if (status)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int National_Values_Core_3_1_Encoder(Bitstream* stream, const National_Values_Core_3_1* p)
{
    if (NormalBitstream(stream, NATIONAL_VALUES_CORE_3_1_CORE_BITSIZE))
    {
        if (National_Values_Core_3_1_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 7,  p->V_NVKVINT_k_m);
            Bitstream_Write(stream, 7,  p->M_NVKVINT_k_m);



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

int National_Values_Core_3_1_Decoder(Bitstream* stream, National_Values_Core_3_1* p)
{
    if (NormalBitstream(stream, NATIONAL_VALUES_CORE_3_1_CORE_BITSIZE))
    {
        //@ ghost const uint32_t pos = stream->bitpos;

	{ p->V_NVKVINT_k_m		= Bitstream_Read(stream, 7); }

	{ p->M_NVKVINT_k_m		= Bitstream_Read(stream, 7); }



	//@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

