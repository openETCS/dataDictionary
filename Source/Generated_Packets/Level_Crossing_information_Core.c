
#include "Level_Crossing_information_Core.h"
#include "UpperBitsNotSet.h"
#include "Bitstream_Write.h"
#include "Bitstream_Read.h"

int Level_Crossing_information_UpperBitsNotSet(const Level_Crossing_information_Core* p)
{
    bool status = true;

    status = status && UpperBitsNotSet64(p->Q_DIR,             2) ;
    status = status && UpperBitsNotSet64(p->L_PACKET,          13);
    status = status && UpperBitsNotSet64(p->Q_SCALE,           2) ;
    status = status && UpperBitsNotSet64(p->NID_LX,            8) ;
    status = status && UpperBitsNotSet64(p->D_LX,              15);
    status = status && UpperBitsNotSet64(p->L_LX,              15);
    status = status && UpperBitsNotSet64(p->Q_LXSTATUS,        1) ;
    if (p->Q_LXSTATUS == 1)
    {
    status = status && UpperBitsNotSet64(p->V_LX,              7) ;
    status = status && UpperBitsNotSet64(p->Q_STOPLX,          1) ;
    }
    if (p->Q_STOPLX == 1)
    {
    status = status && UpperBitsNotSet64(p->L_STOPLX,          15);
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

int Level_Crossing_information_Encoder(Bitstream* stream, const Level_Crossing_information_Core* p)
{
    if (NormalBitstream(stream, LEVEL_CROSSING_INFORMATION_CORE_BITSIZE))
    {
        if (Level_Crossing_information_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 2,  p->Q_DIR);
            Bitstream_Write(stream, 13, p->L_PACKET);
            Bitstream_Write(stream, 2,  p->Q_SCALE);
            Bitstream_Write(stream, 8,  p->NID_LX);
            Bitstream_Write(stream, 15, p->D_LX);
            Bitstream_Write(stream, 15, p->L_LX);
            Bitstream_Write(stream, 1,  p->Q_LXSTATUS);
            if (p->Q_LXSTATUS == 1)
            {
            Bitstream_Write(stream, 7,  p->V_LX);
            Bitstream_Write(stream, 1,  p->Q_STOPLX);
            }

            if (p->Q_STOPLX == 1)
            {
            Bitstream_Write(stream, 15, p->L_STOPLX);
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

int Level_Crossing_information_Decoder(Bitstream* stream, Level_Crossing_information_Core* p)
{
    if (NormalBitstream(stream, LEVEL_CROSSING_INFORMATION_CORE_BITSIZE))
    {
        //@ ghost const uint32_t pos = stream->bitpos;

	{ p->Q_DIR		= Bitstream_Read(stream, 2); }

	{ p->L_PACKET		= Bitstream_Read(stream, 13); }

	{ p->Q_SCALE		= Bitstream_Read(stream, 2); }

	{ p->NID_LX		= Bitstream_Read(stream, 8); }

	{ p->D_LX		= Bitstream_Read(stream, 15); }

	{ p->L_LX		= Bitstream_Read(stream, 15); }

	{ p->Q_LXSTATUS		= Bitstream_Read(stream, 1); }

        if (p->Q_LXSTATUS == 1)
        {
	{ p->V_LX		= Bitstream_Read(stream, 7); }

	{ p->Q_STOPLX		= Bitstream_Read(stream, 1); }
        }

        if (p->Q_STOPLX == 1)
        {
	{ p->L_STOPLX		= Bitstream_Read(stream, 15); }
        }



	//@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

