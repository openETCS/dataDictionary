
#include "System_Version_order_Decoder.h"
#include "Bitstream_Read.h"

int System_Version_order_Decoder(Bitstream* stream, System_Version_order* p)
{
    if (NormalBitstream(stream, SYSTEM_VERSION_ORDER_BITSIZE))
    {
        uint8_t* addr = stream->addr;
        const uint32_t size = stream->size;
        const uint32_t pos = stream->bitpos;

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
	  requires M_VERSION:      stream->bitpos == pos + 15;
	  assigns        	   stream->bitpos;
	  assigns		   p->M_VERSION;
	  ensures  M_VERSION:      stream->bitpos == pos + 22;
	  ensures  M_VERSION:      EqualBits(stream, pos + 15, pos + 22, p->M_VERSION);
	  ensures  M_VERSION:      UpperBitsNotSet(p->M_VERSION, 7);
	*/
	{ p->M_VERSION		= Bitstream_Read(stream, 7); }



        //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
        //@ assert L_PACKET:          EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);
        //@ assert M_VERSION:         EqualBits(stream, pos + 15,  pos + 22,  p->M_VERSION);

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

