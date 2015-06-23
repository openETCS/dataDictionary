
#include "Default_Gradient_for_Temporary_Speed_Restriction_Encoder.h"
#include "Default_Gradient_for_Temporary_Speed_Restriction_UpperBitsNotSet.h"
#include "Bitstream_Write.h"

int Default_Gradient_for_Temporary_Speed_Restriction_Encoder(Bitstream* stream, const Default_Gradient_for_Temporary_Speed_Restriction_Core* p)
{
    if (NormalBitstream(stream, DEFAULT_GRADIENT_FOR_TEMPORARY_SPEED_RESTRICTION_CORE_BITSIZE))
    {
        if (Default_Gradient_for_Temporary_Speed_Restriction_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 2,  p->Q_DIR);
            Bitstream_Write(stream, 13, p->L_PACKET);
            Bitstream_Write(stream, 1,  p->Q_GDIR);
            Bitstream_Write(stream, 8,  p->G_TSR);



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

