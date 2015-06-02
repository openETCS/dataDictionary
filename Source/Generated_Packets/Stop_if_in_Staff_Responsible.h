
#ifndef STOP_IF_IN_STAFF_RESPONSIBLE_H_INCLUDED
#define STOP_IF_IN_STAFF_RESPONSIBLE_H_INCLUDED

#include "Bitstream.h"
#include "Stop_if_in_Staff_Responsible_Core.h"
#include "BasePacket.h"

struct Stop_if_in_Staff_Responsible : public BasePacket
{
    Stop_if_in_Staff_Responsible_Core core;

    Stop_if_in_Staff_Responsible() : BasePacket(137) {}

    void print(std::ostream& stream) const override
    {
        stream << '(' << uint64_t(id) << ')';
    }

    bool equals(const BasePacket& p) const override
    {
	if(auto q = dynamic_cast<const Stop_if_in_Staff_Responsible*>(&p))
	{
	    return
                (core.Q_DIR == q->core.Q_DIR) &&
                (core.L_PACKET == q->core.L_PACKET) &&
                (core.Q_SRSTOP == q->core.Q_SRSTOP);
	}
	return false;
     }
};

typedef std::shared_ptr<Stop_if_in_Staff_Responsible> Stop_if_in_Staff_ResponsiblePtr;

#endif // STOP_IF_IN_STAFF_RESPONSIBLE_H_INCLUDED

