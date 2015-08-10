
#ifndef MOVEMENT_AUTHORITY_REQUEST_PARAMETERS_H_INCLUDED
#define MOVEMENT_AUTHORITY_REQUEST_PARAMETERS_H_INCLUDED

#include "Bitstream.h"
#include "Movement_Authority_Request_Parameters_Core.h"
#include "BasePacket.h"

struct Movement_Authority_Request_Parameters : public BasePacket
{
    Movement_Authority_Request_Parameters_Core core;

    Movement_Authority_Request_Parameters() : BasePacket(57) {}

    void print(std::ostream& stream) const override
    {
        stream << '(' << +header.NID_PACKET << ',' << core << ')';
    }

    bool equals(const BasePacket& p) const override
    {
	if(auto q = dynamic_cast<const Movement_Authority_Request_Parameters*>(&p))
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

typedef std::shared_ptr<Movement_Authority_Request_Parameters> Movement_Authority_Request_ParametersPtr;

#endif // MOVEMENT_AUTHORITY_REQUEST_PARAMETERS_H_INCLUDED

