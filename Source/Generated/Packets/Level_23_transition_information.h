
#ifndef LEVEL_23_TRANSITION_INFORMATION_H_INCLUDED
#define LEVEL_23_TRANSITION_INFORMATION_H_INCLUDED

#include "Bitstream.h"
#include "Level_23_transition_information_Core.h"
#include "BasePacket.h"

struct Level_23_transition_information : public BasePacket
{
    Level_23_transition_information_Core core;

    Level_23_transition_information() : BasePacket(9) {}

    void print(std::ostream& stream) const override
    {
        stream << '(' << header << ',' << core << ')';
    }

    bool equals(const BasePacket& p) const override
    {
        if (auto q = dynamic_cast<const Level_23_transition_information*>(&p))
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

typedef std::shared_ptr<Level_23_transition_information> Level_23_transition_informationPtr;

#endif // LEVEL_23_TRANSITION_INFORMATION_H_INCLUDED

