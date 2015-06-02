
#ifndef LEVEL_23_TRANSITION_INFORMATION_H_INCLUDED
#define LEVEL_23_TRANSITION_INFORMATION_H_INCLUDED

#include "Bitstream.h"
#include "Level_23_transition_information_Core.h"
#include "BasePacket.h"

struct Level_23_transition_information : public BasePacket
{
    Level_23_transition_information_Core core;

    Level_23_transition_information() : BasePacket(9) {}

    void print(std::ostream& stream) const override
    {
        stream << '('
	       << uint64_t(id) << ','
               << core.L_PACKET << ','
               << core.NID_LTRBG << ')';
    }

    bool equals(const BasePacket& p) const override
    {
	if(auto q = dynamic_cast<const Level_23_transition_information*>(&p))
	{
	    return
                (core.L_PACKET == q->core.L_PACKET) &&
                (core.NID_LTRBG == q->core.NID_LTRBG);
	}
	return false;
    }
};

typedef std::shared_ptr<Level_23_transition_information> Level_23_transition_informationPtr;

#endif // LEVEL_23_TRANSITION_INFORMATION_H_INCLUDED

