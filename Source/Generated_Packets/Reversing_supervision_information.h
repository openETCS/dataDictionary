
#ifndef REVERSING_SUPERVISION_INFORMATION_H_INCLUDED
#define REVERSING_SUPERVISION_INFORMATION_H_INCLUDED

#include "Bitstream.h"
#include "Reversing_supervision_information_Core.h"
#include "BasePacket.h"

struct Reversing_supervision_information : public BasePacket
{
    Reversing_supervision_information_Core core;

    Reversing_supervision_information() : BasePacket(139) {}

    void print(std::ostream& stream) const override
    {
        stream << '('
	       << +id << ','
               << +core.Q_DIR << ','
               << +core.L_PACKET << ','
               << +core.Q_SCALE << ','
               << +core.D_REVERSE << ','
               << +core.V_REVERSE << ')';
    }

    bool equals(const BasePacket& p) const override
    {
	if(auto q = dynamic_cast<const Reversing_supervision_information*>(&p))
	{
	    return
                (core.Q_DIR == q->core.Q_DIR) &&
                (core.L_PACKET == q->core.L_PACKET) &&
                (core.Q_SCALE == q->core.Q_SCALE) &&
                (core.D_REVERSE == q->core.D_REVERSE) &&
                (core.V_REVERSE == q->core.V_REVERSE);
	}
	return false;
    }
};

typedef std::shared_ptr<Reversing_supervision_information> Reversing_supervision_informationPtr;

#endif // REVERSING_SUPERVISION_INFORMATION_H_INCLUDED

