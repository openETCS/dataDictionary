
#ifndef REVERSING_AREA_INFORMATION_H_INCLUDED
#define REVERSING_AREA_INFORMATION_H_INCLUDED

#include "Bitstream.h"
#include "Reversing_area_information_Core.h"
#include "BasePacket.h"

struct Reversing_area_information : public BasePacket
{
    Reversing_area_information_Core core;

    Reversing_area_information() : BasePacket(138) {}

    void print(std::ostream& stream) const override
    {
        stream << '(' << uint64_t(id) << ')';
    }

    bool equals(const BasePacket& p) const override
    {
	if(auto q = dynamic_cast<const Reversing_area_information*>(&p))
	{
	    return
                (core.Q_DIR == q->core.Q_DIR) &&
                (core.L_PACKET == q->core.L_PACKET) &&
                (core.Q_SCALE == q->core.Q_SCALE) &&
                (core.D_STARTREVERSE == q->core.D_STARTREVERSE) &&
                (core.L_REVERSEAREA == q->core.L_REVERSEAREA);
	}
	return false;
     }
};

typedef std::shared_ptr<Reversing_area_information> Reversing_area_informationPtr;

#endif // REVERSING_AREA_INFORMATION_H_INCLUDED

