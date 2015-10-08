
#include "Virtual_Balise_Cover_marker_Encoder.h"
#include "Virtual_Balise_Cover_marker_UpperBitsNotSet.h"
#include "Bitstream_Write.h"

int Virtual_Balise_Cover_marker_Encoder(Bitstream* stream, const Virtual_Balise_Cover_marker* p)
{
    if (NormalBitstream(stream, VIRTUAL_BALISE_COVER_MARKER_BITSIZE))
    {
        if (Virtual_Balise_Cover_marker_UpperBitsNotSet(p))
        {
            uint8_t* addr = stream->addr;
            const uint32_t size = stream->size;
            const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 6,  p->NID_VBCMK);


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

