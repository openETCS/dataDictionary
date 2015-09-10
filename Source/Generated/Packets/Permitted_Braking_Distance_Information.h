
#ifndef PERMITTED_BRAKING_DISTANCE_INFORMATION_H_INCLUDED
#define PERMITTED_BRAKING_DISTANCE_INFORMATION_H_INCLUDED

#include "Bitstream.h"
#include "Permitted_Braking_Distance_Information_Core.h"
#include "BasePacket.h"

struct Permitted_Braking_Distance_Information : public BasePacket
{
    Permitted_Braking_Distance_Information_Core core;

    Permitted_Braking_Distance_Information() : BasePacket(52) {}

    void print(std::ostream& stream) const override
    {
        stream << '(' << header << ',' << core << ')';
    }

    bool equals(const BasePacket& p) const override
    {
        if (auto q = dynamic_cast<const Permitted_Braking_Distance_Information*>(&p))
        {
            return header == q->header && core == q->core;
        }

        return false;
    }

    uint16_t length() const override
    {
        return  core.L_PACKET;
    }
};

typedef std::shared_ptr<Permitted_Braking_Distance_Information> Permitted_Braking_Distance_InformationPtr;

#endif // PERMITTED_BRAKING_DISTANCE_INFORMATION_H_INCLUDED

