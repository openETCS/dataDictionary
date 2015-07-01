
#include "Linking_Decoder.h"
#include "Bitstream_Read.h"
#include "Linking_Core_1_Decoder.h"

int Linking_Decoder(Bitstream* stream, Linking_Core* p)
{
    if (NormalBitstream(stream, LINKING_CORE_BITSIZE))
    {
        //@ ghost const uint32_t pos = stream->bitpos;

	{ p->Q_DIR		= Bitstream_Read(stream, 2); }

	{ p->L_PACKET		= Bitstream_Read(stream, 13); }

	{ p->Q_SCALE		= Bitstream_Read(stream, 2); }

	{ p->D_LINK		= Bitstream_Read(stream, 15); }

	{ p->Q_NEWCOUNTRY		= Bitstream_Read(stream, 1); }

        if (p->Q_NEWCOUNTRY == 1)
        {
	{ p->NID_C		= Bitstream_Read(stream, 10); }
        }

	{ p->NID_BG		= Bitstream_Read(stream, 14); }

	{ p->Q_LINKORIENTATION		= Bitstream_Read(stream, 1); }

	{ p->Q_LINKREACTION		= Bitstream_Read(stream, 2); }

	{ p->Q_LOCACC		= Bitstream_Read(stream, 6); }

	{ p->N_ITER_1		= Bitstream_Read(stream, 5); }

        for (uint32_t i = 0; i < p->N_ITER_1; ++i)
        {
            Linking_Core_1_Decoder(stream, &(p->sub_1[i]));
        }


	//@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

