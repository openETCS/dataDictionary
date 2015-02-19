
#include "Radio_infill_area_information_Data_Encoder.h"
#include "Radio_infill_area_information_Data_UpperBitsNotSet.h"
#include "Bitwalker_Poke_Normal.h"

int Radio_infill_area_information_Data_Encoder(Bitstream* stream, const Radio_infill_area_information_Data* p)
{
    if (NormalBitstream(stream, RADIO_INFILL_AREA_INFORMATION_DATA_BITSIZE))
    {
        if (Radio_infill_area_information_Data_UpperBitsNotSet(p))
        {
            uint8_t* addr = stream->addr;
            const uint32_t size = stream->size;
            const uint32_t pos = stream->bitpos;

            Bitwalker_Poke_Normal(addr, size, pos,       2,  p->Q_DIR);
            Bitwalker_Poke_Normal(addr, size, pos + 15,  2,  p->Q_SCALE);
            Bitwalker_Poke_Normal(addr, size, pos + 17,  1,  p->Q_RIU);
            Bitwalker_Poke_Normal(addr, size, pos + 18,  10, p->NID_C);
            Bitwalker_Poke_Normal(addr, size, pos + 28,  14, p->NID_RIU);
            Bitwalker_Poke_Normal(addr, size, pos + 42,  64, p->NID_RADIO);
            Bitwalker_Poke_Normal(addr, size, pos + 106, 15, p->D_INFILL);
            Bitwalker_Poke_Normal(addr, size, pos + 121, 14, p->NID_BG);

            stream->bitpos += RADIO_INFILL_AREA_INFORMATION_DATA_BITSIZE;

            //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
            //@ assert Q_SCALE:           EqualBits(stream, pos + 15,  pos + 17,  p->Q_SCALE);
            //@ assert Q_RIU:             EqualBits(stream, pos + 17,  pos + 18,  p->Q_RIU);
            //@ assert NID_C:             EqualBits(stream, pos + 18,  pos + 28,  p->NID_C);
            //@ assert NID_RIU:           EqualBits(stream, pos + 28,  pos + 42,  p->NID_RIU);
            //@ assert NID_RADIO:         EqualBits(stream, pos + 42,  pos + 106, p->NID_RADIO);
            //@ assert D_INFILL:          EqualBits(stream, pos + 106, pos + 121, p->D_INFILL);
            //@ assert NID_BG:            EqualBits(stream, pos + 121, pos + 135, p->NID_BG);

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

