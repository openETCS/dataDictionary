
#include "Train_running_number_from_RBC_Decoder.h"
#include "Bitstream_Read.h"

int Train_running_number_from_RBC_Decoder(Bitstream* stream, Train_running_number_from_RBC* p)
{
    if (NormalBitstream(stream, TRAIN_RUNNING_NUMBER_FROM_RBC_BITSIZE))
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
	  requires NID_OPERATIONAL: stream->bitpos == pos + 15;
	  assigns        	   stream->bitpos;
	  assigns		   p->NID_OPERATIONAL;
	  ensures  NID_OPERATIONAL: stream->bitpos == pos + 47;
	  ensures  NID_OPERATIONAL: EqualBits(stream, pos + 15, pos + 47, p->NID_OPERATIONAL);
	  ensures  NID_OPERATIONAL: UpperBitsNotSet(p->NID_OPERATIONAL, 32);
	*/
	{ p->NID_OPERATIONAL		= Bitstream_Read(stream, 32); }



        //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
        //@ assert L_PACKET:          EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);
        //@ assert NID_OPERATIONAL:   EqualBits(stream, pos + 15,  pos + 47,  p->NID_OPERATIONAL);

        //@ assert Q_DIR:             UpperBitsNotSet(p->Q_DIR,             2);
        //@ assert L_PACKET:          UpperBitsNotSet(p->L_PACKET,          13);
        //@ assert NID_OPERATIONAL:   UpperBitsNotSet(p->NID_OPERATIONAL,   32);

	//@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

