
#ifndef STAFF_RESPONSIBLE_DISTANCE_INFORMATION_FROM_LOOP_H_INCLUDED
#define STAFF_RESPONSIBLE_DISTANCE_INFORMATION_FROM_LOOP_H_INCLUDED

#include "Bitstream.h"
#include "Staff_Responsible_distance_Information_from_loop_Core.h"
#include "BasePacket.h"

struct Staff_Responsible_distance_Information_from_loop : public BasePacket
{
    Staff_Responsible_distance_Information_from_loop_Core core;

    Staff_Responsible_distance_Information_from_loop() : BasePacket(13) {}

    void print(std::ostream& stream) const override
    {
        stream << '(' << header << ',' << core << ')';
    }

    bool equals(const BasePacket& p) const override
    {
        if (auto q = dynamic_cast<const Staff_Responsible_distance_Information_from_loop*>(&p))
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
        data.nid_packet = 13;
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
        if(data.nid_packet != 13)
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

typedef std::shared_ptr<Staff_Responsible_distance_Information_from_loop> Staff_Responsible_distance_Information_from_loopPtr;

#endif // STAFF_RESPONSIBLE_DISTANCE_INFORMATION_FROM_LOOP_H_INCLUDED

