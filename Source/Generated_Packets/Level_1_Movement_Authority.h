
#ifndef LEVEL_1_MOVEMENT_AUTHORITY_H_INCLUDED
#define LEVEL_1_MOVEMENT_AUTHORITY_H_INCLUDED

#include "Bitstream.h"
#include "Level_1_Movement_Authority_Core.h"
#include "BasePacket.h"

struct Level_1_Movement_Authority : public BasePacket
{
    Level_1_Movement_Authority_Core core;

    Level_1_Movement_Authority() : BasePacket(12) {}

    void print(std::ostream& stream) const override
    {
        stream << '(' << +header.NID_PACKET << ',' << core << ')';
    }

    bool equals(const BasePacket& p) const override
    {
	if(auto q = dynamic_cast<const Level_1_Movement_Authority*>(&p))
	{
	    bool status = true;

	    status = status && (header.NID_PACKET == q->header.NID_PACKET);
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

typedef std::shared_ptr<Level_1_Movement_Authority> Level_1_Movement_AuthorityPtr;

#endif // LEVEL_1_MOVEMENT_AUTHORITY_H_INCLUDED

