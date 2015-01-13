
#include "Radio_Network_registration_Encoder.h"
#include "Radio_Network_registration_UpperBitsNotSet.h"
#include "Bitwalker_Poke_Normal.h"

int Radio_Network_registration_Encoder(Bitstream* stream, const Radio_Network_registration* p)
{
    if (NormalBitstream(stream, RADIO_NETWORK_REGISTRATION_BITSIZE))
    {
        if (Radio_Network_registration_UpperBitsNotSet(p))
        {
            uint8_t* addr = stream->addr;
            const uint32_t size = stream->size;
            const uint32_t pos = stream->bitpos;

            Bitwalker_Poke_Normal(addr, size, pos,       8,  p->NID_PACKET);
            Bitwalker_Poke_Normal(addr, size, pos + 8,   2,  p->Q_DIR);
            Bitwalker_Poke_Normal(addr, size, pos + 10,  13, p->L_PACKET);
            Bitwalker_Poke_Normal(addr, size, pos + 23,  24, p->NID_MN);

            stream->bitpos += RADIO_NETWORK_REGISTRATION_BITSIZE;

            //@ assert NID_PACKET:        EqualBits(stream, pos,       pos + 8,   p->NID_PACKET);
            //@ assert Q_DIR:             EqualBits(stream, pos + 8,   pos + 10,  p->Q_DIR);
            //@ assert L_PACKET:          EqualBits(stream, pos + 10,  pos + 23,  p->L_PACKET);
            //@ assert NID_MN:            EqualBits(stream, pos + 23,  pos + 47,  p->NID_MN);

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

