
#include "List_of_balises_for_SH_Area_Core_1_Decoder.h"
#include "Bitstream_Read.h"

int List_of_balises_for_SH_Area_Core_1_Decoder(Bitstream* stream, List_of_balises_for_SH_Area_Core_1* p)
{
    if (NormalBitstream(stream, LIST_OF_BALISES_FOR_SH_AREA_CORE_1_CORE_BITSIZE))
    {
        //@ ghost const uint32_t pos = stream->bitpos;

	{ p->Q_NEWCOUNTRY_k		= Bitstream_Read(stream, 1); }

        if (p->Q_NEWCOUNTRY_k == 1)
        {
	{ p->NID_C_k		= Bitstream_Read(stream, 10); }
        }

	{ p->NID_BG_k		= Bitstream_Read(stream, 14); }



	//@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

