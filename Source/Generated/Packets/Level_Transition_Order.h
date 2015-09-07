
#ifndef LEVEL_TRANSITION_ORDER_H_INCLUDED
#define LEVEL_TRANSITION_ORDER_H_INCLUDED

#include "Bitstream.h"
#include "Level_Transition_Order_Core.h"
#include "BasePacket.h"

struct Level_Transition_Order : public BasePacket
{
    Level_Transition_Order_Core core;

    Level_Transition_Order() : BasePacket(41) {}

    void print(std::ostream& stream) const override
    {
        stream << '(' << +header.NID_PACKET << ',' << core << ')';
    }

    bool equals(const BasePacket& p) const override
    {
        if (auto q = dynamic_cast<const Level_Transition_Order*>(&p))
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

typedef std::shared_ptr<Level_Transition_Order> Level_Transition_OrderPtr;

#endif // LEVEL_TRANSITION_ORDER_H_INCLUDED

