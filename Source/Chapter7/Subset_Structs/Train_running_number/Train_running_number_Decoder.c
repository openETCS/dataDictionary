
#include "Train_running_number_Decoder.h"
#include "Bitwalker_Peek_Normal.h"

int Train_running_number_Decoder(Bitstream* stream, Train_running_number* p)
{
    if (NormalBitstream(stream, TRAIN_RUNNING_NUMBER_BITSIZE))
    {
        uint8_t* addr = stream->addr;
        const uint32_t size = stream->size;
        const uint32_t pos = stream->bitpos;

        p->NID_PACKET         = Bitwalker_Peek_Normal(addr, size, pos,       8);
        p->L_PACKET           = Bitwalker_Peek_Normal(addr, size, pos + 8,   13);
        p->NID_OPERATIONAL    = Bitwalker_Peek_Normal(addr, size, pos + 21,  32);

        stream->bitpos += TRAIN_RUNNING_NUMBER_BITSIZE;

        //@ assert NID_PACKET:        EqualBits(stream, pos,       pos + 8,   p->NID_PACKET);
        //@ assert L_PACKET:          EqualBits(stream, pos + 8,   pos + 21,  p->L_PACKET);
        //@ assert NID_OPERATIONAL:   EqualBits(stream, pos + 21,  pos + 53,  p->NID_OPERATIONAL);

        return 1;
    }
    else
    {
        return 0;
    }
}

