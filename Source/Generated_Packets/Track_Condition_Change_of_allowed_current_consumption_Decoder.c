
#include "Track_Condition_Change_of_allowed_current_consumption_Decoder.h"
#include "Bitstream_Read.h"

int Track_Condition_Change_of_allowed_current_consumption_Decoder(Bitstream* stream, Track_Condition_Change_of_allowed_current_consumption_Core* p)
{
    if (NormalBitstream(stream, TRACK_CONDITION_CHANGE_OF_ALLOWED_CURRENT_CONSUMPTION_CORE_BITSIZE))
    {
        //@ ghost const uint32_t pos = stream->bitpos;

	{ p->Q_DIR		= Bitstream_Read(stream, 2); }

	{ p->L_PACKET		= Bitstream_Read(stream, 13); }

	{ p->Q_SCALE		= Bitstream_Read(stream, 2); }

	{ p->D_CURRENT		= Bitstream_Read(stream, 15); }

	{ p->M_CURRENT		= Bitstream_Read(stream, 10); }



	//@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

