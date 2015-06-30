
#ifndef RBC_TRANSITION_ORDER_H_INCLUDED
#define RBC_TRANSITION_ORDER_H_INCLUDED

#include "Bitstream.h"
#include "RBC_transition_order_Core.h"
#include "BasePacket.h"

struct RBC_transition_order : public BasePacket
{
    RBC_transition_order_Core core;

    RBC_transition_order() : BasePacket(131) {}

    void print(std::ostream& stream) const override
    {
        stream << '(' << +id << ',' << core << ')';
    }

    bool equals(const BasePacket& p) const override
    {
	if(auto q = dynamic_cast<const RBC_transition_order*>(&p))
	{
	    bool status = true;

	    status = status && (id == q->id);
	    status = status && (core == q->core);

	    return status;
	}
	return false;
    }
};

typedef std::shared_ptr<RBC_transition_order> RBC_transition_orderPtr;

#endif // RBC_TRANSITION_ORDER_H_INCLUDED

