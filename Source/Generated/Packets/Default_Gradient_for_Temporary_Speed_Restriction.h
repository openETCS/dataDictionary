
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

    int encode(Packet_Info& data, kcg_int* stream, kcg_int startAddress) const override
    {
        data.nid_packet = 141;
	data.q_dir = core.Q_DIR;
	data.valid = core.VALID;
	data.startAddress = startAddress;

	return ::encode(data, stream, startAddress, core);
    }

    int decode(const Packet_Info& data, const kcg_int* stream) override
    {
        if(data.nid_packet != 141)
	{
	    return 0;
	}

	return ::decode(data, stream, core);
    }

};

typedef std::shared_ptr<Default_Gradient_for_Temporary_Speed_Restriction> Default_Gradient_for_Temporary_Speed_RestrictionPtr;

#endif // DEFAULT_GRADIENT_FOR_TEMPORARY_SPEED_RESTRICTION_H_INCLUDED

