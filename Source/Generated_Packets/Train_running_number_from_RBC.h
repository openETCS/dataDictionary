
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
        stream << '(' << +id << ',' << core << ')';
    }

    bool equals(const BasePacket& p) const override
    {
	if(auto q = dynamic_cast<const Train_running_number_from_RBC*>(&p))
	{
	    bool status = true;

	    status = status && (id == q->id);
	    status = status && (core == q->core);

	    return status;
	}
	return false;
    }
};

typedef std::shared_ptr<Train_running_number_from_RBC> Train_running_number_from_RBCPtr;

#endif // TRAIN_RUNNING_NUMBER_FROM_RBC_H_INCLUDED

