
#include "Radio_infill_area_information_Encoder.h"
#include "Radio_infill_area_information_UpperBitsNotSet.h"
#include "Bitstream_Write.h"

int Radio_infill_area_information_Encoder(Bitstream* stream, const Radio_infill_area_information_Core* p)
{
    if (NormalBitstream(stream, RADIO_INFILL_AREA_INFORMATION_CORE_BITSIZE))
    {
        if (Radio_infill_area_information_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 2,  p->Q_DIR);
            Bitstream_Write(stream, 13, p->L_PACKET);
            Bitstream_Write(stream, 2,  p->Q_SCALE);
            Bitstream_Write(stream, 1,  p->Q_RIU);
            Bitstream_Write(stream, 10, p->NID_C);
            Bitstream_Write(stream, 14, p->NID_RIU);
            Bitstream_Write(stream, 64, p->NID_RADIO);
            Bitstream_Write(stream, 15, p->D_INFILL);
            Bitstream_Write(stream, 14, p->NID_BG);


            //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
            //@ assert L_PACKET:          EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);
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

