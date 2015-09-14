
#ifndef RADIO_NETWORK_REGISTRATION_H_INCLUDED
#define RADIO_NETWORK_REGISTRATION_H_INCLUDED

#include "Bitstream.h"
#include "Radio_Network_registration_Core.h"
#include "BasePacket.h"

struct Radio_Network_registration : public BasePacket
{
    Radio_Network_registration_Core core;

    Radio_Network_registration() : BasePacket(45) {}

    void print(std::ostream& stream) const override
    {
        stream << '(' << header << ',' << core << ')';
    }

    bool equals(const BasePacket& p) const override
    {
        if (auto q = dynamic_cast<const Radio_Network_registration*>(&p))
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
        data.nid_packet = 45;
	data.q_dir = core.Q_DIR;
	data.valid = core.VALID;
	data.startAddress = startAddress;

	return ::encode(data, stream, startAddress, core);
    }

    int decode(const Packet_Info& data, const kcg_int* stream) override
    {
        if(data.nid_packet != 45)
	{
	    return 0;
	}

	return ::decode(data, stream, core);
    }

};

typedef std::shared_ptr<Radio_Network_registration> Radio_Network_registrationPtr;

#endif // RADIO_NETWORK_REGISTRATION_H_INCLUDED

