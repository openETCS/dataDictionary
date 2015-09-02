
#ifndef INHIBITION_OF_REVOCABLE_TSRS_FROM_BALISES_IN_L23_H_INCLUDED
#define INHIBITION_OF_REVOCABLE_TSRS_FROM_BALISES_IN_L23_H_INCLUDED

#include "Bitstream.h"
#include "Inhibition_of_revocable_TSRs_from_balises_in_L23_Core.h"
#include "BasePacket.h"

struct Inhibition_of_revocable_TSRs_from_balises_in_L23 : public BasePacket
{
    Inhibition_of_revocable_TSRs_from_balises_in_L23_Core core;

    Inhibition_of_revocable_TSRs_from_balises_in_L23() : BasePacket(64) {}

    void print(std::ostream& stream) const override
    {
        stream << '(' << +header.NID_PACKET << ',' << core << ')';
    }

    bool equals(const BasePacket& p) const override
    {
	if(auto q = dynamic_cast<const Inhibition_of_revocable_TSRs_from_balises_in_L23*>(&p))
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

typedef std::shared_ptr<Inhibition_of_revocable_TSRs_from_balises_in_L23> Inhibition_of_revocable_TSRs_from_balises_in_L23Ptr;

#endif // INHIBITION_OF_REVOCABLE_TSRS_FROM_BALISES_IN_L23_H_INCLUDED

