
#ifndef PACKET_FOR_SENDING_FIXED_TEXT_MESSAGES_H_INCLUDED
#define PACKET_FOR_SENDING_FIXED_TEXT_MESSAGES_H_INCLUDED

#include "Bitstream.h"
#include "Packet_for_sending_fixed_text_messages_Core.h"
#include "BasePacket.h"

struct Packet_for_sending_fixed_text_messages : public BasePacket
{
    Packet_for_sending_fixed_text_messages_Core core;

    Packet_for_sending_fixed_text_messages() : BasePacket(76) {}

    void print(std::ostream& stream) const override
    {
        stream << '(' << +header.NID_PACKET << ',' << core << ')';
    }

    bool equals(const BasePacket& p) const override
    {
	if(auto q = dynamic_cast<const Packet_for_sending_fixed_text_messages*>(&p))
	{
	    bool status = true;

	    status = status && (header.NID_PACKET == q->header.NID_PACKET);
	    status = status && (core == q->core);

	    return status;
	}
	return false;
    }
    
    uint16_t length() const override
    {
        return  core.L_PACKET;
    }
};

typedef std::shared_ptr<Packet_for_sending_fixed_text_messages> Packet_for_sending_fixed_text_messagesPtr;

#endif // PACKET_FOR_SENDING_FIXED_TEXT_MESSAGES_H_INCLUDED

