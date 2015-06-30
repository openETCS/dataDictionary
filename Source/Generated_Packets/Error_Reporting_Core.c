
#include "Error_Reporting_Core.h"
#include "UpperBitsNotSet.h"
#include "Bitstream_Write.h"
#include "Bitstream_Read.h"

int Error_Reporting_UpperBitsNotSet(const Error_Reporting_Core* p)
{
    bool status = true;

    status = status && UpperBitsNotSet64(p->L_PACKET,          13);
    status = status && UpperBitsNotSet64(p->M_ERROR,           8) ;

    if (status)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int Error_Reporting_Encoder(Bitstream* stream, const Error_Reporting_Core* p)
{
    if (NormalBitstream(stream, ERROR_REPORTING_CORE_BITSIZE))
    {
        if (Error_Reporting_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 13, p->L_PACKET);
            Bitstream_Write(stream, 8,  p->M_ERROR);



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

int Error_Reporting_Decoder(Bitstream* stream, Error_Reporting_Core* p)
{
    if (NormalBitstream(stream, ERROR_REPORTING_CORE_BITSIZE))
    {
        //@ ghost const uint32_t pos = stream->bitpos;

	{ p->L_PACKET		= Bitstream_Read(stream, 13); }

	{ p->M_ERROR		= Bitstream_Read(stream, 8); }



	//@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

