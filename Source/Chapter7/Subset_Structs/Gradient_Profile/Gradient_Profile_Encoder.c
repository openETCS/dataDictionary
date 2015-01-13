
#include "Gradient_Profile_Encoder.h"
#include "Gradient_Profile_UpperBitsNotSet.h"
#include "Bitwalker_Poke_Normal.h"

int Gradient_Profile_Encoder(Bitstream* stream, const Gradient_Profile* p)
{
    if (NormalBitstream(stream, GRADIENT_PROFILE_BITSIZE))
    {
        if (Gradient_Profile_UpperBitsNotSet(p))
        {
            uint8_t* addr = stream->addr;
            const uint32_t size = stream->size;
            const uint32_t pos = stream->bitpos;

            Bitwalker_Poke_Normal(addr, size, pos,       8,  p->NID_PACKET);
            Bitwalker_Poke_Normal(addr, size, pos + 8,   2,  p->Q_DIR);
            Bitwalker_Poke_Normal(addr, size, pos + 10,  13, p->L_PACKET);
            Bitwalker_Poke_Normal(addr, size, pos + 23,  2,  p->Q_SCALE);
            Bitwalker_Poke_Normal(addr, size, pos + 25,  15, p->D_GRADIENT);
            Bitwalker_Poke_Normal(addr, size, pos + 40,  1,  p->Q_GDIR);
            Bitwalker_Poke_Normal(addr, size, pos + 41,  8,  p->G_A);
            Bitwalker_Poke_Normal(addr, size, pos + 49,  5,  p->N_ITER);
            Bitwalker_Poke_Normal(addr, size, pos + 54,  15, p->D_GRADIENT(k));
            Bitwalker_Poke_Normal(addr, size, pos + 69,  1,  p->Q_GDIR(k));
            Bitwalker_Poke_Normal(addr, size, pos + 70,  8,  p->G_A(k));

            stream->bitpos += GRADIENT_PROFILE_BITSIZE;

            //@ assert NID_PACKET:        EqualBits(stream, pos,       pos + 8,   p->NID_PACKET);
            //@ assert Q_DIR:             EqualBits(stream, pos + 8,   pos + 10,  p->Q_DIR);
            //@ assert L_PACKET:          EqualBits(stream, pos + 10,  pos + 23,  p->L_PACKET);
            //@ assert Q_SCALE:           EqualBits(stream, pos + 23,  pos + 25,  p->Q_SCALE);
            //@ assert D_GRADIENT:        EqualBits(stream, pos + 25,  pos + 40,  p->D_GRADIENT);
            //@ assert Q_GDIR:            EqualBits(stream, pos + 40,  pos + 41,  p->Q_GDIR);
            //@ assert G_A:               EqualBits(stream, pos + 41,  pos + 49,  p->G_A);
            //@ assert N_ITER:            EqualBits(stream, pos + 49,  pos + 54,  p->N_ITER);
            //@ assert D_GRADIENT(k):     EqualBits(stream, pos + 54,  pos + 69,  p->D_GRADIENT(k));
            //@ assert Q_GDIR(k):         EqualBits(stream, pos + 69,  pos + 70,  p->Q_GDIR(k));
            //@ assert G_A(k):            EqualBits(stream, pos + 70,  pos + 78,  p->G_A(k));

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

