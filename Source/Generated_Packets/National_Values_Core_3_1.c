
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


            //@ assert V_NVKVINT_k_m:     EqualBits(stream, pos,       pos + 7,   p->V_NVKVINT_k_m);
            //@ assert M_NVKVINT_k_m:     EqualBits(stream, pos + 7,   pos + 14,  p->M_NVKVINT_k_m);

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

	/*@
	  requires V_NVKVINT_k_m:  stream->bitpos == pos + 0;
	  assigns        	   stream->bitpos;
	  assigns		   p->V_NVKVINT_k_m;
	  ensures  V_NVKVINT_k_m:  stream->bitpos == pos + 7;
	  ensures  V_NVKVINT_k_m:  EqualBits(stream, pos + 0, pos + 7, p->V_NVKVINT_k_m);
	  ensures  V_NVKVINT_k_m:  UpperBitsNotSet(p->V_NVKVINT_k_m, 7);
	*/
	{ p->V_NVKVINT_k_m		= Bitstream_Read(stream, 7); }

	/*@
	  requires M_NVKVINT_k_m:  stream->bitpos == pos + 7;
	  assigns        	   stream->bitpos;
	  assigns		   p->M_NVKVINT_k_m;
	  ensures  M_NVKVINT_k_m:  stream->bitpos == pos + 14;
	  ensures  M_NVKVINT_k_m:  EqualBits(stream, pos + 7, pos + 14, p->M_NVKVINT_k_m);
	  ensures  M_NVKVINT_k_m:  UpperBitsNotSet(p->M_NVKVINT_k_m, 7);
	*/
	{ p->M_NVKVINT_k_m		= Bitstream_Read(stream, 7); }

        //@ assert V_NVKVINT_k_m:     EqualBits(stream, pos,       pos + 7,   p->V_NVKVINT_k_m);
        //@ assert M_NVKVINT_k_m:     EqualBits(stream, pos + 7,   pos + 14,  p->M_NVKVINT_k_m);

        //@ assert V_NVKVINT_k_m:     UpperBitsNotSet(p->V_NVKVINT_k_m,     7);
        //@ assert M_NVKVINT_k_m:     UpperBitsNotSet(p->M_NVKVINT_k_m,     7);

	//@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

