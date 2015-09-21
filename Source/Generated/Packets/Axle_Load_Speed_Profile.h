
#ifndef AXLE_LOAD_SPEED_PROFILE_H_INCLUDED
#define AXLE_LOAD_SPEED_PROFILE_H_INCLUDED

#include "Bitstream.h"
#include "Axle_Load_Speed_Profile_Core.h"
#include "BasePacket.h"

struct Axle_Load_Speed_Profile : public BasePacket
{
    Axle_Load_Speed_Profile_Core core;

    Axle_Load_Speed_Profile() : BasePacket(51) {}

    void print(std::ostream& stream) const override
    {
        stream << '(' << header << ',' << core << ')';
    }

    bool equals(const BasePacket& p) const override
    {
        if (auto q = dynamic_cast<const Axle_Load_Speed_Profile*>(&p))
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
        data.nid_packet = 51;
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
        if(data.nid_packet != 51)
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

typedef std::shared_ptr<Axle_Load_Speed_Profile> Axle_Load_Speed_ProfilePtr;

#endif // AXLE_LOAD_SPEED_PROFILE_H_INCLUDED

