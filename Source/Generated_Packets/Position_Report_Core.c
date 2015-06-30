
#include "Position_Report_Core.h"
#include "UpperBitsNotSet.h"
#include "Bitstream_Write.h"
#include "Bitstream_Read.h"

int Position_Report_UpperBitsNotSet(const Position_Report_Core* p)
{
    bool status = true;

    status = status && UpperBitsNotSet64(p->L_PACKET,          13);
    status = status && UpperBitsNotSet64(p->Q_SCALE,           2) ;
    status = status && UpperBitsNotSet64(p->NID_LRBG,          24);
    status = status && UpperBitsNotSet64(p->D_LRBG,            15);
    status = status && UpperBitsNotSet64(p->Q_DIRLRBG,         2) ;
    status = status && UpperBitsNotSet64(p->Q_DLRBG,           2) ;
    status = status && UpperBitsNotSet64(p->L_DOUBTOVER,       15);
    status = status && UpperBitsNotSet64(p->L_DOUBTUNDER,      15);
    status = status && UpperBitsNotSet64(p->Q_LENGTH,          2) ;
    if ((p->Q_LENGTH == 1) || (p->Q_LENGTH == 2))
    {
    status = status && UpperBitsNotSet64(p->L_TRAININT,        15);
    }
    status = status && UpperBitsNotSet64(p->V_TRAIN,           7) ;
    status = status && UpperBitsNotSet64(p->Q_DIRTRAIN,        2) ;
    status = status && UpperBitsNotSet64(p->M_MODE,            4) ;
    status = status && UpperBitsNotSet64(p->M_LEVEL,           3) ;
    if (p->M_LEVEL == 1)
    {
    status = status && UpperBitsNotSet64(p->NID_NTC,           8) ;
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

int Position_Report_Encoder(Bitstream* stream, const Position_Report_Core* p)
{
    if (NormalBitstream(stream, POSITION_REPORT_CORE_BITSIZE))
    {
        if (Position_Report_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 13, p->L_PACKET);
            Bitstream_Write(stream, 2,  p->Q_SCALE);
            Bitstream_Write(stream, 24, p->NID_LRBG);
            Bitstream_Write(stream, 15, p->D_LRBG);
            Bitstream_Write(stream, 2,  p->Q_DIRLRBG);
            Bitstream_Write(stream, 2,  p->Q_DLRBG);
            Bitstream_Write(stream, 15, p->L_DOUBTOVER);
            Bitstream_Write(stream, 15, p->L_DOUBTUNDER);
            Bitstream_Write(stream, 2,  p->Q_LENGTH);
            if ((p->Q_LENGTH == 1) || (p->Q_LENGTH == 2))
            {
            Bitstream_Write(stream, 15, p->L_TRAININT);
            }

            Bitstream_Write(stream, 7,  p->V_TRAIN);
            Bitstream_Write(stream, 2,  p->Q_DIRTRAIN);
            Bitstream_Write(stream, 4,  p->M_MODE);
            Bitstream_Write(stream, 3,  p->M_LEVEL);
            if (p->M_LEVEL == 1)
            {
            Bitstream_Write(stream, 8,  p->NID_NTC);
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

int Position_Report_Decoder(Bitstream* stream, Position_Report_Core* p)
{
    if (NormalBitstream(stream, POSITION_REPORT_CORE_BITSIZE))
    {
        //@ ghost const uint32_t pos = stream->bitpos;

	{ p->L_PACKET		= Bitstream_Read(stream, 13); }

	{ p->Q_SCALE		= Bitstream_Read(stream, 2); }

	{ p->NID_LRBG		= Bitstream_Read(stream, 24); }

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

