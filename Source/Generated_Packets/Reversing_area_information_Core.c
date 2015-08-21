
#include "Reversing_area_information_Core.h"
#include "UpperBitsNotSet.h"
#include "Bitstream_Write.h"
#include "Bitstream_Read.h"
#include "Bitstream_Normal.h"

int Reversing_area_information_UpperBitsNotSet(const Reversing_area_information_Core* p)
{
    bool status = true;

    status = status && UpperBitsNotSet64(p->Q_DIR,             2) ;
    status = status && UpperBitsNotSet64(p->L_PACKET,          13);
    status = status && UpperBitsNotSet64(p->Q_SCALE,           2) ;
    status = status && UpperBitsNotSet64(p->D_STARTREVERSE,    15);
    status = status && UpperBitsNotSet64(p->L_REVERSEAREA,     15);

    if (status)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int Reversing_area_information_Encoder(Bitstream* stream, const Reversing_area_information_Core* p)
{
    if (Bitstream_Normal(stream, REVERSING_AREA_INFORMATION_CORE_BITSIZE))
    {
        if (Reversing_area_information_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 2,  p->Q_DIR);
            Bitstream_Write(stream, 13, p->L_PACKET);
            Bitstream_Write(stream, 2,  p->Q_SCALE);
            Bitstream_Write(stream, 15, p->D_STARTREVERSE);
            Bitstream_Write(stream, 15, p->L_REVERSEAREA);


            //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
            //@ assert L_PACKET:          EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);
            //@ assert Q_SCALE:           EqualBits(stream, pos + 15,  pos + 17,  p->Q_SCALE);
            //@ assert D_STARTREVERSE:    EqualBits(stream, pos + 17,  pos + 32,  p->D_STARTREVERSE);
            //@ assert L_REVERSEAREA:     EqualBits(stream, pos + 32,  pos + 47,  p->L_REVERSEAREA);

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

int Reversing_area_information_Decoder(Bitstream* stream, Reversing_area_information_Core* p)
{
    if (Bitstream_Normal(stream, REVERSING_AREA_INFORMATION_CORE_BITSIZE))
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
	  requires D_STARTREVERSE: stream->bitpos == pos + 17;
	  assigns        	   stream->bitpos;
	  assigns		   p->D_STARTREVERSE;
	  ensures  D_STARTREVERSE: stream->bitpos == pos + 32;
	  ensures  D_STARTREVERSE: EqualBits(stream, pos + 17, pos + 32, p->D_STARTREVERSE);
	  ensures  D_STARTREVERSE: UpperBitsNotSet(p->D_STARTREVERSE, 15);
	*/
	{ p->D_STARTREVERSE		= Bitstream_Read(stream, 15); }

	/*@
	  requires L_REVERSEAREA:  stream->bitpos == pos + 32;
	  assigns        	   stream->bitpos;
	  assigns		   p->L_REVERSEAREA;
	  ensures  L_REVERSEAREA:  stream->bitpos == pos + 47;
	  ensures  L_REVERSEAREA:  EqualBits(stream, pos + 32, pos + 47, p->L_REVERSEAREA);
	  ensures  L_REVERSEAREA:  UpperBitsNotSet(p->L_REVERSEAREA, 15);
	*/
	{ p->L_REVERSEAREA		= Bitstream_Read(stream, 15); }

        //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
        //@ assert L_PACKET:          EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);
        //@ assert Q_SCALE:           EqualBits(stream, pos + 15,  pos + 17,  p->Q_SCALE);
        //@ assert D_STARTREVERSE:    EqualBits(stream, pos + 17,  pos + 32,  p->D_STARTREVERSE);
        //@ assert L_REVERSEAREA:     EqualBits(stream, pos + 32,  pos + 47,  p->L_REVERSEAREA);

        //@ assert Q_DIR:             UpperBitsNotSet(p->Q_DIR,             2);
        //@ assert L_PACKET:          UpperBitsNotSet(p->L_PACKET,          13);
        //@ assert Q_SCALE:           UpperBitsNotSet(p->Q_SCALE,           2);
        //@ assert D_STARTREVERSE:    UpperBitsNotSet(p->D_STARTREVERSE,    15);
        //@ assert L_REVERSEAREA:     UpperBitsNotSet(p->L_REVERSEAREA,     15);

	//@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

