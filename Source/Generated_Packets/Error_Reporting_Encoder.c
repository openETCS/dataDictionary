
#include "Error_Reporting_Encoder.h"
#include "Error_Reporting_UpperBitsNotSet.h"
#include "Bitstream_Write.h"

int Error_Reporting_Encoder(Bitstream* stream, const Error_Reporting_Core* p)
{
    if (NormalBitstream(stream, ERROR_REPORTING_CORE_BITSIZE))
    {
        if (Error_Reporting_UpperBitsNotSet(p))
        {
            uint8_t* addr = stream->addr;
            const uint32_t size = stream->size;
            const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 13, p->L_PACKET);
            Bitstream_Write(stream, 8,  p->M_ERROR);


            //@ assert L_PACKET:          EqualBits(stream, pos,       pos + 13,  p->L_PACKET);
            //@ assert M_ERROR:           EqualBits(stream, pos + 13,  pos + 21,  p->M_ERROR);

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

