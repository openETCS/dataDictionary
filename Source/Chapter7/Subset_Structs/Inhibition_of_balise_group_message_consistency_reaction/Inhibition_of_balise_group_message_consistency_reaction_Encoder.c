
#include "Inhibition_of_balise_group_message_consistency_reaction_Encoder.h"
#include "Inhibition_of_balise_group_message_consistency_reaction_UpperBitsNotSet.h"
#include "Bitwalker_Poke_Normal.h"

int Inhibition_of_balise_group_message_consistency_reaction_Encoder(Bitstream* stream, const Inhibition_of_balise_group_message_consistency_reaction* p)
{
    if (NormalBitstream(stream, INHIBITION_OF_BALISE_GROUP_MESSAGE_CONSISTENCY_REACTION_BITSIZE))
    {
        if (Inhibition_of_balise_group_message_consistency_reaction_UpperBitsNotSet(p))
        {
            uint8_t* addr = stream->addr;
            const uint32_t size = stream->size;
            const uint32_t pos = stream->bitpos;

            Bitwalker_Poke_Normal(addr, size, pos,       8,  p->NID_PACKET);
            Bitwalker_Poke_Normal(addr, size, pos + 8,   2,  p->Q_DIR);
            Bitwalker_Poke_Normal(addr, size, pos + 10,  13, p->L_PACKET);

            stream->bitpos += INHIBITION_OF_BALISE_GROUP_MESSAGE_CONSISTENCY_REACTION_BITSIZE;

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

