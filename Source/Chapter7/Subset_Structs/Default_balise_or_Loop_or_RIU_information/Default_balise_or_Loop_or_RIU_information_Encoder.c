
#include "Default_balise_or_Loop_or_RIU_information_Encoder.h"
#include "Default_balise_or_Loop_or_RIU_information_UpperBitsNotSet.h"
#include "Bitwalker_Poke_Normal.h"

int Default_balise_or_Loop_or_RIU_information_Encoder(Bitstream* stream, const Default_balise_or_Loop_or_RIU_information* p)
{
    if (NormalBitstream(stream, DEFAULT_BALISE_OR_LOOP_OR_RIU_INFORMATION_BITSIZE))
    {
        if (Default_balise_or_Loop_or_RIU_information_UpperBitsNotSet(p))
        {
            uint8_t* addr = stream->addr;
            const uint32_t size = stream->size;
            const uint32_t pos = stream->bitpos;

            Bitwalker_Poke_Normal(addr, size, pos,       8,  p->NID_PACKET);
            Bitwalker_Poke_Normal(addr, size, pos + 8,   2,  p->Q_DIR);
            Bitwalker_Poke_Normal(addr, size, pos + 10,  13, p->L_PACKET);

            stream->bitpos += DEFAULT_BALISE_OR_LOOP_OR_RIU_INFORMATION_BITSIZE;

            //@ assert NID_PACKET:        EqualBits(stream, pos,       pos + 8,   p->NID_PACKET);
            //@ assert Q_DIR:             EqualBits(stream, pos + 8,   pos + 10,  p->Q_DIR);
            //@ assert L_PACKET:          EqualBits(stream, pos + 10,  pos + 23,  p->L_PACKET);

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

