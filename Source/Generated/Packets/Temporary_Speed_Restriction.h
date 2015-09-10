
#ifndef TEMPORARY_SPEED_RESTRICTION_H_INCLUDED
#define TEMPORARY_SPEED_RESTRICTION_H_INCLUDED

#include "Bitstream.h"
#include "Temporary_Speed_Restriction_Core.h"
#include "BasePacket.h"

struct Temporary_Speed_Restriction : public BasePacket
{
    Temporary_Speed_Restriction_Core core;

    Temporary_Speed_Restriction() : BasePacket(65) {}

    void print(std::ostream& stream) const override
    {
        stream << '(' << header << ',' << core << ')';
    }

    bool equals(const BasePacket& p) const override
    {
        if (auto q = dynamic_cast<const Temporary_Speed_Restriction*>(&p))
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

typedef std::shared_ptr<Temporary_Speed_Restriction> Temporary_Speed_RestrictionPtr;

#endif // TEMPORARY_SPEED_RESTRICTION_H_INCLUDED

