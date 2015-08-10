
#ifndef NATIONAL_VALUES_H_INCLUDED
#define NATIONAL_VALUES_H_INCLUDED

#include "Bitstream.h"
#include "National_Values_Core.h"
#include "BasePacket.h"

struct National_Values : public BasePacket
{
    National_Values_Core core;

    National_Values() : BasePacket(3) {}

    void print(std::ostream& stream) const override
    {
        stream << '(' << +header.NID_PACKET << ',' << core << ')';
    }

    bool equals(const BasePacket& p) const override
    {
	if(auto q = dynamic_cast<const National_Values*>(&p))
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

typedef std::shared_ptr<National_Values> National_ValuesPtr;

#endif // NATIONAL_VALUES_H_INCLUDED

