
#ifndef PACKET_FOR_SENDING_PLAIN_TEXT_MESSAGES_H_INCLUDED
#define PACKET_FOR_SENDING_PLAIN_TEXT_MESSAGES_H_INCLUDED

#include "Bitstream.h"
#include "Packet_for_sending_plain_text_messages_Core.h"
#include "BasePacket.h"

struct Packet_for_sending_plain_text_messages : public BasePacket
{
    Packet_for_sending_plain_text_messages_Core core;

    Packet_for_sending_plain_text_messages() : BasePacket(72) {}

    void print(std::ostream& stream) const override
    {
        stream << '(' << header << ',' << core << ')';
    }

    bool equals(const BasePacket& p) const override
    {
        if (auto q = dynamic_cast<const Packet_for_sending_plain_text_messages*>(&p))
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

    int encode(PacketInfo& data, kcg_int* stream) const override
    {
        data.nid_packet = 72;
        data.q_dir = core.Q_DIR;
	data.valid = 1;

        PacketInfo q = data;

	stream[q.startAddress++] = header.NID_PACKET;

	int ret = ::encode(q, stream, core);

	data.endAddress = q.startAddress-1;

	return ret;
    }

    int decode(const PacketInfo& data, const kcg_int* stream) override
    {
        if(data.nid_packet != 72)
	{
	    return 0;
	}

	PacketInfo q = data;

	header.NID_PACKET = stream[q.startAddress++];

	int ret = ::decode(q, stream, core);

        if (q.startAddress-1 != data.endAddress)
        {
            return 0;
        }

	return ret;
    }

};

typedef std::shared_ptr<Packet_for_sending_plain_text_messages> Packet_for_sending_plain_text_messagesPtr;

#endif // PACKET_FOR_SENDING_PLAIN_TEXT_MESSAGES_H_INCLUDED

