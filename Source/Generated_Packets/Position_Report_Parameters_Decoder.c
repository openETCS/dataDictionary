
#include "Position_Report_Parameters_Decoder.h"
#include "Bitstream_Read.h"
#include "Position_Report_Parameters_Core_1_Decoder.h"

int Position_Report_Parameters_Decoder(Bitstream* stream, Position_Report_Parameters_Core* p)
{
    if (NormalBitstream(stream, POSITION_REPORT_PARAMETERS_CORE_BITSIZE))
    {
        //@ ghost const uint32_t pos = stream->bitpos;

	{ p->Q_DIR		= Bitstream_Read(stream, 2); }

	{ p->L_PACKET		= Bitstream_Read(stream, 13); }

	{ p->Q_SCALE		= Bitstream_Read(stream, 2); }

	{ p->T_CYCLOC		= Bitstream_Read(stream, 8); }

	{ p->D_CYCLOC		= Bitstream_Read(stream, 15); }

	{ p->M_LOC		= Bitstream_Read(stream, 3); }

	{ p->N_ITER_1		= Bitstream_Read(stream, 5); }

        for (uint32_t i = 0; i < p->N_ITER_1; ++i)
        {
            Position_Report_Parameters_Core_1_Decoder(stream, &(p->sub_1[i]));
        }


	//@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

