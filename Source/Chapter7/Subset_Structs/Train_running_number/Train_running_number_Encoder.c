
#include "Train_running_number_Encoder.h"
#include "Train_running_number_UpperBitsNotSet.h"
#include "Bitwalker_Poke_Normal.h"

int Train_running_number_Encoder(Bitstream* stream, const Train_running_number* p)
{
    if (NormalBitstream(stream, TRAIN_RUNNING_NUMBER_BITSIZE))
    {
        if (Train_running_number_UpperBitsNotSet(p))
        {
            uint8_t* addr = stream->addr;
            const uint32_t size = stream->size;
            const uint32_t pos = stream->bitpos;

            Bitwalker_Poke_Normal(addr, size, pos,       8,  p->NID_PACKET);
            Bitwalker_Poke_Normal(addr, size, pos + 8,   13, p->L_PACKET);
            Bitwalker_Poke_Normal(addr, size, pos + 21,  32, p->NID_OPERATIONAL);

            stream->bitpos += TRAIN_RUNNING_NUMBER_BITSIZE;

            //@ assert NID_PACKET:        EqualBits(stream, pos,       pos + 8,   p->NID_PACKET);
            //@ assert L_PACKET:          EqualBits(stream, pos + 8,   pos + 21,  p->L_PACKET);
            //@ assert NID_OPERATIONAL:   EqualBits(stream, pos + 21,  pos + 53,  p->NID_OPERATIONAL);

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

