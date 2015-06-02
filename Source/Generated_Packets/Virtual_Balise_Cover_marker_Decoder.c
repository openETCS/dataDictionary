
#include "Virtual_Balise_Cover_marker_Decoder.h"
#include "Bitstream_Read.h"

int Virtual_Balise_Cover_marker_Decoder(Bitstream* stream, Virtual_Balise_Cover_marker_Core* p)
{
    if (NormalBitstream(stream, VIRTUAL_BALISE_COVER_MARKER_CORE_BITSIZE))
    {
        uint8_t* addr = stream->addr;
        const uint32_t size = stream->size;
        const uint32_t pos = stream->bitpos;

	/*@
	  requires NID_VBCMK:      stream->bitpos == pos + 0;
	  assigns        	   stream->bitpos;
	  assigns		   p->NID_VBCMK;
	  ensures  NID_VBCMK:      stream->bitpos == pos + 6;
	  ensures  NID_VBCMK:      EqualBits(stream, pos + 0, pos + 6, p->NID_VBCMK);
	  ensures  NID_VBCMK:      UpperBitsNotSet(p->NID_VBCMK, 6);
	*/
	{ p->NID_VBCMK		= Bitstream_Read(stream, 6); }

        //@ assert NID_VBCMK:         EqualBits(stream, pos,       pos + 6,   p->NID_VBCMK);

        //@ assert NID_VBCMK:         UpperBitsNotSet(p->NID_VBCMK,         6);

	//@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

