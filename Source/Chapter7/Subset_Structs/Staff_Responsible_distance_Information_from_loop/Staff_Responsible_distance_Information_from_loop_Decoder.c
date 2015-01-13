
#include "Staff_Responsible_distance_Information_from_loop_Decoder.h"
#include "Bitwalker_Peek_Normal.h"

int Staff_Responsible_distance_Information_from_loop_Decoder(Bitstream* stream, Staff_Responsible_distance_Information_from_loop* p)
{
    if (NormalBitstream(stream, STAFF_RESPONSIBLE_DISTANCE_INFORMATION_FROM_LOOP_BITSIZE))
    {
        uint8_t* addr = stream->addr;
        const uint32_t size = stream->size;
        const uint32_t pos = stream->bitpos;

        p->NID_PACKET         = Bitwalker_Peek_Normal(addr, size, pos,       8);
        p->Q_DIR              = Bitwalker_Peek_Normal(addr, size, pos + 8,   2);
        p->L_PACKET           = Bitwalker_Peek_Normal(addr, size, pos + 10,  13);
        p->Q_SCALE            = Bitwalker_Peek_Normal(addr, size, pos + 23,  2);
        p->Q_NEWCOUNTRY(0)    = Bitwalker_Peek_Normal(addr, size, pos + 25,  1);
        p->NID_C(0)           = Bitwalker_Peek_Normal(addr, size, pos + 26,  10);
        p->NID_BG(0)          = Bitwalker_Peek_Normal(addr, size, pos + 36,  14);
        p->Q_NEWCOUNTRY(1)    = Bitwalker_Peek_Normal(addr, size, pos + 50,  1);
        p->NID_C(1)           = Bitwalker_Peek_Normal(addr, size, pos + 51,  10);
        p->NID_BG(1)          = Bitwalker_Peek_Normal(addr, size, pos + 61,  14);
        p->D_SR               = Bitwalker_Peek_Normal(addr, size, pos + 75,  15);
        p->N_ITER             = Bitwalker_Peek_Normal(addr, size, pos + 90,  5);
        p->Q_NEWCOUNTRY_(k)   = Bitwalker_Peek_Normal(addr, size, pos + 95,  1);
        p->NID_C_(k)          = Bitwalker_Peek_Normal(addr, size, pos + 96,  10);
        p->NID_BG_(k)         = Bitwalker_Peek_Normal(addr, size, pos + 106, 14);
        p->D_SR_(k)           = Bitwalker_Peek_Normal(addr, size, pos + 120, 15);

        stream->bitpos += STAFF_RESPONSIBLE_DISTANCE_INFORMATION_FROM_LOOP_BITSIZE;

        //@ assert NID_PACKET:        EqualBits(stream, pos,       pos + 8,   p->NID_PACKET);
        //@ assert Q_DIR:             EqualBits(stream, pos + 8,   pos + 10,  p->Q_DIR);
        //@ assert L_PACKET:          EqualBits(stream, pos + 10,  pos + 23,  p->L_PACKET);
        //@ assert Q_SCALE:           EqualBits(stream, pos + 23,  pos + 25,  p->Q_SCALE);
        //@ assert Q_NEWCOUNTRY(0):   EqualBits(stream, pos + 25,  pos + 26,  p->Q_NEWCOUNTRY(0));
        //@ assert NID_C(0):          EqualBits(stream, pos + 26,  pos + 36,  p->NID_C(0));
        //@ assert NID_BG(0):         EqualBits(stream, pos + 36,  pos + 50,  p->NID_BG(0));
        //@ assert Q_NEWCOUNTRY(1):   EqualBits(stream, pos + 50,  pos + 51,  p->Q_NEWCOUNTRY(1));
        //@ assert NID_C(1):          EqualBits(stream, pos + 51,  pos + 61,  p->NID_C(1));
        //@ assert NID_BG(1):         EqualBits(stream, pos + 61,  pos + 75,  p->NID_BG(1));
        //@ assert D_SR:              EqualBits(stream, pos + 75,  pos + 90,  p->D_SR);
        //@ assert N_ITER:            EqualBits(stream, pos + 90,  pos + 95,  p->N_ITER);
        //@ assert Q_NEWCOUNTRY_(k):  EqualBits(stream, pos + 95,  pos + 96,  p->Q_NEWCOUNTRY_(k));
        //@ assert NID_C_(k):         EqualBits(stream, pos + 96,  pos + 106, p->NID_C_(k));
        //@ assert NID_BG_(k):        EqualBits(stream, pos + 106, pos + 120, p->NID_BG_(k));
        //@ assert D_SR_(k):          EqualBits(stream, pos + 120, pos + 135, p->D_SR_(k));

        return 1;
    }
    else
    {
        return 0;
    }
}

