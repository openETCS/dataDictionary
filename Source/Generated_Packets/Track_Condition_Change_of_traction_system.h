
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
        stream << '(' << +id << ',' << core << ')';
    }

    bool equals(const BasePacket& p) const override
    {
	if(auto q = dynamic_cast<const Track_Condition_Change_of_traction_system*>(&p))
	{
	    bool status = true;

	    status = status && (id == q->id);
	    status = status && (core == q->core);

	    return status;
	}
	return false;
    }
};

typedef std::shared_ptr<Track_Condition_Change_of_traction_system> Track_Condition_Change_of_traction_systemPtr;

#endif // TRACK_CONDITION_CHANGE_OF_TRACTION_SYSTEM_H_INCLUDED

