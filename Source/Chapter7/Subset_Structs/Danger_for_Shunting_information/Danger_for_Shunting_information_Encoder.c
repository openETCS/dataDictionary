
#include "Danger_for_Shunting_information_Encoder.h"
#include "Danger_for_Shunting_information_UpperBitsNotSet.h"
#include "Bitwalker_Poke_Normal.h"

int Danger_for_Shunting_information_Encoder(Bitstream* stream, const Danger_for_Shunting_information* p)
{
    if (NormalBitstream(stream, DANGER_FOR_SHUNTING_INFORMATION_BITSIZE))
    {
        if (Danger_for_Shunting_information_UpperBitsNotSet(p))
        {
            uint8_t* addr = stream->addr;
            const uint32_t size = stream->size;
            const uint32_t pos = stream->bitpos;

            Bitwalker_Poke_Normal(addr, size, pos,       8,  p->NID_PACKET);
            Bitwalker_Poke_Normal(addr, size, pos + 8,   2,  p->Q_DIR);
            Bitwalker_Poke_Normal(addr, size, pos + 10,  13, p->L_PACKET);
            Bitwalker_Poke_Normal(addr, size, pos + 23,  1,  p->Q_ASPECT);

            stream->bitpos += DANGER_FOR_SHUNTING_INFORMATION_BITSIZE;

            //@ assert NID_PACKET:        EqualBits(stream, pos,       pos + 8,   p->NID_PACKET);
            //@ assert Q_DIR:             EqualBits(stream, pos + 8,   pos + 10,  p->Q_DIR);
            //@ assert L_PACKET:          EqualBits(stream, pos + 10,  pos + 23,  p->L_PACKET);
            //@ assert Q_ASPECT:          EqualBits(stream, pos + 23,  pos + 24,  p->Q_ASPECT);

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

