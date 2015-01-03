
#include "Adhesion_Factor_Encoder.h"
#include "Adhesion_Factor_UpperBitsNotSet.h"
#include "Bitwalker_Poke_Normal.h"

int Adhesion_Factor_Encoder(Bitstream* stream, const Adhesion_Factor* p)
{
    if (NormalBitstream(stream, ADHESION_FACTOR_BITSIZE))
    {
        if (Adhesion_Factor_UpperBitsNotSet(p))
        {
            uint8_t* addr = stream->addr;
            const uint32_t size = stream->size;
            const uint32_t pos = stream->bitpos;

            Bitwalker_Poke_Normal(addr, size, pos,      8,  p->NID_PACKET);
            Bitwalker_Poke_Normal(addr, size, pos + 8,  2,  p->Q_DIR);
            Bitwalker_Poke_Normal(addr, size, pos + 10, 13, p->L_PACKET);
            Bitwalker_Poke_Normal(addr, size, pos + 23, 2,  p->Q_SCALE);
            Bitwalker_Poke_Normal(addr, size, pos + 25, 15, p->D_ADHESION);
            Bitwalker_Poke_Normal(addr, size, pos + 40, 15, p->L_ADHESION);
            Bitwalker_Poke_Normal(addr, size, pos + 55, 1,  p->M_ADHESION);

            stream->bitpos += ADHESION_FACTOR_BITSIZE;

            //@ assert NID_PACKET: BitstreamEqual64(stream, pos,      pos + 8,  p->NID_PACKET);
            //@ assert Q_DIR:      BitstreamEqual64(stream, pos + 8,  pos + 10, p->Q_DIR);
            //@ assert L_PACKET:   BitstreamEqual64(stream, pos + 10, pos + 23, p->L_PACKET);
            //@ assert Q_SCALE:    BitstreamEqual64(stream, pos + 23, pos + 25, p->Q_SCALE);
            //@ assert D_ADHESION: BitstreamEqual64(stream, pos + 25, pos + 40, p->D_ADHESION);
            //@ assert L_ADHESION: BitstreamEqual64(stream, pos + 40, pos + 55, p->L_ADHESION);
            //@ assert M_ADHESION: BitstreamEqual64(stream, pos + 55, pos + 56, p->M_ADHESION);

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

