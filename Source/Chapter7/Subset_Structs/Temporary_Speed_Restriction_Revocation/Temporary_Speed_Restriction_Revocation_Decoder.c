
#include "Temporary_Speed_Restriction_Revocation_Decoder.h"
#include "Bitwalker_Peek_Normal.h"

int Temporary_Speed_Restriction_Revocation_Decoder(Bitstream* stream, Temporary_Speed_Restriction_Revocation* p)
{
    if (NormalBitstream(stream, TEMPORARY_SPEED_RESTRICTION_REVOCATION_BITSIZE))
    {
        uint8_t* addr = stream->addr;
        const uint32_t size = stream->size;
        const uint32_t pos = stream->bitpos;

        p->NID_PACKET         = Bitwalker_Peek_Normal(addr, size, pos,       8);
        p->Q_DIR              = Bitwalker_Peek_Normal(addr, size, pos + 8,   2);
        p->L_PACKET           = Bitwalker_Peek_Normal(addr, size, pos + 10,  13);
        p->NID_TSR            = Bitwalker_Peek_Normal(addr, size, pos + 23,  8);

        stream->bitpos += TEMPORARY_SPEED_RESTRICTION_REVOCATION_BITSIZE;

        //@ assert NID_PACKET:        EqualBits(stream, pos,       pos + 8,   p->NID_PACKET);
        //@ assert Q_DIR:             EqualBits(stream, pos + 8,   pos + 10,  p->Q_DIR);
        //@ assert L_PACKET:          EqualBits(stream, pos + 10,  pos + 23,  p->L_PACKET);
        //@ assert NID_TSR:           EqualBits(stream, pos + 23,  pos + 31,  p->NID_TSR);

        return 1;
    }
    else
    {
        return 0;
    }
}

