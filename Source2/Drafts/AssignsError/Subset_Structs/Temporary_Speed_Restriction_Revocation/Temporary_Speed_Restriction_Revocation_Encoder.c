
#include "Temporary_Speed_Restriction_Revocation_Encoder.h"
#include "Temporary_Speed_Restriction_Revocation_UpperBitsNotSet.h"
#include "Bitstream_Write.h"

int Temporary_Speed_Restriction_Revocation_Encoder(Bitstream* stream, const Temporary_Speed_Restriction_Revocation* p)
{
    if (NormalBitstream(stream, TEMPORARY_SPEED_RESTRICTION_REVOCATION_BITSIZE))
    {
        if (Temporary_Speed_Restriction_Revocation_UpperBitsNotSet(p))
        {
            uint8_t* addr = stream->addr;
            const uint32_t size = stream->size;
            const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 2,  p->Q_DIR);
            Bitstream_Write(stream, 13, p->L_PACKET);
            Bitstream_Write(stream, 8,  p->NID_TSR);


            //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
            //@ assert L_PACKET:          EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);
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

