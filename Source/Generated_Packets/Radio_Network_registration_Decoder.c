
#include "Radio_Network_registration_Decoder.h"
#include "Bitstream_Read.h"

int Radio_Network_registration_Decoder(Bitstream* stream, Radio_Network_registration_Core* p)
{
    if (NormalBitstream(stream, RADIO_NETWORK_REGISTRATION_CORE_BITSIZE))
    {
        //@ ghost const uint32_t pos = stream->bitpos;

	{ p->Q_DIR		= Bitstream_Read(stream, 2); }

	{ p->L_PACKET		= Bitstream_Read(stream, 13); }

	{ p->NID_MN		= Bitstream_Read(stream, 24); }



	//@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

