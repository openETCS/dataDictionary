
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
        stream << '(' << +id << ',' << core << ')';
    }

    bool equals(const BasePacket& p) const override
    {
	if(auto q = dynamic_cast<const Track_Ahead_Free_up_to_level_23_transition_location*>(&p))
	{
	    bool status = true;

	    status = status && (id == q->id);
	    status = status && (core == q->core);

	    return status;
	}
	return false;
    }
};

typedef std::shared_ptr<Track_Ahead_Free_up_to_level_23_transition_location> Track_Ahead_Free_up_to_level_23_transition_locationPtr;

#endif // TRACK_AHEAD_FREE_UP_TO_LEVEL_23_TRANSITION_LOCATION_H_INCLUDED

