
#include "Stop_Shunting_on_desk_opening_Decoder.h"
#include "Bitwalker_Peek_Normal.h"

int Stop_Shunting_on_desk_opening_Decoder(Bitstream* stream, Stop_Shunting_on_desk_opening* p)
{
    if (NormalBitstream(stream, STOP_SHUNTING_ON_DESK_OPENING_BITSIZE))
    {
        uint8_t* addr = stream->addr;
        const uint32_t size = stream->size;
        const uint32_t pos = stream->bitpos;

        p->NID_PACKET         = Bitwalker_Peek_Normal(addr, size, pos,       8);
        p->Q_DIR              = Bitwalker_Peek_Normal(addr, size, pos + 8,   2);
        p->L_PACKET           = Bitwalker_Peek_Normal(addr, size, pos + 10,  13);

        stream->bitpos += STOP_SHUNTING_ON_DESK_OPENING_BITSIZE;

        //@ assert NID_PACKET:        EqualBits(stream, pos,       pos + 8,   p->NID_PACKET);
        //@ assert Q_DIR:             EqualBits(stream, pos + 8,   pos + 10,  p->Q_DIR);
        //@ assert L_PACKET:          EqualBits(stream, pos + 10,  pos + 23,  p->L_PACKET);

        return 1;
    }
    else
    {
        return 0;
    }
}

