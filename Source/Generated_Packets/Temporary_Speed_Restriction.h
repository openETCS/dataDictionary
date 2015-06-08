
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
        stream << '('
	       << +id << ','
               << +core.Q_DIR << ','
               << +core.L_PACKET << ','
               << +core.Q_SCALE << ','
               << +core.NID_TSR << ','
               << +core.D_TSR << ','
               << +core.L_TSR << ','
               << +core.Q_FRONT << ','
               << +core.V_TSR << ')';
    }

    bool equals(const BasePacket& p) const override
    {
	if(auto q = dynamic_cast<const Temporary_Speed_Restriction*>(&p))
	{
	    return
                (core.Q_DIR == q->core.Q_DIR) &&
                (core.L_PACKET == q->core.L_PACKET) &&
                (core.Q_SCALE == q->core.Q_SCALE) &&
                (core.NID_TSR == q->core.NID_TSR) &&
                (core.D_TSR == q->core.D_TSR) &&
                (core.L_TSR == q->core.L_TSR) &&
                (core.Q_FRONT == q->core.Q_FRONT) &&
                (core.V_TSR == q->core.V_TSR);
	}
	return false;
    }
};

typedef std::shared_ptr<Temporary_Speed_Restriction> Temporary_Speed_RestrictionPtr;

#endif // TEMPORARY_SPEED_RESTRICTION_H_INCLUDED

