
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
        stream << '(' << +id << ',' << core << ')';
    }

    bool equals(const BasePacket& p) const override
    {
	if(auto q = dynamic_cast<const Session_Management_with_neighbouring_Radio_Infill_Unit*>(&p))
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

typedef std::shared_ptr<Session_Management_with_neighbouring_Radio_Infill_Unit> Session_Management_with_neighbouring_Radio_Infill_UnitPtr;

#endif // SESSION_MANAGEMENT_WITH_NEIGHBOURING_RADIO_INFILL_UNIT_H_INCLUDED

