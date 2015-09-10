
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
        stream << '(' << header << ',' << core << ')';
    }

    bool equals(const BasePacket& p) const override
    {
        if (auto q = dynamic_cast<const Packet_for_sending_fixed_text_messages*>(&p))
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

};

typedef std::shared_ptr<Packet_for_sending_fixed_text_messages> Packet_for_sending_fixed_text_messagesPtr;

#endif // PACKET_FOR_SENDING_FIXED_TEXT_MESSAGES_H_INCLUDED

