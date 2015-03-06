
#include "Danger_for_Shunting_information_Decoder.h"
#include "Bitwalker_Peek_Normal.h"

int Danger_for_Shunting_information_Decoder(Bitstream* stream, Danger_for_Shunting_information* p)
{
    if (NormalBitstream(stream, DANGER_FOR_SHUNTING_INFORMATION_BITSIZE))
    {
        uint8_t* addr = stream->addr;
        const uint32_t size = stream->size;
        const uint32_t pos = stream->bitpos;

        p->Q_DIR              = Bitwalker_Peek_Normal(addr, size, pos,       2);
        p->L_PACKET           = Bitwalker_Peek_Normal(addr, size, pos + 2,   13);
        p->Q_ASPECT           = Bitwalker_Peek_Normal(addr, size, pos + 15,  1);

        stream->bitpos += DANGER_FOR_SHUNTING_INFORMATION_BITSIZE;

        //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
        //@ assert L_PACKET:          EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);
        //@ assert Q_ASPECT:          EqualBits(stream, pos + 15,  pos + 16,  p->Q_ASPECT);

        //@ assert Q_DIR:             UpperBitsNotSet(p->Q_DIR,             2);
        //@ assert L_PACKET:          UpperBitsNotSet(p->L_PACKET,          13);
        //@ assert Q_ASPECT:          UpperBitsNotSet(p->Q_ASPECT,          1);

        return 1;
    }
    else
    {
        return 0;
    }
}

