
#ifndef POSITION_REPORT_PARAMETERS_H_INCLUDED
#define POSITION_REPORT_PARAMETERS_H_INCLUDED

#include "Bitstream.h"
#include "Position_Report_Parameters_Core.h"
#include "BasePacket.h"

struct Position_Report_Parameters : public BasePacket
{
    Position_Report_Parameters_Core core;

    Position_Report_Parameters() : BasePacket(58) {}

    void print(std::ostream& stream) const override
    {
        stream << '(' << header << ',' << core << ')';
    }

    bool equals(const BasePacket& p) const override
    {
        if (auto q = dynamic_cast<const Position_Report_Parameters*>(&p))
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

};

typedef std::shared_ptr<Position_Report_Parameters> Position_Report_ParametersPtr;

#endif // POSITION_REPORT_PARAMETERS_H_INCLUDED

