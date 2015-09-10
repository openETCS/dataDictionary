
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
        stream << '(' << header << ',' << core << ')';
    }

    bool equals(const BasePacket& p) const override
    {
        if (auto q = dynamic_cast<const Position_Report_based_on_two_balise_groups*>(&p))
        {
            return header == q->header && core == q->core;
        }

        return false;
    }

    uint16_t length() const override
    {
        return  core.L_PACKET;
    }
};

typedef std::shared_ptr<Position_Report_based_on_two_balise_groups> Position_Report_based_on_two_balise_groupsPtr;

#endif // POSITION_REPORT_BASED_ON_TWO_BALISE_GROUPS_H_INCLUDED

