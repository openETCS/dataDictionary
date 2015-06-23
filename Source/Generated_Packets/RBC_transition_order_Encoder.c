
#include "RBC_transition_order_Encoder.h"
#include "RBC_transition_order_UpperBitsNotSet.h"
#include "Bitstream_Write.h"

int RBC_transition_order_Encoder(Bitstream* stream, const RBC_transition_order_Core* p)
{
    if (NormalBitstream(stream, RBC_TRANSITION_ORDER_CORE_BITSIZE))
    {
        if (RBC_transition_order_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 2,  p->Q_DIR);
            Bitstream_Write(stream, 13, p->L_PACKET);
            Bitstream_Write(stream, 2,  p->Q_SCALE);
            Bitstream_Write(stream, 15, p->D_RBCTR);
            Bitstream_Write(stream, 10, p->NID_C);
            Bitstream_Write(stream, 14, p->NID_RBC);
            Bitstream_Write(stream, 64, p->NID_RADIO);
            Bitstream_Write(stream, 1,  p->Q_SLEEPSESSION);



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

