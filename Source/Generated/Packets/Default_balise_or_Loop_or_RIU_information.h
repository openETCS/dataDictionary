
#ifndef DEFAULT_BALISE_OR_LOOP_OR_RIU_INFORMATION_H_INCLUDED
#define DEFAULT_BALISE_OR_LOOP_OR_RIU_INFORMATION_H_INCLUDED

#include "Bitstream.h"
#include "Default_balise_or_Loop_or_RIU_information_Core.h"
#include "BasePacket.h"

struct Default_balise_or_Loop_or_RIU_information : public BasePacket
{
    Default_balise_or_Loop_or_RIU_information_Core core;

    Default_balise_or_Loop_or_RIU_information() : BasePacket(254) {}

    void print(std::ostream& stream) const override
    {
        stream << '(' << header << ',' << core << ')';
    }

    bool equals(const BasePacket& p) const override
    {
        if (auto q = dynamic_cast<const Default_balise_or_Loop_or_RIU_information*>(&p))
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
        data.nid_packet = 254;
	data.q_dir = core.Q_DIR;
	data.valid = core.VALID;
	data.startAddress = startAddress;

	return ::encode(data, stream, startAddress, core);
    }

    int decode(const Packet_Info& data, const kcg_int* stream) override
    {
        if(data.nid_packet != 254)
	{
	    return 0;
	}

	return ::decode(data, stream, core);
    }

};

typedef std::shared_ptr<Default_balise_or_Loop_or_RIU_information> Default_balise_or_Loop_or_RIU_informationPtr;

#endif // DEFAULT_BALISE_OR_LOOP_OR_RIU_INFORMATION_H_INCLUDED

