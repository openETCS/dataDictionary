
#include "Track_Condition_Change_of_allowed_current_consumption_Encoder.h"
#include "Track_Condition_Change_of_allowed_current_consumption_UpperBitsNotSet.h"
#include "Bitstream_Write.h"

int Track_Condition_Change_of_allowed_current_consumption_Encoder(Bitstream* stream, const Track_Condition_Change_of_allowed_current_consumption_Core* p)
{
    if (NormalBitstream(stream, TRACK_CONDITION_CHANGE_OF_ALLOWED_CURRENT_CONSUMPTION_CORE_BITSIZE))
    {
        if (Track_Condition_Change_of_allowed_current_consumption_UpperBitsNotSet(p))
        {
            uint8_t* addr = stream->addr;
            const uint32_t size = stream->size;
            const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 2,  p->Q_DIR);
            Bitstream_Write(stream, 13, p->L_PACKET);
            Bitstream_Write(stream, 2,  p->Q_SCALE);
            Bitstream_Write(stream, 15, p->D_CURRENT);
            Bitstream_Write(stream, 10, p->M_CURRENT);


            //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
            //@ assert L_PACKET:          EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);
            //@ assert Q_SCALE:           EqualBits(stream, pos + 15,  pos + 17,  p->Q_SCALE);
            //@ assert D_CURRENT:         EqualBits(stream, pos + 17,  pos + 32,  p->D_CURRENT);
            //@ assert M_CURRENT:         EqualBits(stream, pos + 32,  pos + 42,  p->M_CURRENT);

            return 1;
        }
        else
        {
            return -2;
        }
    }
    else
    {
        return -1;
    }
}

