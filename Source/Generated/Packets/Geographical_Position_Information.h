
#ifndef GEOGRAPHICAL_POSITION_INFORMATION_H_INCLUDED
#define GEOGRAPHICAL_POSITION_INFORMATION_H_INCLUDED

#include "Bitstream.h"
#include "Geographical_Position_Information_Core.h"
#include "BasePacket.h"

struct Geographical_Position_Information : public BasePacket
{
    Geographical_Position_Information_Core core;

    Geographical_Position_Information() : BasePacket(79) {}

    void print(std::ostream& stream) const override
    {
        stream << '(' << header << ',' << core << ')';
    }

    bool equals(const BasePacket& p) const override
    {
        if (auto q = dynamic_cast<const Geographical_Position_Information*>(&p))
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

typedef std::shared_ptr<Geographical_Position_Information> Geographical_Position_InformationPtr;

#endif // GEOGRAPHICAL_POSITION_INFORMATION_H_INCLUDED

