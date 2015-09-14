
#ifndef TEMPORARY_SPEED_RESTRICTION_REVOCATION_H_INCLUDED
#define TEMPORARY_SPEED_RESTRICTION_REVOCATION_H_INCLUDED

#include "Bitstream.h"
#include "Temporary_Speed_Restriction_Revocation_Core.h"
#include "BasePacket.h"

struct Temporary_Speed_Restriction_Revocation : public BasePacket
{
    Temporary_Speed_Restriction_Revocation_Core core;

    Temporary_Speed_Restriction_Revocation() : BasePacket(66) {}

    void print(std::ostream& stream) const override
    {
        stream << '(' << header << ',' << core << ')';
    }

    bool equals(const BasePacket& p) const override
    {
        if (auto q = dynamic_cast<const Temporary_Speed_Restriction_Revocation*>(&p))
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
        data.nid_packet = 66;
	data.q_dir = core.Q_DIR;
	data.valid = core.VALID;
	data.startAddress = startAddress;

	return ::encode(data, stream, startAddress, core);
    }

    int decode(const Packet_Info& data, const kcg_int* stream) override
    {
        if(data.nid_packet != 66)
	{
	    return 0;
	}

	return ::decode(data, stream, core);
    }

};

typedef std::shared_ptr<Temporary_Speed_Restriction_Revocation> Temporary_Speed_Restriction_RevocationPtr;

#endif // TEMPORARY_SPEED_RESTRICTION_REVOCATION_H_INCLUDED

