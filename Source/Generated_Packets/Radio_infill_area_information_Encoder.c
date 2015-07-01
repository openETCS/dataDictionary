
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

