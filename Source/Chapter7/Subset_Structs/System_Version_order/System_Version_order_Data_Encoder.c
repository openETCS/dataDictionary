
#include "System_Version_order_Data_Encoder.h"
#include "System_Version_order_Data_UpperBitsNotSet.h"
#include "Bitwalker_Poke_Normal.h"

int System_Version_order_Data_Encoder(Bitstream* stream, const System_Version_order_Data* p)
{
    if (NormalBitstream(stream, SYSTEM_VERSION_ORDER_DATA_BITSIZE))
    {
        if (System_Version_order_Data_UpperBitsNotSet(p))
        {
            uint8_t* addr = stream->addr;
            const uint32_t size = stream->size;
            const uint32_t pos = stream->bitpos;

            Bitwalker_Poke_Normal(addr, size, pos,       2,  p->Q_DIR);
            Bitwalker_Poke_Normal(addr, size, pos + 15,  7,  p->M_VERSION);

            stream->bitpos += SYSTEM_VERSION_ORDER_DATA_BITSIZE;

            //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
            //@ assert M_VERSION:         EqualBits(stream, pos + 15,  pos + 22,  p->M_VERSION);

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

