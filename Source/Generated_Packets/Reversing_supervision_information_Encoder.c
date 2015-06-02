
#include "Reversing_supervision_information_Encoder.h"
#include "Reversing_supervision_information_UpperBitsNotSet.h"
#include "Bitstream_Write.h"

int Reversing_supervision_information_Encoder(Bitstream* stream, const Reversing_supervision_information_Core* p)
{
    if (NormalBitstream(stream, REVERSING_SUPERVISION_INFORMATION_CORE_BITSIZE))
    {
        if (Reversing_supervision_information_UpperBitsNotSet(p))
        {
            uint8_t* addr = stream->addr;
            const uint32_t size = stream->size;
            const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 2,  p->Q_DIR);
            Bitstream_Write(stream, 13, p->L_PACKET);
            Bitstream_Write(stream, 2,  p->Q_SCALE);
            Bitstream_Write(stream, 15, p->D_REVERSE);
            Bitstream_Write(stream, 7,  p->V_REVERSE);


            //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
            //@ assert L_PACKET:          EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);
            //@ assert Q_SCALE:           EqualBits(stream, pos + 15,  pos + 17,  p->Q_SCALE);
            //@ assert D_REVERSE:         EqualBits(stream, pos + 17,  pos + 32,  p->D_REVERSE);
            //@ assert V_REVERSE:         EqualBits(stream, pos + 32,  pos + 39,  p->V_REVERSE);

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

