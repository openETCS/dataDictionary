
#include "Position_Report_based_on_two_balise_groups_Encoder.h"
#include "Position_Report_based_on_two_balise_groups_UpperBitsNotSet.h"
#include "Bitstream_Write.h"

int Position_Report_based_on_two_balise_groups_Encoder(Bitstream* stream, const Position_Report_based_on_two_balise_groups_Core* p)
{
    if (NormalBitstream(stream, POSITION_REPORT_BASED_ON_TWO_BALISE_GROUPS_CORE_BITSIZE))
    {
        if (Position_Report_based_on_two_balise_groups_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 13, p->L_PACKET);
            Bitstream_Write(stream, 2,  p->Q_SCALE);
            Bitstream_Write(stream, 24, p->NID_LRBG);
            Bitstream_Write(stream, 24, p->NID_PRVLRBG);
            Bitstream_Write(stream, 15, p->D_LRBG);
            Bitstream_Write(stream, 2,  p->Q_DIRLRBG);
            Bitstream_Write(stream, 2,  p->Q_DLRBG);
            Bitstream_Write(stream, 15, p->L_DOUBTOVER);
            Bitstream_Write(stream, 15, p->L_DOUBTUNDER);
            Bitstream_Write(stream, 2,  p->Q_LENGTH);
            if ((p->Q_LENGTH == 1) || (p->Q_LENGTH == 2))
            {
            Bitstream_Write(stream, 15, p->L_TRAININT);
            }

            Bitstream_Write(stream, 7,  p->V_TRAIN);
            Bitstream_Write(stream, 2,  p->Q_DIRTRAIN);
            Bitstream_Write(stream, 4,  p->M_MODE);
            Bitstream_Write(stream, 3,  p->M_LEVEL);
            if (p->M_LEVEL == 1)
            {
            Bitstream_Write(stream, 8,  p->NID_NTC);
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

