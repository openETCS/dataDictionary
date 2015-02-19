
#include "TrackToTrain_Header_Decoder.h"
#include "Bitwalker_Peek_Normal.h"

int TrackToTrain_Header_Decoder(Bitstream* stream, TrackToTrain_Header* p)
{
    if (NormalBitstream(stream, TRACKTOTRAIN_HEADER_BITSIZE))
    {
        uint8_t* addr = stream->addr;
        const uint32_t size = stream->size;
        const uint32_t pos = stream->bitpos;

        p->NID_PACKET         = Bitwalker_Peek_Normal(addr, size, pos,       8);
        p->L_PACKET           = Bitwalker_Peek_Normal(addr, size, pos + 10,  13);

        stream->bitpos += TRACKTOTRAIN_HEADER_BITSIZE;

        //@ assert NID_PACKET:        EqualBits(stream, pos,       pos + 8,   p->NID_PACKET);
        //@ assert L_PACKET:          EqualBits(stream, pos + 10,  pos + 23,  p->L_PACKET);

	//@ assert NID_PACKET:        UpperBitsNotSet(p->NID_PACKET,          8);
	//@ assert L_PACKET:          UpperBitsNotSet(p->L_PACKET,            13);

        return 1;
    }
    else
    {
        return 0;
    }
}

