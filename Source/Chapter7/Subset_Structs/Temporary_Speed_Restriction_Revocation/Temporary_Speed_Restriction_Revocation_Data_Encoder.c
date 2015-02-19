
#include "Temporary_Speed_Restriction_Revocation_Data_Encoder.h"
#include "Temporary_Speed_Restriction_Revocation_Data_UpperBitsNotSet.h"
#include "Bitwalker_Poke_Normal.h"

int Temporary_Speed_Restriction_Revocation_Data_Encoder(Bitstream* stream, const Temporary_Speed_Restriction_Revocation_Data* p)
{
    if (NormalBitstream(stream, TEMPORARY_SPEED_RESTRICTION_REVOCATION_DATA_BITSIZE))
    {
        if (Temporary_Speed_Restriction_Revocation_Data_UpperBitsNotSet(p))
        {
            uint8_t* addr = stream->addr;
            const uint32_t size = stream->size;
            const uint32_t pos = stream->bitpos;

            Bitwalker_Poke_Normal(addr, size, pos,       2,  p->Q_DIR);
            Bitwalker_Poke_Normal(addr, size, pos + 15,  8,  p->NID_TSR);

            stream->bitpos += TEMPORARY_SPEED_RESTRICTION_REVOCATION_DATA_BITSIZE;

            //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
            //@ assert NID_TSR:           EqualBits(stream, pos + 15,  pos + 23,  p->NID_TSR);

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

