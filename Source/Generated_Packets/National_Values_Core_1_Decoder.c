
#include "National_Values_Core_1_Decoder.h"
#include "Bitstream_Read.h"

int National_Values_Core_1_Decoder(Bitstream* stream, National_Values_Core_1* p)
{
    if (NormalBitstream(stream, NATIONAL_VALUES_CORE_1_CORE_BITSIZE))
    {
        //@ ghost const uint32_t pos = stream->bitpos;

	/*@
	  requires NID_C_p:        stream->bitpos == pos + 75;
	  assigns        	   stream->bitpos;
	  assigns		   p->NID_C_p;
	  ensures  NID_C_p:        stream->bitpos == pos + 85;
	  ensures  NID_C_p:        EqualBits(stream, pos + 75, pos + 85, p->NID_C_p);
	  ensures  NID_C_p:        UpperBitsNotSet(p->NID_C_p, 10);
	*/
	{ p->NID_C_p		= Bitstream_Read(stream, 10); }

        //@ assert NID_C_p:           EqualBits(stream, pos + 75,  pos + 85,  p->NID_C_p);

        //@ assert NID_C_p:           UpperBitsNotSet(p->NID_C_p,           10);

	//@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

