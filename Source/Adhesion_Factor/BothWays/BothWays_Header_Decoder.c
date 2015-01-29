
#include "BothWays_Header_Decoder.h"
#include "Bitwalker_Peek_Normal.h"

int BothWays_Header_Decoder(Bitstream* stream, BothWays_Header* p)
{
    if (NormalBitstream(stream, BOTHWAYS_HEADER_BITSIZE))
    {
        uint8_t* addr = stream->addr;
        const uint32_t size = stream->size;
        const uint32_t pos = stream->bitpos;

        p->NID_PACKET         = Bitwalker_Peek_Normal(addr, size, pos,       8);

        stream->bitpos += BOTHWAYS_HEADER_BITSIZE;

        //@ assert NID_PACKET:        EqualBits(stream, pos,       pos + 8,   p->NID_PACKET);

        return 1;
    }
    else
    {
        return 0;
    }
}

