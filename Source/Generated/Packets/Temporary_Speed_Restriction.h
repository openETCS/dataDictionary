
#ifndef TEMPORARY_SPEED_RESTRICTION_H_INCLUDED
#define TEMPORARY_SPEED_RESTRICTION_H_INCLUDED

#include "Bitstream.h"
#include "Temporary_Speed_Restriction_Core.h"
#include "BasePacket.h"

struct Temporary_Speed_Restriction : public BasePacket
{
    Temporary_Speed_Restriction_Core core;

    Temporary_Speed_Restriction() : BasePacket(65) {}

    void print(std::ostream& stream) const override
    {
        stream << '(' << header << ',' << core << ')';
    }

    bool equals(const BasePacket& p) const override
    {
        if (auto q = dynamic_cast<const Temporary_Speed_Restriction*>(&p))
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

    int encode(Packet_Info& data, kcg_int* stream) const override
    {
        data.nid_packet = 65;
        data.q_dir = core.Q_DIR;
	data.valid = 1;

        Packet_Info q = data;

	stream[q.startAddress++] = header.NID_PACKET;

	int ret = ::encode(q, stream, core);

	data.endAddress = q.startAddress-1;

	return ret;
    }

    int decode(const Packet_Info& data, const kcg_int* stream) override
    {
        if(data.nid_packet != 65)
	{
	    return 0;
	}

	Packet_Info q = data;

	header.NID_PACKET = stream[q.startAddress++];

	int ret = ::decode(q, stream, core);

        if (q.startAddress-1 != data.endAddress)
        {
            return 0;
        }

	return ret;
    }

};

typedef std::shared_ptr<Temporary_Speed_Restriction> Temporary_Speed_RestrictionPtr;

#endif // TEMPORARY_SPEED_RESTRICTION_H_INCLUDED

