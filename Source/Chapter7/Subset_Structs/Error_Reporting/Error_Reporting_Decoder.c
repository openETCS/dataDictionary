
#include "Error_Reporting_Decoder.h"
#include "Bitwalker_Peek_Normal.h"

int Error_Reporting_Decoder(Bitstream* stream, Error_Reporting* p)
{
    if (NormalBitstream(stream, ERROR_REPORTING_BITSIZE))
    {
        uint8_t* addr = stream->addr;
        const uint32_t size = stream->size;
        const uint32_t pos = stream->bitpos;

        p->L_PACKET           = Bitwalker_Peek_Normal(addr, size, pos,       13);
        p->M_ERROR            = Bitwalker_Peek_Normal(addr, size, pos + 13,  8);

        stream->bitpos += ERROR_REPORTING_BITSIZE;

        //@ assert L_PACKET:          EqualBits(stream, pos,       pos + 13,  p->L_PACKET);
        //@ assert M_ERROR:           EqualBits(stream, pos + 13,  pos + 21,  p->M_ERROR);

        //@ assert L_PACKET:          UpperBitsNotSet(p->L_PACKET,          13);
        //@ assert M_ERROR:           UpperBitsNotSet(p->M_ERROR,           8);

        return 1;
    }
    else
    {
        return 0;
    }
}

