
#include "Session_Management_with_neighbouring_Radio_Infill_Unit_Encoder.h"
#include "Session_Management_with_neighbouring_Radio_Infill_Unit_UpperBitsNotSet.h"
#include "Bitstream_Write.h"

int Session_Management_with_neighbouring_Radio_Infill_Unit_Encoder(Bitstream* stream, const Session_Management_with_neighbouring_Radio_Infill_Unit_Core* p)
{
    if (NormalBitstream(stream, SESSION_MANAGEMENT_WITH_NEIGHBOURING_RADIO_INFILL_UNIT_CORE_BITSIZE))
    {
        if (Session_Management_with_neighbouring_Radio_Infill_Unit_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 2,  p->Q_DIR);
            Bitstream_Write(stream, 13, p->L_PACKET);
            Bitstream_Write(stream, 1,  p->Q_RIU);
            Bitstream_Write(stream, 10, p->NID_C);
            Bitstream_Write(stream, 14, p->NID_RIU);
            Bitstream_Write(stream, 64, p->NID_RADIO);



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

