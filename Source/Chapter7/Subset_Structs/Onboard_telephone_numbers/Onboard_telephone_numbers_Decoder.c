
#include "Onboard_telephone_numbers_Decoder.h"
#include "Bitwalker_Peek_Normal.h"

int Onboard_telephone_numbers_Decoder(Bitstream* stream, Onboard_telephone_numbers* p)
{
    if (NormalBitstream(stream, ONBOARD_TELEPHONE_NUMBERS_BITSIZE))
    {
        uint8_t* addr = stream->addr;
        const uint32_t size = stream->size;
        const uint32_t pos = stream->bitpos;

        p->NID_PACKET         = Bitwalker_Peek_Normal(addr, size, pos,       8);
        p->L_PACKET           = Bitwalker_Peek_Normal(addr, size, pos + 8,   13);
        p->N_ITER             = Bitwalker_Peek_Normal(addr, size, pos + 21,  5);
        p->NID_RADIO_(k)      = Bitwalker_Peek_Normal(addr, size, pos + 26,  64);

        stream->bitpos += ONBOARD_TELEPHONE_NUMBERS_BITSIZE;

        //@ assert NID_PACKET:        EqualBits(stream, pos,       pos + 8,   p->NID_PACKET);
        //@ assert L_PACKET:          EqualBits(stream, pos + 8,   pos + 21,  p->L_PACKET);
        //@ assert N_ITER:            EqualBits(stream, pos + 21,  pos + 26,  p->N_ITER);
        //@ assert NID_RADIO_(k):     EqualBits(stream, pos + 26,  pos + 90,  p->NID_RADIO_(k));

        return 1;
    }
    else
    {
        return 0;
    }
}

