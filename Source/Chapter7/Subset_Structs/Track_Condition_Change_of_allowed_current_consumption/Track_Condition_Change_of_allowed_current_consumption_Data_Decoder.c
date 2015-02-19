
#include "Track_Condition_Change_of_allowed_current_consumption_Data_Decoder.h"
#include "Bitwalker_Peek_Normal.h"

int Track_Condition_Change_of_allowed_current_consumption_Data_Decoder(Bitstream* stream, Track_Condition_Change_of_allowed_current_consumption_Data* p)
{
    if (NormalBitstream(stream, TRACK_CONDITION_CHANGE_OF_ALLOWED_CURRENT_CONSUMPTION_DATA_BITSIZE))
    {
        uint8_t* addr = stream->addr;
        const uint32_t size = stream->size;
        const uint32_t pos = stream->bitpos;

        p->Q_DIR              = Bitwalker_Peek_Normal(addr, size, pos,       2);
        p->Q_SCALE            = Bitwalker_Peek_Normal(addr, size, pos + 15,  2);
        p->D_CURRENT          = Bitwalker_Peek_Normal(addr, size, pos + 17,  15);
        p->M_CURRENT          = Bitwalker_Peek_Normal(addr, size, pos + 32,  10);

        stream->bitpos += TRACK_CONDITION_CHANGE_OF_ALLOWED_CURRENT_CONSUMPTION_DATA_BITSIZE;

        //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
        //@ assert Q_SCALE:           EqualBits(stream, pos + 15,  pos + 17,  p->Q_SCALE);
        //@ assert D_CURRENT:         EqualBits(stream, pos + 17,  pos + 32,  p->D_CURRENT);
        //@ assert M_CURRENT:         EqualBits(stream, pos + 32,  pos + 42,  p->M_CURRENT);

        //@ assert Q_DIR:             UpperBitsNotSet(p->Q_DIR,             2);
        //@ assert Q_SCALE:           UpperBitsNotSet(p->Q_SCALE,           2);
        //@ assert D_CURRENT:         UpperBitsNotSet(p->D_CURRENT,         15);
        //@ assert M_CURRENT:         UpperBitsNotSet(p->M_CURRENT,         10);

        return 1;
    }
    else
    {
        return 0;
    }
}

