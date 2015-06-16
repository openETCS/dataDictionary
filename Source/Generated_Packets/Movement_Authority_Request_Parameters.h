
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
        stream << '(' << +id << ',' << core << ')';
    }

    bool equals(const BasePacket& p) const override
    {
	if(auto q = dynamic_cast<const Movement_Authority_Request_Parameters*>(&p))
	{
	    bool status = true;

	    status = status && (id == q->id);
	    status = status && (core == q->core);

	    return status;
	}
	return false;
    }
};

typedef std::shared_ptr<Movement_Authority_Request_Parameters> Movement_Authority_Request_ParametersPtr;

#endif // MOVEMENT_AUTHORITY_REQUEST_PARAMETERS_H_INCLUDED

