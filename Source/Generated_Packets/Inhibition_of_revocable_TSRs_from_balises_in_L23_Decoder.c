
#include "Inhibition_of_revocable_TSRs_from_balises_in_L23_Decoder.h"
#include "Bitstream_Read.h"

int Inhibition_of_revocable_TSRs_from_balises_in_L23_Decoder(Bitstream* stream, Inhibition_of_revocable_TSRs_from_balises_in_L23_Core* p)
{
    if (NormalBitstream(stream, INHIBITION_OF_REVOCABLE_TSRS_FROM_BALISES_IN_L23_CORE_BITSIZE))
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

