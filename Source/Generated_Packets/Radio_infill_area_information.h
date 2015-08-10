
#ifndef RADIO_INFILL_AREA_INFORMATION_H_INCLUDED
#define RADIO_INFILL_AREA_INFORMATION_H_INCLUDED

#include "Bitstream.h"
#include "Radio_infill_area_information_Core.h"
#include "BasePacket.h"

struct Radio_infill_area_information : public BasePacket
{
    Radio_infill_area_information_Core core;

    Radio_infill_area_information() : BasePacket(133) {}

    void print(std::ostream& stream) const override
    {
        stream << '(' << +header.NID_PACKET << ',' << core << ')';
    }

    bool equals(const BasePacket& p) const override
    {
	if(auto q = dynamic_cast<const Radio_infill_area_information*>(&p))
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

typedef std::shared_ptr<Radio_infill_area_information> Radio_infill_area_informationPtr;

#endif // RADIO_INFILL_AREA_INFORMATION_H_INCLUDED

