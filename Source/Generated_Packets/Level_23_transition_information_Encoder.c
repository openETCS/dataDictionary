
#include "Level_23_transition_information_Encoder.h"
#include "Level_23_transition_information_UpperBitsNotSet.h"
#include "Bitstream_Write.h"

int Level_23_transition_information_Encoder(Bitstream* stream, const Level_23_transition_information_Core* p)
{
    if (NormalBitstream(stream, LEVEL_23_TRANSITION_INFORMATION_CORE_BITSIZE))
    {
        if (Level_23_transition_information_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 13, p->L_PACKET);
            Bitstream_Write(stream, 24, p->NID_LTRBG);



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

