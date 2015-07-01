
#include "Position_Report_Parameters_Core_1_Decoder.h"
#include "Bitstream_Read.h"

int Position_Report_Parameters_Core_1_Decoder(Bitstream* stream, Position_Report_Parameters_Core_1* p)
{
    if (NormalBitstream(stream, POSITION_REPORT_PARAMETERS_CORE_1_CORE_BITSIZE))
    {
        //@ ghost const uint32_t pos = stream->bitpos;

	{ p->D_LOC_k		= Bitstream_Read(stream, 15); }

	{ p->Q_LGTLOC_k		= Bitstream_Read(stream, 1); }



	//@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

