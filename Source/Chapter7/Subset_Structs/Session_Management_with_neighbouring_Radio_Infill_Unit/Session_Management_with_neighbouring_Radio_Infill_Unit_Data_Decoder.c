
#include "Session_Management_with_neighbouring_Radio_Infill_Unit_Data_Decoder.h"
#include "Bitwalker_Peek_Normal.h"

int Session_Management_with_neighbouring_Radio_Infill_Unit_Data_Decoder(Bitstream* stream, Session_Management_with_neighbouring_Radio_Infill_Unit_Data* p)
{
    if (NormalBitstream(stream, SESSION_MANAGEMENT_WITH_NEIGHBOURING_RADIO_INFILL_UNIT_DATA_BITSIZE))
    {
        uint8_t* addr = stream->addr;
        const uint32_t size = stream->size;
        const uint32_t pos = stream->bitpos;

        p->Q_DIR              = Bitwalker_Peek_Normal(addr, size, pos,       2);
        p->Q_RIU              = Bitwalker_Peek_Normal(addr, size, pos + 15,  1);
        p->NID_C              = Bitwalker_Peek_Normal(addr, size, pos + 16,  10);
        p->NID_RIU            = Bitwalker_Peek_Normal(addr, size, pos + 26,  14);
        p->NID_RADIO          = Bitwalker_Peek_Normal(addr, size, pos + 40,  64);

        stream->bitpos += SESSION_MANAGEMENT_WITH_NEIGHBOURING_RADIO_INFILL_UNIT_DATA_BITSIZE;

        //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
        //@ assert Q_RIU:             EqualBits(stream, pos + 15,  pos + 16,  p->Q_RIU);
        //@ assert NID_C:             EqualBits(stream, pos + 16,  pos + 26,  p->NID_C);
        //@ assert NID_RIU:           EqualBits(stream, pos + 26,  pos + 40,  p->NID_RIU);
        //@ assert NID_RADIO:         EqualBits(stream, pos + 40,  pos + 104, p->NID_RADIO);

        //@ assert Q_DIR:             UpperBitsNotSet(p->Q_DIR,             2);
        //@ assert Q_RIU:             UpperBitsNotSet(p->Q_RIU,             1);
        //@ assert NID_C:             UpperBitsNotSet(p->NID_C,             10);
        //@ assert NID_RIU:           UpperBitsNotSet(p->NID_RIU,           14);
        //@ assert NID_RADIO:         UpperBitsNotSet(p->NID_RADIO,         64);

        return 1;
    }
    else
    {
        return 0;
    }
}

