
#ifndef DANGER_FOR_SHUNTING_INFORMATION_H_INCLUDED
#define DANGER_FOR_SHUNTING_INFORMATION_H_INCLUDED

#include "Bitstream.h"
#include "Danger_for_Shunting_information_Core.h"
#include "BasePacket.h"

struct Danger_for_Shunting_information : public BasePacket
{
    Danger_for_Shunting_information_Core core;

    Danger_for_Shunting_information() : BasePacket(132) {}

    void print(std::ostream& stream) const override
    {
        stream << '(' << header << ',' << core << ')';
    }

    bool equals(const BasePacket& p) const override
    {
        if (auto q = dynamic_cast<const Danger_for_Shunting_information*>(&p))
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
        data.nid_packet = 132;
	data.q_dir = core.Q_DIR;
	data.valid = core.VALID;
	data.startAddress = startAddress;

	return ::encode(data, stream, startAddress, core);
    }

    int decode(const Packet_Info& data, const kcg_int* stream) override
    {
        if(data.nid_packet != 132)
	{
	    return 0;
	}

	return ::decode(data, stream, core);
    }

};

typedef std::shared_ptr<Danger_for_Shunting_information> Danger_for_Shunting_informationPtr;

#endif // DANGER_FOR_SHUNTING_INFORMATION_H_INCLUDED

