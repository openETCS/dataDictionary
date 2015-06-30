
#include "Stop_if_in_Staff_Responsible_Core.h"
#include "UpperBitsNotSet.h"
#include "Bitstream_Write.h"
#include "Bitstream_Read.h"

int Stop_if_in_Staff_Responsible_UpperBitsNotSet(const Stop_if_in_Staff_Responsible_Core* p)
{
    bool status = true;

    status = status && UpperBitsNotSet64(p->Q_DIR,             2) ;
    status = status && UpperBitsNotSet64(p->L_PACKET,          13);
    status = status && UpperBitsNotSet64(p->Q_SRSTOP,          1) ;

    if (status)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int Stop_if_in_Staff_Responsible_Encoder(Bitstream* stream, const Stop_if_in_Staff_Responsible_Core* p)
{
    if (NormalBitstream(stream, STOP_IF_IN_STAFF_RESPONSIBLE_CORE_BITSIZE))
    {
        if (Stop_if_in_Staff_Responsible_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 2,  p->Q_DIR);
            Bitstream_Write(stream, 13, p->L_PACKET);
            Bitstream_Write(stream, 1,  p->Q_SRSTOP);



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

int Stop_if_in_Staff_Responsible_Decoder(Bitstream* stream, Stop_if_in_Staff_Responsible_Core* p)
{
    if (NormalBitstream(stream, STOP_IF_IN_STAFF_RESPONSIBLE_CORE_BITSIZE))
    {
        //@ ghost const uint32_t pos = stream->bitpos;

	{ p->Q_DIR		= Bitstream_Read(stream, 2); }

	{ p->L_PACKET		= Bitstream_Read(stream, 13); }

	{ p->Q_SRSTOP		= Bitstream_Read(stream, 1); }



	//@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

