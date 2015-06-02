
#include "Inhibition_of_revocable_TSRs_from_balises_in_L23_Encoder.h"
#include "Inhibition_of_revocable_TSRs_from_balises_in_L23_UpperBitsNotSet.h"
#include "Bitstream_Write.h"

int Inhibition_of_revocable_TSRs_from_balises_in_L23_Encoder(Bitstream* stream, const Inhibition_of_revocable_TSRs_from_balises_in_L23_Core* p)
{
    if (NormalBitstream(stream, INHIBITION_OF_REVOCABLE_TSRS_FROM_BALISES_IN_L23_CORE_BITSIZE))
    {
        if (Inhibition_of_revocable_TSRs_from_balises_in_L23_UpperBitsNotSet(p))
        {
            uint8_t* addr = stream->addr;
            const uint32_t size = stream->size;
            const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 2,  p->Q_DIR);
            Bitstream_Write(stream, 13, p->L_PACKET);


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

