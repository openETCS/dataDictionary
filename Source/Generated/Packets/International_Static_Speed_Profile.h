
#ifndef INTERNATIONAL_STATIC_SPEED_PROFILE_H_INCLUDED
#define INTERNATIONAL_STATIC_SPEED_PROFILE_H_INCLUDED

#include "Bitstream.h"
#include "International_Static_Speed_Profile_Core.h"
#include "BasePacket.h"

struct International_Static_Speed_Profile : public BasePacket
{
    International_Static_Speed_Profile_Core core;

    International_Static_Speed_Profile() : BasePacket(27) {}

    void print(std::ostream& stream) const override
    {
        stream << '(' << header << ',' << core << ')';
    }

    bool equals(const BasePacket& p) const override
    {
        if (auto q = dynamic_cast<const International_Static_Speed_Profile*>(&p))
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
        data.nid_packet = 27;
	data.q_dir = core.Q_DIR;
	data.valid = core.VALID;
	data.startAddress = startAddress;

	return ::encode(data, stream, startAddress, core);
    }

    int decode(const Packet_Info& data, const kcg_int* stream) override
    {
        if(data.nid_packet != 27)
	{
	    return 0;
	}

	return ::decode(data, stream, core);
    }

};

typedef std::shared_ptr<International_Static_Speed_Profile> International_Static_Speed_ProfilePtr;

#endif // INTERNATIONAL_STATIC_SPEED_PROFILE_H_INCLUDED

