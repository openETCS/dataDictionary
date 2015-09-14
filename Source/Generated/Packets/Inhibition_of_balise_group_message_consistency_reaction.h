
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

    int decode(Bitstream& stream) override
    {
        return ::decode(stream, core);
    }

    int encode(Packet_Info& data, kcg_int* stream, kcg_int startAddress) const override
    {
        data.nid_packet = 145;
        data.q_dir = core.Q_DIR;
	data.valid = 1;
	data.startAddress = startAddress;

	stream[startAddress++] = header.NID_PACKET;

	return ::encode(data, stream, startAddress, core);
    }

    int decode(const Packet_Info& data, const kcg_int* stream) override
    {
        if(data.nid_packet != 145)
	{
	    return 0;
	}

	header.NID_PACKET = stream[data.startAddress];

	return ::decode(data, stream, core);
    }

};

typedef std::shared_ptr<Inhibition_of_balise_group_message_consistency_reaction> Inhibition_of_balise_group_message_consistency_reactionPtr;

#endif // INHIBITION_OF_BALISE_GROUP_MESSAGE_CONSISTENCY_REACTION_H_INCLUDED

