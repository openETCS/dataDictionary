
#include "Stop_if_in_Staff_Responsible_Decoder.h"
#include "Bitwalker_Peek_Normal.h"

int Stop_if_in_Staff_Responsible_Decoder(Bitstream* stream, Stop_if_in_Staff_Responsible* p)
{
    if (NormalBitstream(stream, STOP_IF_IN_STAFF_RESPONSIBLE_BITSIZE))
    {
        uint8_t* addr = stream->addr;
        const uint32_t size = stream->size;
        const uint32_t pos = stream->bitpos;

        p->NID_PACKET         = Bitwalker_Peek_Normal(addr, size, pos,       8);
        p->Q_DIR              = Bitwalker_Peek_Normal(addr, size, pos + 8,   2);
        p->L_PACKET           = Bitwalker_Peek_Normal(addr, size, pos + 10,  13);
        p->Q_SRSTOP           = Bitwalker_Peek_Normal(addr, size, pos + 23,  1);

        stream->bitpos += STOP_IF_IN_STAFF_RESPONSIBLE_BITSIZE;

        //@ assert NID_PACKET:        EqualBits(stream, pos,       pos + 8,   p->NID_PACKET);
        //@ assert Q_DIR:             EqualBits(stream, pos + 8,   pos + 10,  p->Q_DIR);
        //@ assert L_PACKET:          EqualBits(stream, pos + 10,  pos + 23,  p->L_PACKET);
        //@ assert Q_SRSTOP:          EqualBits(stream, pos + 23,  pos + 24,  p->Q_SRSTOP);

        return 1;
    }
    else
    {
        return 0;
    }
}

