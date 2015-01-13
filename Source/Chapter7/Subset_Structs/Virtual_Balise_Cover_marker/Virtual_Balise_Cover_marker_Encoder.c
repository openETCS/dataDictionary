
#include "Virtual_Balise_Cover_marker_Encoder.h"
#include "Virtual_Balise_Cover_marker_UpperBitsNotSet.h"
#include "Bitwalker_Poke_Normal.h"

int Virtual_Balise_Cover_marker_Encoder(Bitstream* stream, const Virtual_Balise_Cover_marker* p)
{
    if (NormalBitstream(stream, VIRTUAL_BALISE_COVER_MARKER_BITSIZE))
    {
        if (Virtual_Balise_Cover_marker_UpperBitsNotSet(p))
        {
            uint8_t* addr = stream->addr;
            const uint32_t size = stream->size;
            const uint32_t pos = stream->bitpos;

            Bitwalker_Poke_Normal(addr, size, pos,       8,  p->NID_PACKET);
            Bitwalker_Poke_Normal(addr, size, pos + 8,   6,  p->NID_VBCMK);

            stream->bitpos += VIRTUAL_BALISE_COVER_MARKER_BITSIZE;

            //@ assert NID_PACKET:        EqualBits(stream, pos,       pos + 8,   p->NID_PACKET);
            //@ assert NID_VBCMK:         EqualBits(stream, pos + 8,   pos + 14,  p->NID_VBCMK);

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

