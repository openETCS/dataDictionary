
#include "Stop_Shunting_on_desk_opening_Data_Encoder.h"
#include "Stop_Shunting_on_desk_opening_Data_UpperBitsNotSet.h"
#include "Bitwalker_Poke_Normal.h"

int Stop_Shunting_on_desk_opening_Data_Encoder(Bitstream* stream, const Stop_Shunting_on_desk_opening_Data* p)
{
    if (NormalBitstream(stream, STOP_SHUNTING_ON_DESK_OPENING_DATA_BITSIZE))
    {
        if (Stop_Shunting_on_desk_opening_Data_UpperBitsNotSet(p))
        {
            uint8_t* addr = stream->addr;
            const uint32_t size = stream->size;
            const uint32_t pos = stream->bitpos;

            Bitwalker_Poke_Normal(addr, size, pos,       2,  p->Q_DIR);

            stream->bitpos += STOP_SHUNTING_ON_DESK_OPENING_DATA_BITSIZE;

            //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);

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

