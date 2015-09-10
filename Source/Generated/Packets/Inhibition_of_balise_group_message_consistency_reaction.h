
#ifndef INHIBITION_OF_BALISE_GROUP_MESSAGE_CONSISTENCY_REACTION_H_INCLUDED
#define INHIBITION_OF_BALISE_GROUP_MESSAGE_CONSISTENCY_REACTION_H_INCLUDED

#include "Bitstream.h"
#include "Inhibition_of_balise_group_message_consistency_reaction_Core.h"
#include "BasePacket.h"

struct Inhibition_of_balise_group_message_consistency_reaction : public BasePacket
{
    Inhibition_of_balise_group_message_consistency_reaction_Core core;

    Inhibition_of_balise_group_message_consistency_reaction() : BasePacket(145) {}

    void print(std::ostream& stream) const override
    {
        stream << '(' << header << ',' << core << ')';
    }

    bool equals(const BasePacket& p) const override
    {
        if (auto q = dynamic_cast<const Inhibition_of_balise_group_message_consistency_reaction*>(&p))
        {
            return header == q->header && core == q->core;
        }

        return false;
    }

    uint16_t length() const override
    {
        return  core.L_PACKET;
    }

    int encode(Bitstream& stream) const override
    {
        return ::encode(stream, core);
    }

};

typedef std::shared_ptr<Inhibition_of_balise_group_message_consistency_reaction> Inhibition_of_balise_group_message_consistency_reactionPtr;

#endif // INHIBITION_OF_BALISE_GROUP_MESSAGE_CONSISTENCY_REACTION_H_INCLUDED

