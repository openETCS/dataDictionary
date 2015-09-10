
#ifndef LEVEL_23_MOVEMENT_AUTHORITY_H_INCLUDED
#define LEVEL_23_MOVEMENT_AUTHORITY_H_INCLUDED

#include "Bitstream.h"
#include "Level_23_Movement_Authority_Core.h"
#include "BasePacket.h"

struct Level_23_Movement_Authority : public BasePacket
{
    Level_23_Movement_Authority_Core core;

    Level_23_Movement_Authority() : BasePacket(15) {}

    void print(std::ostream& stream) const override
    {
        stream << '(' << header << ',' << core << ')';
    }

    bool equals(const BasePacket& p) const override
    {
        if (auto q = dynamic_cast<const Level_23_Movement_Authority*>(&p))
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

typedef std::shared_ptr<Level_23_Movement_Authority> Level_23_Movement_AuthorityPtr;

#endif // LEVEL_23_MOVEMENT_AUTHORITY_H_INCLUDED

