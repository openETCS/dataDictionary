
#include "Default_Gradient_for_Temporary_Speed_Restriction_Encoder.h"
#include "Default_Gradient_for_Temporary_Speed_Restriction_UpperBitsNotSet.h"
#include "Bitwalker_Poke_Normal.h"

int Default_Gradient_for_Temporary_Speed_Restriction_Encoder(Bitstream* stream, const Default_Gradient_for_Temporary_Speed_Restriction* p)
{
    if (NormalBitstream(stream, DEFAULT_GRADIENT_FOR_TEMPORARY_SPEED_RESTRICTION_BITSIZE))
    {
        if (Default_Gradient_for_Temporary_Speed_Restriction_UpperBitsNotSet(p))
        {
            uint8_t* addr = stream->addr;
            const uint32_t size = stream->size;
            const uint32_t pos = stream->bitpos;

            Bitwalker_Poke_Normal(addr, size, pos,       8,  p->NID_PACKET);
            Bitwalker_Poke_Normal(addr, size, pos + 8,   2,  p->Q_DIR);
            Bitwalker_Poke_Normal(addr, size, pos + 10,  13, p->L_PACKET);
            Bitwalker_Poke_Normal(addr, size, pos + 23,  1,  p->Q_GDIR);
            Bitwalker_Poke_Normal(addr, size, pos + 24,  8,  p->G_TSR);

            stream->bitpos += DEFAULT_GRADIENT_FOR_TEMPORARY_SPEED_RESTRICTION_BITSIZE;

            //@ assert NID_PACKET:        EqualBits(stream, pos,       pos + 8,   p->NID_PACKET);
            //@ assert Q_DIR:             EqualBits(stream, pos + 8,   pos + 10,  p->Q_DIR);
            //@ assert L_PACKET:          EqualBits(stream, pos + 10,  pos + 23,  p->L_PACKET);
            //@ assert Q_GDIR:            EqualBits(stream, pos + 23,  pos + 24,  p->Q_GDIR);
            //@ assert G_TSR:             EqualBits(stream, pos + 24,  pos + 32,  p->G_TSR);

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

