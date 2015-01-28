
#include "Train_running_number_from_RBC_Decoder.h"
#include "Bitwalker_Peek_Normal.h"

int Train_running_number_from_RBC_Decoder(Bitstream* stream, Train_running_number_from_RBC* p)
{
    if (NormalBitstream(stream, TRAIN_RUNNING_NUMBER_FROM_RBC_BITSIZE))
    {
        uint8_t* addr = stream->addr;
        const uint32_t size = stream->size;
        const uint32_t pos = stream->bitpos;

        p->NID_PACKET         = Bitwalker_Peek_Normal(addr, size, pos,       8);
        p->Q_DIR              = Bitwalker_Peek_Normal(addr, size, pos + 8,   2);
        p->L_PACKET           = Bitwalker_Peek_Normal(addr, size, pos + 10,  13);
        p->NID_OPERATIONAL    = Bitwalker_Peek_Normal(addr, size, pos + 23,  32);

        stream->bitpos += TRAIN_RUNNING_NUMBER_FROM_RBC_BITSIZE;

        //@ assert NID_PACKET:        EqualBits(stream, pos,       pos + 8,   p->NID_PACKET);
        //@ assert Q_DIR:             EqualBits(stream, pos + 8,   pos + 10,  p->Q_DIR);
        //@ assert L_PACKET:          EqualBits(stream, pos + 10,  pos + 23,  p->L_PACKET);
        //@ assert NID_OPERATIONAL:   EqualBits(stream, pos + 23,  pos + 55,  p->NID_OPERATIONAL);

        return 1;
    }
    else
    {
        return 0;
    }
}

