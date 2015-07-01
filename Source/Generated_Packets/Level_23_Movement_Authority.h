
#ifndef LEVEL_23_MOVEMENT_AUTHORITY_H_INCLUDED
#define LEVEL_23_MOVEMENT_AUTHORITY_H_INCLUDED

#include "Bitstream.h"
#include "Level_23_Movement_Authority_Core.h"
#include "BasePacket.h"

struct Level_23_Movement_Authority : public BasePacket
{
    Level_23_Movement_Authority_Core core;

    Level_23_Movement_Authority() : BasePacket(15) {}

    void print(std::ostream& stream) const override
    {
        stream << '(' << +id << ',' << core << ')';
    }

    bool equals(const BasePacket& p) const override
    {
	if(auto q = dynamic_cast<const Level_23_Movement_Authority*>(&p))
	{
	    bool status = true;

	    status = status && (id == q->id);
	    status = status && (core == q->core);

	    return status;
	}
	return false;
    }
};

typedef std::shared_ptr<Level_23_Movement_Authority> Level_23_Movement_AuthorityPtr;

#endif // LEVEL_23_MOVEMENT_AUTHORITY_H_INCLUDED

