
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



            //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
            //@ assert L_PACKET:          EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);
            //@ assert Q_VBCO:            EqualBits(stream, pos + 15,  pos + 16,  p->Q_VBCO);
            //@ assert NID_VBCMK:         EqualBits(stream, pos + 16,  pos + 22,  p->NID_VBCMK);
            //@ assert NID_C:             EqualBits(stream, pos + 22,  pos + 32,  p->NID_C);

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

