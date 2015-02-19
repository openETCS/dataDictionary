
#include "Error_Reporting_Data_Encoder.h"
#include "Error_Reporting_Data_UpperBitsNotSet.h"
#include "Bitwalker_Poke_Normal.h"

int Error_Reporting_Data_Encoder(Bitstream* stream, const Error_Reporting_Data* p)
{
    if (NormalBitstream(stream, ERROR_REPORTING_DATA_BITSIZE))
    {
        if (Error_Reporting_Data_UpperBitsNotSet(p))
        {
            uint8_t* addr = stream->addr;
            const uint32_t size = stream->size;
            const uint32_t pos = stream->bitpos;

            Bitwalker_Poke_Normal(addr, size, pos,       8,  p->M_ERROR);

            stream->bitpos += ERROR_REPORTING_DATA_BITSIZE;

            //@ assert M_ERROR:           EqualBits(stream, pos,       pos + 8,   p->M_ERROR);

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

