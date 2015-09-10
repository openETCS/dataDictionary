
#ifndef LEVEL_CROSSING_INFORMATION_H_INCLUDED
#define LEVEL_CROSSING_INFORMATION_H_INCLUDED

#include "Bitstream.h"
#include "Level_Crossing_information_Core.h"
#include "BasePacket.h"

struct Level_Crossing_information : public BasePacket
{
    Level_Crossing_information_Core core;

    Level_Crossing_information() : BasePacket(88) {}

    void print(std::ostream& stream) const override
    {
        stream << '(' << header << ',' << core << ')';
    }

    bool equals(const BasePacket& p) const override
    {
        if (auto q = dynamic_cast<const Level_Crossing_information*>(&p))
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

typedef std::shared_ptr<Level_Crossing_information> Level_Crossing_informationPtr;

#endif // LEVEL_CROSSING_INFORMATION_H_INCLUDED

