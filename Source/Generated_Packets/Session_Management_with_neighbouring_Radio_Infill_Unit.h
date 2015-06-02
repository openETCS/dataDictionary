
#ifndef SESSION_MANAGEMENT_WITH_NEIGHBOURING_RADIO_INFILL_UNIT_H_INCLUDED
#define SESSION_MANAGEMENT_WITH_NEIGHBOURING_RADIO_INFILL_UNIT_H_INCLUDED

#include "Bitstream.h"
#include "Session_Management_with_neighbouring_Radio_Infill_Unit_Core.h"
#include "BasePacket.h"

struct Session_Management_with_neighbouring_Radio_Infill_Unit : public BasePacket
{
    Session_Management_with_neighbouring_Radio_Infill_Unit_Core core;

    Session_Management_with_neighbouring_Radio_Infill_Unit() : BasePacket(143) {}

    void print(std::ostream& stream) const override
    {
        stream << '(' << uint64_t(id) << ')';
    }

    bool equals(const BasePacket& p) const override
    {
	if(auto q = dynamic_cast<const Session_Management_with_neighbouring_Radio_Infill_Unit*>(&p))
	{
	    return
                (core.Q_DIR == q->core.Q_DIR) &&
                (core.L_PACKET == q->core.L_PACKET) &&
                (core.Q_RIU == q->core.Q_RIU) &&
                (core.NID_C == q->core.NID_C) &&
                (core.NID_RIU == q->core.NID_RIU) &&
                (core.NID_RADIO == q->core.NID_RADIO);
	}
	return false;
     }
};

typedef std::shared_ptr<Session_Management_with_neighbouring_Radio_Infill_Unit> Session_Management_with_neighbouring_Radio_Infill_UnitPtr;

#endif // SESSION_MANAGEMENT_WITH_NEIGHBOURING_RADIO_INFILL_UNIT_H_INCLUDED

