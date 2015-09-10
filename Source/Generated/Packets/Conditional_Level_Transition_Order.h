
#ifndef CONDITIONAL_LEVEL_TRANSITION_ORDER_H_INCLUDED
#define CONDITIONAL_LEVEL_TRANSITION_ORDER_H_INCLUDED

#include "Bitstream.h"
#include "Conditional_Level_Transition_Order_Core.h"
#include "BasePacket.h"

struct Conditional_Level_Transition_Order : public BasePacket
{
    Conditional_Level_Transition_Order_Core core;

    Conditional_Level_Transition_Order() : BasePacket(46) {}

    void print(std::ostream& stream) const override
    {
        stream << '(' << header << ',' << core << ')';
    }

    bool equals(const BasePacket& p) const override
    {
        if (auto q = dynamic_cast<const Conditional_Level_Transition_Order*>(&p))
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

};

typedef std::shared_ptr<Conditional_Level_Transition_Order> Conditional_Level_Transition_OrderPtr;

#endif // CONDITIONAL_LEVEL_TRANSITION_ORDER_H_INCLUDED

