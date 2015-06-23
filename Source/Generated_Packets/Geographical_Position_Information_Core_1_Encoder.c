
#include "Geographical_Position_Information_Core_1_Encoder.h"
#include "Geographical_Position_Information_Core_1_UpperBitsNotSet.h"
#include "Bitstream_Write.h"

int Geographical_Position_Information_Core_1_Encoder(Bitstream* stream, const Geographical_Position_Information_Core_1* p)
{
    if (NormalBitstream(stream, GEOGRAPHICAL_POSITION_INFORMATION_CORE_1_CORE_BITSIZE))
    {
        if (Geographical_Position_Information_Core_1_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 1,  p->Q_NEWCOUNTRY_k);
            if (p->Q_NEWCOUNTRY_k == 1)
            {
            Bitstream_Write(stream, 10, p->NID_C_k);
            }

            Bitstream_Write(stream, 14, p->NID_BG_k);
            Bitstream_Write(stream, 15, p->D_POSOFF_k);
            Bitstream_Write(stream, 1,  p->Q_MPOSITION_k);
            Bitstream_Write(stream, 24, p->M_POSITION_k);



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

