
#include "Virtual_Balise_Cover_marker_Data_Encoder.h"
#include "Virtual_Balise_Cover_marker_Data_UpperBitsNotSet.h"
#include "Bitwalker_Poke_Normal.h"

int Virtual_Balise_Cover_marker_Data_Encoder(Bitstream* stream, const Virtual_Balise_Cover_marker_Data* p)
{
    if (NormalBitstream(stream, VIRTUAL_BALISE_COVER_MARKER_DATA_BITSIZE))
    {
        if (Virtual_Balise_Cover_marker_Data_UpperBitsNotSet(p))
        {
            uint8_t* addr = stream->addr;
            const uint32_t size = stream->size;
            const uint32_t pos = stream->bitpos;

            Bitwalker_Poke_Normal(addr, size, pos,       6,  p->NID_VBCMK);

            stream->bitpos += VIRTUAL_BALISE_COVER_MARKER_DATA_BITSIZE;

            //@ assert NID_VBCMK:         EqualBits(stream, pos,       pos + 6,   p->NID_VBCMK);

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

