
#include "Stop_Shunting_on_desk_opening_Data_Decoder.h"
#include "Bitwalker_Peek_Normal.h"

int Stop_Shunting_on_desk_opening_Data_Decoder(Bitstream* stream, Stop_Shunting_on_desk_opening_Data* p)
{
    if (NormalBitstream(stream, STOP_SHUNTING_ON_DESK_OPENING_DATA_BITSIZE))
    {
        uint8_t* addr = stream->addr;
        const uint32_t size = stream->size;
        const uint32_t pos = stream->bitpos;

        p->Q_DIR              = Bitwalker_Peek_Normal(addr, size, pos,       2);

        stream->bitpos += STOP_SHUNTING_ON_DESK_OPENING_DATA_BITSIZE;

        //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);

        //@ assert Q_DIR:             UpperBitsNotSet(p->Q_DIR,             2);

        return 1;
    }
    else
    {
        return 0;
    }
}

