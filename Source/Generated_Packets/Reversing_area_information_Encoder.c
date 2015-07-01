
#include "Reversing_area_information_Encoder.h"
#include "Reversing_area_information_UpperBitsNotSet.h"
#include "Bitstream_Write.h"

int Reversing_area_information_Encoder(Bitstream* stream, const Reversing_area_information_Core* p)
{
    if (NormalBitstream(stream, REVERSING_AREA_INFORMATION_CORE_BITSIZE))
    {
        if (Reversing_area_information_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 2,  p->Q_DIR);
            Bitstream_Write(stream, 13, p->L_PACKET);
            Bitstream_Write(stream, 2,  p->Q_SCALE);
            Bitstream_Write(stream, 15, p->D_STARTREVERSE);
            Bitstream_Write(stream, 15, p->L_REVERSEAREA);



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

