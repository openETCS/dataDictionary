
#include "List_of_balises_for_SH_Area_Encoder.h"
#include "List_of_balises_for_SH_Area_UpperBitsNotSet.h"
#include "Bitwalker_Poke_Normal.h"

int List_of_balises_for_SH_Area_Encoder(Bitstream* stream, const List_of_balises_for_SH_Area* p)
{
    if (NormalBitstream(stream, LIST_OF_BALISES_FOR_SH_AREA_BITSIZE))
    {
        if (List_of_balises_for_SH_Area_UpperBitsNotSet(p))
        {
            uint8_t* addr = stream->addr;
            const uint32_t size = stream->size;
            const uint32_t pos = stream->bitpos;

            Bitwalker_Poke_Normal(addr, size, pos,       8,  p->NID_PACKET);
            Bitwalker_Poke_Normal(addr, size, pos + 8,   2,  p->Q_DIR);
            Bitwalker_Poke_Normal(addr, size, pos + 10,  13, p->L_PACKET);
            Bitwalker_Poke_Normal(addr, size, pos + 23,  5,  p->N_ITER);
            Bitwalker_Poke_Normal(addr, size, pos + 28,  1,  p->Q_NEWCOUNTRY(k));
            Bitwalker_Poke_Normal(addr, size, pos + 29,  10, p->NID_C(k));
            Bitwalker_Poke_Normal(addr, size, pos + 39,  14, p->NID_BG(k));

            stream->bitpos += LIST_OF_BALISES_FOR_SH_AREA_BITSIZE;

            //@ assert NID_PACKET:        EqualBits(stream, pos,       pos + 8,   p->NID_PACKET);
            //@ assert Q_DIR:             EqualBits(stream, pos + 8,   pos + 10,  p->Q_DIR);
            //@ assert L_PACKET:          EqualBits(stream, pos + 10,  pos + 23,  p->L_PACKET);
            //@ assert N_ITER:            EqualBits(stream, pos + 23,  pos + 28,  p->N_ITER);
            //@ assert Q_NEWCOUNTRY(k):   EqualBits(stream, pos + 28,  pos + 29,  p->Q_NEWCOUNTRY(k));
            //@ assert NID_C(k):          EqualBits(stream, pos + 29,  pos + 39,  p->NID_C(k));
            //@ assert NID_BG(k):         EqualBits(stream, pos + 39,  pos + 53,  p->NID_BG(k));

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

