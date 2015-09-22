
#ifndef TRAIN_RUNNING_NUMBER_FROM_RBC_H_INCLUDED
#define TRAIN_RUNNING_NUMBER_FROM_RBC_H_INCLUDED

#include "Bitstream.h"
#include "Train_running_number_from_RBC_Core.h"
#include "BasePacket.h"

struct Train_running_number_from_RBC : public BasePacket
{
    Train_running_number_from_RBC_Core core;

    Train_running_number_from_RBC() : BasePacket(140) {}

    void print(std::ostream& stream) const override
    {
        stream << '(' << header << ',' << core << ')';
    }

    bool equals(const BasePacket& p) const override
    {
        if (auto q = dynamic_cast<const Train_running_number_from_RBC*>(&p))
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
        data.nid_packet = 140;
        data.q_dir = core.Q_DIR;
	data.valid = 1;

        PacketInfo q = data;

	stream[q.startAddress++] = header.NID_PACKET;

	int ret = ::encode(q, stream, core);

	data.endAddress = q.startAddress-1;

	return ret;
    }

    int decode(const PacketInfo& data, const kcg_int* stream) override
    {
        if(data.nid_packet != 140)
	{
	    return 0;
	}

	PacketInfo q = data;

	header.NID_PACKET = stream[q.startAddress++];

	int ret = ::decode(q, stream, core);

        if (q.startAddress-1 != data.endAddress)
        {
            return 0;
        }

	return ret;
    }

};

typedef std::shared_ptr<Train_running_number_from_RBC> Train_running_number_from_RBCPtr;

#endif // TRAIN_RUNNING_NUMBER_FROM_RBC_H_INCLUDED

