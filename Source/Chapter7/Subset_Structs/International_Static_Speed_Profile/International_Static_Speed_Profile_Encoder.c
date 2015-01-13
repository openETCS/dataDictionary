
#include "International_Static_Speed_Profile_Encoder.h"
#include "International_Static_Speed_Profile_UpperBitsNotSet.h"
#include "Bitwalker_Poke_Normal.h"

int International_Static_Speed_Profile_Encoder(Bitstream* stream, const International_Static_Speed_Profile* p)
{
    if (NormalBitstream(stream, INTERNATIONAL_STATIC_SPEED_PROFILE_BITSIZE))
    {
        if (International_Static_Speed_Profile_UpperBitsNotSet(p))
        {
            uint8_t* addr = stream->addr;
            const uint32_t size = stream->size;
            const uint32_t pos = stream->bitpos;

            Bitwalker_Poke_Normal(addr, size, pos,       8,  p->NID_PACKET);
            Bitwalker_Poke_Normal(addr, size, pos + 8,   2,  p->Q_DIR);
            Bitwalker_Poke_Normal(addr, size, pos + 10,  13, p->L_PACKET);
            Bitwalker_Poke_Normal(addr, size, pos + 23,  2,  p->Q_SCALE);
            Bitwalker_Poke_Normal(addr, size, pos + 25,  15, p->D_STATIC);
            Bitwalker_Poke_Normal(addr, size, pos + 40,  7,  p->V_STATIC);
            Bitwalker_Poke_Normal(addr, size, pos + 47,  1,  p->Q_FRONT);
            Bitwalker_Poke_Normal(addr, size, pos + 48,  5,  p->N_ITER);
            Bitwalker_Poke_Normal(addr, size, pos + 53,  2,  p->Q_DIFF(n));
            Bitwalker_Poke_Normal(addr, size, pos + 55,  4,  p->NC_CDDIFF(n));
            Bitwalker_Poke_Normal(addr, size, pos + 59,  4,  p->NC_DIFF(n));
            Bitwalker_Poke_Normal(addr, size, pos + 63,  7,  p->V_DIFF(n));
            Bitwalker_Poke_Normal(addr, size, pos + 70,  5,  p->N_ITER);
            Bitwalker_Poke_Normal(addr, size, pos + 75,  15, p->D_STATIC(k));
            Bitwalker_Poke_Normal(addr, size, pos + 90,  7,  p->V_STATIC(k));
            Bitwalker_Poke_Normal(addr, size, pos + 97,  1,  p->Q_FRONT(k));
            Bitwalker_Poke_Normal(addr, size, pos + 98,  5,  p->N_ITER(k));
            Bitwalker_Poke_Normal(addr, size, pos + 103, 2,  p->Q_DIFF(k,m));
            Bitwalker_Poke_Normal(addr, size, pos + 105, 4,  p->NC_CDDIFF(k,m));
            Bitwalker_Poke_Normal(addr, size, pos + 109, 4,  p->NC_DIFF(k,m));
            Bitwalker_Poke_Normal(addr, size, pos + 113, 7,  p->V_DIFF(k,m));

            stream->bitpos += INTERNATIONAL_STATIC_SPEED_PROFILE_BITSIZE;

            //@ assert NID_PACKET:        EqualBits(stream, pos,       pos + 8,   p->NID_PACKET);
            //@ assert Q_DIR:             EqualBits(stream, pos + 8,   pos + 10,  p->Q_DIR);
            //@ assert L_PACKET:          EqualBits(stream, pos + 10,  pos + 23,  p->L_PACKET);
            //@ assert Q_SCALE:           EqualBits(stream, pos + 23,  pos + 25,  p->Q_SCALE);
            //@ assert D_STATIC:          EqualBits(stream, pos + 25,  pos + 40,  p->D_STATIC);
            //@ assert V_STATIC:          EqualBits(stream, pos + 40,  pos + 47,  p->V_STATIC);
            //@ assert Q_FRONT:           EqualBits(stream, pos + 47,  pos + 48,  p->Q_FRONT);
            //@ assert N_ITER:            EqualBits(stream, pos + 48,  pos + 53,  p->N_ITER);
            //@ assert Q_DIFF(n):         EqualBits(stream, pos + 53,  pos + 55,  p->Q_DIFF(n));
            //@ assert NC_CDDIFF(n):      EqualBits(stream, pos + 55,  pos + 59,  p->NC_CDDIFF(n));
            //@ assert NC_DIFF(n):        EqualBits(stream, pos + 59,  pos + 63,  p->NC_DIFF(n));
            //@ assert V_DIFF(n):         EqualBits(stream, pos + 63,  pos + 70,  p->V_DIFF(n));
            //@ assert N_ITER:            EqualBits(stream, pos + 70,  pos + 75,  p->N_ITER);
            //@ assert D_STATIC(k):       EqualBits(stream, pos + 75,  pos + 90,  p->D_STATIC(k));
            //@ assert V_STATIC(k):       EqualBits(stream, pos + 90,  pos + 97,  p->V_STATIC(k));
            //@ assert Q_FRONT(k):        EqualBits(stream, pos + 97,  pos + 98,  p->Q_FRONT(k));
            //@ assert N_ITER(k):         EqualBits(stream, pos + 98,  pos + 103, p->N_ITER(k));
            //@ assert Q_DIFF(k,m):       EqualBits(stream, pos + 103, pos + 105, p->Q_DIFF(k,m));
            //@ assert NC_CDDIFF(k,m):    EqualBits(stream, pos + 105, pos + 109, p->NC_CDDIFF(k,m));
            //@ assert NC_DIFF(k,m):      EqualBits(stream, pos + 109, pos + 113, p->NC_DIFF(k,m));
            //@ assert V_DIFF(k,m):       EqualBits(stream, pos + 113, pos + 120, p->V_DIFF(k,m));

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

