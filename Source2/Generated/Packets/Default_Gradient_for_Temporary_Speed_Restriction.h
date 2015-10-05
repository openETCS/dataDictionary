
#ifndef DEFAULT_GRADIENT_FOR_TEMPORARY_SPEED_RESTRICTION_H_INCLUDED
#define DEFAULT_GRADIENT_FOR_TEMPORARY_SPEED_RESTRICTION_H_INCLUDED

#include "Bitstream.h"
#include "Default_Gradient_for_Temporary_Speed_Restriction_Core.h"
#include "BasePacket.h"

struct Default_Gradient_for_Temporary_Speed_Restriction : public BasePacket
{
    Default_Gradient_for_Temporary_Speed_Restriction_Core core;

    Default_Gradient_for_Temporary_Speed_Restriction() : BasePacket(141) {}

    void print(std::ostream& stream) const override
    {
        stream << '(' << header << ',' << core << ')';
    }

    bool equals(const BasePacket& p) const override
    {
        if (auto q = dynamic_cast<const Default_Gradient_for_Temporary_Speed_Restriction*>(&p))
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
        data.nid_packet = 141;
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
        if(data.nid_packet != 141)
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

typedef std::shared_ptr<Default_Gradient_for_Temporary_Speed_Restriction> Default_Gradient_for_Temporary_Speed_RestrictionPtr;

#endif // DEFAULT_GRADIENT_FOR_TEMPORARY_SPEED_RESTRICTION_H_INCLUDED

