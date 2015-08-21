
#ifndef GEOGRAPHICAL_POSITION_INFORMATION_H_INCLUDED
#define GEOGRAPHICAL_POSITION_INFORMATION_H_INCLUDED

#include "Bitstream.h"
#include "Geographical_Position_Information_Core.h"
#include "BasePacket.h"

struct Geographical_Position_Information : public BasePacket
{
    Geographical_Position_Information_Core core;

    Geographical_Position_Information() : BasePacket(79) {}

    void print(std::ostream& stream) const override
    {
        stream << '(' << +header.NID_PACKET << ',' << core << ')';
    }

    bool equals(const BasePacket& p) const override
    {
	if(auto q = dynamic_cast<const Geographical_Position_Information*>(&p))
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

typedef std::shared_ptr<Geographical_Position_Information> Geographical_Position_InformationPtr;

#endif // GEOGRAPHICAL_POSITION_INFORMATION_H_INCLUDED

