
#include "Inhibition_of_revocable_TSRs_from_balises_in_L23_Encoder.h"
#include "Inhibition_of_revocable_TSRs_from_balises_in_L23_UpperBitsNotSet.h"
#include "Bitwalker_Poke_Normal.h"

int Inhibition_of_revocable_TSRs_from_balises_in_L23_Encoder(Bitstream* stream, const Inhibition_of_revocable_TSRs_from_balises_in_L23* p)
{
    if (NormalBitstream(stream, INHIBITION_OF_REVOCABLE_TSRS_FROM_BALISES_IN_L23_BITSIZE))
    {
        if (Inhibition_of_revocable_TSRs_from_balises_in_L23_UpperBitsNotSet(p))
        {
            uint8_t* addr = stream->addr;
            const uint32_t size = stream->size;
            const uint32_t pos = stream->bitpos;

            Bitwalker_Poke_Normal(addr, size, pos,       2,  p->Q_DIR);
            Bitwalker_Poke_Normal(addr, size, pos + 2,   13, p->L_PACKET);

            stream->bitpos += INHIBITION_OF_REVOCABLE_TSRS_FROM_BALISES_IN_L23_BITSIZE;

            //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
            //@ assert L_PACKET:          EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);

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

