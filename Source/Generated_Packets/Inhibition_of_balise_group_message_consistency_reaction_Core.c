
#include "Inhibition_of_balise_group_message_consistency_reaction_Core.h"
#include "UpperBitsNotSet.h"
#include "Bitstream_Write.h"
#include "Bitstream_Read.h"

int Inhibition_of_balise_group_message_consistency_reaction_UpperBitsNotSet(const Inhibition_of_balise_group_message_consistency_reaction_Core* p)
{
    bool status = true;

    status = status && UpperBitsNotSet64(p->Q_DIR,             2) ;
    status = status && UpperBitsNotSet64(p->L_PACKET,          13);

    if (status)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int Inhibition_of_balise_group_message_consistency_reaction_Encoder(Bitstream* stream, const Inhibition_of_balise_group_message_consistency_reaction_Core* p)
{
    if (NormalBitstream(stream, INHIBITION_OF_BALISE_GROUP_MESSAGE_CONSISTENCY_REACTION_CORE_BITSIZE))
    {
        if (Inhibition_of_balise_group_message_consistency_reaction_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 2,  p->Q_DIR);
            Bitstream_Write(stream, 13, p->L_PACKET);



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

int Inhibition_of_balise_group_message_consistency_reaction_Decoder(Bitstream* stream, Inhibition_of_balise_group_message_consistency_reaction_Core* p)
{
    if (NormalBitstream(stream, INHIBITION_OF_BALISE_GROUP_MESSAGE_CONSISTENCY_REACTION_CORE_BITSIZE))
    {
        //@ ghost const uint32_t pos = stream->bitpos;

	{ p->Q_DIR		= Bitstream_Read(stream, 2); }

	{ p->L_PACKET		= Bitstream_Read(stream, 13); }



	//@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

