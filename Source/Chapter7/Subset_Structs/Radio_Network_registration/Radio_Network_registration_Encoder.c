
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

            Bitwalker_Poke_Normal(addr, size, pos,       2,  p->Q_DIR);
            Bitwalker_Poke_Normal(addr, size, pos + 2,   13, p->L_PACKET);
            Bitwalker_Poke_Normal(addr, size, pos + 15,  24, p->NID_MN);

            stream->bitpos += RADIO_NETWORK_REGISTRATION_BITSIZE;

            //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
            //@ assert L_PACKET:          EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);
            //@ assert NID_MN:            EqualBits(stream, pos + 15,  pos + 39,  p->NID_MN);

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

