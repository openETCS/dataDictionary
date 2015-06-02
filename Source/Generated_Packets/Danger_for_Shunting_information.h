
#ifndef DANGER_FOR_SHUNTING_INFORMATION_H_INCLUDED
#define DANGER_FOR_SHUNTING_INFORMATION_H_INCLUDED

#include "Bitstream.h"
#include "Danger_for_Shunting_information_Core.h"
#include "BasePacket.h"

struct Danger_for_Shunting_information : public BasePacket
{
    Danger_for_Shunting_information_Core core;

    Danger_for_Shunting_information() : BasePacket(132) {}

    void print(std::ostream& stream) const override
    {
        stream << '(' << uint64_t(id) << ')';
    }

    bool equals(const BasePacket& p) const override
    {
	if(auto q = dynamic_cast<const Danger_for_Shunting_information*>(&p))
	{
	    return
                (core.Q_DIR == q->core.Q_DIR) &&
                (core.L_PACKET == q->core.L_PACKET) &&
                (core.Q_ASPECT == q->core.Q_ASPECT);
	}
	return false;
     }
};

typedef std::shared_ptr<Danger_for_Shunting_information> Danger_for_Shunting_informationPtr;

#endif // DANGER_FOR_SHUNTING_INFORMATION_H_INCLUDED

