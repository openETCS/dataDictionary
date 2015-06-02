
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
        stream << '('
	       << uint64_t(id) << ','
               << core.Q_DIR << ','
               << core.L_PACKET << ','
               << core.Q_SCALE << ','
               << core.D_RBCTR << ','
               << core.NID_C << ','
               << core.NID_RBC << ','
               << core.NID_RADIO << ','
               << core.Q_SLEEPSESSION << ')';
    }

    bool equals(const BasePacket& p) const override
    {
	if(auto q = dynamic_cast<const RBC_transition_order*>(&p))
	{
	    return
                (core.Q_DIR == q->core.Q_DIR) &&
                (core.L_PACKET == q->core.L_PACKET) &&
                (core.Q_SCALE == q->core.Q_SCALE) &&
                (core.D_RBCTR == q->core.D_RBCTR) &&
                (core.NID_C == q->core.NID_C) &&
                (core.NID_RBC == q->core.NID_RBC) &&
                (core.NID_RADIO == q->core.NID_RADIO) &&
                (core.Q_SLEEPSESSION == q->core.Q_SLEEPSESSION);
	}
	return false;
    }
};

typedef std::shared_ptr<RBC_transition_order> RBC_transition_orderPtr;

#endif // RBC_TRANSITION_ORDER_H_INCLUDED

