
#ifndef VIRTUAL_BALISE_COVER_ORDER_H_INCLUDED
#define VIRTUAL_BALISE_COVER_ORDER_H_INCLUDED

#include "Bitstream.h"
#include "Virtual_Balise_Cover_order_Core.h"
#include "BasePacket.h"

struct Virtual_Balise_Cover_order : public BasePacket
{
    Virtual_Balise_Cover_order_Core core;

    Virtual_Balise_Cover_order() : BasePacket(6) {}

    void print(std::ostream& stream) const override
    {
        stream << '(' << +id << ',' << core << ')';
    }

    bool equals(const BasePacket& p) const override
    {
	if(auto q = dynamic_cast<const Virtual_Balise_Cover_order*>(&p))
	{
	    bool status = true;

	    status = status && (id == q->id);
	    status = status && (core == q->core);

	    return status;
	}
	return false;
    }
};

typedef std::shared_ptr<Virtual_Balise_Cover_order> Virtual_Balise_Cover_orderPtr;

#endif // VIRTUAL_BALISE_COVER_ORDER_H_INCLUDED

