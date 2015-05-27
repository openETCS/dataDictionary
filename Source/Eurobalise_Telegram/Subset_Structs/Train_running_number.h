
#ifndef TRAIN_RUNNING_NUMBER_H_INCLUDED
#define TRAIN_RUNNING_NUMBER_H_INCLUDED

#include "Bitstream.h"
#include "BasePacket.h"
#include "Train_running_number_Core.h"

struct Train_running_number : public BasePacket
{
    Train_running_number_Core core;

    Train_running_number() : BasePacket(5) {}

    void print(std::ostream& stream) const
    {
        stream << '(' << id << ','
	<< core.L_PACKET << ','
	<< core.NID_OPERATIONAL << ')';
    }

    bool equals(const BasePacket& p) const
    {
        auto q = dynamic_cast<const Train_running_number*>(&p);
	if(q)
	{
           return (core.L_PACKET == q->core.L_PACKET) &&
	          (core.NID_OPERATIONAL == q->core.NID_OPERATIONAL);
	}
	return false;
    }
};

typedef std::shared_ptr<Train_running_number> Train_running_numberPtr;

#endif // TRAIN_RUNNING_NUMBER_H_INCLUDED

