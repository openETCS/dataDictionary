
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
        stream << '(' << header << ',' << core << ')';
    }

    bool equals(const BasePacket& p) const override
    {
        if (auto q = dynamic_cast<const Position_Report*>(&p))
        {
            return header == q->header && core == q->core;
        }

        return false;
    }

    uint16_t length() const override
    {
        return  core.L_PACKET;
    }

    int encode(Bitstream& stream) const override
    {
        return ::encode(stream, core);
    }

    int decode(Bitstream& stream) override
    {
        return ::decode(stream, core);
    }

};

typedef std::shared_ptr<Position_Report> Position_ReportPtr;

#endif // POSITION_REPORT_H_INCLUDED

