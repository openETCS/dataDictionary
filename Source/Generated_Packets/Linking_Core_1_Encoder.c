
#include "Linking_Core_1_Encoder.h"
#include "Linking_Core_1_UpperBitsNotSet.h"
#include "Bitstream_Write.h"

int Linking_Core_1_Encoder(Bitstream* stream, const Linking_Core_1* p)
{
    if (NormalBitstream(stream, LINKING_CORE_1_CORE_BITSIZE))
    {
        if (Linking_Core_1_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 15, p->D_LINK_k);
            Bitstream_Write(stream, 1,  p->Q_NEWCOUNTRY_k);
            if (p->Q_NEWCOUNTRY_k == 1)
            {
            Bitstream_Write(stream, 10, p->NID_C_k);
            }

            Bitstream_Write(stream, 14, p->NID_BG_k);
            Bitstream_Write(stream, 1,  p->Q_LINKORIENTATION_k);
            Bitstream_Write(stream, 2,  p->Q_LINKREACTION_k);
            Bitstream_Write(stream, 6,  p->Q_LOCACC_k);



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

