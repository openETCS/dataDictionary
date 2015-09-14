
#ifndef LEVEL_CROSSING_INFORMATION_H_INCLUDED
#define LEVEL_CROSSING_INFORMATION_H_INCLUDED

#include "Bitstream.h"
#include "Level_Crossing_information_Core.h"
#include "BasePacket.h"

struct Level_Crossing_information : public BasePacket
{
    Level_Crossing_information_Core core;

    Level_Crossing_information() : BasePacket(88) {}

    void print(std::ostream& stream) const override
    {
        stream << '(' << header << ',' << core << ')';
    }

    bool equals(const BasePacket& p) const override
    {
        if (auto q = dynamic_cast<const Level_Crossing_information*>(&p))
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
        data.nid_packet = 88;
	data.q_dir = core.Q_DIR;
	data.valid = core.VALID;
	data.startAddress = startAddress;

	return ::encode(data, stream, startAddress, core);
    }

    int decode(const Packet_Info& data, const kcg_int* stream) override
    {
        if(data.nid_packet != 88)
	{
	    return 0;
	}

	return ::decode(data, stream, core);
    }

};

typedef std::shared_ptr<Level_Crossing_information> Level_Crossing_informationPtr;

#endif // LEVEL_CROSSING_INFORMATION_H_INCLUDED

