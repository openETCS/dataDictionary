
#include "Radio_infill_area_information_Encoder.h"
#include "Radio_infill_area_information_UpperBitsNotSet.h"
#include "Bitwalker_Poke_Normal.h"

int Radio_infill_area_information_Encoder(Bitstream* stream, const Radio_infill_area_information* p)
{
    if (NormalBitstream(stream, RADIO_INFILL_AREA_INFORMATION_BITSIZE))
    {
        if (Radio_infill_area_information_UpperBitsNotSet(p))
        {
            uint8_t* addr = stream->addr;
            const uint32_t size = stream->size;
            const uint32_t pos = stream->bitpos;

            Bitwalker_Poke_Normal(addr, size, pos,       8,  p->NID_PACKET);
            Bitwalker_Poke_Normal(addr, size, pos + 8,   2,  p->Q_DIR);
            Bitwalker_Poke_Normal(addr, size, pos + 10,  13, p->L_PACKET);
            Bitwalker_Poke_Normal(addr, size, pos + 23,  2,  p->Q_SCALE);
            Bitwalker_Poke_Normal(addr, size, pos + 25,  1,  p->Q_RIU);
            Bitwalker_Poke_Normal(addr, size, pos + 26,  10, p->NID_C);
            Bitwalker_Poke_Normal(addr, size, pos + 36,  14, p->NID_RIU);
            Bitwalker_Poke_Normal(addr, size, pos + 50,  64, p->NID_RADIO);
            Bitwalker_Poke_Normal(addr, size, pos + 114, 15, p->D_INFILL);
            Bitwalker_Poke_Normal(addr, size, pos + 129, 14, p->NID_BG);

            stream->bitpos += RADIO_INFILL_AREA_INFORMATION_BITSIZE;

            //@ assert NID_PACKET:        EqualBits(stream, pos,       pos + 8,   p->NID_PACKET);
            //@ assert Q_DIR:             EqualBits(stream, pos + 8,   pos + 10,  p->Q_DIR);
            //@ assert L_PACKET:          EqualBits(stream, pos + 10,  pos + 23,  p->L_PACKET);
            //@ assert Q_SCALE:           EqualBits(stream, pos + 23,  pos + 25,  p->Q_SCALE);
            //@ assert Q_RIU:             EqualBits(stream, pos + 25,  pos + 26,  p->Q_RIU);
            //@ assert NID_C:             EqualBits(stream, pos + 26,  pos + 36,  p->NID_C);
            //@ assert NID_RIU:           EqualBits(stream, pos + 36,  pos + 50,  p->NID_RIU);
            //@ assert NID_RADIO:         EqualBits(stream, pos + 50,  pos + 114, p->NID_RADIO);
            //@ assert D_INFILL:          EqualBits(stream, pos + 114, pos + 129, p->D_INFILL);
            //@ assert NID_BG:            EqualBits(stream, pos + 129, pos + 143, p->NID_BG);

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

