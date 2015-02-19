
#include "Radio_Network_registration_Data_Decoder.h"
#include "Bitwalker_Peek_Normal.h"

int Radio_Network_registration_Data_Decoder(Bitstream* stream, Radio_Network_registration_Data* p)
{
    if (NormalBitstream(stream, RADIO_NETWORK_REGISTRATION_DATA_BITSIZE))
    {
        uint8_t* addr = stream->addr;
        const uint32_t size = stream->size;
        const uint32_t pos = stream->bitpos;

        p->Q_DIR              = Bitwalker_Peek_Normal(addr, size, pos,       2);
        p->NID_MN             = Bitwalker_Peek_Normal(addr, size, pos + 15,  24);

        stream->bitpos += RADIO_NETWORK_REGISTRATION_DATA_BITSIZE;

        //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
        //@ assert NID_MN:            EqualBits(stream, pos + 15,  pos + 39,  p->NID_MN);

        //@ assert Q_DIR:             UpperBitsNotSet(p->Q_DIR,             2);
        //@ assert NID_MN:            UpperBitsNotSet(p->NID_MN,            24);

        return 1;
    }
    else
    {
        return 0;
    }
}

