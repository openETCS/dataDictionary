
#include "Radio_Network_registration_Encoder.h"
#include "Radio_Network_registration_UpperBitsNotSet.h"
#include "Bitstream_Write.h"

int Radio_Network_registration_Encoder(Bitstream* stream, const Radio_Network_registration_Core* p)
{
    if (NormalBitstream(stream, RADIO_NETWORK_REGISTRATION_CORE_BITSIZE))
    {
        if (Radio_Network_registration_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 2,  p->Q_DIR);
            Bitstream_Write(stream, 13, p->L_PACKET);
            Bitstream_Write(stream, 24, p->NID_MN);



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

