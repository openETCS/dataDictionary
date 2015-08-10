
#ifndef STOP_SHUNTING_ON_DESK_OPENING_H_INCLUDED
#define STOP_SHUNTING_ON_DESK_OPENING_H_INCLUDED

#include "Bitstream.h"
#include "Stop_Shunting_on_desk_opening_Core.h"
#include "BasePacket.h"

struct Stop_Shunting_on_desk_opening : public BasePacket
{
    Stop_Shunting_on_desk_opening_Core core;

    Stop_Shunting_on_desk_opening() : BasePacket(135) {}

    void print(std::ostream& stream) const override
    {
        stream << '(' << +id << ',' << core << ')';
    }

    bool equals(const BasePacket& p) const override
    {
	if(auto q = dynamic_cast<const Stop_Shunting_on_desk_opening*>(&p))
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

typedef std::shared_ptr<Stop_Shunting_on_desk_opening> Stop_Shunting_on_desk_openingPtr;

#endif // STOP_SHUNTING_ON_DESK_OPENING_H_INCLUDED

