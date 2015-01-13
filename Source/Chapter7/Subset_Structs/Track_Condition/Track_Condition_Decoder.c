
#include "Track_Condition_Decoder.h"
#include "Bitwalker_Peek_Normal.h"

int Track_Condition_Decoder(Bitstream* stream, Track_Condition* p)
{
    if (NormalBitstream(stream, TRACK_CONDITION_BITSIZE))
    {
        uint8_t* addr = stream->addr;
        const uint32_t size = stream->size;
        const uint32_t pos = stream->bitpos;

        p->NID_PACKET         = Bitwalker_Peek_Normal(addr, size, pos,       8);
        p->Q_DIR              = Bitwalker_Peek_Normal(addr, size, pos + 8,   2);
        p->L_PACKET           = Bitwalker_Peek_Normal(addr, size, pos + 10,  13);
        p->Q_SCALE            = Bitwalker_Peek_Normal(addr, size, pos + 23,  2);
        p->Q_TRACKINIT        = Bitwalker_Peek_Normal(addr, size, pos + 25,  1);
        p->D_TRACKINIT        = Bitwalker_Peek_Normal(addr, size, pos + 26,  15);
        p->D_TRACKCOND        = Bitwalker_Peek_Normal(addr, size, pos + 41,  15);
        p->L_TRACKCOND        = Bitwalker_Peek_Normal(addr, size, pos + 56,  15);
        p->M_TRACKCOND        = Bitwalker_Peek_Normal(addr, size, pos + 71,  4);
        p->N_ITER             = Bitwalker_Peek_Normal(addr, size, pos + 75,  5);
        p->D_TRACKCOND(k)     = Bitwalker_Peek_Normal(addr, size, pos + 80,  15);
        p->L_TRACKCOND(k)     = Bitwalker_Peek_Normal(addr, size, pos + 95,  15);
        p->M_TRACKCOND(k)     = Bitwalker_Peek_Normal(addr, size, pos + 110, 4);

        stream->bitpos += TRACK_CONDITION_BITSIZE;

        //@ assert NID_PACKET:        EqualBits(stream, pos,       pos + 8,   p->NID_PACKET);
        //@ assert Q_DIR:             EqualBits(stream, pos + 8,   pos + 10,  p->Q_DIR);
        //@ assert L_PACKET:          EqualBits(stream, pos + 10,  pos + 23,  p->L_PACKET);
        //@ assert Q_SCALE:           EqualBits(stream, pos + 23,  pos + 25,  p->Q_SCALE);
        //@ assert Q_TRACKINIT:       EqualBits(stream, pos + 25,  pos + 26,  p->Q_TRACKINIT);
        //@ assert D_TRACKINIT:       EqualBits(stream, pos + 26,  pos + 41,  p->D_TRACKINIT);
        //@ assert D_TRACKCOND:       EqualBits(stream, pos + 41,  pos + 56,  p->D_TRACKCOND);
        //@ assert L_TRACKCOND:       EqualBits(stream, pos + 56,  pos + 71,  p->L_TRACKCOND);
        //@ assert M_TRACKCOND:       EqualBits(stream, pos + 71,  pos + 75,  p->M_TRACKCOND);
        //@ assert N_ITER:            EqualBits(stream, pos + 75,  pos + 80,  p->N_ITER);
        //@ assert D_TRACKCOND(k):    EqualBits(stream, pos + 80,  pos + 95,  p->D_TRACKCOND(k));
        //@ assert L_TRACKCOND(k):    EqualBits(stream, pos + 95,  pos + 110, p->L_TRACKCOND(k));
        //@ assert M_TRACKCOND(k):    EqualBits(stream, pos + 110, pos + 114, p->M_TRACKCOND(k));

        return 1;
    }
    else
    {
        return 0;
    }
}

