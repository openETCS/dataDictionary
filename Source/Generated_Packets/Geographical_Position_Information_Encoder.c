
#include "Geographical_Position_Information_Encoder.h"
#include "Geographical_Position_Information_UpperBitsNotSet.h"
#include "Bitstream_Write.h"
#include "Geographical_Position_Information_Core_1_Encoder.h"

int Geographical_Position_Information_Encoder(Bitstream* stream, const Geographical_Position_Information_Core* p)
{
    if (NormalBitstream(stream, GEOGRAPHICAL_POSITION_INFORMATION_CORE_BITSIZE))
    {
        if (Geographical_Position_Information_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 2,  p->Q_DIR);
            Bitstream_Write(stream, 13, p->L_PACKET);
            Bitstream_Write(stream, 2,  p->Q_SCALE);
            Bitstream_Write(stream, 1,  p->Q_NEWCOUNTRY);
            if (p->Q_NEWCOUNTRY == 1)
            {
            Bitstream_Write(stream, 10, p->NID_C);
            }

            Bitstream_Write(stream, 14, p->NID_BG);
            Bitstream_Write(stream, 15, p->D_POSOFF);
            Bitstream_Write(stream, 1,  p->Q_MPOSITION);
            Bitstream_Write(stream, 24, p->M_POSITION);
            Bitstream_Write(stream, 5,  p->N_ITER_1);
            for (uint32_t i = 0; i < p->N_ITER_1; ++i)
            {
                Geographical_Position_Information_Core_1_Encoder(stream, &(p->sub_1[i]));
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

