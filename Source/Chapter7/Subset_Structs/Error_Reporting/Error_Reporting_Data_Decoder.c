
#include "Error_Reporting_Data_Decoder.h"
#include "Bitwalker_Peek_Normal.h"

int Error_Reporting_Data_Decoder(Bitstream* stream, Error_Reporting_Data* p)
{
    if (NormalBitstream(stream, ERROR_REPORTING_DATA_BITSIZE))
    {
        uint8_t* addr = stream->addr;
        const uint32_t size = stream->size;
        const uint32_t pos = stream->bitpos;

        p->M_ERROR            = Bitwalker_Peek_Normal(addr, size, pos,       8);

        stream->bitpos += ERROR_REPORTING_DATA_BITSIZE;

        //@ assert M_ERROR:           EqualBits(stream, pos,       pos + 8,   p->M_ERROR);

        //@ assert M_ERROR:           UpperBitsNotSet(p->M_ERROR,           8);

        return 1;
    }
    else
    {
        return 0;
    }
}

