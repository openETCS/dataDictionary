
#include "Track_Condition_Change_of_traction_system_Decoder.h"
#include "Bitwalker_Peek_Normal.h"

int Track_Condition_Change_of_traction_system_Decoder(Bitstream* stream, Track_Condition_Change_of_traction_system* p)
{
    if (NormalBitstream(stream, TRACK_CONDITION_CHANGE_OF_TRACTION_SYSTEM_BITSIZE))
    {
        uint8_t* addr = stream->addr;
        const uint32_t size = stream->size;
        const uint32_t pos = stream->bitpos;

        p->NID_PACKET         = Bitwalker_Peek_Normal(addr, size, pos,       8);
        p->Q_DIR              = Bitwalker_Peek_Normal(addr, size, pos + 8,   2);
        p->L_PACKET           = Bitwalker_Peek_Normal(addr, size, pos + 10,  13);
        p->Q_SCALE            = Bitwalker_Peek_Normal(addr, size, pos + 23,  2);
        p->D_TRACTION         = Bitwalker_Peek_Normal(addr, size, pos + 25,  15);
        p->M_VOLTAGE          = Bitwalker_Peek_Normal(addr, size, pos + 40,  4);
        p->NID_CTRACTION      = Bitwalker_Peek_Normal(addr, size, pos + 44,  10);

        stream->bitpos += TRACK_CONDITION_CHANGE_OF_TRACTION_SYSTEM_BITSIZE;

        //@ assert NID_PACKET:        EqualBits(stream, pos,       pos + 8,   p->NID_PACKET);
        //@ assert Q_DIR:             EqualBits(stream, pos + 8,   pos + 10,  p->Q_DIR);
        //@ assert L_PACKET:          EqualBits(stream, pos + 10,  pos + 23,  p->L_PACKET);
        //@ assert Q_SCALE:           EqualBits(stream, pos + 23,  pos + 25,  p->Q_SCALE);
        //@ assert D_TRACTION:        EqualBits(stream, pos + 25,  pos + 40,  p->D_TRACTION);
        //@ assert M_VOLTAGE:         EqualBits(stream, pos + 40,  pos + 44,  p->M_VOLTAGE);
        //@ assert NID_CTRACTION:     EqualBits(stream, pos + 44,  pos + 54,  p->NID_CTRACTION);

        return 1;
    }
    else
    {
        return 0;
    }
}

