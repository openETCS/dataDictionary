
#include "Header_Decoder.h"
#include "Bitwalker_Peek_Normal.h"

int Header_Decoder(Bitstream* stream, Header* p)
{
    if (NormalBitstream(stream, HEADER_BITSIZE))
    {
        uint8_t* addr = stream->addr;
        const uint32_t size = stream->size;
        const uint32_t pos = stream->bitpos;

        p->NID_PACKET         = Bitwalker_Peek_Normal(addr, size, pos,       8);

        stream->bitpos += HEADER_BITSIZE;

        //@ assert NID_PACKET:        EqualBits(stream, pos,       pos + 8,   p->NID_PACKET);

	//@ assert NID_PACKET:        UpperBitsNotSet(p->NID_PACKET,        8);

        return 1;
    }
    else
    {
        return 0;
    }
}

