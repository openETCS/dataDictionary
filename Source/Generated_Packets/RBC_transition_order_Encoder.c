
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


            //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
            //@ assert L_PACKET:          EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);
            //@ assert Q_SCALE:           EqualBits(stream, pos + 15,  pos + 17,  p->Q_SCALE);
            //@ assert D_RBCTR:           EqualBits(stream, pos + 17,  pos + 32,  p->D_RBCTR);
            //@ assert NID_C:             EqualBits(stream, pos + 32,  pos + 42,  p->NID_C);
            //@ assert NID_RBC:           EqualBits(stream, pos + 42,  pos + 56,  p->NID_RBC);
            //@ assert NID_RADIO:         EqualBits(stream, pos + 56,  pos + 120, p->NID_RADIO);
            //@ assert Q_SLEEPSESSION:    EqualBits(stream, pos + 120, pos + 121, p->Q_SLEEPSESSION);

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

