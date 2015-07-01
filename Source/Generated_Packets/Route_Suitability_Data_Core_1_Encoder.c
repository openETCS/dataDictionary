
#include "Route_Suitability_Data_Core_1_Encoder.h"
#include "Route_Suitability_Data_Core_1_UpperBitsNotSet.h"
#include "Bitstream_Write.h"

int Route_Suitability_Data_Core_1_Encoder(Bitstream* stream, const Route_Suitability_Data_Core_1* p)
{
    if (NormalBitstream(stream, ROUTE_SUITABILITY_DATA_CORE_1_CORE_BITSIZE))
    {
        if (Route_Suitability_Data_Core_1_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 15, p->D_SUITABILITY_k);
            Bitstream_Write(stream, 2,  p->Q_SUITABILITY_k);
            if (p->Q_SUITABILITY_k == 0)
            {
            Bitstream_Write(stream, 8,  p->M_LINEGAUGE_k);
            }

            if (p->Q_SUITABILITY_k == 1)
            {
            Bitstream_Write(stream, 7,  p->M_AXLELOADCAT_k);
            }

            if (p->Q_SUITABILITY_k == 2)
            {
            Bitstream_Write(stream, 4,  p->M_VOLTAGE_k);
            }

            if ((p->Q_SUITABILITY_k == 2) && (p->M_VOLTAGE_k != 0))
            {
            Bitstream_Write(stream, 10, p->NID_CTRACTION_k);
            }




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

