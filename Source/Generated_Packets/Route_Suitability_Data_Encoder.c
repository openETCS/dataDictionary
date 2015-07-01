
#include "Route_Suitability_Data_Encoder.h"
#include "Route_Suitability_Data_UpperBitsNotSet.h"
#include "Bitstream_Write.h"
#include "Route_Suitability_Data_Core_1_Encoder.h"

int Route_Suitability_Data_Encoder(Bitstream* stream, const Route_Suitability_Data_Core* p)
{
    if (NormalBitstream(stream, ROUTE_SUITABILITY_DATA_CORE_BITSIZE))
    {
        if (Route_Suitability_Data_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 2,  p->Q_DIR);
            Bitstream_Write(stream, 13, p->L_PACKET);
            Bitstream_Write(stream, 2,  p->Q_SCALE);
            Bitstream_Write(stream, 1,  p->Q_TRACKINIT);
            if (p->Q_TRACKINIT == 1)
            {
            Bitstream_Write(stream, 15, p->D_TRACKINIT);
            }

            if (p->Q_TRACKINIT == 0)
            {
            Bitstream_Write(stream, 15, p->D_SUITABILITY);
            Bitstream_Write(stream, 2,  p->Q_SUITABILITY);
            if (p->Q_SUITABILITY == 0)
            {
            Bitstream_Write(stream, 8,  p->M_LINEGAUGE);
            }

            if (p->Q_SUITABILITY == 1)
            {
            Bitstream_Write(stream, 7,  p->M_AXLELOADCAT);
            }

            if (p->Q_SUITABILITY == 2)
            {
            Bitstream_Write(stream, 4,  p->M_VOLTAGE);
            }

            if ((p->Q_SUITABILITY == 2) && (p->M_VOLTAGE != 0))
            {
            Bitstream_Write(stream, 10, p->NID_CTRACTION);
            }

            Bitstream_Write(stream, 5,  p->N_ITER_1);
            for (uint32_t i = 0; i < p->N_ITER_1; ++i)
            {
                Route_Suitability_Data_Core_1_Encoder(stream, &(p->sub_1[i]));
            }
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

