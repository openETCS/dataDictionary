
#include "Level_Transition_Order_Encoder.h"
#include "Level_Transition_Order_UpperBitsNotSet.h"
#include "Bitwalker_Poke_Normal.h"

int Level_Transition_Order_Encoder(Bitstream* stream, const Level_Transition_Order* p)
{
    if (NormalBitstream(stream, LEVEL_TRANSITION_ORDER_BITSIZE))
    {
        if (Level_Transition_Order_UpperBitsNotSet(p))
        {
            uint8_t* addr = stream->addr;
            const uint32_t size = stream->size;
            const uint32_t pos = stream->bitpos;

            Bitwalker_Poke_Normal(addr, size, pos,       8,  p->NID_PACKET);
            Bitwalker_Poke_Normal(addr, size, pos + 8,   2,  p->Q_DIR);
            Bitwalker_Poke_Normal(addr, size, pos + 10,  13, p->L_PACKET);
            Bitwalker_Poke_Normal(addr, size, pos + 23,  2,  p->Q_SCALE);
            Bitwalker_Poke_Normal(addr, size, pos + 25,  15, p->D_LEVELTR);
            Bitwalker_Poke_Normal(addr, size, pos + 40,  3,  p->M_LEVELTR);
            Bitwalker_Poke_Normal(addr, size, pos + 43,  8,  p->NID_NTC);
            Bitwalker_Poke_Normal(addr, size, pos + 51,  15, p->L_ACKLEVELTR);
            Bitwalker_Poke_Normal(addr, size, pos + 66,  5,  p->N_ITER);
            Bitwalker_Poke_Normal(addr, size, pos + 71,  3,  p->M_LEVELTR(k));
            Bitwalker_Poke_Normal(addr, size, pos + 74,  8,  p->NID_NTC(k));
            Bitwalker_Poke_Normal(addr, size, pos + 82,  15, p->L_ACKLEVELTR(k));

            stream->bitpos += LEVEL_TRANSITION_ORDER_BITSIZE;

            //@ assert NID_PACKET:        EqualBits(stream, pos,       pos + 8,   p->NID_PACKET);
            //@ assert Q_DIR:             EqualBits(stream, pos + 8,   pos + 10,  p->Q_DIR);
            //@ assert L_PACKET:          EqualBits(stream, pos + 10,  pos + 23,  p->L_PACKET);
            //@ assert Q_SCALE:           EqualBits(stream, pos + 23,  pos + 25,  p->Q_SCALE);
            //@ assert D_LEVELTR:         EqualBits(stream, pos + 25,  pos + 40,  p->D_LEVELTR);
            //@ assert M_LEVELTR:         EqualBits(stream, pos + 40,  pos + 43,  p->M_LEVELTR);
            //@ assert NID_NTC:           EqualBits(stream, pos + 43,  pos + 51,  p->NID_NTC);
            //@ assert L_ACKLEVELTR:      EqualBits(stream, pos + 51,  pos + 66,  p->L_ACKLEVELTR);
            //@ assert N_ITER:            EqualBits(stream, pos + 66,  pos + 71,  p->N_ITER);
            //@ assert M_LEVELTR(k):      EqualBits(stream, pos + 71,  pos + 74,  p->M_LEVELTR(k));
            //@ assert NID_NTC(k):        EqualBits(stream, pos + 74,  pos + 82,  p->NID_NTC(k));
            //@ assert L_ACKLEVELTR(k):   EqualBits(stream, pos + 82,  pos + 97,  p->L_ACKLEVELTR(k));

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

