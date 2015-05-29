
#include "Packet_Header_Encoder.h"
#include "Packet_Header_UpperBitsNotSet.h"
#include "Bitwalker_Poke_Normal.h"

int Packet_Header_Encoder(Bitstream* stream, const Packet_Header* p)
{
    if (NormalBitstream(stream, PACKET_HEADER_BITSIZE))
    {
        if (Packet_Header_UpperBitsNotSet(p))
        {
            uint8_t* addr = stream->addr;
            const uint32_t size = stream->size;
            const uint32_t pos = stream->bitpos;

            Bitwalker_Poke_Normal(addr, size, pos,  	 8,  p->NID_PACKET);

            stream->bitpos += PACKET_HEADER_BITSIZE;

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
