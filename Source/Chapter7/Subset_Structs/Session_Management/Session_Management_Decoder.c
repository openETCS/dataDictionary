
#include "Session_Management_Decoder.h"
#include "Bitwalker_Peek_Normal.h"

int Session_Management_Decoder(Bitstream* stream, Session_Management* p)
{
    if (NormalBitstream(stream, SESSION_MANAGEMENT_BITSIZE))
    {
        uint8_t* addr = stream->addr;
        const uint32_t size = stream->size;
        const uint32_t pos = stream->bitpos;

        p->NID_PACKET         = Bitwalker_Peek_Normal(addr, size, pos,       8);
        p->Q_DIR              = Bitwalker_Peek_Normal(addr, size, pos + 8,   2);
        p->L_PACKET           = Bitwalker_Peek_Normal(addr, size, pos + 10,  13);
        p->Q_RBC              = Bitwalker_Peek_Normal(addr, size, pos + 23,  1);
        p->NID_C              = Bitwalker_Peek_Normal(addr, size, pos + 24,  10);
        p->NID_RBC            = Bitwalker_Peek_Normal(addr, size, pos + 34,  14);
        p->NID_RADIO          = Bitwalker_Peek_Normal(addr, size, pos + 48,  64);
        p->Q_SLEEPSESSION     = Bitwalker_Peek_Normal(addr, size, pos + 112, 1);

        stream->bitpos += SESSION_MANAGEMENT_BITSIZE;

        //@ assert NID_PACKET:        EqualBits(stream, pos,       pos + 8,   p->NID_PACKET);
        //@ assert Q_DIR:             EqualBits(stream, pos + 8,   pos + 10,  p->Q_DIR);
        //@ assert L_PACKET:          EqualBits(stream, pos + 10,  pos + 23,  p->L_PACKET);
        //@ assert Q_RBC:             EqualBits(stream, pos + 23,  pos + 24,  p->Q_RBC);
        //@ assert NID_C:             EqualBits(stream, pos + 24,  pos + 34,  p->NID_C);
        //@ assert NID_RBC:           EqualBits(stream, pos + 34,  pos + 48,  p->NID_RBC);
        //@ assert NID_RADIO:         EqualBits(stream, pos + 48,  pos + 112, p->NID_RADIO);
        //@ assert Q_SLEEPSESSION:    EqualBits(stream, pos + 112, pos + 113, p->Q_SLEEPSESSION);

        return 1;
    }
    else
    {
        return 0;
    }
}

