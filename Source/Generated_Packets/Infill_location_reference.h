
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
        stream << '('
	       << uint64_t(id) << ','
               << core.Q_DIR << ','
               << core.L_PACKET << ','
               << core.Q_NEWCOUNTRY << ','
               << core.NID_C << ','
               << core.NID_BG << ')';
    }

    bool equals(const BasePacket& p) const override
    {
	if(auto q = dynamic_cast<const Infill_location_reference*>(&p))
	{
	    return
                (core.Q_DIR == q->core.Q_DIR) &&
                (core.L_PACKET == q->core.L_PACKET) &&
                (core.Q_NEWCOUNTRY == q->core.Q_NEWCOUNTRY) &&
                (core.NID_C == q->core.NID_C) &&
                (core.NID_BG == q->core.NID_BG);
	}
	return false;
    }
};

typedef std::shared_ptr<Infill_location_reference> Infill_location_referencePtr;

#endif // INFILL_LOCATION_REFERENCE_H_INCLUDED

