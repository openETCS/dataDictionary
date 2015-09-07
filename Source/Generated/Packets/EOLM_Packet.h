
#ifndef EOLM_PACKET_H_INCLUDED
#define EOLM_PACKET_H_INCLUDED

#include "Bitstream.h"
#include "EOLM_Packet_Core.h"
#include "BasePacket.h"

struct EOLM_Packet : public BasePacket
{
    EOLM_Packet_Core core;

    EOLM_Packet() : BasePacket(134) {}

    void print(std::ostream& stream) const override
    {
        stream << '(' << +header.NID_PACKET << ',' << core << ')';
    }

    bool equals(const BasePacket& p) const override
    {
        if (auto q = dynamic_cast<const EOLM_Packet*>(&p))
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

typedef std::shared_ptr<EOLM_Packet> EOLM_PacketPtr;

#endif // EOLM_PACKET_H_INCLUDED

