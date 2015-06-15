
#include "Gradient_Profile_Decoder.h"
#include "Gradient_Profile_1_Decoder.h"
#include "Bitstream_Read.h"

int Gradient_Profile_Decoder(Bitstream* stream, Gradient_Profile_Core* p)
{
    if (NormalBitstream(stream, GRADIENT_PROFILE_CORE_BITSIZE))
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
	  requires D_GRADIENT:        stream->bitpos == pos + 17;
	  assigns        	      stream->bitpos;
	  assigns		      p->D_GRADIENT;
	  ensures  D_GRADIENT:        stream->bitpos == pos + 32;
	  ensures  D_GRADIENT:        EqualBits(stream, pos + 17, pos + 32, p->D_GRADIENT);
	  ensures  D_GRADIENT:        UpperBitsNotSet(p->D_GRADIENT, 15);
	*/
	{ p->D_GRADIENT		= Bitstream_Read(stream, 15); }

	/*@
	  requires Q_GDIR:        stream->bitpos == pos + 32;
	  assigns       	  stream->bitpos;
	  assigns		  p->Q_GDIR;
	  ensures  Q_GDIR:        stream->bitpos == pos + 33;
	  ensures  Q_GDIR:        EqualBits(stream, pos + 32, pos + 33, p->Q_GDIR);
	  ensures  Q_GDIR:        UpperBitsNotSet(p->Q_GDIR, 1);
	*/
	{ p->Q_GDIR		= Bitstream_Read(stream, 1); }

	/*@
	  requires G_A:        stream->bitpos == pos + 33;
	  assigns              stream->bitpos;
	  assigns              p->G_A;
	  ensures  G_A:        stream->bitpos == pos + 41;
	  ensures  G_A:        EqualBits(stream, pos + 33, pos + 41, p->G_A);
	  ensures  G_A:        UpperBitsNotSet(p->G_A, 8);
	*/
	{ p->G_A		= Bitstream_Read(stream, 8); }
	
	/*@
	  requires N_ITER:        stream->bitpos == pos + 41;
	  assigns              stream->bitpos;
	  assigns              p->N_ITER;
	  ensures  N_ITER:        stream->bitpos == pos + 46;
	  ensures  N_ITER:        EqualBits(stream, pos + 41, pos + 46, p->N_ITER);
	  ensures  N_ITER:        UpperBitsNotSet(p->N_ITER, 5);
	*/
	{ p->N_ITER		= Bitstream_Read(stream, 5); }

	{ Gradient_Profile_1_Decoder(stream, &(p->GRADIENT_PROFILE_1), p->N_ITER); }

        //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
        //@ assert L_PACKET:          EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);
        //@ assert Q_SCALE:           EqualBits(stream, pos + 15,  pos + 17,  p->Q_SCALE);
	//@ assert D_GRADIENT:        EqualBits(stream, pos + 17,  pos + 32,  p->D_GRADIENT);
	//@ assert Q_GDIR:            EqualBits(stream, pos + 32,  pos + 33,  p->Q_GDIR);
	//@ assert G_A:               EqualBits(stream, pos + 33,  pos + 41,  p->G_A);
	//@ assert N_ITER:            EqualBits(stream, pos + 41,  pos + 46,  p->N_ITER);

        //@ assert Q_DIR:             UpperBitsNotSet(p->Q_DIR,             2);
        //@ assert L_PACKET:          UpperBitsNotSet(p->L_PACKET,          13);
        //@ assert Q_SCALE:           UpperBitsNotSet(p->Q_SCALE,           2);
	//@ assert D_GRADIENT:        UpperBitsNotSet(p->D_GRADIENT,        15);
	//@ assert Q_GDIR:            UpperBitsNotSet(p->Q_GDIR,            1);
	//@ assert G_A:               UpperBitsNotSet(p->G_A,               8);
	//@ assert N_ITER:            UpperBitsNotSet(p->N_ITER,            5);

	//@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

