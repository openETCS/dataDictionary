
#include "Inhibition_of_revocable_TSRs_from_balises_in_L23_Data_Encoder.h"
#include "Inhibition_of_revocable_TSRs_from_balises_in_L23_Data_UpperBitsNotSet.h"
#include "Bitwalker_Poke_Normal.h"

int Inhibition_of_revocable_TSRs_from_balises_in_L23_Data_Encoder(Bitstream* stream, const Inhibition_of_revocable_TSRs_from_balises_in_L23_Data* p)
{
    if (NormalBitstream(stream, INHIBITION_OF_REVOCABLE_TSRS_FROM_BALISES_IN_L23_DATA_BITSIZE))
    {
        if (Inhibition_of_revocable_TSRs_from_balises_in_L23_Data_UpperBitsNotSet(p))
        {
            uint8_t* addr = stream->addr;
            const uint32_t size = stream->size;
            const uint32_t pos = stream->bitpos;

            Bitwalker_Poke_Normal(addr, size, pos,       2,  p->Q_DIR);

            stream->bitpos += INHIBITION_OF_REVOCABLE_TSRS_FROM_BALISES_IN_L23_DATA_BITSIZE;

            //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);

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

