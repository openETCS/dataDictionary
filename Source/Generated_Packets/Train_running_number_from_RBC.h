
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
        stream << '(' << uint64_t(id) << ')';
    }

    bool equals(const BasePacket& p) const override
    {
	if(auto q = dynamic_cast<const Train_running_number_from_RBC*>(&p))
	{
	    return
                (core.Q_DIR == q->core.Q_DIR) &&
                (core.L_PACKET == q->core.L_PACKET) &&
                (core.NID_OPERATIONAL == q->core.NID_OPERATIONAL);
	}
	return false;
     }
};

typedef std::shared_ptr<Train_running_number_from_RBC> Train_running_number_from_RBCPtr;

#endif // TRAIN_RUNNING_NUMBER_FROM_RBC_H_INCLUDED

