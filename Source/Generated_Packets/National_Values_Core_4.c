
#include "National_Values_Core_4.h"
#include "UpperBitsNotSet.h"
#include "Bitstream_Write.h"
#include "Bitstream_Read.h"

int National_Values_Core_4_UpperBitsNotSet(const National_Values_Core_4* p)
{
    bool status = true;

    status = status && UpperBitsNotSet64(p->L_NVKRINT_l,       5) ;
    status = status && UpperBitsNotSet64(p->M_NVKRINT_l,       5) ;

    if (status)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int National_Values_Core_4_Encoder(Bitstream* stream, const National_Values_Core_4* p)
{
    if (NormalBitstream(stream, NATIONAL_VALUES_CORE_4_CORE_BITSIZE))
    {
        if (National_Values_Core_4_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 5,  p->L_NVKRINT_l);
            Bitstream_Write(stream, 5,  p->M_NVKRINT_l);



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

int National_Values_Core_4_Decoder(Bitstream* stream, National_Values_Core_4* p)
{
    if (NormalBitstream(stream, NATIONAL_VALUES_CORE_4_CORE_BITSIZE))
    {
        //@ ghost const uint32_t pos = stream->bitpos;

	{ p->L_NVKRINT_l		= Bitstream_Read(stream, 5); }

	{ p->M_NVKRINT_l		= Bitstream_Read(stream, 5); }



	//@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

