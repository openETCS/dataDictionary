
#ifndef STAFF_RESPONSIBLE_DISTANCE_INFORMATION_FROM_LOOP_H_INCLUDED
#define STAFF_RESPONSIBLE_DISTANCE_INFORMATION_FROM_LOOP_H_INCLUDED

#include "Bitstream.h"
#include "Staff_Responsible_distance_Information_from_loop_Core.h"
#include "BasePacket.h"

struct Staff_Responsible_distance_Information_from_loop : public BasePacket
{
    Staff_Responsible_distance_Information_from_loop_Core core;

    Staff_Responsible_distance_Information_from_loop() : BasePacket(13) {}

    void print(std::ostream& stream) const override
    {
        stream << '(' << +header.NID_PACKET << ',' << core << ')';
    }

    bool equals(const BasePacket& p) const override
    {
        if (auto q = dynamic_cast<const Staff_Responsible_distance_Information_from_loop*>(&p))
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

typedef std::shared_ptr<Staff_Responsible_distance_Information_from_loop> Staff_Responsible_distance_Information_from_loopPtr;

#endif // STAFF_RESPONSIBLE_DISTANCE_INFORMATION_FROM_LOOP_H_INCLUDED

