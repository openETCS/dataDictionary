
#ifndef AXLE_LOAD_SPEED_PROFILE_H_INCLUDED
#define AXLE_LOAD_SPEED_PROFILE_H_INCLUDED

#include "Bitstream.h"
#include "Axle_Load_Speed_Profile_Core.h"
#include "BasePacket.h"

struct Axle_Load_Speed_Profile : public BasePacket
{
    Axle_Load_Speed_Profile_Core core;

    Axle_Load_Speed_Profile() : BasePacket(51) {}

    void print(std::ostream& stream) const override
    {
        stream << '(' << header << ',' << core << ')';
    }

    bool equals(const BasePacket& p) const override
    {
        if (auto q = dynamic_cast<const Axle_Load_Speed_Profile*>(&p))
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

};

typedef std::shared_ptr<Axle_Load_Speed_Profile> Axle_Load_Speed_ProfilePtr;

#endif // AXLE_LOAD_SPEED_PROFILE_H_INCLUDED

