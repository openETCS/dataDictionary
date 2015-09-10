
#ifndef REPOSITIONING_INFORMATION_H_INCLUDED
#define REPOSITIONING_INFORMATION_H_INCLUDED

#include "Bitstream.h"
#include "Repositioning_Information_Core.h"
#include "BasePacket.h"

struct Repositioning_Information : public BasePacket
{
    Repositioning_Information_Core core;

    Repositioning_Information() : BasePacket(16) {}

    void print(std::ostream& stream) const override
    {
        stream << '(' << header << ',' << core << ')';
    }

    bool equals(const BasePacket& p) const override
    {
        if (auto q = dynamic_cast<const Repositioning_Information*>(&p))
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

typedef std::shared_ptr<Repositioning_Information> Repositioning_InformationPtr;

#endif // REPOSITIONING_INFORMATION_H_INCLUDED

