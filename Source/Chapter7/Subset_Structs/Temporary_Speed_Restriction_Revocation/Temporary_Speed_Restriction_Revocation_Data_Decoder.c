
#include "Temporary_Speed_Restriction_Revocation_Data_Decoder.h"
#include "Bitwalker_Peek_Normal.h"

int Temporary_Speed_Restriction_Revocation_Data_Decoder(Bitstream* stream, Temporary_Speed_Restriction_Revocation_Data* p)
{
    if (NormalBitstream(stream, TEMPORARY_SPEED_RESTRICTION_REVOCATION_DATA_BITSIZE))
    {
        uint8_t* addr = stream->addr;
        const uint32_t size = stream->size;
        const uint32_t pos = stream->bitpos;

        p->Q_DIR              = Bitwalker_Peek_Normal(addr, size, pos,       2);
        p->NID_TSR            = Bitwalker_Peek_Normal(addr, size, pos + 15,  8);

        stream->bitpos += TEMPORARY_SPEED_RESTRICTION_REVOCATION_DATA_BITSIZE;

        //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
        //@ assert NID_TSR:           EqualBits(stream, pos + 15,  pos + 23,  p->NID_TSR);

        //@ assert Q_DIR:             UpperBitsNotSet(p->Q_DIR,             2);
        //@ assert NID_TSR:           UpperBitsNotSet(p->NID_TSR,           8);

        return 1;
    }
    else
    {
        return 0;
    }
}

