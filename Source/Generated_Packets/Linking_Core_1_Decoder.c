
#include "Linking_Core_1_Decoder.h"
#include "Bitstream_Read.h"

int Linking_Core_1_Decoder(Bitstream* stream, Linking_Core_1* p)
{
    if (NormalBitstream(stream, LINKING_CORE_1_CORE_BITSIZE))
    {
        //@ ghost const uint32_t pos = stream->bitpos;

	{ p->D_LINK_k		= Bitstream_Read(stream, 15); }

	{ p->Q_NEWCOUNTRY_k		= Bitstream_Read(stream, 1); }

        if (p->Q_NEWCOUNTRY_k == 1)
        {
	{ p->NID_C_k		= Bitstream_Read(stream, 10); }
        }

	{ p->NID_BG_k		= Bitstream_Read(stream, 14); }

	{ p->Q_LINKORIENTATION_k		= Bitstream_Read(stream, 1); }

	{ p->Q_LINKREACTION_k		= Bitstream_Read(stream, 2); }

	{ p->Q_LOCACC_k		= Bitstream_Read(stream, 6); }



	//@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

