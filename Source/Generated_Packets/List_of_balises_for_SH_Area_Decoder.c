
#include "List_of_balises_for_SH_Area_Decoder.h"
#include "Bitstream_Read.h"
#include "List_of_balises_for_SH_Area_Core_1_Decoder.h"

int List_of_balises_for_SH_Area_Decoder(Bitstream* stream, List_of_balises_for_SH_Area_Core* p)
{
    if (NormalBitstream(stream, LIST_OF_BALISES_FOR_SH_AREA_CORE_BITSIZE))
    {
        //@ ghost const uint32_t pos = stream->bitpos;

	{ p->Q_DIR		= Bitstream_Read(stream, 2); }

	{ p->L_PACKET		= Bitstream_Read(stream, 13); }

	{ p->N_ITER_1		= Bitstream_Read(stream, 5); }

        for (uint32_t i = 0; i < p->N_ITER_1; ++i)
        {
            List_of_balises_for_SH_Area_Core_1_Decoder(stream, &(p->sub_1[i]));
        }


	//@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

