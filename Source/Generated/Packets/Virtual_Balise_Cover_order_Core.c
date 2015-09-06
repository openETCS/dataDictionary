
#include "Virtual_Balise_Cover_order_Core.h"
#include "Bit64.h"
#include "Bitstream_Write.h"
#include "Bitstream_Read.h"
#include "Bitstream_Normal.h"

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
    if (Bitstream_Normal(stream, VIRTUAL_BALISE_COVER_ORDER_CORE_BITSIZE))
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



            //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
            //@ assert L_PACKET:          EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);
            //@ assert Q_VBCO:            EqualBits(stream, pos + 15,  pos + 16,  p->Q_VBCO);
            //@ assert NID_VBCMK:         EqualBits(stream, pos + 16,  pos + 22,  p->NID_VBCMK);
            //@ assert NID_C:             EqualBits(stream, pos + 22,  pos + 32,  p->NID_C);

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
    if (Bitstream_Normal(stream, VIRTUAL_BALISE_COVER_ORDER_CORE_BITSIZE))
    {
        //@ ghost const uint32_t pos = stream->bitpos;

	/*@
	  requires Q_DIR:          stream->bitpos == pos + 0;
	  assigns        	   stream->bitpos;
	  assigns		   p->Q_DIR;
	  ensures  Q_DIR:          stream->bitpos == pos + 2;
	  ensures  Q_DIR:          EqualBits(stream, pos + 0, pos + 2, p->Q_DIR);
	  ensures  Q_DIR:          UpperBitsNotSet(p->Q_DIR, 2);
	*/
	{ p->Q_DIR		= Bitstream_Read(stream, 2); }

	/*@
	  requires L_PACKET:       stream->bitpos == pos + 2;
	  assigns        	   stream->bitpos;
	  assigns		   p->L_PACKET;
	  ensures  L_PACKET:       stream->bitpos == pos + 15;
	  ensures  L_PACKET:       EqualBits(stream, pos + 2, pos + 15, p->L_PACKET);
	  ensures  L_PACKET:       UpperBitsNotSet(p->L_PACKET, 13);
	*/
	{ p->L_PACKET		= Bitstream_Read(stream, 13); }

	/*@
	  requires Q_VBCO:         stream->bitpos == pos + 15;
	  assigns        	   stream->bitpos;
	  assigns		   p->Q_VBCO;
	  ensures  Q_VBCO:         stream->bitpos == pos + 16;
	  ensures  Q_VBCO:         EqualBits(stream, pos + 15, pos + 16, p->Q_VBCO);
	  ensures  Q_VBCO:         UpperBitsNotSet(p->Q_VBCO, 1);
	*/
	{ p->Q_VBCO		= Bitstream_Read(stream, 1); }

	/*@
	  requires NID_VBCMK:      stream->bitpos == pos + 16;
	  assigns        	   stream->bitpos;
	  assigns		   p->NID_VBCMK;
	  ensures  NID_VBCMK:      stream->bitpos == pos + 22;
	  ensures  NID_VBCMK:      EqualBits(stream, pos + 16, pos + 22, p->NID_VBCMK);
	  ensures  NID_VBCMK:      UpperBitsNotSet(p->NID_VBCMK, 6);
	*/
	{ p->NID_VBCMK		= Bitstream_Read(stream, 6); }

	/*@
	  requires NID_C:          stream->bitpos == pos + 22;
	  assigns        	   stream->bitpos;
	  assigns		   p->NID_C;
	  ensures  NID_C:          stream->bitpos == pos + 32;
	  ensures  NID_C:          EqualBits(stream, pos + 22, pos + 32, p->NID_C);
	  ensures  NID_C:          UpperBitsNotSet(p->NID_C, 10);
	*/
	{ p->NID_C		= Bitstream_Read(stream, 10); }

        if (p->Q_VBCO == 1)
        {
	{ p->T_VBC		= Bitstream_Read(stream, 8); }
        }

        //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
        //@ assert L_PACKET:          EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);
        //@ assert Q_VBCO:            EqualBits(stream, pos + 15,  pos + 16,  p->Q_VBCO);
        //@ assert NID_VBCMK:         EqualBits(stream, pos + 16,  pos + 22,  p->NID_VBCMK);
        //@ assert NID_C:             EqualBits(stream, pos + 22,  pos + 32,  p->NID_C);

        //@ assert Q_DIR:             UpperBitsNotSet(p->Q_DIR,             2);
        //@ assert L_PACKET:          UpperBitsNotSet(p->L_PACKET,          13);
        //@ assert Q_VBCO:            UpperBitsNotSet(p->Q_VBCO,            1);
        //@ assert NID_VBCMK:         UpperBitsNotSet(p->NID_VBCMK,         6);
        //@ assert NID_C:             UpperBitsNotSet(p->NID_C,             10);

	//@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

