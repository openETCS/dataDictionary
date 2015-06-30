
#include "Position_Report_Parameters_Core.h"
#include "UpperBitsNotSet.h"
#include "Bitstream_Write.h"
#include "Bitstream_Read.h"

int Position_Report_Parameters_UpperBitsNotSet(const Position_Report_Parameters_Core* p)
{
    bool status = true;

    status = status && UpperBitsNotSet64(p->Q_DIR,             2) ;
    status = status && UpperBitsNotSet64(p->L_PACKET,          13);
    status = status && UpperBitsNotSet64(p->Q_SCALE,           2) ;
    status = status && UpperBitsNotSet64(p->T_CYCLOC,          8) ;
    status = status && UpperBitsNotSet64(p->D_CYCLOC,          15);
    status = status && UpperBitsNotSet64(p->M_LOC,             3) ;
    status = status && UpperBitsNotSet64(p->N_ITER_1,          5) ;
    for (uint32_t i = 0; i < p->N_ITER_1; ++i)
    {
        status = status && Position_Report_Parameters_Core_1_UpperBitsNotSet(&(p->sub_1[i]));
    }

    if (status)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int Position_Report_Parameters_Encoder(Bitstream* stream, const Position_Report_Parameters_Core* p)
{
    if (NormalBitstream(stream, POSITION_REPORT_PARAMETERS_CORE_BITSIZE))
    {
        if (Position_Report_Parameters_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 2,  p->Q_DIR);
            Bitstream_Write(stream, 13, p->L_PACKET);
            Bitstream_Write(stream, 2,  p->Q_SCALE);
            Bitstream_Write(stream, 8,  p->T_CYCLOC);
            Bitstream_Write(stream, 15, p->D_CYCLOC);
            Bitstream_Write(stream, 3,  p->M_LOC);
            Bitstream_Write(stream, 5,  p->N_ITER_1);
            for (uint32_t i = 0; i < p->N_ITER_1; ++i)
            {
                Position_Report_Parameters_Core_1_Encoder(stream, &(p->sub_1[i]));
            }



            return 1;
        }
        else
        {
            return -2;
        }
    }
    else
    {
        return -1;
    }
}

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

