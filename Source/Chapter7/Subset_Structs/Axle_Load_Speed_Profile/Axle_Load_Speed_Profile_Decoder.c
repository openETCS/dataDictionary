
#include "Axle_Load_Speed_Profile_Decoder.h"
#include "Bitwalker_Peek_Normal.h"

int Axle_Load_Speed_Profile_Decoder(Bitstream* stream, Axle_Load_Speed_Profile* p)
{
    if (NormalBitstream(stream, AXLE_LOAD_SPEED_PROFILE_BITSIZE))
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
        p->D_AXLELOAD         = Bitwalker_Peek_Normal(addr, size, pos + 41,  15);
        p->L_AXLELOAD         = Bitwalker_Peek_Normal(addr, size, pos + 56,  15);
        p->Q_FRONT            = Bitwalker_Peek_Normal(addr, size, pos + 71,  1);
        p->N_ITER             = Bitwalker_Peek_Normal(addr, size, pos + 72,  5);
        p->M_AXLELOADCAT(n)   = Bitwalker_Peek_Normal(addr, size, pos + 77,  7);
        p->V_AXLELOAD(n)      = Bitwalker_Peek_Normal(addr, size, pos + 84,  7);
        p->N_ITER             = Bitwalker_Peek_Normal(addr, size, pos + 91,  5);
        p->D_AXLELOAD(k)      = Bitwalker_Peek_Normal(addr, size, pos + 96,  15);
        p->L_AXLELOAD(k)      = Bitwalker_Peek_Normal(addr, size, pos + 111, 15);
        p->Q_FRONT(k)         = Bitwalker_Peek_Normal(addr, size, pos + 126, 1);
        p->N_ITER(k)          = Bitwalker_Peek_Normal(addr, size, pos + 127, 5);
        p->M_AXLELOADCAT(k,m) = Bitwalker_Peek_Normal(addr, size, pos + 132, 7);
        p->V_AXLELOAD(k,m)    = Bitwalker_Peek_Normal(addr, size, pos + 139, 7);

        stream->bitpos += AXLE_LOAD_SPEED_PROFILE_BITSIZE;

        //@ assert NID_PACKET:        EqualBits(stream, pos,       pos + 8,   p->NID_PACKET);
        //@ assert Q_DIR:             EqualBits(stream, pos + 8,   pos + 10,  p->Q_DIR);
        //@ assert L_PACKET:          EqualBits(stream, pos + 10,  pos + 23,  p->L_PACKET);
        //@ assert Q_SCALE:           EqualBits(stream, pos + 23,  pos + 25,  p->Q_SCALE);
        //@ assert Q_TRACKINIT:       EqualBits(stream, pos + 25,  pos + 26,  p->Q_TRACKINIT);
        //@ assert D_TRACKINIT:       EqualBits(stream, pos + 26,  pos + 41,  p->D_TRACKINIT);
        //@ assert D_AXLELOAD:        EqualBits(stream, pos + 41,  pos + 56,  p->D_AXLELOAD);
        //@ assert L_AXLELOAD:        EqualBits(stream, pos + 56,  pos + 71,  p->L_AXLELOAD);
        //@ assert Q_FRONT:           EqualBits(stream, pos + 71,  pos + 72,  p->Q_FRONT);
        //@ assert N_ITER:            EqualBits(stream, pos + 72,  pos + 77,  p->N_ITER);
        //@ assert M_AXLELOADCAT(n):  EqualBits(stream, pos + 77,  pos + 84,  p->M_AXLELOADCAT(n));
        //@ assert V_AXLELOAD(n):     EqualBits(stream, pos + 84,  pos + 91,  p->V_AXLELOAD(n));
        //@ assert N_ITER:            EqualBits(stream, pos + 91,  pos + 96,  p->N_ITER);
        //@ assert D_AXLELOAD(k):     EqualBits(stream, pos + 96,  pos + 111, p->D_AXLELOAD(k));
        //@ assert L_AXLELOAD(k):     EqualBits(stream, pos + 111, pos + 126, p->L_AXLELOAD(k));
        //@ assert Q_FRONT(k):        EqualBits(stream, pos + 126, pos + 127, p->Q_FRONT(k));
        //@ assert N_ITER(k):         EqualBits(stream, pos + 127, pos + 132, p->N_ITER(k));
        //@ assert M_AXLELOADCAT(k,m): EqualBits(stream, pos + 132, pos + 139, p->M_AXLELOADCAT(k,m));
        //@ assert V_AXLELOAD(k,m):   EqualBits(stream, pos + 139, pos + 146, p->V_AXLELOAD(k,m));

        return 1;
    }
    else
    {
        return 0;
    }
}

