
#include "System_Version_order_Decoder.h"
#include "Bitwalker_Peek_Normal.h"

int System_Version_order_Decoder(Bitstream* stream, System_Version_order* p)
{
    if (NormalBitstream(stream, SYSTEM_VERSION_ORDER_BITSIZE))
    {
        uint8_t* addr = stream->addr;
        const uint32_t size = stream->size;
        const uint32_t pos = stream->bitpos;

        p->Q_DIR              = Bitwalker_Peek_Normal(addr, size, pos,       2);
        p->L_PACKET           = Bitwalker_Peek_Normal(addr, size, pos + 2,   13);
        p->M_VERSION          = Bitwalker_Peek_Normal(addr, size, pos + 15,  7);

        stream->bitpos += SYSTEM_VERSION_ORDER_BITSIZE;

        //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
        //@ assert L_PACKET:          EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);
        //@ assert M_VERSION:         EqualBits(stream, pos + 15,  pos + 22,  p->M_VERSION);

        //@ assert Q_DIR:             UpperBitsNotSet(p->Q_DIR,             2);
        //@ assert L_PACKET:          UpperBitsNotSet(p->L_PACKET,          13);
        //@ assert M_VERSION:         UpperBitsNotSet(p->M_VERSION,         7);

        return 1;
    }
    else
    {
        return 0;
    }
}

