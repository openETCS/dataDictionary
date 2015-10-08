
#include "Adhesion_Factor_Encoder.h"
#include "Adhesion_Factor_UpperBitsNotSet.h"
#include "Bitstream_Write.h"

int Adhesion_Factor_Encoder(Bitstream* stream, const Adhesion_Factor* p)
{
    if (NormalBitstream(stream, ADHESION_FACTOR_BITSIZE))
    {
        if (Adhesion_Factor_UpperBitsNotSet(p))
        {
            uint8_t* addr = stream->addr;
            const uint32_t size = stream->size;
            const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 2,  p->Q_DIR);
            Bitstream_Write(stream, 13, p->L_PACKET);
            Bitstream_Write(stream, 2,  p->Q_SCALE);
            Bitstream_Write(stream, 15, p->D_ADHESION);
            Bitstream_Write(stream, 15, p->L_ADHESION);
            Bitstream_Write(stream, 1,  p->M_ADHESION);


            //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
            //@ assert L_PACKET:          EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);
            //@ assert Q_SCALE:           EqualBits(stream, pos + 15,  pos + 17,  p->Q_SCALE);
            //@ assert D_ADHESION:        EqualBits(stream, pos + 17,  pos + 32,  p->D_ADHESION);
            //@ assert L_ADHESION:        EqualBits(stream, pos + 32,  pos + 47,  p->L_ADHESION);
            //@ assert M_ADHESION:        EqualBits(stream, pos + 47,  pos + 48,  p->M_ADHESION);

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

