
#include "Stop_Shunting_on_desk_opening_Decoder.h"
#include "Bitwalker_Peek_Normal.h"

int Stop_Shunting_on_desk_opening_Decoder(Bitstream* stream, Stop_Shunting_on_desk_opening* p)
{
    if (NormalBitstream(stream, STOP_SHUNTING_ON_DESK_OPENING_BITSIZE))
    {
        uint8_t* addr = stream->addr;
        const uint32_t size = stream->size;
        const uint32_t pos = stream->bitpos;

        p->Q_DIR              = Bitwalker_Peek_Normal(addr, size, pos,       2);
        p->L_PACKET           = Bitwalker_Peek_Normal(addr, size, pos + 2,   13);

        stream->bitpos += STOP_SHUNTING_ON_DESK_OPENING_BITSIZE;

        //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
        //@ assert L_PACKET:          EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);

        //@ assert Q_DIR:             UpperBitsNotSet(p->Q_DIR,             2);
        //@ assert L_PACKET:          UpperBitsNotSet(p->L_PACKET,          13);

        return 1;
    }
    else
    {
        return 0;
    }
}

