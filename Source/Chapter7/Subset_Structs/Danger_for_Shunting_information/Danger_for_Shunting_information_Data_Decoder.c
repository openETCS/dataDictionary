
#include "Danger_for_Shunting_information_Data_Decoder.h"
#include "Bitwalker_Peek_Normal.h"

int Danger_for_Shunting_information_Data_Decoder(Bitstream* stream, Danger_for_Shunting_information_Data* p)
{
    if (NormalBitstream(stream, DANGER_FOR_SHUNTING_INFORMATION_DATA_BITSIZE))
    {
        uint8_t* addr = stream->addr;
        const uint32_t size = stream->size;
        const uint32_t pos = stream->bitpos;

        p->Q_DIR              = Bitwalker_Peek_Normal(addr, size, pos,       2);
        p->Q_ASPECT           = Bitwalker_Peek_Normal(addr, size, pos + 15,  1);

        stream->bitpos += DANGER_FOR_SHUNTING_INFORMATION_DATA_BITSIZE;

        //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
        //@ assert Q_ASPECT:          EqualBits(stream, pos + 15,  pos + 16,  p->Q_ASPECT);

        //@ assert Q_DIR:             UpperBitsNotSet(p->Q_DIR,             2);
        //@ assert Q_ASPECT:          UpperBitsNotSet(p->Q_ASPECT,          1);

        return 1;
    }
    else
    {
        return 0;
    }
}

