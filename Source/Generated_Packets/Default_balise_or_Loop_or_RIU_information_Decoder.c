
#include "Default_balise_or_Loop_or_RIU_information_Decoder.h"
#include "Bitstream_Read.h"

int Default_balise_or_Loop_or_RIU_information_Decoder(Bitstream* stream, Default_balise_or_Loop_or_RIU_information_Core* p)
{
    if (NormalBitstream(stream, DEFAULT_BALISE_OR_LOOP_OR_RIU_INFORMATION_CORE_BITSIZE))
    {
        //@ ghost const uint32_t pos = stream->bitpos;

	{ p->Q_DIR		= Bitstream_Read(stream, 2); }

	{ p->L_PACKET		= Bitstream_Read(stream, 13); }



	//@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

