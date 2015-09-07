
#ifndef SESSION_MANAGEMENT_H_INCLUDED
#define SESSION_MANAGEMENT_H_INCLUDED

#include "Bitstream.h"
#include "Session_Management_Core.h"
#include "BasePacket.h"

struct Session_Management : public BasePacket
{
    Session_Management_Core core;

    Session_Management() : BasePacket(42) {}

    void print(std::ostream& stream) const override
    {
        stream << '(' << +header.NID_PACKET << ',' << core << ')';
    }

    bool equals(const BasePacket& p) const override
    {
        if (auto q = dynamic_cast<const Session_Management*>(&p))
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

typedef std::shared_ptr<Session_Management> Session_ManagementPtr;

#endif // SESSION_MANAGEMENT_H_INCLUDED

