
#include "National_Values_Core_2.h"
#include "UpperBitsNotSet.h"
#include "Bitstream_Write.h"
#include "Bitstream_Read.h"
#include "Bitstream_Normal.h"

int National_Values_Core_2_UpperBitsNotSet(const National_Values_Core_2* p)
{
    bool status = true;

    status = status && UpperBitsNotSet64(p->V_NVKVINT,         7) ;
    status = status && UpperBitsNotSet64(p->M_NVKVINT,         7) ;

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
    if (Bitstream_Normal(stream, NATIONAL_VALUES_CORE_2_CORE_BITSIZE))
    {
        if (National_Values_Core_2_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 7,  p->V_NVKVINT);
            Bitstream_Write(stream, 7,  p->M_NVKVINT);


            //@ assert V_NVKVINT:         EqualBits(stream, pos,       pos + 7,   p->V_NVKVINT);
            //@ assert M_NVKVINT:         EqualBits(stream, pos + 7,   pos + 14,  p->M_NVKVINT);

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
    if (Bitstream_Normal(stream, NATIONAL_VALUES_CORE_2_CORE_BITSIZE))
    {
        //@ ghost const uint32_t pos = stream->bitpos;

	/*@
	  requires V_NVKVINT:      stream->bitpos == pos + 0;
	  assigns        	   stream->bitpos;
	  assigns		   p->V_NVKVINT;
	  ensures  V_NVKVINT:      stream->bitpos == pos + 7;
	  ensures  V_NVKVINT:      EqualBits(stream, pos + 0, pos + 7, p->V_NVKVINT);
	  ensures  V_NVKVINT:      UpperBitsNotSet(p->V_NVKVINT, 7);
	*/
	{ p->V_NVKVINT		= Bitstream_Read(stream, 7); }

	/*@
	  requires M_NVKVINT:      stream->bitpos == pos + 7;
	  assigns        	   stream->bitpos;
	  assigns		   p->M_NVKVINT;
	  ensures  M_NVKVINT:      stream->bitpos == pos + 14;
	  ensures  M_NVKVINT:      EqualBits(stream, pos + 7, pos + 14, p->M_NVKVINT);
	  ensures  M_NVKVINT:      UpperBitsNotSet(p->M_NVKVINT, 7);
	*/
	{ p->M_NVKVINT		= Bitstream_Read(stream, 7); }

        //@ assert V_NVKVINT:         EqualBits(stream, pos,       pos + 7,   p->V_NVKVINT);
        //@ assert M_NVKVINT:         EqualBits(stream, pos + 7,   pos + 14,  p->M_NVKVINT);

        //@ assert V_NVKVINT:         UpperBitsNotSet(p->V_NVKVINT,         7);
        //@ assert M_NVKVINT:         UpperBitsNotSet(p->M_NVKVINT,         7);

	//@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}
