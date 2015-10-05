
#ifndef TEMPORARY_SPEED_RESTRICTION_REVOCATION_H_INCLUDED
#define TEMPORARY_SPEED_RESTRICTION_REVOCATION_H_INCLUDED

#include "Bitstream.h"
#include "Temporary_Speed_Restriction_Revocation_Core.h"
#include "BasePacket.h"

struct Temporary_Speed_Restriction_Revocation : public BasePacket
{
    Temporary_Speed_Restriction_Revocation_Core core;

    Temporary_Speed_Restriction_Revocation() : BasePacket(66) {}

    void print(std::ostream& stream) const override
    {
        stream << '(' << header << ',' << core << ')';
    }

    bool equals(const BasePacket& p) const override
    {
        if (auto q = dynamic_cast<const Temporary_Speed_Restriction_Revocation*>(&p))
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

    int encode(PacketInfo& data, kcg_int* stream) const override
    {
        data.nid_packet = 66;
        data.q_dir = core.Q_DIR;
        data.valid = 1;

        PacketInfo q = data;

        stream[q.startAddress++] = header.NID_PACKET;

        int ret = ::encode(q, stream, core);

        data.endAddress = q.startAddress - 1;

        return ret;
    }

    int decode(const PacketInfo& data, const kcg_int* stream) override
    {
        if (data.nid_packet != 66)
        {
            return 0;
        }

        PacketInfo q = data;

        header.NID_PACKET = stream[q.startAddress++];

        int ret = ::decode(q, stream, core);

        if (q.startAddress - 1 != data.endAddress)
        {
            return 0;
        }

        return ret;
    }

};

typedef std::shared_ptr<Temporary_Speed_Restriction_Revocation> Temporary_Speed_Restriction_RevocationPtr;

#endif // TEMPORARY_SPEED_RESTRICTION_REVOCATION_H_INCLUDED

