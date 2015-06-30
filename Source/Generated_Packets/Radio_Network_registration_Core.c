
#include "Radio_Network_registration_Core.h"
#include "UpperBitsNotSet.h"
#include "Bitstream_Write.h"
#include "Bitstream_Read.h"

int Radio_Network_registration_UpperBitsNotSet(const Radio_Network_registration_Core* p)
{
    bool status = true;

    status = status && UpperBitsNotSet64(p->Q_DIR,             2) ;
    status = status && UpperBitsNotSet64(p->L_PACKET,          13);
    status = status && UpperBitsNotSet64(p->NID_MN,            24);

    if (status)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

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

int Radio_Network_registration_Decoder(Bitstream* stream, Radio_Network_registration_Core* p)
{
    if (NormalBitstream(stream, RADIO_NETWORK_REGISTRATION_CORE_BITSIZE))
    {
        //@ ghost const uint32_t pos = stream->bitpos;

	{ p->Q_DIR		= Bitstream_Read(stream, 2); }

	{ p->L_PACKET		= Bitstream_Read(stream, 13); }

	{ p->NID_MN		= Bitstream_Read(stream, 24); }



	//@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

