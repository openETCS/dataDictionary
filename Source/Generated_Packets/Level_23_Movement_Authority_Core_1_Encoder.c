
#include "Level_23_Movement_Authority_Core_1_Encoder.h"
#include "Level_23_Movement_Authority_Core_1_UpperBitsNotSet.h"
#include "Bitstream_Write.h"

int Level_23_Movement_Authority_Core_1_Encoder(Bitstream* stream, const Level_23_Movement_Authority_Core_1* p)
{
    if (NormalBitstream(stream, LEVEL_23_MOVEMENT_AUTHORITY_CORE_1_CORE_BITSIZE))
    {
        if (Level_23_Movement_Authority_Core_1_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 15, p->L_SECTION_k);
            Bitstream_Write(stream, 1,  p->Q_SECTIONTIMER_k);
            Bitstream_Write(stream, 10, p->T_SECTIONTIMER_k);
            Bitstream_Write(stream, 15, p->D_SECTIONTIMERSTOPLOC_k);



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

