
#ifndef TRACK_CONDITION_CHANGE_OF_TRACTION_SYSTEM_H_INCLUDED
#define TRACK_CONDITION_CHANGE_OF_TRACTION_SYSTEM_H_INCLUDED

#include "Bitstream.h"
#include "Track_Condition_Change_of_traction_system_Core.h"
#include "BasePacket.h"

struct Track_Condition_Change_of_traction_system : public BasePacket
{
    Track_Condition_Change_of_traction_system_Core core;

    Track_Condition_Change_of_traction_system() : BasePacket(39) {}

    void print(std::ostream& stream) const override
    {
        stream << '('
	       << +id << ','
               << +core.Q_DIR << ','
               << +core.L_PACKET << ','
               << +core.Q_SCALE << ','
               << +core.D_TRACTION << ','
               << +core.M_VOLTAGE << ','
               << +core.NID_CTRACTION << ')';
    }

    bool equals(const BasePacket& p) const override
    {
	if(auto q = dynamic_cast<const Track_Condition_Change_of_traction_system*>(&p))
	{
	    return
                (core.Q_DIR == q->core.Q_DIR) &&
                (core.L_PACKET == q->core.L_PACKET) &&
                (core.Q_SCALE == q->core.Q_SCALE) &&
                (core.D_TRACTION == q->core.D_TRACTION) &&
                (core.M_VOLTAGE == q->core.M_VOLTAGE) &&
                (!(core.M_VOLTAGE != 0) || (
                (core.NID_CTRACTION == q->core.NID_CTRACTION)
                ));
	}
	return false;
    }
};

typedef std::shared_ptr<Track_Condition_Change_of_traction_system> Track_Condition_Change_of_traction_systemPtr;

#endif // TRACK_CONDITION_CHANGE_OF_TRACTION_SYSTEM_H_INCLUDED

