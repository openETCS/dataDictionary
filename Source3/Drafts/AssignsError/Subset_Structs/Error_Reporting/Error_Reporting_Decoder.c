
#include "Error_Reporting_Decoder.h"
#include "Bitstream_Read.h"

int Error_Reporting_Decoder(Bitstream* stream, Error_Reporting* p)
{
    if (NormalBitstream(stream, ERROR_REPORTING_BITSIZE))
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
	  requires M_ERROR:        stream->bitpos == pos + 13;
	  assigns        	   stream->bitpos;
	  assigns		   p->M_ERROR;
	  ensures  M_ERROR:        stream->bitpos == pos + 21;
	  ensures  M_ERROR:        EqualBits(stream, pos + 13, pos + 21, p->M_ERROR);
	  ensures  M_ERROR:        UpperBitsNotSet(p->M_ERROR, 8);
	*/
	{ p->M_ERROR		= Bitstream_Read(stream, 8); }



        //@ assert L_PACKET:          EqualBits(stream, pos,       pos + 13,  p->L_PACKET);
        //@ assert M_ERROR:           EqualBits(stream, pos + 13,  pos + 21,  p->M_ERROR);

        //@ assert L_PACKET:          UpperBitsNotSet(p->L_PACKET,          13);
        //@ assert M_ERROR:           UpperBitsNotSet(p->M_ERROR,           8);

	//@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

