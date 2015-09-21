
#ifndef SESSION_MANAGEMENT_WITH_NEIGHBOURING_RADIO_INFILL_UNIT_H_INCLUDED
#define SESSION_MANAGEMENT_WITH_NEIGHBOURING_RADIO_INFILL_UNIT_H_INCLUDED

#include "Bitstream.h"
#include "Session_Management_with_neighbouring_Radio_Infill_Unit_Core.h"
#include "BasePacket.h"

struct Session_Management_with_neighbouring_Radio_Infill_Unit : public BasePacket
{
    Session_Management_with_neighbouring_Radio_Infill_Unit_Core core;

    Session_Management_with_neighbouring_Radio_Infill_Unit() : BasePacket(143) {}

    void print(std::ostream& stream) const override
    {
        stream << '(' << header << ',' << core << ')';
    }

    bool equals(const BasePacket& p) const override
    {
        if (auto q = dynamic_cast<const Session_Management_with_neighbouring_Radio_Infill_Unit*>(&p))
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
        data.nid_packet = 143;
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
        if(data.nid_packet != 143)
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

typedef std::shared_ptr<Session_Management_with_neighbouring_Radio_Infill_Unit> Session_Management_with_neighbouring_Radio_Infill_UnitPtr;

#endif // SESSION_MANAGEMENT_WITH_NEIGHBOURING_RADIO_INFILL_UNIT_H_INCLUDED

