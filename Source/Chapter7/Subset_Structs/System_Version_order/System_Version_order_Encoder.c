
#include "System_Version_order_Encoder.h"
#include "System_Version_order_UpperBitsNotSet.h"
#include "Bitwalker_Poke_Normal.h"

int System_Version_order_Encoder(Bitstream* stream, const System_Version_order* p)
{
    if (NormalBitstream(stream, SYSTEM_VERSION_ORDER_BITSIZE))
    {
        if (System_Version_order_UpperBitsNotSet(p))
        {
            uint8_t* addr = stream->addr;
            const uint32_t size = stream->size;
            const uint32_t pos = stream->bitpos;

            Bitwalker_Poke_Normal(addr, size, pos,       8,  p->NID_PACKET);
            Bitwalker_Poke_Normal(addr, size, pos + 8,   2,  p->Q_DIR);
            Bitwalker_Poke_Normal(addr, size, pos + 10,  13, p->L_PACKET);
            Bitwalker_Poke_Normal(addr, size, pos + 23,  7,  p->M_VERSION);

            stream->bitpos += SYSTEM_VERSION_ORDER_BITSIZE;

            //@ assert NID_PACKET:        EqualBits(stream, pos,       pos + 8,   p->NID_PACKET);
            //@ assert Q_DIR:             EqualBits(stream, pos + 8,   pos + 10,  p->Q_DIR);
            //@ assert L_PACKET:          EqualBits(stream, pos + 10,  pos + 23,  p->L_PACKET);
            //@ assert M_VERSION:         EqualBits(stream, pos + 23,  pos + 30,  p->M_VERSION);

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

