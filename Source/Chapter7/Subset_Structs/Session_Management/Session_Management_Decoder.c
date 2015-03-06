
#include "Session_Management_Decoder.h"
#include "Bitwalker_Peek_Normal.h"

int Session_Management_Decoder(Bitstream* stream, Session_Management* p)
{
    if (NormalBitstream(stream, SESSION_MANAGEMENT_BITSIZE))
    {
        uint8_t* addr = stream->addr;
        const uint32_t size = stream->size;
        const uint32_t pos = stream->bitpos;

        p->Q_DIR              = Bitwalker_Peek_Normal(addr, size, pos,       2);
        p->L_PACKET           = Bitwalker_Peek_Normal(addr, size, pos + 2,   13);
        p->Q_RBC              = Bitwalker_Peek_Normal(addr, size, pos + 15,  1);
        p->NID_C              = Bitwalker_Peek_Normal(addr, size, pos + 16,  10);
        p->NID_RBC            = Bitwalker_Peek_Normal(addr, size, pos + 26,  14);
        p->NID_RADIO          = Bitwalker_Peek_Normal(addr, size, pos + 40,  64);
        p->Q_SLEEPSESSION     = Bitwalker_Peek_Normal(addr, size, pos + 104, 1);

        stream->bitpos += SESSION_MANAGEMENT_BITSIZE;

        //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
        //@ assert L_PACKET:          EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);
        //@ assert Q_RBC:             EqualBits(stream, pos + 15,  pos + 16,  p->Q_RBC);
        //@ assert NID_C:             EqualBits(stream, pos + 16,  pos + 26,  p->NID_C);
        //@ assert NID_RBC:           EqualBits(stream, pos + 26,  pos + 40,  p->NID_RBC);
        //@ assert NID_RADIO:         EqualBits(stream, pos + 40,  pos + 104, p->NID_RADIO);
        //@ assert Q_SLEEPSESSION:    EqualBits(stream, pos + 104, pos + 105, p->Q_SLEEPSESSION);

        //@ assert Q_DIR:             UpperBitsNotSet(p->Q_DIR,             2);
        //@ assert L_PACKET:          UpperBitsNotSet(p->L_PACKET,          13);
        //@ assert Q_RBC:             UpperBitsNotSet(p->Q_RBC,             1);
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

