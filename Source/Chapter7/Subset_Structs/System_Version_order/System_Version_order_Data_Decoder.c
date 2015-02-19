
#include "System_Version_order_Data_Decoder.h"
#include "Bitwalker_Peek_Normal.h"

int System_Version_order_Data_Decoder(Bitstream* stream, System_Version_order_Data* p)
{
    if (NormalBitstream(stream, SYSTEM_VERSION_ORDER_DATA_BITSIZE))
    {
        uint8_t* addr = stream->addr;
        const uint32_t size = stream->size;
        const uint32_t pos = stream->bitpos;

        p->Q_DIR              = Bitwalker_Peek_Normal(addr, size, pos,       2);
        p->M_VERSION          = Bitwalker_Peek_Normal(addr, size, pos + 15,  7);

        stream->bitpos += SYSTEM_VERSION_ORDER_DATA_BITSIZE;

        //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
        //@ assert M_VERSION:         EqualBits(stream, pos + 15,  pos + 22,  p->M_VERSION);

        //@ assert Q_DIR:             UpperBitsNotSet(p->Q_DIR,             2);
        //@ assert M_VERSION:         UpperBitsNotSet(p->M_VERSION,         7);

        return 1;
    }
    else
    {
        return 0;
    }
}

