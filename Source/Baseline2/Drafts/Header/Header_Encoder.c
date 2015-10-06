
#include "Header_Encoder.h"
#include "Header_UpperBitsNotSet.h"
#include "Bitwalker_Poke_Normal.h"

int Header_Encoder(Bitstream* stream, const Header* p)
{
    if (NormalBitstream(stream, HEADER_BITSIZE))
    {
        if (Header_UpperBitsNotSet(p))
        {
            uint8_t* addr = stream->addr;
            const uint32_t size = stream->size;
            const uint32_t pos = stream->bitpos;

            Bitwalker_Poke_Normal(addr, size, pos,  	 8,  p->NID_PACKET);

            stream->bitpos += HEADER_BITSIZE;

            //@ assert NID_PACKET:           EqualBits(stream, pos,       pos + 8,  p->NID_PACKET);

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

