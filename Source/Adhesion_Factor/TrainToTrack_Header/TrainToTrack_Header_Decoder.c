
#include "TrainToTrack_Header_Decoder.h"
#include "Bitwalker_Peek_Normal.h"

int TrainToTrack_Header_Decoder(Bitstream* stream, TrainToTrack_Header* p)
{
    if (NormalBitstream(stream, TRAINTOTRACK_HEADER_BITSIZE))
    {
        uint8_t* addr = stream->addr;
        const uint32_t size = stream->size;
        const uint32_t pos = stream->bitpos;

        p->NID_PACKET         = Bitwalker_Peek_Normal(addr, size, pos,       8);
        p->L_PACKET           = Bitwalker_Peek_Normal(addr, size, pos + 8,   21);

        stream->bitpos += TRAINTOTRACK_HEADER_BITSIZE;

        //@ assert NID_PACKET:        EqualBits(stream, pos,       pos + 8,   p->NID_PACKET);
        //@ assert L_PACKET:          EqualBits(stream, pos + 8,   pos + 21,  p->L_PACKET);

        return 1;
    }
    else
    {
        return 0;
    }
}

