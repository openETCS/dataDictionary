
#include "Level_Crossing_information_Decoder.h"
#include "Bitwalker_Peek_Normal.h"

int Level_Crossing_information_Decoder(Bitstream* stream, Level_Crossing_information* p)
{
    if (NormalBitstream(stream, LEVEL_CROSSING_INFORMATION_BITSIZE))
    {
        uint8_t* addr = stream->addr;
        const uint32_t size = stream->size;
        const uint32_t pos = stream->bitpos;

        p->NID_PACKET         = Bitwalker_Peek_Normal(addr, size, pos,       8);
        p->Q_DIR              = Bitwalker_Peek_Normal(addr, size, pos + 8,   2);
        p->L_PACKET           = Bitwalker_Peek_Normal(addr, size, pos + 10,  13);
        p->Q_SCALE            = Bitwalker_Peek_Normal(addr, size, pos + 23,  2);
        p->NID_LX             = Bitwalker_Peek_Normal(addr, size, pos + 25,  8);
        p->D_LX               = Bitwalker_Peek_Normal(addr, size, pos + 33,  15);
        p->L_LX               = Bitwalker_Peek_Normal(addr, size, pos + 48,  15);
        p->Q_LXSTATUS         = Bitwalker_Peek_Normal(addr, size, pos + 63,  1);
        p->V_LX               = Bitwalker_Peek_Normal(addr, size, pos + 64,  7);
        p->Q_STOPLX           = Bitwalker_Peek_Normal(addr, size, pos + 71,  1);
        p->L_STOPLX           = Bitwalker_Peek_Normal(addr, size, pos + 72,  15);

        stream->bitpos += LEVEL_CROSSING_INFORMATION_BITSIZE;

        //@ assert NID_PACKET:        EqualBits(stream, pos,       pos + 8,   p->NID_PACKET);
        //@ assert Q_DIR:             EqualBits(stream, pos + 8,   pos + 10,  p->Q_DIR);
        //@ assert L_PACKET:          EqualBits(stream, pos + 10,  pos + 23,  p->L_PACKET);
        //@ assert Q_SCALE:           EqualBits(stream, pos + 23,  pos + 25,  p->Q_SCALE);
        //@ assert NID_LX:            EqualBits(stream, pos + 25,  pos + 33,  p->NID_LX);
        //@ assert D_LX:              EqualBits(stream, pos + 33,  pos + 48,  p->D_LX);
        //@ assert L_LX:              EqualBits(stream, pos + 48,  pos + 63,  p->L_LX);
        //@ assert Q_LXSTATUS:        EqualBits(stream, pos + 63,  pos + 64,  p->Q_LXSTATUS);
        //@ assert V_LX:              EqualBits(stream, pos + 64,  pos + 71,  p->V_LX);
        //@ assert Q_STOPLX:          EqualBits(stream, pos + 71,  pos + 72,  p->Q_STOPLX);
        //@ assert L_STOPLX:          EqualBits(stream, pos + 72,  pos + 87,  p->L_STOPLX);

        return 1;
    }
    else
    {
        return 0;
    }
}

