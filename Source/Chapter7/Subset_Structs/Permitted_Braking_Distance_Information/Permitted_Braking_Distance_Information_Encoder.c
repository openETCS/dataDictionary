
#include "Permitted_Braking_Distance_Information_Encoder.h"
#include "Permitted_Braking_Distance_Information_UpperBitsNotSet.h"
#include "Bitwalker_Poke_Normal.h"

int Permitted_Braking_Distance_Information_Encoder(Bitstream* stream, const Permitted_Braking_Distance_Information* p)
{
    if (NormalBitstream(stream, PERMITTED_BRAKING_DISTANCE_INFORMATION_BITSIZE))
    {
        if (Permitted_Braking_Distance_Information_UpperBitsNotSet(p))
        {
            uint8_t* addr = stream->addr;
            const uint32_t size = stream->size;
            const uint32_t pos = stream->bitpos;

            Bitwalker_Poke_Normal(addr, size, pos,       8,  p->NID_PACKET);
            Bitwalker_Poke_Normal(addr, size, pos + 8,   2,  p->Q_DIR);
            Bitwalker_Poke_Normal(addr, size, pos + 10,  13, p->L_PACKET);
            Bitwalker_Poke_Normal(addr, size, pos + 23,  2,  p->Q_SCALE);
            Bitwalker_Poke_Normal(addr, size, pos + 25,  1,  p->Q_TRACKINIT);
            Bitwalker_Poke_Normal(addr, size, pos + 26,  15, p->D_TRACKINIT);
            Bitwalker_Poke_Normal(addr, size, pos + 41,  15, p->D_PBD);
            Bitwalker_Poke_Normal(addr, size, pos + 56,  1,  p->Q_GDIR);
            Bitwalker_Poke_Normal(addr, size, pos + 57,  8,  p->G_PBDSR);
            Bitwalker_Poke_Normal(addr, size, pos + 65,  1,  p->Q_PBDSR);
            Bitwalker_Poke_Normal(addr, size, pos + 66,  15, p->D_PBDSR);
            Bitwalker_Poke_Normal(addr, size, pos + 81,  15, p->L_PBDSR);
            Bitwalker_Poke_Normal(addr, size, pos + 96,  5,  p->N_ITER);
            Bitwalker_Poke_Normal(addr, size, pos + 101, 15, p->D_PBD(k));
            Bitwalker_Poke_Normal(addr, size, pos + 116, 1,  p->Q_GDIR(k));
            Bitwalker_Poke_Normal(addr, size, pos + 117, 8,  p->G_PBDSR(k));
            Bitwalker_Poke_Normal(addr, size, pos + 125, 1,  p->Q_PBDSR(k));
            Bitwalker_Poke_Normal(addr, size, pos + 126, 15, p->D_PBDSR(k));
            Bitwalker_Poke_Normal(addr, size, pos + 141, 15, p->L_PBDSR(k));

            stream->bitpos += PERMITTED_BRAKING_DISTANCE_INFORMATION_BITSIZE;

            //@ assert NID_PACKET:        EqualBits(stream, pos,       pos + 8,   p->NID_PACKET);
            //@ assert Q_DIR:             EqualBits(stream, pos + 8,   pos + 10,  p->Q_DIR);
            //@ assert L_PACKET:          EqualBits(stream, pos + 10,  pos + 23,  p->L_PACKET);
            //@ assert Q_SCALE:           EqualBits(stream, pos + 23,  pos + 25,  p->Q_SCALE);
            //@ assert Q_TRACKINIT:       EqualBits(stream, pos + 25,  pos + 26,  p->Q_TRACKINIT);
            //@ assert D_TRACKINIT:       EqualBits(stream, pos + 26,  pos + 41,  p->D_TRACKINIT);
            //@ assert D_PBD:             EqualBits(stream, pos + 41,  pos + 56,  p->D_PBD);
            //@ assert Q_GDIR:            EqualBits(stream, pos + 56,  pos + 57,  p->Q_GDIR);
            //@ assert G_PBDSR:           EqualBits(stream, pos + 57,  pos + 65,  p->G_PBDSR);
            //@ assert Q_PBDSR:           EqualBits(stream, pos + 65,  pos + 66,  p->Q_PBDSR);
            //@ assert D_PBDSR:           EqualBits(stream, pos + 66,  pos + 81,  p->D_PBDSR);
            //@ assert L_PBDSR:           EqualBits(stream, pos + 81,  pos + 96,  p->L_PBDSR);
            //@ assert N_ITER:            EqualBits(stream, pos + 96,  pos + 101, p->N_ITER);
            //@ assert D_PBD(k):          EqualBits(stream, pos + 101, pos + 116, p->D_PBD(k));
            //@ assert Q_GDIR(k):         EqualBits(stream, pos + 116, pos + 117, p->Q_GDIR(k));
            //@ assert G_PBDSR(k):        EqualBits(stream, pos + 117, pos + 125, p->G_PBDSR(k));
            //@ assert Q_PBDSR(k):        EqualBits(stream, pos + 125, pos + 126, p->Q_PBDSR(k));
            //@ assert D_PBDSR(k):        EqualBits(stream, pos + 126, pos + 141, p->D_PBDSR(k));
            //@ assert L_PBDSR(k):        EqualBits(stream, pos + 141, pos + 156, p->L_PBDSR(k));

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

