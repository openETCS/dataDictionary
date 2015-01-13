
#include "Mode_profile_Encoder.h"
#include "Mode_profile_UpperBitsNotSet.h"
#include "Bitwalker_Poke_Normal.h"

int Mode_profile_Encoder(Bitstream* stream, const Mode_profile* p)
{
    if (NormalBitstream(stream, MODE_PROFILE_BITSIZE))
    {
        if (Mode_profile_UpperBitsNotSet(p))
        {
            uint8_t* addr = stream->addr;
            const uint32_t size = stream->size;
            const uint32_t pos = stream->bitpos;

            Bitwalker_Poke_Normal(addr, size, pos,       8,  p->NID_PACKET);
            Bitwalker_Poke_Normal(addr, size, pos + 8,   2,  p->Q_DIR);
            Bitwalker_Poke_Normal(addr, size, pos + 10,  13, p->L_PACKET);
            Bitwalker_Poke_Normal(addr, size, pos + 23,  2,  p->Q_SCALE);
            Bitwalker_Poke_Normal(addr, size, pos + 25,  15, p->D_MAMODE);
            Bitwalker_Poke_Normal(addr, size, pos + 40,  2,  p->M_MAMODE);
            Bitwalker_Poke_Normal(addr, size, pos + 42,  7,  p->V_MAMODE);
            Bitwalker_Poke_Normal(addr, size, pos + 49,  15, p->L_MAMODE);
            Bitwalker_Poke_Normal(addr, size, pos + 64,  15, p->L_ACKMAMODE);
            Bitwalker_Poke_Normal(addr, size, pos + 79,  1,  p->Q_MAMODE);
            Bitwalker_Poke_Normal(addr, size, pos + 80,  5,  p->N_ITER);
            Bitwalker_Poke_Normal(addr, size, pos + 85,  15, p->D_MAMODE(k));
            Bitwalker_Poke_Normal(addr, size, pos + 100, 2,  p->M_MAMODE(k));
            Bitwalker_Poke_Normal(addr, size, pos + 102, 7,  p->V_MAMODE(k));
            Bitwalker_Poke_Normal(addr, size, pos + 109, 15, p->L_MAMODE(k));
            Bitwalker_Poke_Normal(addr, size, pos + 124, 15, p->L_ACKMAMODE(k));
            Bitwalker_Poke_Normal(addr, size, pos + 139, 1,  p->Q_MAMODE(k));

            stream->bitpos += MODE_PROFILE_BITSIZE;

            //@ assert NID_PACKET:        EqualBits(stream, pos,       pos + 8,   p->NID_PACKET);
            //@ assert Q_DIR:             EqualBits(stream, pos + 8,   pos + 10,  p->Q_DIR);
            //@ assert L_PACKET:          EqualBits(stream, pos + 10,  pos + 23,  p->L_PACKET);
            //@ assert Q_SCALE:           EqualBits(stream, pos + 23,  pos + 25,  p->Q_SCALE);
            //@ assert D_MAMODE:          EqualBits(stream, pos + 25,  pos + 40,  p->D_MAMODE);
            //@ assert M_MAMODE:          EqualBits(stream, pos + 40,  pos + 42,  p->M_MAMODE);
            //@ assert V_MAMODE:          EqualBits(stream, pos + 42,  pos + 49,  p->V_MAMODE);
            //@ assert L_MAMODE:          EqualBits(stream, pos + 49,  pos + 64,  p->L_MAMODE);
            //@ assert L_ACKMAMODE:       EqualBits(stream, pos + 64,  pos + 79,  p->L_ACKMAMODE);
            //@ assert Q_MAMODE:          EqualBits(stream, pos + 79,  pos + 80,  p->Q_MAMODE);
            //@ assert N_ITER:            EqualBits(stream, pos + 80,  pos + 85,  p->N_ITER);
            //@ assert D_MAMODE(k):       EqualBits(stream, pos + 85,  pos + 100, p->D_MAMODE(k));
            //@ assert M_MAMODE(k):       EqualBits(stream, pos + 100, pos + 102, p->M_MAMODE(k));
            //@ assert V_MAMODE(k):       EqualBits(stream, pos + 102, pos + 109, p->V_MAMODE(k));
            //@ assert L_MAMODE(k):       EqualBits(stream, pos + 109, pos + 124, p->L_MAMODE(k));
            //@ assert L_ACKMAMODE(k):    EqualBits(stream, pos + 124, pos + 139, p->L_ACKMAMODE(k));
            //@ assert Q_MAMODE(k):       EqualBits(stream, pos + 139, pos + 140, p->Q_MAMODE(k));

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

