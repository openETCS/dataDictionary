
#include "National_Values_Core_1.h"
#include "UpperBitsNotSet.h"
#include "Bitstream_Write.h"
#include "Bitstream_Read.h"

int National_Values_Core_1_UpperBitsNotSet(const National_Values_Core_1* p)
{
    bool status = true;

    status = status && UpperBitsNotSet64(p->NID_C_p,           10);

    if (status)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int National_Values_Core_1_Encoder(Bitstream* stream, const National_Values_Core_1* p)
{
    if (NormalBitstream(stream, NATIONAL_VALUES_CORE_1_CORE_BITSIZE))
    {
        if (National_Values_Core_1_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 10, p->NID_C_p);


            //@ assert NID_C_p:           EqualBits(stream, pos + 47,  pos + 57,  p->NID_C_p);

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

int National_Values_Core_1_Decoder(Bitstream* stream, National_Values_Core_1* p)
{
    if (NormalBitstream(stream, NATIONAL_VALUES_CORE_1_CORE_BITSIZE))
    {
        //@ ghost const uint32_t pos = stream->bitpos;

	/*@
	  requires NID_C_p:        stream->bitpos == pos + 47;
	  assigns        	   stream->bitpos;
	  assigns		   p->NID_C_p;
	  ensures  NID_C_p:        stream->bitpos == pos + 57;
	  ensures  NID_C_p:        EqualBits(stream, pos + 47, pos + 57, p->NID_C_p);
	  ensures  NID_C_p:        UpperBitsNotSet(p->NID_C_p, 10);
	*/
	{ p->NID_C_p		= Bitstream_Read(stream, 10); }

        //@ assert NID_C_p:           EqualBits(stream, pos + 47,  pos + 57,  p->NID_C_p);

        //@ assert NID_C_p:           UpperBitsNotSet(p->NID_C_p,           10);

	//@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

