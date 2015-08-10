
#ifndef INTERNATIONAL_STATIC_SPEED_PROFILE_H_INCLUDED
#define INTERNATIONAL_STATIC_SPEED_PROFILE_H_INCLUDED

#include "Bitstream.h"
#include "International_Static_Speed_Profile_Core.h"
#include "BasePacket.h"

struct International_Static_Speed_Profile : public BasePacket
{
    International_Static_Speed_Profile_Core core;

    International_Static_Speed_Profile() : BasePacket(27) {}

    void print(std::ostream& stream) const override
    {
        stream << '(' << +header.NID_PACKET << ',' << core << ')';
    }

    bool equals(const BasePacket& p) const override
    {
	if(auto q = dynamic_cast<const International_Static_Speed_Profile*>(&p))
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

typedef std::shared_ptr<International_Static_Speed_Profile> International_Static_Speed_ProfilePtr;

#endif // INTERNATIONAL_STATIC_SPEED_PROFILE_H_INCLUDED

