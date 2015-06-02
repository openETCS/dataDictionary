
#include "Default_balise_or_Loop_or_RIU_information_Encoder.h"
#include "Default_balise_or_Loop_or_RIU_information_UpperBitsNotSet.h"
#include "Bitstream_Write.h"

int Default_balise_or_Loop_or_RIU_information_Encoder(Bitstream* stream, const Default_balise_or_Loop_or_RIU_information_Core* p)
{
    if (NormalBitstream(stream, DEFAULT_BALISE_OR_LOOP_OR_RIU_INFORMATION_CORE_BITSIZE))
    {
        if (Default_balise_or_Loop_or_RIU_information_UpperBitsNotSet(p))
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

