
#include "Default_Gradient_for_Temporary_Speed_Restriction_Encoder.h"
#include "Default_Gradient_for_Temporary_Speed_Restriction_UpperBitsNotSet.h"
#include "Bitstream_Write.h"

int Default_Gradient_for_Temporary_Speed_Restriction_Encoder(Bitstream* stream, const Default_Gradient_for_Temporary_Speed_Restriction_Core* p)
{
    if (NormalBitstream(stream, DEFAULT_GRADIENT_FOR_TEMPORARY_SPEED_RESTRICTION_CORE_BITSIZE))
    {
        if (Default_Gradient_for_Temporary_Speed_Restriction_UpperBitsNotSet(p))
        {
            uint8_t* addr = stream->addr;
            const uint32_t size = stream->size;
            const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 2,  p->Q_DIR);
            Bitstream_Write(stream, 13, p->L_PACKET);
            Bitstream_Write(stream, 1,  p->Q_GDIR);
            Bitstream_Write(stream, 8,  p->G_TSR);


            //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
            //@ assert L_PACKET:          EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);
            //@ assert Q_GDIR:            EqualBits(stream, pos + 15,  pos + 16,  p->Q_GDIR);
            //@ assert G_TSR:             EqualBits(stream, pos + 16,  pos + 24,  p->G_TSR);

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

