
#ifndef STOP_IF_IN_STAFF_RESPONSIBLE_H_INCLUDED
#define STOP_IF_IN_STAFF_RESPONSIBLE_H_INCLUDED

#include "Bitstream.h"
#include "Stop_if_in_Staff_Responsible_Core.h"
#include "BasePacket.h"

struct Stop_if_in_Staff_Responsible : public BasePacket
{
    Stop_if_in_Staff_Responsible_Core core;

    Stop_if_in_Staff_Responsible() : BasePacket(137) {}

    void print(std::ostream& stream) const override
    {
        stream << '(' << header << ',' << core << ')';
    }

    bool equals(const BasePacket& p) const override
    {
        if (auto q = dynamic_cast<const Stop_if_in_Staff_Responsible*>(&p))
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

typedef std::shared_ptr<Stop_if_in_Staff_Responsible> Stop_if_in_Staff_ResponsiblePtr;

#endif // STOP_IF_IN_STAFF_RESPONSIBLE_H_INCLUDED

