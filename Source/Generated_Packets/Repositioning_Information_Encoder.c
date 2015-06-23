
#include "Repositioning_Information_Encoder.h"
#include "Repositioning_Information_UpperBitsNotSet.h"
#include "Bitstream_Write.h"

int Repositioning_Information_Encoder(Bitstream* stream, const Repositioning_Information_Core* p)
{
    if (NormalBitstream(stream, REPOSITIONING_INFORMATION_CORE_BITSIZE))
    {
        if (Repositioning_Information_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 2,  p->Q_DIR);
            Bitstream_Write(stream, 13, p->L_PACKET);
            Bitstream_Write(stream, 2,  p->Q_SCALE);
            Bitstream_Write(stream, 15, p->L_SECTION);



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

