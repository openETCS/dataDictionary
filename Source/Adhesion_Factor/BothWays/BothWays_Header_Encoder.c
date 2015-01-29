
#include "BothWays_Header_Encoder.h"
#include "BothWays_Header_UpperBitsNotSet.h"
#include "Bitwalker_Poke_Normal.h"

int BothWays_Header_Encoder(Bitstream* stream, const BothWays_Header* p)
{
    if (NormalBitstream(stream, BOTHWAYS_HEADER_BITSIZE))
    {
        if (BothWays_Header_UpperBitsNotSet(p))
        {
            uint8_t* addr = stream->addr;
            const uint32_t size = stream->size;
            const uint32_t pos = stream->bitpos;

            Bitwalker_Poke_Normal(addr, size, pos,  	 8,  p->NID_PACKET);

            stream->bitpos += BOTHWAYS_HEADER_BITSIZE;

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

