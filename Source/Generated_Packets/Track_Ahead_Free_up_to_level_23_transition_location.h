
#ifndef TRACK_AHEAD_FREE_UP_TO_LEVEL_23_TRANSITION_LOCATION_H_INCLUDED
#define TRACK_AHEAD_FREE_UP_TO_LEVEL_23_TRANSITION_LOCATION_H_INCLUDED

#include "Bitstream.h"
#include "Track_Ahead_Free_up_to_level_23_transition_location_Core.h"
#include "BasePacket.h"

struct Track_Ahead_Free_up_to_level_23_transition_location : public BasePacket
{
    Track_Ahead_Free_up_to_level_23_transition_location_Core core;

    Track_Ahead_Free_up_to_level_23_transition_location() : BasePacket(90) {}

    void print(std::ostream& stream) const override
    {
        stream << '('
	       << +id << ','
               << +core.Q_DIR << ','
               << +core.L_PACKET << ','
               << +core.Q_NEWCOUNTRY << ','
               << +core.NID_C << ','
               << +core.NID_BG << ')';
    }

    bool equals(const BasePacket& p) const override
    {
	if(auto q = dynamic_cast<const Track_Ahead_Free_up_to_level_23_transition_location*>(&p))
	{
	    return
                (core.Q_DIR == q->core.Q_DIR) &&
                (core.L_PACKET == q->core.L_PACKET) &&
                (core.Q_NEWCOUNTRY == q->core.Q_NEWCOUNTRY) &&
                (!(core.Q_NEWCOUNTRY == 1) || (
                (core.NID_C == q->core.NID_C)
                ));
	}
	return false;
    }
};

typedef std::shared_ptr<Track_Ahead_Free_up_to_level_23_transition_location> Track_Ahead_Free_up_to_level_23_transition_locationPtr;

#endif // TRACK_AHEAD_FREE_UP_TO_LEVEL_23_TRANSITION_LOCATION_H_INCLUDED

