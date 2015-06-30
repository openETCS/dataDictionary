
#include "Level_Crossing_information_Encoder.h"
#include "Level_Crossing_information_UpperBitsNotSet.h"
#include "Bitstream_Write.h"

int Level_Crossing_information_Encoder(Bitstream* stream, const Level_Crossing_information_Core* p)
{
    if (NormalBitstream(stream, LEVEL_CROSSING_INFORMATION_CORE_BITSIZE))
    {
        if (Level_Crossing_information_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 2,  p->Q_DIR);
            Bitstream_Write(stream, 13, p->L_PACKET);
            Bitstream_Write(stream, 2,  p->Q_SCALE);
            Bitstream_Write(stream, 8,  p->NID_LX);
            Bitstream_Write(stream, 15, p->D_LX);
            Bitstream_Write(stream, 15, p->L_LX);
            Bitstream_Write(stream, 1,  p->Q_LXSTATUS);
            if (p->Q_LXSTATUS == 1)
            {
            Bitstream_Write(stream, 7,  p->V_LX);
            Bitstream_Write(stream, 1,  p->Q_STOPLX);
            }

            if (p->Q_STOPLX == 1)
            {
            Bitstream_Write(stream, 15, p->L_STOPLX);
            }



            //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
            //@ assert L_PACKET:          EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);
            //@ assert Q_SCALE:           EqualBits(stream, pos + 15,  pos + 17,  p->Q_SCALE);
            //@ assert NID_LX:            EqualBits(stream, pos + 17,  pos + 25,  p->NID_LX);
            //@ assert D_LX:              EqualBits(stream, pos + 25,  pos + 40,  p->D_LX);
            //@ assert L_LX:              EqualBits(stream, pos + 40,  pos + 55,  p->L_LX);
            //@ assert Q_LXSTATUS:        EqualBits(stream, pos + 55,  pos + 56,  p->Q_LXSTATUS);

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

