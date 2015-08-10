
#ifndef LINKING_H_INCLUDED
#define LINKING_H_INCLUDED

#include "Bitstream.h"
#include "Linking_Core.h"
#include "BasePacket.h"

struct Linking : public BasePacket
{
    Linking_Core core;

    Linking() : BasePacket(5) {}

    void print(std::ostream& stream) const override
    {
        stream << '(' << +id << ',' << core << ')';
    }

    bool equals(const BasePacket& p) const override
    {
	if(auto q = dynamic_cast<const Linking*>(&p))
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

typedef std::shared_ptr<Linking> LinkingPtr;

#endif // LINKING_H_INCLUDED

