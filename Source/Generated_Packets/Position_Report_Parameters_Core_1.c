
#include "Position_Report_Parameters_Core_1.h"
#include "UpperBitsNotSet.h"
#include "Bitstream_Write.h"
#include "Bitstream_Read.h"

int Position_Report_Parameters_Core_1_UpperBitsNotSet(const Position_Report_Parameters_Core_1* p)
{
    bool status = true;

    status = status && UpperBitsNotSet64(p->D_LOC_k,           15);
    status = status && UpperBitsNotSet64(p->Q_LGTLOC_k,        1) ;

    if (status)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int Position_Report_Parameters_Core_1_Encoder(Bitstream* stream, const Position_Report_Parameters_Core_1* p)
{
    if (NormalBitstream(stream, POSITION_REPORT_PARAMETERS_CORE_1_CORE_BITSIZE))
    {
        if (Position_Report_Parameters_Core_1_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 15, p->D_LOC_k);
            Bitstream_Write(stream, 1,  p->Q_LGTLOC_k);



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

int Position_Report_Parameters_Core_1_Decoder(Bitstream* stream, Position_Report_Parameters_Core_1* p)
{
    if (NormalBitstream(stream, POSITION_REPORT_PARAMETERS_CORE_1_CORE_BITSIZE))
    {
        //@ ghost const uint32_t pos = stream->bitpos;

	{ p->D_LOC_k		= Bitstream_Read(stream, 15); }

	{ p->Q_LGTLOC_k		= Bitstream_Read(stream, 1); }



	//@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

