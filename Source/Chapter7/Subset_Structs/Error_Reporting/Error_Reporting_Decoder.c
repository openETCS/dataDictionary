
#include "Error_Reporting_Decoder.h"
#include "Bitwalker_Peek_Normal.h"

int Error_Reporting_Decoder(Bitstream* stream, Error_Reporting* p)
{
    if (NormalBitstream(stream, ERROR_REPORTING_BITSIZE))
    {
        uint8_t* addr = stream->addr;
        const uint32_t size = stream->size;
        const uint32_t pos = stream->bitpos;

        p->NID_PACKET         = Bitwalker_Peek_Normal(addr, size, pos,       8);
        p->L_PACKET           = Bitwalker_Peek_Normal(addr, size, pos + 8,   13);
        p->M_ERROR            = Bitwalker_Peek_Normal(addr, size, pos + 21,  8);

        stream->bitpos += ERROR_REPORTING_BITSIZE;

        //@ assert NID_PACKET:        EqualBits(stream, pos,       pos + 8,   p->NID_PACKET);
        //@ assert L_PACKET:          EqualBits(stream, pos + 8,   pos + 21,  p->L_PACKET);
        //@ assert M_ERROR:           EqualBits(stream, pos + 21,  pos + 29,  p->M_ERROR);

        return 1;
    }
    else
    {
        return 0;
    }
}

