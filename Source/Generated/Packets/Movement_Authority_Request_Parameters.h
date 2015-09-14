
#ifndef MOVEMENT_AUTHORITY_REQUEST_PARAMETERS_H_INCLUDED
#define MOVEMENT_AUTHORITY_REQUEST_PARAMETERS_H_INCLUDED

#include "Bitstream.h"
#include "Movement_Authority_Request_Parameters_Core.h"
#include "BasePacket.h"

struct Movement_Authority_Request_Parameters : public BasePacket
{
    Movement_Authority_Request_Parameters_Core core;

    Movement_Authority_Request_Parameters() : BasePacket(57) {}

    void print(std::ostream& stream) const override
    {
        stream << '(' << header << ',' << core << ')';
    }

    bool equals(const BasePacket& p) const override
    {
        if (auto q = dynamic_cast<const Movement_Authority_Request_Parameters*>(&p))
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
        data.nid_packet = 57;
	data.q_dir = core.Q_DIR;
	data.valid = core.VALID;
	data.startAddress = startAddress;

	return ::encode(data, stream, startAddress, core);
    }

    int decode(const Packet_Info& data, const kcg_int* stream) override
    {
        if(data.nid_packet != 57)
	{
	    return 0;
	}

	return ::decode(data, stream, core);
    }

};

typedef std::shared_ptr<Movement_Authority_Request_Parameters> Movement_Authority_Request_ParametersPtr;

#endif // MOVEMENT_AUTHORITY_REQUEST_PARAMETERS_H_INCLUDED

