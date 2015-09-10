
#ifndef LIST_OF_BALISES_FOR_SH_AREA_H_INCLUDED
#define LIST_OF_BALISES_FOR_SH_AREA_H_INCLUDED

#include "Bitstream.h"
#include "List_of_balises_for_SH_Area_Core.h"
#include "BasePacket.h"

struct List_of_balises_for_SH_Area : public BasePacket
{
    List_of_balises_for_SH_Area_Core core;

    List_of_balises_for_SH_Area() : BasePacket(49) {}

    void print(std::ostream& stream) const override
    {
        stream << '(' << header << ',' << core << ')';
    }

    bool equals(const BasePacket& p) const override
    {
        if (auto q = dynamic_cast<const List_of_balises_for_SH_Area*>(&p))
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

typedef std::shared_ptr<List_of_balises_for_SH_Area> List_of_balises_for_SH_AreaPtr;

#endif // LIST_OF_BALISES_FOR_SH_AREA_H_INCLUDED

