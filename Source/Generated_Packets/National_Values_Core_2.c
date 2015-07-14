
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


            //@ assert V_NVKVINT_n:       EqualBits(stream, pos,       pos + 7,   p->V_NVKVINT_n);
            //@ assert M_NVKVINT_n:       EqualBits(stream, pos + 7,   pos + 14,  p->M_NVKVINT_n);

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

	/*@
	  requires V_NVKVINT_n:    stream->bitpos == pos + 0;
	  assigns        	   stream->bitpos;
	  assigns		   p->V_NVKVINT_n;
	  ensures  V_NVKVINT_n:    stream->bitpos == pos + 7;
	  ensures  V_NVKVINT_n:    EqualBits(stream, pos + 0, pos + 7, p->V_NVKVINT_n);
	  ensures  V_NVKVINT_n:    UpperBitsNotSet(p->V_NVKVINT_n, 7);
	*/
	{ p->V_NVKVINT_n		= Bitstream_Read(stream, 7); }

	/*@
	  requires M_NVKVINT_n:    stream->bitpos == pos + 7;
	  assigns        	   stream->bitpos;
	  assigns		   p->M_NVKVINT_n;
	  ensures  M_NVKVINT_n:    stream->bitpos == pos + 14;
	  ensures  M_NVKVINT_n:    EqualBits(stream, pos + 7, pos + 14, p->M_NVKVINT_n);
	  ensures  M_NVKVINT_n:    UpperBitsNotSet(p->M_NVKVINT_n, 7);
	*/
	{ p->M_NVKVINT_n		= Bitstream_Read(stream, 7); }

        //@ assert V_NVKVINT_n:       EqualBits(stream, pos,       pos + 7,   p->V_NVKVINT_n);
        //@ assert M_NVKVINT_n:       EqualBits(stream, pos + 7,   pos + 14,  p->M_NVKVINT_n);

        //@ assert V_NVKVINT_n:       UpperBitsNotSet(p->V_NVKVINT_n,       7);
        //@ assert M_NVKVINT_n:       UpperBitsNotSet(p->M_NVKVINT_n,       7);

	//@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

