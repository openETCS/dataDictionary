
#ifndef VIRTUAL_BALISE_COVER_ORDER_H_INCLUDED
#define VIRTUAL_BALISE_COVER_ORDER_H_INCLUDED

#include "Bitstream.h"
#include "Virtual_Balise_Cover_order_Core.h"
#include "BasePacket.h"

struct Virtual_Balise_Cover_order : public BasePacket
{
    Virtual_Balise_Cover_order_Core core;

    Virtual_Balise_Cover_order() : BasePacket(6) {}

    void print(std::ostream& stream) const override
    {
        stream << '(' << header << ',' << core << ')';
    }

    bool equals(const BasePacket& p) const override
    {
        if (auto q = dynamic_cast<const Virtual_Balise_Cover_order*>(&p))
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
        data.nid_packet = 6;
        data.q_dir = core.Q_DIR;
	data.valid = 1;
	data.startAddress = startAddress;

	stream[startAddress++] = header.NID_PACKET;

	return ::encode(data, stream, startAddress, core);
    }

    int decode(const Packet_Info& data, const kcg_int* stream) override
    {
        if(data.nid_packet != 6)
	{
	    return 0;
	}

	header.NID_PACKET = stream[data.startAddress];

	return ::decode(data, stream, core);
    }

};

typedef std::shared_ptr<Virtual_Balise_Cover_order> Virtual_Balise_Cover_orderPtr;

#endif // VIRTUAL_BALISE_COVER_ORDER_H_INCLUDED

