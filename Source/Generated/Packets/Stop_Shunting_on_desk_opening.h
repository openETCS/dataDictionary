
#ifndef STOP_SHUNTING_ON_DESK_OPENING_H_INCLUDED
#define STOP_SHUNTING_ON_DESK_OPENING_H_INCLUDED

#include "Bitstream.h"
#include "Stop_Shunting_on_desk_opening_Core.h"
#include "BasePacket.h"

struct Stop_Shunting_on_desk_opening : public BasePacket
{
    Stop_Shunting_on_desk_opening_Core core;

    Stop_Shunting_on_desk_opening() : BasePacket(135) {}

    void print(std::ostream& stream) const override
    {
        stream << '(' << header << ',' << core << ')';
    }

    bool equals(const BasePacket& p) const override
    {
        if (auto q = dynamic_cast<const Stop_Shunting_on_desk_opening*>(&p))
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
        data.nid_packet = 135;
	data.q_dir = core.Q_DIR;
	data.valid = core.VALID;
	data.startAddress = startAddress;

	return ::encode(data, stream, startAddress, core);
    }

    int decode(const Packet_Info& data, const kcg_int* stream) override
    {
        if(data.nid_packet != 135)
	{
	    return 0;
	}

	return ::decode(data, stream, core);
    }

};

typedef std::shared_ptr<Stop_Shunting_on_desk_opening> Stop_Shunting_on_desk_openingPtr;

#endif // STOP_SHUNTING_ON_DESK_OPENING_H_INCLUDED

