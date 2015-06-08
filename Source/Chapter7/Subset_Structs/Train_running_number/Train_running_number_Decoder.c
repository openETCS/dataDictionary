
#include "Train_running_number_Decoder.h"
#include "Bitwalker_Peek_Normal.h"

int Train_running_number_Decoder(Bitstream* stream, Train_running_number* p)
{
    if (NormalBitstream(stream, TRAIN_RUNNING_NUMBER_BITSIZE))
    {
        uint8_t* addr = stream->addr;
        const uint32_t size = stream->size;
        const uint32_t pos = stream->bitpos;

        p->L_PACKET           = Bitwalker_Peek_Normal(addr, size, pos,       13);
        p->NID_OPERATIONAL    = Bitwalker_Peek_Normal(addr, size, pos + 13,  32);

        stream->bitpos += TRAIN_RUNNING_NUMBER_BITSIZE;

        //@ assert L_PACKET:          EqualBits(stream, pos,       pos + 13,  p->L_PACKET);
        //@ assert NID_OPERATIONAL:   EqualBits(stream, pos + 13,  pos + 45,  p->NID_OPERATIONAL);

        //@ assert L_PACKET:          UpperBitsNotSet(p->L_PACKET,          13);
        //@ assert NID_OPERATIONAL:   UpperBitsNotSet(p->NID_OPERATIONAL,   32);

        return 1;
    }
    else
    {
        return 0;
    }
}

