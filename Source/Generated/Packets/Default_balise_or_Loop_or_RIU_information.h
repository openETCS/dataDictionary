
#ifndef DEFAULT_BALISE_OR_LOOP_OR_RIU_INFORMATION_H_INCLUDED
#define DEFAULT_BALISE_OR_LOOP_OR_RIU_INFORMATION_H_INCLUDED

#include "Bitstream.h"
#include "Default_balise_or_Loop_or_RIU_information_Core.h"
#include "BasePacket.h"

struct Default_balise_or_Loop_or_RIU_information : public BasePacket
{
    Default_balise_or_Loop_or_RIU_information_Core core;

    Default_balise_or_Loop_or_RIU_information() : BasePacket(254) {}

    void print(std::ostream& stream) const override
    {
        stream << '(' << +header.NID_PACKET << ',' << core << ')';
    }

    bool equals(const BasePacket& p) const override
    {
	if(auto q = dynamic_cast<const Default_balise_or_Loop_or_RIU_information*>(&p))
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

typedef std::shared_ptr<Default_balise_or_Loop_or_RIU_information> Default_balise_or_Loop_or_RIU_informationPtr;

#endif // DEFAULT_BALISE_OR_LOOP_OR_RIU_INFORMATION_H_INCLUDED

