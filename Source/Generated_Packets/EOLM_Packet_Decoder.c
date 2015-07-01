
#include "EOLM_Packet_Decoder.h"
#include "Bitstream_Read.h"

int EOLM_Packet_Decoder(Bitstream* stream, EOLM_Packet_Core* p)
{
    if (NormalBitstream(stream, EOLM_PACKET_CORE_BITSIZE))
    {
        //@ ghost const uint32_t pos = stream->bitpos;

	{ p->Q_DIR		= Bitstream_Read(stream, 2); }

	{ p->L_PACKET		= Bitstream_Read(stream, 13); }

	{ p->Q_SCALE		= Bitstream_Read(stream, 2); }

	{ p->NID_LOOP		= Bitstream_Read(stream, 14); }

	{ p->D_LOOP		= Bitstream_Read(stream, 15); }

	{ p->L_LOOP		= Bitstream_Read(stream, 15); }

	{ p->Q_LOOPDIR		= Bitstream_Read(stream, 1); }

	{ p->Q_SSCODE		= Bitstream_Read(stream, 4); }



	//@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

