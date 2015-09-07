
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
        stream << '(' << +header.NID_PACKET << ',' << core << ')';
    }

    bool equals(const BasePacket& p) const override
    {
        if (auto q = dynamic_cast<const Danger_for_Shunting_information*>(&p))
        {
            bool status = true;

            status = status && (header.NID_PACKET == q->header.NID_PACKET);
            status = status && (core == q->core);

            return status;
        }

        return false;
    }

    uint16_t length() const override
    {
        return  core.L_PACKET;
    }
};

typedef std::shared_ptr<Danger_for_Shunting_information> Danger_for_Shunting_informationPtr;

#endif // DANGER_FOR_SHUNTING_INFORMATION_H_INCLUDED

