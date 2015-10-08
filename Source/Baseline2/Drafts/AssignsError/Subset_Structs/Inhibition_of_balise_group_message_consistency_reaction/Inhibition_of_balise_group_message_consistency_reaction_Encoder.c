
#include "Inhibition_of_balise_group_message_consistency_reaction_Encoder.h"
#include "Inhibition_of_balise_group_message_consistency_reaction_UpperBitsNotSet.h"
#include "Bitstream_Write.h"

int Inhibition_of_balise_group_message_consistency_reaction_Encoder(Bitstream* stream, const Inhibition_of_balise_group_message_consistency_reaction* p)
{
    if (NormalBitstream(stream, INHIBITION_OF_BALISE_GROUP_MESSAGE_CONSISTENCY_REACTION_BITSIZE))
    {
        if (Inhibition_of_balise_group_message_consistency_reaction_UpperBitsNotSet(p))
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

