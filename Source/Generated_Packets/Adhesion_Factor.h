
#ifndef ADHESION_FACTOR_H_INCLUDED
#define ADHESION_FACTOR_H_INCLUDED

#include "Bitstream.h"
#include "Adhesion_Factor_Core.h"
#include "BasePacket.h"

struct Adhesion_Factor : public BasePacket
{
    Adhesion_Factor_Core core;

    Adhesion_Factor() : BasePacket(71) {}

    void print(std::ostream& stream) const override
    {
        stream << '(' << +header.NID_PACKET << ',' << core << ')';
    }

    bool equals(const BasePacket& p) const override
    {
	if(auto q = dynamic_cast<const Adhesion_Factor*>(&p))
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

typedef std::shared_ptr<Adhesion_Factor> Adhesion_FactorPtr;

#endif // ADHESION_FACTOR_H_INCLUDED

