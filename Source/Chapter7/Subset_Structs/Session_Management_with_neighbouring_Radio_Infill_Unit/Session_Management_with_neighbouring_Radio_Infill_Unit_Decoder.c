
#include "Session_Management_with_neighbouring_Radio_Infill_Unit_Decoder.h"
#include "Bitwalker_Peek_Normal.h"

int Session_Management_with_neighbouring_Radio_Infill_Unit_Decoder(Bitstream* stream, Session_Management_with_neighbouring_Radio_Infill_Unit* p)
{
    if (NormalBitstream(stream, SESSION_MANAGEMENT_WITH_NEIGHBOURING_RADIO_INFILL_UNIT_BITSIZE))
    {
        uint8_t* addr = stream->addr;
        const uint32_t size = stream->size;
        const uint32_t pos = stream->bitpos;

        p->NID_PACKET         = Bitwalker_Peek_Normal(addr, size, pos,       8);
        p->Q_DIR              = Bitwalker_Peek_Normal(addr, size, pos + 8,   2);
        p->L_PACKET           = Bitwalker_Peek_Normal(addr, size, pos + 10,  13);
        p->Q_RIU              = Bitwalker_Peek_Normal(addr, size, pos + 23,  1);
        p->NID_C              = Bitwalker_Peek_Normal(addr, size, pos + 24,  10);
        p->NID_RIU            = Bitwalker_Peek_Normal(addr, size, pos + 34,  14);
        p->NID_RADIO          = Bitwalker_Peek_Normal(addr, size, pos + 48,  64);

        stream->bitpos += SESSION_MANAGEMENT_WITH_NEIGHBOURING_RADIO_INFILL_UNIT_BITSIZE;

        //@ assert NID_PACKET:        EqualBits(stream, pos,       pos + 8,   p->NID_PACKET);
        //@ assert Q_DIR:             EqualBits(stream, pos + 8,   pos + 10,  p->Q_DIR);
        //@ assert L_PACKET:          EqualBits(stream, pos + 10,  pos + 23,  p->L_PACKET);
        //@ assert Q_RIU:             EqualBits(stream, pos + 23,  pos + 24,  p->Q_RIU);
        //@ assert NID_C:             EqualBits(stream, pos + 24,  pos + 34,  p->NID_C);
        //@ assert NID_RIU:           EqualBits(stream, pos + 34,  pos + 48,  p->NID_RIU);
        //@ assert NID_RADIO:         EqualBits(stream, pos + 48,  pos + 112, p->NID_RADIO);

        return 1;
    }
    else
    {
        return 0;
    }
}

