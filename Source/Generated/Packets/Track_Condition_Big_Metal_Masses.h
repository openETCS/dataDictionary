
#ifndef TRACK_CONDITION_BIG_METAL_MASSES_H_INCLUDED
#define TRACK_CONDITION_BIG_METAL_MASSES_H_INCLUDED

#include "Bitstream.h"
#include "Track_Condition_Big_Metal_Masses_Core.h"
#include "BasePacket.h"

struct Track_Condition_Big_Metal_Masses : public BasePacket
{
    Track_Condition_Big_Metal_Masses_Core core;

    Track_Condition_Big_Metal_Masses() : BasePacket(67) {}

    void print(std::ostream& stream) const override
    {
        stream << '(' << header << ',' << core << ')';
    }

    bool equals(const BasePacket& p) const override
    {
        if (auto q = dynamic_cast<const Track_Condition_Big_Metal_Masses*>(&p))
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
        data.nid_packet = 67;
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
        if(data.nid_packet != 67)
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

typedef std::shared_ptr<Track_Condition_Big_Metal_Masses> Track_Condition_Big_Metal_MassesPtr;

#endif // TRACK_CONDITION_BIG_METAL_MASSES_H_INCLUDED

