
#include "Level_23_transition_information_Decoder.h"
#include "Bitstream_Read.h"

int Level_23_transition_information_Decoder(Bitstream* stream, Level_23_transition_information* p)
{
    if (NormalBitstream(stream, LEVEL_23_TRANSITION_INFORMATION_BITSIZE))
    {
        uint8_t* addr = stream->addr;
        const uint32_t size = stream->size;
        const uint32_t pos = stream->bitpos;

	/*@
	  requires L_PACKET:       stream->bitpos == pos + 0;
	  assigns        	   stream->bitpos;
	  assigns		   p->L_PACKET;
	  ensures  L_PACKET:       stream->bitpos == pos + 13;
	  ensures  L_PACKET:       EqualBits(stream, pos + 0, pos + 13, p->L_PACKET);
	  ensures  L_PACKET:       UpperBitsNotSet(p->L_PACKET, 13);
	*/
	{ p->L_PACKET		= Bitstream_Read(stream, 13); }

	/*@
	  requires NID_LTRBG:      stream->bitpos == pos + 13;
	  assigns        	   stream->bitpos;
	  assigns		   p->NID_LTRBG;
	  ensures  NID_LTRBG:      stream->bitpos == pos + 37;
	  ensures  NID_LTRBG:      EqualBits(stream, pos + 13, pos + 37, p->NID_LTRBG);
	  ensures  NID_LTRBG:      UpperBitsNotSet(p->NID_LTRBG, 24);
	*/
	{ p->NID_LTRBG		= Bitstream_Read(stream, 24); }



        //@ assert L_PACKET:          EqualBits(stream, pos,       pos + 13,  p->L_PACKET);
        //@ assert NID_LTRBG:         EqualBits(stream, pos + 13,  pos + 37,  p->NID_LTRBG);

        //@ assert L_PACKET:          UpperBitsNotSet(p->L_PACKET,          13);
        //@ assert NID_LTRBG:         UpperBitsNotSet(p->NID_LTRBG,         24);

	//@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

