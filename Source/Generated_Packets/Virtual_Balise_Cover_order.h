
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
        stream << '('
	       << +id << ','
               << +core.Q_DIR << ','
               << +core.L_PACKET << ','
               << +core.Q_VBCO << ','
               << +core.NID_VBCMK << ','
               << +core.NID_C << ','
               << +core.T_VBC << ')';
    }

    bool equals(const BasePacket& p) const override
    {
	if(auto q = dynamic_cast<const Virtual_Balise_Cover_order*>(&p))
	{
	    return
                (core.Q_DIR == q->core.Q_DIR) &&
                (core.L_PACKET == q->core.L_PACKET) &&
                (core.Q_VBCO == q->core.Q_VBCO) &&
                (core.NID_VBCMK == q->core.NID_VBCMK) &&
                (core.NID_C == q->core.NID_C) &&
                ((!core.Q_VBCO == 1) || (
                (core.T_VBC == q->core.T_VBC)
                ));
	}
	return false;
    }
};

typedef std::shared_ptr<Virtual_Balise_Cover_order> Virtual_Balise_Cover_orderPtr;

#endif // VIRTUAL_BALISE_COVER_ORDER_H_INCLUDED

