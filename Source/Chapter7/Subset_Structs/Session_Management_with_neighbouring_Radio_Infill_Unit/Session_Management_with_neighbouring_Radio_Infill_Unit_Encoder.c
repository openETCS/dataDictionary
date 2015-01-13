
#include "Session_Management_with_neighbouring_Radio_Infill_Unit_Encoder.h"
#include "Session_Management_with_neighbouring_Radio_Infill_Unit_UpperBitsNotSet.h"
#include "Bitwalker_Poke_Normal.h"

int Session_Management_with_neighbouring_Radio_Infill_Unit_Encoder(Bitstream* stream, const Session_Management_with_neighbouring_Radio_Infill_Unit* p)
{
    if (NormalBitstream(stream, SESSION_MANAGEMENT_WITH_NEIGHBOURING_RADIO_INFILL_UNIT_BITSIZE))
    {
        if (Session_Management_with_neighbouring_Radio_Infill_Unit_UpperBitsNotSet(p))
        {
            uint8_t* addr = stream->addr;
            const uint32_t size = stream->size;
            const uint32_t pos = stream->bitpos;

            Bitwalker_Poke_Normal(addr, size, pos,       8,  p->NID_PACKET);
            Bitwalker_Poke_Normal(addr, size, pos + 8,   2,  p->Q_DIR);
            Bitwalker_Poke_Normal(addr, size, pos + 10,  13, p->L_PACKET);
            Bitwalker_Poke_Normal(addr, size, pos + 23,  1,  p->Q_RIU);
            Bitwalker_Poke_Normal(addr, size, pos + 24,  10, p->NID_C);
            Bitwalker_Poke_Normal(addr, size, pos + 34,  14, p->NID_RIU);
            Bitwalker_Poke_Normal(addr, size, pos + 48,  64, p->NID_RADIO);

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
            return -2;
        }
    }
    else
    {
        return -1;
    }
}

