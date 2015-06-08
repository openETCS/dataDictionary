
#ifndef LEVEL_CROSSING_INFORMATION_H_INCLUDED
#define LEVEL_CROSSING_INFORMATION_H_INCLUDED

#include "Bitstream.h"
#include "Level_Crossing_information_Core.h"
#include "BasePacket.h"

struct Level_Crossing_information : public BasePacket
{
    Level_Crossing_information_Core core;

    Level_Crossing_information() : BasePacket(88) {}

    void print(std::ostream& stream) const override
    {
        stream << '('
	       << uint64_t(id) << ','
               << core.Q_DIR << ','
               << core.L_PACKET << ','
               << core.Q_SCALE << ','
               << core.NID_LX << ','
               << core.D_LX << ','
               << core.L_LX << ','
               << core.Q_LXSTATUS << ','
               << core.V_LX << ','
               << core.Q_STOPLX << ','
               << core.L_STOPLX << ')';
    }

    bool equals(const BasePacket& p) const override
    {
	if(auto q = dynamic_cast<const Level_Crossing_information*>(&p))
	{
	    return
                (core.Q_DIR == q->core.Q_DIR) &&
                (core.L_PACKET == q->core.L_PACKET) &&
                (core.Q_SCALE == q->core.Q_SCALE) &&
                (core.NID_LX == q->core.NID_LX) &&
                (core.D_LX == q->core.D_LX) &&
                (core.L_LX == q->core.L_LX) &&
                (core.Q_LXSTATUS == q->core.Q_LXSTATUS) &&
                (core.V_LX == q->core.V_LX) &&
                (core.Q_STOPLX == q->core.Q_STOPLX) &&
                (core.L_STOPLX == q->core.L_STOPLX);
	}
	return false;
    }
};

typedef std::shared_ptr<Level_Crossing_information> Level_Crossing_informationPtr;

#endif // LEVEL_CROSSING_INFORMATION_H_INCLUDED

