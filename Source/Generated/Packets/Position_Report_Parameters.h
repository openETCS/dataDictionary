
#ifndef POSITION_REPORT_PARAMETERS_H_INCLUDED
#define POSITION_REPORT_PARAMETERS_H_INCLUDED

#include "Bitstream.h"
#include "Position_Report_Parameters_Core.h"
#include "BasePacket.h"

struct Position_Report_Parameters : public BasePacket
{
    Position_Report_Parameters_Core core;

    Position_Report_Parameters() : BasePacket(58) {}

    void print(std::ostream& stream) const override
    {
        stream << '(' << header << ',' << core << ')';
    }

    bool equals(const BasePacket& p) const override
    {
        if (auto q = dynamic_cast<const Position_Report_Parameters*>(&p))
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
        data.nid_packet = 58;
	data.q_dir = core.Q_DIR;
	data.valid = core.VALID;
	data.startAddress = startAddress;

	return ::encode(data, stream, startAddress, core);
    }

    int decode(const Packet_Info& data, const kcg_int* stream) override
    {
        if(data.nid_packet != 58)
	{
	    return 0;
	}

	return ::decode(data, stream, core);
    }

};

typedef std::shared_ptr<Position_Report_Parameters> Position_Report_ParametersPtr;

#endif // POSITION_REPORT_PARAMETERS_H_INCLUDED

