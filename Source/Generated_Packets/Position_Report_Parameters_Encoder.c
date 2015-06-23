
#include "Position_Report_Parameters_Encoder.h"
#include "Position_Report_Parameters_UpperBitsNotSet.h"
#include "Bitstream_Write.h"
#include "Position_Report_Parameters_Core_1_Encoder.h"

int Position_Report_Parameters_Encoder(Bitstream* stream, const Position_Report_Parameters_Core* p)
{
    if (NormalBitstream(stream, POSITION_REPORT_PARAMETERS_CORE_BITSIZE))
    {
        if (Position_Report_Parameters_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 2,  p->Q_DIR);
            Bitstream_Write(stream, 13, p->L_PACKET);
            Bitstream_Write(stream, 2,  p->Q_SCALE);
            Bitstream_Write(stream, 8,  p->T_CYCLOC);
            Bitstream_Write(stream, 15, p->D_CYCLOC);
            Bitstream_Write(stream, 3,  p->M_LOC);
            Bitstream_Write(stream, 5,  p->N_ITER_1);
            for (uint32_t i = 0; i < p->N_ITER_1; ++i)
            {
                Position_Report_Parameters_Core_1_Encoder(stream, &(p->sub_1[i]));
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

