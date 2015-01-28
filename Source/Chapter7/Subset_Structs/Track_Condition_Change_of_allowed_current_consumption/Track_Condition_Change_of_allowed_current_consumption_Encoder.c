
#include "Track_Condition_Change_of_allowed_current_consumption_Encoder.h"
#include "Track_Condition_Change_of_allowed_current_consumption_UpperBitsNotSet.h"
#include "Bitwalker_Poke_Normal.h"

int Track_Condition_Change_of_allowed_current_consumption_Encoder(Bitstream* stream, const Track_Condition_Change_of_allowed_current_consumption* p)
{
    if (NormalBitstream(stream, TRACK_CONDITION_CHANGE_OF_ALLOWED_CURRENT_CONSUMPTION_BITSIZE))
    {
        if (Track_Condition_Change_of_allowed_current_consumption_UpperBitsNotSet(p))
        {
            uint8_t* addr = stream->addr;
            const uint32_t size = stream->size;
            const uint32_t pos = stream->bitpos;

            Bitwalker_Poke_Normal(addr, size, pos,       8,  p->NID_PACKET);
            Bitwalker_Poke_Normal(addr, size, pos + 8,   2,  p->Q_DIR);
            Bitwalker_Poke_Normal(addr, size, pos + 10,  13, p->L_PACKET);
            Bitwalker_Poke_Normal(addr, size, pos + 23,  2,  p->Q_SCALE);
            Bitwalker_Poke_Normal(addr, size, pos + 25,  15, p->D_CURRENT);
            Bitwalker_Poke_Normal(addr, size, pos + 40,  10, p->M_CURRENT);

            stream->bitpos += TRACK_CONDITION_CHANGE_OF_ALLOWED_CURRENT_CONSUMPTION_BITSIZE;

            //@ assert NID_PACKET:        EqualBits(stream, pos,       pos + 8,   p->NID_PACKET);
            //@ assert Q_DIR:             EqualBits(stream, pos + 8,   pos + 10,  p->Q_DIR);
            //@ assert L_PACKET:          EqualBits(stream, pos + 10,  pos + 23,  p->L_PACKET);
            //@ assert Q_SCALE:           EqualBits(stream, pos + 23,  pos + 25,  p->Q_SCALE);
            //@ assert D_CURRENT:         EqualBits(stream, pos + 25,  pos + 40,  p->D_CURRENT);
            //@ assert M_CURRENT:         EqualBits(stream, pos + 40,  pos + 50,  p->M_CURRENT);

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

