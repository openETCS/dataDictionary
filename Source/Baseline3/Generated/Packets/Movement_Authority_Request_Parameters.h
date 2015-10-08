
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

    int encode(PacketInfo& data, kcg_int* stream) const override
    {
        data.nid_packet = 57;
        data.q_dir = core.Q_DIR;
        data.valid = 1;

        PacketInfo q = data;

        stream[q.startAddress++] = header.NID_PACKET;

        int ret = ::encode(q, stream, core);

        data.endAddress = q.startAddress - 1;

        return ret;
    }

    int decode(const PacketInfo& data, const kcg_int* stream) override
    {
        if (data.nid_packet != 57)
        {
            return 0;
        }

        PacketInfo q = data;

        header.NID_PACKET = stream[q.startAddress++];

        int ret = ::decode(q, stream, core);

        if (q.startAddress - 1 != data.endAddress)
        {
            return 0;
        }

        return ret;
    }

};

typedef std::shared_ptr<Movement_Authority_Request_Parameters> Movement_Authority_Request_ParametersPtr;

#endif // MOVEMENT_AUTHORITY_REQUEST_PARAMETERS_H_INCLUDED

