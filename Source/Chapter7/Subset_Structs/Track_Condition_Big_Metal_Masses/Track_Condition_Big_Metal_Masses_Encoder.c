
#include "Track_Condition_Big_Metal_Masses_Encoder.h"
#include "Track_Condition_Big_Metal_Masses_UpperBitsNotSet.h"
#include "Bitwalker_Poke_Normal.h"

int Track_Condition_Big_Metal_Masses_Encoder(Bitstream* stream, const Track_Condition_Big_Metal_Masses* p)
{
    if (NormalBitstream(stream, TRACK_CONDITION_BIG_METAL_MASSES_BITSIZE))
    {
        if (Track_Condition_Big_Metal_Masses_UpperBitsNotSet(p))
        {
            uint8_t* addr = stream->addr;
            const uint32_t size = stream->size;
            const uint32_t pos = stream->bitpos;

            Bitwalker_Poke_Normal(addr, size, pos,       8,  p->NID_PACKET);
            Bitwalker_Poke_Normal(addr, size, pos + 8,   2,  p->Q_DIR);
            Bitwalker_Poke_Normal(addr, size, pos + 10,  13, p->L_PACKET);
            Bitwalker_Poke_Normal(addr, size, pos + 23,  2,  p->Q_SCALE);
            Bitwalker_Poke_Normal(addr, size, pos + 25,  15, p->D_TRACKCOND);
            Bitwalker_Poke_Normal(addr, size, pos + 40,  15, p->L_TRACKCOND);
            Bitwalker_Poke_Normal(addr, size, pos + 55,  5,  p->N_ITER);
            Bitwalker_Poke_Normal(addr, size, pos + 60,  15, p->D_TRACKCOND(k));
            Bitwalker_Poke_Normal(addr, size, pos + 75,  15, p->L_TRACKCOND(k));

            stream->bitpos += TRACK_CONDITION_BIG_METAL_MASSES_BITSIZE;

            //@ assert NID_PACKET:        EqualBits(stream, pos,       pos + 8,   p->NID_PACKET);
            //@ assert Q_DIR:             EqualBits(stream, pos + 8,   pos + 10,  p->Q_DIR);
            //@ assert L_PACKET:          EqualBits(stream, pos + 10,  pos + 23,  p->L_PACKET);
            //@ assert Q_SCALE:           EqualBits(stream, pos + 23,  pos + 25,  p->Q_SCALE);
            //@ assert D_TRACKCOND:       EqualBits(stream, pos + 25,  pos + 40,  p->D_TRACKCOND);
            //@ assert L_TRACKCOND:       EqualBits(stream, pos + 40,  pos + 55,  p->L_TRACKCOND);
            //@ assert N_ITER:            EqualBits(stream, pos + 55,  pos + 60,  p->N_ITER);
            //@ assert D_TRACKCOND(k):    EqualBits(stream, pos + 60,  pos + 75,  p->D_TRACKCOND(k));
            //@ assert L_TRACKCOND(k):    EqualBits(stream, pos + 75,  pos + 90,  p->L_TRACKCOND(k));

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

