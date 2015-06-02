
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
        stream << '(' << uint64_t(id) << ')';
    }

    bool equals(const BasePacket& p) const override
    {
	if(auto q = dynamic_cast<const Movement_Authority_Request_Parameters*>(&p))
	{
	    return
                (core.Q_DIR == q->core.Q_DIR) &&
                (core.L_PACKET == q->core.L_PACKET) &&
                (core.T_MAR == q->core.T_MAR) &&
                (core.T_TIMEOUTRQST == q->core.T_TIMEOUTRQST) &&
                (core.T_CYCRQST == q->core.T_CYCRQST);
	}
	return false;
     }
};

typedef std::shared_ptr<Movement_Authority_Request_Parameters> Movement_Authority_Request_ParametersPtr;

#endif // MOVEMENT_AUTHORITY_REQUEST_PARAMETERS_H_INCLUDED

