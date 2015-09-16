
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
        stream << '(' << header << ',' << core << ')';
    }

    bool equals(const BasePacket& p) const override
    {
        if (auto q = dynamic_cast<const Virtual_Balise_Cover_marker*>(&p))
        {
            return header == q->header && core == q->core;
        }

        return false;
    }

    uint16_t length() const override
    {
        return  14;
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
        data.nid_packet = 0;
	data.valid = 1;
	data.startAddress = startAddress;

	stream[startAddress++] = header.NID_PACKET;

	return ::encode(data, stream, startAddress, core);
    }

    int decode(const Packet_Info& data, const kcg_int* stream) override
    {
        if(data.nid_packet != 0)
	{
	    return 0;
	}

	header.NID_PACKET = stream[data.startAddress];

	return ::decode(data, stream, core);
    }

};

typedef std::shared_ptr<Virtual_Balise_Cover_marker> Virtual_Balise_Cover_markerPtr;

#endif // VIRTUAL_BALISE_COVER_MARKER_H_INCLUDED

