
#ifndef SESSION_MANAGEMENT_H_INCLUDED
#define SESSION_MANAGEMENT_H_INCLUDED

#include "Bitstream.h"
#include "Session_Management_Core.h"
#include "BasePacket.h"

struct Session_Management : public BasePacket
{
    Session_Management_Core core;

    Session_Management() : BasePacket(42) {}

    void print(std::ostream& stream) const override
    {
        stream << '('
	       << +id << ','
               << +core.Q_DIR << ','
               << +core.L_PACKET << ','
               << +core.Q_RBC << ','
               << +core.NID_C << ','
               << +core.NID_RBC << ','
               << +core.NID_RADIO << ','
               << +core.Q_SLEEPSESSION << ')';
    }

    bool equals(const BasePacket& p) const override
    {
	if(auto q = dynamic_cast<const Session_Management*>(&p))
	{
	    return
                (core.Q_DIR == q->core.Q_DIR) &&
                (core.L_PACKET == q->core.L_PACKET) &&
                (core.Q_RBC == q->core.Q_RBC) &&
                (core.NID_C == q->core.NID_C) &&
                (core.NID_RBC == q->core.NID_RBC) &&
                (core.NID_RADIO == q->core.NID_RADIO) &&
                (core.Q_SLEEPSESSION == q->core.Q_SLEEPSESSION);
	}
	return false;
    }
};

typedef std::shared_ptr<Session_Management> Session_ManagementPtr;

#endif // SESSION_MANAGEMENT_H_INCLUDED

