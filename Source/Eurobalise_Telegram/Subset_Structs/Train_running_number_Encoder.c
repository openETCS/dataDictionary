
#include "Train_running_number_Encoder.h"
#include "Train_running_number_UpperBitsNotSet.h"
#include "Bitstream_Write.h"

int Train_running_number_Encoder(Bitstream* stream, const Train_running_number_Core* p)
{
    if (NormalBitstream(stream, TRAIN_RUNNING_NUMBER_CORE_BITSIZE))
    {
        if (Train_running_number_UpperBitsNotSet(p))
        {
            uint8_t* addr = stream->addr;
            const uint32_t size = stream->size;
            const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 13, p->L_PACKET);
            Bitstream_Write(stream, 32, p->NID_OPERATIONAL);


            //@ assert L_PACKET:          EqualBits(stream, pos,       pos + 13,  p->L_PACKET);
            //@ assert NID_OPERATIONAL:   EqualBits(stream, pos + 13,  pos + 45,  p->NID_OPERATIONAL);

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

