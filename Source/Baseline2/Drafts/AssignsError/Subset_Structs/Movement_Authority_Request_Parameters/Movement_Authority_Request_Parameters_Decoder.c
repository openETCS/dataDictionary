
#include "Movement_Authority_Request_Parameters_Decoder.h"
#include "Bitstream_Read.h"

int Movement_Authority_Request_Parameters_Decoder(Bitstream* stream, Movement_Authority_Request_Parameters* p)
{
    if (NormalBitstream(stream, MOVEMENT_AUTHORITY_REQUEST_PARAMETERS_BITSIZE))
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
	  requires T_MAR:          stream->bitpos == pos + 15;
	  assigns        	   stream->bitpos;
	  assigns		   p->T_MAR;
	  ensures  T_MAR:          stream->bitpos == pos + 23;
	  ensures  T_MAR:          EqualBits(stream, pos + 15, pos + 23, p->T_MAR);
	  ensures  T_MAR:          UpperBitsNotSet(p->T_MAR, 8);
	*/
	{ p->T_MAR		= Bitstream_Read(stream, 8); }

	/*@
	  requires T_TIMEOUTRQST:  stream->bitpos == pos + 23;
	  assigns        	   stream->bitpos;
	  assigns		   p->T_TIMEOUTRQST;
	  ensures  T_TIMEOUTRQST:  stream->bitpos == pos + 33;
	  ensures  T_TIMEOUTRQST:  EqualBits(stream, pos + 23, pos + 33, p->T_TIMEOUTRQST);
	  ensures  T_TIMEOUTRQST:  UpperBitsNotSet(p->T_TIMEOUTRQST, 10);
	*/
	{ p->T_TIMEOUTRQST		= Bitstream_Read(stream, 10); }

	/*@
	  requires T_CYCRQST:      stream->bitpos == pos + 33;
	  assigns        	   stream->bitpos;
	  assigns		   p->T_CYCRQST;
	  ensures  T_CYCRQST:      stream->bitpos == pos + 41;
	  ensures  T_CYCRQST:      EqualBits(stream, pos + 33, pos + 41, p->T_CYCRQST);
	  ensures  T_CYCRQST:      UpperBitsNotSet(p->T_CYCRQST, 8);
	*/
	{ p->T_CYCRQST		= Bitstream_Read(stream, 8); }



        //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
        //@ assert L_PACKET:          EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);
        //@ assert T_MAR:             EqualBits(stream, pos + 15,  pos + 23,  p->T_MAR);
        //@ assert T_TIMEOUTRQST:     EqualBits(stream, pos + 23,  pos + 33,  p->T_TIMEOUTRQST);
        //@ assert T_CYCRQST:         EqualBits(stream, pos + 33,  pos + 41,  p->T_CYCRQST);

        //@ assert Q_DIR:             UpperBitsNotSet(p->Q_DIR,             2);
        //@ assert L_PACKET:          UpperBitsNotSet(p->L_PACKET,          13);
        //@ assert T_MAR:             UpperBitsNotSet(p->T_MAR,             8);
        //@ assert T_TIMEOUTRQST:     UpperBitsNotSet(p->T_TIMEOUTRQST,     10);
        //@ assert T_CYCRQST:         UpperBitsNotSet(p->T_CYCRQST,         8);

	//@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

