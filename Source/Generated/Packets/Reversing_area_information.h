
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
        stream << '(' << header << ',' << core << ')';
    }

    bool equals(const BasePacket& p) const override
    {
        if (auto q = dynamic_cast<const Reversing_area_information*>(&p))
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

typedef std::shared_ptr<Reversing_area_information> Reversing_area_informationPtr;

#endif // REVERSING_AREA_INFORMATION_H_INCLUDED

