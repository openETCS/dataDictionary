
#include "Stop_if_in_Staff_Responsible_Decoder.h"
#include "Bitstream_Read.h"

int Stop_if_in_Staff_Responsible_Decoder(Bitstream* stream, Stop_if_in_Staff_Responsible_Core* p)
{
    if (NormalBitstream(stream, STOP_IF_IN_STAFF_RESPONSIBLE_CORE_BITSIZE))
    {
        //@ ghost const uint32_t pos = stream->bitpos;

	{ p->Q_DIR		= Bitstream_Read(stream, 2); }

	{ p->L_PACKET		= Bitstream_Read(stream, 13); }

	{ p->Q_SRSTOP		= Bitstream_Read(stream, 1); }



	//@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

