
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
        stream << '(' << +header.NID_PACKET << ',' << core << ')';
    }

    bool equals(const BasePacket& p) const override
    {
        if (auto q = dynamic_cast<const RBC_transition_order*>(&p))
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

typedef std::shared_ptr<RBC_transition_order> RBC_transition_orderPtr;

#endif // RBC_TRANSITION_ORDER_H_INCLUDED

