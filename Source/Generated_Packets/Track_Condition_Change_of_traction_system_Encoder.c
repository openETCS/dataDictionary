
#include "Track_Condition_Change_of_traction_system_Encoder.h"
#include "Track_Condition_Change_of_traction_system_UpperBitsNotSet.h"
#include "Bitstream_Write.h"

int Track_Condition_Change_of_traction_system_Encoder(Bitstream* stream, const Track_Condition_Change_of_traction_system_Core* p)
{
    if (NormalBitstream(stream, TRACK_CONDITION_CHANGE_OF_TRACTION_SYSTEM_CORE_BITSIZE))
    {
        if (Track_Condition_Change_of_traction_system_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 2,  p->Q_DIR);
            Bitstream_Write(stream, 13, p->L_PACKET);
            Bitstream_Write(stream, 2,  p->Q_SCALE);
            Bitstream_Write(stream, 15, p->D_TRACTION);
            Bitstream_Write(stream, 4,  p->M_VOLTAGE);
            if (p->M_VOLTAGE != 0)
            {
            Bitstream_Write(stream, 10, p->NID_CTRACTION);
            }



            //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
            //@ assert L_PACKET:          EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);
            //@ assert Q_SCALE:           EqualBits(stream, pos + 15,  pos + 17,  p->Q_SCALE);
            //@ assert D_TRACTION:        EqualBits(stream, pos + 17,  pos + 32,  p->D_TRACTION);
            //@ assert M_VOLTAGE:         EqualBits(stream, pos + 32,  pos + 36,  p->M_VOLTAGE);

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

