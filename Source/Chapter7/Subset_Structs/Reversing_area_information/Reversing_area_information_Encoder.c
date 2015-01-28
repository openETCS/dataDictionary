
#include "Reversing_area_information_Encoder.h"
#include "Reversing_area_information_UpperBitsNotSet.h"
#include "Bitwalker_Poke_Normal.h"

int Reversing_area_information_Encoder(Bitstream* stream, const Reversing_area_information* p)
{
    if (NormalBitstream(stream, REVERSING_AREA_INFORMATION_BITSIZE))
    {
        if (Reversing_area_information_UpperBitsNotSet(p))
        {
            uint8_t* addr = stream->addr;
            const uint32_t size = stream->size;
            const uint32_t pos = stream->bitpos;

            Bitwalker_Poke_Normal(addr, size, pos,       8,  p->NID_PACKET);
            Bitwalker_Poke_Normal(addr, size, pos + 8,   2,  p->Q_DIR);
            Bitwalker_Poke_Normal(addr, size, pos + 10,  13, p->L_PACKET);
            Bitwalker_Poke_Normal(addr, size, pos + 23,  2,  p->Q_SCALE);
            Bitwalker_Poke_Normal(addr, size, pos + 25,  15, p->D_STARTREVERSE);
            Bitwalker_Poke_Normal(addr, size, pos + 40,  15, p->L_REVERSEAREA);

            stream->bitpos += REVERSING_AREA_INFORMATION_BITSIZE;

            //@ assert NID_PACKET:        EqualBits(stream, pos,       pos + 8,   p->NID_PACKET);
            //@ assert Q_DIR:             EqualBits(stream, pos + 8,   pos + 10,  p->Q_DIR);
            //@ assert L_PACKET:          EqualBits(stream, pos + 10,  pos + 23,  p->L_PACKET);
            //@ assert Q_SCALE:           EqualBits(stream, pos + 23,  pos + 25,  p->Q_SCALE);
            //@ assert D_STARTREVERSE:    EqualBits(stream, pos + 25,  pos + 40,  p->D_STARTREVERSE);
            //@ assert L_REVERSEAREA:     EqualBits(stream, pos + 40,  pos + 55,  p->L_REVERSEAREA);

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

