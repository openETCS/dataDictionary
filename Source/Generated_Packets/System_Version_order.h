
#ifndef SYSTEM_VERSION_ORDER_H_INCLUDED
#define SYSTEM_VERSION_ORDER_H_INCLUDED

#include "Bitstream.h"
#include "System_Version_order_Core.h"
#include "BasePacket.h"

struct System_Version_order : public BasePacket
{
    System_Version_order_Core core;

    System_Version_order() : BasePacket(2) {}

    void print(std::ostream& stream) const override
    {
        stream << '(' << +header.NID_PACKET << ',' << core << ')';
    }

    bool equals(const BasePacket& p) const override
    {
	if(auto q = dynamic_cast<const System_Version_order*>(&p))
	{
	    bool status = true;

	    status = status && (header.NID_PACKET == q->header.NID_PACKET);
	    status = status && (core == q->core);

	    return status;
	}
	return false;
    }
    
    uint16_t length() const override
    {
        return  core.L_PACKET;
    }
};

typedef std::shared_ptr<System_Version_order> System_Version_orderPtr;

#endif // SYSTEM_VERSION_ORDER_H_INCLUDED

