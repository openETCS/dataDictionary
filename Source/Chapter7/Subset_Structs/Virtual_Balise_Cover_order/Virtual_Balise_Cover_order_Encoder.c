
#include "Virtual_Balise_Cover_order_Encoder.h"
#include "Virtual_Balise_Cover_order_UpperBitsNotSet.h"
#include "Bitwalker_Poke_Normal.h"

int Virtual_Balise_Cover_order_Encoder(Bitstream* stream, const Virtual_Balise_Cover_order* p)
{
    if (NormalBitstream(stream, VIRTUAL_BALISE_COVER_ORDER_BITSIZE))
    {
        if (Virtual_Balise_Cover_order_UpperBitsNotSet(p))
        {
            uint8_t* addr = stream->addr;
            const uint32_t size = stream->size;
            const uint32_t pos = stream->bitpos;

            Bitwalker_Poke_Normal(addr, size, pos,       8,  p->NID_PACKET);
            Bitwalker_Poke_Normal(addr, size, pos + 8,   2,  p->Q_DIR);
            Bitwalker_Poke_Normal(addr, size, pos + 10,  13, p->L_PACKET);
            Bitwalker_Poke_Normal(addr, size, pos + 23,  1,  p->Q_VBCO);
            Bitwalker_Poke_Normal(addr, size, pos + 24,  6,  p->NID_VBCMK);
            Bitwalker_Poke_Normal(addr, size, pos + 30,  10, p->NID_C);
            Bitwalker_Poke_Normal(addr, size, pos + 40,  8,  p->T_VBC);

            stream->bitpos += VIRTUAL_BALISE_COVER_ORDER_BITSIZE;

            //@ assert NID_PACKET:        EqualBits(stream, pos,       pos + 8,   p->NID_PACKET);
            //@ assert Q_DIR:             EqualBits(stream, pos + 8,   pos + 10,  p->Q_DIR);
            //@ assert L_PACKET:          EqualBits(stream, pos + 10,  pos + 23,  p->L_PACKET);
            //@ assert Q_VBCO:            EqualBits(stream, pos + 23,  pos + 24,  p->Q_VBCO);
            //@ assert NID_VBCMK:         EqualBits(stream, pos + 24,  pos + 30,  p->NID_VBCMK);
            //@ assert NID_C:             EqualBits(stream, pos + 30,  pos + 40,  p->NID_C);
            //@ assert T_VBC:             EqualBits(stream, pos + 40,  pos + 48,  p->T_VBC);

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

