
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
        p->Q_DIR              = Bitwalker_Peek_Normal(addr, size, pos + 8,   10);
        p->L_PACKET           = Bitwalker_Peek_Normal(addr, size, pos + 10,  23);

        stream->bitpos += TRACKTOTRAIN_HEADER_BITSIZE;

        //@ assert NID_PACKET:        EqualBits(stream, pos,       pos + 2,   p->NID_PACKET);
        //@ assert Q_DIR:             EqualBits(stream, pos + 2,   pos + 17,  p->Q_DIR);
        //@ assert L_PACKET:          EqualBits(stream, pos + 17,  pos + 32,  p->L_PACKET);

        return 1;
    }
    else
    {
        return 0;
    }
}

