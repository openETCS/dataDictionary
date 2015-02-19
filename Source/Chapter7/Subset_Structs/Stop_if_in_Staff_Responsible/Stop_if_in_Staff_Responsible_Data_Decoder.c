
#include "Stop_if_in_Staff_Responsible_Data_Decoder.h"
#include "Bitwalker_Peek_Normal.h"

int Stop_if_in_Staff_Responsible_Data_Decoder(Bitstream* stream, Stop_if_in_Staff_Responsible_Data* p)
{
    if (NormalBitstream(stream, STOP_IF_IN_STAFF_RESPONSIBLE_DATA_BITSIZE))
    {
        uint8_t* addr = stream->addr;
        const uint32_t size = stream->size;
        const uint32_t pos = stream->bitpos;

        p->Q_DIR              = Bitwalker_Peek_Normal(addr, size, pos,       2);
        p->Q_SRSTOP           = Bitwalker_Peek_Normal(addr, size, pos + 15,  1);

        stream->bitpos += STOP_IF_IN_STAFF_RESPONSIBLE_DATA_BITSIZE;

        //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
        //@ assert Q_SRSTOP:          EqualBits(stream, pos + 15,  pos + 16,  p->Q_SRSTOP);

        //@ assert Q_DIR:             UpperBitsNotSet(p->Q_DIR,             2);
        //@ assert Q_SRSTOP:          UpperBitsNotSet(p->Q_SRSTOP,          1);

        return 1;
    }
    else
    {
        return 0;
    }
}

