
#include "Inhibition_of_balise_group_message_consistency_reaction_Data_Decoder.h"
#include "Bitwalker_Peek_Normal.h"

int Inhibition_of_balise_group_message_consistency_reaction_Data_Decoder(Bitstream* stream, Inhibition_of_balise_group_message_consistency_reaction_Data* p)
{
    if (NormalBitstream(stream, INHIBITION_OF_BALISE_GROUP_MESSAGE_CONSISTENCY_REACTION_DATA_BITSIZE))
    {
        uint8_t* addr = stream->addr;
        const uint32_t size = stream->size;
        const uint32_t pos = stream->bitpos;

        p->Q_DIR              = Bitwalker_Peek_Normal(addr, size, pos,       2);

        stream->bitpos += INHIBITION_OF_BALISE_GROUP_MESSAGE_CONSISTENCY_REACTION_DATA_BITSIZE;

        //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);

        //@ assert Q_DIR:             UpperBitsNotSet(p->Q_DIR,             2);

        return 1;
    }
    else
    {
        return 0;
    }
}

