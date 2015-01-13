
#include "Infill_location_reference_Decoder.h"
#include "Bitwalker_Peek_Normal.h"

int Infill_location_reference_Decoder(Bitstream* stream, Infill_location_reference* p)
{
    if (NormalBitstream(stream, INFILL_LOCATION_REFERENCE_BITSIZE))
    {
        uint8_t* addr = stream->addr;
        const uint32_t size = stream->size;
        const uint32_t pos = stream->bitpos;

        p->NID_PACKET         = Bitwalker_Peek_Normal(addr, size, pos,       8);
        p->Q_DIR              = Bitwalker_Peek_Normal(addr, size, pos + 8,   2);
        p->L_PACKET           = Bitwalker_Peek_Normal(addr, size, pos + 10,  13);
        p->Q_NEWCOUNTRY       = Bitwalker_Peek_Normal(addr, size, pos + 23,  1);
        p->NID_C              = Bitwalker_Peek_Normal(addr, size, pos + 24,  10);
        p->NID_BG             = Bitwalker_Peek_Normal(addr, size, pos + 34,  14);

        stream->bitpos += INFILL_LOCATION_REFERENCE_BITSIZE;

        //@ assert NID_PACKET:        EqualBits(stream, pos,       pos + 8,   p->NID_PACKET);
        //@ assert Q_DIR:             EqualBits(stream, pos + 8,   pos + 10,  p->Q_DIR);
        //@ assert L_PACKET:          EqualBits(stream, pos + 10,  pos + 23,  p->L_PACKET);
        //@ assert Q_NEWCOUNTRY:      EqualBits(stream, pos + 23,  pos + 24,  p->Q_NEWCOUNTRY);
        //@ assert NID_C:             EqualBits(stream, pos + 24,  pos + 34,  p->NID_C);
        //@ assert NID_BG:            EqualBits(stream, pos + 34,  pos + 48,  p->NID_BG);

        return 1;
    }
    else
    {
        return 0;
    }
}

