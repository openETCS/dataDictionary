
#include "Geographical_Position_Information_Encoder.h"
#include "Geographical_Position_Information_UpperBitsNotSet.h"
#include "Bitwalker_Poke_Normal.h"

int Geographical_Position_Information_Encoder(Bitstream* stream, const Geographical_Position_Information* p)
{
    if (NormalBitstream(stream, GEOGRAPHICAL_POSITION_INFORMATION_BITSIZE))
    {
        if (Geographical_Position_Information_UpperBitsNotSet(p))
        {
            uint8_t* addr = stream->addr;
            const uint32_t size = stream->size;
            const uint32_t pos = stream->bitpos;

            Bitwalker_Poke_Normal(addr, size, pos,       8,  p->NID_PACKET);
            Bitwalker_Poke_Normal(addr, size, pos + 8,   2,  p->Q_DIR);
            Bitwalker_Poke_Normal(addr, size, pos + 10,  13, p->L_PACKET);
            Bitwalker_Poke_Normal(addr, size, pos + 23,  2,  p->Q_SCALE);
            Bitwalker_Poke_Normal(addr, size, pos + 25,  1,  p->Q_NEWCOUNTRY);
            Bitwalker_Poke_Normal(addr, size, pos + 26,  10, p->NID_C);
            Bitwalker_Poke_Normal(addr, size, pos + 36,  14, p->NID_BG);
            Bitwalker_Poke_Normal(addr, size, pos + 50,  15, p->D_POSOFF);
            Bitwalker_Poke_Normal(addr, size, pos + 65,  1,  p->Q_MPOSITION);
            Bitwalker_Poke_Normal(addr, size, pos + 66,  24, p->M_POSITION);
            Bitwalker_Poke_Normal(addr, size, pos + 90,  5,  p->N_ITER);
            Bitwalker_Poke_Normal(addr, size, pos + 95,  1,  p->Q_NEWCOUNTRY(k));
            Bitwalker_Poke_Normal(addr, size, pos + 96,  10, p->NID_C(k));
            Bitwalker_Poke_Normal(addr, size, pos + 106, 14, p->NID_BG(k));
            Bitwalker_Poke_Normal(addr, size, pos + 120, 15, p->D_POSOFF(k));
            Bitwalker_Poke_Normal(addr, size, pos + 135, 1,  p->Q_MPOSITION(k));
            Bitwalker_Poke_Normal(addr, size, pos + 136, 24, p->M_POSITION(k));

            stream->bitpos += GEOGRAPHICAL_POSITION_INFORMATION_BITSIZE;

            //@ assert NID_PACKET:        EqualBits(stream, pos,       pos + 8,   p->NID_PACKET);
            //@ assert Q_DIR:             EqualBits(stream, pos + 8,   pos + 10,  p->Q_DIR);
            //@ assert L_PACKET:          EqualBits(stream, pos + 10,  pos + 23,  p->L_PACKET);
            //@ assert Q_SCALE:           EqualBits(stream, pos + 23,  pos + 25,  p->Q_SCALE);
            //@ assert Q_NEWCOUNTRY:      EqualBits(stream, pos + 25,  pos + 26,  p->Q_NEWCOUNTRY);
            //@ assert NID_C:             EqualBits(stream, pos + 26,  pos + 36,  p->NID_C);
            //@ assert NID_BG:            EqualBits(stream, pos + 36,  pos + 50,  p->NID_BG);
            //@ assert D_POSOFF:          EqualBits(stream, pos + 50,  pos + 65,  p->D_POSOFF);
            //@ assert Q_MPOSITION:       EqualBits(stream, pos + 65,  pos + 66,  p->Q_MPOSITION);
            //@ assert M_POSITION:        EqualBits(stream, pos + 66,  pos + 90,  p->M_POSITION);
            //@ assert N_ITER:            EqualBits(stream, pos + 90,  pos + 95,  p->N_ITER);
            //@ assert Q_NEWCOUNTRY(k):   EqualBits(stream, pos + 95,  pos + 96,  p->Q_NEWCOUNTRY(k));
            //@ assert NID_C(k):          EqualBits(stream, pos + 96,  pos + 106, p->NID_C(k));
            //@ assert NID_BG(k):         EqualBits(stream, pos + 106, pos + 120, p->NID_BG(k));
            //@ assert D_POSOFF(k):       EqualBits(stream, pos + 120, pos + 135, p->D_POSOFF(k));
            //@ assert Q_MPOSITION(k):    EqualBits(stream, pos + 135, pos + 136, p->Q_MPOSITION(k));
            //@ assert M_POSITION(k):     EqualBits(stream, pos + 136, pos + 160, p->M_POSITION(k));

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

