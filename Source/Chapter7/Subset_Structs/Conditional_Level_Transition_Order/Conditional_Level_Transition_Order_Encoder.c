
#include "Conditional_Level_Transition_Order_Encoder.h"
#include "Conditional_Level_Transition_Order_UpperBitsNotSet.h"
#include "Bitwalker_Poke_Normal.h"

int Conditional_Level_Transition_Order_Encoder(Bitstream* stream, const Conditional_Level_Transition_Order* p)
{
    if (NormalBitstream(stream, CONDITIONAL_LEVEL_TRANSITION_ORDER_BITSIZE))
    {
        if (Conditional_Level_Transition_Order_UpperBitsNotSet(p))
        {
            uint8_t* addr = stream->addr;
            const uint32_t size = stream->size;
            const uint32_t pos = stream->bitpos;

            Bitwalker_Poke_Normal(addr, size, pos,       8,  p->NID_PACKET);
            Bitwalker_Poke_Normal(addr, size, pos + 8,   2,  p->Q_DIR);
            Bitwalker_Poke_Normal(addr, size, pos + 10,  13, p->L_PACKET);
            Bitwalker_Poke_Normal(addr, size, pos + 23,  3,  p->M_LEVELTR);
            Bitwalker_Poke_Normal(addr, size, pos + 26,  8,  p->NID_NTC);
            Bitwalker_Poke_Normal(addr, size, pos + 34,  5,  p->N_ITER);
            Bitwalker_Poke_Normal(addr, size, pos + 39,  3,  p->M_LEVELTR(k));
            Bitwalker_Poke_Normal(addr, size, pos + 42,  8,  p->NID_NTC(k));

            stream->bitpos += CONDITIONAL_LEVEL_TRANSITION_ORDER_BITSIZE;

            //@ assert NID_PACKET:        EqualBits(stream, pos,       pos + 8,   p->NID_PACKET);
            //@ assert Q_DIR:             EqualBits(stream, pos + 8,   pos + 10,  p->Q_DIR);
            //@ assert L_PACKET:          EqualBits(stream, pos + 10,  pos + 23,  p->L_PACKET);
            //@ assert M_LEVELTR:         EqualBits(stream, pos + 23,  pos + 26,  p->M_LEVELTR);
            //@ assert NID_NTC:           EqualBits(stream, pos + 26,  pos + 34,  p->NID_NTC);
            //@ assert N_ITER:            EqualBits(stream, pos + 34,  pos + 39,  p->N_ITER);
            //@ assert M_LEVELTR(k):      EqualBits(stream, pos + 39,  pos + 42,  p->M_LEVELTR(k));
            //@ assert NID_NTC(k):        EqualBits(stream, pos + 42,  pos + 50,  p->NID_NTC(k));

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

