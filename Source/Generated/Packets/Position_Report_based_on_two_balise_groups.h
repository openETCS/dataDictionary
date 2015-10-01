
#ifndef POSITION_REPORT_BASED_ON_TWO_BALISE_GROUPS_H_INCLUDED
#define POSITION_REPORT_BASED_ON_TWO_BALISE_GROUPS_H_INCLUDED

#include "Bitstream.h"
#include "Position_Report_based_on_two_balise_groups_Core.h"
#include "BasePacket.h"

struct Position_Report_based_on_two_balise_groups : public BasePacket
{
    Position_Report_based_on_two_balise_groups_Core core;

    Position_Report_based_on_two_balise_groups() : BasePacket(1) {}

    void print(std::ostream& stream) const override
    {
        stream << '(' << header << ',' << core << ')';
    }

    bool equals(const BasePacket& p) const override
    {
        if (auto q = dynamic_cast<const Position_Report_based_on_two_balise_groups*>(&p))
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
        data.nid_packet = 1;
	data.valid = 1;

        PacketInfo q = data;

	stream[q.startAddress++] = header.NID_PACKET;

	int ret = ::encode(q, stream, core);

	data.endAddress = q.startAddress-1;

	return ret;
    }

    int decode(const PacketInfo& data, const kcg_int* stream) override
    {
        if(data.nid_packet != 1)
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

typedef std::shared_ptr<Position_Report_based_on_two_balise_groups> Position_Report_based_on_two_balise_groupsPtr;

#endif // POSITION_REPORT_BASED_ON_TWO_BALISE_GROUPS_H_INCLUDED

