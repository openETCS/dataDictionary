
#include "Onboard_telephone_numbers_Encoder.h"
#include "Onboard_telephone_numbers_UpperBitsNotSet.h"
#include "Bitwalker_Poke_Normal.h"

int Onboard_telephone_numbers_Encoder(Bitstream* stream, const Onboard_telephone_numbers* p)
{
    if (NormalBitstream(stream, ONBOARD_TELEPHONE_NUMBERS_BITSIZE))
    {
        if (Onboard_telephone_numbers_UpperBitsNotSet(p))
        {
            uint8_t* addr = stream->addr;
            const uint32_t size = stream->size;
            const uint32_t pos = stream->bitpos;

            Bitwalker_Poke_Normal(addr, size, pos,       8,  p->NID_PACKET);
            Bitwalker_Poke_Normal(addr, size, pos + 8,   13, p->L_PACKET);
            Bitwalker_Poke_Normal(addr, size, pos + 21,  5,  p->N_ITER);
            Bitwalker_Poke_Normal(addr, size, pos + 26,  64, p->NID_RADIO_(k));

            stream->bitpos += ONBOARD_TELEPHONE_NUMBERS_BITSIZE;

            //@ assert NID_PACKET:        EqualBits(stream, pos,       pos + 8,   p->NID_PACKET);
            //@ assert L_PACKET:          EqualBits(stream, pos + 8,   pos + 21,  p->L_PACKET);
            //@ assert N_ITER:            EqualBits(stream, pos + 21,  pos + 26,  p->N_ITER);
            //@ assert NID_RADIO_(k):     EqualBits(stream, pos + 26,  pos + 90,  p->NID_RADIO_(k));

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

