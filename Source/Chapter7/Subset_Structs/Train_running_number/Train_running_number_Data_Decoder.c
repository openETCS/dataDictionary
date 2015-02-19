
#include "Train_running_number_Data_Decoder.h"
#include "Bitwalker_Peek_Normal.h"

int Train_running_number_Data_Decoder(Bitstream* stream, Train_running_number_Data* p)
{
    if (NormalBitstream(stream, TRAIN_RUNNING_NUMBER_DATA_BITSIZE))
    {
        uint8_t* addr = stream->addr;
        const uint32_t size = stream->size;
        const uint32_t pos = stream->bitpos;

        p->NID_OPERATIONAL    = Bitwalker_Peek_Normal(addr, size, pos,       32);

        stream->bitpos += TRAIN_RUNNING_NUMBER_DATA_BITSIZE;

        //@ assert NID_OPERATIONAL:   EqualBits(stream, pos,       pos + 32,  p->NID_OPERATIONAL);

        //@ assert NID_OPERATIONAL:   UpperBitsNotSet(p->NID_OPERATIONAL,   32);

        return 1;
    }
    else
    {
        return 0;
    }
}

