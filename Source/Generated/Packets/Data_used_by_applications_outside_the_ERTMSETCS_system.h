
#ifndef DATA_USED_BY_APPLICATIONS_OUTSIDE_THE_ERTMSETCS_SYSTEM_H_INCLUDED
#define DATA_USED_BY_APPLICATIONS_OUTSIDE_THE_ERTMSETCS_SYSTEM_H_INCLUDED

#include "Bitstream.h"
#include "Data_used_by_applications_outside_the_ERTMSETCS_system_Core.h"
#include "BasePacket.h"

struct Data_used_by_applications_outside_the_ERTMSETCS_system : public BasePacket
{
    Data_used_by_applications_outside_the_ERTMSETCS_system_Core core;

    Data_used_by_applications_outside_the_ERTMSETCS_system() : BasePacket(44) {}

    void print(std::ostream& stream) const override
    {
        stream << '(' << header << ',' << core << ')';
    }

    bool equals(const BasePacket& p) const override
    {
        if (auto q = dynamic_cast<const Data_used_by_applications_outside_the_ERTMSETCS_system*>(&p))
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
        data.nid_packet = 44;
        data.q_dir = core.Q_DIR;
	data.valid = 1;
	data.startAddress = startAddress;

	stream[startAddress++] = header.NID_PACKET;

	return ::encode(data, stream, startAddress, core);
    }

    int decode(const Packet_Info& data, const kcg_int* stream) override
    {
        if(data.nid_packet != 44)
	{
	    return 0;
	}

	header.NID_PACKET = stream[data.startAddress];

	return ::decode(data, stream, core);
    }

};

typedef std::shared_ptr<Data_used_by_applications_outside_the_ERTMSETCS_system> Data_used_by_applications_outside_the_ERTMSETCS_systemPtr;

#endif // DATA_USED_BY_APPLICATIONS_OUTSIDE_THE_ERTMSETCS_SYSTEM_H_INCLUDED

