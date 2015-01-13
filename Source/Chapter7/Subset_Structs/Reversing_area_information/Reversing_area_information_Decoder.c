
#include "Reversing_area_information_Decoder.h"
#include "Bitwalker_Peek_Normal.h"

int Reversing_area_information_Decoder(Bitstream* stream, Reversing_area_information* p)
{
    if (NormalBitstream(stream, REVERSING_AREA_INFORMATION_BITSIZE))
    {
        uint8_t* addr = stream->addr;
        const uint32_t size = stream->size;
        const uint32_t pos = stream->bitpos;

        p->NID_PACKET         = Bitwalker_Peek_Normal(addr, size, pos,       8);
        p->Q_DIR              = Bitwalker_Peek_Normal(addr, size, pos + 8,   2);
        p->L_PACKET           = Bitwalker_Peek_Normal(addr, size, pos + 10,  13);
        p->Q_SCALE            = Bitwalker_Peek_Normal(addr, size, pos + 23,  2);
        p->D_STARTREVERSE     = Bitwalker_Peek_Normal(addr, size, pos + 25,  15);
        p->L_REVERSEAREA      = Bitwalker_Peek_Normal(addr, size, pos + 40,  15);

        stream->bitpos += REVERSING_AREA_INFORMATION_BITSIZE;

        //@ assert NID_PACKET:        EqualBits(stream, pos,       pos + 8,   p->NID_PACKET);
        //@ assert Q_DIR:             EqualBits(stream, pos + 8,   pos + 10,  p->Q_DIR);
        //@ assert L_PACKET:          EqualBits(stream, pos + 10,  pos + 23,  p->L_PACKET);
        //@ assert Q_SCALE:           EqualBits(stream, pos + 23,  pos + 25,  p->Q_SCALE);
        //@ assert D_STARTREVERSE:    EqualBits(stream, pos + 25,  pos + 40,  p->D_STARTREVERSE);
        //@ assert L_REVERSEAREA:     EqualBits(stream, pos + 40,  pos + 55,  p->L_REVERSEAREA);

        return 1;
    }
    else
    {
        return 0;
    }
}

