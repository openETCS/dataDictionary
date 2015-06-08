
#ifndef POSITION_REPORT_BASED_ON_TWO_BALISE_GROUPS_H_INCLUDED
#define POSITION_REPORT_BASED_ON_TWO_BALISE_GROUPS_H_INCLUDED

#include "Bitstream.h"
#include "Position_Report_based_on_two_balise_groups_Core.h"
#include "BasePacket.h"

struct Position_Report_based_on_two_balise_groups : public BasePacket
{
    Position_Report_based_on_two_balise_groups_Core core;

    Position_Report_based_on_two_balise_groups() : BasePacket(1) {}

    void print(std::ostream& stream) const override
    {
        stream << '('
	       << uint64_t(id) << ','
               << core.L_PACKET << ','
               << core.Q_SCALE << ','
               << core.NID_LRBG << ','
               << core.NID_PRVLRBG << ','
               << core.D_LRBG << ','
               << core.Q_DIRLRBG << ','
               << core.Q_DLRBG << ','
               << core.L_DOUBTOVER << ','
               << core.L_DOUBTUNDER << ','
               << core.Q_LENGTH << ','
               << core.L_TRAININT << ','
               << core.V_TRAIN << ','
               << core.Q_DIRTRAIN << ','
               << core.M_MODE << ','
               << core.M_LEVEL << ','
               << core.NID_NTC << ')';
    }

    bool equals(const BasePacket& p) const override
    {
	if(auto q = dynamic_cast<const Position_Report_based_on_two_balise_groups*>(&p))
	{
	    return
                (core.L_PACKET == q->core.L_PACKET) &&
                (core.Q_SCALE == q->core.Q_SCALE) &&
                (core.NID_LRBG == q->core.NID_LRBG) &&
                (core.NID_PRVLRBG == q->core.NID_PRVLRBG) &&
                (core.D_LRBG == q->core.D_LRBG) &&
                (core.Q_DIRLRBG == q->core.Q_DIRLRBG) &&
                (core.Q_DLRBG == q->core.Q_DLRBG) &&
                (core.L_DOUBTOVER == q->core.L_DOUBTOVER) &&
                (core.L_DOUBTUNDER == q->core.L_DOUBTUNDER) &&
                (core.Q_LENGTH == q->core.Q_LENGTH) &&
                (core.L_TRAININT == q->core.L_TRAININT) &&
                (core.V_TRAIN == q->core.V_TRAIN) &&
                (core.Q_DIRTRAIN == q->core.Q_DIRTRAIN) &&
                (core.M_MODE == q->core.M_MODE) &&
                (core.M_LEVEL == q->core.M_LEVEL) &&
                (core.NID_NTC == q->core.NID_NTC);
	}
	return false;
    }
};

typedef std::shared_ptr<Position_Report_based_on_two_balise_groups> Position_Report_based_on_two_balise_groupsPtr;

#endif // POSITION_REPORT_BASED_ON_TWO_BALISE_GROUPS_H_INCLUDED

