
#include "Track_Condition_Change_of_traction_system_Decoder.h"
#include "Bitstream_Read.h"

int Track_Condition_Change_of_traction_system_Decoder(Bitstream* stream, Track_Condition_Change_of_traction_system_Core* p)
{
    if (NormalBitstream(stream, TRACK_CONDITION_CHANGE_OF_TRACTION_SYSTEM_CORE_BITSIZE))
    {
        //@ ghost const uint32_t pos = stream->bitpos;

	{ p->Q_DIR		= Bitstream_Read(stream, 2); }

	{ p->L_PACKET		= Bitstream_Read(stream, 13); }

	{ p->Q_SCALE		= Bitstream_Read(stream, 2); }

	{ p->D_TRACTION		= Bitstream_Read(stream, 15); }

	{ p->M_VOLTAGE		= Bitstream_Read(stream, 4); }

        if (p->M_VOLTAGE != 0)
        {
	{ p->NID_CTRACTION		= Bitstream_Read(stream, 10); }
        }



	//@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

