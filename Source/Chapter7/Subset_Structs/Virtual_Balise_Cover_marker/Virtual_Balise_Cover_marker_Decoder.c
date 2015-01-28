
#include "Virtual_Balise_Cover_marker_Decoder.h"
#include "Bitwalker_Peek_Normal.h"

int Virtual_Balise_Cover_marker_Decoder(Bitstream* stream, Virtual_Balise_Cover_marker* p)
{
    if (NormalBitstream(stream, VIRTUAL_BALISE_COVER_MARKER_BITSIZE))
    {
        uint8_t* addr = stream->addr;
        const uint32_t size = stream->size;
        const uint32_t pos = stream->bitpos;

        p->NID_PACKET         = Bitwalker_Peek_Normal(addr, size, pos,       8);
        p->NID_VBCMK          = Bitwalker_Peek_Normal(addr, size, pos + 8,   6);

        stream->bitpos += VIRTUAL_BALISE_COVER_MARKER_BITSIZE;

        //@ assert NID_PACKET:        EqualBits(stream, pos,       pos + 8,   p->NID_PACKET);
        //@ assert NID_VBCMK:         EqualBits(stream, pos + 8,   pos + 14,  p->NID_VBCMK);

        return 1;
    }
    else
    {
        return 0;
    }
}

