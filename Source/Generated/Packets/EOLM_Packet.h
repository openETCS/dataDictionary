
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
        stream << '(' << header << ',' << core << ')';
    }

    bool equals(const BasePacket& p) const override
    {
        if (auto q = dynamic_cast<const EOLM_Packet*>(&p))
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

    int encode(Packet_Info& data, kcg_int* stream, kcg_int startAddress) const override
    {
        data.nid_packet = 134;
	data.q_dir = core.Q_DIR;
	data.valid = core.VALID;
	data.startAddress = startAddress;

	return ::encode(data, stream, startAddress, core);
    }

    int decode(const Packet_Info& data, const kcg_int* stream) override
    {
        if(data.nid_packet != 134)
	{
	    return 0;
	}

	return ::decode(data, stream, core);
    }

};

typedef std::shared_ptr<EOLM_Packet> EOLM_PacketPtr;

#endif // EOLM_PACKET_H_INCLUDED

