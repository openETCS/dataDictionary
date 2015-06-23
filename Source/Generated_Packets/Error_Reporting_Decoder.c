
#include "Error_Reporting_Decoder.h"
#include "Bitstream_Read.h"

int Error_Reporting_Decoder(Bitstream* stream, Error_Reporting_Core* p)
{
    if (NormalBitstream(stream, ERROR_REPORTING_CORE_BITSIZE))
    {
        //@ ghost const uint32_t pos = stream->bitpos;

	{ p->L_PACKET		= Bitstream_Read(stream, 13); }

	{ p->M_ERROR		= Bitstream_Read(stream, 8); }



	//@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

