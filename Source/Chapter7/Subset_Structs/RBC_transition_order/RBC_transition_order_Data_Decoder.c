
#include "RBC_transition_order_Data_Decoder.h"
#include "Bitwalker_Peek_Normal.h"

int RBC_transition_order_Data_Decoder(Bitstream* stream, RBC_transition_order_Data* p)
{
    if (NormalBitstream(stream, RBC_TRANSITION_ORDER_DATA_BITSIZE))
    {
        uint8_t* addr = stream->addr;
        const uint32_t size = stream->size;
        const uint32_t pos = stream->bitpos;

        p->Q_DIR              = Bitwalker_Peek_Normal(addr, size, pos,       2);
        p->Q_SCALE            = Bitwalker_Peek_Normal(addr, size, pos + 15,  2);
        p->D_RBCTR            = Bitwalker_Peek_Normal(addr, size, pos + 17,  15);
        p->NID_C              = Bitwalker_Peek_Normal(addr, size, pos + 32,  10);
        p->NID_RBC            = Bitwalker_Peek_Normal(addr, size, pos + 42,  14);
        p->NID_RADIO          = Bitwalker_Peek_Normal(addr, size, pos + 56,  64);
        p->Q_SLEEPSESSION     = Bitwalker_Peek_Normal(addr, size, pos + 120, 1);

        stream->bitpos += RBC_TRANSITION_ORDER_DATA_BITSIZE;

        //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
        //@ assert Q_SCALE:           EqualBits(stream, pos + 15,  pos + 17,  p->Q_SCALE);
        //@ assert D_RBCTR:           EqualBits(stream, pos + 17,  pos + 32,  p->D_RBCTR);
        //@ assert NID_C:             EqualBits(stream, pos + 32,  pos + 42,  p->NID_C);
        //@ assert NID_RBC:           EqualBits(stream, pos + 42,  pos + 56,  p->NID_RBC);
        //@ assert NID_RADIO:         EqualBits(stream, pos + 56,  pos + 120, p->NID_RADIO);
        //@ assert Q_SLEEPSESSION:    EqualBits(stream, pos + 120, pos + 121, p->Q_SLEEPSESSION);

        //@ assert Q_DIR:             UpperBitsNotSet(p->Q_DIR,             2);
        //@ assert Q_SCALE:           UpperBitsNotSet(p->Q_SCALE,           2);
        //@ assert D_RBCTR:           UpperBitsNotSet(p->D_RBCTR,           15);
        //@ assert NID_C:             UpperBitsNotSet(p->NID_C,             10);
        //@ assert NID_RBC:           UpperBitsNotSet(p->NID_RBC,           14);
        //@ assert NID_RADIO:         UpperBitsNotSet(p->NID_RADIO,         64);
        //@ assert Q_SLEEPSESSION:    UpperBitsNotSet(p->Q_SLEEPSESSION,    1);

        return 1;
    }
    else
    {
        return 0;
    }
}

