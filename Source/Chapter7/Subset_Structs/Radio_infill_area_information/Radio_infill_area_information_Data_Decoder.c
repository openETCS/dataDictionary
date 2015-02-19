
#include "Radio_infill_area_information_Data_Decoder.h"
#include "Bitwalker_Peek_Normal.h"

int Radio_infill_area_information_Data_Decoder(Bitstream* stream, Radio_infill_area_information_Data* p)
{
    if (NormalBitstream(stream, RADIO_INFILL_AREA_INFORMATION_DATA_BITSIZE))
    {
        uint8_t* addr = stream->addr;
        const uint32_t size = stream->size;
        const uint32_t pos = stream->bitpos;

        p->Q_DIR              = Bitwalker_Peek_Normal(addr, size, pos,       2);
        p->Q_SCALE            = Bitwalker_Peek_Normal(addr, size, pos + 15,  2);
        p->Q_RIU              = Bitwalker_Peek_Normal(addr, size, pos + 17,  1);
        p->NID_C              = Bitwalker_Peek_Normal(addr, size, pos + 18,  10);
        p->NID_RIU            = Bitwalker_Peek_Normal(addr, size, pos + 28,  14);
        p->NID_RADIO          = Bitwalker_Peek_Normal(addr, size, pos + 42,  64);
        p->D_INFILL           = Bitwalker_Peek_Normal(addr, size, pos + 106, 15);
        p->NID_BG             = Bitwalker_Peek_Normal(addr, size, pos + 121, 14);

        stream->bitpos += RADIO_INFILL_AREA_INFORMATION_DATA_BITSIZE;

        //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
        //@ assert Q_SCALE:           EqualBits(stream, pos + 15,  pos + 17,  p->Q_SCALE);
        //@ assert Q_RIU:             EqualBits(stream, pos + 17,  pos + 18,  p->Q_RIU);
        //@ assert NID_C:             EqualBits(stream, pos + 18,  pos + 28,  p->NID_C);
        //@ assert NID_RIU:           EqualBits(stream, pos + 28,  pos + 42,  p->NID_RIU);
        //@ assert NID_RADIO:         EqualBits(stream, pos + 42,  pos + 106, p->NID_RADIO);
        //@ assert D_INFILL:          EqualBits(stream, pos + 106, pos + 121, p->D_INFILL);
        //@ assert NID_BG:            EqualBits(stream, pos + 121, pos + 135, p->NID_BG);

        //@ assert Q_DIR:             UpperBitsNotSet(p->Q_DIR,             2);
        //@ assert Q_SCALE:           UpperBitsNotSet(p->Q_SCALE,           2);
        //@ assert Q_RIU:             UpperBitsNotSet(p->Q_RIU,             1);
        //@ assert NID_C:             UpperBitsNotSet(p->NID_C,             10);
        //@ assert NID_RIU:           UpperBitsNotSet(p->NID_RIU,           14);
        //@ assert NID_RADIO:         UpperBitsNotSet(p->NID_RADIO,         64);
        //@ assert D_INFILL:          UpperBitsNotSet(p->D_INFILL,          15);
        //@ assert NID_BG:            UpperBitsNotSet(p->NID_BG,            14);

        return 1;
    }
    else
    {
        return 0;
    }
}

