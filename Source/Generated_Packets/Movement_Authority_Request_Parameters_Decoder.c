
#include "Movement_Authority_Request_Parameters_Decoder.h"
#include "Bitstream_Read.h"

int Movement_Authority_Request_Parameters_Decoder(Bitstream* stream, Movement_Authority_Request_Parameters_Core* p)
{
    if (NormalBitstream(stream, MOVEMENT_AUTHORITY_REQUEST_PARAMETERS_CORE_BITSIZE))
    {
        //@ ghost const uint32_t pos = stream->bitpos;

	{ p->Q_DIR		= Bitstream_Read(stream, 2); }

	{ p->L_PACKET		= Bitstream_Read(stream, 13); }

	{ p->T_MAR		= Bitstream_Read(stream, 8); }

	{ p->T_TIMEOUTRQST		= Bitstream_Read(stream, 10); }

	{ p->T_CYCRQST		= Bitstream_Read(stream, 8); }



	//@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

