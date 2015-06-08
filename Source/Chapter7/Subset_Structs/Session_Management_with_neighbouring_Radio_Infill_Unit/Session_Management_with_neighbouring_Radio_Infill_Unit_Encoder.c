
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

            Bitwalker_Poke_Normal(addr, size, pos,       2,  p->Q_DIR);
            Bitwalker_Poke_Normal(addr, size, pos + 2,   13, p->L_PACKET);
            Bitwalker_Poke_Normal(addr, size, pos + 15,  1,  p->Q_RIU);
            Bitwalker_Poke_Normal(addr, size, pos + 16,  10, p->NID_C);
            Bitwalker_Poke_Normal(addr, size, pos + 26,  14, p->NID_RIU);
            Bitwalker_Poke_Normal(addr, size, pos + 40,  64, p->NID_RADIO);

            stream->bitpos += SESSION_MANAGEMENT_WITH_NEIGHBOURING_RADIO_INFILL_UNIT_BITSIZE;

            //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
            //@ assert L_PACKET:          EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);
            //@ assert Q_RIU:             EqualBits(stream, pos + 15,  pos + 16,  p->Q_RIU);
            //@ assert NID_C:             EqualBits(stream, pos + 16,  pos + 26,  p->NID_C);
            //@ assert NID_RIU:           EqualBits(stream, pos + 26,  pos + 40,  p->NID_RIU);
            //@ assert NID_RADIO:         EqualBits(stream, pos + 40,  pos + 104, p->NID_RADIO);

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

