
#include "Reversing_area_information_Decoder.h"
#include "Bitwalker_Peek_Normal.h"

int Reversing_area_information_Decoder(Bitstream* stream, Reversing_area_information* p)
{
    if (NormalBitstream(stream, REVERSING_AREA_INFORMATION_BITSIZE))
    {
        uint8_t* addr = stream->addr;
        const uint32_t size = stream->size;
        const uint32_t pos = stream->bitpos;

        p->Q_DIR              = Bitwalker_Peek_Normal(addr, size, pos,       2);
        p->L_PACKET           = Bitwalker_Peek_Normal(addr, size, pos + 2,   13);
        p->Q_SCALE            = Bitwalker_Peek_Normal(addr, size, pos + 15,  2);
        p->D_STARTREVERSE     = Bitwalker_Peek_Normal(addr, size, pos + 17,  15);
        p->L_REVERSEAREA      = Bitwalker_Peek_Normal(addr, size, pos + 32,  15);

        stream->bitpos += REVERSING_AREA_INFORMATION_BITSIZE;

        //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
        //@ assert L_PACKET:          EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);
        //@ assert Q_SCALE:           EqualBits(stream, pos + 15,  pos + 17,  p->Q_SCALE);
        //@ assert D_STARTREVERSE:    EqualBits(stream, pos + 17,  pos + 32,  p->D_STARTREVERSE);
        //@ assert L_REVERSEAREA:     EqualBits(stream, pos + 32,  pos + 47,  p->L_REVERSEAREA);

        //@ assert Q_DIR:             UpperBitsNotSet(p->Q_DIR,             2);
        //@ assert L_PACKET:          UpperBitsNotSet(p->L_PACKET,          13);
        //@ assert Q_SCALE:           UpperBitsNotSet(p->Q_SCALE,           2);
        //@ assert D_STARTREVERSE:    UpperBitsNotSet(p->D_STARTREVERSE,    15);
        //@ assert L_REVERSEAREA:     UpperBitsNotSet(p->L_REVERSEAREA,     15);

        return 1;
    }
    else
    {
        return 0;
    }
}

