
#ifndef TEMPORARY_SPEED_RESTRICTION_REVOCATION_H_INCLUDED
#define TEMPORARY_SPEED_RESTRICTION_REVOCATION_H_INCLUDED

#include "Bitstream.h"
#include "Temporary_Speed_Restriction_Revocation_Core.h"
#include "BasePacket.h"

struct Temporary_Speed_Restriction_Revocation : public BasePacket
{
    Temporary_Speed_Restriction_Revocation_Core core;

    Temporary_Speed_Restriction_Revocation() : BasePacket(66) {}

    void print(std::ostream& stream) const override
    {
        stream << '(' << +id << ',' << core << ')';
    }

    bool equals(const BasePacket& p) const override
    {
	if(auto q = dynamic_cast<const Temporary_Speed_Restriction_Revocation*>(&p))
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

typedef std::shared_ptr<Temporary_Speed_Restriction_Revocation> Temporary_Speed_Restriction_RevocationPtr;

#endif // TEMPORARY_SPEED_RESTRICTION_REVOCATION_H_INCLUDED

