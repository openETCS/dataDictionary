
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
        stream << '(' << +id << ',' << core << ')';
    }

    bool equals(const BasePacket& p) const override
    {
	if(auto q = dynamic_cast<const Position_Report*>(&p))
	{
	    bool status = true;

	    status = status && (id == q->id);
	    status = status && (core == q->core);

	    return status;
	}
	return false;
    }
};

typedef std::shared_ptr<Position_Report> Position_ReportPtr;

#endif // POSITION_REPORT_H_INCLUDED

