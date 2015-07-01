
#include "Position_Report_Parameters_Core_1_Encoder.h"
#include "Position_Report_Parameters_Core_1_UpperBitsNotSet.h"
#include "Bitstream_Write.h"

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

