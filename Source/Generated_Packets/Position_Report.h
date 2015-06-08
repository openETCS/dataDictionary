
#ifndef POSITION_REPORT_H_INCLUDED
#define POSITION_REPORT_H_INCLUDED

#include "Bitstream.h"
#include "Position_Report_Core.h"
#include "BasePacket.h"

struct Position_Report : public BasePacket
{
    Position_Report_Core core;

    Position_Report() : BasePacket(0) {}

    void print(std::ostream& stream) const override
    {
        stream << '('
	       << +id << ','
               << +core.L_PACKET << ','
               << +core.Q_SCALE << ','
               << +core.NID_LRBG << ','
               << +core.D_LRBG << ','
               << +core.Q_DIRLRBG << ','
               << +core.Q_DLRBG << ','
               << +core.L_DOUBTOVER << ','
               << +core.L_DOUBTUNDER << ','
               << +core.Q_LENGTH << ','
               << +core.L_TRAININT << ','
               << +core.V_TRAIN << ','
               << +core.Q_DIRTRAIN << ','
               << +core.M_MODE << ','
               << +core.M_LEVEL << ','
               << +core.NID_NTC << ')';
    }

    bool equals(const BasePacket& p) const override
    {
	if(auto q = dynamic_cast<const Position_Report*>(&p))
	{
	    return
                (core.L_PACKET == q->core.L_PACKET) &&
                (core.Q_SCALE == q->core.Q_SCALE) &&
                (core.NID_LRBG == q->core.NID_LRBG) &&
                (core.D_LRBG == q->core.D_LRBG) &&
                (core.Q_DIRLRBG == q->core.Q_DIRLRBG) &&
                (core.Q_DLRBG == q->core.Q_DLRBG) &&
                (core.L_DOUBTOVER == q->core.L_DOUBTOVER) &&
                (core.L_DOUBTUNDER == q->core.L_DOUBTUNDER) &&
                (core.Q_LENGTH == q->core.Q_LENGTH) &&
                ((!(core.Q_LENGTH == 1) || (core.Q_LENGTH == 2)) || (
                (core.L_TRAININT == q->core.L_TRAININT)
                )) &&
                ((!core.M_LEVEL == 1) || (
                (core.NID_NTC == q->core.NID_NTC)
                ));
	}
	return false;
    }
};

typedef std::shared_ptr<Position_Report> Position_ReportPtr;

#endif // POSITION_REPORT_H_INCLUDED

