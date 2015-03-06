
#include "Train_running_number_from_RBC_Encoder.h"
#include "Train_running_number_from_RBC_UpperBitsNotSet.h"
#include "Bitwalker_Poke_Normal.h"

int Train_running_number_from_RBC_Encoder(Bitstream* stream, const Train_running_number_from_RBC* p)
{
    if (NormalBitstream(stream, TRAIN_RUNNING_NUMBER_FROM_RBC_BITSIZE))
    {
        if (Train_running_number_from_RBC_UpperBitsNotSet(p))
        {
            uint8_t* addr = stream->addr;
            const uint32_t size = stream->size;
            const uint32_t pos = stream->bitpos;

            Bitwalker_Poke_Normal(addr, size, pos,       2,  p->Q_DIR);
            Bitwalker_Poke_Normal(addr, size, pos + 2,   13, p->L_PACKET);
            Bitwalker_Poke_Normal(addr, size, pos + 15,  32, p->NID_OPERATIONAL);

            stream->bitpos += TRAIN_RUNNING_NUMBER_FROM_RBC_BITSIZE;

            //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
            //@ assert L_PACKET:          EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);
            //@ assert NID_OPERATIONAL:   EqualBits(stream, pos + 15,  pos + 47,  p->NID_OPERATIONAL);

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

