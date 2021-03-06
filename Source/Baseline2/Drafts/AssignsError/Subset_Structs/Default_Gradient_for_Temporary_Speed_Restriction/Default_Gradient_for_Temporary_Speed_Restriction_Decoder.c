
#include "Default_Gradient_for_Temporary_Speed_Restriction_Decoder.h"
#include "Bitstream_Read.h"

int Default_Gradient_for_Temporary_Speed_Restriction_Decoder(Bitstream* stream, Default_Gradient_for_Temporary_Speed_Restriction* p)
{
    if (NormalBitstream(stream, DEFAULT_GRADIENT_FOR_TEMPORARY_SPEED_RESTRICTION_BITSIZE))
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
	  requires Q_GDIR:         stream->bitpos == pos + 15;
	  assigns        	   stream->bitpos;
	  assigns		   p->Q_GDIR;
	  ensures  Q_GDIR:         stream->bitpos == pos + 16;
	  ensures  Q_GDIR:         EqualBits(stream, pos + 15, pos + 16, p->Q_GDIR);
	  ensures  Q_GDIR:         UpperBitsNotSet(p->Q_GDIR, 1);
	*/
	{ p->Q_GDIR		= Bitstream_Read(stream, 1); }

	/*@
	  requires G_TSR:          stream->bitpos == pos + 16;
	  assigns        	   stream->bitpos;
	  assigns		   p->G_TSR;
	  ensures  G_TSR:          stream->bitpos == pos + 24;
	  ensures  G_TSR:          EqualBits(stream, pos + 16, pos + 24, p->G_TSR);
	  ensures  G_TSR:          UpperBitsNotSet(p->G_TSR, 8);
	*/
	{ p->G_TSR		= Bitstream_Read(stream, 8); }



        //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
        //@ assert L_PACKET:          EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);
        //@ assert Q_GDIR:            EqualBits(stream, pos + 15,  pos + 16,  p->Q_GDIR);
        //@ assert G_TSR:             EqualBits(stream, pos + 16,  pos + 24,  p->G_TSR);

        //@ assert Q_DIR:             UpperBitsNotSet(p->Q_DIR,             2);
        //@ assert L_PACKET:          UpperBitsNotSet(p->L_PACKET,          13);
        //@ assert Q_GDIR:            UpperBitsNotSet(p->Q_GDIR,            1);
        //@ assert G_TSR:             UpperBitsNotSet(p->G_TSR,             8);

	//@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

