
#include "RBC_transition_order_Encoder.h"
#include "RBC_transition_order_UpperBitsNotSet.h"
#include "Bitwalker_Poke_Normal.h"

int RBC_transition_order_Encoder(Bitstream* stream, const RBC_transition_order* p)
{
    if (NormalBitstream(stream, RBC_TRANSITION_ORDER_BITSIZE))
    {
        if (RBC_transition_order_UpperBitsNotSet(p))
        {
            uint8_t* addr = stream->addr;
            const uint32_t size = stream->size;
            const uint32_t pos = stream->bitpos;

            Bitwalker_Poke_Normal(addr, size, pos,       2,  p->Q_DIR);
            Bitwalker_Poke_Normal(addr, size, pos + 2,   13, p->L_PACKET);
            Bitwalker_Poke_Normal(addr, size, pos + 15,  2,  p->Q_SCALE);
            Bitwalker_Poke_Normal(addr, size, pos + 17,  15, p->D_RBCTR);
            Bitwalker_Poke_Normal(addr, size, pos + 32,  10, p->NID_C);
            Bitwalker_Poke_Normal(addr, size, pos + 42,  14, p->NID_RBC);
            Bitwalker_Poke_Normal(addr, size, pos + 56,  64, p->NID_RADIO);
            Bitwalker_Poke_Normal(addr, size, pos + 120, 1,  p->Q_SLEEPSESSION);

            stream->bitpos += RBC_TRANSITION_ORDER_BITSIZE;

            //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
            //@ assert L_PACKET:          EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);
            //@ assert Q_SCALE:           EqualBits(stream, pos + 15,  pos + 17,  p->Q_SCALE);
            //@ assert D_RBCTR:           EqualBits(stream, pos + 17,  pos + 32,  p->D_RBCTR);
            //@ assert NID_C:             EqualBits(stream, pos + 32,  pos + 42,  p->NID_C);
            //@ assert NID_RBC:           EqualBits(stream, pos + 42,  pos + 56,  p->NID_RBC);
            //@ assert NID_RADIO:         EqualBits(stream, pos + 56,  pos + 120, p->NID_RADIO);
            //@ assert Q_SLEEPSESSION:    EqualBits(stream, pos + 120, pos + 121, p->Q_SLEEPSESSION);

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

