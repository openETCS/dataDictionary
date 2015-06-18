
#include "Level_Crossing_information_Decoder.h"
#include "Bitstream_Read.h"

int Level_Crossing_information_Decoder(Bitstream* stream, Level_Crossing_information_Core* p)
{
    if (NormalBitstream(stream, LEVEL_CROSSING_INFORMATION_CORE_BITSIZE))
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
	  requires Q_SCALE:        stream->bitpos == pos + 15;
	  assigns        	   stream->bitpos;
	  assigns		   p->Q_SCALE;
	  ensures  Q_SCALE:        stream->bitpos == pos + 17;
	  ensures  Q_SCALE:        EqualBits(stream, pos + 15, pos + 17, p->Q_SCALE);
	  ensures  Q_SCALE:        UpperBitsNotSet(p->Q_SCALE, 2);
	*/
	{ p->Q_SCALE		= Bitstream_Read(stream, 2); }

	/*@
	  requires NID_LX:         stream->bitpos == pos + 17;
	  assigns        	   stream->bitpos;
	  assigns		   p->NID_LX;
	  ensures  NID_LX:         stream->bitpos == pos + 25;
	  ensures  NID_LX:         EqualBits(stream, pos + 17, pos + 25, p->NID_LX);
	  ensures  NID_LX:         UpperBitsNotSet(p->NID_LX, 8);
	*/
	{ p->NID_LX		= Bitstream_Read(stream, 8); }

	/*@
	  requires D_LX:           stream->bitpos == pos + 25;
	  assigns        	   stream->bitpos;
	  assigns		   p->D_LX;
	  ensures  D_LX:           stream->bitpos == pos + 40;
	  ensures  D_LX:           EqualBits(stream, pos + 25, pos + 40, p->D_LX);
	  ensures  D_LX:           UpperBitsNotSet(p->D_LX, 15);
	*/
	{ p->D_LX		= Bitstream_Read(stream, 15); }

	/*@
	  requires L_LX:           stream->bitpos == pos + 40;
	  assigns        	   stream->bitpos;
	  assigns		   p->L_LX;
	  ensures  L_LX:           stream->bitpos == pos + 55;
	  ensures  L_LX:           EqualBits(stream, pos + 40, pos + 55, p->L_LX);
	  ensures  L_LX:           UpperBitsNotSet(p->L_LX, 15);
	*/
	{ p->L_LX		= Bitstream_Read(stream, 15); }

	/*@
	  requires Q_LXSTATUS:     stream->bitpos == pos + 55;
	  assigns        	   stream->bitpos;
	  assigns		   p->Q_LXSTATUS;
	  ensures  Q_LXSTATUS:     stream->bitpos == pos + 56;
	  ensures  Q_LXSTATUS:     EqualBits(stream, pos + 55, pos + 56, p->Q_LXSTATUS);
	  ensures  Q_LXSTATUS:     UpperBitsNotSet(p->Q_LXSTATUS, 1);
	*/
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

        //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
        //@ assert L_PACKET:          EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);
        //@ assert Q_SCALE:           EqualBits(stream, pos + 15,  pos + 17,  p->Q_SCALE);
        //@ assert NID_LX:            EqualBits(stream, pos + 17,  pos + 25,  p->NID_LX);
        //@ assert D_LX:              EqualBits(stream, pos + 25,  pos + 40,  p->D_LX);
        //@ assert L_LX:              EqualBits(stream, pos + 40,  pos + 55,  p->L_LX);
        //@ assert Q_LXSTATUS:        EqualBits(stream, pos + 55,  pos + 56,  p->Q_LXSTATUS);

        //@ assert Q_DIR:             UpperBitsNotSet(p->Q_DIR,             2);
        //@ assert L_PACKET:          UpperBitsNotSet(p->L_PACKET,          13);
        //@ assert Q_SCALE:           UpperBitsNotSet(p->Q_SCALE,           2);
        //@ assert NID_LX:            UpperBitsNotSet(p->NID_LX,            8);
        //@ assert D_LX:              UpperBitsNotSet(p->D_LX,              15);
        //@ assert L_LX:              UpperBitsNotSet(p->L_LX,              15);
        //@ assert Q_LXSTATUS:        UpperBitsNotSet(p->Q_LXSTATUS,        1);

	//@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

