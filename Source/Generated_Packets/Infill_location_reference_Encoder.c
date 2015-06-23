
#include "Infill_location_reference_Encoder.h"
#include "Infill_location_reference_UpperBitsNotSet.h"
#include "Bitstream_Write.h"

int Infill_location_reference_Encoder(Bitstream* stream, const Infill_location_reference_Core* p)
{
    if (NormalBitstream(stream, INFILL_LOCATION_REFERENCE_CORE_BITSIZE))
    {
        if (Infill_location_reference_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 2,  p->Q_DIR);
            Bitstream_Write(stream, 13, p->L_PACKET);
            Bitstream_Write(stream, 1,  p->Q_NEWCOUNTRY);
            if (p->Q_NEWCOUNTRY == 1)
            {
            Bitstream_Write(stream, 10, p->NID_C);
            }

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

