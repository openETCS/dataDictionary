
#include "Stop_Shunting_on_desk_opening_Encoder.h"
#include "Stop_Shunting_on_desk_opening_UpperBitsNotSet.h"
#include "Bitstream_Write.h"

int Stop_Shunting_on_desk_opening_Encoder(Bitstream* stream, const Stop_Shunting_on_desk_opening_Core* p)
{
    if (NormalBitstream(stream, STOP_SHUNTING_ON_DESK_OPENING_CORE_BITSIZE))
    {
        if (Stop_Shunting_on_desk_opening_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 2,  p->Q_DIR);
            Bitstream_Write(stream, 13, p->L_PACKET);


            //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
            //@ assert L_PACKET:          EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);

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

