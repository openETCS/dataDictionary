
#include "Virtual_Balise_Cover_marker_Decoder.h"
#include "Bitwalker_Peek_Normal.h"

int Virtual_Balise_Cover_marker_Decoder(Bitstream* stream, Virtual_Balise_Cover_marker* p)
{
    if (NormalBitstream(stream, VIRTUAL_BALISE_COVER_MARKER_BITSIZE))
    {
        uint8_t* addr = stream->addr;
        const uint32_t size = stream->size;
        const uint32_t pos = stream->bitpos;

        p->NID_VBCMK          = Bitwalker_Peek_Normal(addr, size, pos,       6);

        stream->bitpos += VIRTUAL_BALISE_COVER_MARKER_BITSIZE;

        //@ assert NID_VBCMK:         EqualBits(stream, pos,       pos + 6,   p->NID_VBCMK);

        //@ assert NID_VBCMK:         UpperBitsNotSet(p->NID_VBCMK,         6);

        return 1;
    }
    else
    {
        return 0;
    }
}

