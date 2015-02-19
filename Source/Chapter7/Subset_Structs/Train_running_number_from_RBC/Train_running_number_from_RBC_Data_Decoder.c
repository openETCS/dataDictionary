
#include "Train_running_number_from_RBC_Data_Decoder.h"
#include "Bitwalker_Peek_Normal.h"

int Train_running_number_from_RBC_Data_Decoder(Bitstream* stream, Train_running_number_from_RBC_Data* p)
{
    if (NormalBitstream(stream, TRAIN_RUNNING_NUMBER_FROM_RBC_DATA_BITSIZE))
    {
        uint8_t* addr = stream->addr;
        const uint32_t size = stream->size;
        const uint32_t pos = stream->bitpos;

        p->Q_DIR              = Bitwalker_Peek_Normal(addr, size, pos,       2);
        p->NID_OPERATIONAL    = Bitwalker_Peek_Normal(addr, size, pos + 15,  32);

        stream->bitpos += TRAIN_RUNNING_NUMBER_FROM_RBC_DATA_BITSIZE;

        //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
        //@ assert NID_OPERATIONAL:   EqualBits(stream, pos + 15,  pos + 47,  p->NID_OPERATIONAL);

        //@ assert Q_DIR:             UpperBitsNotSet(p->Q_DIR,             2);
        //@ assert NID_OPERATIONAL:   UpperBitsNotSet(p->NID_OPERATIONAL,   32);

        return 1;
    }
    else
    {
        return 0;
    }
}

