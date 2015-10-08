
#include "System_Version_order_Encoder.h"
#include "System_Version_order_UpperBitsNotSet.h"
#include "Bitstream_Write.h"

int System_Version_order_Encoder(Bitstream* stream, const System_Version_order* p)
{
    if (NormalBitstream(stream, SYSTEM_VERSION_ORDER_BITSIZE))
    {
        if (System_Version_order_UpperBitsNotSet(p))
        {
            uint8_t* addr = stream->addr;
            const uint32_t size = stream->size;
            const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 2,  p->Q_DIR);
            Bitstream_Write(stream, 13, p->L_PACKET);
            Bitstream_Write(stream, 7,  p->M_VERSION);


            //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
            //@ assert L_PACKET:          EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);
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

