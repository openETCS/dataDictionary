
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
        stream << '(' << +id << ',' << core << ')';
    }

    bool equals(const BasePacket& p) const override
    {
	if(auto q = dynamic_cast<const Radio_Network_registration*>(&p))
	{
	    bool status = true;

	    status = status && (id == q->id);
	    status = status && (core == q->core);

	    return status;
	}
	return false;
    }
};

typedef std::shared_ptr<Radio_Network_registration> Radio_Network_registrationPtr;

#endif // RADIO_NETWORK_REGISTRATION_H_INCLUDED

