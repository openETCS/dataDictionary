
#ifndef SESSION_MANAGEMENT_H_INCLUDED
#define SESSION_MANAGEMENT_H_INCLUDED

#include "Bitstream.h"
#include "Session_Management_Core.h"
#include "BasePacket.h"

struct Session_Management : public BasePacket
{
    Session_Management_Core core;

    Session_Management() : BasePacket(42) {}

    void print(std::ostream& stream) const override
    {
        stream << '(' << header << ',' << core << ')';
    }

    bool equals(const BasePacket& p) const override
    {
        if (auto q = dynamic_cast<const Session_Management*>(&p))
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

    int encode(Packet_Info& data, kcg_int* stream, kcg_int startAddress) const override
    {
        data.nid_packet = 42;
	data.q_dir = core.Q_DIR;
	data.valid = core.VALID;
	data.startAddress = startAddress;

	return ::encode(data, stream, startAddress, core);
    }

    int decode(const Packet_Info& data, const kcg_int* stream) override
    {
        if(data.nid_packet != 42)
	{
	    return 0;
	}

	return ::decode(data, stream, core);
    }

};

typedef std::shared_ptr<Session_Management> Session_ManagementPtr;

#endif // SESSION_MANAGEMENT_H_INCLUDED

