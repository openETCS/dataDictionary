
#include "Default_balise_or_Loop_or_RIU_information_Data_Encoder.h"
#include "Default_balise_or_Loop_or_RIU_information_Data_UpperBitsNotSet.h"
#include "Bitwalker_Poke_Normal.h"

int Default_balise_or_Loop_or_RIU_information_Data_Encoder(Bitstream* stream, const Default_balise_or_Loop_or_RIU_information_Data* p)
{
    if (NormalBitstream(stream, DEFAULT_BALISE_OR_LOOP_OR_RIU_INFORMATION_DATA_BITSIZE))
    {
        if (Default_balise_or_Loop_or_RIU_information_Data_UpperBitsNotSet(p))
        {
            uint8_t* addr = stream->addr;
            const uint32_t size = stream->size;
            const uint32_t pos = stream->bitpos;

            Bitwalker_Poke_Normal(addr, size, pos,       2,  p->Q_DIR);

            stream->bitpos += DEFAULT_BALISE_OR_LOOP_OR_RIU_INFORMATION_DATA_BITSIZE;

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

