
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

