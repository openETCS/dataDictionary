
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
        stream << '('
	       << +id << ','
               << +core.Q_DIR << ','
               << +core.L_PACKET << ','
               << +core.Q_SCALE << ','
               << +core.Q_RIU << ','
               << +core.NID_C << ','
               << +core.NID_RIU << ','
               << +core.NID_RADIO << ','
               << +core.D_INFILL << ','
               << +core.NID_BG << ')';
    }

    bool equals(const BasePacket& p) const override
    {
	if(auto q = dynamic_cast<const Radio_infill_area_information*>(&p))
	{
	    return
                (core.Q_DIR == q->core.Q_DIR) &&
                (core.L_PACKET == q->core.L_PACKET) &&
                (core.Q_SCALE == q->core.Q_SCALE) &&
                (core.Q_RIU == q->core.Q_RIU) &&
                (core.NID_C == q->core.NID_C) &&
                (core.NID_RIU == q->core.NID_RIU) &&
                (core.NID_RADIO == q->core.NID_RADIO) &&
                (core.D_INFILL == q->core.D_INFILL) &&
                (core.NID_BG == q->core.NID_BG);
	}
	return false;
    }
};

typedef std::shared_ptr<Radio_infill_area_information> Radio_infill_area_informationPtr;

#endif // RADIO_INFILL_AREA_INFORMATION_H_INCLUDED

