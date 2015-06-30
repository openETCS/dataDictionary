
#include "System_Version_order_Core.h"
#include "UpperBitsNotSet.h"
#include "Bitstream_Write.h"
#include "Bitstream_Read.h"

int System_Version_order_UpperBitsNotSet(const System_Version_order_Core* p)
{
    bool status = true;

    status = status && UpperBitsNotSet64(p->Q_DIR,             2) ;
    status = status && UpperBitsNotSet64(p->L_PACKET,          13);
    status = status && UpperBitsNotSet64(p->M_VERSION,         7) ;

    if (status)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int System_Version_order_Encoder(Bitstream* stream, const System_Version_order_Core* p)
{
    if (NormalBitstream(stream, SYSTEM_VERSION_ORDER_CORE_BITSIZE))
    {
        if (System_Version_order_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 2,  p->Q_DIR);
            Bitstream_Write(stream, 13, p->L_PACKET);
            Bitstream_Write(stream, 7,  p->M_VERSION);


            //@ assert Q_DIR:             EqualBits(stream, pos + 6,   pos + 8,   p->Q_DIR);
            //@ assert L_PACKET:          EqualBits(stream, pos + 8,   pos + 21,  p->L_PACKET);
            //@ assert M_VERSION:         EqualBits(stream, pos + 21,  pos + 28,  p->M_VERSION);

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

int System_Version_order_Decoder(Bitstream* stream, System_Version_order_Core* p)
{
    if (NormalBitstream(stream, SYSTEM_VERSION_ORDER_CORE_BITSIZE))
    {
        //@ ghost const uint32_t pos = stream->bitpos;

	/*@
	  requires Q_DIR:          stream->bitpos == pos + 6;
	  assigns        	   stream->bitpos;
	  assigns		   p->Q_DIR;
	  ensures  Q_DIR:          stream->bitpos == pos + 8;
	  ensures  Q_DIR:          EqualBits(stream, pos + 6, pos + 8, p->Q_DIR);
	  ensures  Q_DIR:          UpperBitsNotSet(p->Q_DIR, 2);
	*/
	{ p->Q_DIR		= Bitstream_Read(stream, 2); }

	/*@
	  requires L_PACKET:       stream->bitpos == pos + 8;
	  assigns        	   stream->bitpos;
	  assigns		   p->L_PACKET;
	  ensures  L_PACKET:       stream->bitpos == pos + 21;
	  ensures  L_PACKET:       EqualBits(stream, pos + 8, pos + 21, p->L_PACKET);
	  ensures  L_PACKET:       UpperBitsNotSet(p->L_PACKET, 13);
	*/
	{ p->L_PACKET		= Bitstream_Read(stream, 13); }

	/*@
	  requires M_VERSION:      stream->bitpos == pos + 21;
	  assigns        	   stream->bitpos;
	  assigns		   p->M_VERSION;
	  ensures  M_VERSION:      stream->bitpos == pos + 28;
	  ensures  M_VERSION:      EqualBits(stream, pos + 21, pos + 28, p->M_VERSION);
	  ensures  M_VERSION:      UpperBitsNotSet(p->M_VERSION, 7);
	*/
	{ p->M_VERSION		= Bitstream_Read(stream, 7); }

        //@ assert Q_DIR:             EqualBits(stream, pos + 6,   pos + 8,   p->Q_DIR);
        //@ assert L_PACKET:          EqualBits(stream, pos + 8,   pos + 21,  p->L_PACKET);
        //@ assert M_VERSION:         EqualBits(stream, pos + 21,  pos + 28,  p->M_VERSION);

        //@ assert Q_DIR:             UpperBitsNotSet(p->Q_DIR,             2);
        //@ assert L_PACKET:          UpperBitsNotSet(p->L_PACKET,          13);
        //@ assert M_VERSION:         UpperBitsNotSet(p->M_VERSION,         7);

	//@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

