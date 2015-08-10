
#ifndef LEVEL_CROSSING_INFORMATION_H_INCLUDED
#define LEVEL_CROSSING_INFORMATION_H_INCLUDED

#include "Bitstream.h"
#include "Level_Crossing_information_Core.h"
#include "BasePacket.h"

struct Level_Crossing_information : public BasePacket
{
    Level_Crossing_information_Core core;

    Level_Crossing_information() : BasePacket(88) {}

    void print(std::ostream& stream) const override
    {
        stream << '(' << +id << ',' << core << ')';
    }

    bool equals(const BasePacket& p) const override
    {
	if(auto q = dynamic_cast<const Level_Crossing_information*>(&p))
	{
	    bool status = true;

	    status = status && (id == q->id);
	    status = status && (core == q->core);

	    return status;
	}
	return false;
    }
    
    uint16_t length() const override
    {
        return  core.L_PACKET;
    }
};

typedef std::shared_ptr<Level_Crossing_information> Level_Crossing_informationPtr;

#endif // LEVEL_CROSSING_INFORMATION_H_INCLUDED

