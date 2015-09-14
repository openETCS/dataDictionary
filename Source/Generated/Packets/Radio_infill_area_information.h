
#ifndef RADIO_INFILL_AREA_INFORMATION_H_INCLUDED
#define RADIO_INFILL_AREA_INFORMATION_H_INCLUDED

#include "Bitstream.h"
#include "Radio_infill_area_information_Core.h"
#include "BasePacket.h"

struct Radio_infill_area_information : public BasePacket
{
    Radio_infill_area_information_Core core;

    Radio_infill_area_information() : BasePacket(133) {}

    void print(std::ostream& stream) const override
    {
        stream << '(' << header << ',' << core << ')';
    }

    bool equals(const BasePacket& p) const override
    {
        if (auto q = dynamic_cast<const Radio_infill_area_information*>(&p))
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
        data.nid_packet = 133;
        data.q_dir = core.Q_DIR;
	data.valid = 1;
	data.startAddress = startAddress;

	stream[startAddress++] = header.NID_PACKET;

	return ::encode(data, stream, startAddress, core);
    }

    int decode(const Packet_Info& data, const kcg_int* stream) override
    {
        if(data.nid_packet != 133)
	{
	    return 0;
	}

	header.NID_PACKET = stream[data.startAddress];

	return ::decode(data, stream, core);
    }

};

typedef std::shared_ptr<Radio_infill_area_information> Radio_infill_area_informationPtr;

#endif // RADIO_INFILL_AREA_INFORMATION_H_INCLUDED

