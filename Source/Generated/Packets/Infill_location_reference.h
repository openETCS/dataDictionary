
#ifndef INFILL_LOCATION_REFERENCE_H_INCLUDED
#define INFILL_LOCATION_REFERENCE_H_INCLUDED

#include "Bitstream.h"
#include "Infill_location_reference_Core.h"
#include "BasePacket.h"

struct Infill_location_reference : public BasePacket
{
    Infill_location_reference_Core core;

    Infill_location_reference() : BasePacket(136) {}

    void print(std::ostream& stream) const override
    {
        stream << '(' << header << ',' << core << ')';
    }

    bool equals(const BasePacket& p) const override
    {
        if (auto q = dynamic_cast<const Infill_location_reference*>(&p))
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

typedef std::shared_ptr<Infill_location_reference> Infill_location_referencePtr;

#endif // INFILL_LOCATION_REFERENCE_H_INCLUDED

