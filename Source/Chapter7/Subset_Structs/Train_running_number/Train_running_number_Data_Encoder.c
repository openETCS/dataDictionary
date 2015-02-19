
#include "Train_running_number_Data_Encoder.h"
#include "Train_running_number_Data_UpperBitsNotSet.h"
#include "Bitwalker_Poke_Normal.h"

int Train_running_number_Data_Encoder(Bitstream* stream, const Train_running_number_Data* p)
{
    if (NormalBitstream(stream, TRAIN_RUNNING_NUMBER_DATA_BITSIZE))
    {
        if (Train_running_number_Data_UpperBitsNotSet(p))
        {
            uint8_t* addr = stream->addr;
            const uint32_t size = stream->size;
            const uint32_t pos = stream->bitpos;

            Bitwalker_Poke_Normal(addr, size, pos,       32, p->NID_OPERATIONAL);

            stream->bitpos += TRAIN_RUNNING_NUMBER_DATA_BITSIZE;

            //@ assert NID_OPERATIONAL:   EqualBits(stream, pos,       pos + 32,  p->NID_OPERATIONAL);

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

