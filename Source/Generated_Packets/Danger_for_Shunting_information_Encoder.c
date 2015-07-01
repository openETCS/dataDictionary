
#include "Danger_for_Shunting_information_Encoder.h"
#include "Danger_for_Shunting_information_UpperBitsNotSet.h"
#include "Bitstream_Write.h"

int Danger_for_Shunting_information_Encoder(Bitstream* stream, const Danger_for_Shunting_information_Core* p)
{
    if (NormalBitstream(stream, DANGER_FOR_SHUNTING_INFORMATION_CORE_BITSIZE))
    {
        if (Danger_for_Shunting_information_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 2,  p->Q_DIR);
            Bitstream_Write(stream, 13, p->L_PACKET);
            Bitstream_Write(stream, 1,  p->Q_ASPECT);



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

