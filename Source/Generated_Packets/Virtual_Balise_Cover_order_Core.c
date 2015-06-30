
#include "Virtual_Balise_Cover_order_Core.h"
#include "UpperBitsNotSet.h"
#include "Bitstream_Write.h"
#include "Bitstream_Read.h"

int Virtual_Balise_Cover_order_UpperBitsNotSet(const Virtual_Balise_Cover_order_Core* p)
{
    bool status = true;

    status = status && UpperBitsNotSet64(p->Q_DIR,             2) ;
    status = status && UpperBitsNotSet64(p->L_PACKET,          13);
    status = status && UpperBitsNotSet64(p->Q_VBCO,            1) ;
    status = status && UpperBitsNotSet64(p->NID_VBCMK,         6) ;
    status = status && UpperBitsNotSet64(p->NID_C,             10);
    if (p->Q_VBCO == 1)
    {
    status = status && UpperBitsNotSet64(p->T_VBC,             8) ;
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

int Virtual_Balise_Cover_order_Encoder(Bitstream* stream, const Virtual_Balise_Cover_order_Core* p)
{
    if (NormalBitstream(stream, VIRTUAL_BALISE_COVER_ORDER_CORE_BITSIZE))
    {
        if (Virtual_Balise_Cover_order_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 2,  p->Q_DIR);
            Bitstream_Write(stream, 13, p->L_PACKET);
            Bitstream_Write(stream, 1,  p->Q_VBCO);
            Bitstream_Write(stream, 6,  p->NID_VBCMK);
            Bitstream_Write(stream, 10, p->NID_C);
            if (p->Q_VBCO == 1)
            {
            Bitstream_Write(stream, 8,  p->T_VBC);
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

int Virtual_Balise_Cover_order_Decoder(Bitstream* stream, Virtual_Balise_Cover_order_Core* p)
{
    if (NormalBitstream(stream, VIRTUAL_BALISE_COVER_ORDER_CORE_BITSIZE))
    {
        //@ ghost const uint32_t pos = stream->bitpos;

	{ p->Q_DIR		= Bitstream_Read(stream, 2); }

	{ p->L_PACKET		= Bitstream_Read(stream, 13); }

	{ p->Q_VBCO		= Bitstream_Read(stream, 1); }

	{ p->NID_VBCMK		= Bitstream_Read(stream, 6); }

	{ p->NID_C		= Bitstream_Read(stream, 10); }

        if (p->Q_VBCO == 1)
        {
	{ p->T_VBC		= Bitstream_Read(stream, 8); }
        }



	//@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

