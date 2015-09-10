
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
        stream << '(' << header << ',' << core << ')';
    }

    bool equals(const BasePacket& p) const override
    {
        if (auto q = dynamic_cast<const Reversing_supervision_information*>(&p))
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

typedef std::shared_ptr<Reversing_supervision_information> Reversing_supervision_informationPtr;

#endif // REVERSING_SUPERVISION_INFORMATION_H_INCLUDED

