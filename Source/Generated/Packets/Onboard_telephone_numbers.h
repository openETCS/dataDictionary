
#ifndef ONBOARD_TELEPHONE_NUMBERS_H_INCLUDED
#define ONBOARD_TELEPHONE_NUMBERS_H_INCLUDED

#include "Bitstream.h"
#include "Onboard_telephone_numbers_Core.h"
#include "BasePacket.h"

struct Onboard_telephone_numbers : public BasePacket
{
    Onboard_telephone_numbers_Core core;

    Onboard_telephone_numbers() : BasePacket(3) {}

    void print(std::ostream& stream) const override
    {
        stream << '(' << +header.NID_PACKET << ',' << core << ')';
    }

    bool equals(const BasePacket& p) const override
    {
	if(auto q = dynamic_cast<const Onboard_telephone_numbers*>(&p))
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

typedef std::shared_ptr<Onboard_telephone_numbers> Onboard_telephone_numbersPtr;

#endif // ONBOARD_TELEPHONE_NUMBERS_H_INCLUDED

