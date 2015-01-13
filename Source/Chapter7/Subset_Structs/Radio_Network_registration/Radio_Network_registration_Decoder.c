
#include "Radio_Network_registration_Decoder.h"
#include "Bitwalker_Peek_Normal.h"

int Radio_Network_registration_Decoder(Bitstream* stream, Radio_Network_registration* p)
{
    if (NormalBitstream(stream, RADIO_NETWORK_REGISTRATION_BITSIZE))
    {
        uint8_t* addr = stream->addr;
        const uint32_t size = stream->size;
        const uint32_t pos = stream->bitpos;

        p->NID_PACKET         = Bitwalker_Peek_Normal(addr, size, pos,       8);
        p->Q_DIR              = Bitwalker_Peek_Normal(addr, size, pos + 8,   2);
        p->L_PACKET           = Bitwalker_Peek_Normal(addr, size, pos + 10,  13);
        p->NID_MN             = Bitwalker_Peek_Normal(addr, size, pos + 23,  24);

        stream->bitpos += RADIO_NETWORK_REGISTRATION_BITSIZE;

        //@ assert NID_PACKET:        EqualBits(stream, pos,       pos + 8,   p->NID_PACKET);
        //@ assert Q_DIR:             EqualBits(stream, pos + 8,   pos + 10,  p->Q_DIR);
        //@ assert L_PACKET:          EqualBits(stream, pos + 10,  pos + 23,  p->L_PACKET);
        //@ assert NID_MN:            EqualBits(stream, pos + 23,  pos + 47,  p->NID_MN);

        return 1;
    }
    else
    {
        return 0;
    }
}

