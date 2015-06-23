
#include "Geographical_Position_Information_Core_1_Decoder.h"
#include "Bitstream_Read.h"

int Geographical_Position_Information_Core_1_Decoder(Bitstream* stream, Geographical_Position_Information_Core_1* p)
{
    if (NormalBitstream(stream, GEOGRAPHICAL_POSITION_INFORMATION_CORE_1_CORE_BITSIZE))
    {
        //@ ghost const uint32_t pos = stream->bitpos;

	{ p->Q_NEWCOUNTRY_k		= Bitstream_Read(stream, 1); }

        if (p->Q_NEWCOUNTRY_k == 1)
        {
	{ p->NID_C_k		= Bitstream_Read(stream, 10); }
        }

	{ p->NID_BG_k		= Bitstream_Read(stream, 14); }

	{ p->D_POSOFF_k		= Bitstream_Read(stream, 15); }

	{ p->Q_MPOSITION_k		= Bitstream_Read(stream, 1); }

	{ p->M_POSITION_k		= Bitstream_Read(stream, 24); }



	//@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

