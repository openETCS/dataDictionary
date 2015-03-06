
#include "Stop_if_in_Staff_Responsible_Decoder.h"
#include "Bitwalker_Peek_Normal.h"

int Stop_if_in_Staff_Responsible_Decoder(Bitstream* stream, Stop_if_in_Staff_Responsible* p)
{
    if (NormalBitstream(stream, STOP_IF_IN_STAFF_RESPONSIBLE_BITSIZE))
    {
        uint8_t* addr = stream->addr;
        const uint32_t size = stream->size;
        const uint32_t pos = stream->bitpos;

        p->Q_DIR              = Bitwalker_Peek_Normal(addr, size, pos,       2);
        p->L_PACKET           = Bitwalker_Peek_Normal(addr, size, pos + 2,   13);
        p->Q_SRSTOP           = Bitwalker_Peek_Normal(addr, size, pos + 15,  1);

        stream->bitpos += STOP_IF_IN_STAFF_RESPONSIBLE_BITSIZE;

        //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
        //@ assert L_PACKET:          EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);
        //@ assert Q_SRSTOP:          EqualBits(stream, pos + 15,  pos + 16,  p->Q_SRSTOP);

        //@ assert Q_DIR:             UpperBitsNotSet(p->Q_DIR,             2);
        //@ assert L_PACKET:          UpperBitsNotSet(p->L_PACKET,          13);
        //@ assert Q_SRSTOP:          UpperBitsNotSet(p->Q_SRSTOP,          1);

        return 1;
    }
    else
    {
        return 0;
    }
}

