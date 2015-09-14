
#ifndef CONDITIONAL_LEVEL_TRANSITION_ORDER_H_INCLUDED
#define CONDITIONAL_LEVEL_TRANSITION_ORDER_H_INCLUDED

#include "Bitstream.h"
#include "Conditional_Level_Transition_Order_Core.h"
#include "BasePacket.h"

struct Conditional_Level_Transition_Order : public BasePacket
{
    Conditional_Level_Transition_Order_Core core;

    Conditional_Level_Transition_Order() : BasePacket(46) {}

    void print(std::ostream& stream) const override
    {
        stream << '(' << header << ',' << core << ')';
    }

    bool equals(const BasePacket& p) const override
    {
        if (auto q = dynamic_cast<const Conditional_Level_Transition_Order*>(&p))
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
        data.nid_packet = 46;
        data.q_dir = core.Q_DIR;
	data.valid = 1;
	data.startAddress = startAddress;

	stream[startAddress++] = header.NID_PACKET;

	return ::encode(data, stream, startAddress, core);
    }

    int decode(const Packet_Info& data, const kcg_int* stream) override
    {
        if(data.nid_packet != 46)
	{
	    return 0;
	}

	header.NID_PACKET = stream[data.startAddress];

	return ::decode(data, stream, core);
    }

};

typedef std::shared_ptr<Conditional_Level_Transition_Order> Conditional_Level_Transition_OrderPtr;

#endif // CONDITIONAL_LEVEL_TRANSITION_ORDER_H_INCLUDED

