
#ifndef ONBOARD_TELEPHONE_NUMBERS_H_INCLUDED
#define ONBOARD_TELEPHONE_NUMBERS_H_INCLUDED

#include "Bitstream.h"
#include "Onboard_telephone_numbers_Core.h"
#include "BasePacket.h"

struct Onboard_telephone_numbers : public BasePacket
{
    Onboard_telephone_numbers_Core core;

    Onboard_telephone_numbers() : BasePacket(3) {}

    void print(std::ostream& stream) const override
    {
        stream << '(' << header << ',' << core << ')';
    }

    bool equals(const BasePacket& p) const override
    {
        if (auto q = dynamic_cast<const Onboard_telephone_numbers*>(&p))
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
        data.nid_packet = 3;
	
	data.valid = core.VALID;
	data.startAddress = startAddress;

	return ::encode(data, stream, startAddress, core);
    }

    int decode(const Packet_Info& data, const kcg_int* stream) override
    {
        if(data.nid_packet != 3)
	{
	    return 0;
	}

	return ::decode(data, stream, core);
    }

};

typedef std::shared_ptr<Onboard_telephone_numbers> Onboard_telephone_numbersPtr;

#endif // ONBOARD_TELEPHONE_NUMBERS_H_INCLUDED

