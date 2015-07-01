
#include "Virtual_Balise_Cover_order_Encoder.h"
#include "Virtual_Balise_Cover_order_UpperBitsNotSet.h"
#include "Bitstream_Write.h"

int Virtual_Balise_Cover_order_Encoder(Bitstream* stream, const Virtual_Balise_Cover_order_Core* p)
{
    if (NormalBitstream(stream, VIRTUAL_BALISE_COVER_ORDER_CORE_BITSIZE))
    {
        if (Virtual_Balise_Cover_order_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 2,  p->Q_DIR);
            Bitstream_Write(stream, 13, p->L_PACKET);
            Bitstream_Write(stream, 1,  p->Q_VBCO);
            Bitstream_Write(stream, 6,  p->NID_VBCMK);
            Bitstream_Write(stream, 10, p->NID_C);
            if (p->Q_VBCO == 1)
            {
            Bitstream_Write(stream, 8,  p->T_VBC);
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

