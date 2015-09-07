
#ifndef VIRTUAL_BALISE_COVER_MARKER_H_INCLUDED
#define VIRTUAL_BALISE_COVER_MARKER_H_INCLUDED

#include "Bitstream.h"
#include "Virtual_Balise_Cover_marker_Core.h"
#include "BasePacket.h"

struct Virtual_Balise_Cover_marker : public BasePacket
{
    Virtual_Balise_Cover_marker_Core core;

    Virtual_Balise_Cover_marker() : BasePacket(0) {}

    void print(std::ostream& stream) const override
    {
        stream << '(' << +header.NID_PACKET << ',' << core << ')';
    }

    bool equals(const BasePacket& p) const override
    {
        if (auto q = dynamic_cast<const Virtual_Balise_Cover_marker*>(&p))
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
        return  14;
    }
};

typedef std::shared_ptr<Virtual_Balise_Cover_marker> Virtual_Balise_Cover_markerPtr;

#endif // VIRTUAL_BALISE_COVER_MARKER_H_INCLUDED

