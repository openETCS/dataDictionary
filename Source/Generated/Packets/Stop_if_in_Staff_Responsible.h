
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
        stream << '(' << +header.NID_PACKET << ',' << core << ')';
    }

    bool equals(const BasePacket& p) const override
    {
        if (auto q = dynamic_cast<const Stop_if_in_Staff_Responsible*>(&p))
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

typedef std::shared_ptr<Stop_if_in_Staff_Responsible> Stop_if_in_Staff_ResponsiblePtr;

#endif // STOP_IF_IN_STAFF_RESPONSIBLE_H_INCLUDED

