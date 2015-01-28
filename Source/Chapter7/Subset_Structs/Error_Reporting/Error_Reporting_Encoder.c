
#include "Error_Reporting_Encoder.h"
#include "Error_Reporting_UpperBitsNotSet.h"
#include "Bitwalker_Poke_Normal.h"

int Error_Reporting_Encoder(Bitstream* stream, const Error_Reporting* p)
{
    if (NormalBitstream(stream, ERROR_REPORTING_BITSIZE))
    {
        if (Error_Reporting_UpperBitsNotSet(p))
        {
            uint8_t* addr = stream->addr;
            const uint32_t size = stream->size;
            const uint32_t pos = stream->bitpos;

            Bitwalker_Poke_Normal(addr, size, pos,       8,  p->NID_PACKET);
            Bitwalker_Poke_Normal(addr, size, pos + 8,   13, p->L_PACKET);
            Bitwalker_Poke_Normal(addr, size, pos + 21,  8,  p->M_ERROR);

            stream->bitpos += ERROR_REPORTING_BITSIZE;

            //@ assert NID_PACKET:        EqualBits(stream, pos,       pos + 8,   p->NID_PACKET);
            //@ assert L_PACKET:          EqualBits(stream, pos + 8,   pos + 21,  p->L_PACKET);
            //@ assert M_ERROR:           EqualBits(stream, pos + 21,  pos + 29,  p->M_ERROR);

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

