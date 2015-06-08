
#include "Position_Report_Encoder.h"
#include "Position_Report_UpperBitsNotSet.h"
#include "Bitstream_Write.h"

int Position_Report_Encoder(Bitstream* stream, const Position_Report_Core* p)
{
    if (NormalBitstream(stream, POSITION_REPORT_CORE_BITSIZE))
    {
        if (Position_Report_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 13, p->L_PACKET);
            Bitstream_Write(stream, 2,  p->Q_SCALE);
            Bitstream_Write(stream, 24, p->NID_LRBG);
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



            //@ assert L_PACKET:          EqualBits(stream, pos,       pos + 13,  p->L_PACKET);
            //@ assert Q_SCALE:           EqualBits(stream, pos + 13,  pos + 15,  p->Q_SCALE);
            //@ assert NID_LRBG:          EqualBits(stream, pos + 15,  pos + 39,  p->NID_LRBG);
            //@ assert D_LRBG:            EqualBits(stream, pos + 39,  pos + 54,  p->D_LRBG);
            //@ assert Q_DIRLRBG:         EqualBits(stream, pos + 54,  pos + 56,  p->Q_DIRLRBG);
            //@ assert Q_DLRBG:           EqualBits(stream, pos + 56,  pos + 58,  p->Q_DLRBG);
            //@ assert L_DOUBTOVER:       EqualBits(stream, pos + 58,  pos + 73,  p->L_DOUBTOVER);
            //@ assert L_DOUBTUNDER:      EqualBits(stream, pos + 73,  pos + 88,  p->L_DOUBTUNDER);
            //@ assert Q_LENGTH:          EqualBits(stream, pos + 88,  pos + 90,  p->Q_LENGTH);

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

