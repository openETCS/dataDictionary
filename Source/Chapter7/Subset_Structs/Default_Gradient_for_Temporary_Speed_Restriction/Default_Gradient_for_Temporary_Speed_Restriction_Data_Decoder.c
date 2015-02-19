
#include "Default_Gradient_for_Temporary_Speed_Restriction_Data_Decoder.h"
#include "Bitwalker_Peek_Normal.h"

int Default_Gradient_for_Temporary_Speed_Restriction_Data_Decoder(Bitstream* stream, Default_Gradient_for_Temporary_Speed_Restriction_Data* p)
{
    if (NormalBitstream(stream, DEFAULT_GRADIENT_FOR_TEMPORARY_SPEED_RESTRICTION_DATA_BITSIZE))
    {
        uint8_t* addr = stream->addr;
        const uint32_t size = stream->size;
        const uint32_t pos = stream->bitpos;

        p->Q_DIR              = Bitwalker_Peek_Normal(addr, size, pos,       2);
        p->Q_GDIR             = Bitwalker_Peek_Normal(addr, size, pos + 15,  1);
        p->G_TSR              = Bitwalker_Peek_Normal(addr, size, pos + 16,  8);

        stream->bitpos += DEFAULT_GRADIENT_FOR_TEMPORARY_SPEED_RESTRICTION_DATA_BITSIZE;

        //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
        //@ assert Q_GDIR:            EqualBits(stream, pos + 15,  pos + 16,  p->Q_GDIR);
        //@ assert G_TSR:             EqualBits(stream, pos + 16,  pos + 24,  p->G_TSR);

        //@ assert Q_DIR:             UpperBitsNotSet(p->Q_DIR,             2);
        //@ assert Q_GDIR:            UpperBitsNotSet(p->Q_GDIR,            1);
        //@ assert G_TSR:             UpperBitsNotSet(p->G_TSR,             8);

        return 1;
    }
    else
    {
        return 0;
    }
}

