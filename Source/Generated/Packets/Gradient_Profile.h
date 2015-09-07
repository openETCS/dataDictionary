
#ifndef GRADIENT_PROFILE_H_INCLUDED
#define GRADIENT_PROFILE_H_INCLUDED

#include "Bitstream.h"
#include "Gradient_Profile_Core.h"
#include "BasePacket.h"

struct Gradient_Profile : public BasePacket
{
    Gradient_Profile_Core core;

    Gradient_Profile() : BasePacket(21) {}

    void print(std::ostream& stream) const override
    {
        stream << '(' << +header.NID_PACKET << ',' << core << ')';
    }

    bool equals(const BasePacket& p) const override
    {
        if (auto q = dynamic_cast<const Gradient_Profile*>(&p))
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

typedef std::shared_ptr<Gradient_Profile> Gradient_ProfilePtr;

#endif // GRADIENT_PROFILE_H_INCLUDED

