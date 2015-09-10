
#ifndef NATIONAL_VALUES_H_INCLUDED
#define NATIONAL_VALUES_H_INCLUDED

#include "Bitstream.h"
#include "National_Values_Core.h"
#include "BasePacket.h"

struct National_Values : public BasePacket
{
    National_Values_Core core;

    National_Values() : BasePacket(3) {}

    void print(std::ostream& stream) const override
    {
        stream << '(' << header << ',' << core << ')';
    }

    bool equals(const BasePacket& p) const override
    {
        if (auto q = dynamic_cast<const National_Values*>(&p))
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

typedef std::shared_ptr<National_Values> National_ValuesPtr;

#endif // NATIONAL_VALUES_H_INCLUDED

