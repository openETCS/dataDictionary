
#include "Position_Report_based_on_two_balise_groups_Decoder.h"
#include "Bitstream_Read.h"

int Position_Report_based_on_two_balise_groups_Decoder(Bitstream* stream, Position_Report_based_on_two_balise_groups_Core* p)
{
    if (NormalBitstream(stream, POSITION_REPORT_BASED_ON_TWO_BALISE_GROUPS_CORE_BITSIZE))
    {
        //@ ghost const uint32_t pos = stream->bitpos;

	{ p->L_PACKET		= Bitstream_Read(stream, 13); }

	{ p->Q_SCALE		= Bitstream_Read(stream, 2); }

	{ p->NID_LRBG		= Bitstream_Read(stream, 24); }

	{ p->NID_PRVLRBG		= Bitstream_Read(stream, 24); }

	{ p->D_LRBG		= Bitstream_Read(stream, 15); }

	{ p->Q_DIRLRBG		= Bitstream_Read(stream, 2); }

	{ p->Q_DLRBG		= Bitstream_Read(stream, 2); }

	{ p->L_DOUBTOVER		= Bitstream_Read(stream, 15); }

	{ p->L_DOUBTUNDER		= Bitstream_Read(stream, 15); }

	{ p->Q_LENGTH		= Bitstream_Read(stream, 2); }

        if ((p->Q_LENGTH == 1) || (p->Q_LENGTH == 2))
        {
	{ p->L_TRAININT		= Bitstream_Read(stream, 15); }
        }

	{ p->V_TRAIN		= Bitstream_Read(stream, 7); }

	{ p->Q_DIRTRAIN		= Bitstream_Read(stream, 2); }

	{ p->M_MODE		= Bitstream_Read(stream, 4); }

	{ p->M_LEVEL		= Bitstream_Read(stream, 3); }

        if (p->M_LEVEL == 1)
        {
	{ p->NID_NTC		= Bitstream_Read(stream, 8); }
        }



	//@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

