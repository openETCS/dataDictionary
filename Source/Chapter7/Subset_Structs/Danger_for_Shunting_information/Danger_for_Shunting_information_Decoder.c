
#include "Danger_for_Shunting_information_Decoder.h"
#include "Bitwalker_Peek_Normal.h"

int Danger_for_Shunting_information_Decoder(Bitstream* stream, Danger_for_Shunting_information* p)
{
    if (NormalBitstream(stream, DANGER_FOR_SHUNTING_INFORMATION_BITSIZE))
    {
        uint8_t* addr = stream->addr;
        const uint32_t size = stream->size;
        const uint32_t pos = stream->bitpos;

        p->NID_PACKET         = Bitwalker_Peek_Normal(addr, size, pos,       8);
        p->Q_DIR              = Bitwalker_Peek_Normal(addr, size, pos + 8,   2);
        p->L_PACKET           = Bitwalker_Peek_Normal(addr, size, pos + 10,  13);
        p->Q_ASPECT           = Bitwalker_Peek_Normal(addr, size, pos + 23,  1);

        stream->bitpos += DANGER_FOR_SHUNTING_INFORMATION_BITSIZE;

        //@ assert NID_PACKET:        EqualBits(stream, pos,       pos + 8,   p->NID_PACKET);
        //@ assert Q_DIR:             EqualBits(stream, pos + 8,   pos + 10,  p->Q_DIR);
        //@ assert L_PACKET:          EqualBits(stream, pos + 10,  pos + 23,  p->L_PACKET);
        //@ assert Q_ASPECT:          EqualBits(stream, pos + 23,  pos + 24,  p->Q_ASPECT);

        return 1;
    }
    else
    {
        return 0;
    }
}

