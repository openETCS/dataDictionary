
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
        stream << '('
	       << +id << ','
               << +core.Q_DIR << ','
               << +core.L_PACKET << ','
               << +core.M_VERSION << ')';
    }

    bool equals(const BasePacket& p) const override
    {
	if(auto q = dynamic_cast<const System_Version_order*>(&p))
	{
	    return
                (core.Q_DIR == q->core.Q_DIR) &&
                (core.L_PACKET == q->core.L_PACKET) &&
                (core.M_VERSION == q->core.M_VERSION);
	}
	return false;
    }
};

typedef std::shared_ptr<System_Version_order> System_Version_orderPtr;

#endif // SYSTEM_VERSION_ORDER_H_INCLUDED

